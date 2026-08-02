class Solution {
public:
    int solve(int i,bool buy,int fee,vector<int>&prices,vector<vector<int>>&dp){
        int n=prices.size();
        if(i>=n)return 0;
        if(dp[i][buy] != -1)return dp[i][buy];

        if(!buy){
            int skip = solve(i+1, false, fee,prices, dp);
            int take = -prices[i]+solve(i+1, true, fee,prices, dp);
            return dp[i][0] = max(skip, take);
        }
        else{
            int skip = solve(i+1, true, fee,prices, dp);
            int profit = prices[i];
            int take = (profit-fee) + solve(i+1, false, fee,prices, dp);
            return dp[i][1] = max(skip, take);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2, -1));
        return solve(0,false,fee,prices,dp);
    }
};