#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class Interval {
public:
	int start, end;
	Interval(int start, int end) {
		this->start = start;
		this->end = end;
	}
};
 
class comp{
public:
    bool operator()(const Interval &a, const Interval &b){
        return a.start == b.start? a.end < b.end : a.start < b.start;
    }
};
 
class Solution {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        sort(airplanes.begin(), airplanes.end(), comp());
		priority_queue<int, vector<int>, greater<int>> min_heap;
		int res = 0;
		for(auto ele : airplanes){
			min_heap.push(ele.end);
			while(min_heap.top() < ele.start){
				min_heap.pop();
			}
			if(res < min_heap.size())	res = min_heap.size();
		}
		return res;
    }
};

int main(){
	return 0;
}
