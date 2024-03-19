class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        priority_queue<int> pq;
        for(auto x: tasks) mp[x]++;
        for(auto x: mp) pq.push(x.second);
        int time = 0;
        while(!pq.empty()){
            int cycle = n+1;
            vector<int> vec;
            while(!pq.empty() && cycle){
                if(pq.top() > 1)
                    vec.push_back(pq.top()-1);
                pq.pop();
                cycle--;
                time++;
            }
            for(auto x: vec)
                pq.push(x);
            
            if(pq.empty())
                break;
            
            time += cycle;
        }

        return time;
    }
};