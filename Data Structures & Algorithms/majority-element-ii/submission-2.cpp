class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num1 = -1, num2 = -1;
        int cnt1 = 0, cnt2 = 0;

        // finds out the most freq 2 numbers
        for(auto &num : nums) {
            if(num == num1) cnt1++;
            else if(num == num2) cnt2++;
            else if(cnt1 == 0) {
                num1 = num;
                cnt1 = 1;
            } else if(cnt2 == 0) {
                num2 = num;
                cnt2 = 1;
            } else {
                // reduce both count(if both > 0) upon encountering a diff number
                cnt1--;
                cnt2--;
            }
        }

        // calculate actual freq of the most freq 2 numbers
        cnt1 = 0, cnt2 = 0;
        for(auto &num : nums) {
            if(num == num1) cnt1++;
            else if(num == num2) cnt2++;
        }

        cout << cnt1 << " " << cnt2 << endl;

        vector<int> res;
        if(cnt1 > (n / 3)) res.push_back(num1);
        if(cnt2 > (n / 3)) res.push_back(num2);

        return res;
    }
};