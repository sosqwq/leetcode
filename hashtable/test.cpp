#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
    std::vector<int> nums1 = {1, 2, 2, 3, 4, 4, 5};

    // 创建空的 result_set
    std::unordered_set<int> result_set;

    // 使用 nums1 的范围初始化 nums_set
    std::unordered_set<int> nums_set(nums1.begin(), nums1.end());

    // 输出 nums_set 的内容（无序且唯一）
    for (int num : nums_set) {
        std::cout << num << " ";
    }

    return 0;
}
