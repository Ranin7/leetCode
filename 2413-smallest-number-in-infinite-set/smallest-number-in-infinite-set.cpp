class SmallestInfiniteSet {
private:
    int curr;
    set<int> addedBack;

public:
    SmallestInfiniteSet() {
        curr = 1;
    }

    int popSmallest() {
        if (!addedBack.empty()) {
            int smallest = *addedBack.begin();
            addedBack.erase(smallest);
            return smallest;
        } else {
            return curr++;
        }
    }

    void addBack(int num) {
        if (num < curr) {
            addedBack.insert(num);
        }
    }
};
