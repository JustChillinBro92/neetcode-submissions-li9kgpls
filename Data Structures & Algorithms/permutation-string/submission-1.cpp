class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        vector<int> freq1(26, 0), freq2(26, 0);
        int window = s1.size();

        for(char c: s1) freq1[c - 'a']++;

        for(int i = 0; i < s2.size(); i++) {
            freq2[s2[i] - 'a']++;

            if(i >= window)
                freq2[s2[i - window] - 'a']--;

            if(freq1 == freq2) return true;
        }
        return false;
    }
};
