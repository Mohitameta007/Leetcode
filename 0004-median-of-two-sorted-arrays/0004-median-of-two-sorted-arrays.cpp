class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merge;
        int n1 = 0;
        int n2 = 0;

        while(n1 != nums1.size() && n2 != nums2.size())
        {
            if(nums1[n1] < nums2[n2])
            {
                merge.push_back(nums1[n1]);
                n1++;
            }
            else 
            {
                merge.push_back(nums2[n2]);
                n2++;
            }
        }

        while(n1 != nums1.size())
        {
            merge.push_back(nums1[n1]);
            n1++;
        }
        while(n2 != nums2.size())
        {
            merge.push_back(nums2[n2]);
            n2++;
        }

        int size = merge.size();
        double ans = 0;

        if(size % 2 == 0)
        {
            ans = (merge[size/2]+merge[(size/2)-1]);
            return ans/2;
        }
        else return merge[size/2];

    }
};