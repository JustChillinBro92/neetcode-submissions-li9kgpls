class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded = "";
        for(string word : strs)
            encoded += to_string(word.size()) + "#" + word;
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0, j, len;

        while(i < s.size()) {
           j = i;
           while(s[j] != '#') j++;
           len = stoi(s.substr(i, j+1));
           decoded.push_back(s.substr(j+1, len));
           i = j + 1 + len;
        }
        return decoded;
    }
};
