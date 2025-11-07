#include <iostream>
using namespace std;

//定义链表节点
struct ListNode
{
int val;//值
ListNode* next;//指向下一个节点的指针
listNode(int x):val(x),next(nullptr) {}//构造函数初始化
};

//定义链表类
class LinkedList{
public:
listNode* head;//链表的头节点
LinkedList():head(nullptr);//构造函数初始化

//遍历链表
void traverse()
{
  ListNode* current = head;
  while(current!=nullptr)
    {
      cout<<current->val<<"->";
      current = current->next;
    }
  cout<<"NULL"<<endl;
}

//在链表指定位置插入新节点
void insert(int position,int value)
{
  ListNode* newNode = new ListNode(value);
  if(position==0)
  {
    //在头部插入
    newNode->next=head;
    head=newNode;
  }
  else 
  {
    ListNode* temp=head;
    for(int i=0;temp!=nullptr&&i<position-1;i++)
      {
        temp=temp->next;
      }
    if(temp!=nullptr)
    {
      newNode->next=temp->nexp;
      temp->next=newNode;
    }
  }
}

//从链表中删除指定位置节点
void remove(int position)
{
  if(head==nullptr)  return //空链表，直接返回
    ListNode* temp=head;
  if(position==0)
  {
    head=temp->next;
    delete temp;
  }
  else
  {
    for(int i=0;temp!=nullptr&&i<position-1;i++)
      {
        temp=temp->next;
      }
    if(temp==nullptr||temp-next==nullptr) return;
    ListNode* next=temp->next->next;
    delete temp->next;
    temp->next=next;
  }
}
};

int main()
{
  LinkedList list;
  //插入节点
  list.insert(0,1);
  list.insert(1,2);
  list.insert(2,3);
  cout<<"After insertion:";
  list.traverse();
  //删除节点
  list.remove(1);
  cout<<"Afer deletion:";
  list.traverse();
  return 0;
  
}
