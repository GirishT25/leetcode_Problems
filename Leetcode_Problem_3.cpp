// a b c a b c
// | | | | | |
// 0 1 2 3 4 5
// | | | | | |
// 97 98 99 97 98 99




#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastIndex;
    int maxLen = 0, start = 0;

    for (int end = 0; end < s.length(); end++) {
        char currentChar = s[end];
        if (lastIndex.find(currentChar) != lastIndex.end() && lastIndex[currentChar] >= start) {
            start = lastIndex[currentChar] + 1;  // Move the start to the right of the repeated character
        }

        lastIndex[currentChar] = end;
        maxLen = max(maxLen, end - start + 1);
    }

    return maxLen;
}

int main() {
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}
