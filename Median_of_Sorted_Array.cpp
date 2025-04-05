class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
                nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    
        sort(nums1.begin(), nums1.end());
    
        
            int n = nums1.size();
            if (n % 2 != 0) {
                
                return nums1[n / 2];
            } else {
                
                return (nums1[n / 2 - 1] + nums1[n / 2]) / 2.0;
            }
        }
    };
    

// Optimization: O(log(min(n, m))) time complexity and O(1) space complexity
class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            // Ensure nums1 is the smaller array
            if (nums1.size() > nums2.size()) {
                return findMedianSortedArrays(nums2, nums1);
            }
    
            int x = nums1.size();
            int y = nums2.size();
            int low = 0, high = x;
    
            while (low <= high) {
                int partitionX = (low + high) / 2;
                int partitionY = (x + y + 1) / 2 - partitionX;
    
                int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
                int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];
    
                int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
                int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];
    
                if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                    // Found the correct partition
                    if ((x + y) % 2 == 0) {
                        return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                    } else {
                        return max(maxLeftX, maxLeftY);
                    }
                } else if (maxLeftX > minRightY) {
                    // Move left
                    high = partitionX - 1;
                } else {
                    // Move right
                    low = partitionX + 1;
                }
            }
    
            throw std::invalid_argument("Input arrays are not sorted properly.");
        }
    };
    