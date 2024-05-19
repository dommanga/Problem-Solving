#include <bits/stdc++.h>

using namespace std;

const int Max = 102;
const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, -1, 1};

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;

    int arr[Max][Max];
    int dist[Max][Max];

    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++)
        {
            cin >> arr[i][j];
            dist[i][j] = -1;
        }

    queue<pair<int, int>> q;
    dist[1][1] = 0;
    q.push({1, 1});

    while (!q.empty())
    {
        int cur_r = q.front().first;
        int cur_c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int next_r = cur_r + dr[i];
            int next_c = cur_c + dc[i];

            if (arr[next_r][next_c] == 1)
                continue;
            else if (next_r > H || next_r < 1 || next_c > W || next_c < 1)
                continue;
            else if (dist[next_r][next_c] >= 0)
                continue;

            dist[next_r][next_c] = dist[cur_r][cur_c] + 1;
            q.push({next_r, next_c});
        }
    }

    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (dist[i][j] == -1)
                cout << "-";
            else
                cout << dist[i][j];
            if (j != W)
                cout << " ";
        }
        if (i != H)
            cout << endl;
    }
}