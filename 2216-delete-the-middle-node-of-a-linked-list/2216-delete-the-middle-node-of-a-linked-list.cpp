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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* sl=head;
        ListNode* f=head;
        ListNode* p=NULL;
        while(f){
            f=f->next;
            if(f) f=f->next;
            else break;
            p=sl;
            sl=sl->next;
        }
        if(p){
            p->next=sl->next;
            sl->next=NULL;
            delete sl;
        }
        else return head->next;
        return head;

    }
};