class ATM {
    private:
    vector<long long> count;
    const vector<int> denominations = {20, 50, 100, 200, 500};


public:
    ATM() {
        count = vector<long long>(5, 0);
    }
    
    void deposit(vector<int> banknotesCount) {
          for (int i = 0; i < 5; ++i) {
            count[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
         vector<int> result(5, 0);
        int remaining = amount;
            for (int i = 4; i >= 0; --i) {
            int value = denominations[i];
            long long available = count[i];
            long long take = min((long long)(remaining / value), available);
            result[i] = (int)take;
            remaining -= take * value;
        }
         if (remaining != 0) {
            return {-1}; }
                for (int i = 0; i < 5; ++i) {
            count[i] -= result[i];
        }
        
        return result;
    }
    
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */