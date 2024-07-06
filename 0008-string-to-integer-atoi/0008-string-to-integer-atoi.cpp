class Solution {
public:
    int myAtoi(string s) 
    {
        int i = 0 ;
        
        while(i<s.size() && s[i]==' ')
        {
            i++;
        }
        s = s.substr(i);
        
        int flag = 1;
        int skip_positivesign = 0;
        
        long ans = 0 ; 
        
        if(s[0]=='-') flag = -1;
        if(s[0]=='+') skip_positivesign=1;
        
        if(flag==1 && skip_positivesign==0 )
        {
            i=0;
        }
        else 
        {
            i=1;
        }
        
        while(i<s.size())
        {
            if(s[i]==' ' || !isdigit(s[i])) break;
            
            else
            {
                ans = ans*10 + s[i]-'0';
                
                if(flag==-1 && flag*ans<INT_MIN) return INT_MIN;
                if(flag==1 && flag*ans>INT_MAX) return INT_MAX;
                i++;
            }
        }
        return (int)(flag*ans);
    }
};