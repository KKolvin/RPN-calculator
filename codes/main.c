#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "node.h"
#include "stack.h"
#include "rpn.h"
#include "errors.h"
#include "rpn-converter.h"

int main(int argc, char* argv[]) {
    int status = NOERROR;
    char line[100];

    FILE* infile = fopen(argv[1], "r");
    FILE* outfile = fopen(argv[2], "w+");

    if (!infile || !outfile) {
        status = INVALID_FILE_OPERATION;
        return -1;
    }

    while (fgets(line, 100, infile)) {
        fprintf(outfile,"Infix: %s\n", line);
        //printf("infix is %s\n", line);
        char* postfix = convert(line, &status);
        if (status != 0) {
            fprintf(outfile,"Conversion from infix to postfix failure");
            printf("CONVERSION FAILURE\n\n");
            continue;
        }
        fprintf(outfile,"Postfix: %s\n", postfix);
        double answer = evaluate(postfix, &status);
        fprintf(outfile, "Result: %f\n\n", answer);
        status=0;
    }
    fclose(infile);
    fclose(outfile);


    return 0;
    // ps 5 test
    /*char expression_a[] = "( 8 + 9 ) - 10";
    char* converted_a = convert(expression_a, &status);
    double result1 = evaluate(converted_a, &status);
    outputError(status);
    if (status == 0) {
        printf("The result for expression 1 is : %f\n",result1);
    }
    printf("\n");*/

    // ps 4 test
    /*char expression1[] = "24.2 12 / 3 / 17 + +";
    char expression2[] = "+";
    char expression3[] = "17 22 / 4 * 16 -";
    char expression4[] = "2 8 ^ 3 /";
    char expression5[] = "17 22 33 / 4 + 2";
    char expression6[] = "";
    char expression7[] = "8 7 + 6 - 5 / 4 * 3 ^";

    printf("First test:\n");
    double result1 = evaluate(expression1, &status);
    outputError(status);
    if (status == 0) {
        printf("The result for expression 1 is : %f\n",result1);
    }
    printf("\n");

    printf("Second test:\n");
    double result2 = evaluate(expression2, &status);
    outputError(status);
    if (status == 0) {
        printf("The result for expression 2 is : %f\n",result2);
    }
    printf("\n");

    printf("Third test:\n");
    double result3 = evaluate(expression3, &status);
    outputError(status);
    if (status == 0) {
        printf("The result for expression 3 is : %f\n",result3);
    }
    printf("\n");

    printf("Fourth test:\n");
    double result4 = evaluate(expression4, &status);
    outputError(status);
    if (status == 0) {
        printf("The result for expression 4 is : %f\n",result4);
    }
    printf("\n");

    printf("Fifth test:\n");
    double result5 = evaluate(expression5, &status);
    outputError(status);
    if (status == 0) {
        printf("The result for expression 5 is : %f\n",result5);
    }
    printf("\n");

    printf("Sixth test:\n");
    double result6 = evaluate(expression6, &status);
    outputError(status);
    if (status == 0) {
        printf("The result for expression 6 is : %f\n",result6);
    }
    printf("\n");

    printf("Seventh test:\n");
    double result7 = evaluate(expression7, &status);
    outputError(status);
    if (status == 0) {
        printf("The result for expression 7 is : %f\n",result7);
    }
    printf("\n");
    */

}
