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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *temp=head;
        int n=0;
        while(temp)
        {
            temp=temp->next;
            n++;
        }
        int size=n/k;
        int rem=n%k;
        temp=head;
        vector<ListNode *>ans;
        while(temp)
        {
            ListNode *c=new ListNode(100);
            ListNode *tempc=c;
            int s=size;
            if(rem>0) s++;
            rem--;
            for(int i=0;i<s;i++)
            {
                  tempc->next=temp;
                  temp=temp->next;
                  tempc=tempc->next;
            }
            tempc->next=NULL;
            ans.push_back(c->next);
        }
        if(ans.size()<k)
        {
            int extra=k-ans.size();
            for(int i=0;i<extra;i++)
            {
                ans.push_back(NULL);
            }
        }
        return ans;
    }
    
};