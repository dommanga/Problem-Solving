#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int N, K;
    string S;

    cin >> N >> K;
    cin >> S;

    for (int i = 0; i < N; i++)
    {
        if (S[i] == 'A')
            continue;
        int count = 'Z' - S[i] + 1;
        if (count <= K)
        {
            K -= count;
            S[i] = 'A';
        }
    }

    for (int i = 0; i < K; i++)
    {
        if (S[N - 1] == 'Z')
            S[N - 1] = 'A';
        else
        {
            S[N - 1]++;
        }
    }

    cout << S;
}