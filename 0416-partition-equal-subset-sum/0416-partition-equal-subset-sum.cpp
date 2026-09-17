class Solution {
public:
    bool solve(int indx , int target , vector<int> &arr , vector<vector<int>> &dp){
        if(target == 0){
            return true;
        }
        if(indx == 0){
            return (arr[0] == target);
        }
        if(dp[indx][target] != -1){
            return dp[indx][target];
        }
        bool not_pick = solve(indx - 1 , target , arr , dp);
        bool pick = false;
        if(arr[indx] <= target){
            pick = solve(indx - 1 , target - arr[indx] , arr, dp);
        }
        return dp[indx][target] = pick || not_pick;
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        int indx = nums.size() - 1;
        for(auto x : nums){
            totalSum += x;
        }
        if(totalSum % 2 != 0){
            return false;
        }
        int target = totalSum / 2;
        int n = nums.size();
        vector<vector<bool>> dp(n, vector<bool>(target + 1 , false));
        for(int i = 0 ; i < nums.size(); i++){
            dp[i][0] = true;
        }
        if(nums[0] <= target) dp[0][nums[0]] = true;
        for(int i = 1 ; i < nums.size(); i++){
            for(int j = 1 ; j <= target ; j++){
                bool not_take = dp[i - 1][j];
                bool take = false;
                if(nums[i] <= j){
                    take = dp[i-1][j-nums[i]];
                }
                dp[i][j] = take || not_take;
            }
        }
        return dp[indx][target];
    }
};