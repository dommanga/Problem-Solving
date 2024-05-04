#include <bits/stdc++.h>

using namespace std;

long long int dp[2][100001];
long long int v[101];
long long int w[101];

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int N, K;

    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        cin >> v[i];

    for (int i = 1; i <= N; i++)
        cin >> w[i];

    long long int Max_happiness = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            dp[1][j] = dp[0][j];

            if (j >= w[i])
                dp[1][j] = max(dp[0][j], dp[0][j - w[i]] + v[i]);

            Max_happiness = max(Max_happiness, dp[1][j] * (K - j));

            /*-----------  more visible and efficient implementation  ------------*/
            /*
            dp[i % 2][j] = dp[(i - 1) % 2][j];

            if (j >= w[i])
                dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[(i - 1) % 2][j - w[i]] + v[i]);

            Max_happiness = max(Max_happiness, dp[i % 2][j] * (K - j));
            */
        }
        for (int j = 1; j <= K; j++)
        {
            dp[0][j] = dp[1][j];
        }
    }

    cout << Max_happiness;
}