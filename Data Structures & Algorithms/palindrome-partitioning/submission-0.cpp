class Solution {
private:
    bool isPalindrome(string &s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }
    
    vector<vector<string>> res;
    void dfs(string &s, vector<string> &curr, int start) {
        if(start == s.size()) {
            res.push_back(curr);
            return;
        }

        for(int end = start; end < s.size(); end++) {
            if(isPalindrome(s, start, end)) {
                curr.push_back(s.substr(start, end - start + 1));
                // partition
                dfs(s, curr, end + 1);
                curr.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        dfs(s, curr, 0);
        return res;
    }
};
