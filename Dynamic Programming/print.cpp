#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>> &dp)
{
    int n = dp.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                cout << dp[i][j] << " ";
            }
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - j == -1)
            {
                cout << dp[i][j] << " ";
            }
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - j == -2)
            {
                cout << dp[i][j] << " ";
            }
        }
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> dp{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    print(dp);

    return 0;
}
