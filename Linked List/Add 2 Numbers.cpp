You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummyhead=new ListNode(-1);
        ListNode *curr=dummyhead;
        ListNode *temp1=l1;
        ListNode *temp2=l2;
        int carry=0;
        while(temp1!=NULL || temp2!=NULL){
          int sum=carry;
          if(temp1) sum+=temp1->val;
          if(temp2) sum+=temp2->val;
          ListNode *Newnode=new ListNode(sum%10);
          carry=sum/10;
          curr->next=Newnode;
          curr=Newnode;
          if(temp1) temp1=temp1->next;
          if(temp2) temp2=temp2->next;
        }
        if(carry){
          ListNode *Newnode=new ListNode(carry);
          curr->next=Newnode;
        }
        return dummyhead->next;

    }
};
