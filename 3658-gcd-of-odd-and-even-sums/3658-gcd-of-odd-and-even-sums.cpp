class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int evensum = n * (2 * 2 + ( n - 1 ) * 2) / 2;
        int oddsum  = n * (2 * 1 + ( n - 1 ) * 2) / 2;
        return gcd(evensum , oddsum);

        
    }
};