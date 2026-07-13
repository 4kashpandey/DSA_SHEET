import java.util.*;

class Solution {
    // Function to calculate the maximum profit
    static int maximumProfit(int n, int fee, int[] Arr) {
        // Handle the base case when n is 0
        if (n == 0) {
            return 0;
        }

        int dp[][] = new int[n + 1][2];
        
        // Iterate through the array backwards
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;

                if (buy == 0) { // We can buy the stock
                    profit = Math.max(0 + dp[ind + 1][0], -Arr[ind] + dp[ind + 1][1]);
                }

                if (buy == 1) { // We can sell the stock
                    profit = Math.max(0 + dp[ind + 1][1], Arr[ind] - fee + dp[ind + 1][0]);
                }

                dp[ind][buy] = profit;
            }
        }

        // The maximum profit is stored in dp[0][0]
        return dp[0][0];
    }

    public static void main(String args[]) {
        int prices[] = {1, 3, 2, 8, 4, 9};
        int n = prices.length;
        int fee = 2;

        System.out.println("The maximum profit that can be generated is " + maximumProfit(n, fee, prices));
    }
}