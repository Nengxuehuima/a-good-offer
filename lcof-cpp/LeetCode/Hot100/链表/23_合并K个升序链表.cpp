最小堆 / 优先队列（推荐）
利用 最小堆（priority_queue） 每次取当前最小节点。
思路：
  1、把每个链表的头节点放入最小堆；
  2、每次弹出堆顶最小节点，接入结果链表；
  3、把被弹出节点的下一个节点入堆；
  4、直到堆为空。


#include <bits/stdc++.h>
using namespace std;

//
// 链表定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//比较器，用于优先队列
struct cmp{
  bool operator()(ListNode* a,ListNode* b){
    return a->val > b->val;//小项堆(值小的优先)
  }
};

class Solution{
public:
ListNode* mergeKLists(vector<ListNode*>& lists){
  priority_queue<ListNode*,vector<ListNode*>,cmp> pq;

  //把每个链表的头节点放进堆
  for(auto node : lists){
    if(node)  pq.push(node);
  }

  ListNode dummy(0);
  ListNode* tail = &dummy;

  //每次取出堆顶最小节点
  while(!pq.empty()){
    ListNode* cur = pq.top(); //访问堆顶元素（即当前最小的节点），pq.top() 返回指向最小的节点的指针并保存到变量 cur 里
    pq.pop();//弹出堆顶元素，即删除堆中当前最小的那个节点。
    tail->next = cur;
    tail = tail->next;

    //如果还有下一个节点，继续入堆
    if(cur->next)  pq.push(cur->next);
  }
  return dummy.next;
}
};
