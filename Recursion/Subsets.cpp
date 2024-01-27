#include <bits/stdc++.h>
using namespace std;
 void solve(vector<int>& v, vector<vector<int>>& ans, int i,vector<int>& nums) {
        if (i >= nums.size()) {
            ans.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        solve(v, ans, i + 1,nums);
        v.pop_back();
        solve(v, ans, i+1,nums);
        return;
    }
int main(){

return 0;
}
class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {

    }
};