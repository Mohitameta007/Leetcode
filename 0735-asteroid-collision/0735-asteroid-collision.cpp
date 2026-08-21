class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;
        int i = 0;
        while(i < asteroids.size())
        {
            bool destroyed = false;
            if(st.empty()) st.push(asteroids[i]);

            else if(asteroids[i] < 0 && st.top() > 0)
            {
                int size = abs(asteroids[i]);
                while(!st.empty() && st.top() > 0)
                {
                    if(st.top() < size)
                    {
                        st.pop();
                    }
                    else if(st.top() == size) 
                    {
                        destroyed = true;
                        st.pop();
                        break;
                    }
                    else 
                    {
                        destroyed = true;
                        break;
                    }
                }
                if(!destroyed) st.push(asteroids[i]);
            }
            else{
                st.push(asteroids[i]);
            }
            i++;
        }

        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin() , ans.end());

        return ans;
    }
};