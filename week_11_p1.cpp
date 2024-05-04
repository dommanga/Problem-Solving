#include <bits/stdc++.h>

using namespace std;

long long int dp[101][10001];
long long int v[101];
long long int w[101];

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int N, K;

    cin >> N >> K;

    for (int i = 1; i <= N; i++)
    {
        cin >> v[i];
    }

    for (int i = 1; i <= N; i++)
    {
        cin >> w[i];
    }

    long long int Max_happiness = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            Max_happiness = max(Max_happiness, dp[N][j] * (K - j));
        }
    }

    cout << Max_happiness;
}