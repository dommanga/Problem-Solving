#include <bits/stdc++.h>

using namespace std;

vector<int> h_;
vector<int> w_;
long long int N, M;

bool test(long long int mid)
{
    long long int Num = 0;

    for (int i = 0; i < N; i++)
    {
        Num += (h_[i] / mid) * (w_[i] / mid);
    }
    return M <= Num;
}

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        long long int h_length;
        cin >> h_length;
        h_.push_back(h_length);
    }

    for (int i = 0; i < N; i++)
    {
        long long int w_length;
        cin >> w_length;
        w_.push_back(w_length);
    }

    cin >> M;

    long long int Min = 1;
    long long int Max = 1000000;

    while (Min != Max)
    {
        long long int mid = (Min + Max + 1) / 2;

        if (test(mid))
            Min = mid;
        else
            Max = mid - 1;
    }

    if (Max == 1)
    {
        if (!test(Max))
        {
            cout << -1;
            return 0;
        }
    }

    cout << Max;
}
