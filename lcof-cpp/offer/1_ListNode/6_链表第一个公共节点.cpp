class Solution
{
public:
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        ListNode *head1 = pHead1;
        ListNode *head2 = pHead2;
        // 两个指针，同样的速度，走完同样长度 不管两条链表有无相同节点
        while (head1 != head2)
        {
            head1 = (head1 == nullptr) ? pHead2 : head1->next;
            head2 = (head2 == nullptr) ? pHead1 : head2->next;
        }
        return head1;
    }
};

#include <set>
class Solution
{
public:
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        if (pHead1 == nullptr || pHead2 == nullptr)
            return nullptr;
        set<ListNode *> s;
        while (pHead1)
        {
            s.insert(pHead1);
            pHead1 = pHead1->next;
        }
        while (pHead2)
        {
            if (s.find(pHead2) != s.end())
                return pHead2;
            pHead2 = pHead2->next;
        }
        return nullptr;
    }
};

// 第二种
