class Solution {
public:
    vector<vector<int>> result;

    void backtrack(int k, int n, int start, vector<int>& path) {
        if (k == 0 && n == 0) {
            result.push_back(path);
            return;
        }

        for (int i = start; i <= 9; ++i) {
            if (i > n) break; // لا حاجة للاستمرار إذا تجاوزنا n

            path.push_back(i);
            backtrack(k - 1, n - i, i + 1, path);
            path.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        backtrack(k, n, 1, path);
        return result;
    }
};
