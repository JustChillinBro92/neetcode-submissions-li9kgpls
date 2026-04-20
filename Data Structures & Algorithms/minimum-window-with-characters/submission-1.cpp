class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> window, check;
        int have = 0, need, l = 0, minLength = INT_MAX, startIndex;

        for(int i = 0; i < t.size(); i++) check[t[i]]++;
        need = check.size();

        for(int r = 0; r < s.size(); r++) {
            window[s[r]]++;
            if(window[s[r]] == check[s[r]]) have++;

            while(have == need) {
                if(r-l+1 < minLength) {
                    minLength = r-l+1;
                    startIndex = l;
                }

                window[s[l]]--;
                if(window[s[l]] < check[s[l]]) have--;
                l++;
            }
        }
        return minLength == INT_MAX ? "" : s.substr(startIndex, minLength);
    }
};
