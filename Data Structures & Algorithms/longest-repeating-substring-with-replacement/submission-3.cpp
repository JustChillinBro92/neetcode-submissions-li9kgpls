// THIS IS SO FKING STUPID BRUH....MAKES NO SENSE
/* “ We don't need the window to always be valid.
We just need to never miss the best valid size ” */
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;

        int l = 0, r = 0, maxFreq = 0, longest = 0;
        while(r < s.size()) {
            freq[s[r]]++;
            maxFreq = max(maxFreq, freq[s[r]]);
            
            while((r-l+1) - maxFreq > k) {
                freq[s[l]]--;
                l++;
            }

            longest = max(longest, r-l+1);
            r++;
        }
        return longest;
    }
};
