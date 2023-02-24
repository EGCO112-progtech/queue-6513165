#include "Node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Queue.h"

int main(int argc, char **argv) {
  NodePtr headPtr = NULL;
  NodePtr tailPtr = NULL;
  // For struct Queue
  Queue q;
  q.headPtr = NULL;
  q.tailPtr = NULL;
  q.size = 0;

  int i, x, cash, n=1;

  for (i = 1; i < argc; i++) {
    if (strcmp(argv[i], "x") == 0) {
      printf("Customer no: %d\n", n);
      x = dequeue_struct(&q);
      if (x == 0);
        else {
          printf("You have to pay %d\n", x);
          printf(":Cash:");
          scanf("%d", &cash);
          while (cash < x) {
            printf("Cash:");
            scanf("%d", &cash);
          };
          printf("Thank you\n");
          if (cash > x)
            printf("Change is:%d\n", cash - x);
        }
      n++;
    } else {
      enqueue_struct(&q, atoi(argv[i]), atoi(argv[i + 1]));
      i++;
    }
  }
  printf("======================================\n");
  if (q.size == 1 || q.size == 0)
    printf("There is %d ppl left in the queue.\n", q.size);
  else
    printf("There are %d ppl left in the queue.\n", q.size);
  printf("Clearing queue\n");
    while(q.size>0)
      dequeue_struct(&q);
  return 0;
}
