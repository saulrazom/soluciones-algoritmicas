class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head->next)
            return true;
            
        stack<int> s;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            s.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast)
            slow = slow->next;
        while (slow) {
            if (s.top() != slow->val)
                return false;
            s.pop();
            slow = slow->next;
        }
        return true;
    }
};