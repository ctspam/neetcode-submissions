class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i; j < nums.size(); ++j)
            {
                int currentSum = 0;
                for(int k = i; k <= j ; ++k)
                {
                    currentSum += nums[k];
                }
                maxSum = max(maxSum, currentSum);
            }
        }
        return maxSum;
    }
};
