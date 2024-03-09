#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;

    list<int> a;

    for (int i = 0; i < N; i++)
    {
        string command;
        cin >> command;

        if (command == "push_front")
        {
            int element;
            cin >> element;
            a.push_front(element);
        }
        else if (command == "push_back")
        {
            int element;
            cin >> element;
            a.push_back(element);
        }
        else if (command == "pop_front")
        {
            if (a.empty())
                cout << "invalid" << endl;
            else
            {
                cout << a.front() << endl;
                a.pop_front();
            }
        }
        else if (command == "pop_back")
        {
            if (a.empty())
                cout << "invalid" << endl;
            else
            {
                cout << a.back() << endl;
                a.pop_back();
            }
        }
        else if (command == "front")
        {
            if (a.empty())
                cout << "invalid" << endl;
            else
                cout << a.front() << endl;
        }
        else if (command == "back")
        {
            if (a.empty())
                cout << "invalid" << endl;
            else
                cout << a.back() << endl;
        }
        else if (command == "size")
        {
            cout << a.size() << endl;
        }
        else if (command == "empty")
        {
            if (a.empty())
                cout << "empty" << endl;
            else
                cout << "not empty" << endl;
        }
    }
}