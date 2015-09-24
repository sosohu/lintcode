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
		int res = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(d[i][j] == 0){
					dfs(A, d, i, j, n, m);
				}
				res = max(res, d[i][j]);
			}
		}
		return res;
    }

	void dfs(vector<vector<int>> &A, vector<vector<int>> &d, int i, int j, int n, int m){
		if(d[i][j] != 0)	return;
		d[i][j] = 1;
		if(i + 1 < n && A[i][j] < A[i+1][j]){
			dfs(A, d, i+1, j, n, m);
			d[i][j] = max(d[i][j], d[i+1][j] + 1);
		}
		if(i - 1 > -1 && A[i][j] < A[i-1][j]){
			dfs(A, d, i-1, j, n, m);
			d[i][j] = max(d[i][j], d[i-1][j] + 1);
		}
		if(j + 1 < m && A[i][j] < A[i][j+1]){
			dfs(A, d, i, j+1, n, m);
			d[i][j] = max(d[i][j], d[i][j+1] + 1);
		}
		if(j - 1 > -1 && A[i][j] < A[i][j-1]){
			dfs(A, d, i, j-1, n, m);
			d[i][j] = max(d[i][j], d[i][j-1] + 1);
		}
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
