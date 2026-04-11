class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, maxLen = 0;

        for(int i = 0; i < n; i++) {
            // odd len palindrome check i.e., "aba"
            int l = i, r = i;
            while(l >= 0 && r < n && s[l] == s[r]) {
                if(r - l + 1 > maxLen) {
                    start = l;
                    maxLen = r - l + 1;
                }
                // expand outwards from that index
                l--; r++;
            }

            // even len palindrome check i.e., "abba"
            l = i, r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]) {
                if(r - l + 1 > maxLen) {
                    start = l;
                    maxLen = r - l + 1;
                }
                // expand outwards from that index
                l--; r++;
            }
        }

        return s.substr(start, maxLen);
    }
};
