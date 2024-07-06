class Solution {
public:
    int reverse(int x) 
    {
        int flag = 1; 
        if(x<0) flag =-1;
        
        long pop = 0 ; 
        int unit_dig = 0 ;
        
        x = abs(x);
        while(x!=0)
        {
            unit_dig=x%10;
            pop = pop*10 +unit_dig;
            x=x/10;
        }
        if(flag==-1 && flag*pop<INT_MIN) return 0;
        if(flag==1 && flag*pop>INT_MAX) return 0;
        
        return (int)(flag*pop);
    }
};