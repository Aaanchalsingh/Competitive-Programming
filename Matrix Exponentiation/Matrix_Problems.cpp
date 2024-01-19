// FIBONACCI IN LOG(N) TIME LOG(N) SPACE
#include <bits/stdc++.h>
using namespace std;
class Mat
{
public:
    int size;
    vector<vector<int>> matrix;
    Mat(int s)
    {
        size = s;
        matrix = vector<vector<int>>(size, vector<int>(size, 0));
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
    void identity()
    {
        for (int i = 0; i < size; i++)
            matrix[i][i] = 1;
    }
    Mat operator+(Mat B)
    {
        Mat res = Mat(size);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                res.matrix[i][j] = matrix[i][j] + B.matrix[i][j];
            }
        }
        return res;
    }
    Mat operator*(Mat B)
    {
        Mat res = Mat(size);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                for (int k = 0; k < size; k++)
                    res.matrix[i][j] += matrix[i][k] * B.matrix[k][j];
            }
        }
        return res;
    }
    Mat operator*(int B)
    {
        Mat res = Mat(size);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
                res.matrix[i][j] += matrix[i][j] * B;
        }
        return res;
    }
    Mat operator^(int b)
    {
        Mat a(*this);
        Mat res(size);
        res.identity();
        while (b)
        {
            if (b & 1)
                res = res * a;
            b >>= 1;
            a = a * a;
        }
        return res;
    }
};
int main()
{
    Mat a(5), b(5);
    a.identity();
    b.identity();
    Mat c = a + b;
    c.print();
    Mat d = c * c;
    d.print();
    d = c * 10;
    d.print();
    d = d ^ 2;
    d.print();
    return 0;
}