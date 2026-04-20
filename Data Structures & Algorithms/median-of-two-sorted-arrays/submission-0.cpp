class Solution {
public:
    vector<int> mergeArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        int i = 0, j = 0;
        int s1 = nums1.size(), s2 = nums2.size(); 

        while(i < s1 && j < s2) {
            if(nums1[i] <= nums2[j]) {
                nums3.push_back(nums1[i]);
                i++;
            } else {
                nums3.push_back(nums2[j]);
                j++;
            }
        }

        if(i == s1) {
            while(j != s2) {
                nums3.push_back(nums2[j]);
                j++;
            }
        } else if(j == s2) {
            while(i != s1) {
                nums3.push_back(nums1[i]);
                i++;
            } 
        }
        return nums3;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3 = mergeArray(nums1, nums2);
        int n = nums3.size();

        double median;
        if(n % 2 == 0) {
            median = (nums3[(n-1)/2] + nums3[(n-1)/2 + 1]) / 2.0;
        } else {
            median = (nums3[n/2]);
        }
        return median;
    } 
};
