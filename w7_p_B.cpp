#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);

    long long int N;

    cin >> N;

    stack<int> color;
    int trash = -1;
    int num_remove = 0;

    for (int i = 0; i < N; i++)
    {
        int b_1, b_2;
        int cur_color;
        cin >> b_1 >> b_2;

        if (b_1 == b_2)
            cur_color = b_1;
        else
            cur_color = trash;

        if (color.empty())
            color.push(cur_color);
        else
        {
            if (color.top() == cur_color && cur_color != trash)
            {
                num_remove += 4;
                color.pop();
            }
            else
            {
                color.push(cur_color);
            }
        }
    }

    cout << num_remove;
}