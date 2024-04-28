#include <bits/stdc++.h>

using namespace std;

long long int N, F_N;
long long int mod_num = 1000000007;
int f[3];

struct Matrix
{
    int n;
    vector<vector<long long int>> mat;

    Matrix(int n) : n(n)
    {
        mat.resize(n, vector<long long int>(n, 0));
    }

    Matrix operator*(const Matrix &m) const
    {
        Matrix result(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    result.mat[i][j] += (mat[i][k] * m.mat[k][j]) % mod_num;

        return result;
    }

    static Matrix multiply(const Matrix &m, int pow)
    {
        if (pow == 0) // identity matrix
        {
            Matrix identity(m.n);
            for (int i = 0; i < m.n; i++)
                identity.mat[i][i] = 1;
            return identity;
        }

        Matrix divided = multiply(m, pow / 2);
        if (pow % 2 == 0)
        {
            return divided * divided;
        }
        else
        {
            return divided * divided * m;
        }
    }
};

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);

    cin >> N;

    Matrix rock_mat(3);

    for (int i = 0; i < 3; i++)
        rock_mat.mat[0][i] = 1;
    rock_mat.mat[1][0] = 1;
    rock_mat.mat[2][1] = 1;

    Matrix N_rock_result = rock_mat.multiply(rock_mat, N - 1);

    f[0] = f[1] = 1;
    f[2] = f[1] + f[0];

    F_N = 0;
    for (int k = 0; k < 3; k++)
    {
        F_N += N_rock_result.mat[0][k] * f[2 - k];
    }

    cout << F_N % mod_num;
}