class Solution {
public:
    vector<vector<int>> memo;
    
    int solve(string& ring, string& key, int ptr, int index) {
        int n = ring.size();
        int m = key.size();

        if (index >= m) return 0;

        if (memo[index][ptr] != -1) {
            return memo[index][ptr];
        }

        int steps = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (ring[i] == key[index]) {
                int distance = min(abs(i - ptr), n - abs(i - ptr)) + 1;
                steps = min(steps, distance + solve(ring, key, i, index + 1));
            }
        }
        memo[index][ptr] = steps;
        return steps;
    }

    int findRotateSteps(string ring, string key) {
        int ptr = 0;
        int index = 0;
        int n = ring.size();
        int m = key.size();
        memo.assign(m + 1, vector<int>(n + 1, -1));

        return solve(ring, key, ptr, index);
    }
};
