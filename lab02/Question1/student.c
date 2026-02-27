// Question1/Student.c
// ------------------------------------------------------------
// CS Lab - Valid Parentheses (STACK PRACTICE)
//
// Task:
// Implement `isValid(const char *s)`.
// Given a string s containing only: () {} []
// return true if it is a valid parentheses string, else false.
//
// Valid rules:
// 1) Open brackets must be closed by the same type of brackets.
// 2) Open brackets must be closed in the correct order.
// 3) Every close bracket has a corresponding open bracket.
//
// Examples:
//   s = "()"        -> true
//   s = "()[]{}"    -> true
//   s = "(]"        -> false
//   s = "([)]"      -> false
//   s = "{[]}"      -> true
//   s = ""          -> true   (empty string is valid)
//
// How to run tests (from the folder containing the Makefile):
//   make run1
// ------------------------------------------------------------

#include "Student.h"
#include <stdbool.h>
#include <stdlib.h>  // malloc, free
#include <stddef.h>  // size_t
#include <string.h>  // strlen

#include <stdbool.h>
#include <stdlib.h>

static bool is_open(char c) {
    return c == '(' || c == '[' || c == '{';
}

static bool matches(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

bool isValid(const char *s) {
    if (s == NULL) return true;

    int n = 0;
    while (s[n] != '\0') n++;

    char *stack = (char *)malloc((size_t)n * sizeof(char));
    if (!stack) return false;

    int top = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        if (is_open(c)) {
            stack[top++] = c;           // push
        } else {
            if (top == 0) {             // nothing to match
                free(stack);
                return false;
            }
            char open = stack[top - 1]; // peek
            if (!matches(open, c)) {
                free(stack);
                return false;
            }
            top--;                      // pop
        }
    }

    bool ok = (top == 0);
    free(stack);
    return ok;
}