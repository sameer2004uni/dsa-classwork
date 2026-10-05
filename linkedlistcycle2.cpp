/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode* detectCycle(ListNode* head) {
        
        ListNode* fastPointer = head;
        ListNode* slowPointer = head;
      
        while (fastPointer != nullptr && fastPointer->next != nullptr) {
         
            slowPointer = slowPointer->next;
  
            fastPointer = fastPointer->next->next;
          
            if (slowPointer == fastPointer) {
                ListNode* startPointer = head;
         
                while (startPointer != slowPointer) {
                    startPointer = startPointer->next;
                    slowPointer = slowPointer->next;
                }

                return startPointer;
            }
        }
      
        // No cycle detected
        return nullptr;
    }
};
