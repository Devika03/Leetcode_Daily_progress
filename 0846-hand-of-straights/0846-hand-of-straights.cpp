class Solution {
public:
    bool check(vector<int>& hand, int groupSize, int i, int n) {
        int temp = hand[i];
        hand[i] = -1;
        int count = 1;
        i++;
        while (count < groupSize && i < n) {
            if (hand[i] == temp + 1) {
                count++;
                temp++;
                hand[i] = -1;
            }
            i++;
        }

        if (count == groupSize) {
            return true;
        } else {
            return false;
        }
    }

    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        sort(hand.begin(), hand.end());

        for (int i = 0; i < n; i++) {

            if (hand[i] != -1) {
                if (check(hand, groupSize, i, n) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};