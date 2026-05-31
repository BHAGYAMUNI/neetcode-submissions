class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> mp;

public:
    TimeMap() {
        // Constructor
    }

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (!mp.count(key)) return "";

        const vector<pair<int, string>>& vec = mp[key];
        int low = 0, high = vec.size() - 1;
        string res = "";

        // Binary search for largest timestamp ≤ given timestamp
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (vec[mid].first <= timestamp) {
                res = vec[mid].second;  // possible result, go right
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return res;
    }
};
