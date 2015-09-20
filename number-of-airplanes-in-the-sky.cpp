#include <iostream>
#include <algorithm>
#include <vector>

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
        return a.end < b.end;
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
        int dp = 1;
        for(int i = 1; i < airplanes.size(); i++){
			Interval target(airplanes[i].start, airplanes[i].start);
            auto iter = lower_bound(airplanes.begin(), airplanes.begin() + i, 
									target,  comp());
            int gap = airplanes.begin() + i - iter + 1;
            dp = max(dp, gap);
        }
        return dp;
    }
};

int main(){
	return 0;
}
