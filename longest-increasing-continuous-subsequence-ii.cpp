#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param A an integer matrix
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequenceII(vector<vector<int>>& A) {
        // Write your code here
		bool isOk = false;
		int n = A.size();
		if(n == 0)	return 0;
		int m = A[0].size();
		vector<vector<int>>	d(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				getDu(A, d, i, j, n, m);
			}
		}
		int res = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(d[i][j] == 0){
					int path = 0;
					path = dfs(A, i, j, n, m);
					res = max(res, path);
				}
			}
		}
		return res;
    }

	void getDu(vector<vector<int>> &A, vector<vector<int>> &dp, int i, int j, int n, int m){
		if(i+1 < n && A[i][j] > A[i+1][j])	dp[i][j]++;	
		if(j+1 < m && A[i][j] > A[i][j+1])	dp[i][j]++;	
		if(i-1 > -1 && A[i][j] > A[i-1][j])	dp[i][j]++;	
		if(j-1 > -1 && A[i][j] > A[i][j-1])	dp[i][j]++;	
	}

	int dfs(vector<vector<int>> &A, int i, int j, int n, int m){
		int res = 0;
		if(i+1 < n && A[i][j] < A[i+1][j]){
			int path = dfs(A, i+1, j, n, m);	
			res = max(res, path);
		}
		if(j+1 < m && A[i][j] < A[i][j+1]){
			int path = dfs(A, i, j+1, n, m);	
			res = max(res, path);
		}
		if(i-1 > -1 && A[i][j] < A[i-1][j]){
			int path = dfs(A, i-1, j, n, m);	
			res = max(res, path);
		}	
		if(j-1 > -1 && A[i][j] < A[i][j-1]){
			int path = dfs(A, i, j-1, n, m);
			res = max(res, path);
		}
		res++;
		return res;
	}
};

int main(){
	vector<vector<int>> A{
 							 {1 ,2 ,3 ,4 ,5},
							 {16,17,24,23,6},
							  {15,18,25,22,7},
							  {14,19,20,21,8},
							  {13,12,11,10,9}
						};
	Solution sl;
	cout<<sl.longestIncreasingContinuousSubsequenceII(A)<<endl;
}
