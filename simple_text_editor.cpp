/*
*
* I SHOULD HAVE USED A STACK TO MAKE IT PASS ALL THE TEST CASES
*
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int main() {
    
    string q_temp;
    getline(cin, q_temp);
    int q = stoi(ltrim(rtrim(q_temp)));
    
    string main_str, backup_str;
    
    for (int q_ = 0; q_ < q; q_++) {
        
        string op_tt;
        getline(cin, op_tt);
        vector<string> op_t = split(rtrim(op_tt));
        int op = stoi(op_t[0]);
        
        switch (op) {
            case 1: {
                backup_str = main_str;
                main_str.append(op_t[1]);
                break;
            }
            case 2: {
                int length = stoi(op_t[1]);
                if (!main_str.empty()) {
                    backup_str = main_str;
                    main_str.erase(main_str.end() - length, main_str.end());
                }
                break;
            }
            case 3: {
                int kth = stoi(op_t[1]);
                if (!main_str.empty()) {
                    cout << main_str[kth - 1] << endl;
                }
                break;
            }
            case 4: {
                main_str = backup_str;
                break;
            }
            default:break;
        }
        
        // cout << op << " " << main_str << " " << backup_str << endl;
        
    } // end of main loop (q_)
      
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
