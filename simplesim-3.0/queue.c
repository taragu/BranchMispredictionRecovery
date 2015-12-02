#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//code taken from http://geeksquiz.com/queue-set-1introduction-and-array-implementation/

struct Queue
{
  int front, rear, size;
  unsigned capacity;
  int* array;
};
 
struct Queue* createQueue(unsigned capacity)
{
  struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
  queue->capacity = capacity;
  queue->front = queue->size = 0; 
  queue->rear = capacity - 1; 
  queue->array = (int*) malloc(queue->capacity * sizeof(int));
  return queue;
}

//returns new queue with the item deleted
struct Queue* delete(struct Queue* queue, int item) {
  //make new queue without the element
  struct Queue* newQueue = createQueue(queue->capacity);
  newQueue->capacity = queue->capacity;
  newQueue->size = queue->size-1;
  int newQueueIndex = 0;
  for (int i=0; i<queue->capacity; i++) {
    if (queue->array[i] != item) {
      newQueue->array[newQueueIndex] = queue->array[i];
      newQueueIndex++;
    }
  }
  //update front and rear
  /**  if (queue->array[queue->front] == item) {
    newQueue->front = (queue->front +1)%queue->capacity;
    }*/
  newQueue->front = (queue->front);
  newQueue->rear = (queue->rear-1)%queue->capacity;
  return newQueue;
}
 
// Queue is full when size becomes equal to the capacity 
int isFull(struct Queue* queue)
{  return (queue->size == queue->capacity);  }
 
// Queue is empty when size is 0
int isEmpty(struct Queue* queue)
{  return (queue->size == 0); }
 
// Function to add an item to the queue.  It changes rear and size
void enqueue(struct Queue* queue, int item)
{
  if (isFull(queue))
    return;
  queue->rear = (queue->rear + 1)%queue->capacity;
  queue->array[queue->rear] = item;
  queue->size = queue->size + 1;
  printf("%d enqueued to queue\n", item);
}
 
// Function to remove an item from queue.  It changes front and size
int dequeue(struct Queue* queue)
{
  if (isEmpty(queue))
    return INT_MIN;
  int item = queue->array[queue->front];
  queue->front = (queue->front + 1)%queue->capacity;
  queue->size = queue->size - 1;
  return item;
}
 
// Function to get front of queue
int front(struct Queue* queue)
{
  if (isEmpty(queue))
    return INT_MIN;
  return queue->array[queue->front];
}
 
// Function to get rear of queue
int rear(struct Queue* queue)
{
  if (isEmpty(queue))
    return INT_MIN;
  return queue->array[queue->rear];
}

void printQueue(struct Queue* queue) {
  for (int i=0; i<queue->capacity; i++) {
    if (i==queue->front) {
      printf("[front]");
    }
    if (i==queue->rear) {
      printf("[rear]");
    }
    printf("%d   ", queue->array[i]);
  }
  printf("\n\n\n");
}
 
// Driver program to test above functions./
int main()
{
  struct Queue* queue = createQueue(1000);
 
  enqueue(queue, 10);
  enqueue(queue, 20);
  enqueue(queue, 30);
  enqueue(queue, 40);
  enqueue(queue, 50);
  printf("%d dequeued from queue\n", dequeue(queue));
 
  printf("Front item is %d\n", front(queue));
  printf("Rear item is %d\n", rear(queue));
  printQueue(queue);
  
  struct Queue* newQueue = delete(queue, 50);
  printf("After deleting 50:\n");
  printQueue(newQueue);
  return 0;
}
