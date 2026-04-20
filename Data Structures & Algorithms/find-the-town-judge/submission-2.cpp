class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> person_trust(n + 1, 0);

        for(int i = 0; i < trust.size(); i++) {
            int p = trust[i][0];
            int t = trust[i][1];
            person_trust[p]--;
            person_trust[t]++;
        }

        for(int i = 1; i <= n; i++) {
            if(person_trust[i] == n - 1) 
                return i;
        }
        return -1;
    }
};