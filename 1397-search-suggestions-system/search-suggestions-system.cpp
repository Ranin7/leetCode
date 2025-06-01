class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result;
        sort(products.begin(), products.end()); 

        string prefix;
        for (char c : searchWord) {
            prefix += c;

            auto it = lower_bound(products.begin(), products.end(), prefix);
            vector<string> suggestions;

            for (int i = 0; i < 3 && it + i != products.end(); ++i) {
                string& word = *(it + i);
                if (word.substr(0, prefix.size()) == prefix) {
                    suggestions.push_back(word);
                } else {
                    break;
                }
            }

            result.push_back(suggestions);
        }

        return result;
    }
};
