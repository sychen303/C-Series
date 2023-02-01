#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int i, j;
int main_exit;
void menu();
struct date
{
    int month, day, year;
};
struct
{
    char name[60];
    long unsigned acc_num;
    int age;
    char address[60];
    char aadhar[12];
    double mobile;
    char acc_type[10];
    float amount;
    struct date dob;
    struct date deposit;
    struct date withdraw;
} add, update, check, delete, transaction;

float interest(float time, float amount, int rate)
{
    float SI;
    SI = (rate * time * amount) / 100.0;
    return (SI);
}

void fordelay(int j)
{
    int i, k;
    for (i = 0; i < j; i++)
        k = i;
}
void close(void)
{
    printf("\n\n\n\nBank Management System by Rishabh & Team!");
}

void new_account()
{
    int choice;
    FILE *ptr;

    ptr = fopen("database.txt", "a+");
account_no:
    system("cls");
    printf("\t\t\t\t\t\t ADD RECORD \t\t\t\t\t\t");
    printf("\n\n\nEnter today's date(mm/dd/yyyy): ");
    scanf("%d/%d/%d", &add.deposit.month, &add.deposit.day, &add.deposit.year);
    printf("\nEnter the account number (9 digits): ");
    scanf("%lu", &check.acc_num);
    while (fscanf(ptr, "%lu %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", &add.acc_num, &add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, &add.address, &add.aadhar, &add.mobile, &add.acc_type, &add.amount, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        if (check.acc_num == add.acc_num)
        {
            printf("Account Number already in use! Please enter another account number.");
            fordelay(10000000000000);
            goto account_no;
        }
    }
    add.acc_num = check.acc_num;
    printf("\nEnter name of the customer: ");
    scanf("%s", &add.name);
    printf("\nEnter date of birth(mm/dd/yyyy): ");
    scanf("%d/%d/%d", &add.dob.month, &add.dob.day, &add.dob.year);
    printf("\nEnter age: ");
    scanf("%d", &add.age);
    printf("\nEnter address: ");
    scanf("%s", add.address);
    printf("\nEnter Aadhaar Number(12 digits): ");
    scanf("%s", add.aadhar);
    printf("\nEnter the Mobile Number(10 digits): ");
    scanf("%lf", &add.mobile);
    printf("\nEnter amount to be deposited: Rs. ");
    scanf("%f", &add.amount);
    printf("\nType of account:\n\t#Savings\n\t#Current\n\t#Fixed-Deposit-1(for 1 year)\n\t#Fixed-Deposit-2(for 2 years)\n\t#Fixed-Deposit-3(for 3 years)\n\n\tEnter your choice: ");
    scanf("%s", add.acc_type);
    fprintf(ptr, "%lu %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_num, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.aadhar, add.mobile, add.acc_type, add.amount, add.deposit.month, add.deposit.day, add.deposit.year);

    fclose(ptr);
    printf("\nNew Account created successfully!");
add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to main menu and 0 to exit:");
    scanf("%d", &main_exit);
    system("cls");
    if (main_exit == 1)
        menu();
    else if (main_exit == 0)
        close();
    else
    {
        printf("\nInvalid Input!!!\a");
        goto add_invalid;
    }
}

void view_list()
{
    FILE *view;
    view = fopen("database.txt", "r");
    int test = 0;
    system("cls");
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tMOBILE\n");

    while (fscanf(view, "%lu %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_num, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.aadhar, &add.mobile, add.acc_type, &add.amount, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        printf("\n%6lu\t %10s\t\t\t%10s\t\t%.0lf", add.acc_num, add.name, add.address, add.mobile);
        test++;
    }
    fclose(view);
    if (test == 0)
    {
        system("cls");
        printf("\nNO RECORDS FOUND!!!\n");
    }
view_list_invalid:
    printf("\n\nEnter 1 to go to main menu and 0 to exit:");
    scanf("%d", &main_exit);
    system("cls");
    if (main_exit == 1)
        menu();
    else if (main_exit == 0)
        close();
    else
    {
        printf("\nInvalid Input!!!\a");
        goto view_list_invalid;
    }
}

void edit(void)
{
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("database.txt", "r");
    newrec = fopen("new.txt", "w");

    printf("\nEnter the 9 digit account number you want to make changes to: ");
    scanf("%d", &update.acc_num);
    while (fscanf(old, "%lu %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_num, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.aadhar, &add.mobile, add.acc_type, &add.amount, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        if (add.acc_num == update.acc_num)
        {
            test = 1;
            printf("\nWhat do you want to update?\n1.Address\n2.Mobile\n\nEnter your choice(1 or 2): ");
            scanf("%d", &choice);
            system("cls");
            if (choice == 1)
            {
                printf("Enter the new address: ");
                scanf("%s", update.address);
                fprintf(newrec, "%lu %s %d/%d/%d %d %s %lf %s %f %d/%d/%d\n", add.acc_num, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, update.address, add.aadhar, add.mobile, add.acc_type, add.amount, add.deposit.month, add.deposit.day, add.deposit.year);
                system("cls");
                printf("Changes saved!");
            }
            else if (choice == 2)
            {
                printf("Enter the new phone number:");
                scanf("%lf", &update.mobile);
                fprintf(newrec, "%lu %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_num, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.aadhar, update.mobile, add.acc_type, add.amount, add.deposit.month, add.deposit.day, add.deposit.year);
                system("cls");
                printf("Changes saved!");
            }
        }
        else
            fprintf(newrec, "%lu %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_num, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.aadhar, add.mobile, add.acc_type, add.amount, add.deposit.month, add.deposit.day, add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("database.txt");
    rename("new.txt", "database.txt");

    if (test != 1)
    {
        system("cls");
        printf("\nRecord not found!!\a\a\a");
    edit_invalid:
        printf("\nEnter 0 to try again, 1 to go to main menu and 0 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)

            menu();
        else if (main_exit == 2)
            close();
        else if (main_exit == 0)
            edit();
        else
        {
            printf("\nInvalid!\a");
            goto edit_invalid;
        }
    }
    else
    {
        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
            menu();
        else
            close();
    }
}

void transact(void)
{
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("database.txt", "r");
    newrec = fopen("new.txt", "w");

    printf("Enter the 9 digit account no. of the customer:");
    scanf("%d", &transaction.acc_num);
    while (fscanf(old, "%lu %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_num, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.aadhar, &add.mobile, add.acc_type, &add.amount, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {

        if (add.acc_num == transaction.acc_num)
        {
            test = 1;
            if (strcmpi(add.acc_type, "fixed1") == 0 || strcmpi(add.acc_type, "fixed2") == 0 || strcmpi(add.acc_type, "fixed3") == 0)
            {
                printf("\a\a\a\n\nCASH DEPOSIT AND WITHDRAWALS IS NOT ALLOWED IN FIXED ACCOUNTS!!!!!");
                fordelay(1000000000);
                system("cls");
                menu();
            }
            printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 or 2):");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("Enter the amount you want to deposit:Rs. ");
                scanf("%f", &transaction.amount);
                add.amount += transaction.amount;
                fprintf(newrec, "%lu %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_num, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.aadhar, add.mobile, add.acc_type, add.amount, add.deposit.month, add.deposit.day, add.deposit.year);
                printf("\n\nAmount Deposited Successfully!");
            }
            else
            {
                printf("Enter the amount you want to withdraw:Rs. ");
                scanf("%f", &transaction.amount);
                add.amount -= transaction.amount;
                fprintf(newrec, "%lu %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_num, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.aadhar, add.mobile, add.acc_type, add.amount, add.deposit.month, add.deposit.day, add.deposit.year);
                printf("\n\nAmount Withdrawn Successfully!");
            }
        }
        else
        {
            fprintf(newrec, "%lu %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_num, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.aadhar, add.mobile, add.acc_type, add.amount, add.deposit.month, add.deposit.day, add.deposit.year);
        }
    }
    fclose(old);
    fclose(newrec);
    remove("database.txt");
    rename("new.txt", "database.txt");
    if (test != 1)
    {
        printf("\n\nNo Record Found!!");
    transact_invalid:
        printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 0)
            transact();
        else if (main_exit == 1)
            menu();
        else if (main_exit == 2)
            close();
        else
        {
            printf("\nInvalid!");
            goto transact_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
            menu();
        else
            close();
    }
}
void erase(void)
{
    FILE *old, *newrec;
    int test = 0;
    old = fopen("database.txt", "r");
    newrec = fopen("new.txt", "w");
    printf("Enter the 9 digit account no. of the customer you want to delete:");
    scanf("%d", &delete.acc_num);
    while (fscanf(old, "%lu %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_num, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.aadhar, &add.mobile, add.acc_type, &add.amount, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        if (add.acc_num != delete.acc_num)
            fprintf(newrec, "%lu %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_num, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.aadhar, add.mobile, add.acc_type, add.amount, add.deposit.month, add.deposit.day, add.deposit.year);

        else
        {
            test++;
            printf("\nRecord deleted successfully!\n");
        }
    }
    fclose(old);
    fclose(newrec);
    remove("database.txt");
    rename("new.txt", "database.txt");
    if (test == 0)
    {
        printf("\nRecord not found!!\a\a\a");
    erase_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d", &main_exit);

        if (main_exit == 1)
            menu();
        else if (main_exit == 2)
            close();
        else if (main_exit == 0)
            erase();
        else
        {
            printf("\nInvalid!\a");
            goto erase_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
            menu();
        else
            close();
    }
}

void see(void)
{
    FILE *ptr;
    int test = 0, rate;
    int choice;
    float time;
    float intrst;
    ptr = fopen("database.txt", "r");
    printf("You want to check by?\n1.Account Number\n2.Name\nEnter your choice:");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("Enter the 9 digit account number:");
        scanf("%d", &check.acc_num);

        while (fscanf(ptr, "%lu %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_num, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.aadhar, &add.mobile, add.acc_type, &add.amount, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
        {
            if (add.acc_num == check.acc_num)
            {
                system("cls");
                test = 1;

                printf("\nAccount NO.:%lu\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nAadhaar No:%s \nPhone number:%.0lf \nType Of Account:%s \nAvailable Balance::Rs.  %.2f \nDate Of Deposit:%d/%d/%d\n\n", add.acc_num, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.aadhar, add.mobile,
                       add.acc_type, add.amount, add.deposit.month, add.deposit.day, add.deposit.year);
                if (strcmpi(add.acc_type, "fixed1") == 0)
                {
                    time = 1.0;
                    rate = 9;
                    intrst = interest(time, add.amount, rate);
                    printf("\n\nYou will get Rs. %.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 1);
                }
                else if (strcmpi(add.acc_type, "fixed2") == 0)
                {
                    time = 2.0;
                    rate = 11;
                    intrst = interest(time, add.amount, rate);
                    printf("\n\nYou will get Rs. .%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 2);
                }
                else if (strcmpi(add.acc_type, "fixed3") == 0)
                {
                    time = 3.0;
                    rate = 13;
                    intrst = interest(time, add.amount, rate);
                    printf("\n\nYou will get Rs. .%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 3);
                }
                else if (strcmpi(add.acc_type, "savings") == 0)
                {
                    time = (1.0 / 12.0);
                    rate = 8;
                    intrst = interest(time, add.amount, rate);
                    printf("\n\nYou will get Rs. .%.2f as interest on %d of every month", intrst, add.deposit.day);
                }
                else if (strcmpi(add.acc_type, "current") == 0)
                {

                    printf("\n\nYou will get no interest\a\a");
                }
            }
        }
    }
    else if (choice == 2)
    {
        printf("Enter the name:");
        scanf("%s", &check.name);
        while (fscanf(ptr, "%lu %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_num, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.aadhar, &add.mobile, add.acc_type, &add.amount, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
        {
            if (strcmpi(add.name, check.name) == 0)
            {
                system("cls");
                test = 1;
                printf("\nAccount No.:%lu\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nAadhaar No:%s \nPhone number:%.0lf \nType Of Account:%s \nAvailable Balance:$%.2f \nDate Of Deposit:%d/%d/%d\n\n", add.acc_num, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.aadhar, add.mobile,
                       add.acc_type, add.amount, add.deposit.month, add.deposit.day, add.deposit.year);
                if (strcmpi(add.acc_type, "fixed1") == 0)
                {
                    time = 1.0;
                    rate = 9;
                    intrst = interest(time, add.amount, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 1);
                }
                else if (strcmpi(add.acc_type, "fixed2") == 0)
                {
                    time = 2.0;
                    rate = 11;
                    intrst = interest(time, add.amount, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 2);
                }
                else if (strcmpi(add.acc_type, "fixed3") == 0)
                {
                    time = 3.0;
                    rate = 13;
                    intrst = interest(time, add.amount, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 3);
                }
                else if (strcmpi(add.acc_type, "saving") == 0)
                {
                    time = (1.0 / 12.0);
                    rate = 8;
                    intrst = interest(time, add.amount, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d of every month", intrst, add.deposit.day);
                }
                else if (strcmpi(add.acc_type, "current") == 0)
                {

                    printf("\n\nYou will get no interest\a\a");
                }
            }
        }
    }

    fclose(ptr);
    if (test != 1)
    {
        system("cls");
        printf("\nNo Records Found!!\a\a\a");
    see_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
            menu();
        else if (main_exit == 2)
            close();
        else if (main_exit == 0)
            see();
        else
        {
            system("cls");
            printf("\nInvalid!\a");
            goto see_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &main_exit);
    }
    if (main_exit == 1)
    {
        system("cls");
        menu();
    }

    else
    {

        system("cls");
        close();
    }
}

void menu(void)
{
    int choice;
    system("cls");
    system("color 02");
    printf("\n\n\t\t\tCSE-F BANK MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.CREATE NEW ACCOUNT\n\t\t2.UPDATE EXISTING ACCOUNT\n\t\t3.TRANSACTIONS\n\t\t4.DETAILS OF EXISTING ACCOUNT\n\t\t5.DELETE EXISTING ACCOUNT\n\t\t6.SHOW CUSTOMER DATABASE\n\t\t7.EXIT\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d", &choice);

    system("cls");
    switch (choice)
    {
    case 1:
        new_account();
        break;
    case 2:
        edit();
        break;
    case 3:
        transact();
        break;
    case 4:
        see();
        break;
    case 5:
        erase();
        break;
    case 6:
        view_list();
        break;
    case 7:
        close();
        break;
    }
}

int main()
{
    char pass[10], password[10] = "rishabh";
    int i = 0;
    printf("\n\n\t\tEnter your password to login:");
    scanf("%s", pass);
    if (strcmp(pass, password) == 0)
    {
        printf("\n\nACCESS GRANTED!\nLOADING");
        for (i = 0; i <= 6; i++)
        {
            fordelay(100000000);
            printf(".");
        }
        system("cls");
        menu();
    }
    else
    {
        printf("\n\nPASSWORD INCORRECT!!\a\a\a");
    login_try:
        printf("\nEnter 1 to try again and 0 to exit:");
        scanf("%d", &main_exit);
        if (main_exit == 1)
        {

            system("cls");
            main();
        }

        else if (main_exit == 0)
        {
            system("cls");
            close();
        }
        else
        {
            printf("\nInvalid!");
            fordelay(1000000000);
            system("cls");
            goto login_try;
        }
    }
    return 0;
}