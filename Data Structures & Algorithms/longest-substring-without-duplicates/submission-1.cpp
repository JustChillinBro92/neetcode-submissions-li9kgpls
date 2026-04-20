class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> substr;

        int l = 0, r = 0, maxLen = 0;
        while(r < s.size()) {
            while(substr.find(s[r]) != substr.end()) {
                substr.erase(s[l]);
                l++;
            }
            substr.insert(s[r]);
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};
