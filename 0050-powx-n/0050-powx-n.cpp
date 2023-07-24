class Solution {
public:
    double myPow(double x, long long int n) {
        
        if( n == 0) return 1;

        if( n < 0) {
            x = 1/x;
            n = -n;
        }
        double ans = myPow( x, n/2);
        ans = ans * ans;
        if( n%2 == 0) {

            return ans;
        }
        else  {
            return x*ans;
        }
    }
};