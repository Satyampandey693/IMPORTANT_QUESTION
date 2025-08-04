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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        else if(list2==NULL) return list1;
        if(list1->val>list2->val){
           ListNode* p=list1;
            list1=list2;
            list2=p;
        }
        ListNode* cur1=list1;
        ListNode* cur2=list2;
        // while(cur1!=NULL){

        // }
        ListNode* prev=cur1;
        ListNode* pr=NULL;
        while(cur2!=NULL&&cur1!=NULL){
            
            while(cur1!=NULL&&cur1->val<=cur2->val){
                pr=cur1;
                cur1=cur1->next;
                // cur2=cur2->next;

            }

            pr->next=cur2;
            ListNode* nx=cur2->next;
            cur2->next=cur1;
            cur1=cur2;
            prev=cur2;
            cur2=nx;

        }
        if(cur2!=NULL){
             prev->next=cur2;
        }
        return list1;
    }
};