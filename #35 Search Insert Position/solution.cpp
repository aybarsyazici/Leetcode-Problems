class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return 0;
        int i = 0, j = nums.size()-1;
        for(;i < j;)
        {
            cout << "i is " << i << " j is " << j << endl;
            if(target == nums[i] || target == nums[j])
                return target == nums[i] ? i:j;
            else{
                if(target > nums[i])
                    i++;
                if(target < nums[j])
                    j--;
            }
        }
        if(nums[j] < target){
            return j+1;
        }
        return i;
    }
};