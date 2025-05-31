class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        int left = 0, right = n - 1;
        long long total = 0;

        priority_queue<int, vector<int>, greater<int>> leftHeap;
        priority_queue<int, vector<int>, greater<int>> rightHeap;

        // املأ الهيبين بالبداية
        while (leftHeap.size() < candidates && left <= right) {
            leftHeap.push(costs[left++]);
        }
        while (rightHeap.size() < candidates && left <= right) {
            rightHeap.push(costs[right--]);
        }

        for (int i = 0; i < k; ++i) {
            if (!leftHeap.empty() && (rightHeap.empty() || leftHeap.top() <= rightHeap.top())) {
                total += leftHeap.top();
                leftHeap.pop();
                if (left <= right) {
                    leftHeap.push(costs[left++]);
                }
            } else {
                total += rightHeap.top();
                rightHeap.pop();
                if (left <= right) {
                    rightHeap.push(costs[right--]);
                }
            }
        }

        return total;
    }
};
