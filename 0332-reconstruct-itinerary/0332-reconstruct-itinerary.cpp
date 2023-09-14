class Solution {
public:
    unordered_map<string,vector<string>>adj;
    int numTickets=0;
    vector<string>result;

    bool DFS(string fromAirport,vector<string>&paths){
        paths.push_back(fromAirport);
        if(paths.size()==numTickets+1){
            result=paths;
            return true;
        }
        vector<string>&neighbours=adj[fromAirport];
        for(int i=0;i<neighbours.size();i++){
            string toAirport=neighbours[i];
            neighbours.erase(neighbours.begin()+i);
            if(DFS(toAirport,paths)==true){
                return true;
            }
            neighbours.insert(neighbours.begin()+i,toAirport);
        }
        paths.pop_back();
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        numTickets=tickets.size();
        //fill the adj list
        for(auto&t:tickets){
            string u=t[0];
            string v=t[1];
            adj[u].push_back(v);
        }
        //sort on basis of lexographical order
        for(auto&edges:adj){
            sort(begin(edges.second),end(edges.second));
        }
        //DFS
        vector<string>paths;
        DFS("JFK",paths);
        return result;
    }
};