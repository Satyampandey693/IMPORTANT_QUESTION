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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p=headA;
        ListNode* q=headB;
        int c=0;
        
        while(p!=q){
            p=p->next;
            q=q->next;
            if(p==NULL){p=headB;c++;}
            if(q==NULL) {q=headA;c++;}
             if(c>2) return NULL;
        }
       
        return p;
    }
};