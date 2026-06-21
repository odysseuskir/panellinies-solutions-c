#include <stdio.h>

#define NUM_MODELS 5
#define DAYS 5

float calc_average(int consumption[NUM_MODELS][DAYS], const int i)
{
    int sum = 0;
    for (int j = 0; j < DAYS; j++)
    {
        sum = sum + consumption[i][j];
    }
    const float average = (float)sum / DAYS;
    return average;
}

int main()
{
    char name[NUM_MODELS];
    int consumption[NUM_MODELS][DAYS];

    for (int i = 0; i < NUM_MODELS; i++)
    {
        printf("Give name of model %d: ", i + 1);
        scanf(" %c", &name[i]);
        for (int j = 0; j < DAYS; j++)
        {
            printf("Give consumption of model %d during day %d: ", i + 1, j + 1);
            scanf("%d", &consumption[i][j]);
            while (consumption[i][j] < 1)
            {
                printf("Error - Consumption needs to be positive integer: ");
                scanf("%d", &consumption[i][j]);
            }
        }
    }

    float average[NUM_MODELS];
    for (int i = 0; i < NUM_MODELS; i++)
    {
        average[i] = calc_average(consumption, i);
    }

    bool stop = false;
    char key;
    printf("Enter model name to look up: ");
    scanf(" %c", &key);
    int i = 0;
    int min_j = 0;

    while (i < NUM_MODELS && stop == false)
    {
        if (name[i] == key)
        {
            stop = true;
            min_j = 0;
            int min_consumption = consumption[i][0];

            for (int j = 1; j < DAYS; j++)
            {
                if (consumption[i][j] < min_consumption)
                {
                    min_j = j;
                    min_consumption = consumption[i][j];
                }
            }
        }
        else
        {
            i++;
        }
    }

    if (stop == false)
    {
        printf("Model not found\n");
    }
    else
    {
        printf("Model found. %d is the day with the least consumption.\n", min_j + 1);
    }

    for (i = 0; i < NUM_MODELS - 1; i++)
    {
        for (int j = 0; j < NUM_MODELS - i - 1; j++)
        {
            if (average[j] < average[j + 1])
            {
                float temp = average[j];
                average[j] = average[j + 1];
                average[j + 1] = temp;

                char temp_n = name[j];
                name[j] = name[j + 1];
                name[j + 1] = temp_n;
            }
        }
    }

    for (i = 0; i < NUM_MODELS; i++)
    {
        printf("%c\n", name[i]);
    }

    return 0;
}
