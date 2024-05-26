#include <bits/stdc++.h>

using namespace std;

long long int dp[1005][1005];

long long int nCr(int n, int r)
{
    if (dp[n][r])
        return dp[n][r];
    if (r == 0 || n == r)
        return 1;
    return dp[n][r] = (nCr(n - 1, r) + nCr(n - 1, r - 1)) % 1000000007;
}

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int T;
    cin >> T;
    int n, r;

    for (int i = 0; i < T; i++)
    {
        cin >> n >> r;
        cout << nCr(n, r) << endl;
    }
}
