#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);

    vector<int> lotto;

    for (int i = 0; i < 6; i++)
    {
        int num;
        cin >> num;

        lotto.push_back(num);
    }

    sort(lotto.begin(), lotto.end());

    long long int N;
    cin >> N;

    long long int total_prize = 0;

    for (int i = 0; i < N; i++)
    {
        vector<int> my_lotto;

        int correct_num = 0;

        for (int i = 0; i < 6; i++)
        {
            int my_num;
            cin >> my_num;

            int min = 0;
            int max = lotto.size() - 1;

            while (max != min)
            {
                int mid = (min + max + 1) / 2;

                if (lotto[mid] > my_num)
                {
                    max = mid - 1;
                }
                else
                {
                    min = mid;
                }
            }

            if (lotto[min] == my_num)
                correct_num++;
        }

        if (correct_num == 6)
            total_prize += 100000000;
        else if (correct_num == 5)
            total_prize += 1000000;
        else if (correct_num == 4)
            total_prize += 50000;
        else if (correct_num == 3)
            total_prize += 5000;
    }

    cout << total_prize;
}