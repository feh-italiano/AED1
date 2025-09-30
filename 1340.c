#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_SIZE 1000
#define MAX_CASES 1000

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

typedef struct {
    int data[MAX_SIZE];
    int size;
} PriorityQueue;

void stack_init(Stack *s) {
    s->top = -1;
}

void stack_push(Stack *s, int val) {
    s->data[++(s->top)] = val;
}

int stack_pop(Stack *s) {
    return s->data[(s->top)--];
}

int stack_top(Stack *s) {
    return s->data[s->top];
}

int stack_empty(Stack *s) {
    return s->top == -1;
}

void queue_init(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

void queue_push(Queue *q, int val) {
    q->data[++(q->rear)] = val;
}

int queue_pop(Queue *q) {
    return q->data[(q->front)++];
}

int queue_front(Queue *q) {
    return q->data[q->front];
}

int queue_empty(Queue *q) {
    return q->front > q->rear;
}

void pq_init(PriorityQueue *pq) {
    pq->size = 0;
}

void pq_swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void pq_push(PriorityQueue *pq, int val) {
    int i = pq->size++;
    pq->data[i] = val;
    
    while (i > 0 && pq->data[i] > pq->data[(i - 1) / 2]) {
        pq_swap(&pq->data[i], &pq->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int pq_pop(PriorityQueue *pq) {
    int max = pq->data[0];
    pq->data[0] = pq->data[--(pq->size)];
    
    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        
        if (left < pq->size && pq->data[left] > pq->data[largest]) {
            largest = left;
        }
        if (right < pq->size && pq->data[right] > pq->data[largest]) {
            largest = right;
        }
        if (largest == i) break;
        
        pq_swap(&pq->data[i], &pq->data[largest]);
        i = largest;
    }
    
    return max;
}

int pq_top(PriorityQueue *pq) {
    return pq->data[0];
}

int pq_empty(PriorityQueue *pq) {
    return pq->size == 0;
}

int main() {
    int n;
    char line[100];
    char results[MAX_CASES][20];
    int result_count = 0;
    
    while (scanf("%d", &n) != EOF) {
        getchar();
        
        int op[MAX_SIZE], val[MAX_SIZE];
        int op_count = 0;
        
        for (int i = 0; i < n; i++) {
            fgets(line, sizeof(line), stdin);
            if (line[0] == '1') {
                op[op_count] = 1;
                sscanf(line + 2, "%d", &val[op_count]);
                op_count++;
            } else {
                op[op_count] = 2;
                sscanf(line + 2, "%d", &val[op_count]);
                op_count++;
            }
        }
        
        int is_stack = 1, is_queue = 1, is_priority = 1;
        
        Stack s; stack_init(&s);
        Queue q; queue_init(&q);
        PriorityQueue pq; pq_init(&pq);
        
        for (int i = 0; i < op_count; i++) {
            if (op[i] == 1) {
                if (is_stack) stack_push(&s, val[i]);
                if (is_queue) queue_push(&q, val[i]);
                if (is_priority) pq_push(&pq, val[i]);
            } else {
                if (is_stack) {
                    if (stack_empty(&s) || stack_pop(&s) != val[i]) {
                        is_stack = 0;
                    }
                }
                
                if (is_queue) {
                    if (queue_empty(&q) || queue_pop(&q) != val[i]) {
                        is_queue = 0;
                    }
                }
                
                if (is_priority) {
                    if (pq_empty(&pq) || pq_pop(&pq) != val[i]) {
                        is_priority = 0;
                    }
                }
            }
        }
        
        int count = is_stack + is_queue + is_priority;
        
        if (count == 0) {
            strcpy(results[result_count], "impossible");
        } else if (count > 1) {
            strcpy(results[result_count], "not sure");
        } else {
            if (is_stack) {
                strcpy(results[result_count], "stack");
            } else if (is_queue) {
                strcpy(results[result_count], "queue");
            } else {
                strcpy(results[result_count], "priority queue");
            }
        }
        result_count++;
    }
    
    for (int i = 0; i < result_count; i++) {
        printf("%s\n", results[i]);
    }
    
    return 0;
}