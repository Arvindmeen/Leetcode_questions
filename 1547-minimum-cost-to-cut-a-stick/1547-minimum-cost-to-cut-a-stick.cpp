class Solution {
public:
    int solve(int left,int right,vector<int>&cuts,vector<vector<int>>&dp){
        if(left>right)return 0;
        if(dp[left][right]!=-1)return dp[left][right];
        int ans=INT_MAX;
        for(int j=left;j<=right;j++){
            int cost=cuts[right+1]-cuts[left-1]+solve(left,j-1,cuts,dp)+solve(j+1,right,cuts,dp);
            ans=min(ans,cost);
        }
        return dp[left][right]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        int size=cuts.size();
        vector<vector<int>>dp(size,vector<int>(size,-1));
        return solve(1,size-2,cuts,dp);
    }
};