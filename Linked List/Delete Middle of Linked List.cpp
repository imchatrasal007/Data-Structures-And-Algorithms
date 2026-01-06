Given a singly linked list, delete the middle of the linked list.
Note:
If there are even nodes, then there would be two middle nodes, we need to delete the second middle element.
If the input linked list has a single node, then it should return NULL.


/* Link list Node:

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

// Deletes middle of linked list and returns head of the modified list
Node* deleteMid(Node* head)
{
   struct Node *temp,*curr,*nextnode,*prev,*after;
   int i,j,mid,count;
   i=1;
   j=1;
   count=0;
   if(head==NULL || head->next==NULL)
   {
   return NULL;
   }
   temp=head;
   while(temp!=0)
   {
       count++;
       temp=temp->next;
   }
   mid=(i+count)/2;
   if(count%2!=0)
   {
   curr=head;
   while(j<mid-1)
   {
       curr=curr->next;
       j++;
   }
   nextnode=curr->next;
   curr->next=nextnode->next;
   delete nextnode;
   }
   else 
   {
      prev=head;
      while(j<mid)
      {
          prev=prev->next;
          j++;
      }
      after=prev->next;
      prev->next=after->next;
      delete after;
    }
    return head;
    
  
   
}
