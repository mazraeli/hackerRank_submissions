#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    string n_temp;
    getline(cin, n_temp);
    
    int64_t n = stoi(ltrim(rtrim(n_temp)));
    
    stack<int64_t> stack_one, stack_two;
    
    // one = true ; two = false
    bool stack_in_use = true;
    
    for (int i = 0; i < n; i++) {
        string query_tt;
        getline(cin, query_tt);
        
        vector<string> query_t = split(rtrim(query_tt));
        int64_t query = stoi(query_t[0]);
        
        switch (query) {
            case 1 : {
                if (!stack_in_use && !stack_two.empty()) {
                    stack_one.push(stack_two.top());
                    stack_two.pop();
                }
                int64_t data = stoi(query_t[1]);
                stack_one.push(data);
                stack_in_use = true;
                
                break;
            }
            case 2 : {
                if (stack_in_use && !stack_one.empty()) {
                    while (stack_one.size() > 1) {
                        stack_two.push(stack_one.top());
                        stack_one.pop();
                    }
                    // dequeue
                    stack_one.pop();
                    stack_in_use = false;
                } else if (!stack_in_use && !stack_two.empty()){
                    stack_two.pop();
                }
                
                break;
            }
            case 3 : {
                if (stack_in_use && !stack_one.empty()) {
                    while (stack_one.size() > 1) {
                        stack_two.push(stack_one.top());
                        stack_one.pop();
                    }
                    cout << stack_one.top() << endl;
                    stack_two.push(stack_one.top());
                    stack_one.pop();
                    stack_in_use = false;
                } else if (!stack_in_use && !stack_two.empty()){
                    cout << stack_two.top() << endl;
                }
                
                break;
            }
            default: break;
        }
    }
     
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
