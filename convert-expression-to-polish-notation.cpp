#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
	bool isNumber(string s){
		return s[0] <= '9' && s[0] >= '0';
	}

	bool notParenthesis(char op){
		return op != '(' && op != ')';
	}

	//可以再扩展多个等级的优先级
	int getLevel(char op){
		if(op == '*' || op == '/')	return 2;
		else	return 1;
	}

public:
    vector<string> convertToPN(vector<string> &expression) {
		stack<char> s;
		char op;
		vector<string> res;
		for(int i = expression.size() - 1; i >= 0; i--){
			if(isNumber(expression[i])){
				res.push_back(expression[i]);
			}else{
				op = expression[i][0];
				if(op == ')'){
					s.push(op);
				}else if(op == '('){
					while(s.top() != ')'){
						res.push_back(string(1, s.top()));
						s.pop();
					}
					s.pop();
				}else{
					if(s.empty() || s.top() == ')'){
						s.push(op);
					}else{
						while(!s.empty() && notParenthesis(s.top())
								 && getLevel(op) < getLevel(s.top())){
							res.push_back(string(1, s.top()));
							s.pop();
						}
						s.push(op);
					}
				}
			}
		}
		while(!s.empty()){
			res.push_back(string(1, s.top()));
			s.pop();
		}
		reverse(res.begin(), res.end());
		return res;
    }
};

int main(){
	Solution sl;
	vector<string> expression{"(","(","1","+","(","2",")",")","*","3","+","(","4","/","2",")","-","5",")"};
	vector<string> res = sl.convertToPN(expression);
	for(auto ele : res)
		cout<<ele<<endl;
}
