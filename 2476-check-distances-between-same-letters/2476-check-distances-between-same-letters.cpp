class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {

        std::unordered_map<char, int>mp;
        std::vector<int> computedDistances(26, INT_MIN); 

        for (int i = 0; i < s.size(); i++) {
            int charIndex =s[i] - 'a';
            if (mp.find(s[i]) != mp.end()) {
                // Calculate the distance between current and first occurrence
                int firstOccurrence = mp[s[i]];
                computedDistances[charIndex] = i-1- firstOccurrence;
            } else {
                // Store the first occurrence of the character
                mp[s[i]] = i;
            }
        }

        // Compare computed distances with the given distances
        for (int i = 0; i < 26; i++) {
           
          if(computedDistances[i]!=INT_MIN && computedDistances[i]!=distance[i]) return false;
        }
        return true;
    }
};