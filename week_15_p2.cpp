#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int deligent_teams = 0;

    for (int i = 0; i < N; i++)
    {
        vector<int> T(3);
        cin >> T[0] >> T[1] >> T[2];

        if (T[0] == -1)
            continue;
        if (T[1] == -1 && T[2] > -1)
            continue;

        if (T[1] == -1)
        {
            deligent_teams++;
            continue;
        }
        if (T[2] == -1)
            if (T[0] <= T[1])
            {
                deligent_teams++;
                continue;
            }
        if (T[0] <= T[1] && T[1] <= T[2])
            deligent_teams++;
    }

    cout << deligent_teams;
}