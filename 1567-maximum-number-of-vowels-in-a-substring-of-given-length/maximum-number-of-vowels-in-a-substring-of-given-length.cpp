class Solution {
public:
    int maxVowels(string s, int k) {
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        int count = 0, maxCount = 0;

        for (int i = 0; i < k; ++i) {
            if (isVowel(s[i])) count++;
        }

        maxCount = count;

        for (int i = k; i < s.length(); ++i) {
            if (isVowel(s[i - k])) count--;  
            if (isVowel(s[i])) count++;      
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};
