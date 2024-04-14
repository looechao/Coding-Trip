#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

// 删除节点函数
void deleteNode(Node*& head, int value) {
    if(head == nullptr) {
        return;
    }
    if(head->data == value) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }
    Node* current = head;
    while(current->next != nullptr && current->next->data != value) {
        current = current->next;
    }
    if(current->next != nullptr) {
        Node* toDelete = current->next;
        current->next = current->next->next;
        delete toDelete;
    }
}

// 主函数
int main() {
    // 创建链表
    Node* head = new Node;
    head->data = 1;
    head->next = new Node;
    head->next->data = 2;
    head->next->next = new Node;
    head->next->next->data = 3;
    head->next->next->next = nullptr;

    // 删除值为2的节点
    deleteNode(head, 2);

    // 打印链表
    Node* current = head;
    while(current != nullptr) {
        cout << current->data << ' ';
        current = current->next;
    }

    return 0;
}
