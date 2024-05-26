#include <bits/stdc++.h>

using namespace std;

vector<int> friend_num(100002, -1);

void addEdge(vector<vector<int>> &g, int a, int b)
{
    g[a].push_back(b);
    g[b].push_back(a);
}

void dfs(int node, vector<vector<int>> &graph, vector<int> &visited, vector<int> &comp)
{
    stack<int> s;
    s.push(node);
    visited[node] = 1;

    while (!s.empty())
    {
        int cur = s.top();
        s.pop();
        comp.push_back(cur);

        for (int neighbor : graph[cur])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = 1;
                s.push(neighbor);
            }
        }
    }
}

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int N, M;

    cin >> N >> M;
    vector<vector<int>> graph(N + 1);

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(graph, u, v);
    }

    vector<int> visited(N + 1);

    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            vector<int> comp;
            dfs(i, graph, visited, comp);
            int size = comp.size();
            friend_num[i] = size - 1;

            for (int c : comp)
            {
                friend_num[c] = size - 1;
            }
        }
    }

    int query;
    cin >> query;

    for (int i = 0; i < query; i++)
    {
        int student_num;
        cin >> student_num;

        cout << friend_num[student_num] << endl;
    }
}