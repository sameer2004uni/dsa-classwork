
class Solution {
public:
  
    ListNode* sortList(ListNode* head) {
        // Base case: empty list or single node
        if (!head || !head->next) {
            return head;
        }
    
        ListNode* slowPtr = head;
        ListNode* fastPtr = head->next; 
      
        while (fastPtr && fastPtr->next) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
      
        // Split the list into two halves
        ListNode* firstHalf = head;
        ListNode* secondHalf = slowPtr->next;
        slowPtr->next = nullptr;  // Disconnect the two halves
      
        // Recursively sort both halves
        firstHalf = sortList(firstHalf);
        secondHalf = sortList(secondHalf);
      
        // Merge the two sorted halves
        ListNode* dummyHead = new ListNode(0);  // Dummy node to simplify merging
        ListNode* currentTail = dummyHead;
      
        // Merge nodes from both lists in sorted order
        while (firstHalf && secondHalf) {
            if (firstHalf->val <= secondHalf->val) {
                currentTail->next = firstHalf;
                firstHalf = firstHalf->next;
            } else {
                currentTail->next = secondHalf;
                secondHalf = secondHalf->next;
            }
            currentTail = currentTail->next;
        }
      
        // Append remaining nodes from either list
        currentTail->next = firstHalf ? firstHalf : secondHalf;
      
        // Return the merged sorted list (skip dummy head)
        ListNode* sortedHead = dummyHead->next;
        delete dummyHead;  // Clean up dummy node
        return sortedHead;
    }
};
