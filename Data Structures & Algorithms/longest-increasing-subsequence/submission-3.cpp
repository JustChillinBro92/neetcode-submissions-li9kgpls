class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        int maxSeqLen = 1;
        for(int i = 0; i < n; i++) {
            // for each valid num till 'i' try to find the maxSeq
            // and store/update SeqLen in a dp at that index
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            maxSeqLen = max(maxSeqLen, dp[i]);
        }

        return maxSeqLen;
    }
};
