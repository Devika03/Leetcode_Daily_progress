class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        if(mat == target){
            return true;
        }
        //transpose
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
        //reversing 
        for(int i = 0; i < n; i++){
            reverse(mat[i].begin(), mat[i].end());
        }
        if(mat == target){
            return true;
        }
        //repeating above steps total 3 times for 90,180,270 degree 
         for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
        for(int i = 0; i < n; i++){
            reverse(mat[i].begin(), mat[i].end());
        }
        if(mat == target){
            return true;
        }
         for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
        for(int i = 0; i < n; i++){
            reverse(mat[i].begin(), mat[i].end());
        }
        if(mat == target){
            return true;
        }
        return false;
    }
};