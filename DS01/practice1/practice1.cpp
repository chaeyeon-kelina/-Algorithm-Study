#include <stdio.h>
#include <stdlib.h>

short check(short num, short *flag)
{
    short a;
    if (num >= 10)
        a = num % 10;
    else
        a = num;

    switch (a) {
    case 3:
        printf("¦");
        *flag = 1;
        break;
    case 6:
        printf("¦");
        *flag = 1;
        break;
    case 9:
        printf("¦");
        *flag = 1;
        break;
    default:
        break;
    }

    if (num < 10)
        return 1;
    else
        return check(num /= 10, flag);
}

int main()
{
    short A, B;
    short a = 0;
    short flag = 0;
    printf("������ ���ڿ� ������ ���� �Է�:");
    scanf("%hd %hd", &A, &B);

    for (short i = A; i <= B; i++) {
        printf("\n");
        flag = 0;
        check(i, &flag);
        
        if (flag == 0)
            printf("%hd", i);
    }
    return 0;
}


/*
������ �� �� ����

#include <stdio.h>
#include <stdlib.h>

int main()
{
    short A, B;
    short a = 0;
    short flag = 0;
    printf("������ ���ڿ� ������ ���� �Է�:");
    scanf("%hd %hd", &A, &B);

    for (short i = A; i <= B; i++) {
        printf("\n");
        flag = 0;
        short num = i;
        while (1) {
            if (num >= 10)
                a = num % 10;
            else
                a = num;

            switch (a) {
            case 3:
                printf("¦");
                flag = 1;
                break;
            case 6:
                printf("¦");
                flag = 1;
                break;
            case 9:
                printf("¦");
                flag = 1;
                break;
            default:
                break;
            }

            if (num < 10)
                break;
            else
                num /= 10;
        }
        if (flag == 0)
            printf("%hd", i);
    }
    return 0;
}
*/