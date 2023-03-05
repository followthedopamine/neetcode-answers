/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (66.56%)
 * Likes:    14443
 * Dislikes: 421
 * Total Accepted:    1.9M
 * Total Submissions: 2.8M
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings strs, group the anagrams together. You can return
 * the answer in any order.
 *
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 *
 *
 * Example 1:
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * Example 2:
 * Input: strs = [""]
 * Output: [[""]]
 * Example 3:
 * Input: strs = ["a"]
 * Output: [["a"]]
 *
 *
 * Constraints:
 *
 *
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] consists of lowercase English letters.
 *
 *
 * Time: O(n * l) -> n = length of strs, l = max length of a string in strs
 *   Space: O(n * l)
 *
 * 118/118 cases passed (63 ms)
 * Your runtime beats 24.45 % of cpp submissions
 * Your memory usage beats 8.7 % of cpp submissions (28.3 MB)
 */

#include <iostream>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
 private:
  string getKey(string word) {
    vector<int> count(26);
    for (int i = 0; i < word.size(); i++) {
      count[word[i] - 'a']++;
    }

    string result = "";

    for (int d : count) {
      result += d;
    }

    return result;
  }

 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> result;
    unordered_map<string, vector<string>> map;

    for (int i = 0; i < strs.size(); i++) {
      string key = getKey(strs[i]);
      if (map.find(key) != map.end()) {
        map[key].push_back(strs[i]);
      } else {
        map.insert({key, vector<string>{strs[i]}});
      }
    }

    for (pair<string, vector<string>> mapPair : map) {
      result.push_back(mapPair.second);
    }
    return result;
  }
};

// @lc code=end

// Seems pretty simple to do this in O(n)^2
// Just hash map the letters of the first word, then check all other words
// We can optimize by removing the matching words from the array
// For the words that don't match we create a new hash map

// If we made an array of hash maps we could probably do it in 2 passes
// One to make the array of hash maps and then a second pass to match them so that would technically be O(n) but I wonder if we could optimize to one pass somehow.

// If we combine these two techniques we might be able to do it in one pass

// First we create an array for the hashmaps and an array for the result
// Then we break apart the word and add the first hash map to the array
// For the next word we create a hash map and check if it's equal to all previous hash maps
// If it's not equal to any of them then we add it
// I think that's still O(n) and we do it in one pass.

// Note: might have to use an ordered map since we're comparing maps but I'm not sure yet

// Test case failed initially:
// ["ddddddddddg","dgggggggggg"]
// I really don't know why this case failed, it seems like two maps with different values on each key really shouldn't be equal.

// A simpler solution is as follows:
// Count the letters in the word and use that as a key in a hash map