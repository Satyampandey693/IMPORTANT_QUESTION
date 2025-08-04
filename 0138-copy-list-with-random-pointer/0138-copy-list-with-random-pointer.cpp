/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node* head2=new Node(head->val);
        Node* p2=head2;
        Node* p1=head->next;
        while(p1!=NULL){
            Node* nn=new Node(p1->val);
            p2->next=nn;
            p2=nn;
            p1=p1->next;
        }
        p2=head2;
        p1=head;
        while(p1!=NULL){
            Node* nx=p1->next;
            p1->next=p2;
            Node* nx2=p2->next;
            p2->next=nx;
            p1=nx;
            p2=nx2;
        }
        //assigning random pointer
         p2=head2;
        p1=head;
        while(p2!=NULL){
            if(p1->random!=NULL)
            p2->random=p1->random->next;
            
            // p1=p1->next;
            // p1->next=p2->next;
            p1=p1->next;
            if(p1==NULL) break;
            p1=p1->next;
            // p2->next=p1->next;
            p2=p2->next;
            if(p2==NULL) break;
            p2=p2->next;
        }
        // return head2;
         p2=head2;
        p1=head;
        //change
         while(p2!=NULL){
            // if(p1->random!=NULL)
            // p2->random=p1->random->next;
            
            // p1=p1->next;
            p1->next=p2->next;
            p1=p1->next;
            if(p1==NULL) break;
            // p1=p1->next;
            p2->next=p1->next;
            p2=p2->next;
            if(p2==NULL) break;
            // p2=p2->next;
        }
        return head2;



    }
};