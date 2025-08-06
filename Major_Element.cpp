class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         unordered_map<int, int> count;
        int n = nums.size();
        vector<int> result;
        for (int num : nums) {
            count[num]++;
        }

        // Check for elements appearing more than ⌊n/3⌋ times
        for (auto& pair : count) {
            if (pair.second > n / 3) {
                result.push_back(pair.first);
            }
        }

        return result;
    }
};
