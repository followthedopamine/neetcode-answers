/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (43.83%)
 * Likes:    6224
 * Dislikes: 6749
 * Total Accepted:    1.8M
 * Total Submissions: 4.1M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * A phrase is a palindrome if, after converting all uppercase letters into
 * lowercase letters and removing all non-alphanumeric characters, it reads the
 * same forward and backward. Alphanumeric characters include letters and
 * numbers.
 *
 * Given a string s, return true if it is a palindrome, or false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "A man, a plan, a canal: Panama"
 * Output: true
 * Explanation: "amanaplanacanalpanama" is a palindrome.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "race a car"
 * Output: false
 * Explanation: "raceacar" is not a palindrome.
 *
 *
 * Example 3:
 *
 *
 * Input: s = " "
 * Output: true
 * Explanation: s is an empty string "" after removing non-alphanumeric
 * characters.
 * Since an empty string reads the same forward and backward, it is a
 * palindrome.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 2 * 10^5
 * s consists only of printable ASCII characters.
 *
 *
 * 485/485 cases passed (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 84.89 % of cpp submissions (7.4 MB)
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
 public:
  bool isPalindrome(string s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
      if (!isalnum(s[left])) {
        left++;
        continue;
      }
      if (!isalnum(s[right])) {
        right--;
        continue;
      }
      if (tolower(s[left]) != tolower(s[right])) {
        return false;
      }
      left++;
      right--;
    }

    return true;
  }
};
// @lc code=end

// Very simple two pointers problem, just create a pointer at each end of the string and if they meet in the middle after matching each other all the way then the string is a palindrome