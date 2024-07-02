import java.util.Arrays;

class Solution {

    public boolean solve(int index1, int index2, String s, String p, Integer[][] dp) {
        if (index1 < 0 && index2 < 0) {
            return true;
        }

        if (index1 < 0) {
            while (index2 >= 0) {
                if (p.charAt(index2) != '*') {
                    return false;
                }
                index2 -= 2;
            }
            return true;
        }

        if (index1 >= 0 && index2 < 0) {
            return false;
        }

        if (dp[index1][index2] != null) {
            return dp[index1][index2] == 1;
        }

        boolean result = false;

        if (s.charAt(index1) == p.charAt(index2) || p.charAt(index2) == '.') {
            result = solve(index1 - 1, index2 - 1, s, p, dp);
        } else if (p.charAt(index2) == '*') {
            boolean zero = solve(index1, index2 - 2, s, p, dp);
            boolean one = (index1 >= 0 && (s.charAt(index1) == p.charAt(index2 - 1) || p.charAt(index2 - 1) == '.')) &&
                    solve(index1 - 1, index2, s, p, dp);

            result = zero || one;
        } else {
            result = false;
        }

        dp[index1][index2] = result ? 1 : 0;
        return result;
    }

    public boolean isMatch(String s, String p) {
        int n = s.length();
        int m = p.length();

        Integer[][] dp = new Integer[n + 1][m + 1];
        return solve(n - 1, m - 1, s, p, dp);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String s = "aa";
        String p = "a*";
        System.out.println(solution.isMatch(s, p)); // Output: true
    }
}
