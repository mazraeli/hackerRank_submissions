#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    
    char mid_day_flag = s[s.length() - 2];
    
    if (s[1] == '2' && s[0] == '1') {
        if (mid_day_flag == 'A') {
             s[0] = '0';
             s[1] = '0';
             
             return string(s.begin(), s.end() - 2);
        }
    } else {
        if (mid_day_flag == 'P') {
             int h = stoi(s.substr(0, 2));
             
             h += 12;
             
             string st = to_string(h);
             
             s[0] = st[0];
             s[1] = st[1];
             
             return string(s.begin(), s.end() - 2);
        }
    }
    return string(s.begin(), s.end() - 2);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
