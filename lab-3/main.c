#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

char main_menu(void);
void first_task(void);
void second_task(void);



int main(void)
{
    char ans;
    while((ans = toupper(main_menu())) != 'Q')
    {
    if (ans == 'C')
    {
        first_task();

    } else if (ans == 'F')
    {
        second_task();
    }
    }
    return 0;
}

void first_task()
{
    int size, *array, *buf;
    int i, max, max_pos, positive_pos = -1;
    printf("Size: ");
    scanf("%d", &size);
    array = (int*) malloc(sizeof(int) * size);
    if (!array)
    {
        printf("Memory error\n");
        return -1;
    }
    srand(time(NULL));
    printf("Your array: ");
    for(i = 0; i < size; i++)
    {
        array[i] = rand() % 100 - 10;
        printf("%d ", array[i]);
    }
    max = array[max_pos = 0];
    for(i = 1; i < size; i++)
        if (max < array[i])
            max = array[max_pos = i];
    for(i = max_pos + 1; i < size; i++)
        if (array[i] > 0)
        {
            positive_pos = i;
            break;
        }
    if (positive_pos != -1)
    {
        printf("\nMax element: %d\nFirst positive: %d", max, array[positive_pos]);
        buf = (int*) malloc(sizeof(int) * --size);
        if (positive_pos != size)
        {
            memmove(array + positive_pos, array + positive_pos + 1, (size - positive_pos + 1) * sizeof(int));
            memcpy(buf, array, size * sizeof(int));
        }
        else
            memcpy(buf, array, size * sizeof(int));
        free(array);
        array = buf;
        puts("");
        for(i = 0; i < size; i++)
            printf("%d ", array[i]);
        puts("");
    }
    else
    {
        puts("\nPositive number not found after max element");
        free(array);
    }
}

void second_task()
{
    int row, column, k;
    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of column: ");
    int **matrix = (int**)malloc(row * sizeof(int));
    scanf("%d", &column);
    int *arr = (int*)(malloc(sizeof(int) * column));
    printf("Enter value of k: ");
    scanf("%d", &k);
    for (int i = 0; i < row; ++i)
    {
        matrix[i] = (int*)malloc(column * sizeof(int));
    }
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            printf("Element matrix[%d][%d] = ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
            arr[j] = 0;

        }
    }
    printf("Your matrix: \n");
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            printf("[%d]\t", matrix[i][j]);
        }
        printf("\n\n");
    }
    int sum = 0;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            if(matrix[i][j] > k)
            {
                sum += matrix[i][j];
            }
        }
    }
    printf("Sum of elements > k: %d\n", sum);

    for(int i = 0; i < column; ++i)
    {
        for(int j = 0; j < row; ++j)
        {
            if(matrix[j][i] < 0)
                ++arr[i];
        }
    }

    for (int i = 0; i < column; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < row; ++i)
        {
            free(matrix[i]);
        }
        free(matrix);
}

char main_menu() {
    char choice;
    printf("*******************************\n");
    printf("What do you want to do?\n");
    printf("*******************************\n");
    printf("[C\\c] Complete the first task\n");
    printf("[F\\f] Complete the second task\n");
    printf("[Q\\q] Quit\n");
    printf("*******************************\n");
    printf("Your choice: ");
    while((choice = getchar()) == '\n');
    printf("\n");
    return choice;
}
