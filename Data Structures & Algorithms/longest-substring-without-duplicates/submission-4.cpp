class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp; 
        int maxLen = 0;
        int l = 0, r = 0;
        
        while(r < s.size()) {
            if(mp.count(s[r]))
                l = max(mp[s[r]] + 1, l);

            mp[s[r]] = r;
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};
