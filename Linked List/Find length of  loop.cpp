Given the head of a linked list, determine whether the list contains a loop. If a loop is present, return the number of nodes in the loop, otherwise return 0.


/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

//Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head)
{
    struct Node *fast,*slow;
    fast=slow=head;
    int count=0;
    while(fast!=0 && fast->next!=0)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow)
        {
            slow=slow->next;
            fast->next=0;
            while(slow!=0)
            {
             slow=slow->next;
             count++;
             }
            return count;
        }
    }
    return 0;
    
}
