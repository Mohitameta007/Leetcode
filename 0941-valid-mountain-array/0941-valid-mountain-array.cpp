class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() == 0 || arr.size() == 1) return false;
        int temp = 1;
        bool peak = false;
        bool isuphill = false;

        while(temp < arr.size())
        {
            if(arr[temp-1] < arr[temp] && peak == false)
            {
                isuphill = true;
                temp++;
            }
            else if(arr[temp-1] > arr[temp] && peak == false && isuphill == true)
            {
                peak = true;
                temp++;
            }
            else if((arr[temp-1] > arr[temp]) && peak == true && isuphill == true)
            {
                temp++;
            }
            else return false;
        }
        if(peak == true && isuphill == true) return true;
        else return false;
    }
};