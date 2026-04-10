You are given the head of a singly linked list of positive integers. You have to check if the given linked list is palindrome or not.

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

class Solution {
  public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        Node*slow=head;
        stack<int> s;
        while(slow!=NULL){
            s.push(slow->data);
            slow=slow->next;
        }
        while(head!=NULL){
            int i=s.top();
            s.pop();
            if(head->data!=i){
                return false;
            }
            head=head->next;
        }
        return true;
        
    }
};
