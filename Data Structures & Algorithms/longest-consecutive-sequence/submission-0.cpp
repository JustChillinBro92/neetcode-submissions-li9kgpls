class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        int longest = 0;

        for(int num : nums) set.insert(num);
        for(int num : set) {
            if(set.find(num-1) == set.end()) {
                int length = 1;
                while(set.find(num + length) != set.end()) 
                    length++;

                longest = max(longest, length);
            }    
        }
        return longest;
    }
};
