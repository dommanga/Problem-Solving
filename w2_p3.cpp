#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<int>> mat;
    int col, row;
    cin >> col >> row;

    mat.resize(col, vector<int>(row, 0));

    for (int i = 0; i < col; i++)
    {
        int temp;
        for (int j = 0; j < row; j++)
        {
            cin >> temp;
            mat[i][j] = temp;
        }
    }
    int max_sum = 0;

    int row_temp = 0;
    for (int i = 0; i < col; i++)
    {
        row_temp = accumulate(mat[i].begin(), mat[i].end(), 0);

        for (int j = 0; j < row; j++)
        {
            int col_temp = 0;
            for (int s = 0; s < col; s++)
            {
                col_temp += mat[s][j];
            }

            int sum = row_temp + col_temp - mat[i][j];
            if (sum > max_sum)
                max_sum = sum;
        }
    }

    cout << max_sum;
}