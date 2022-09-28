# Task
Design & Implement classes for representing unordered sets of integers:

(Note: The syntax of implemented functions must be exactly same as specified below)

* Class `Set`, representing a set of integer numbers.
* Class `SetEl`, representing a single element of set.

## Class SetEl

* **int SetEl::value() const**

  returns the element’s value.
  
* **Set * SetEl::set() const**

  returns a pointer to Set in which this element belongs.

## Class Set

* **void Set::output() const**

  print the whole set in any order of the elements. Start the output with curly bracket (a brace), print out integer numbers representing elements of the set separated by commas and close the sequence with another brace. For example, the set of integers from 1 to 4 can be written as {4,2,1,3}.
  
* **int Set::size() const**

  returns the number of elements in set.
  
* **bool Set::add(int x)**

  adds a single integer x to set. Returns true or false depending on whether x was actually added (true) or was already present in set (false).
  
* **int Set::add(const Set * pSet)**

  adds to this all elements of the set pointed by pSet. Returns number of elements actually added. The set pointed by pSet remains unchanged.
  
* **int Set::merge(SetEl * pEl)**

  melds the set this with set containing pEl. Returns number of elements actually added to set this, in particular 0 if nothing was added to this as well as when pEl already belongs to this. After this operation, the set initially containing pEl should become empty (unless of course pEl belonged to this from the beginning).

* **int Set::merge(Set * pSet)**

  analogous to the above method. After this operation, the set pointed by pSet should become empty.
  
* **SetEl * Set::min() const**

  returns a pointer to the minimum element of the set (NULL if set is empty).
  
* **SetEl * Set::max() const**

  returns a pointer to the maximum element of the set (NULL if set is empty).
  
* **void Set::clean()**
  
  delete all elements from the set.
