class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        if(nums.size() == 0) return;
        if(nums.size() == 1) return;


        int pivot = nums.size()-1;
        int smaller = 0;
        while(pivot > 0)
        {
            if(nums[pivot] > nums[pivot-1])
            {
                smaller = pivot-1;
                break;
            }
            pivot--;
        }
        if(pivot == 0) {
            reverse(nums.begin() , nums.end());
            return;
        }
        pivot = nums.size()-1;
        while(pivot > smaller)
        {
            if(nums[pivot] > nums[smaller])
            {
                swap(nums[pivot] , nums[smaller]);
                break;
            }
            pivot--;
        }

        reverse(nums.begin()+smaller+1 , nums.end());
    }
};