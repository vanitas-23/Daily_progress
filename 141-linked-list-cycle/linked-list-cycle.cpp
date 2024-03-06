/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        while(head!=NULL){
            if(head->val!=INT_MAX)
            head->val=INT_MAX;
            else
            return true;
            head=head->next;
        }
        return false;
    }
};
//return hasCycle(head.next);