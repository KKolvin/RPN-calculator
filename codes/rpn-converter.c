#include "rpn-converter.h"
#include "errors.h"
#include "stack.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <malloc.h>
#define SIZE 100

int precedence(char ope) {
    // operator of a higher precedence returns a bigger number
    if (ope == '+' || ope == '-') {return 1;}
    else if (ope == '*' || ope == '/') {return 2;}
    else if (ope == '^') {return 3;}
    else if (ope == '(' || ope == ')') {return -1;}
    return false;
}

char* convert(char* expression, int* status) {
    char* token = strtok(expression, " ");
    if (!token){ //null input
        *status = NULLINPUT;
        return NULL;
    }
    clearStack();
    char debugger[100];
    char* postfix = malloc(SIZE);
    char operators[] = "+-*/^";
    while (token) {
        if (strstr(token, "\n")) {
            token = strtok(token, "\n");
        }
        if (isdigit(*token)){
            strcat(postfix, token);
            strcat(postfix," ");
        }
        else if (strstr(operators, token) != NULL) {
            while (!isStackEmpty()) {
                node* topNode = peek();
                char topOpe = topNode->contents.operator;
                int topOpe_pre = topNode->precedence;
                int currentOpe_pre = precedence(*token);
                if (topOpe_pre >= currentOpe_pre && topOpe != '(') {
                    strcpy(debugger, "");
                    sprintf(debugger,"%c ",topNode->contents.operator);
                    strcat(postfix, debugger);
                    pop();
                    continue;
                }
                break;
            }
            push(createOpeNode(*token, OPERATOR));
        }
        else if (*token == '(') {
            push(createOpeNode(*token, OPERATOR));
        }
        else if (*token == ')') {
            if (isStackEmpty()) {
                *status = MISMATCHED_PARENTHESIS;
                return false;
            }
            node* topNode = pop();
            char topOpe = topNode->contents.operator;
            while (topOpe != '(') {
                strcpy(debugger, "");
                sprintf(debugger,"%c ",topOpe);
                strcat(postfix, debugger);
                if (isStackEmpty()) { // the stack runs out without finding a left parenthesis
                    *status = MISMATCHED_PARENTHESIS;
                    return false;
                }
                topOpe = pop()->contents.operator;
            }
        }
        else {
            *status = INVALIDEXPRESSION;
            return false;
        }
        token = strtok(NULL, " ");
    }
    while (!isStackEmpty()) {
        node* topNode = pop();
        if (topNode=='('||topNode==')') { // If the operator token on the top of the stack is a parenthesis
            *status = MISMATCHED_PARENTHESIS;
            return false;
        }
        strcpy(debugger, "");
        sprintf(debugger,"%c ",topNode->contents.operator);
        strcat(postfix, debugger);
    }
    clearStack();
    //printf("we have: %s\n", postfix);
    return postfix;
}