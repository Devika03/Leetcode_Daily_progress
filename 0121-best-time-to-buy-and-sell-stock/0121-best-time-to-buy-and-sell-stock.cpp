class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        int mini = prices[0];
        int profit = 0 ; 
        int current_profit = 0 ; 
        int max_profit = 0 ; 
        
        for(int i = 1 ; i < n ; i++)
        {
            current_profit = prices[i]-mini;
            max_profit = max(max_profit,current_profit);
            mini = min(prices[i],mini);
        }
        return max_profit;
    }
};



// class Solution {
// public:
//     int maxProfit(vector<int>& prices) 
//{
//         if(prices.size()<2)return 0;

//         int min = prices[0];
//         int pft = 0 ;

//         for (int i = 1 ; i < prices.size() ; i++)
//         {
//             if (prices[i]-min > pft)
//             {
//                 pft=prices[i]-min;
//             }
//             if (prices[i]<min)
//                     min=prices[i];    
                
//         }
//         return pft;
        
//     }
// };