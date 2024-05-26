#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int T;
    cin >> T;
    int a, b;

    for (int i = 0; i < T; i++)
    {
        cin >> a >> b;
        vector<bool> isPrime(b + 1, true);
        for (int i = 2; i * i < b; i++)
        {
            if (isPrime[i])
                for (int j = i * i; j <= b; j += i)
                    isPrime[j] = false;
        }

        long long int cnt = 0;
        int start = a == 1 ? 2 : a;
        for (int i = start; i <= b; i++)
            if (isPrime[i])
                cnt++;

        cout << cnt << endl;
    }
}
