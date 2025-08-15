#include <stdio.h>
#include <stdlib.h>

/*
    链表：
        单链表
        双链表
    操作：
        创建连接
        插入节点
            从头结点插入
            从尾结点插入
            从指定位置插入
        删除节点
            删除头结点
            删除尾结点
            删除指定位置节点
        查找节点
            查找头结点
            查找尾结点
            查找指定位置节点
        遍历链表
            正向遍历
            逆向遍历
        释放链表
*/

typedef struct Node {
    int data;
    struct Node *next;
} Node;

/*
    创建节点
        返回值为Node
        参数为int类型的data
        需要使用malloc创建节点
*/
Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/*
    释放链表
        需要遍历链表，释放每个节点
        使用while循环遍历链表
*/
void freeList(Node *head) {
    Node *current = head;
    Node *nextNode;
    
    while (current != NULL) {
        nextNode = current->next; // 保存下一个节点
        free(current); // 释放当前节点
        current = nextNode; // 移动到下一个节点
    }
}

/*
    正向遍历链表
        使用while(p->next != NULL)进行遍历
*/
void printList(Node *head) {
    while(head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main(int argc, char *argv[]) {
    // 创建一个有头结点的链表
    Node *head = createNode(0); // 头结点的data可以是任意值，这里设为0
    head->next = createNode(1); // 插入第一个数据节点
    head->next->next = createNode(2); // 插入第二个数据节点
    
    printList(head);

    freeList(head); // 释放链表
    head = NULL; // 避免悬空指针

    return 0;
}



