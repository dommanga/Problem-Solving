#include <bits/stdc++.h>
#define total_top_num 4

using namespace std;

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int command_num;

    stack<int> tower[total_top_num];

    cin >> command_num;
    for (int i = 0; i < command_num; i++)
    {
        string command;
        cin >> command;
        if (command == "stack")
        {
            int tower_num, y;
            cin >> tower_num >> y;

            tower[tower_num - 1].push(y);
        }
        else if (command == "pop")
        {
            int tower_num;
            cin >> tower_num;

            if (!tower[tower_num - 1].empty())
                tower[tower_num - 1].pop();
        }
        else if (command == "top")
        {
            int top_max = -1;

            for (int i = 0; i < total_top_num; i++)
            {
                if (!tower[i].empty() && tower[i].top() > top_max)
                    top_max = tower[i].top();
            }
            cout << top_max << endl;
        }
    }
}