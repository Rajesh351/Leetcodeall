class MapSum {
public:
    unordered_map<string, int> mp;

    MapSum() {}

    void insert(string key, int val) {
        mp[key] = val;
    }

    int sum(string prefix) {
        int count = 0;

        for (const auto& it : mp) {
            const string& s = it.first;
            if (s.find(prefix) == 0) { // Check if the string starts with the prefix
                count += it.second;
            }
        }

        return count;
    }
};
