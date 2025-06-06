class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) return false;

        vector<int> freq1(26, 0), freq2(26, 0);
        unordered_set<char> chars1, chars2;

        for (char c : word1) {
            freq1[c - 'a']++;
            chars1.insert(c);
        }

        for (char c : word2) {
            freq2[c - 'a']++;
            chars2.insert(c);
        }

        if (chars1 != chars2) return false;

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
    }
};
