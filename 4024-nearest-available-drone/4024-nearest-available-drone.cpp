class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int mini =INT_MAX;
        int indx = -1;
        for(int i = 0 ; i < drones.size() ; i++)
        {
            int sum = abs(drones[i][0] - target[0]) + abs(drones[i][1] - target[1]);
            if(sum <= drones[i][2])
            {
                if(mini > sum)
                {
                    mini = sum;
                    indx = i;
                }
            }
        }
        return indx;
    }
};