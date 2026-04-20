class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> agram;
        vector<vector<string>> res;
        
        for(string str: strs) {
            string key = str; 
            sort(key.begin(), key.end());
            agram[key].push_back(str);  
        }

        for(auto &p: agram) res.push_back(p.second);
        return res;
    }
};
