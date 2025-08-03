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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int p=n;
        ListNode* s=head;
        while(p>1){
         s=s->next;
         p--;
        }

        ListNode* pr=NULL;
        ListNode* curr=head;
        while(s->next!=NULL){
            pr=curr;
            curr=curr->next;
            s=s->next;
        }
        if(pr!=NULL){
            pr->next=curr->next;
            curr->next=NULL;

        }
        else
        return curr->next;
        return head;

    }
};