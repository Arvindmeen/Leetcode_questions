class Solution {
public:
    int solve(int i,int sum,int target,vector<int>&nums){
        int n=nums.size();
        if (i == n) {
            return (sum == target);
        }
        int negative=solve(i+1,sum-nums[i],target,nums);
        int postive=solve(i+1,sum+nums[i],target,nums);
        return negative+postive;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return solve(0,0,target,nums);
    }
};