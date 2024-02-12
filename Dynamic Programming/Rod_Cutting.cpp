#include <iostream>
#include <vector>
using namespace std;

int solve(int v[], int i, int target, vector<vector<int>> &dp) {
    if (i < 0 || target == 0) return 0;
    if (i == 0) return target * v[0];

    if (dp[i][target] != -1) return dp[i][target];
    int nottake = solve(v, i - 1, target, dp);
    int take = 0;
    if (target - i - 1 >= 0)
        take = solve(v, i, target - i - 1, dp) + v[i];
    return dp[i][target] = max(take, nottake);
}

int cutRod(int price[], int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solve(price, n - 1, n, dp);
}

int main() {
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(price) / sizeof(price[0]);
    cout << "Maximum obtainable value is " << cutRod(price, size) << endl;
    return 0;
}
