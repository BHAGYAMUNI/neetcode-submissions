class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minH;
    int sizeK;
    KthLargest(int k, vector<int>& nums) {
        sizeK = k;
        for (int val : nums) {
            minH.push(val);
            if (minH.size() > sizeK) {
                minH.pop();
            }
        }
    }

    int add(int val) {
        minH.push(val);
        if (minH.size() > sizeK) {
            minH.pop();
        }
        return minH.top(); // This is the kth largest
    }
};
