
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
    public:
        ListNode* EntryNodeOfLoop(ListNode* pHead) {
            ListNode* slow = pHead, *fast = pHead;
            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
                if(slow == fast) break;
            }
            if(fast == nullptr || fast->next == nullptr) return nullptr;
    
            fast = pHead;
            while (slow != fast) {
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }
    };