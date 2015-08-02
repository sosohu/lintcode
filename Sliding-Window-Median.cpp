#include <iostream>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct DListNode{
    int val;
	int pos;
    DListNode *pre, *next;
    DListNode(int val = 0, int pos = -1) : val(val), pos(pos), pre(NULL), next(NULL){

    }
};

class Solution {
    public:
    /**
    * @param nums: A list of integers.
    * @return: The median of the element inside the window
    * at each moving
    */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
    // write your code here
        auto n = nums.size();
		if(n == 0 || k == 0)	return vector<int>();
        multimap<int, DListNode*> table;
        DListNode *pHead = new DListNode(), *pTail = new DListNode(), *pMid;
        pHead->next = pTail;
        pTail->pre = pHead;
        for(auto i = 0; i < k; i++){
            auto iter = table.upper_bound(nums[i]);
            auto pNext = iter == table.end()? pTail : iter->second;
            auto pCur = new DListNode(nums[i], i);
            pCur->next = pNext;
            pCur->pre = pNext->pre;
            pNext->pre = pCur;
            pCur->pre->next = pCur;
            table.insert(iter, make_pair(nums[i], pCur));
        }
        auto iter = table.begin();
        for(auto i = 1; i < ( k + 1 ) / 2; i++){
            iter++;
        }
        pMid = iter->second;
        vector<int> res;
        res.push_back(pMid->val);
        for(auto i = k; i < n; i++){
            int index = i - k;
            //insert
            iter = table.upper_bound(nums[i]);
            auto pNext = iter == table.end()? pTail : iter->second;
            auto pCur = new DListNode(nums[i], i);
            pCur->next = pNext;
            pCur->pre = pNext->pre;
            pNext->pre = pCur;
            pCur->pre->next = pCur;
            table.insert(iter, make_pair(nums[i], pCur));
            if(nums[index] < pMid->val || (nums[index] == pMid->val && index < pMid->pos)){
                if(nums[i] >= pMid->val){
                    pMid = pMid->next;
                }
            }else if(nums[index] > pMid->val || (nums[index] == pMid->val && index > pMid->pos)){
                if(nums[i] < pMid->val){
                    pMid = pMid->pre;
                }
            }else{
                pMid = pMid->next;
                if(pMid == pTail || nums[i] < pMid->val){
                    pMid = pMid->pre->pre;
                }
            }
            //delete
            iter = table.lower_bound(nums[index]);
            auto pDel = iter->second;
            pDel->pre->next = pDel->next;
            pDel->next->pre = pDel->pre;
            table.erase(iter);
            delete pDel;
            pDel = NULL;
            res.push_back(pMid->val);
        }
        return res;
    }
};

int main(){
	Solution sl;
	vector<int> nums{1,2,7,7,2,10,3,4,5};
	vector<int> res = sl.medianSlidingWindow(nums, 2);
	for(int i = 0; i < res.size(); i++)
		cout<<res[i]<<endl;
}
