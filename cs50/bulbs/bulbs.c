#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    string message = get_string("Enter  Message ");

    for (int i = 0; i < strlen(message); i++)
    {
        int mask = 0b10000000;

        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            int bit = message[i] & mask;
            print_bulb(bit != 0);
            mask = mask >> 1;
        }
        printf("\n");
    }
    return 0;
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
