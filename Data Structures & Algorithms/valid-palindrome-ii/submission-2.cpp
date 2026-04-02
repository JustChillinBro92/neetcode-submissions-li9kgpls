class Solution {
bool isPalindrome(string s, int l, int r) {
    while(l < r) {
        if(s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}

public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while(l < r) {
            if(s[l] != s[r]) {
                // skip left char AND right char to check
                if(!isPalindrome(s, l+1, r) && 
                   !isPalindrome(s, l, r-1))
                return false;
            }
            l++; r--;
        }
        return true;
    }
};