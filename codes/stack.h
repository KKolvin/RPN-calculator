#ifndef PS4_STACK_H
#define PS4_STACK_H
#include <stdbool.h>
#include "node.h"

bool clearStack(void);

bool isStackEmpty(void);

bool push(struct node*);

struct node* pop(void);

struct node* peek(void);

void printStack(void);

#endif //PS4_STACK_H
