class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& ar, int k) {
        int n=ar.size();
        deque<int> dq; // our deque consists of only indexes
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!dq.empty() && dq.front()==i-k){
                dq.pop_front(); // popping out the index out of bounds elements
            }
            while(!dq.empty() && ar[dq.back()]<=ar[i]){
                dq.pop_back(); // as we are having <= deque anything greater comes all the elements before it which are smaller must be popped.
            }
            dq.push_back(i);
            if(i>=k-1){ // for every window
                ans.push_back(ar[dq.front()]); // our max will be at front 
            }
        }
        return ans;
    }
};