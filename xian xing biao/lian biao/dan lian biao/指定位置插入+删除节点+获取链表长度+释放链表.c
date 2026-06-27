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

//指定位置插入
int insertnode(Node *L,int pos,elemtype e){
    //用来保存插入位置的前驱节点
    Node *p = L;
    int i = 0;
    //遍历链表找到插入位置的前驱节点
    while(i < pos-1){
        p = p->next;
        i++;
        if(p == NULL){
            return 0;
        }
    }

    //要插入的新结点
    Node *q = (Node*)malloc(sizeof(Node));
    q->data = e;
    q->next = p->next;
    p->next = q;
    return 1;
}

//删除节点
int deletenode(Node *L,int pos){
    //要删除结点的前驱
    Node *p = L;
    int i = 0;
    //遍历链表，找到要删除节点的前驱
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

    //q指向要删除的节点
    Node *q = p->next;
    //让要删除节点的前驱指向要删除节点的后继
    p->next = q->next;
    //释放要删除节点的内存空间
    free(q);
    return 1;
}

//获取链表长度
int listlength(Node *L){
    Node *p = L;
    int len = 0;
    while(p != NULL){
        p = p->next;
        len++;
    }
    return len;
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

//主函数
int main(){
    Node *list = initlist();
    Node *tail = get_tail(list);
    tail = inserttail(tail,10);
    tail = inserttail(tail,20);
    tail = inserttail(tail,30);
    listnode(list);
    insertnode(list,2,15);
    listnode(list);
    deletenode(list,2);
    listnode(list);
    printf("%d\n",listlength(list));
    freelist(list);
    printf("%d\n",listlength(list));
    return 0;
}