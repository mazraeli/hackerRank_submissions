#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bfs' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. 2D_INTEGER_ARRAY edges
 *  4. INTEGER s
 */

#define EDGE_WEIGHT 6

template<typename T>
void print_queue(T q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    } cout << endl;
}

template<typename T>
void print_vec(const T vec) {
    for (const auto element : vec) 
        cout << element << " ";
    cout << endl;
}

template<typename T>
void print_adj_mat(const T mat) {
    for (const auto row : mat) {
        for (const auto col : row) {
            std::cout << col << " ";
        } std::cout << "\n";
    }
}

vector<int> bfs(const int n, const int m, vector<vector<int>> edges, int s) {

    // adjacency matrix
    std::vector<std::vector<int>> adj_matrix (n, std::vector<int>(n, 0));
    // result vector
    std::vector<int> result_vec (n, 0);
    // visiting queue
    std::queue<int> q;
    // visited nodes
    std::vector<bool> visited (n, false);
    
    // initialize the adjacency matrix
    for (int i = 0; i < m; i++) {
        adj_matrix[edges[i][0] - 1][edges[i][1] - 1] = 1;
        adj_matrix[edges[i][1] - 1][edges[i][0] - 1] = 1;
    }
    
    vector<int> row (adj_matrix[s - 1].begin(), adj_matrix[s - 1].end());
    
    visited[s - 1] = true;
    for (int i = 0; i < n; i++) {
        if (row[i] == 1) {
            q.push(i);
            result_vec[i] += EDGE_WEIGHT;
            visited[i] = true;
        }
    }
    
    while (!q.empty()) {
        int node_t = q.front();
        q.pop();
        
        row = adj_matrix[node_t];
        for (int i = 0; i < n; i++) {
            if (!visited[i] and row[i] == 1) {
                q.push(i);
                result_vec[i] = result_vec[node_t] + EDGE_WEIGHT;
                visited[i] = true;
            }
        }
    }
    
    // returning vector
    std::vector<int> ret_vec;
    for (int i = 0; i < n; i++) {
        if (i == (s - 1))
            continue;
        if (result_vec[i] == 0) {
            ret_vec.push_back(-1);
            continue;
        }
        ret_vec.push_back(result_vec[i]);
    }
        
    return ret_vec;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        vector<vector<int>> edges(m);

        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            string edges_row_temp_temp;
            getline(cin, edges_row_temp_temp);

            vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int edges_row_item = stoi(edges_row_temp[j]);

                edges[i][j] = edges_row_item;
            }
        }

        string s_temp;
        getline(cin, s_temp);

        int s = stoi(ltrim(rtrim(s_temp)));

        vector<int> result = bfs(n, m, edges, s);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
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

