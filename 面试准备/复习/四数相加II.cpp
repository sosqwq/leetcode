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
    public:
        int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {    
            unordered_map <int, int> map;
            int counts = 0;
            for(int i = 0; i< nums1.size();i++){
                for(int j= 0; j< nums2.size();j++){
                    //map 加入 新元素
                    //map ++ 计算元素出现的次数
                    map[nums1[i]+nums2[j]]++;
                }
            }

            for(int i = 0; i< nums3.size();i++){
                for(int j= 0; j< nums4.size();j++){
                    int target = 0 -(nums3[i]+nums4[j]);
                    auto targets = map.find(target);

                    if( targets != map.end() ){
                        counts += targets -> second;
                    }
                }
            }
            return counts;
        }
    };