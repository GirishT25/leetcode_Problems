class Solution {
public:
bool isVowel(char &ch){
    return(ch == 'a' || ch == 'i' || ch =='e' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'I' || ch == 'E' || ch == 'O' || ch == 'U'
        );
}
    bool halvesAreAlike(string s) {
        int n = s.length();

        int i = 0;
        int j = n/2;

        int countL = 0;
        int countR = 0;
         while(i < n/2 && j < n){
            if(isVowel(s[i])) countL++;

            if(isVowel(s[j])) countR++;

            i++;
            j++;
        }

        return countL == countR;
       
    }
};
