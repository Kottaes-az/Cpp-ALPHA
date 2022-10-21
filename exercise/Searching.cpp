#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define MaxNode 20
#define MAX 2000
#define StartNode 1

vector<vector<int>> map;

void dfs_stack(int start, int n)
{
    vector<int> visited;
    for (int i = 0; i <= n; i++) visited[i] = 0;
    visited[start] = 1;
    stack<int> s;
    cout << start << " ";
    for (int i = 1; i <= n; i++)
        if (map[i][start] == 1 && !visited[i]) {
            visited[i] = 1;
            s.push(i);
        }
    while (!s.empty()) {
        int s_top = s.top();
        visited[s_top] = 1;
        cout << s_top << " ";
        s.pop();
        for (int i = 1; i <= n; i++)
            if (map[i][s_top] == 1 && !visited[i]) {
                visited[i] = 1;
                s.push(i);
            }
    }
}

int main(int argc, const char *argv[])
{
    int num_edge, num_node;
    int x, y;
    cout << "Input number of nodes and edges >" << endl;
    cin >> num_node >> num_edge;
    for (int i = 0; i < num_node; i++)
        for (int j = 0; j < num_node; j++) map[i][j] = 0;

    for (int i = 1; i <= num_edge; i++) {
        cin >> x >> y;
        map[x][y] = map[y][x] = 1;
    }

    dfs_stack(StartNode, num_node);

    return 0;
}