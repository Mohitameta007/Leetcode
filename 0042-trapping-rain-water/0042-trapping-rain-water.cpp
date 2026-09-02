class Solution {
public:
    int trap(vector<int>& height) {
        int units = 0;
        vector<int> leftmax(height.size() , 0);
        vector<int> rightmax(height.size() , 0);

        leftmax[0] = height[0];
        for(int i = 1 ; i < height.size() ; i++)
        {
            leftmax[i] = max(leftmax[i-1] , height[i]);
        }

        rightmax[height.size()-1] = height[height.size()-1];
        for(int i = height.size()-2 ; i >= 0 ; i--)
        {
            rightmax[i] = max(rightmax[i+1] , height[i]);
        }

        for(int i = 1 ; i < height.size()-1 ; i++)
        {
            if(height[i] < leftmax[i] && height[i] < rightmax[i])
            {
                units += min(leftmax[i] , rightmax[i]) - height[i];
            }
        }
        return units;
    }
};