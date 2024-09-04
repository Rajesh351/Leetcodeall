class Solution {
private:
    static const vector<int> X;
    static const vector<int> Y;
public:
    static int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int i=0,j=0,res = 0,direction=0;
        set<pair<int,int>> st;
        for(const auto &it : obstacles){
            st.insert({it[0],it[1]});
        }

        for(const auto & command : commands){
            if(command == -1){
                direction = (direction+1) % 4;
            }else if(command == -2){
                direction = (direction-1);
                if(direction < 0) direction = 3;
            }else{
                for(int dist=0; dist < command; dist++){
                    int ii = X[direction] + i;
                    int jj = Y[direction] + j;
                    if(st.find({ii,jj}) != st.end()) break;
                    i=ii;j=jj;
                    res = max(res,i*i + j*j);
                }
            }
        }
        return res;
    }
};

const vector<int> Solution::X = {0, 1, 0, -1};
const vector<int> Solution::Y = {1, 0, -1, 0};
