class Solution {
private:
    void reverseArray(vector<int> &arr, int l, int r) {
        while(l < r) {
            swap(arr[l], arr[r]);
            l++; r--;
        }
    }

public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if(k == 0) return;
        reverseArray(nums, 0, n-1);
        reverseArray(nums, 0, k-1);
        reverseArray(nums, k, n-1);
    }
};