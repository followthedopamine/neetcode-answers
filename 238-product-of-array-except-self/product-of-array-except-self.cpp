/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (64.82%)
 * Likes:    16658
 * Dislikes: 914
 * Total Accepted:    1.6M
 * Total Submissions: 2.4M
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given an integer array nums, return an array answer such that answer[i] is
 * equal to the product of all the elements of nums except nums[i].
 *
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
 * integer.
 *
 * You must write an algorithm that runs in O(n) time and without using the
 * division operation.
 *
 *
 * Example 1:
 * Input: nums = [1,2,3,4]
 * Output: [24,12,8,6]
 * Example 2:
 * Input: nums = [-1,1,0,-3,3]
 * Output: [0,0,9,0,0]
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 10^5
 * -30 <= nums[i] <= 30
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
 * integer.
 *
 *
 *
 * Follow up: Can you solve the problem in O(1) extra space complexity? (The
 * output array does not count as extra space for space complexity analysis.)
 *
 * Time complexity O(n)
 * Space complexity O(1)
 *
 * 22/22 cases passed (31 ms)
 * Your runtime beats 39.39 % of cpp submissions
 * Your memory usage beats 90.54 % of cpp submissions (24 MB)
 */
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 1);

    int prefix = 1;
    for (int i = 0; i < n; i++) {
      result[i] = prefix;
      prefix = prefix * nums[i];
    }

    int postfix = 1;
    for (int i = n - 1; i >= 0; i--) {
      result[i] = result[i] * postfix;
      postfix = postfix * nums[i];
    }

    return result;
  }
};
// @lc code=end

// So the straightforward solution is pretty simple we just multiply all numbers together and then divide by nums[i] in a second pass, this is O(n) time complexity and O(n) space complexity but we're not allowed to use division so there must be another trick to it.

// There's a simple solution which doesn't use division that just loops through every number except nums[i] but that has O(n)^2 time complexity.

// My next thought is we remove the element from the array and then multiply the whole array using some in built function that I don't know yet. It seems that would have to be O(n)^2 time complexity as well though.

// Maybe we could be cheeky and instead of using division we could multiply by a decimal but I don't think that's intended.

// What if there's a left product and a right product and we multiply them together as we move along the array.

// Input: nums = [1,2,3,4]
//  Output: [24,12,8,6]

// So for nums[0] our left product would be 1 because it's empty and our right product would be 24.

// We move our pointers over but we still need to divide our right product so this doesn't work.

// Okay so the solution is similar to where I was at with the two pointers but to make it less time complex we need to create two arrays of values of what the pointer values would be, this way we'll have the values stored and we won't need to divide. This is much less efficient and very impractical but it does solve the problem's restrictions.