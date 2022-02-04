#include "rpn.h"
#include "node.h"
#include "stack.h"
#include "errors.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

double calculate(double number1, double number2, char operator) {
    double result = 0;
    switch(operator){
        case '+':{ // addition
            result = number2+number1;
            break;
        }
        case '-':{ // subtraction
            result = number2-number1;
            break;
        }
        case '*':{ // multiplication
            result = number2*number1;
            break;
        }
        case '/':{ //division
            result = number2/number1;
            break;
        }
        case '^':{ //power
            if (number1 == 0) {
                result = 1;
                break;
            }
            result = number2;
            while (number1 != 1) {
                result = result * number2;
                number1 = number1 - 1;
            }
            break;
        }
        default:
            return false;
    }
    return result;
}

double evaluate (char* expression, int* status) {
    clearStack();
    //return first token
    char* token = strtok(expression, " ");

    if (!token){ //null input
        *status = NULLINPUT;
        return 0.0;
    }
    if (!isdigit(*token)) {
        *status = WRONGINPUT;
        return 0.0;
    }


    //walk through the rest of the tokens
    while (token != NULL) {
        if (isdigit(*token)) {
            double value = atof(token);
            node* number = createNode(value, NUMBER);
            push(number);
        }
        else {
            //first number
            node* node1 = pop();
            if (node1 == NULL){
                *status = WRONGINPUT;
                return 0.0;
            }
            double number1 = node1->contents.value;
            //second number
            node* node2 = pop();
            if (node2 == NULL) { // this means we have 1 num and 1 operator left in the stack
                *status = TOOMANYOPERATOR;
                return 0.0;
            }
            double number2 = node2->contents.value;
            //check for error
            if (*token == "/" && number2 == 0) { // 0 can't be divisor
                *status = DIVISORZERO;
                return 0.0;
            }
            //the successful case
            double newNum = calculate(number1, number2, *token);
            if (newNum == false) {
                *status = INVALIDOPERATOR;
                return 0.0;
            }
            free(node1);
            free(node2);
            push(createNode(newNum, NUMBER));
        }
        // update to the next token
        token = strtok(NULL, " ");
    }

    // calculation now completed; it's time to check what's left in the stack
    node* output = pop();
    if (isStackEmpty()){ // we should have just a number
        *status = NOERROR;
        return output->contents.value;
    }
    else{
        *status = INVALIDEXPRESSION;
        return 0.0;
    }
}