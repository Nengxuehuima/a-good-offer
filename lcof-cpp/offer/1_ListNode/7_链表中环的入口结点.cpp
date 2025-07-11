
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
        class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next||!head->next->next) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                fast = head;
                break;
            }
        }
        if(fast != head) return nullptr;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
    };