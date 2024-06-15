class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        int n=profits.size();
        vector<pair<int,int>>v;
        for(int i=0;i<profits.size();i++){
            v.push_back({capital[i],profits[i]});
        }
        sort(v.begin(),v.end());
        int i=0;
        priority_queue<int>pq;
        while(k--){
            while(i<n && v[i].first<=w){
                pq.push(v[i].second);
                i++;
            }
            if(pq.empty()){
                break;
            }
            w+=pq.top();
            pq.pop();
        }
        return w;

    }
};