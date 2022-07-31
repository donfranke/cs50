#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
//              a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q   r  s  t  u  v  x  x  y  z
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    string word1_lower = "";

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("%s\n", "Player 1 wins!");
    }
    else if (score1 < score2)
    {
        printf("%s\n", "Player 2 wins!");
    }
    else if (score1 == score2)
    {
        printf("%s\n", "Tie!");
    }
}

int compute_score(string word)
{
    // Compute and return score for string
    char c = 'a';
    int score = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {
        c = word[i];
        if (c >= 65 && c <= 90)
        {
            c += 32;
        }
        if (c < 61 || c > 122)
        {
            c = 0;
        }
        score += POINTS[c - 97];
    }
    return score;
}