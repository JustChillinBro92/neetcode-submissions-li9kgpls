class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        unordered_set<int> num_set;
        int longest = 0;

        for(int num: nums) num_set.insert(num);
        for(int num: num_set) {
            // if (no.-1) not exist, no. is start of a seq
            if(!num_set.count(num-1)) {
                int seq_length = 1;
                // looking for (no. + 1, no. + 2,...)
                while(num_set.count(num + seq_length))
                    seq_length++;
                longest = max(longest, seq_length);
            }
        }
        return longest;
    }
};
