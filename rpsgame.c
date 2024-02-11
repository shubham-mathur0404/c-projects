#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

int game(char you, char comp);

int main()
{
    char answer;
    do
    {
    int n;
    char you, comp, result;

    srand(time(NULL));

    n = rand() % 100;

    if (n > 33)

        comp = 'r';

    else if (n > 33 && n < 66)

        comp = 'p';

    else
        comp = 's';

    printf("enter your move:-\n");

    scanf("%c", &you);

    result = game(you, comp);

    if (result == -1)
    {
        printf("\n\n\t\t\t\tGame Draw!\n");
    }
    else if (result == 1)
    {
        printf("\n\n\t\t\t\tWow! You have won the game!\n");
    }
    else
    {
        printf("\n\n\t\t\t\tOh! You have lost the game!\n");
    }
    printf("\t\t\t\tYOu choose : %c and Computer choose : %c\n", you, comp);

     
    
        printf("press y to continue\n");
        scanf(" %c", &answer); 
        fflush(stdin);
    } while (answer == 'y' || answer == 'Y');


    return 0;
}

int game(char you, char comp)
{
    if (you == comp)
        return -1;
    if (you == 'r' && comp == 'p')
        return 0;
    else if (you == 'p' && comp == 'r')
        return 1;

    if (you == 'p' && comp == 's')
        return 0;
    else if (you == 's' && comp == 'p')
        return 1;

    if (you == 's' && comp == 'r')
        return 0;
    else if (you == 'r' && comp == 's')
        return 1;
}