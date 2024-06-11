#include <vector>
#include <algorithm>

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) 
    {
        // Sort both players and trainers
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        
        int count = 0;
        
        int i = 0, j = 0;
        
        // Traverse through both arrays to find the maximum number of matches
        while (i < players.size() && j < trainers.size()) 
        {
            if (players[i] <= trainers[j]) 
            {
                // If the current player can be matched with the current trainer
                count++;
                i++; 
                j++;
            }
            else{
            j++; }
        }
        
        return count;
    }
};





/*
int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) 
    {
        int count = 0;
        unordered_map<int,int>player_map;//<index,is_matched>
        unordered_map<int,int>trainer_map;//<index,is_matched>
        
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        
        for(int i = 0 ; i<players.size() ;i++ )
        {
            player_map[i]=0;
        }
        for(int i = 0 ; i<trainers.size() ;i++ )
        {
            trainer_map[i]=0;
        }
        
        for(int i = 0 ; i<players.size() ; i++)
        {
            if(player_map[i] == 0)
            {
                for(int j = 0 ; j<trainers.size() ; j++)
                {
                    if(players[i]<=trainers[j])
                    {
                        if(trainer_map[j]==0)
                        {
                        player_map[i]=1;
                        trainer_map[j]=1;
                        count++;
                        break;
                        }
                        
                    }
                    
                }
            }
        }
        return count;
        
    }
*/