Given two strings, head1 and head2, represented as linked lists where each character is stored in a node's data field, complete the function compare() that mimics the behavior of strcmp(). Specifically, the function should return:
0 if both strings are identical,
1 if the first linked list is lexicographically greater, and
-1 if the second linked list is lexicographically greater.
 

/* Linked list Node structure
struct Node
{
    char c;
    struct Node *next;
    
    Node(char x){
        c = x;
        next = NULL;
    }
    
};
*/

// Compare two strings represented as linked lists
int compare(Node *list1, Node *list2) 
{
     
     while(list1!=NULL && list2!=NULL)
     {
         if(list1->c>list2->c)
         {
         return 1;
         }
         else if(list1->c<list2->c)
         {
         return -1;
         }
         else if(list1->c==list2->c)
         {
             
         }
         list1=list1->next;
         list2=list2->next;
     }
     return 0;
} 
