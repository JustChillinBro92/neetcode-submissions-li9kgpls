class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0;
        for(int two = 0; two < nums.size(); two++) {
            int curr = nums[two];

            nums[two] = 2;
            if(curr < 2) nums[one++] = 1;
            if(curr < 1) nums[zero++] = 0; 
        }
    }
};