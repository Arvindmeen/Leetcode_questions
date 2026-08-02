class Solution {
public:
    int solve(int i,bool buy,vector<int>&prices,vector<vector<int>>&dp){
        int n=prices.size();
        if(i>=n)return 0;
        if(dp[i][buy] != -1)return dp[i][buy];

        if(!buy){
            int skip = solve(i+1, false, prices, dp);
            int take = -prices[i]+solve(i+1, true, prices, dp);
            return dp[i][0] = max(skip, take);
        }
        else{
            int skip = solve(i+1, true, prices, dp);
            int profit = prices[i];
            int take = profit + solve(i+1, false, prices, dp);
            return dp[i][1] = max(skip, take);
        }
    }
    int maxProfit(vector<int>& prices) {
       bool buy=false;
       bool sell=false;
       int n=prices.size();
    //    vector<vector<int>> dp(n,vector<int>(2, -1));
    //    return solve(0,buy,prices,dp);
    vector<vector<int>> dp(n+1,vector<int>(2, 0));
      for(int i=n-1;i>=0;i--){
        for(int j=0;j<=1;j++){
           if(!j){
            int skip = dp[i+1][0];
            int take = -prices[i]+dp[i+1][1];
            dp[i][0] = max(skip, take);
        }
        else{
            int skip = dp[i+1][1];
            int profit = prices[i];
            int take = profit + dp[i+1][0];
            dp[i][1] = max(skip, take);
        } 
        }
      }
     return dp[0][0];
    }
};