class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // kandanes algorithm 

        int maxSum = nums[0], curSum = 0;
        
        for(int n : nums)
        {
            curSum = max(curSum, 0);
            curSum += n;
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};
