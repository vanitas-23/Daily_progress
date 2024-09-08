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
        
        vector<ListNode*>res(k);
        if(head==nullptr)
        return res;
        ListNode* temp=head;
        int n=0;
        while(temp!=nullptr)
        {
            n++;
            temp=temp->next;
        }

        int ele=n/k;
        int ext=n%k;
        
         ListNode* node = head, *prev = nullptr;
        for(int i=0;i<k;i++){
            res[i]=node;
            for(int j=0;j< ele + (ext>0);j++ ){
                prev=node;
                node=node->next;
            }
            prev->next=nullptr;

            ext--;
        }
        return res;
    }
};