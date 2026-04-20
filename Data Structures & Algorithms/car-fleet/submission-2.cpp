class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<double, double>> pos_spd;
        stack<double> time;

        for(int i = 0; i < position.size(); i++)
            pos_spd.push_back({position[i], speed[i]});

        // sort in descending order
        sort(pos_spd.begin(), pos_spd.end());
        reverse(pos_spd.begin(), pos_spd.end());

        for(int i = 0; i < pos_spd.size(); i++) {
            double car_time = (double)(target - pos_spd[i].first) / pos_spd[i].second;

            // if current car time is <= ahead car time, it catches up and joins(MERGE) ahead car's fleet 
            if(!time.empty() && car_time <= time.top()) continue;
            time.push(car_time);
        }
        return time.size();
    }
};
