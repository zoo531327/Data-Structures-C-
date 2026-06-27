#include<stdio.h>
#include<stdlib.h>
typedef int elemtype;

typedef struct node{
    elemtype data;
    struct node *next;
}Node;

//初始化链表
Node *initlist(){
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}

//头插法
int inserthead(Node *L,elemtype e){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->next = L->next;
    L->next = p;
    return 1;
}

//遍历
void listnode(Node *L){
    Node *p = L->next;
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
    Node *list = initlist();
    inserthead(list,10);
    inserthead(list,20);
    inserthead(list,30);
    listnode(list);
    return 0;
}