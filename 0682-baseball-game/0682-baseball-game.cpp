class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int ans = 0;

        for(int i = 0 ; i < operations.size() ; i++)
        {
            if(operations[i] == "+")
            {
                int first = st.top();
                st.pop();
                int temp = first+st.top();
                st.push(first);
                st.push(temp);
            }
            else if(operations[i] == "D")
            {
                int temp = st.top();
                st.push(temp*2);
            }
            else if(operations[i] == "C")
            {
                st.pop();
            }
            else{
                st.push(stoi(operations[i]));
            }
        }

        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};