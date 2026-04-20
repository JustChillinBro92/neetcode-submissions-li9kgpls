class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> set;
        int l = 0, maxLength = 0;

        for(int r = 0; r < s.size(); r++) {
            while(set.find(s[r]) != set.end()) {
                set.erase(s[l]);
                l++;
            }
            set.insert(s[r]);
            maxLength = max(maxLength, r - l + 1);
        }
        return maxLength;
    }
};
