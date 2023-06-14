class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int>st;//st contains indexes.
        int lse[n];
        int rse[n];
        

        for (int i = 0; i <n; i++)//For lse[]
        {
            while (!st.empty() && heights[st.top()]>= heights[i]) st.pop();
            if (st.empty()) lse[i]=0;
            else lse[i] = st.top()+ 1;
            st.push(i);
        }

        st = {};//We clear the stack to be re-used. 

        for (int i = n-1; i >=0; i--)//For rse.
        {
            while (!st.empty() && heights[st.top()] >= heights[i])st.pop();
            
            if (st.empty()) rse[i] = n-1;
            else rse[i] = st.top() - 1;
            st.push(i);
        }
        
        int max_Area = 0;
        for (int i = 0; i < n; i++) max_Area = max(heights[i] * (rse[i] - lse[i] + 1), max_Area);
   
    return max_Area;
    }
    };
