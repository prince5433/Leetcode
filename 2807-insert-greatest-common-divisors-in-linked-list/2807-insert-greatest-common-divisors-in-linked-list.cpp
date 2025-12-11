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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {

        // Pointer to traverse the list
        ListNode* temp = head;

        // Loop until there are at least two nodes to form a pair
        while (temp && temp->next) {

            // Calculate gcd of current node value and next node value
            int g = __gcd(temp->val, temp->next->val);

            // Create a new node to store this gcd
            ListNode* newNode = new ListNode(g);

            // Insert the new node between temp and temp->next
            newNode->next = temp->next;  // new node points to next node
            temp->next = newNode;        // current node points to new node

            // Move to the node after the inserted gcd node
            temp = newNode->next;
        }

        // Head doesn't change, so return original head
        return head;
    }
};
