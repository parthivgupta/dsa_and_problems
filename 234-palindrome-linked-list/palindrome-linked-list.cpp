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
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        stack<int>st;

        while(temp != NULL ) {
            st.push(temp -> val);
            temp = temp -> next;
        }
        // comparison while popping out from stack
        while(head != NULL) {
            int t = st.top();
            st.pop();

            if(head -> val != t) return false;
            head = head -> next;
        }
        return true;
    }
};