#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
		int n = A.size();
		vector<vector<int>> dp(2, vector<int>(m+1, 0));
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				dp[i % 2][j] = 0;
				if(A[i-1] <= j){
					dp[i % 2][j] = V[i-1] + dp[(i - 1) % 2][j - A[i - 1]];
				}
				dp[i % 2][j] = max(dp[i % 2][j], dp[(i - 1) % 2][j]);
			}
		}
		return dp[n % 2][m];
    }
};

int main(){
	Solution sl;
	vector<int> A{2, 3, 5, 7}, V{1, 5, 2, 4};
	cout<<sl.backPackII(10, A, V)<<endl;
}
