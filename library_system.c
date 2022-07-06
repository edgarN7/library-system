#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fOperationToDo();

void fList();

void fUpdate();

int main()
{
    //FILE * fpLibrary;

    int operationChoosed = fOperationToDo();

    switch (operationChoosed)
    {
    case 1:
        fList();
        break;

    case 2:
        fUpdate();
        break;

    default:
        printf("operationChoosed error.\n");
        break;
    }

    return 0;
}

int fOperationToDo()
{
    int operation = 0;

    printf("1 - To list the library;\n2 - To update the library;\n\n");

    do
    {
        scanf("%d", &operation);
    } while ((operation != 1) && (operation != 2));

    printf("\n");

    return operation;
}

void fList()
{
    FILE *csvLibraryL;
    char c;

    csvLibraryL = fopen("teste_ls.csv", "r");
    if (csvLibraryL == NULL)
    {
        fputs("File Error\n", stderr);
        exit(2);
    }

    while ((c = getc(csvLibraryL)) != EOF)
    {
        printf("%c", c);
    }
};

void fUpdate()
{
    FILE *csvLibraryU;
    char borrowOrReturn;
    char booksName[256];
    int booksQuantity = 0;

    csvLibraryU = fopen("teste_ls.csv", "r");
    if (csvLibraryU == NULL)
    {
        fputs("File Error\n", stderr);
        exit(3);
    }

    long lSize;
    char *buffer;
    size_t result;

    // obtain file size:
    fseek(csvLibraryU, 0, SEEK_END);
    lSize = ftell(csvLibraryU);
    rewind(csvLibraryU);

    // allocate memory to contain the whole file:
    buffer = (char *)malloc(sizeof(char) * lSize);
    if (buffer == NULL)
    {
        fputs("Memory error", stderr);
        exit(4);
    }

    // copy the file into the buffer:
    result = fread(buffer, 1, lSize, csvLibraryU);
    if (result != lSize)
    {
        fputs("Reading error", stderr);
        exit(5);
    }

    printf("%s\n\n", buffer);

    char *matrixLines[256];
    int n = 0, countLines = 0;

    matrixLines[n] = strtok(buffer, "\n");
    while (matrixLines[n] != NULL)
    {
        printf("s:%s n:%d\n", matrixLines[n], n);
        n++;
        matrixLines[n] = strtok(NULL, "\n");

        countLines++;
    }

    struct stBooks
    {
        char *bName;
        int bQuantity;
    };

    struct stBooks bookAndQuantities[countLines];

    for (int i = 0; i < countLines; i++)
    {
        bookAndQuantities->bName = strtok(matrixLines[i], ",");
        bookAndQuantities->bQuantity = atoi(strtok(NULL, "\0"));
    }

    printf("b - To borrow a book;\nr - To return a book\n\n");

    do
    {
        borrowOrReturn = getchar();
    } while ((borrowOrReturn != 'b') && (borrowOrReturn != 'r'));

    printf("\n");

    switch (borrowOrReturn)
    {
    case 'b':
        printf("What is the book's name?\n");
        gets(booksName);
        printf("\n");

        printf("How many?\n");
        scanf("%d", &booksQuantity);
        break;

    case 'r':
        printf("txo\n");
        break;

    default:
        printf("txu\n");
        break;
    }
}