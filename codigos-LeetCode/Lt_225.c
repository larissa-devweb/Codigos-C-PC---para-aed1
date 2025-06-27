// 🔧 Declaração antecipada obrigatória pro LeetCode
typedef struct MyStack MyStack;

typedef struct {
    int data[100];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

void enqueue(Queue *q, int val) {
    q->data[q->rear++] = val;
}

int dequeue(Queue *q) {
    return q->data[q->front++];
}

int frontQueue(Queue *q) {
    return q->data[q->front];
}

bool isEmptyQueue(Queue *q) {
    return q->front == q->rear;
}

struct MyStack {
    Queue q1;
    Queue q2;
};

MyStack* myStackCreate() {
    MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
    initQueue(&stack->q1);
    initQueue(&stack->q2);
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    enqueue(&obj->q2, x);

    while (!isEmptyQueue(&obj->q1)) {
        enqueue(&obj->q2, dequeue(&obj->q1));
    }

    Queue temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
}

int myStackPop(MyStack* obj) {
    return dequeue(&obj->q1);
}

int myStackTop(MyStack* obj) {
    return frontQueue(&obj->q1);
}

bool myStackEmpty(MyStack* obj) {
    return isEmptyQueue(&obj->q1);
}

void myStackFree(MyStack* obj) {
    free(obj);
}
