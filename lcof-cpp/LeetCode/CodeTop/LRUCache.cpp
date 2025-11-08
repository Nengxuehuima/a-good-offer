#include <iostream>
#include <unordered_map>
using namespace std;

struct DLinkNode
{
  int key , val;
  DLinkNode* pre;
  DLinkNode* next;
  DLinkNode():key(0) , val(0) , pre(nullptr) , next(nullptr) {}
  DLinkNode(int _key,int _val):key(_key) , val(_val) , pre(nullptr) , next(nullptr){}
};


class LRUCache
{
private:
  unordered_map<int,DLinkNode*> cache;
  DLinkNode* head , * tail;//head 和 tail 是虚拟头节点和尾节点，它们不存储数据，只是为了简化链表操作。
  int size;
  int capacity;
  
  void addNode(DLinkNode* node)//添加到头节点
  {
    node->pre=head;//设置新节点 node 的 prev 指向 head。
    node->next=head->next;//设置新节点 node 的 next 指向原来 head 后面的第一个节点。
    head->next->pre=node;//更新原来第一个节点的 prev 指向 node。如果不更新，原来第一个节点的pre还指向原来的head
    head->next=node;//更新 head 的 next 指向新节点 node。
  }
  
  void removeNode(DLinkNode* node)//删除节点
  {
    DLinkNode* pre=node->pre;
    DlinkNode* next=node->next;
    pre->next=next;//pre的下一个节点原本应该是node，但是node被删除，因此pre的下一个节点为node的下一个节点
    next->pre=pre;
  }
  
  void moveToHead(DLinkNode* node)//移动到头节点
  {
    removeNode(node);
    addNode(node);
  }
  
  DLinkNode* popTial()//删除尾节点
  {
    DLinkNode* res = tail->pre;
    removeNode(res);
    return res;
  }

public:
  LRUCahce(int capacity):capacity(capacity),size(0);
  {
    head=new DLinkNode();
    tail=new DLinkNode();
    head->next=tail;
    tail->pre=head;
  }
  
  int get(int key)
  {
    if(cache.find(key)==cache.end())  return -1;
    DLinkNode* node=cache[key];
    moveToHead(node);
    return node->val;
  }
  
  void put(int key,int value)
  {
    if(cahce.find(key)==cache.end())
    {
      DLinkNode* newNode=new DLinkNode(key,value);
      cache[key]=newNode;
      addNode(newNode);
      ++size;
      if(size>capacity)
      {
        DLinkNode* tail=popTail();
        cache.erase(tail->key);
        delete tail;
        --size;
      }
      else
      {
        DLinkNode* node=cache[key];
        node->value=value;
        moveToHead(node);
      }
    }
  }
};
int main()
{
   LRUCache cache(2); // capacity

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // 返回 1
    cache.put(3, 3);    // 逐出键 2
    cout << cache.get(2) << endl; // 返回 -1 (未找到)
    cache.put(4, 4);    // 逐出键 1
    cout << cache.get(1) << endl; // 返回 -1 (未找到)
    cout << cache.get(3) << endl; // 返回 3
    cout << cache.get(4) << endl; // 返回 4

}
