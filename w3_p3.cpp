#include <bits/stdc++.h>
#define total_top_num 4

using namespace std;

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);

    map<int, int> container;
    int N;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int product;
        cin >> product;

        container.insert({product, i + 1});
    }

    int ppl;
    cin >> ppl;

    for (int i = 0; i < ppl; i++)
    {
        int request;
        cin >> request;

        if (container.find(request) != container.end())
        {
            if (container[request] > 0)
            {
                cout << container[request] << endl;
                container[request] = -1;
            }
            else
                cout << "empty" << endl;
        }
        else
            cout << "invalid" << endl;
    }
}