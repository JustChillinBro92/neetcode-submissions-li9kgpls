class Solution {
public:
    int findMax(vector<int>& piles) {
        int max = piles[0];
        for(int i = 0; i < piles.size(); i++) {
            if(piles[i] > max) max = piles[i];
        }
        return max;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int lb = 1, ub = findMax(piles), k;

        while(lb <= ub) {
            k = (lb + ub) / 2;
            
            int hours = 0;
            for(int i = 0; i < piles.size(); i++) {
                hours += piles[i] / k;
                int rem = piles[i] % k;
                if(rem != 0) hours += 1;
            }
            if(hours <= h) ub = k - 1;
            else lb = k + 1;
        }
        return lb;
    }
};
