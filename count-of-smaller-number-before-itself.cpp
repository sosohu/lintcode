#include <iostream>
#include <vector>

using namespace std;

struct SegTreeNode{
	int val;
	int begin, end;
	SegTreeNode *left, *right;
	SegTreeNode(int begin, int end, int val = 0) : val(val), begin(begin),
					end(end), left(NULL), right(NULL){

	}
};

class SegTree{
public:
	SegTree(int begin = 0, int end = 0) : root(build(begin, end)){}

	SegTreeNode* build(int start, int end){
        if(start > end) return NULL;
        SegTreeNode *root = new SegTreeNode(start, end);
        if(start == end)    return root;
        int mid = (start + end) / 2;
        root->left = build(start, mid);
        root->right = build(mid+1, end);
        return root;
	}

	int query(int begin, int end){
		if(begin > end)	return 0;
		return query(root, begin, end);
	}

	void insert(int pos){
		insert(root, pos);
	}

private:
	int query(SegTreeNode *root, int begin, int end){
		if(root->begin == begin && root->end == end)	return root->val;
		if(begin > root->left->end)
			return query(root->right, begin, end);
		if(end < root->right->begin)
			return query(root->left, begin, end);
		return query(root->left, begin, root->left->end) 
				+ query(root->right, root->right->begin, end);
	}

	void insert(SegTreeNode *root, int pos){
		root->val++;
		if(root->begin == root->end){
			return;
		}
		if(pos <= root->left->end){
			insert(root->left, pos);
		}else{
			insert(root->right, pos);
		}
	}

private:
	SegTreeNode *root;
};

class Solution {
public:
	vector<int> countOfSmallerNumberII(vector<int> &A) {
        // write your code here
		vector<int> res(A.size(), 0);
		st = new SegTree(0, 10000);
		for(int i = 0; i < A.size(); i++){
			st->insert(A[i]);
			res[i] = st->query(0, A[i] - 1);
		}
		return res;
    };

private:
	SegTree* st;
};

int main(){
	Solution sl;
	vector<int> A{1,2,7,8,5};
	vector<int> res = sl.countOfSmallerNumberII(A);
	for(auto ele : res)
		cout<<ele<<endl;
}
