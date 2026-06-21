#include <stdio.h>

#define NUM_STORES 10

int main() {
    int inventory[NUM_STORES];

    for (int i = 0; i < NUM_STORES; i++) {
        printf("Give value for store %d: ", i + 1);
        scanf("%d", &inventory[i]);

        while (inventory[i] < 1) {
            printf("Please enter a positive value: ");
            scanf("%d", &inventory[i]);
        }
    }

    printf("\nEnter store selections (0 to exit):\n");
    int choice;
    int transactions = 0;
    int successful_transactions = 0;
    int first_empty_store = -1;

    do {
        printf("Enter store number: ");
        scanf("%d", &choice);
        choice--;

        if (choice < 0) break;
        if (choice >= NUM_STORES) {
            printf("Invalid store number.\n");
            continue;
        }

        printf("Enter amount: ");
        int amount;
        scanf("%d", &amount);

        if (amount <= 0) {
            printf("Invalid amount.\n");
            continue;
        }

        if (inventory[choice] >= amount) {
            inventory[choice] -= amount;
            successful_transactions++;

            if (inventory[choice] == 0 && first_empty_store == -1) {
                first_empty_store = choice;
            }
        } else {
            printf("Insufficient stock. Available: %d\n", inventory[choice]);
            inventory[choice] = 0;

            if (first_empty_store == -1) {
                first_empty_store = choice;
            }
        }

        transactions++;
    } while (1);

    if (transactions > 0) {
        float success_rate = (successful_transactions / (float)transactions) * 100;
        printf("\nSuccess rate: %.2f%%\n", success_rate);
    }

    if (first_empty_store != -1) {
        printf("First depleted store: %d\n", first_empty_store + 1);
    } else {
        printf("No stores depleted.\n");
    }

    return 0;
}
