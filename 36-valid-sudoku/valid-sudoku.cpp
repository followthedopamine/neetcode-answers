/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku/description/
 *
 * algorithms
 * Medium (57.76%)
 * Likes:    8137
 * Dislikes: 881
 * Total Accepted:    1M
 * Total Submissions: 1.8M
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be
 * validated according to the following rules:
 *
 *
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9
 * without repetition.
 *
 *
 * Note:
 *
 *
 * A Sudoku board (partially filled) could be valid but is not necessarily
 * solvable.
 * Only the filled cells need to be validated according to the mentioned
 * rules.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: board =
 * [["5","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: board =
 * [["8","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 * Output: false
 * Explanation: Same as Example 1, except with the 5 in the top left corner
 * being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it
 * is invalid.
 *
 *
 *
 * Constraints:
 *
 *
 * board.length == 9
 * board[i].length == 9
 * board[i][j] is a digit 1-9 or '.'.
 *
 *
 * 507/507 cases passed (31 ms)
 * Your runtime beats 30.9 % of cpp submissions
 * Your memory usage beats 10.82 % of cpp submissions (21.1 MB)
 *
 * Time complexity: O(n)
 * Space complexity: TODO
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 private:
  bool addToMap(unordered_map<int, unordered_set<char>>& map, int key, char value) {
    if (map.find(key) == map.end()) {
      map.insert({key, unordered_set<char>{value}});
    } else {
      if (map[key].find(value) != map[key].end()) {
        return false;
      }
      map[key].insert(value);
    }
    return true;
  }

 public:
  unordered_map<int, unordered_set<char>> rows;
  unordered_map<int, unordered_set<char>> cols;
  unordered_map<int, unordered_set<char>> squares;

  bool isValidSudoku(vector<vector<char>>& board) {
    for (int r = 0; r < board.size(); r++) {
      for (int c = 0; c < board[r].size(); c++) {
        // If square is blank then don't process
        if (board[r][c] == '.') continue;

        if (!addToMap(rows, r, board[r][c])) {
          return false;
        }

        if (!addToMap(cols, c, board[r][c])) {
          return false;
        }

        int square = (r / 3) * 3 + (c / 3);
        if (!addToMap(squares, square, board[r][c])) {
          return false;
        }
      }
    }
    return true;
  }
};
// @lc code=end

// Ok so I think we just need a fat hash map here

// What if we store values for each way that a square can be invalid
// So for space 0,0 we have:
// 0c = column 0 = [5]
// 0r = row 0 = [5]
// 0s = square 0 = [5]

// Then 0,1 we have:
// 1c = [3]
// 0r = [3, 5]
// 0s = [3, 5]

// Time complexity will be O(n) because we should only need one pass. Although since there's only one valid array format will it be O(1) instead? Not sure.

// Run time seems really slow, might be a mistake in my code.