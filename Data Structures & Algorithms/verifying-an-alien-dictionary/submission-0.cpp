class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> alph(26);
        for(int i = 0; i < order.size(); i++) 
            alph[order[i] - 'a'] = i;

        for(int i = 0; i < words.size()-1; i++) {
            string w1 = words[i]; 
            string w2 = words[i+1];

            int j = 0;
            while(j < w1.size()) {
                if(j == w2.size()) return false;
                if(w1[j] != w2[j]) {
                    if(alph[w1[j] - 'a'] > alph[w2[j] - 'a'])
                        return false;
                    break;
                }
                j++;
            }
        }
        return true;
    }
};