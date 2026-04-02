class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size()-1;

        while(i < j) {
            int num = numbers[j] + numbers[i];
            if(num > target) j--;
            else if(num < target) i++;
            else return {i+1, j+1};
        }
        return {};
    }
};
