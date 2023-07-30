class Solution {
public:
    double soupServings(int n) {
        map<pair<double , double>, double> mp;
        return  n >= 4800 ? 1.0 : dfs(mp, (n+ 24)/25, (n+ 24)/25);
    }
    double dfs(map<pair<double , double>, double>& mp, int A, int B) {
        if(A <= 0) {
            if(B<=0) {
                return 0.5;
            }
            else return 1;
        }else if(B<=0) return 0;
        if(mp.count({A,B})) return mp[{A,B}];
        return mp[{A,B}] = 0.25*(dfs(mp, A-4, B)+dfs(mp, A-3, B-1)+dfs(mp, A-2, B-2)+dfs(mp, A-1, B-3));
    }
};