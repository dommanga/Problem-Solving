#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int student_num;
    int mid, fin, assign;

    cin >> student_num;
    int student[student_num];

    for (int i = 0; i < student_num; i++)
    {

        cin >> mid >> fin >> assign;
        int total_score;

        total_score = mid * 2 + fin * 3 + assign * 5;

        student[i] = total_score;
    }

    for (int i = 0; i < student_num; i++)
    {
        cout << student[i] << " ";

        if (student[i] >= 950)
            cout << "A+" << endl;
        else if (student[i] >= 900)
            cout << "A0" << endl;
        else if (student[i] >= 850)
            cout << "A-" << endl;
        else if (student[i] >= 800)
            cout << "B+" << endl;
        else if (student[i] >= 750)
            cout << "B0" << endl;
        else if (student[i] >= 700)
            cout << "B-" << endl;
        else if (student[i] >= 600)
            cout << "C+" << endl;
        else if (student[i] >= 500)
            cout << "C0" << endl;
        else if (student[i] >= 400)
            cout << "C-" << endl;
        else if (student[i] >= 300)
            cout << "D+" << endl;
        else if (student[i] >= 200)
            cout << "D0" << endl;
        else if (student[i] >= 100)
            cout << "D-" << endl;
        else
            cout << "F" << endl;
    }
}