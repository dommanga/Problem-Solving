#include <bits/stdc++.h>

using namespace std;

vector<int> v_sum;

void possible_sum(vector<int> &card_set)
{
    if (card_set.empty())
    {
        v_sum.push_back(0);

        return;
    }
    for (int i = 0; i < card_set.size(); i++)
    {
        v_sum.push_back(accumulate(card_set.begin(), card_set.end(), 0));

        int temp = card_set.back();
        card_set.pop_back();

        possible_sum(card_set);

        card_set.insert(card_set.begin(), temp);
    }
}

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> num_cards;
    for (int i = 0; i < N; i++)
    {
        int card;
        cin >> card;
        num_cards.push_back(card);
    }

    possible_sum(num_cards);

    sort(v_sum.begin(), v_sum.end());
    v_sum.erase(unique(v_sum.begin(), v_sum.end()), v_sum.end());

    for (int i = 0; i < v_sum.size(); i++)
    {
        cout << v_sum[i] << endl;
    }
}