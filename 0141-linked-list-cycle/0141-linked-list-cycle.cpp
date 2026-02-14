class Solution {
public:
    bool hasCycle(ListNode *head) {

        // slow pointer moves 1 step at a time
        ListNode* slow = head;

        // fast pointer moves 2 steps at a time
        ListNode* fast = head;

        // Traverse list until fast reaches end
        // fast != NULL → fast pointer valid hona chahiye
        // fast->next != NULL → fast ko 2 step move karne ke liye next valid hona chahiye
        while(fast != NULL && fast->next != NULL){

            // move slow pointer by 1 step
            slow = slow->next;

            // move fast pointer by 2 steps
            fast = fast->next->next;

            // If slow and fast meet at same node,
            // cycle exists
            if(slow == fast)
                return true;
        }

        // If fast reaches NULL, no cycle exists
        return false;
    }
};
