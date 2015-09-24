#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySumII(vector<int>& A) {
        // Write your code here
        int n = A.size();
        if(n == 0)  return vector<int>();
		
		vector<int> tmp(2, 0), tmp_min(2, 0);
		int sum = 0;
        for(int i = 0; i < n; i++){
            sum = sum + A[i];
        }
		int res = getMaxSub(A, tmp);
		int minSub = getMinSub(A, tmp_min);
		if(minSub >= 0)	return vector<int>{0, n-1};
		if(minSub == sum)	return tmp;
		minSub = sum - minSub;
		if(res < minSub){
			tmp[0] = (tmp_min[1] + 1) % n;
			tmp[1] = (tmp_min[0] + n - 1) % n;
		}
        return tmp;
    }

	int getMaxSub(vector<int> &A, vector<int> &res){
		vector<int> dp(A.size(), 0), pos(A.size(), 0);
		int tmp = INT_MIN;
		for(int i = 0; i < A.size(); i++){
			dp[i] = A[i];
			pos[i] = i;
			if(i != 0 && dp[i-1] > 0){
				dp[i] = dp[i-1] + A[i];
				pos[i] = pos[i-1];
			}
			if(tmp < dp[i]){
				res[0] = pos[i];
				res[1] = i;
				tmp = dp[i];
			}
		}
		return tmp;
	}

	int getMinSub(vector<int> &A, vector<int> &res){
		vector<int> dp(A.size(), 0), pos(A.size(), 0);
		int tmp = INT_MAX;
		for(int i = 0; i < A.size(); i++){
			dp[i] = A[i];
			pos[i] = i;
			if(i != 0 && dp[i-1] < 0){
				dp[i] = dp[i-1] + A[i];
				pos[i] = pos[i-1];
			}
			if(tmp > dp[i]){
				res[0] = pos[i];
				res[1] = i;
				tmp = dp[i];
			}
		}
		return tmp;
	}
};

int main(){
	Solution sl;
	vector<int> A{-5,10,5,-3,1,1,1,-2,3,-4};
	vector<int> res = sl.continuousSubarraySumII(A);
	cout<<res[0]<<", "<<res[1]<<endl;
}
