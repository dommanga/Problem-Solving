#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int N;
    vector<int> v;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    int add_sum;
    int first = 1;

    do
    {
        int temp = 0;
        for (int i = 0; i < v.size() - 1; i++)
        {
            temp += v[i] * v[i + 1];
        }
        if (first)
        {
            add_sum = temp;
            first = 0;
        }
        if (add_sum < temp)
        {
            add_sum = temp;
        }

    } while (next_permutation(v.begin(), v.end()));

    cout << add_sum;
}