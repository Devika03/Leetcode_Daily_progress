class Solution {
public:
     int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> rooms(n);
        sort(begin(meetings), end(meetings)); // step 1 - sort
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> used; // create both heaps
        priority_queue<int, vector<int>, greater<>> free; // create both heaps
        for (int i = 0; i < n; ++i){
            free.push(i); // enqueue all into the free-room heaps
        }
        for (auto& e : meetings){
            long long st = e[0];
            while(!used.empty() && st >= used.top().first){  // if the room ends before it starts, put it into the free-room heap
                free.push(used.top().second);
                used.pop();
            }
            if (free.empty()){ // take top from the used-room heap if needed.
                auto [time, r] = used.top();
                st = time;
                used.pop();
                free.push(r);
            }
            int r = free.top();
            free.pop();
            rooms[r]++;
            used.push({st+e[1]-e[0], r}); // used the room, enqueue it.
        }
        return max_element(begin(rooms), end(rooms)) - begin(rooms);
    }
};