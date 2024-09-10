#include <stdio.h>

int main()
{
    int sum = 0;
    int len = 5;
    int arr[] = {1, -2, 3, -4, 5};

    for (int idx = 0; idx < len; idx++)
    {
        if (arr[idx] > 0)
        {
            sum += arr[idx];
        }
    }

    printf("The result is %d\n", sum);

    return 0;
}