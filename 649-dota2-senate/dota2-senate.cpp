class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant, dire;
        int n = senate.length();

        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }

        while (!radiant.empty() && !dire.empty()) {
            int rIndex = radiant.front(); radiant.pop();
            int dIndex = dire.front(); dire.pop();

            if (rIndex < dIndex) {
                radiant.push(rIndex + n);
            } else {
                dire.push(dIndex + n);
            }
        }

        return radiant.empty() ? "Dire" : "Radiant";
    }
};
