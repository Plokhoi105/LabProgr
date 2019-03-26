#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

char menu() {
    char choice;
    printf("***********************\n");
    printf("What do you want to do?\n");
    printf("***********************\n");
    printf("[C] Complete the task\n");
    printf("[Q] Quit\n");
    printf("***********************\n");
    printf("Your choice: ");
    while((choice = getchar()) == '\n');
    printf("\n");
    return choice;
}

int main(int argc, char *argv[]){
    char ans;
    while((ans = toupper(menu())) != 'Q') {
    if (ans == 'C') {
            double a, b, x, res;
            printf("a = ");
            scanf("%lf", &a);
            printf("b = ");
            scanf("%lf", &b);
            printf("x = ");
            scanf("%lf", &x);
            res = (pow(sin(a-x),3.2))/(b+pow(x,-1.7));
            printf("F(x) = %.2f\n\n", res);
    }
    }
    return 0;
}
