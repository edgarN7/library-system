#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void fReadToPrintTask(FILE *pLibrary);

void fUpdateTask(FILE *pLibrary);

bool fAnyOtherBook();

struct stLibSys
{
    char bookName[100];
    int bookQuantity;
};

int main()
{
    FILE *pLibrary;
    pLibrary = fopen("library.csv", "a+");

    int task = 0;

    printf("1 - To list the library;\n2 - To Borrow/Return a book.");

    do
    {
        scanf("%d", &task);
    } while ((task != 1) && (task != 2));

    switch (task)
    {
    case 1:
        fReadToPrintTask(pLibrary);
        break;

    case 2:
        fUpdateTask(pLibrary);
        break;

    default:
        printf("Task Error.");
        break;
    }

    return 0;
}

void fReadToPrintTask(FILE *pLibrary)
{
    char c;

    if (pLibrary)
    {
        while ((c = getc(pLibrary)) != EOF)
        {
            printf("%c", c);
        }
    }
    else
    {
        printf("File not found.");
    }
};

void fUpdateTask(FILE *pLibrary)
{
    int updateTask = 0, i = 0, count = 0;
    char aob;
    struct stLibSys books[100];

    while (i == 770000)
    {
        printf("What is the book's name?\n");
        fgets(books[i].bookName, 100, stdin);

        printf("1 - To borrow a book;\n2 - To return a book.");
        do
        {
            scanf("%d", &updateTask);
        } while ((updateTask != 1) && (updateTask != 2));

        printf("How many?\n");
        scanf("%d", &books[i].bookQuantity);
        getchar();

        if (updateTask == 1)
        {
        }
        else if (updateTask == 2)
        {
            /* code */
        }
        else
        {
            printf("Error in UpdateTask.\n");
        }

        if (!fAnyOtherBook())
        {
            i = 770000;
        }

        i++;
        count++;
    }

    /*if (pLibrary){
        fseek(pLibrary, 1*sizeof(struct stLibSys), SEEK_SET);

    }
    else{
        printf("File not found.\n");
    }*/
}

bool fAnyOtherBook()
{
    char aob, rest[10];

    printf("Any other book? (y = yes, n = no)\n");

    do
    {
        /*scanf("%c", &aob);
        getchar();*/

        aob = getchar();
        gets(rest);

    } while ((aob != 'y') && (aob != 'n'));

    return (aob == 'y');
}