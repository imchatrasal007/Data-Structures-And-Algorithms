You are given the head of a linked list, You have to return the value of the middle node of the linked list.
If the number of nodes is odd, return the middle node value.
If the number of nodes is even, there are two middle nodes, so return the second middle node value.
/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */
class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        struct Node *temp,*curr,*prev;
        int count,i,j,mid;
        count=0;
        i=1;
        j=1;
        temp=head;
        while(temp!=0)
        {
            count++;
            temp=temp->next;
        }
        mid=(i+count)/2;
        curr=head;
        while(j<mid)
        {
            curr=curr->next;
            j++;
        }
        if(count%2==0)
        {
        prev=curr->next;
        return (prev->data);
        }
        else if(count%2!=0)
        {
        return (curr->data);
        }
        return -1;
}
};
