#include <bits/stdc++.h>
using namespace std;

/*
    return pts to set
    output all ele
    return size;
    check and add
    add one set to amother
    min
    max
    clear()

    the problem;
    setEl needs also store the ptr to set where it belongs

*/

class Set;

class SetEl {
    private:
        int data;
        Set* ptr;

    public:
        SetEl(int d, Set* p);
        int value() const {
            return data;
        }
        Set* set() const {
            return ptr;
        }
        friend bool operator==(const SetEl& El1, const SetEl& El2) {
            return El1.data == El2.data;
        }
        friend bool operator<(const SetEl& El1, const SetEl& El2) {
            return El1.data < El2.data;
        }
        friend ostream& operator<<(ostream& os, const SetEl& El) {
            os << El.data;
            return os;
        }
};

class Set {
    private:
        set<SetEl> data;

    public:
        void output() const {
            int i=0;

            cout << '{';
            for(SetEl El:data) {
                if(i) cout << ',';
                cout << El;
                i++;
            }
            cout << '}' << endl;
        };
        int size() const {
            return data.size();
        }
        bool add(int x) {
            // set<SetEl>::iterator fIt = find(data.begin(), data.end(), x);

            // if(fIt==data.end()) {
            //     data.insert(SetEl(x, this));
            //     return true;
            // }
            // else return false;

            if(!data.count(SetEl(x, this))) {
                data.insert(SetEl(x, this));
                return true;
            }
            else return false;
        }
        int add(const Set *pSet) {
            if(pSet == this || pSet->size()==0) return 0;

            // for(SetEl El: data) {
            //     pSet->add(El.value());
            // }
            //! Amazing that the parameter is const Set

            set<SetEl> pData = pSet->data;

            int prevSize = size();
            for(SetEl pEl: pData) 
                data.insert(SetEl(pEl.value(), this));
            int finSize = size();

            return finSize - prevSize;
        }
        int merge(SetEl *pEl) {
            if(pEl->set() == this) return 0;
            
            int added = add(pEl->set());
            pEl->set()->clean();

            return added;
        }
        int merge(Set *pSet) {
            int added = add(pSet);
            pSet->clean();

            return added;
        }

        SetEl * min() const {
            if(size()) {
                auto minIt = min_element(data.begin(), data.end());
                SetEl* ptr = const_cast<SetEl*>(&(*minIt));
                return ptr;
            }
            return nullptr;
        }
        SetEl * max() const {
            if(size()) {
                auto maxIt = max_element(data.begin(), data.end());
                SetEl* ptr = const_cast<SetEl*>(&(*maxIt));
                return ptr;
            }
            return nullptr;
        }
        void clean() {
            data.clear();
        }
};


SetEl::SetEl(int d, Set* p) : data(d), ptr(p) {};

int main() {
    Set obj1;
    Set obj2;
    Set obj3;

    cout << obj1.add(15) << " " << obj1.add(20) << ' ' << obj2.add(25) << ' ' << obj2.add(30) << endl;
    cout << obj1.add(&obj2) << endl;
    obj1.output();

    cout << obj1.min()->value() << " " << obj1.max()->value() << endl;

    cout << obj3.merge(obj1.min()) << endl;
    obj1.output();obj2.output();obj3.output();
    
    cout << obj2.add(45) << obj2.add(50) << endl;

    cout << obj3.merge(&obj2) << endl;
    obj1.output();obj2.output();obj3.output();

    return 0;
}