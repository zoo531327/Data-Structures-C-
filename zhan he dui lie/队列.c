#include<stdio.h>
#define MAXSIZE 100
typedef int elemtype;

typedef struct{
    elemtype data[MAXSIZE];
    int front;
    int rear;
}queue;

//初始化
void initqueue(queue *q){
    q->front = 0;
    q->rear = 0;
}

//判断队列是否为空
int isempty(queue *q){
    if(q->front == q->rear){
        printf("空的\n");
        return 1;
    }
    else return 0;
}

//出队
elemtype dequeue(queue *q){
    if(q->front == q->rear){
        printf("空的\n");
        return 0;
    }
    elemtype e = q->data[q->front];
    q->front++;
    return e;
}

//队列满了，调整队列
int queuefull(queue *q){
    if(q->front > 0){
        int step = q->front;
        for(int i = q->front; i <= q->rear; ++i){
            q->data[i - step] = q->data[i];
        }
        q->front = 0;
        q->rear = q->rear - step;
        return 1;
    }
    else{
        printf("真的满了\n");
        return 0;
    }
}

//入队
int equeue(queue *q,elemtype e){
    if(q->rear >= MAXSIZE){
        if(!queuefull(q)){
            return 0;
        }
    }
    q->data[q->rear] = e;
    q->rear++;
    return 1;
}

//获取队头数据
int gethead(queue *q,elemtype *e){
    if(q->front == q->rear){
        printf("空的\n");
        return 0;
    }
    *e = q->data[q->front];
    return 1;
}
int main(){
    queue q;
    initqueue(&q);

    equeue(&q,10);
    equeue(&q,20);
    equeue(&q,30);
    equeue(&q,40);
    equeue(&q,50);

    printf("%d\n",dequeue(&q));
    printf("%d\n",dequeue(&q));
    elemtype e;
    gethead(&q,&e);
    printf("%d\n",e);
}