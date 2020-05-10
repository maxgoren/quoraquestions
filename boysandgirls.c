/******************************
 *  continuing with out answers
 *  Question: how do find out based
 *  on student input if there is
 *  more boy or girl students
 * ****************************/
#include <stdio.h>

int boysorgirls()
{
    int counter;     //for controling loops
    int class_size = 0;  //number of students in class
    int num_boys = 0, num_girls = 0;
    char gender[10]; 
    printf("how many students are in the class? ");
    scanf("%d", &class_size);
    printf("please enter 'm' for boys and 'f' for girls\n");
    for(counter = 1; counter <= class_size;counter++)
    {
        printf("Is student number %d male or female? ", counter);
        scanf("%s", gender);
        switch (gender[0])
        {
            case 'm':
                num_boys++;
                break;
            case 'f':
                num_girls++;
                break;
            default:
                printf("improper input\n");
        }
    }
    if (num_boys < num_girls)
    {
        printf("There are more girls than boys in the class\n");
        return num_girls;
    }
    if (num_boys > num_girls)
    {
        printf("There is more boys than girls in the class\n");
        return num_boys;
    }
    if (num_boys == num_girls)
    {
        printf("there is the same amount of girls as boys in the class\n");
        return 42; //even!
    }
    return 1; //if it gets to here there was an error.
}