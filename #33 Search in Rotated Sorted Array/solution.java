class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        while(start <= end)
        {
            //std::cout << "Start is: " << nums[start] << " End is: " << nums[end] << std::endl;
            if(nums[start] == target) //We have found the target
                return start;
            if(nums[end] == target) 
                return end;
            /*if(nums[end] < target) //Target can not be found anymore.
                return -1;*/
            if(end > 0 && nums[end-1] < nums[end])
                end--;
            start++;
        }
        return -1;
    }
};