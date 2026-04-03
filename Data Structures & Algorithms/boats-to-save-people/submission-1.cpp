class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.rbegin(), people.rend());

        int minBoat = 0, n = people.size();
        int l = 0, r = n - 1;
        while(l <= r) {
            if(people[l] + people[r] <= limit) r--;
            l++; 
            minBoat++;
        }
        return minBoat;
    }
};