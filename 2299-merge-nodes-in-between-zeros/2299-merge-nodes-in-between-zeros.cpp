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
    ListNode* mergeNodes(ListNode* head) {

        ListNode* temp = head->next;
        int sum = 0;
        ListNode* ans = new ListNode(-1);
        ListNode* p = ans;
        while (temp != NULL) {
            if (temp->val == 0) {

                ans->next= new ListNode(sum);
                sum=0;
                ans = ans->next;
            } else {
                sum += temp->val;
            }
            temp = temp->next;
        }
        return p->next;
    }
};