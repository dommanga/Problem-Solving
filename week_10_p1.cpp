#include <bits/stdc++.h>

using namespace std;

int arr[200001];
long long int f[200001];
long long int mod_num = 1000000007;

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i < K + 1; i++)
    {
        int loc;
        cin >> loc;
        arr[loc] = 1;
    }

    // f[n] is the number of cases to reach n-th location (0 ~ N+1)

    f[0] = 1;

    if (arr[1] == 1) // you can't reach 1-st location
        f[1] = 0;
    else
        f[1] = 1;

    if (arr[2] == 1) // you can't reach 2-nd location
        f[2] = 0;
    else
        f[2] = f[1] + f[0]; // you cam jump by 1 or 2 from 1-st or 0-th location to reach 2-nd location

    for (int i = 3; i <= N + 1; i++)
    {
        if (arr[i] == 1)
            f[i] = 0;
        else
            f[i] = (f[i - 1] + f[i - 2] + f[i - 3]) % mod_num;
    }

    cout << f[N + 1];
}