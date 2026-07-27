class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int>pq;
        for(int x:nums)pq.push(x);
        int total=pq.top()-1;
        pq.pop();
        total*=(pq.top()-1);
        return (total);
    }
};