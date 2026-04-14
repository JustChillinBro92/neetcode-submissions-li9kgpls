class Solution {
private:
    unordered_set<int> failed;
    bool possible(string &s, unordered_set<string> &wordSet, int i) {
        if(i == s.size()) return true;
        if(failed.find(i) != failed.end()) return false;

        for(int j = i; j < s.size(); j++) {
            string word = s.substr(i, j - i + 1);
            if(wordSet.find(word) != wordSet.end()) {
                if(possible(s, wordSet, j + 1))
                    return true;
            }
        }

        failed.insert(i);
        return false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;
        for(auto &w : wordDict) wordSet.insert(w);
        return possible(s, wordSet, 0);
    }
};
