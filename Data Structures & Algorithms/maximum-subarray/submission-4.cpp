class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        //THIS IS THE BRUTE FORCE O(n^3) 
    //     int maxSum = -1;
    //     for (int i = 0; i < nums.size(); ++i)
    //     {
    //         for (int j = i; j < nums.size(); ++j)
    //         {
    //             int currentSum = 0;
    //             for(int k = i; k <= j ; ++k)
    //             {
    //                 currentSum += nums[k];
    //             }
    //             maxSum = max(maxSum, currentSum);
    //         }
    //     }
    //     return maxSum;
    // }

        //how to improve?, how can we get to O(n^2)
        int maxSum = -1;
        for(int i = 0; i < nums.size(); ++i)
        {
            int currentSum = 0;
            for(int j = i; j < nums.size(); ++j)
            {
                currentSum += nums[j];
                maxSum = max(currentSum, maxSum);
            }
        }
        return maxSum;
    }
};
