#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

// get height from user input
// only return if certain conditions are met
int get_height(void)
{
    int height;
    char c;

    while (true)
    {
        height = get_int("Height: ");
        if (height > 0 && height < 9)
        {
            return height;
        }
    }
    return 0;
}

void print_blocks(int height)
{
    int j = 0;
    char block[10];
    // iterate rows
    for (int i = 0; i < height; i++)
    {
        // print blank spaces leading up to start of row
        for (int l = 0; l < height - i - 1; l++)
        {
            printf(" ");
        }

        for (int k = 0; k < j + 1; k++)
        {
            block[k] = '#';
        }
        // print blocks after leading spaces
        printf("%s  %s\n", block, block);
        j++;
    }
}

int main(void)
{
    int height = 0;
    height = get_height();
    print_blocks(height);
}