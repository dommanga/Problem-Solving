#include <bits/stdc++.h>

using namespace std;

vector<int> merge_sort(vector<int> v)
{
    if (v.size() > 1)
    {
        int mid = (v.size() + 1) / 2;
        vector<int> left_v = merge_sort(vector<int>(v.begin(), v.begin() + mid));
        vector<int> right_v = merge_sort(vector<int>(v.begin() + mid, v.end()));

        vector<int> result(left_v.size() + right_v.size());

        merge(left_v.begin(), left_v.end(), right_v.begin(), right_v.end(), result.begin());

        for (int k = 0; k < result.size(); k++)
        {
            result[k] += k;
        }

        return result;
    }

    return v;
}

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        vector<int> arr;
        for (int j = 0; j < N; j++)
        {
            int num;
            cin >> num;
            arr.push_back(num);
        }

        vector<int> result = merge_sort(arr);

        for (int k = 0; k < result.size(); k++)
        {
            cout << result[k];
            if (k != result.size() - 1) // !last num
                cout << " ";
        }
        cout << endl;
    }
}