class Solution {
public:
int countSubstrings(string s) {
int l=0,r=0;
int count=0;
for(int i=0;i<s.size();i++){
l=i;
r=i;
while(l>0&&s[l-1]==s[l])l--;
while(r<(s.size()-1)&&s[r+1]==s[r])r++;
count+=((r-l+1)*(r-l+2))/2;
i=r;
while(l>0&&r<(s.size()-1)&&s[l-1]==s[r+1]){
l--;
r++;
count++;
}
}
return count;
}
};