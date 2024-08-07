class Solution {
public:
 const string oneToNineteen[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
const string tens[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
const string thousands[4] = {"", "Thousand", "Million", "Billion"};

string convertHundred(int n) {
    string result;
    if (n / 100 > 0) {
        result += oneToNineteen[n / 100] + " Hundred ";
        n %= 100;
    }
    if (n >= 20) {
        result += tens[n / 10] + " ";
        n %= 10;
    }
    if (n > 0) {
        result += oneToNineteen[n] + " ";
    }
    return result;
}

string convertToWords(long long n) {
    if (n == 0) {
        return "Zero";
    }

    string result;
    int i = 0;
    
    while (n > 0) {
        if (n % 1000 != 0) {
            result = convertHundred(n % 1000) + thousands[i] + " " + result;
        }
        n /= 1000;
        i++;
    }

    // Capitalize the first letter of the result
    if (!result.empty()) {
        result[0] = toupper(result[0]);
    }

    // Remove trailing space
    bool check=true;
    while(check)
    {
    if (result.back() == ' ') {
        result.pop_back();
    }
    else check=false;}

    return result;
}
    string numberToWords(int num) { 
    string str=convertToWords(num);
       return str;  
     }
};