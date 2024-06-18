class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        


        sort(trainers.begin(),trainers.end());
        sort(players.begin(),players.end());
        int count=0;
        int j=0;
        for(int i=0;i<players.size();i++)
        {
            while(j<trainers.size())
            {
                 if(trainers[j]>=players[i]){
                    count++;
                     j++;
                    break;
                 }
                 else
                 j++;
            }
        }
        return count;
    }
};