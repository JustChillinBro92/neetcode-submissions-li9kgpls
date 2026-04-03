class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int tw = accumulate(people.begin(), people.end(), 0);
        sort(people.rbegin(), people.rend());

        int minBoat = 0, n = people.size();
        int l = 0, r = n - 1;
        while(l < r) {
            if((people[l] + people[r]) <= limit) {
                tw -= (people[l] + people[r]);
                l++; r--;
            } else {
                tw -= people[l];
                l++;
            }
            minBoat++;
        }
        if(tw != 0) minBoat++;

        return minBoat;
    }
};