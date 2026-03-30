class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto &num : nums) s.insert(num);

        int longest = 0;
        for(auto &num : s) {
            if(s.find(num - 1) == s.end()) {
                int seq_len = 1;
                while(s.find(num + seq_len) != s.end())
                    seq_len++;
                longest = max(longest, seq_len);
            }
        }
        return longest;
    }
};
