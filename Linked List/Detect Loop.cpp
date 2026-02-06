You are given the head of a singly linked list. You have to determine whether the given linked list contains a loop or not. A loop exists in a linked list if the next pointer of the last node points to any other node in the list (including itself), rather than being null
//User function template for C++

/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
    public:
    bool detectLoop(Node* head)
    {
        struct Node *prevnode,*nextnode;
        prevnode=nextnode=head;
        while(nextnode!=0 && nextnode->next!=0)
        {
            nextnode=nextnode->next->next;
            prevnode=prevnode->next;
            if(nextnode==prevnode)
            return true;
        }
        return false;
    }
};
