class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] < nums[i-1])
            {
                if(i > 2)
                {
                    if(nums[i-2] != nums[i] && nums[i] != nums[i-1])
                        swap(nums[i], nums[i-1]);
                    else
                    {
                        nums.erase(nums.begin()+i);
                        i--;
                    }
                    
                }
                else
                {
                    swap(nums[i], nums[i-1]);
                }
            }
            else if(nums[i] == nums[i-1])
            {
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        return nums.size();
    }
};