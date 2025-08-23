#include <stdio.h>

struct Item
{
    int value, weight;
};

void swap(struct Item *a, struct Item *b)
{
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}
void sortItems(struct Item arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            double r1 = (double)arr[j].value / arr[j].weight;
            double r2 = (double)arr[j + 1].value / arr[j + 1].weight;
            if (r1 < r2)
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

double fractionalKnapsack(int W, struct Item arr[], int n)
{
    sortItems(arr, n);

    double totalValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight <= W)
        {
            W -= arr[i].weight;
            totalValue += arr[i].value;
        }
        else
        {
            totalValue += arr[i].value * ((double)W / arr[i].weight);
            break;
        }
    }

    return totalValue;
}

int main()
{
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item arr[n];

    printf("Enter values of items:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].value);
    }

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].weight);
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    double maxValue = fractionalKnapsack(W, arr, n);

    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    return 0;
}