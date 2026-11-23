/*Build a simple, menu-driven Personal Expense Tracker in C to help a student manage a monthly budget, 
categorize expenses (Food, Travel, Books, Entertainment), calculate total spending and remaining budget, 
identify the highest-spending category, and display a warning if the budget is exceeded.*/

#include <stdio.h>

void addExpense(float exp[]) 
{
    int category;
    float amount;
    printf("\nCategories:\n");
    printf("1. Food\n");
    printf("2. Travel\n");
    printf("3. Books\n");
    printf("4. Entertainment\n");
    printf("Select category (1-4): ");
    scanf("%d", &category);

    if (category < 1 || category > 4) 
    {
        printf("Invalid category!\n");
        return;
    }

    printf("Enter amount: ");
    scanf("%f", &amount);

    if (amount <= 0)
    {
        printf("Invalid amount!\n");
        return;
    }

    exp[category - 1] = exp[category - 1] + amount;
    printf("Expense added!\n");
}

void showSummary(float exp[], float budget) 
{
    float total = 0;
    int maxIndex = 0;
    for (int i = 0; i < 4; i++)
    {
        total = total + exp[i];
        if (exp[i] > exp[maxIndex]) 
        {
            maxIndex = i;
        }
    }
    printf("\n--- Expense Summary ---\n");
    printf("Food          : %f\n", exp[0]);
    printf("Travel        : %f\n", exp[1]);
    printf("Books         : %f\n", exp[2]);
    printf("Entertainment : %f\n", exp[3]);
    printf("-----------------------\n");
    printf("Total Spent    : \n", total);
    printf("Monthly Budget : \n", budget);

    if (total <= budget) 
    {
        printf("Remaining Budget : %f\n", budget - total);
    } 
    else 
    {
        printf("WARNING! Budget exceeded by : %f\n", total - budget);
    }

    if (total == 0) 
    {
        printf("Highest Spending : None\n");
    }
    else if (maxIndex == 0) 
    {
        printf("Highest Spending : Food (%f)\n", exp[0]);
    }
    else if (maxIndex == 1) 
    {
        printf("Highest Spending : Travel (%f)\n", exp[1]);
    }
    else if (maxIndex == 2) 
    {
        printf("Highest Spending : Books (%f)\n", exp[2]);
    } 
    else if (maxIndex == 3)
    {
        printf("Highest Spending : Entertainment (%f)\n", exp[3]);
    }
}

int main() 
{
    float budget;
    float exp[4] = {0, 0, 0, 0}; 
    int choice;

    printf("=== Personal Expense Tracker ===\n");
    printf("Enter your monthly budget: ");
    scanf("%f", &budget);

    while (budget <= 0) 
    {
        printf("Invalid! Enter budget greater than 0\n");
        printf("Enter your monthly budget: ");  
        scanf("%f", &budget);
    }
    do 
    {
        printf("\n--- Menu ---\n");
        printf("1. Add Expense\n");
        printf("2. View Summary\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                addExpense(exp);
                break;
            case 2:
                showSummary(exp, budget);
                break;
            case 3:
                printf("Exiting... Thank you!\n");
                break;
            default:
                printf("Wrong choice! Enter 1, 2 or 3.\n");
                break;
        }
    }
     while (choice != 3);

    return 0;       
}
