#include <stdio.h>

int main()
{
    float best1 = 0.0;
    float best2 = 0.0;
    char best1_name = '?';
    char best2_name = '?';
    int athletes = 0;
    int athletes_pass = 0;

    char name;
    printf("Enter athlete name: ");
    scanf(" %c", &name);

    while (name != 'E')
    {
        int attempts = 1;
        bool pass = false;

        while (attempts < 6 && pass == false)
        {
            float attempt;
            printf("Enter %c's %dth attempt: ", name, attempts);
            scanf("%f", &attempt);

            if (attempt > 10.5)
            {
                pass = true;
                athletes_pass++;

                if (attempt > best1)
                {
                    best2 = best1;
                    best2_name = best1_name;
                    best1 = attempt;
                    best1_name = name;
                }
                else if (attempt > best2)
                {
                    best2 = attempt;
                    best2_name = name;
                }

                printf("%c passed!\n", name);
            }
            else
            {
                attempts++;
            }
        }

        if (pass == false)
        {
            printf("%c did not pass.\n", name);
        }

        athletes++;
        printf("Enter athlete name: ");
        scanf(" %c", &name);
    }

    printf("\n%c is the athlete with the best performance.\n", best1_name);
    printf("%c is the athlete with the second best performance.\n\n", best2_name);

    float percentage = (athletes_pass / (float)athletes) * 100;
    printf("%.2f percent of athletes passed.\n", percentage);

    return 0;
}
