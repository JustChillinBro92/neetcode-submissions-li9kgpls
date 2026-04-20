class Solution {
private:
    vector<string> res;
    vector<string> keypad = {
        "+", "", "abc", "def", "ghi", 
        "jkl", "mno", "qprs", "tuv", "wxyz"
    };

    void dfs(string &digits, string currString, int start) {
        if(currString.size() == digits.size()) {
            res.push_back(currString);
            return;
        }

        string select = keypad[digits[start] - '0'];
        for(auto &c : select) {
            dfs(digits, currString + c, start + 1);
        }
    } 

public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        dfs(digits, "", 0);
        return res;
    }
};
