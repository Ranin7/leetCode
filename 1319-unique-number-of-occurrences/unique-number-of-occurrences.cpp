class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        unordered_set<int> seen;

        for (int num : arr) {
            freq[num]++;
        }

        for (auto& entry : freq) {
            if (seen.count(entry.second)) {
                return false;  
            }
            seen.insert(entry.second);
        }

        return true;
    }
};
