class Solution {
public:
    string sortVowels(string s) {
         auto isVowel = [](char ch) {
            ch = tolower(ch);
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        };

        // Step 1: Count frequency of each vowel (ASCII range 128 is enough)
        vector<int> freq(128, 0);
        for (char c : s) {
            if (isVowel(c)) freq[c]++;
        }

        // Step 2: Rebuild string with vowels in sorted order
        int cur = 0;  // ASCII index pointer
        for (char &c : s) {
            if (isVowel(c)) {
                while (cur < 128 && freq[cur] == 0) cur++;
                c = (char)cur;
                freq[cur]--;
            }
        }

        return s;
    }
};
