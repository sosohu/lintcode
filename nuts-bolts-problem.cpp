#include <iostream>
#include <vector>
#include <string>

using namespace std;

 class Comparator {
     public:
	int cmp(string a, string b){
		int i = 0, j = 0;
		while(i < a.size() && j < b.size()){
			if(a[i] < b[j] - ('A' - 'a'))	return -1;
			if(a[i] > b[j] - ('A' - 'a'))	return 0;
			i++;
			j++;
		}
		return i == j? 0 : (i == a.size()? -1 : 1);
	}
};

class Solution {
public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
        // write your code here
        int n = nuts.size(), m = bolts.size();
        vector<vector<string>> res(2, vector<string>()); 
        res = mergesort(nuts, bolts, compare);
        nuts = res[0];
        bolts = res[1];
    }
    
    vector<vector<string>> mergesort(vector<string> nuts, vector<string> bolts, Comparator compare){
        vector<string> bnuts, snuts, bbolts, sbolts;
        vector<vector<string>> res(2, vector<string>()), small(2, vector<string>()), big(2, vector<string>());
        if(!nuts.size() || !bolts.size()) return res;
        string cur = nuts[nuts.size() - 1], there;
        for(int i = 0; i < bolts.size(); i++){
            if(compare.cmp(cur, bolts[i]) > 0){
                sbolts.push_back(bolts[i]);
            }else if(compare.cmp(cur, bolts[i]) < 0){
                bbolts.push_back(bolts[i]);
            }else{
                res[0].push_back(cur);
                res[1].push_back(bolts[i]);
				there = bolts[i];
            }
        }
        nuts.pop_back();
        for(int i = 0; i < nuts.size(); i++){
            if(compare.cmp(nuts[i], there) < 0){
                snuts.push_back(nuts[i]);
            }else if(compare.cmp(nuts[i], there) > 0){
                bnuts.push_back(nuts[i]);
            }
        }
        small = mergesort(snuts, sbolts, compare);
        big = mergesort(bnuts, bbolts, compare);
        res[0].insert(res[0].end(), small[0].begin(), small[0].end());
        res[1].insert(res[1].end(), small[1].begin(), small[1].end());
        res[0].insert(res[0].end(), big[0].begin(), big[0].end());
        res[1].insert(res[1].end(), big[1].begin(), big[1].end());
        return res;
    }
};

int main(){
	Solution sl;
	vector<string> nuts = {"ab","bc","dd","gg"};
	vector<string> bolts = {"AB","GG","DD","BC"};
	Comparator cmp;
	sl.sortNutsAndBolts(nuts, bolts, cmp);
	for(auto ele : nuts)
		cout<<ele<<",";
	cout<<endl;
	for(auto ele : bolts)
		cout<<ele<<",";
	cout<<endl;
}
