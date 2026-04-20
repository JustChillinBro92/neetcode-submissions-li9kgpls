class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lb = 0;
        int ub = nums.size()-1;

        while(lb <= ub) {
            int mid = (lb + ub) / 2;
            if(nums[mid] == target) return mid;
            else if(target < nums[mid]) ub = mid - 1;
            else lb = mid + 1;
        }
        return -1;
    }
};
