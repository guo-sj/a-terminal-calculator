#define NUMBER   '0' /* signal that a number was found */

enum BASE {
    BINARY = 2,
    OCTAL = 8,
    HEXADECIMAL = 16,
};

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
double get_top_element();
void clear_stack();
int duplicate_top_elem();
int swap_top_elem();
void ungets(char *s);
void print_stack();
void show_buf();

void baseconv(double num, int base, char result[]);
void dec2bin(double num, char result[]);
void dec2oct(double num, char result[]);
void dec2hex(double num, char result[]);
