class Solution {
    bool isPossibleToFillAllBalls(vector<int>& position, int m, int currDiff) {
        // traverse and see if we can place m balls with currDiff space apart
        int prevPosition = position[0];
        int currBallPlaced = 1;
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - prevPosition >= currDiff) {
                currBallPlaced++;
                prevPosition = position[i];
                if (currBallPlaced == m) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    int maxDistance(vector<int>& position, int m) {

        sort(position.begin(), position.end());

        int bucketFilled = 0;

        int startDiff = 1;
        int endDiff = position[position.size() - 1] - position[0];

        int force = 0;

        while (startDiff <= endDiff) {
            int midDiff = startDiff + (endDiff - startDiff) / 2;
            if (isPossibleToFillAllBalls(position, m, midDiff)) {
                startDiff = midDiff + 1;
                force = midDiff;
            } else {
                endDiff = midDiff - 1;
            }
        }
        return force;
    }
};