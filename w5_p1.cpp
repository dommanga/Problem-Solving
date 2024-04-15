#include <bits/stdc++.h>

#define MAX_stock_num 10
#define initial_money 1000

using namespace std;

vector<vector<int>> stocks(3);

void buy_stock(int &cur_money, int time)
{
    int to_buy = 0;
    vector<int> total_profit;
    vector<int> possible_num;

    for (int i = 0; i < 3; i++)
    {
        int profit = stocks[i][time + 1] - stocks[i][time];

        int num = cur_money / stocks[i][time];
        if (num > MAX_stock_num)
            num = MAX_stock_num;
        possible_num.push_back(num);

        total_profit.push_back(profit * possible_num[i]);
    }

    for (int i = 0; i + 1 < 3; i++)
    {
        if (total_profit[i + 1] > total_profit[to_buy])
        {
            to_buy = i + 1;
        }
    }

    if (total_profit[to_buy] <= 0)
        return;

    cur_money += total_profit[to_buy];
}

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int N;
    int my_money = initial_money;

    cin >> N;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int price;
            cin >> price;
            stocks[i].push_back(price);
        }
    }
    for (int time = 0; time + 1 < N; time++)
        buy_stock(my_money, time);

    cout << my_money;
}