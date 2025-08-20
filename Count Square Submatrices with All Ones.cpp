class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows , vector<int>(cols , 0));
        for(int j = 0 ; j < cols ; j++) dp[0][j] = matrix[0][j];
        for(int i = 0 ; i < rows ; i++) dp[i][0] = matrix[i][0];
        for(int i = 1 ; i < rows ; i++){
            for(int j = 1 ; j < cols ; j++){
                if(matrix[i][j] == 1){
                dp[i][j] = 1 + min(dp[i -1][j] , min(dp[i-1][j-1] , dp[i][j-1]));
                }
                else{
                    dp[i][j] = 0;
                    
                }

            }
        }
        int sum = 0 ;
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                sum+= dp[i][j];
            }
        }
        return sum;
    }
};
