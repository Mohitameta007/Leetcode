class Solution {
public:
    bool isHappy(int n) {
        long long temp = n;
        long long newn = 0;
        set<int> st;
        while(temp != 1)
        {
            while(temp > 0)
            {
                int dig = temp%10;
                newn += 1LL*dig*dig;
                temp /= 10;
            }
            temp = newn;
            newn = 0;
            auto it = st.find(temp);
            if(it != st.end()) return false;
            st.insert(temp);
        }
        return true;
    }
};