#include<stdio.h>
#include<stdlib.h>
typedef int elemtype;

typedef struct Stack{
    elemtype data;
    struct Stack *next;
}stack;

//初始化
stack *initstack(){
    stack *s = (stack*)malloc(sizeof(stack));
    s->data = 0;
    s->next = NULL;
    return s;
}

//判断栈表是否为空
int isempty(stack *s){
    if(s->next == NULL){
        printf("空的\n");
        return 1;
    }
    else return 0;
}

//进栈/压栈
int push(stack *s,elemtype e){
    stack *p = (stack*)malloc(sizeof(stack));
    p->data = e;
    p->next = s->next;
    s->next = p;
    return 1;
}

//出栈
int pop(stack *s,elemtype *e){
    if(s->next == NULL){
        printf("空的\n");
        return 0;
    }
    *e = s->next->data;
    stack *q = s->next;
    s->next = q->next;
    free(q);
    return 1;
}

//获取栈顶元素
int gettop(stack *s,elemtype *e){
    if(s->next == NULL){
        printf("空的\n");
        return 0;
    }
    *e = s->next->data;
    return 1;
}

int main(){
    stack *s = initstack();
    push(s,10);
    push(s,20);
    push(s,30);

    elemtype e;
    pop(s,&e);
    printf("%d\n",e);

    gettop(s,&e);
    printf("%d\n",e);

    return 0;
}