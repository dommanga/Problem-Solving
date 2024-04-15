#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int N, Q;
    cin >> N;

    vector<int> point, query;

    for (int i = 0; i < N; i++)
    {
        int dot;
        cin >> dot;
        point.push_back(dot);
    }

    sort(point.begin(), point.end());

    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        int q;
        cin >> q;

        int min = 0;
        int max = point.size() - 1;

        while (min != max)
        {
            int mid = (min + max + 1) / 2;

            if (q >= point[mid])
                min = mid;
            else
                max = mid - 1;
        }

        if (min == 0)
        {
            cout << point[min + 1] << endl;
            continue;
        }
        else if (min == point.size() - 1)
        {
            cout << point[min - 1] << endl;
            continue;
        }

        int dis_right = abs(point[min + 1] - point[min]);
        int dis_left = abs(point[min] - point[min - 1]);

        int most_min = dis_right < dis_left ? min + 1 : min - 1;

        cout << point[most_min] << endl;
    }
}