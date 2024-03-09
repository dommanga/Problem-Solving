#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int R_nums[10];
    set<int> arr[10];

    for (int i = 0; i < 10; i++)
    {
        cin >> R_nums[i];
    }

    int iter = 1;
    int i = 0;

    for (int k = 0; k < 10; k++)
    {
        for (int i = 1; i <= sqrt(R_nums[k]); i++)
        {
            if (R_nums[k] % i == 0)
            {
                arr[k].insert(i);
                arr[k].insert(R_nums[k] / i);
            }
        }
    }

    // set 원소 개수 세기
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i].size() << endl;
    }
}