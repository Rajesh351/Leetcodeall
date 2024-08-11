class Solution {
public:
   vector<string> belowTwenty = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
                                  "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", 
                                  "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        return convert(num).substr(1); // Remove the leading space
    }

private:
    string convert(int num) {
        if (num == 0) return "";
        if (num < 20) return " " + belowTwenty[num];
        if (num < 100) return " " + tens[num / 10] + convert(num % 10);
        if (num < 1000) return " " + belowTwenty[num / 100] + " Hundred" + convert(num % 100);
        if (num < 1000000) return convert(num / 1000) + " Thousand" + convert(num % 1000);
        if (num < 1000000000) return convert(num / 1000000) + " Million" + convert(num % 1000000);
        return convert(num / 1000000000) + " Billion" + convert(num % 1000000000);
    }
};