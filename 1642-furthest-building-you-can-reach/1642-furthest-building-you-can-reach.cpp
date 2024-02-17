class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int i=0;
        priority_queue<int> pq;
        for(i;i<heights.size()-1;i++){
            if(heights[i+1]<=heights[i])
                continue;
            int d=heights[i+1]-heights[i];
            if(bricks>=d){
                bricks-=d;
                pq.push(d);
            }
            else if(ladders>0){
                if(pq.size()){
                int x=pq.top();
                if(x>d){
                    pq.pop();
                    bricks+=x;
                    bricks-=d;
                    pq.push(d);
                    
                }
                }
                ladders--;
            }
            else break;
        }
       return i; 
    }
};