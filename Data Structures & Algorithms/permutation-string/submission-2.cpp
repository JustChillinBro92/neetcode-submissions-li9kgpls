class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if(n1 > n2) return false;
        
        vector<int> freq1(26, 0), freq2(26, 0);

        for(auto &c : s1) freq1[c - 'a']++;
        for(int i = 0; i < n2; i++) {
            freq2[s2[i] - 'a']++;
            if(i >= n1) freq2[s2[i - n1] - 'a']--;
            if(freq1 == freq2) return true;
        }
        return false;
    }
};
