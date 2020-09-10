class Solution {
    public int[] searchRange(int[] nums, int target) {
        int i = 0, j = nums.length-1;
        if(nums.length == 0)
        {
            return new int[] {-1,-1};
        }
        if(target > nums[nums.length-1])
        {
            return new int[] {-1,-1};
        }
        for(;i <= j;)
        {
            if(nums[i] < target)
            {
                i++;
            } 
            if(nums[j] > target)
            {
                j--;
            }
            if(nums[i] == target && nums[j] == target)
            {
                return new int[] {i,j};
            }
        }
        return new int[] {-1,-1};   
    }
}