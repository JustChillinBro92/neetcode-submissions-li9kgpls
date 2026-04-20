class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> person_trust(n + 1, 0);

        for(int i = 0; i < trust.size(); i++) {
            int p = trust[i][0];
            int t = trust[i][1];
            person_trust[p] = t;
        }

        int count = 0;
        for(int i = 1; i <= n; i++) {
            int trust = person_trust[i];
            if(!trust) continue;

            if(!person_trust[trust])
                count++;

            if(count == n-1) 
                return trust;
        }
        return -1;
    }
};