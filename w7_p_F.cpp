#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

long long int compute_K(int bal)
{
    int cur_bal = 0;
    long long int i = 0;
    long long int num_K = 1;

    int max = arr[i];
    int min = arr[i];

    while (true)
    {
        if (max < arr[i])
            max = arr[i];
        if (min > arr[i])
            min = arr[i];

        int pushed_bal = max - min;

        if (pushed_bal <= bal)
        {
            cur_bal = pushed_bal;
            i++;
            if (arr.size() == i)
                break;
        }
        else
        {
            max = arr[i];
            min = arr[i];
            num_K++;
        }
    }
    return num_K;
}

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);

    long long int N, K;

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        int elem;
        cin >> elem;
        arr.push_back(elem);
    }

    int min_bal = 0;
    int max_bal = *max_element(arr.begin(), arr.end()) - *min_element(arr.begin(), arr.end());

    while (min_bal != max_bal)
    {
        int mid_bal = (min_bal + max_bal) / 2;

        if (K >= compute_K(mid_bal))
        {
            max_bal = mid_bal;
        }
        else
            min_bal = mid_bal + 1;
    }

    cout << min_bal;
}