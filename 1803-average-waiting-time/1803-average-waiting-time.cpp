class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {

       long long currentTime = 0;
    long long totalWaitingTime = 0;
    int n = customers.size();

    for (const auto& customer : customers) {
        int arrivalTime = customer[0];
        int cookingTime = customer[1];

        if (currentTime < arrivalTime) {
            currentTime = arrivalTime;
        }

        currentTime += cookingTime;
        totalWaitingTime += (currentTime - arrivalTime);
    }

    return static_cast<double>(totalWaitingTime) / n;
      
    }
}; 