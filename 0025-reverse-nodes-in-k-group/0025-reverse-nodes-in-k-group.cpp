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
ListNode* root;
ListNode* rev(ListNode* head,int k){
 if (!head || k == 1) return head;

        // Check if there are at least k nodes
        ListNode* check = head;
        for (int i = 0; i < k; ++i) {
            if (!check) return head;
            check = check->next;
        }

        // Reverse k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        int count = 0;

        while (curr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Recursively reverse the rest of the list
        if (next)
            head->next = reverseKGroup(next, k);

        return prev; // new head of the reversed group
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
      return rev(head,k);  
    }
};