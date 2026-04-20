class Solution {
public:
    int findMin(vector<int> &nums) {
        int lb = 0, ub = nums.size()-1;

        // always search in unsorted portion
        while(lb < ub) {
            int mid = lb + (ub-lb) / 2;
            if(nums[mid] < nums[ub]) ub = mid;
            else lb = mid + 1;
        }
        return nums[lb];
    }
};
