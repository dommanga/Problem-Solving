#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> s(3);

    for (int i = 0; i < 3; i++)
    {
        cin >> s[i];
    }

    sort(s.begin(), s.end());

    string text = "PONIX";

    if (s[0][0] == 'k' && s[1][0] == 'l' && s[2][0] == 'p')
        text = "GLOBAL";

    cout << text;
}