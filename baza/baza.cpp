#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Store
{
    int id;
    char name[20];
    float cost; // $
    float profit; // $
    int available;
};
void input(struct Store*, int*);
void output(struct Store*, int*);
void adding(struct Store*, int*);
void deleting(struct Store*, int*);
int my_strcmp(const char*, const char*);
void search(struct Store*, int*);
void save_to_file(struct Store*, int*);
void load_from_file(struct Store*, int*);

int main()
{

    int commandSwitch = 1;
    struct Store array[100];
    int len = 0;
    int* plen = &len;

    printf_s("Welcome to the Stnaknin's Store DataBase. Enjoy yourself! \n \n");
    while (commandSwitch)
    {
        printf("--------------------------------------------------\n");
        printf_s("| 1. Input                                       |\n");
        printf("--------------------------------------------------\n");
        printf_s("| 2. Output                                      | \n");
        printf("--------------------------------------------------\n");
        printf_s("| 3. Adding                                      | \n");
        printf("--------------------------------------------------\n");
        printf_s("| 4. Deleting                                    | \n");
        printf("--------------------------------------------------\n");
        printf_s("| 5. Search                                      | \n");
        printf("--------------------------------------------------\n");
        printf_s("| 6. Save to file                                | \n");
        printf("--------------------------------------------------\n");
        printf_s("| 7. Load from file                              | \n");
        printf("--------------------------------------------------\n");
        printf_s("| 0. Exit                                        | \n");
        printf("--------------------------------------------------\n");
        printf_s("Enter the number --> ");
        scanf_s(" %d", &commandSwitch);
        printf_s(" \n \n");
        switch (commandSwitch)
        {
        case 1:
            input(array, plen);
            continue;
        case 2:
            output(array, plen);
            continue;
        case 3:
            adding(array, plen);
            continue;
        case 4:
            deleting(array, plen);
            continue;
        case 5:
            search(array, plen);
            continue;
        case 6:
            save_to_file(array, plen);
            continue;
        case 7:
            load_from_file(array, plen);
            continue;
        case 0:
            printf_s("Good luck! \n");
            continue;
        default:
            printf_s("Sorry, wrong number. Try again \n");
            continue;
        }
    }
}

void input(struct Store* array, int* plen)
{

    int i = 0;
    char a;
    do {
        printf("Input the name of product (without spaces, use '_'), cost ($), profit ($) and amount in storage: \n");
        array[i].id = i + 1;
        scanf(" %s", array[i].name);
        scanf(" %f", &array[i].cost);
        scanf(" %f", &array[i].profit);
        scanf(" %d", &array[i].available);

        i++;

        printf("Do you want to continue? (y/n): \n");
        scanf(" %c", &a);
        printf("\n");

    } while (a != 'n');
    *plen = i;
}

void output(struct Store* array, int* plen)
{
    if (*plen)
    {
        printf("--------------------------------------------------\n");
        printf("| %-3s | %-8s | %-6s | %-8s | %-4s | \n", "id", "name", "cost", "profit", "available");
        printf("--------------------------------------------------\n");
        for (int i = 0; i < *plen; i++) {
            printf("| %-3d | %-8s | %-6.2f | %-8.2f | %-9d | \n", array[i].id, array[i].name, array[i].cost, array[i].profit, array[i].available);
        }
        printf("--------------------------------------------------\n");
    }
    else
    {
        printf_s("Sorry, but the database should not be empty ;-; \n");
    }
}

void adding(struct Store* array, int* plen)
{
    if (*plen)
    {
        int i = *plen;
        char a;
        do {
            printf("Input the name of product, cost ($), profit ($) and amount in storage: \n");
            array[i].id = i + 1;
            scanf(" %s", array[i].name);
            scanf(" %f", &array[i].cost);
            scanf(" %f", &array[i].profit);
            scanf(" %d", &array[i].available);

            i++;

            printf("Do you want to continue? (y/n): \n");
            scanf(" %c", &a);
            printf("\n");

        } while (a != 'n');
        *plen = i;
    }
    else
    {
        printf_s("Sorry, but the database should not be empty ;-; \n");
    }
}

void deleting(struct Store* array, int* plen)
{
    if (*plen)
    {
        int number;
        printf("Which line do you want to delete ? \n");
        scanf(" %d", &number);

        if ((number - 1) < 0 || (number - 1) > *plen)
        {
            printf_s("Enter the line number that is filled in the database ;-; \n");
        }
        else
        {
            for (int i = number - 1; i < *plen - 1; i++)
            {
                array[i + 1].id -= 1;
                array[i] = array[i + 1];
            }

            (*plen)--;
        }
    }
    else
    {
        printf_s("Sorry, but the database should not be empty ;-; \n");
    }
}

int my_strcmp(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return (int)*str1 - (int)*str2;;
}

void search(struct Store* array, int* plen)
{
    if (*plen)
    {
        int choice;
        printf("Choose the number to search: \n \n");
        printf("--------------------------------------------------\n");
        printf_s("| 1. Id                                          |\n");
        printf("--------------------------------------------------\n");
        printf_s("| 2. Name                                        | \n");
        printf("--------------------------------------------------\n");
        printf_s("| 3. Cost                                        | \n");
        printf("--------------------------------------------------\n");
        printf_s("| 4. Profit                                      | \n");
        printf("--------------------------------------------------\n");
        printf_s("| 5. Available                                   | \n");
        printf("--------------------------------------------------\n \n");
        printf("--> ");
        scanf(" %d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
        {
            int search_id;
            printf("Enter the id to search: \n");
            scanf(" %d", &search_id);
            for (int i = 0; i < *plen; i++)
            {
                if (array[i].id == search_id)
                {
                    printf("--------------------------------------------------\n");
                    printf("| %-3s | %-8s | %-6s | %-8s | %-4s | \n", "id", "name", "cost", "profit", "available");
                    printf("--------------------------------------------------\n");
                    printf("| %-3d | %-8s | %-6.2f | %-8.2f | %-9d | \n", array[i].id, array[i].name, array[i].cost, array[i].profit, array[i].available);
                    printf("--------------------------------------------------\n \n");
                }
            }
            break;
        }
        case 2:
        {
            char search_name[20];
            printf("Enter the name to search: \n");
            scanf(" %s", search_name);
            for (int i = 0; i < *plen; i++)
            {
                if (my_strcmp(array[i].name, search_name) == 0)
                {
                    printf("--------------------------------------------------\n");
                    printf("| %-3s | %-8s | %-6s | %-8s | %-4s | \n", "id", "name", "cost", "profit", "available");
                    printf("--------------------------------------------------\n");
                    printf("| %-3d | %-8s | %-6.2f | %-8.2f | %-9d | \n", array[i].id, array[i].name, array[i].cost, array[i].profit, array[i].available);
                    printf("--------------------------------------------------\n \n");
                }
            }
            break;
        }
        case 3:
        {
            float search_cost;
            printf("Enter the cost to search: \n");
            scanf(" %f", &search_cost);
            for (int i = 0; i < *plen; i++)
            {
                if (array[i].cost == search_cost)
                {
                    printf("--------------------------------------------------\n");
                    printf("| %-3s | %-8s | %-6s | %-8s | %-4s | \n", "id", "name", "cost", "profit", "available");
                    printf("--------------------------------------------------\n");
                    printf("| %-3d | %-8s | %-6.2f | %-8.2f | %-9d | \n", array[i].id, array[i].name, array[i].cost, array[i].profit, array[i].available);
                    printf("--------------------------------------------------\n \n");
                }
            }
            break;
        }
        case 4:
        {
            float search_profit;
            printf("Enter the profit to search: \n");
            scanf(" %f", &search_profit);
            for (int i = 0; i < *plen; i++)
            {
                if (array[i].profit == search_profit)
                {
                    printf("--------------------------------------------------\n");
                    printf("| %-3s | %-8s | %-6s | %-8s | %-4s | \n", "id", "name", "cost", "profit", "available");
                    printf("--------------------------------------------------\n");
                    printf("| %-3d | %-8s | %-6.2f | %-8.2f | %-9d | \n", array[i].id, array[i].name, array[i].cost, array[i].profit, array[i].available);
                    printf("--------------------------------------------------\n \n");
                }
            }
            break;
        }
        case 5:
        {
            int search_available;
            printf("Enter the available amount to search: \n");
            scanf(" %d", &search_available);
            for (int i = 0; i < *plen; i++)
            {
                if (array[i].available == search_available)
                {
                    printf("--------------------------------------------------\n");
                    printf("| %-3s | %-8s | %-6s | %-8s | %-4s | \n", "id", "name", "cost", "profit", "available");
                    printf("--------------------------------------------------\n");
                    printf("| %-3d | %-8s | %-6.2f | %-8.2f | %-9d | \n", array[i].id, array[i].name, array[i].cost, array[i].profit, array[i].available);
                    printf("--------------------------------------------------\n \n");
                }
            }
            break;
        }
        default:
            printf("Invalid choice. Please choose a valid column.\n");
            break;
        }
    }
    else
    {
        printf_s("Sorry, but the database should not be empty ;-; \n");
    }
}

void save_to_file(struct Store* array, int* plen)
{
    for (int i = 0; i < *plen; i++)
    {

        FILE* file = fopen("Database 'Stankin Store'.txt", "w");
        if (file == NULL)
        {
            printf("Sorry, but we can't open this file for writing ;-; \n");
            return;
        }

        for (int i = 0; i < *plen; i++)
        {
            fprintf(file, "%d %s %f %f %d\n", array[i].id, array[i].name, array[i].cost, array[i].profit, array[i].available);
        }

        fclose(file);
    }
    printf("File has been saved \n");
}

void load_from_file(struct Store* array, int* plen)
{
    FILE* file = fopen("Database 'Stankin Store'.txt", "r");
    if (file == NULL)
    {
        printf("Sorry, but we can't open this file for reading ;-; \n");
        return;
    }

    int i = 0;
    while (fscanf(file, "%d %s %f %f %d\n", &array[i].id, array[i].name, &array[i].cost, &array[i].profit, &array[i].available) != EOF)
    {
        i++;
    }

    *plen = i;

    fclose(file);
    printf("File has been loaded \n");
}