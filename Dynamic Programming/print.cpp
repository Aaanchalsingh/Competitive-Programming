#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>> &v)
{
    int n = v.size();
    for (int k = 1; k < n; k++)
    {
        for (int j = k; j < n; j++)
        {
            int i = j - k;
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<int>> dp{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    print(dp);

    return 0;
}
