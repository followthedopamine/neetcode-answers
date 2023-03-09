/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (48.85%)
 * Likes:    15173
 * Dislikes: 629
 * Total Accepted:    1.1M
 * Total Submissions: 2.2M
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers nums, return the length of the longest
 * consecutive elements sequence.
 *
 * You must write an algorithm that runs in O(n) time.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [100,4,200,1,3,2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,3,7,2,5,8,4,6,0,1]
 * Output: 9
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 *
 *
 * 72/72 cases passed (125 ms)
 * Your runtime beats 79.77 % of cpp submissions
 * Your memory usage beats 77.15 % of cpp submissions (45.7 MB)
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

#include <unordered_set>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> set(nums.begin(), nums.end());
    int max_seq = 0;

    for (auto& num : set) {
      // Check for left neighbour
      if (set.find(num - 1) == set.end()) {
        // There is no left neighbour
        int seq_count = 1;
        while (1) {
          if (set.find(num + seq_count) == set.end()) {
            max_seq = max(max_seq, seq_count);
            break;
          } else {
            seq_count++;
          }
        }
      }
    }

    return max_seq;
  }
};
// @lc code=end

// Initial thoughts are that I can just add all the numbers to an ordered set and then loop through the set counting the longest consecutive elements but I'm not 100% sure that's O(n) time because I don't really know how ordered sets work. It seems like it should be O(n log n) because it's effectively sorting the array and I know that the fastest sorting algorithms take O(n log n).
