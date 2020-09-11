class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int currMax = nums[0];
        int currMin = nums[0];
        int globalMax = nums[0];
        //We will apply Kadane's Algorithm.
        for(int i = 1; i < nums.size(); i++) 
        {
            /*We will move through the array once
            Each time we get to a new index we have 3 options.
            
            1.) Our new max is our current index.
            2.) Our new max is our old max * current index.
            3.) Our new max is our old min * current index. (as negative values will switch the min to max.)
            */
            int tempMax = currMax; //We change our currMax before we use it for checking the changes of currMin, thus save it to a temporary variable to prevent errors.
            currMax  = max(nums[i], max(currMax*nums[i],currMin*nums[i]));
            if(currMax > globalMax)
                globalMax  = currMax;
            /*
            Again we have 3 options
            
            1.) Our new min is our current index.
            2.) Our new min is our old max * current index.
            3.) Our new min is our old min * current index. (as negative values will switch the min to max.)
            */
            currMin = min(nums[i],min(tempMax*nums[i],currMin*nums[i]));
        }
        return currMax > globalMax ? currMax : globalMax;
    }
};