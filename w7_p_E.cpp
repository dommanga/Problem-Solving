#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    int plus, minus;
    cin >> plus >> minus;

    vector<int> number_card;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        number_card.push_back(num);
    }

    sort(number_card.begin(), number_card.end());

    int sum = 0;
    int idx = 0;

    if (minus > 1)
        if (M == 0)
        {
            sum -= accumulate(number_card.begin(), number_card.begin() + minus, 0);
        }
        else
        {
            sum = accumulate(number_card.begin() + 1, number_card.begin() + minus, 0) - number_card[0];
        }
    else if (minus > 0)
        sum -= number_card[0];

    idx = minus;

    sum += accumulate(number_card.begin() + idx, number_card.end(), 0);

    cout << sum;
}