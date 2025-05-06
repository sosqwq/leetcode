#include <iostream>
#include <vector>
#include <cstring> 
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;
class Solution {
    private:

    static bool cmp(const vector<int> & a, const vector<int> & b){
        return a[1] < b[1];
    }
    public:
        int eraseOverlapIntervals(vector<vector<int>>& intervals) {
            
            if(intervals.size() == 0) return 0;
            sort(intervals.begin(), intervals.end(),cmp);
            int result = 1;
            int end = intervals[0][1];
            for(int i= 1;i< intervals.size(); i++){
                if(end <= intervals[i][0]){
                    result += 1;
                    end = intervals[i][1];
                }
            
            }
            return intervals.size() - result;
        }
    };