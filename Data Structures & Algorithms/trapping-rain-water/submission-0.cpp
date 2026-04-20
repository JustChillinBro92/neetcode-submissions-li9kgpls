class Solution {
public:
    int trap(vector<int>& heights) {
        int l = 0, r = heights.size()-1, maxArea = 0;
        int leftMax = heights[l], rightMax = heights[r];

        while(l < r) {
            if(leftMax < rightMax) {
                l++;
                leftMax = max(leftMax, heights[l]);
                maxArea += leftMax - heights[l];
            } else {
                r--;
                rightMax = max(rightMax, heights[r]);
                maxArea += rightMax - heights[r];
            }
        }
        return maxArea;
    }
};
