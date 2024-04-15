#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> &v1, vector<int> &v2)
{
    return v1[1] > v2[1];
}

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> slimes;

    for (int i = 0; i < N; i++)
    {
        int slime;
        cin >> slime;
        slimes.push(slime);
    }

    int Q;
    cin >> Q;
    vector<vector<int>> query(Q);
    vector<int> print_mana(Q);

    for (int i = 0; i < Q; i++)
    {
        int q;
        cin >> q;
        query[i].push_back(i);
        query[i].push_back(q);
    }

    sort(query.begin(), query.end(), cmp);

    int total_mana = 0;

    for (int i = 0; i < Q; i++)
    {

        while (slimes.size() != query[i][1])
        {
            int s_1 = slimes.top();
            slimes.pop();

            int s_2 = slimes.top();
            slimes.pop();

            int s_sum = s_1 + s_2;
            total_mana += s_sum;

            slimes.push(s_sum);
        }

        print_mana[query[i][0]] = total_mana;
    }

    for (int i = 0; i < print_mana.size(); i++)
        cout << print_mana[i] << endl;
}
