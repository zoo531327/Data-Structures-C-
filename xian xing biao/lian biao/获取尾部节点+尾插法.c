#include<stdio.h>
#include<stdlib.h>
typedef int elemtype;

//定义顺序表
typedef struct node{
    elemtype data;
    struct node *next;
}Node;

//初始化
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

//获取尾部结点
Node *get_tail(Node *L){
    Node *p = L;
    while(p->next != NULL){
        p = p->next;
    }
    return p;
}

//尾插法
Node *inserttail(Node *tail, elemtype e){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    tail->next = p;
    p->next = NULL;
    return p;
}

//主函数
int main(){
    Node *list = initlist();
    Node *tail = get_tail(list);
    tail = inserttail(tail,10);
    tail = inserttail(tail,20);
    tail = inserttail(tail,30);
    listnode(list);
    return 0;
}
