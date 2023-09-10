class Solution {
public:
const int modu=1e9+7;
long long solve(int n){
    //base case
    if(n==1)
    return 1;
    return (((n*(n+1))/2)%modu*(solve(n-2)%modu))%modu;
}
    int countOrders(int n) {
     if(n==1)
     return 1;
     if(n==2)
     return 6;
     int p=2*n-1;
     return (int)solve(p)%modu;
    }
};