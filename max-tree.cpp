#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

class Solution {
public:
    /**
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode* maxTree(vector<int> A) {
        // write your code here
		int n = A.size();
		return mergeMaxTree(A, 0, n-1);
    }

	TreeNode *mergeMaxTree(vector<int> &A, int begin, int end){
		if(begin > end)	return NULL;
		if(begin == end)	return new TreeNode(A[(begin + end) / 2]);
		int mid = (begin + end) / 2;
		TreeNode *left = mergeMaxTree(A, begin, mid);
		TreeNode *right = mergeMaxTree(A, mid+1, end);
		return mergeTree(left, right);
	}

	TreeNode *mergeTree(TreeNode *lhs, TreeNode *rhs){
		if(!lhs || !rhs)	return rhs? rhs : lhs;
		if(lhs->val > rhs->val){
			lhs->right = mergeTree(lhs->right, rhs);
			return lhs;
		}else{
			rhs->left = mergeTree(lhs, rhs->left);
			return rhs;
		}	
	}
};


int main(){

}
