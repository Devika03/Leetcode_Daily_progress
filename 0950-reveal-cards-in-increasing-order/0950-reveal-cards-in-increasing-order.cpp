class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        queue<int> q;
        int n = deck.size();
        vector<int> result(n);
        for (int i = 0; i < n; ++i)
            q.push(i);
        for (int card : deck) {
            int idx = q.front();
            q.pop();
            result[idx] = card;
            if (!q.empty()) {
                int next_idx = q.front();
                q.pop();
                q.push(next_idx);
            }
        }
        
        return result;
    }
};