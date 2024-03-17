#include <bits/stdc++.h>

using namespace std;

vector<int> bro_flavor(3, 0);
vector<vector<int>> record;

void give_fruit(int idx, vector<int> &fruit, int &min_diff)
{
    if (idx == fruit.size())
    {
        int diff_cur = *max_element(bro_flavor.begin(), bro_flavor.end()) - *min_element(bro_flavor.begin(), bro_flavor.end());
        min_diff = min(min_diff, diff_cur);

        return;
    }
    for (int i = 0; i < 3; i++)
    {
        if (record[i].size() == 3)
            continue;
        bro_flavor[i] += fruit[idx];
        record[i].push_back(fruit[idx]);
        give_fruit(idx + 1, fruit, min_diff);
        record[i].pop_back();
        bro_flavor[i] -= fruit[idx];
    }
}

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);

    record.push_back(vector<int>());
    record.push_back(vector<int>());
    record.push_back(vector<int>());

    int fruit_total = 10;
    vector<int> flavor_fruit;

    for (int i = 0; i < fruit_total; i++)
    {
        int flavor;
        cin >> flavor;
        flavor_fruit.push_back(flavor);
    }

    int min_diff = INT_MAX;

    sort(flavor_fruit.begin(), flavor_fruit.end());

    for (int i = 0; i < 10; i++)
    {
        vector<int> remain = flavor_fruit;
        remain.erase(remain.begin() + i);
        fill(bro_flavor.begin(), bro_flavor.end(), 0);
        give_fruit(0, remain, min_diff);
    }

    cout << min_diff;
}