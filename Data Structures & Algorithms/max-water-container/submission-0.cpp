class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1, maxArea, res = 0;
        while(l < r) {
            maxArea = min(height[l], height[r]) * (r-l);
            res = max(res, maxArea);

            if(height[l] < height[r]) l++;
            else r--;
        }
        return res;
    }
};