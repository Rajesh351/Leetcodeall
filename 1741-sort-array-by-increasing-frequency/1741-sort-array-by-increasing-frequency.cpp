class Solution {
public:
    std::unordered_map<int, int> createFrequencyMap(const std::vector<int>& v) {
        std::unordered_map<int, int> freqMap;
        for (int num : v) {
            freqMap[num]++;
        }
        return freqMap;
    }
     static bool customComparator(const std::pair<int, int>& a,
                          const std::pair<int, int>& b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second < b.second;
    }
    vector<int> frequencySort(vector<int>& v) {
        std::unordered_map<int, int> freqMap = createFrequencyMap(v);
        std::vector<std::pair<int, int>> freqVec;
        for (int num : v) {
            freqVec.push_back({num, freqMap[num]});
        }
        std::sort(freqVec.begin(), freqVec.end(), customComparator);
        std::vector<int> sortedVec;
        for (const auto& pair : freqVec) {
            sortedVec.push_back(pair.first);
        }
        return sortedVec;
    }
};