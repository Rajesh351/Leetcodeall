class Solution {
public:
    string compressedString(string word) {

        string ans = "";
        int count = 1; // Initialize count as 1 to include the first character
        int i = 0;

        for (i = 0; i < word.size() - 1; i++) {
            if (word[i] == word[i + 1]) {
                count++;
            } else {

               if(count>0)
               {
                ans += to_string(count);
                ans += word[i]; // Add the count if greater than 1
               }
                count = 1; // Reset count for the next character sequence
            }

            // Special case when count reaches 9
            if (count == 9) {

                ans += to_string(count);
                ans += word[i];
                count = 0;
            }
        }

        // Handle the last character sequence
       if(count>0)
       {
        ans += to_string(count);
        ans += word[i];
       }

        return ans;
    }
};