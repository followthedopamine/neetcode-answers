/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * 57/57 cases passed (9 ms)
 * Your runtime beats 89.37 % of cpp submissions
 * Your memory usage beats 44.74 % of cpp submissions (10.8 MB)
 */

#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;

    for (int i = 0; i < nums.size(); i++) {
      int complement = target - nums[i];
      if (m.find(complement) != m.end()) {
        return vector<int>{m[complement], i};
      } else {
        m.insert({nums[i], i});
      }
    }
    return vector<int>{0, 0};
  }
};
// @lc code=end
