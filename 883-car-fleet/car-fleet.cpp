class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>car;
        for(int i=0;i<speed.size();i++){
            car.push_back({position[i],speed[i]});
        }
        sort(car.begin(),car.end(),greater<>());
        // stack<double>st;
        // double d=(1.0*(target-car[0].first))/(1.0*car[0].second);
        // st.push(d);
        int count=0;
        double nettime=0.0;
        for(int i=0;i<speed.size();i++){
            double time=(1.0*(target-car[i].first))/(1.0*car[i].second);
            // if(st.top()<time){
            //     st.push(time);
            // }
            if(time>nettime){
                count++;
                nettime=time;
            }
        }
        // return st.size();
        return count;
    }
};