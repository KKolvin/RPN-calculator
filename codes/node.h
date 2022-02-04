#ifndef PS4_NODE_H
#define PS4_NODE_H

enum {OPERATOR, NUMBER} type;

typedef struct node {
    union {
        double value;
        char operator;
    } contents;
    int type;
    int precedence;
    struct node *next;
} node;

node* createNode(double, int);
node* createOpeNode(char, int);

#endif //PS4_NODE_H
