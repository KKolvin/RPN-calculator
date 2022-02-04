#include "errors.h"
#include <stdio.h>

char* errors[] = {
        "No error, program finishes",
        "Null input, program fails",
        "Invalid input, program fails",
        "DIVISION can't be 0, program fails",
        "Too many operators, program fails",
        "Invalid operator, program fails",
        "Invalid expression, program fails",
        "Mismatched parenthesis, program fails",
        "Invalid file operation, program fails"
};

void outputError(int input){
    printf("%s\n", errors[input]);
}