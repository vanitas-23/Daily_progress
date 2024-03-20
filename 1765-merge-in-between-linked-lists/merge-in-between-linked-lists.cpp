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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *x=list1,*y=list2,*z=list1;
        for(int i=0;i<a-1;i++)
        x=x->next;

        for(int i=0;i<=b;i++)
        z=z->next;

        x->next=nullptr;
        ListNode* temp=list2;
        while(true){
             if(temp->next==nullptr){
             temp->next=z;
             break;}
             temp=temp->next;
        }
        x->next=list2;
        return list1;



    }
};