#include <bits/stdc++.h>

using namespace std;

long long int gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long int lcm(long long int a, long long int b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int T;
    cin >> T;
    long long int a, b, c;

    for (int i = 0; i < T; i++)
    {
        cin >> a >> b >> c;
        cout << gcd(a, gcd(b, c)) << " ";
        cout << lcm(a, lcm(b, c)) << endl;
    }
}
