class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
         sort(points.begin(), points.end(),
          [](const vector<int> &v1,const  vector<int> &v2) {return v1[1] < v2[1];} 
          );

        long previousEndPoint = points[0][1];
        int totalArowCount =1;

        for(int i=1; i<points.size(); i++)
        {
            if(previousEndPoint < points[i][0])
            {
                totalArowCount++;
                previousEndPoint = points[i][1];
            }
        }

        return totalArowCount;
    }
};