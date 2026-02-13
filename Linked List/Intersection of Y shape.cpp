Given two singly linked lists, write a program to get the point where two linked lists intersect each other. If the linked list does not merge at any point, it should return NULL.
/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution
{
public:
    int intersectPoint(Node* head1, Node* head2)
    {
            struct Node *temp1,*temp2;
        temp1=head1;
        temp2=head2;
        if(head1==NULL || head2==NULL)
        {
            return NULL;
        }
        while(temp1!=temp2)
        {
            if(temp1==NULL)
            {
            temp1=head2;
            }
            if(temp2==NULL)
            {
            temp2=head1;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return (temp1->data);
    }
};

