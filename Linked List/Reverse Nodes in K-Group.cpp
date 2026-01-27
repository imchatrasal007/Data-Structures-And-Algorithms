Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.
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
   int lengthOfLinkedList(ListNode *head){
     int length=0;
     ListNode*temp=head;
     while(temp!=NULL){
      temp=temp->next;
      length++;
     }
     return length;
   }
    ListNode* reverseKGroup(ListNode* head, int k) {
      if(head==NULL){
        return NULL;
      }
      int count=0;
       ListNode *prevnode;
       ListNode *currentnode;
       ListNode *nextnode;
       prevnode=0;
       currentnode=nextnode=head;
       while(nextnode!=0 && count<k){
         nextnode=nextnode->next;
         currentnode->next=prevnode;
         prevnode=currentnode;
         currentnode=nextnode;
         count++;
       }
       if(nextnode!=0){
         if(lengthOfLinkedList(nextnode)>=k)
         {
         head->next=reverseKGroup(nextnode,k);
         }
        else{
          head->next=nextnode;
          return prevnode;
        }
       }
       return prevnode;
    }
};
