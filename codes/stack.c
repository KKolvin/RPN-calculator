#include "stack.h"
#include "node.h"
#include <malloc.h>

node* HEAD = NULL;

bool clearStack() {
    if (!HEAD) {
        return true;
    }
    struct node* delete = HEAD;
    while (delete != NULL) {
        free(pop());
        delete = delete->next;
    }
    return true;
}

bool isStackEmpty() {
    if (HEAD != NULL) {
        return false;
    }
    return true;
}

bool push(node* node) {
    if (!node) {
        return false;
    }
    if (!HEAD) {
        HEAD = node;
        return true;
    }
    node->next = HEAD;
    HEAD = node;
    return true;
}

struct node* pop() {
    if (!HEAD) {
        return NULL;
    }
    node* popNode = HEAD;
    HEAD = popNode->next;
    popNode->next = NULL;
    return popNode;
}

struct node* peek() {
    if (!HEAD) {
        return false;
    }
    return HEAD;
}

void printStack(void) {
    node *walker = HEAD;
    if (isStackEmpty()) {
        puts("Empty stack");
    } else {
        printf("Stack: ");
        while (walker) {
            printf(" %c ", walker->contents);
            walker = walker->next;
        }
        puts("");
    }
}