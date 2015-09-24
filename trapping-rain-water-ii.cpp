#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class cmp{
public:
	bool operator()(const pair<int, vector<int>> lhs, const pair<int, vector<int>> rhs){
		return lhs.first > rhs.first;
	}
};

class Solution {
public:
	typedef priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, cmp> Priority;
    /**
     * @param heights: a matrix of integers
     * @return: an integer
     */
    int trapRainWater(vector<vector<int>> &heights) {
		int n = heights.size();
		int m = heights[0].size();
		vector<vector<bool>> visited(n, vector<bool>(m, false));
	 	Priority q;
		for(int i = 0; i < n; i++){
			q.push(make_pair(heights[i][0], vector<int>{i, 0}));
			visited[i][0] = true;
			if(m > 1){
				q.push(make_pair(heights[i][m-1], vector<int>{i, m-1}));
				visited[i][m-1] = true;
			}
		}
		for(int j = 1; j < m-1; j++){
			q.push(make_pair(heights[0][j], vector<int>{0, j}));
			visited[0][j] = true;
			if(n > 1){
				q.push(make_pair(heights[n-1][j], vector<int>{n-1, j}));
				visited[n-1][j] = true;
			}
		}
		int res = 0;
		while(!q.empty()){
			int i = (q.top().second)[0];
			int j = (q.top().second)[1];
			q.pop();
			res = res + dfs(heights, q, visited, i+1, j, n, m, heights[i][j]);
			res = res + dfs(heights, q, visited, i-1, j, n, m, heights[i][j]);
			res = res + dfs(heights, q, visited, i, j+1, n, m, heights[i][j]);
			res = res + dfs(heights, q, visited, i, j-1, n, m, heights[i][j]);
		}
		return res;
	}

	int dfs(vector<vector<int>> &heights, Priority &q, 
			vector<vector<bool>> &visited, int i, int j, int n, int m, int height){
		if(i < 0 || j < 0 || i >= n || j >= m )	return 0;
		int res = 0;
		if(!visited[i][j]){
			if(height > heights[i][j]) res = height - heights[i][j];
			heights[i][j] = max(height, heights[i][j]);
			q.push(make_pair(max(height, heights[i][j]), vector<int>{i, j}));
			visited[i][j] = true;
		}
		return res;
	}
};

int main(){
	vector<vector<int>> heights = {{12,13,0,12},{13,4,13,12},{13,8,10,12},{12,13,12,12},{13,13,13,13}};
	Solution sl;
	cout<<sl.trapRainWater(heights)<<endl;
}
