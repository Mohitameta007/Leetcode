class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int leftmax = 0;
        int right = height.size()-1;
        int rightmax = 0;
        int trapwater = 0;

        while(left < right)
        {
            leftmax = max(leftmax , height[left]);
            rightmax = max(rightmax , height[right]);

            if(height[left] <= height[right])
            {
                if(leftmax > 0 && rightmax > 0 && leftmax > height[left])
                {
                    trapwater += min(leftmax , rightmax) - height[left];
                }
                left++;
            }
            else
            {
                if(leftmax > 0 && rightmax > 0 && rightmax > height[right])
                {
                    trapwater += min(leftmax , rightmax) - height[right];
                }
                right--;
            }
        }

        return trapwater;
    }
};