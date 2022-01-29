#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

bool compare_br(char left, char right) {
    if (left == '(' && right == ')')
        return true;
    if (left == '{' && right == '}')
        return true;
    if (left == '[' && right == ']')
        return true;
    return false;
}

string isBalanced(string s) {
    
    if (s.size() <= 1 || s.size() % 2 != 0) {
        cout << "from the first if" << endl;
        return "NO";
    }
    
    stack<char> st;
    for (auto & element : s) {
        if (element == '(' || element == '[' || element == '{') {
            st.push(element);
            continue;
        }
        if (st.empty()) {
            return "NO";
        }
        if (!compare_br(st.top(), element)) {
            return "NO";
        }
        st.pop();
    }
    
    return st.empty() ? "YES" : "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

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
