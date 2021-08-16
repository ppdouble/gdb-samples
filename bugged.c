/*
 * Sample C program bugged with a simple, yet nasty error
 */


#include <stdio.h>

#define PROMPT "Enter a string: "

void get_input (char *, char *);
void null_function1 ();
void null_function2 ();

int main (int argc, char *argv[]) {

    char *s_val;

    null_function1 ();
    null_function2 ();
    get_input(PROMPT, s_val);
    (void) printf("You entered: %s\n", s_val);
    (void) printf("The end of buggy code!\n");

    return 0;
}

void get_input (char *prompt, char *str) {
    (void) printf("%s", prompt);
    for (*str = getchar(); *str != '\n'; *str = getchar()) {
        str++;
        *str = '\0'; /* string terminator */
    }
}

void null_function1 () {
}

void null_function2 () {
}
