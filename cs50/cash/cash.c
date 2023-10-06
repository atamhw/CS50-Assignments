#include <cs50.h>
#include <stdio.h>

int get_cents(void)
{
    int cents = 0;
    do
    {
        cents = get_int("How many cents do you have?");
    }
    while (cents < 0);
    return cents;
}
int calculate_quarters(int cents)
{
    int quarter = 25;
    int numQuarters = cents / quarter;
    return numQuarters;
}
int calculate_dimes(int cents)
{
    // dimes = 10 cents
    int dime = 10;
    int numDimes = cents / dime;
    return numDimes;
}

int calculate_nickels(int cents)
{
    int nickel = 5;
    int numNickels = cents / nickel;
    return numNickels;
}
int calculate_pennies(int cents)
{
    return cents;
}

int main(void)
{
    int cents = get_cents();
    // Ask how many cents the customer is owed

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

<    // Print total number of coins to give the customer
    printf("%i\n", coins);
}
