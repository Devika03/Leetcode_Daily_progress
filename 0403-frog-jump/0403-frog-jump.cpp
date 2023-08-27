class Solution {
public:
    bool f(int idx,int prevStep,vector<int>&stones,map<pair<int,int>,int> &dp){
        if(idx == stones.size()-1) return true;
        // choice 1
        if(dp.count({idx,prevStep})) return dp[{idx,prevStep}];
        bool choice1 = false;
        auto takeK = lower_bound(stones.begin(),stones.end(),stones[idx] + prevStep);
        int takeKIdx = takeK - stones.begin();
        if(takeKIdx<stones.size() && stones[takeKIdx] - stones[idx] == prevStep){
            choice1 = f(takeKIdx,prevStep,stones,dp);
        }
        //choice 2
        bool choice2 = false;
        auto takeKP1 = lower_bound(stones.begin(),stones.end(),stones[idx] + prevStep + 1);
        int takeKP1Idx = takeKP1 - stones.begin();
        if(takeKP1Idx<stones.size() && stones[takeKP1Idx] - stones[idx] == prevStep + 1){
            choice2 = f(takeKP1Idx,prevStep+1,stones,dp);
        }
        //choice 3
        bool choice3 = false;
        auto takeKM1 = lower_bound(stones.begin(),stones.end(),stones[idx] + prevStep - 1);
        int takeKM1Idx = takeKM1 - stones.begin();
        if(takeKM1Idx<stones.size() && prevStep!=1 && stones[takeKM1Idx] - stones[idx] == prevStep - 1){
            choice3 = f(takeKM1Idx,prevStep-1,stones,dp);
        }
        return dp[{idx,prevStep}] = choice1 || choice2 || choice3;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1) return false;
        int n = stones.size();
        map<pair<int,int>,int> dp;
        return f(1,1,stones,dp);
    }
};