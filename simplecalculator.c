#include <stdio.h>

int main()
{
    char answer;
    while (1)
    {
        char ch;
        double a, b;

        printf("Enter an operator (+, -, *, /) :- ");
        scanf("%c", &ch);

        printf("enter the numbers :-");
        scanf("%lf %lf", &a, &b);

        switch (ch)
        {
        case '+':

            printf("%.1lf + %.1lf = %.1lf\n", a, b, a + b);

            break;

        case '-':

            printf("%.1lf - %.1lf = %.1lf\n", a, b, a - b);

            break;

        case '*':

            printf("%.1lf * %.1lf = %.1lf\n", a, b, a * b);

            break;

        case '/':

            printf("%.1lf / %.1lf = %.1lf\n", a, b, a / b);

            break;

        default:
            printf(
                "Error! please write a valid operator\n");
        }

    }

    return 0;
}