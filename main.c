/* this is the main file from which i will
*  brach out to show concepts and examples
*  as i develope them as answers for quora.
******************************************/
#include <stdio.h>
#include "boysandgirls.c"
int basicio(); //if we want to type out our functions below main() we must first declare them up top.
int boysorgirls();
int main()
{
    int ret;          //declare an integer because basicio()'s function type is int
    ret = basicio();  // and thus returns an integer
    printf("basicio() returned %d\n", ret); //this is how you display an integers value: %d
    ret = boysorgirls();
    printf("boysorgirls() returned %d\n", ret);
    return 0;
}

int basicio()
{
    char name[50];                //we declare a character array to hold our string
    printf("What us your name? "); //this is the basic use of printf()
    scanf("%s", name);             //scanf is used for input, because we want a string
    printf("Hello %s!\n", name);   //we use %s
    return 0;                     //our function is an int and is expected to returna digit
}