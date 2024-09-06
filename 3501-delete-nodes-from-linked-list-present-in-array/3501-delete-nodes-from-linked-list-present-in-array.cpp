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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
      unordered_map<int,int>mp;
      for(auto a:nums) mp[a]++;
      ListNode *temp=head;
      vector<int>v;
        while(temp!=NULL)
        {
            if(mp.find(temp->val)==mp.end())
            v.push_back(temp->val);

            temp=temp->next;
        }
        ListNode *ans=new ListNode(-1);
        ListNode *p=ans;
        for(int i=0;i<v.size();i++)
        {
            ListNode *newNode=new ListNode(v[i]);
            p->next=newNode;
            p=p->next;
        }
        return ans->next;
    }
};