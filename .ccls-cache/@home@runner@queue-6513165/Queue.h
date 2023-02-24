#define price_1 100
#define price_2 20
#define price_3 50

typedef struct {
  NodePtr headPtr, tailPtr;
  int size;
} Queue;

void enqueue_struct(Queue *q, int x, int y) {
  printf("My order is %d\n",x);
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (new_node) {
    /*Finish enqueue */
    new_node->order_number = x;
    new_node->qty = y;
    new_node->nextPtr = NULL;
    
    if (q->headPtr == NULL)
      q->headPtr = new_node;
    else
      (q->tailPtr)->nextPtr = new_node;
    q->tailPtr = new_node;
    q->size++;
  }
}

int dequeue_struct(Queue *q) {
  NodePtr t = q->headPtr;
  int price_all;
  if (q->size>0) {
    switch(t->order_number){
      case 1: printf("Ramen\n"); price_all=price_1*t->qty; break;
      case 2: printf("Somtum\n"); price_all=price_2*t->qty; break;
      case 3: printf("Fried Chicken\n"); price_all=price_3*t->qty; break;
      default: printf("No Food\n"); price_all=0; break;
    }
    //int value = t->data;
    /*Finish dequeue */

    q->headPtr = t->nextPtr;
    if (q->headPtr == NULL)
      q->tailPtr = NULL;
    q->size--;
    free(t);
    return price_all;
  }
  printf("Empty queue");
  return 0;
}
