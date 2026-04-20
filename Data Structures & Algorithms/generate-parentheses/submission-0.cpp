class Solution {
private:
    vector<string> res;
    string curr = "";
    int _n;

    void dfs(int openCnt, int closeCnt) {
        if(openCnt == _n && closeCnt == _n) {
            res.push_back(curr);
            return;
        }

        // '(' goes first 
        if(openCnt < _n) {
            curr += "(";
            dfs(openCnt + 1, closeCnt);
            curr.pop_back();
        }
        
        // ')' goes after
        if(closeCnt < openCnt) {
            curr += ")";
            dfs(openCnt, closeCnt + 1);
            curr.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        _n = n;
        dfs(0, 0);
        return res;
    }
};
