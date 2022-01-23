#include <stdio.h>
#include <stdlib.h>  /* for atof() */
#include <stdbool.h>
#include <math.h>
#include "calc.h"

#define MAXOP    100 /* max size of operand or operator */

void helpinfo();

/* reverse Polish calculator */
int main(void)
{
    int type;
    double op2;
    double x, y, z;    /* declare variables x, y, z */
    double r;    /* most recently printed value */
    char s[MAXOP];
    bool assign, arithmetic;

    assign = arithmetic = false;
    x = y = z = 0.0;
    r = 0.0;
    printf("> ");    /* print prompt */
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;

            case '+':
                push(pop() + pop());
                break;

            case '*':
                push(pop() * pop());
                break;

            case '-':
                op2 = pop();
                push(pop() - op2);
                break;

            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;

            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push((int)pop() % (int)op2);
                else
                    printf("error: zero divisor\n");
                break;

            case '\n':
                r = pop();
                printf("\t%.8g\n", r);
                printf("> ");    /* print prompt */
                break;

            case 'h':    /* show help info */
                helpinfo();
                printf("> ");    /* print prompt */
                break;

            case 'p':    /* print top element of the stack */
                if (get_top_element())
                    printf("\n\ttop element of the stack: %.8g\n", get_top_element());
                printf("> ");    /* print prompt */
                break;

            case 'd':    /* duplicate top element */
                if (duplicate_top_elem())
                    printf("\n\ttop element has been duplicated\n");
                printf("> ");    /* print prompt */
                break;

            case 's':    /* swap the top two elements */
                if (swap_top_elem())
                    printf("\n\tthe top two elements have been swapped\n");
                printf("> ");    /* print prompt */
                break;

            case 'c':    /* clear the stack */
                clear_stack();
                printf("\n\tthe stack is clear\n");
                printf("> ");    /* print prompt */
                break;

            case 'a':    /* print the stack */
                print_stack();
                printf("> ");    /* print prompt */
                break;

            case 'i':    /* sin() */
                push(sin(pop()));
                break;

            case 'o':    /* cos() */
                push(cos(pop()));
                break;

            case 'e':    /* exp() */
                push(exp(pop()));
                break;

            case 'w':    /* pow() */
                {
                    double x, y;
                    y = pop();
                    x = pop();
                    if (x == 0 && y < 0 ||
                            x < 0 && y-(int)y != 0)  { /* verify if y is an integer */
                        printf("error:  pow(x,y) error\n");
                        printf("> ");    /* print prompt */
                    }
                    push(pow(x, y));
                }
                break;

            case 'v':    /* show variables */
                printf("\n\nnormal variables:\n");
                printf("\tx:  %g\n", x);
                printf("\ty:  %g\n", y);
                printf("\tz:  %g\n", z);
                printf("\nmost recently printed variables:\n");
                printf("\tr:  %g\n", r);
                printf("> ");    /* print prompt */
                break;

            case '=':    /* for assignment of variables */
                assign = true;
                break;

            case '&':    /* for arithmetic operation of variables */
                arithmetic = true;
                break;

            case 'x':    /* variable x */
                if (assign) {
                    x = pop();
                    printf("\n\tx:  %g\n", x);
                    printf("> ");    /* print prompt */
                    assign = false;
                } else if (arithmetic) {
                    push(x);
                    arithmetic = false;
                }
                break;

            case 'y':    /* variable y */
                if (assign) {
                    y = pop();
                    printf("\n\ty:  %g\n", y);
                    printf("> ");    /* print prompt */
                    assign = false;
                } else if (arithmetic) {
                    push(y);
                    arithmetic = false;
                }
                break;

            case 'z':    /* variable z */
                if (assign) {
                    z = pop();
                    printf("\n\tz:  %g\n", z);
                    printf("> ");    /* print prompt */
                    assign = false;
                } else if (arithmetic) {
                    push(z);
                    arithmetic = false;
                }
                break;

            case 'r':    /* for most recently printed variables */
                if (assign) {
                    printf("error: can't not assign the most recently printed variables\n");
                    printf("> ");    /* print prompt */
                }
                else if (arithmetic) {
                    push(r);
                    arithmetic = false;
                }
                break;

            case 't':    /* TODO: base conversions */
                break;

            default:
                printf("\n\terror: unknown command %s\n", s);
                printf("> ");    /* print prompt */
                break;
        }
    }
    printf("Calculator exit!\n");
    return 0;
}

/* helpinfo:  print help information */
void helpinfo()
{
    printf("\n\n<============== Reverse Polish Calculator ============>\n\n");
    printf("h:  print help infomation\n");
    printf("p:  print top element of the stack\n");
    printf("d:  duplicate top element\n");
    printf("s:  swap the top two elements\n");
    printf("c:  clear stack\n");
    printf("a:  print stack\n");
    printf("i:  sin()\n");
    printf("o:  cos()\n");
    printf("e:  exp()\n");
    printf("w:  pow()\n");
    printf("v:  show all variables\n");
    printf("x:  normal variable\n");
    printf("y:  normal variable\n");
    printf("z:  normal variable\n");
    printf("r:  most recently printed variable\n");
    printf("=:  assign variables, e.g. 2 3 + = x <=> x = 5\n");
    printf("&:  reference to variables' value, e.g. &x &y + <=> x + y\n");
    printf("t:  show base conversions\n");
    printf("\n");
}
