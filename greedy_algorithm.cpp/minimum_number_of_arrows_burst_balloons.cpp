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
    static bool cmp(const vector<int> & a, const vector<int>  & b){
        return a[0] < b[0];
    }
    public:
        int findMinArrowShots(vector<vector<int>>& points) {
            if(points.size() == 0) return 0;
            sort(points.begin(), points.end(), cmp);

            int result = 1;
            for(int i = 1; i< points.size(); i++){
                if(points[i][0] > points[i-1][1]){
                    result += 1;
                }
                else{
                    points[i][1] = min(points[i][1], points[i-1][1]);
                }
            }
            return result;
            /*
              int end = intervals[0][1];
            for(int i= 1;i< intervals.size(); i++){
                if(end <= intervals[i][0]){
                    result += 1;
                    end = intervals[i][1];
                }
            */
        }
    };