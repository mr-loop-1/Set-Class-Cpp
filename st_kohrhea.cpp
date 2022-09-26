#include <bits/stdc++.h>

using namespace std;


vector<vector<string>> joinTwoTable(vector<vector<string>>& v1, int columnIndex1, vector<vector<string>>& v2, int columnIndex2) 
{
    vector<vector<string>> result;
    vector<string> columns;

    string commonColumn = v1[0][columnIndex1];
    // cout << commonColumn << endl;

    for(string s: v1[0]) {
        columns.push_back(s);
    }
    for(string s: v2[0]) {
        if(s == commonColumn) continue;
        columns.push_back(s);
    }

    // push headers
    result.push_back(columns);

    for(int i=1; i!=v1.size(); i++) {

        string joiner = v1[i][columnIndex1];

        for(int j=1; j!=v2.size(); j++) {
            if(v2[j][columnIndex2] == joiner) {

                // push a new joined row
                vector<string> temp;

                for(string s1: v1[i]) {
                    temp.push_back(s1);
                }
                for(auto k=0; k!=v2[j].size(); k++) {
                    if(k==columnIndex2) continue;
                    temp.push_back(v2[j][k]);
                }

                result.push_back(temp);
            }
        }
    }

    return result;
} 

int main() {
    vector<vector<string>> v1 = { vector<string> { "Numbers", "Alphabets" },
                              vector<string> { "1", "a" },
                              vector<string> { "2", "b" },
                              vector<string> { "3", "a" } };

// First Column Name: Fruits
// Second Column Name: Alphabets
vector<vector<string>> v2 = { vector<string> { "Fruits", "Alphabets" },
                              vector<string> { "apple", "a" },
                              vector<string> { "pear", "a" },
                              vector<string> { "peach", "c" },
                              vector<string> { "orange", "b" } };


    vector<vector<string>> res = joinTwoTable(v1, 1, v2, 1);

    for(int i=0; i!=res.size(); i++) {
        for(int j=0; j!=res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;


}