void findCombination(int indx , int target, vector<int> &arr, vector<vector<int>> &ans , vector<int> &ds){
    if(indx == arr.size()){
        if(target == 0){
            ans.push_back(ds);
        }
        return;
    }
    if(arr[indx] <= target){
        ds.push_back(arr[indx]);
        findCombination(indx , target - arr[indx] , arr, ans , ds);
        ds.pop_back();
    }
        findCombination(indx+1 , target  , arr, ans , ds);

}
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> ans;
      vector<int> ds;
      findCombination(0 , target , candidates , ans , ds);
      return ans;
    }
};
