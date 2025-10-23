#include <iostream>
using namespace std;

// 定义链表节点结构
struct Node {
    int data;       // 节点存储的数据
    Node* next;     // 指向下一个节点的指针
    // 构造函数，方便创建节点
    Node(int val) : data(val), next(nullptr) {}
};

// 链表反转函数（核心）：传入头节点，返回反转后的新头节点
Node* reverseLinkedList(Node* head) {
    Node* prev = nullptr;  // 记录前一个节点，初始为null（反转后最后一个节点指向null）
    Node* curr = head;     // 当前遍历的节点，从原头节点开始
    Node* nextTemp = nullptr;  // 临时保存下一个节点，避免反转时断链

    while (curr != nullptr) {
        nextTemp = curr->next;  // 1. 先保存当前节点的下一个节点
        curr->next = prev;      // 2. 反转当前节点的指向（指向之前的节点）
        prev = curr;            // 3. prev向后移动，指向当前节点
        curr = nextTemp;        // 4. curr向后移动，处理下一个节点
    }
    return prev;  // 循环结束后，prev就是新的头节点
}

// 辅助函数：打印链表（验证结果）
void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "nullptr" << endl;
}

// 主函数：测试逻辑
int main() {
    // 1. 创建一个示例链表：1 -> 2 -> 3 -> 4 -> nullptr
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "原链表：";
    printList(head);

    // 2. 反转链表
    head = reverseLinkedList(head);

    cout << "反转后：";
    printList(head);

    // 3. 释放内存（避免内存泄漏，养成好习惯）
    Node* temp = nullptr;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
