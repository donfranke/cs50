#include <cs50.h>
#include <stdio.h>

// get first 2 digits of cc number
int getFirst2Digits(long input)
{
    long local = input;

    while (local >= 100)
    {
        local /= 10;
    }
    return local;
}

// get last digit of cc number
int getLastDigit(long input)
{
    return input % 10;
}

// determine card type by card number prefix
char *get_card_type(int prefix)
{
    if (prefix > 50 && prefix < 56)
    {
        return "MASTERCARD";
    }
    if (prefix == 34 || prefix == 37)
    {
        return "AMEX";
    }
    if (prefix > 39 && prefix < 50)
    {
        return "VISA";
    }
    return "INVALID";
}

// main
int main(void)
{
    long cc_num = get_long("Number: ");
    int counter = 0;
    int odd_total = 0;
    int luhn_total = 0;
    int l[30];
    string cc_num_as_string = "";

    // cc nums are at least 13 digits
    if (cc_num < 1000000000000)
    {
        printf("%s\n", "INVALID");
    }
    else
    {
        int cc_prefix = getFirst2Digits(cc_num);

        // multiply alternating digits by 2, starting with first digit
        int i = 0;
        while (cc_num != 0)
        {
            int digit = cc_num % 10;
            cc_num = cc_num / 10;

            if (counter % 2 != 0)
            {
                // multiply each digit by 2
                int times_two = digit * 2;

                // break into separate digits if more than 1 digit
                if (times_two > 9)
                {
                    int a = times_two / 10;
                    int b = times_two % 10;
                    l[i++] = a;
                    l[i] = b;
                    i++;
                }
                else
                {
                    l[i] = times_two;
                    i++;
                }
            }
            else
            {
                odd_total += digit;
            }
            counter++;
        }

        // add together single digits
        for (i = 0; i < 30; i++)
        {
            luhn_total += l[i];
        }

        // combine totals
        luhn_total += odd_total;

        // if luhn_total ends in 0, return card type
        if (luhn_total % 10 == 0)
        {
            printf("%s\n", get_card_type(cc_prefix));
        }
        else
        {
            printf("%s\n", "INVALID");
        }
    }
    return 0;
}
