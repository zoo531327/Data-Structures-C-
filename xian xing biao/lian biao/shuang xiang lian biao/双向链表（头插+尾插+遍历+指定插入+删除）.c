#include<stdio.h>
#include<stdlib.h>
typedef int elemtype;

typedef struct node{
    elemtype data;
    struct node *next,*prev;
}Node;

//初始化链表
Node *initlist(){
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    head->prev = NULL;
    return head;
}

//头插法
int inserthead(Node *L, elemtype e){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->prev = L;
    p->next = L->next;
    if(L->next != NULL){
        L->next->prev = p;
    }
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

//获取尾部节点
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
    p->prev = tail;
    tail->next = p;
    p->next = NULL;
    return p;
}

//指定位置插入
int insertnode(Node *L,int pos,elemtype e){
    Node *p = L;
    int i = 0;
    while(i < pos-1){
        p = p->next;
        i++;
        if(p == NULL){
            return 0;
        }
    }

    Node *q = (Node*)malloc(sizeof(Node));
    q->data = e;
    q->prev = p;
    q->next = p->next;
    p->next->prev = q;
    p->next = q;
    return 1;
}

//删除节点
int deletenode(Node *L, int pos){
    Node *p = L;
    int i= 0;
    while(i < pos-1){
        p = p->next;
        i++;
        if(p == NULL){
            return 0;
        }
    }
    if(p->next == NULL){
        printf("要删除的位置错误\n");
        return 0;
    }

    Node *q = p->next;
    p->next = q->next;
    q->next->prev = p;
    free(q);
    return 1;
}

//释放链表
void freelist(Node *L){
    Node *p = L->next;
    Node *q;

    while(p != NULL){
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
}

int main(){
    Node *list = initlist();

    //头插
    /* inserthead(list,10);
    inserthead(list,20);
    inserthead(list,30);
    listnode(list); */

    
    //尾插
    Node *tail = get_tail(list);
    tail = inserttail(tail,10);
    tail = inserttail(tail,20);
    tail = inserttail(tail,30);
    listnode(list);

    //指定插入
    insertnode(list,2,15);
    listnode(list);

    //删除
    deletenode(list,2);
    listnode(list);
}