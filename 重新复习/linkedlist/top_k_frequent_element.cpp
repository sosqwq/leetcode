#include <iostream>
#include <vector>
#include <cstring> 
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;

class Solution {
public:
//  小顶堆的判定方法，使 堆顶是 从小到大排序的小顶堆
/*  如果 lhs.second 比 rhs.second 大，返回 true
    说明 lhs 的优先级更低
*/

    class mycomparison {
        public: 
        /*谁的 second 更大，谁就往下沉
            所以 second 更小的元素留在堆顶*/
            bool operator()(const pair<int, int> & lhs, const pair < int, int> &rhs){
                return lhs.second > rhs.second;
            }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int i= 0;i <nums.size();i++){
            map[nums[i]]++;
        }
        // 对频率排序
        // 定义一个小顶堆，大小为k
        // 优先队列 是按“优先级”出队。
        // priority_queue<元素类型, 底层容器, 比较器> 名字;
        priority_queue<pair<int,int> , vector<pair<int,int>>, mycomparison> pri_que;

        for(unordered_map<int,int> :: iterator it = map.begin(); it != map.end(); it++){
            pri_que.push(*it);
            if(pri_que.size() > k){
                pri_que.pop();
            }
        }

        vector<int> result(k);
        for(int i = k-1; i>= 0; i--){
            result[i] = pri_que.top().first;
            pri_que.pop();
        }

        return result;
    }
};