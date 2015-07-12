#include <iostream>
#include <vector>
#include <algorithm>

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
        if(n == 0)  return 0;
        sort(A.begin(), A.end());
        int left = 0, right = n - 1, res = 0;
        while(left < right && A[right] - A[left] > target){
            res += A[right] - A[left] - target;
            left++;
            right--;
        }
        return res;
    }
};

int main(){
	vector<int> A{20,25,35,45,55,65,75,85,25,35,45,55,15,15,15,7,2,11,15,11,15};
	Solution sl;
	cout<<sl.MinAdjustmentCost(A, 10)<<endl;
}

