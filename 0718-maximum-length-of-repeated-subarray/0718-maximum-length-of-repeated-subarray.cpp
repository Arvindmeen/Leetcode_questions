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
        vector<vector<int>>dp(left+1,vector<int>(right+1,0));
        // return solve(left-1,right-1,test1,test2,dp);
        int ans=0;
        for(int i=1;i<=left;i++){
            for(int j=1;j<=right;j++){
                if(test1[i-1]==test2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }
                else dp[i][j]=0;
            }
        }
        return ans;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        string s1="";
        string s2="";
        for(int x:nums1)s1+=x;
        for(int x:nums2)s2+=x;
        return longestCommonSubsequence(s1,s2);
    }
};