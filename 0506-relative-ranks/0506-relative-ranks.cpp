class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) 
    {
        int n = score.size();
        int index[n];
        for (int i = 0; i < n; i++)
            index[i] = i;
        sort(index, index + n, [&](const int x, const int y) {return score[x] > score[y];});

        vector<string> res (n, "");
        for (int i = 0; i < n; i++) {
            if (i == 0)
                res[index[i]] = "Gold Medal";
            else if (i == 1)
                res[index[i]] = "Silver Medal";
            else if (i == 2)
                res[index[i]] = "Bronze Medal";
            else
                res[index[i]] = to_string(i + 1);
        }
        return res;
    }
};