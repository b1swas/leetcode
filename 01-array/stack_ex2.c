// https://leetcode.com/problems/valid-parentheses/
// Given string consisting of only brackets: '(', ')', '{', '}', '[' and ']'
// determine if the input string is valid, ie, brackets opened and closed on order

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isValid(char * s) {
    char stack[10000];
    int top = -1; // stack pointer

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } else {
            if (top == -1) return false;

            char open = stack[top--];
            if ((open == '(' && c != ')') ||
                (open == '{' && c != '}') ||
                (open == '[' && c != ']')) {
                return false;
            }
        }
    }

    return top == -1;
}

int main(int argc, char *argv[]) {
    char s1[] = "()[]{}"; // true
    char s2[] = "([])"; // true
    char s3[] = "(]"; // false
    char s4[] = "([)]"; // false
    printf("%s\n", isValid(s1) ? "true" : "false");
    printf("%s\n", isValid(s2) ? "true" : "false");
    printf("%s\n", isValid(s3) ? "true" : "false");
    printf("%s\n", isValid(s4) ? "true" : "false");
}
