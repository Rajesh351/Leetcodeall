class Solution {
public:
    static bool comp( pair<int,int>&a,pair<int,int>&b){
        return a.first<b.first;
    }
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& h, string d) {
        vector<pair<int,int>>v;
        int n = pos.size();
         
        for( int  i = 0; i< n; i++){
            v.push_back({pos[i], i});                //storing the position with index
        }
        sort(v.begin(),v.end(),comp);                //sort acc to pos
        stack<int>st;                               // store the index of remaining robot whose surviving till now
        vector<int>ans;
        
        for( int i= 0; i < n; i++){
            
            int ind =  v[i].second;                 // finding respective index of that pos           
            
            if( d[ind] =='L'){                       // check the dir if it is left 
                if(st.empty()) ans.push_back(ind);   // if there is nothing to collide for  a particle that moving in left direction so it never collide to anyone  so its health never decrease  , so push into our final ans  
                else{
                    while( !st.empty() && h[st.top()] <  h[ind]){      // check if anyone going to right dir and with min health with current robot which moving in Left
                        st.pop();   //removing right moving robot with min health 
                        h[ind]--;   //health of cur robot decrease by one
                    }
                    if( st.empty())ans.push_back(ind);  // if there no right moving robot remain so again push into our final ans 
                    else{
                        if( h[st.top() ] == h[ind])st.pop();   // if left and right moving robot have same health then  remove both robot 
                        else {
                            h[st.top()]--;   //if right moving element having more health than left ,then health of right moving decrease  by one  
                             if( h[st.top()]== 0)st.pop();   // if( health of right moving become zero which at the top of stack them removing from stack )
                             }
                    }
                }
            }
            else {
                st.push(ind);  // if cur robot is right moving so it don't collide with previous right moving robots so simply store the index of this one  
            }
        }
        
        while( !st.empty()){
            ans.push_back(st.top());   // now storing tha index of remaining right moving robot whose survive till the end and present in stack
            st.pop();
        }
        sort( ans.begin(),ans.end());    // acc to question result store in intial given state  
        
        for( int i =0; i< ans.size(); i++)ans[i] = h[ans[i]];   // now assigning  health of robot with index ans[i] 
        return ans;
    }
};