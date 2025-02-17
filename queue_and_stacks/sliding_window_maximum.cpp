#include <iostream>
#include <vector>
#include <cstring> 
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <deque>
using namespace std;

class Solution {
    private:
    class MyQueue { //单调队列（从大到小）
        public:
            deque <int> que; 
            void pop(int val){
                if(!que.empty()&& val==que.front()){
                    que.pop_front();
                }

            }
            void push(int val){
                while(!que.empty() && val > que.back()){
                    que.pop_back();
                }
                que.push_back(val);

            }
            int front(){
                return que.front();
            }
        };
            
    public:
        
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            MyQueue que; 
            vector<int> result;
            // 先将k元素放进队列
            for(int i= 0; i<k;i++){
                que.push(nums[i]);
                result.push_back(que.front());
            }
            //从K开始
            for(int i = k; i< nums.size();i++){
                que.pop(nums[i-k]);
                que.push(nums[i]);
                result.push_back(que.front());
            }
            return result;

        }
    };