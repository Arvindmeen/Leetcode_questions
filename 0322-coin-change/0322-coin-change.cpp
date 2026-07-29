class Solution {
public:
   int solve(int i,int amount,vector<int>&coins,vector<vector<int>>&dp){
    if(amount==0)return 0;
    if(i>=coins.size() && amount!=0)return INT_MAX;
    if(dp[i][amount]!=-1)return dp[i][amount];
    int skip=solve(i+1,amount,coins,dp);
    int take=INT_MAX;
    if(amount>=coins[i]){
        int res = solve(i, amount - coins[i], coins,dp);
        if(res != INT_MAX)
            take = 1 + res;
        }
      
    return dp[i][amount]=min(take,skip);
   }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=solve(0,amount,coins,dp);
       return ans==INT_MAX?-1:ans;
    }
};


// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         if(amount==0)return 0;
//         if(coins.size()==1 && (coins[0]>amount || amount%coins[0]!=0))return -1;
//         sort(coins.begin(),coins.end(),[](int &a, int &b){
//             return a>b;
//         });
//         int ans=0;
//         for(int val:coins){
//             if(val>amount){
//               continue;
//             }
//             ans+=amount/val;
//             amount=amount-ans*val;
            
//              if(amount==0)return ans;
//        }
//        return ans;
//     }
// };