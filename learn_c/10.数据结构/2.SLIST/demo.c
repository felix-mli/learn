#include <sys/queue.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_LENTH 1024

typedef struct keyValue{
    char *key;
    char *value;
} kv;

// 定义一个节点
struct node{
    kv data; // 节点数据
    // 匿名结构体，nodes是匿名结构体的变量
    SLIST_ENTRY(node) nodes;
};
// 定义链表头
SLIST_HEAD(slist_head, node);

char g_keyList[MAX_LENTH][32] = {"name", "age", "city"};
char g_valueList[MAX_LENTH][32] = {"Alice", "30", "New York", "Bob", "25", "Los Angeles", "Charlie", "35", "Chicago"};

// 写一个函数去创建节点
struct node* createNode(const char *key, const char *value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    newNode->data.key = (char *)key; // 注意这里需要确保key和value的生命周期
    newNode->data.value = (char *)value; // 同上
    return newNode;
}

// 获取二位数组真实的长度s
static size_t getArrLen() {
    size_t count = 0;
    for (size_t i = 0; i < MAX_LENTH; i++) {
        if (g_valueList[i][0] == '\0') { // 遇到空字符串时停止
            break;
        }
        count++;
    }
    return count;
}

int main(int argc, char* argv[]) {
    struct slist_head head;
    SLIST_INIT(&head); // 初始化链表头

    for (size_t i = 0; i < getArrLen() / 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            struct node *node1 = createNode(g_keyList[j], g_valueList[i * 3 + j]);
            if (node1 == NULL) {
                fprintf(stderr, "Failed to create node\n");
                return 1;
            }
            SLIST_INSERT_HEAD(&head, node1, nodes); // 将节点插入到链表头
        }
    }
    

    char str[MAX_LENTH] = {0};
    struct node *temp;
    int offset = 0;
    int len = 0;
    SLIST_FOREACH(temp, &head, nodes) {
        printf("Key: %s, Value: %s\n", temp->data.key, temp->data.value);
        len = snprintf(str + offset, MAX_LENTH - offset, "%s:%s,", temp->data.key, temp->data.value);
        if (len < 0 || len > MAX_LENTH - offset) {
            break;
        }
        offset += len;
    }

    printf("str = %s\n", str);

    // 移除头结点
    // SLIST_REMOVE_HEAD(&head, nodes); // 移除链表头节点
    // SLIST_FOREACH(temp, &head, nodes) {
    //     printf("Key: %s, Value: %s\n", temp->data.key, temp->data.value);
    // }

    // 移除指定节点
    struct node *prev = NULL;
    struct node *curr = SLIST_FIRST(&head);

    while (curr != NULL) {
        if (curr->data.key && strcmp(curr->data.key, "city") == 0) {
            struct node *to_delete = curr;
            if (prev) {
                curr = SLIST_NEXT(curr, nodes);
                // 替代 SLIST_REMOVE_AFTER(prev, nodes);
                prev->nodes.sle_next = curr ? curr->nodes.sle_next : NULL;
                free(to_delete);
            } else {
                curr = SLIST_NEXT(curr, nodes);
                SLIST_REMOVE_HEAD(&head, nodes);
                free(to_delete);
            }
        } else {
            prev = curr;
            curr = SLIST_NEXT(curr, nodes);
        }
    }

    memset(str, 0, sizeof(str)); // 清空字符串
    offset = 0;
    len = 0;
    SLIST_FOREACH(temp, &head, nodes) {
        printf("Key: %s, Value: %s\n", temp->data.key, temp->data.value);
        len = snprintf(str + offset, MAX_LENTH - offset, "%s:%s,", temp->data.key, temp->data.value);
        if (len < 0 || len > MAX_LENTH - offset) {
            break;
        }
        offset += len;
    }

    printf("str = %s\n", str);

    // 释放链表
    struct node *current;
    while (!SLIST_EMPTY(&head)) {
        current = SLIST_FIRST(&head); // 获取链表头节点
        SLIST_REMOVE_HEAD(&head, nodes); // 移除链表头节点
        free(current); // 释放节点内存
    }
    
    return 0;
}