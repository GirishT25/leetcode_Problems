class Solution {
public:

    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for(int i = 0 ; i < cards.size() ; i++){
          nums.push_back(1.0  * cards[i]);
        }
    return solve(nums);
    }
  bool solve(vector<double>& nums) {
        double epsilon = 1e-6;
        if (nums.size() == 1) {
            return fabs(nums[0] - 24.0) < epsilon;
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j) continue;

                vector<double> next;
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j) {
                        next.push_back(nums[k]);
                    }
                }

                double a = nums[i], b = nums[j];
                vector<double> candidates = {a + b, a - b, b - a, a * b};
                if (fabs(b) > epsilon) candidates.push_back(a / b);
                if (fabs(a) > epsilon) candidates.push_back(b / a);

                for (double val : candidates) {
                    next.push_back(val);
                    if (solve(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }
};
