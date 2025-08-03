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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        
        ListNode* tail=head;
        int c=1;
        while(tail->next!=NULL){
            tail=tail->next;
            c++;

        }
        k=k%c;
        int p=k;
        if(k==0) return head;
        ListNode* s=head;
        while(p>1){
         s=s->next;
         p--;
        }
        // p=k;

        ListNode* pr=NULL;
        ListNode* curr=head;
        while(s->next!=NULL){
            pr=curr;
            curr=curr->next;
            s=s->next;
        }
    //    else{
    //     return head;
    //    }
    // if(pr==NULL) 
    if(tail==head) return head;
        tail->next=head;
        if(pr!=NULL)
        pr->next=NULL;
        return curr;

        
    }
};