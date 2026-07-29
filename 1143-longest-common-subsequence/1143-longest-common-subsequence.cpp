class Solution {
public:
   int solve(int left,int right,string &test1,string &test2,vector<vector<int>>&dp){
    if(left<0 || right<0)return 0;
    if(dp[left][right]!=-1)return dp[left][right];
     if(test1[left]==test2[right]){
        return dp[left][right]= 1+solve(left-1,right-1,test1,test2,dp);
     }
     else{
        return dp[left][right]= max(solve(left-1,right,test1,test2,dp),solve(left,right-1,test1,test2,dp));
     }
   }
    int longestCommonSubsequence(string test1, string test2) {
        int left=test1.length();
        int right=test2.length();
        vector<vector<int>>dp(left,vector<int>(right,-1));
        return solve(left-1,right-1,test1,test2,dp);
    }
};