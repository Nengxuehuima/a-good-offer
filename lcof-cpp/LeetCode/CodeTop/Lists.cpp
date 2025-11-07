//单向链表：每个节点只有指向下一个节点的指针
//双向链表：每个节点有指向前一个节点和后一个节点的指针
//循环链表：链表的最后一个节点指向头节点，形成环。
//面试中常询问数组与链表的区别，即C++中的vector与list。
//链表支持分散存储，且链表大小可动态调整。数组需要连续的内存空间，且大小固定(vector是动态数组)
//数组支持随机访问，而链表的访问需要从头开始遍历；数组的插入删除操作需要移动大量元素，而链表插入删除只需修改指针

单向链表
struct ListNode
{
int data;//数据域
struct ListNode* next;//指针域，指向下一个节点
}；
//创建单项链表节点的示例函数
struct ListNode* createNode(int data)
{
  struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
  if(newNode==NULL)
  {
    exit(-1);//内存分配失败
  }
  newNode->data=data;
  newNode->next=NULL;
  return newNode;
}

双向链表
struct DoubleListNode
{
int data;
struct DoubleListNode* pre;//前一个节点指针
struct DoubleListNode* next;//后一个节点指针
};
创建双链表节点示例函数
struct DoubleListNode* createDoubleListNode(int data)
{
  struct DoubleListNode* newNode=(struct DoubleListNode*)malloc(sizeof(struct DoubleListNode));
  if(nwNode==NULL)
    exit(-1);
  newNode->data=data;
  newNode->pre=NULL;
  newNode->next=NULL;
  return newNode;
}

循环链表
struct CircularListNode
{
int data;
struct CircularListNode* next;
};

创建循环链表节点示例函数
struct CircularListNode* creatCircularListNode(int data)
{
  struct CirculatListNode* newNode=(struct CircularListNode*)malloc(sizeof(struct CircularNode));
  if(newNode==NULL)
    exit(-1);
  newNode->data=data;
  newNode->next=newNode;//初始化，自己指向自己形成环
}
