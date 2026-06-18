class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> hash_map;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        hash_map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        const auto& pairs = hash_map[key];
        int l = 0, r = pairs.size() - 1;
        string result  = "";

        while (l <= r) {
            int m = (r - l) / 2 + l;
            if (pairs[m].first > timestamp) {
                r = m - 1;
            } else {
                result = pairs[m].second;
                l = m + 1;
            }
        }
        return result;
    }
};
