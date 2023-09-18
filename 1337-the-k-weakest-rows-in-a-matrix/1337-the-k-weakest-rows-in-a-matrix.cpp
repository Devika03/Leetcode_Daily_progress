class Solution {
public:
    static bool customComp(pair<int, int>& A, pair<int, int>& B){
      if(A.first == B.first) return A.second < B.second;
      return A.first < B.first;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> orderNums;
        vector<int> ans;
        for(int i=0;i<mat.size();i++){
          int Ones = 0;
          for(auto num: mat[i])  if(num == 1) Ones++; 
          orderNums.push_back({Ones, i});
        }
        sort(orderNums.begin(), orderNums.end(), customComp);
        for(int i=0;i<k;i++) ans.push_back(orderNums[i].second);
        return ans;
    }
};