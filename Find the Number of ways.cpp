class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
         int n = points.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                int ax = points[i][0], ay = points[i][1];
                int bx = points[j][0], by = points[j][1];

                // Condition: A upper-left of B
                if (ax <= bx && ay >= by && (ax < bx || ay > by)) {
                    bool valid = true;

                    for (int k = 0; k < n; k++) {
                        if (k == i || k == j) continue;
                        int cx = points[k][0], cy = points[k][1];

                        // Check if C is inside rectangle (including border)
                        if (ax <= cx && cx <= bx && by <= cy && cy <= ay) {
                            valid = false;
                            break;
                        }
                    }

                    if (valid) count++;
                }
            }
        }

        return count;
    }
};
