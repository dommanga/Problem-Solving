#include <bits/stdc++.h>

using namespace std;

string which_material(long long N, long long K)
{
    if (N == 1)
    {
        switch (K)
        {
        case 1:
            return "upper bread";
        case 2:
            return "patty";
        case 3:
            return "lettuce";
        case 4:
            return "patty";
        case 5:
            return "lower bread";
        }
    }

    long long hamburger_length_lower = 5;
    for (long long i = 2; i <= N - 1; i++)
    {
        hamburger_length_lower = hamburger_length_lower * 2 + 3;
    }
    if (K == 1)
        return "upper bread";
    else if (K == hamburger_length_lower + 2)
        return "lettuce";
    else if (K == 2 * hamburger_length_lower + 3)
        return "lower bread";
    else if (K < hamburger_length_lower + 2)
        return which_material(N - 1, K - 1);
    else
        return which_material(N - 1, K - hamburger_length_lower - 2);
}

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        long long N, K;
        cin >> N >> K;

        cout << which_material(N, K) << endl;
    }
}