class Solution
{
public:
void setZeroes(vector<vector<int>>&matrix) {
int m = matrix.size();
int n = matrix[0].size();
    vector<int>rcheck(m,1);
    vector<int>ccheck(n,1);
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j< n; j++)
        {
            if(matrix[i][j]==0)
            {
                rcheck[i]=0;
                ccheck[j]=0;
            }
        }
    }
    for(int i =0 ; i < m ; i++)
    {
        if(rcheck[i]==0)
        {
            matrix[i].assign(n,0); // ith row will be filled with ncol. of 0s. 
        }
    }
    for(int j=0; j<n ;j++)
    {
        if(ccheck[j]==0)
        {
            for(int i =0 ; i< m ; i++)
            {
                matrix[i][j]=0;
            }
        }
    }}};

/*int m =matrix.size();
if(m==0)return;
int n=matrix[0].size();
if(n==0)
return;
vector<bool>rows(m,false),cols(n,false);
for(int i=0;i<m;++i){
for(int j=0;j<n;++j){
if(matrix[i][j]==0){
rows[i]=true;cols[j]=true;}}}
for(int i=0;i<m;++i){
if(rows[i]){
    for(int j=0;j<n;++j){matrix[i][j]=0;}}}
for(int j=0;j<n;++j){
if(cols[j]){
for(int i=0;i<m;i+i){
matrix[i][j]=0;*/