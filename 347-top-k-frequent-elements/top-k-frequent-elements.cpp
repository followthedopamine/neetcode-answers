/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (64.71%)
 * Likes:    12838
 * Dislikes: 473
 * Total Accepted:    1.3M
 * Total Submissions: 2.1M
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given an integer array nums and an integer k, return the k most frequent
 * elements. You may return the answer in any order.
 *
 *
 * Example 1:
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * Example 2:
 * Input: nums = [1], k = 1
 * Output: [1]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * k is in the range [1, the number of unique elements in the array].
 * It is guaranteed that the answer is unique.
 *
 *
 *
 * Follow up: Your algorithm's time complexity must be better than O(n log n),
 * where n is the array's size.
 *
 * First attempt:
 * Your runtime beats 13.02 % of cpp submissions
 * Your memory usage beats 97.91 % of cpp submissions (13.5 MB)
 *
 *
 */

#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    for (int num : nums) {
      if (map.find(num) == map.end()) {
        map.insert({num, 1});
      } else {
        map[num]++;
      }
    }

    vector<int> result;
    for (int i = 0; i < k; i++) {
      pair<int, int> highest = {0, 0};
      for (pair<int, int> m : map) {
        if (m.second > highest.second) {
          highest = m;
        }
      }
      map.erase(highest.first);
      result.push_back(highest.first);
    }

    return result;
  }
};
// @lc code=end

// So my first thought is to add everything to an unordered map and then print the k keys with the largest values

// I think this would be O(n + (u * k)) where n is number of elements in the vector and u is the number of unique numbers

// Ok so getting the hash map is pretty straightforward but now I've run into an issue when sorting them. The issue is that I don't know if it would be a lower time complexity to sort the whole map O(n log n) where n is number of elements in map. Or just run the loop k times to get the k largest valeus O(u * k). I think it depends on the size of k in relation to the size of n.

// So the follow up is that it must be better than O(n log n) which means there's definitely something I'm missing.