class Solution {
private:
    void mergeSort(vector<int> &nums, int lb, int ub) {
        if(lb >= ub) return;

        int mid = lb + (ub - lb) / 2;
        mergeSort(nums, lb, mid);
        mergeSort(nums, mid + 1, ub);
        merge(nums, lb, mid, ub);
    }

    void merge(vector<int> &nums, int lb, int mid, int ub) {
        vector<int> temp;

        int i = lb, j = mid + 1;
        while(i <= mid && j <= ub) {
            if(nums[i] <= nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }

        while(i <= mid) temp.push_back(nums[i++]);
        while(j <= ub) temp.push_back(nums[j++]);

        for(int i = lb; i <= ub; i++)
            nums[i] = temp[i - lb];
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};