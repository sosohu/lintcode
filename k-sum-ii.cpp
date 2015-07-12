class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer 
     */
     
    void backtrack(vector<int> &A, vector<vector<int> > &res, vector<int> &trace,
                    int pos, int n, int k, int target){
        if(k == 0 && target == 0){
            res.push_back(trace);
            return;
        }
        if(pos == n || k == 0)  return;
        backtrack(A, res, trace, pos+1, n, k, target);
        trace.push_back(A[pos]);
        backtrack(A, res, trace, pos+1, n, k-1, target - A[pos]);
        trace.pop_back();
    }
     
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        // write your code here
        vector<vector<int> > res;
        vector<int> trace;
        backtrack(A, res, trace, 0, A.size(), k, target);
        return res;
    }
};


