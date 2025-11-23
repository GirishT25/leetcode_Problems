class Solution {
public:
    int minimumFlips(int n) {
        string s ;
        while(n){
            s += ('0' + n % 2);
            n = n / 2;
        }
        int changes = 0;
        int n1 = (int) s.length();
        for(int i = 0 ; i < n1 ; i++){
            if(s[i] != s[n1 - 1 - i]){
                changes++;
            }
        }
        return changes;
    }
};
