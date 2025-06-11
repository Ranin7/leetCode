class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 0) return 0;

        int cash = 0;           // الربح عندما لا نملك سهمًا
        int hold = -prices[0];  // الربح عندما نملك سهمًا (بدأنا بشراء أول يوم)

        for (int i = 1; i < n; ++i) {
            cash = max(cash, hold + prices[i] - fee);  // نبيع
            hold = max(hold, cash - prices[i]);        // نشتري
        }

        return cash;
    }
};
