#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
		int n = A.size();
		vector<vector<int>> dp(2, vector<int>(m+1, 0));

		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				dp[i % 2][j] = 0;
				if(A[i-1] <= j){
					dp[i % 2][j] = A[i-1] + dp[(i - 1) % 2][j-A[i-1]];
				}
				dp[i % 2][j] = max(dp[i % 2][j], dp[(i - 1) % 2][j]);
			}
		}
		return dp[n % 2][m];
    }
};

int main(){
	Solution sl;
	vector<int> A{3,4,8,5};
	cout<<sl.backPack(10, A)<<endl;
}
