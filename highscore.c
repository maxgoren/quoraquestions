/***********************************
*
*   Question: How do you implement
*   a highscore function for a game?
************************************/

#include <stdio.h>

int highscore(int player_score);

int main(int argc, char *argv[])
{
    int l;
    l = highscore(666);
    return 0;
}

int highscore(int player_score)
{
    int high_score;
    char buffer[10];
    FILE *fptr;
    fptr = fopen("score.txt", "r");
    fgets(buffer, 8, fptr);
    fclose(fptr);
    printf("eh?\n");
    high_score = atoi(&buffer);
    printf("uh..\n");
    if (player_score > high_score)
    {
        printf("Congratulations! Your Score of %d is the new High Score!\n", player_score);
        printf("Previous High Score: %d\n", high_score);
        fptr = fopen("score.txt", "w");
	fprintf(fptr, "%d", player_score);
        fclose(fptr);
    } else {
        printf("Sorry, your score of %d is lower than the High Score of %d\n\n", player_score, high_score);
    }
    return 0;
}
