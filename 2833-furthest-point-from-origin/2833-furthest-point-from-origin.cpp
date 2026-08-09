class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int count = 0;
        int dashcount = 0;

        for(int i = 0 ; i < moves.size() ; i++)
        {
            if(moves[i] == 'L') count--;
            else if(moves[i] == 'R') count++;   
            else dashcount++;
        }

        if(count > 0) count += dashcount;
        else if(count == 0)  count += dashcount;
        else count -= dashcount;

        return abs(count);
    }
};