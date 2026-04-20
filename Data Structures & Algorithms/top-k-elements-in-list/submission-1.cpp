class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        unordered_map<int, vector<int>> bucket(nums.size()+1);
        vector<int> res;

        for(int num: nums) freq[num]++;

        for(auto &[num, count]: freq)
            bucket[count].push_back(num);

        for(int i = nums.size(); i > 0 && res.size() < k; i--) {
            for(int num: bucket[i]) res.push_back(num);
        }
        return res;
    }
};
