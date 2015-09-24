#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraySumII(vector<int>& A, int start, int end) {
		int n = A.size(), res = 0;
		if(n == 0 || start > end)	return 0;
		for(int i = 0; i < n; i++){
			int sum  = 0;
			for(int j = i; j >= 0; j--){
				sum = sum + A[j];
				if(sum >= start && sum <= end){
					res++;
				}
			}
		}
		return res;
    }
};

int main(){
	Solution sl;
	vector<int> A{-1, -2, -3, -4};
	cout<<sl.subarraySumII(A, -3, -1)<<endl;
}
