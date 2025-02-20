/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @param m int整型
     * @param n int整型
     * @return ListNode类
     */
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        // 虚拟头部
        auto dummyHead = new ListNode(-1);
        dummyHead->next = head;
        auto pre = dummyHead;
        for (int i = 0; i < m - 1; i++)
            pre = pre->next;
        // 本质上只有3个变量3次动作， 并且中间反转后就已经有序了
        ListNode *cur = pre->next;
        ListNode *cur_next = nullptr;
        // n-m差多少 就需要交换 n-m次 1 2 <--1次--> 3 <--1次--> 4 5
        // cur 永远是要修改的那个 也就是最后一个
        for (int i = 0; i < n - m; i++)
        {
            // cur->next记住了 所以下一个修改cur->next
            cur_next = cur->next;
            cur->next = cur_next->next;
            cur_next->next = pre->next; // 类似于插队 插队插到前面去 因为cur永远是cur_next前一个 但不是pre->next,pre是不变的
            pre->next = cur_next;       // 更新 新的插队人员
        }
        return dummyHead->next;
    }
};