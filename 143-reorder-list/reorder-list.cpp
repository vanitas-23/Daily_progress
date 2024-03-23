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
    void reorderList(ListNode* head) {
         deque <ListNode*> dq;
        ListNode* cur =head;
        while(cur){
            dq.push_back(cur);
            cur=cur->next;
        }
        if(dq.size()==1 || dq.size()==2) return;
        bool f=0;
        ListNode*node = NULL;
        while(dq.size()>1){
             ListNode* first =dq.front();
            dq.pop_front();
          if(f==0){
              head= first;
                  f=1;
          }  
            else{
                node->next=first;
            }
         
            node= dq.back();
            dq.pop_back();
            first->next=node;
        }
        if(dq.size()==1){
            ListNode* temp = dq.front();
            node->next = temp;
            dq.pop_back();
            temp->next=NULL;
        }
        else
        node->next=NULL;

        return ;
    }
};