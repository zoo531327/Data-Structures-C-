#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int elemtype;

typedef struct{
    elemtype *data;
    int top;
}stack;

//初始化
stack *initstack(){
    stack *s = (stack*)malloc(sizeof(stack));
    s->data = (elemtype*)malloc(sizeof(elemtype)*MAXSIZE);
    s->top = -1;
    return s;
}

//判断栈是否为空
int isempty(stack *s){
    if(s->top == -1){
        printf("空的\n");
        return 1;
    }
    else{
        return 0;
    }
}

//进栈、压栈
int push(stack *s,elemtype e){
    if(s->top >= MAXSIZE-1){
        printf("栈已满\n");
        return 0; 
    }
    s->top++;
    s->data[s->top] = e;
    return 0;
}

//出栈
int pop(stack *s,elemtype *e){
    int a = isempty(s);
    if(a != 1){
        *e = s->data[s->top];
        s->top--;
        return 1;
    }
    else return 0;
}

//获取栈顶元素
int gettop(stack *s,elemtype *e){
    int a = isempty(s);
    if(a != 1){
        *e = s->data[s->top];
        return 1;
    }
    else return 0;
}

int main(){
    stack *s = initstack();
    push(s,10);
    push(s,20);
    push(s,30);
    elemtype e;
    pop(s,&e);
    printf("出栈元素：%d\n",e);
    gettop(s,&e);
    printf("栈顶元素：%d\n",e);
}