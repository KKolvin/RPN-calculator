#include "node.h"
#include "rpn-converter.h"
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>


node* createNode(double value, int type) { //Create a new node with a given value
    if (!value && !type) {
        printf("input needed");
        return false;
    }
    node* newNode = NULL;
    newNode = (node*) malloc(sizeof(node*));
    if (newNode) {
        newNode->contents.value = value;
        newNode->type = type;
        newNode->next = NULL;
        return newNode;
    }
    return false;
}

node* createOpeNode(char operator, int type) { //Create a new node of an operator
    if (!operator && !type) {
        printf("input needed");
        return false;
    }
    node* newNode = NULL;
    newNode = (node*) malloc(sizeof(node*));
    if (newNode) {
        newNode->contents.operator = operator;
        newNode->type = type;
        newNode->next = NULL;
        newNode->precedence = precedence(operator);
        return newNode;
    }
    return false;
}