You are given the head of a singly linked list. You have to reverse the linked list and return the head of the reversed list.
  
/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution {
  public:
    Node* reverseList(struct Node* head) {
        Node*prev=NULL;
        Node*current=head;
        Node*forward=NULL;
        while(current!=NULL){
            forward=current->next;
            current->next=prev;
            prev=current;
            current=forward;
        }
        return prev;
    }
};
