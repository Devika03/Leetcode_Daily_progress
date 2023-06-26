class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int cd) {
        long long ans = 0;
        priority_queue< int, vector< int >, greater < int > > pql,pqr;
        if(cd * 2 >= costs.size()) {
            sort(costs.begin(), costs.end());
            for(int i = 0; i < k; i++) ans += costs[i];
            return ans;
        }
        int l = 0, r = costs.size() - 1;
        for( ; l <= cd-1; l++) pql.push(costs[l]);
        l--;
        for( ; r >= costs.size() - cd; r--) pqr.push(costs[r]);
        r++;

        while(k --> 0) {
            if(pql.empty() || pqr.empty()) {
                if(pql.empty()) {
                    ans += pqr.top();
                    pqr.pop();
                }else {
                    ans += pql.top();
                    pql.pop();
                }
            }else 
            {    if(pql.top() <= pqr.top()) {
                    ans += pql.top();
                    pql.pop();
                    if(l+1 < r) pql.push(costs[l+1]);
                    l++;
                }else {
                    ans += pqr.top();
                    pqr.pop();
                    if(r-1 > l) pqr.push(costs[r-1]);
                    r--;
                }
            }
        }
        return ans;
        
    }
};