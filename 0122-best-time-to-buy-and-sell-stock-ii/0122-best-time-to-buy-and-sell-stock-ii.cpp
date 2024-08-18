class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int pft = 0;
        for(int i =1 ; i<prices.size() ; i++)
        {
            if(prices[i]>prices[i-1])
                pft+=prices[i]-prices[i-1];
        }
        return pft;
    }
};