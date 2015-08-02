#include <iostream>
#include <stack>
#include <vector>

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

	int getNum(string s){
		int num = 0;
		for(int i = 0; i < s.size(); i++){
			num = num*10 + s[i] - '0';
		}
		return num;
	}

	int makeOp(int a, int b, char op){
		switch(op){
			case '+':	return a + b;
			case '-':	return a - b;
			case '*':	return a * b;
			case '/':	return a / b;
		}
	}

public:
    vector<string> convertToRPN(vector<string> &expression) {
		stack<char> s;
		char op;
		vector<string> res;
		for(int i = 0; i < expression.size(); i++){
			if(isNumber(expression[i])){
				res.push_back(expression[i]);
			}else{
				op = expression[i][0];
				if(op == '('){
					s.push(op);
				}else if(op == ')'){
					while(s.top() != '('){
						res.push_back(string(1, s.top()));
						s.pop();
					}
					s.pop();
				}else{
					if(s.empty() || s.top() == '('){
						s.push(op);
					}else{
						while(!s.empty() && notParenthesis(s.top())
								 && getLevel(op) <= getLevel(s.top())){
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
		return res;
    }

	int evaluateExpression(vector<string> &expression) {
		vector<string> res = convertToRPN(expression);
		stack<int> s;
		for(int i = 0; i < res.size(); i++){
			if(isNumber(res[i])){
				s.push(getNum(res[i]));
			}else{
				int b = s.top();
				s.pop();
				int a = s.top();
				s.pop();
				a = makeOp(a, b, res[i][0]);
				s.push(a);
			}
		}
		return s.empty()? 0 : s.top();
	}
};

int main(){
	Solution sl;
	vector<string> expression{"(","(","1","+","(","2",")",")","*","3","+","(","4","/","2",")","-","5",")"};
	cout<<sl.evaluateExpression(expression)<<endl;
}
