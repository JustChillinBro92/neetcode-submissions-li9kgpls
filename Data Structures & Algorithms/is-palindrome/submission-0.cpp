class Solution {
public:
    bool isPalindrome(string s) {
        vector<int> arr;

        for(char letter : s) 
            if(isalnum(letter)) arr.push_back(tolower(letter));
        
        int left = 0, right = arr.size() - 1;
        while(left < right) {
            if(arr[left] != arr[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
