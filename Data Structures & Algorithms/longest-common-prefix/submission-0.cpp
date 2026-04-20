class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        string res="";
        string first = strs[0], last = strs[strs.size()-1];

        for(int i = 0; i < min(first.size(), last.size()); i++) {
            if(first[i] != last[i]) break;
            res += first[i];
        }
        return res;
    }
};