class Solution {
public:
    int solve(int i,int buy,int times,vector<int>&prices,vector<vector<vector<int>>>&dp){
        int n=prices.size();
        if(i>=n || times==2)return 0;
        if(dp[i][buy][times]!=-1)return dp[i][buy][times];
        if(!buy && times<2){
            int skip=solve(i+1,buy,times,prices,dp);
            int take=-prices[i]+solve(i+1,1,times,prices,dp);
            return dp[i][buy][times]= max(skip,take);
        }
        else{
            int skip=solve(i+1,buy,times,prices,dp);
            int take=prices[i]+solve(i+1,0,times+1,prices,dp);
            return dp[i][buy][times]= max(skip,take);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
       vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
       return solve(0,0,0,prices,dp); 
    }
};