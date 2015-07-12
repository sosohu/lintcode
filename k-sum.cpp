class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    
	// O(n*k*target), O(n*k*target)
    int kSum(vector<int> A, int k, int target) {
        // wirte your code here
		//dp[i][j][p] means how many ways of selecting j elements from the first i elements where sum is target
        vector<vector<vector<int>>> dp(A.size()+1, vector<vector<int>>(k+1, vector<int>(target+1, 0)));
        
        for(int i = 1; i <= A.size(); i++){
            for(int j = 1; j <= min(i, k); j++){
                for(int p = 1; p <= target; p++){
                    dp[i][j][p] = dp[i-1][j][p];
                    if(p == A[i-1] && j == 1){
                        dp[i][j][p]++;
                    }else if(p > A[i-1]){
                        dp[i][j][p] += dp[i-1][j-1][p - A[i-1]];
                    }
                }
            }
        }
        return dp[A.size()][k][target];
    }
};

