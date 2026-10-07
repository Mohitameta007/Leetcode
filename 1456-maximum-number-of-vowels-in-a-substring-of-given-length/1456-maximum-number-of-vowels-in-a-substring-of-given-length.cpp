class Solution {
public:
    int maxVowels(string s, int k) {
        int start = 0;
        int end = 0;
        int vowel = 0;
        while(end < k)
        {
            if(s[end] == 'a' || s[end] == 'e' || s[end] == 'i' || s[end] == 'o' || s[end] == 'u') vowel++;
            end++;
        }
        int maxi = vowel;
        
        while(end < s.size())
        {
            if(s[start] == 'a' || s[start] == 'e' || s[start] == 'i' || s[start] == 'o' || s[start] == 'u') vowel--;
            start++;
            if(s[end] == 'a' || s[end] == 'e' || s[end] == 'i' || s[end] == 'o' || s[end] == 'u') vowel++;
            end++;

            maxi = max(vowel , maxi);
        }

        return maxi;
    }
};