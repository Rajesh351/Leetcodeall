/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
       

        ListNode *prev=head;
        ListNode *curr=head->next;
        if(curr->next==NULL) return {-1,-1};
        ListNode *next=curr->next;
         int count=2;
         vector<int>v;
        while(curr->next!=NULL)
        {
            if(prev->val<curr->val && curr->val>next->val)
             {
                v.push_back(count);
             }
            
            else if(prev->val>curr->val && curr->val <next->val)
            {
                v.push_back(count);
            }
            count++;
            prev=curr;
            curr=curr->next;
            if(curr->next!=NULL) next=curr->next;
        }
         
         if(v.size()>1)
         {
        int maxdis=abs(v[0]-v[v.size()-1]);
        int mindis=INT_MAX;
        for(int i=1;i<v.size();i++)
        {
            mindis=min(mindis,v[i]-v[i-1]);
        }
        vector<int>v1;
        v1.push_back(maxdis);
        v1.push_back(mindis);
        sort(v1.begin(),v1.end());
        return v1;
         }
         return {-1,-1};
        
    }
};