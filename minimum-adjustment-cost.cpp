#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        // write your code here
		int n = A.size();
		vector<vector<int> > dp(n+1, vector<int>(101, 0));
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 100; j++){
				int low = max(1, j - target);
				int high = min(100, j + target);
				dp[i][j] = INT_MAX;
				for(int k = low; k <= high; k++){
					dp[i][j] = min(dp[i][j], dp[i-1][k]);
				}
				dp[i][j] += abs(A[i-1] - j);
			}
		}
		return *min_element(dp[n].begin() + 1, dp[n].end());
    }
};

int main(){
	vector<int> A{20,25,35,45,55,65,75,85,25,35,45,55,15,15,15,7,2,11,15,11,15};
	Solution sl;
	cout<<sl.MinAdjustmentCost(A, 10)<<endl;
}

