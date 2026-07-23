class Solution {
public:
    vector<string> findWords(vector<string>& words) {

        string keyboard = "qwertyuiopasdfghjklzxcvbnm" ;
        vector<string> ans;
        int row = 0;
        bool valid = true;
        for(int i = 0 ; i < words.size() ; i++)
        {
            int index = keyboard.find(tolower(words[i][0]));
            if(index >= 0 && index <= 9) row = 1;
            else if(index >= 10 && index <= 18) row = 2;
            else row = 3;

            valid = true;
            for(int j = 1 ; j < words[i].size() ; j++)
            {
                int index = keyboard.find(tolower(words[i][j]));
                if(row == 1 && index > 9)
                {
                    valid = false;
                    break;
                }
                if(row == 2 && (index < 10 || index > 18)) 
                {
                    valid = false;
                    break;
                }
                if(row == 3 && index < 19) 
                {
                    valid = false;
                    break;
                }
            }
            if(valid == true) ans.push_back(words[i]);
        }

        return ans;

    }
};