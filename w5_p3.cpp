#include <bits/stdc++.h>

using namespace std;

struct Potato
{
    int start, end;

    Potato(int s, int e)
    {
        start = s;
        end = e;
    }

    bool operator<(const Potato &other) const
    {
        if (end == other.end)
            return start < other.start;
        return end < other.end;
    }
};

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int N;
    cin >> N;

    // vector<Potato> potatoes;
    list<Potato> potatoes;

    for (int i = 0; i < N; i++)
    {
        int start, end;
        cin >> start >> end;
        Potato p(start, end);
        potatoes.push_back(p);
    }

    // sort(potatoes.begin(), potatoes.end());
    potatoes.sort();

    int today = 1;
    int eat_count = 0;
    int i = 0;
    int temp = 0;

    auto it = potatoes.begin();

    while (!potatoes.empty())
    {
        int eat_limit = 3;

        while (eat_limit > 0 && it != potatoes.end())
        {
            if (it->start <= today && it->end >= today)
            {
                eat_count++;
                eat_limit--;
                it = potatoes.erase(it);
            }
            else if (it->start < today)
            {
                it = potatoes.erase(it);
            }
            else
                it++;
        }
        today++;
        it = potatoes.begin();
    }
    cout << eat_count;
}