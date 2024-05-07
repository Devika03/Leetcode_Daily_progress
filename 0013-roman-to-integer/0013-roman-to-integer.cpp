class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>map;
        map['I'] =1;
        map['V'] =5;
        map['X'] =10;
        map['L'] =50;
        map['C'] =100;
        map['D'] =500;
        map['M'] =1000;
        int sum=0;
        for(int i = 0 ; i<s.size()-1 ; i++)//Traverse till (n-1)th Element and the value of ith Element will be added/subtracted to the sum depending on the value of the adjacent element.
        {
             auto it1=map.find(s[i]);
             auto it2=map.find(s[i+1]);
             if(it1->second >= it2->second)
             {
                 sum+=it1->second;
             }
            else
            {
                sum-=it1->second;
            }
        }
        auto it_last= map.find(s[s.size()-1]);
        sum+=it_last->second;
        return sum;

        
    }
};
// Create a string of size n and fill
// the string with character x.
//string s(size_t n, char x);




/*int sum =0;
        for(int i =0; i<s.size()-1; i++)
        {
            auto it1 =mp.find(s[i]);
            auto it2 =mp.find(s[i+1]);

            if(it1->second>=it2->second)
            {
                sum+=it1->second;
            }
            else
            {
                sum-=it1->second;
            }

        }
        sum+= mp[s[s.size()-1]];

        return sum;*/