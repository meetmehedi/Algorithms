#include <stdio.h>

struct Activity
{
    int start, finish;
};

void swap(struct Activity *a, struct Activity *b)
{
    struct Activity temp = *a;
    *a = *b;
    *b = temp;
}

void sortActivities(struct Activity arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].finish > arr[j + 1].finish)
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void activitySelection(struct Activity arr[], int n)
{
    sortActivities(arr, n);

    printf("Selected activities (start, finish):\n");

    int last = 0;
    printf("(%d, %d)\n", arr[last].start, arr[last].finish);

    for (int i = 1; i < n; i++)
    {
        if (arr[i].start >= arr[last].finish)
        {
            printf("(%d, %d)\n", arr[i].start, arr[i].finish);
            last = i;
        }
    }
}

int main()
{
    int n;
    printf("Enter number of activities: ");
    scanf("%d", &n);

    struct Activity arr[n];

    printf("Enter start times:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i].start);

    printf("Enter finish times:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i].finish);

    activitySelection(arr, n);

    return 0;
}