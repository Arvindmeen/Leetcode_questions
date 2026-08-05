class Solution {
public:
    int solve(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
    int n=nums.size();
    if(i==n)return 0;
    if(dp[i][j+1]!=-1)return dp[i][j+1];
    int skip=0+solve(i+1,j,nums,dp);
    int take=0;
       if(j==-1 || nums[i]>nums[j]){
        take=1+solve(i+1,i,nums,dp);
        }
      return dp[i][j+1]= max(skip,take);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return solve(0,-1,nums,dp);

        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
               int skip=0+dp[i+1][j+1];
                int take=0;
                if(j==-1 || nums[i]>nums[j]){
                    take=1+dp[i+1][i+1];
                    }
                 dp[i][j+1]= max(skip,take); 
            }
        }
      return dp[0][0];
    }
};