#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /**
     * @param matrix an integer matrix
     * @return the coordinate of the left-up and right-down number
     */
    vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) {
        // Write your code here
		int n = matrix.size();
		int m = matrix[0].size();
		for(int i = 0; i < n; i++){
			vector<int>	line(m, 0);
			for(int l = 1; l <= n - i; l++){
				unordered_map<int, int> table;
				for(int j = 0; j < m; j++){
					line[j] = line[j] + matrix[i + l - 1][j];
				}
				vector<int>	sum(m, line[0]);
				for(int j = 1; j < m; j++){
					sum[j] = sum[j-1] + line[j];
				}
				for(int j = 0; j < m; j++){
					if(sum[j] == 0){
						return vector<vector<int>>{{i, 0},{i + l - 1, j}};
					}else if(table.count(sum[j])){
						return vector<vector<int>>{{i, table[sum[j]] + 1}, {i + l -1 , j}};
					}else{
						table[sum[j]] = j;
					}
				}
			}
		}
		return vector<vector<int>>{{},{}};
    }
};

int main(){
	vector<vector<int>> matrix = {{1,5,7},{3,7,-8},{4,-8,9}};
	Solution sl;
	vector<vector<int>> res = sl.submatrixSum(matrix);
	for(int i = 0; i < res.size(); i++){
		for(int j = 0; j < res[i].size(); j++)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}
}
