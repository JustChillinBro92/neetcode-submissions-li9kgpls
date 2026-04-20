class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lb = 0, ub = nums.size()-1;

        while(lb <= ub) {
            int mid = lb + (ub - lb) / 2;

            if(nums[mid] == target) return mid;

            // mid element found in left sorted portion
            else if(nums[lb] <= nums[mid]) {
                // target is in right sorted portion
                if(target > nums[mid] || target < nums[lb])
                    lb = mid + 1;
                // target is in left sorted portion
                else ub = mid - 1;
            } else {
                // target is in left sorted portion
                if(target < nums[mid] || target > nums[ub])
                    ub = mid - 1;
                // target is in right sorted portion
                else lb = mid + 1;
            }
        }
        return -1;
    }
};
