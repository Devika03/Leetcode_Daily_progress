class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if(tokens.size() ==0 )
        return 0;
        sort(tokens.begin(),tokens.end());
        int score=0;
        int maxi=0;
        int i=0;
        int j=tokens.size()-1;
        while(i<=j){
            if(tokens[i] <= power){
                power-=tokens[i++];
                score++;
                  maxi=max(score,maxi);
            }
            else if(score >0){
                    power +=tokens[j--];
                    score--;
                }
            else{
                break;
            }
          
        }
        return maxi;
    }
};