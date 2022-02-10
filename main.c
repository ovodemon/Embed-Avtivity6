/**********************************************************************/
// ENGR-2350 Activity-Structs
// Name: Yijia Zhou
// RIN: 661995479
// This is the base project for several activities and labs throughout
// the course.  The outline provided below isn't necessarily *required*
// by a C program; however, this format is required within ENGR-2350
// to ease debugging/grading by the staff.
/**********************************************************************/

// We'll always add this include statement. This basically takes the
// code contained within the "engr_2350_msp432.h" file and adds it here.
#include "engr2350_msp432.h"

// Add function prototypes here, as needed.

// This is one implementation for creating a custom struct variable type named "homework_t"
typedef struct _homework_t {
    float average;      // The struct has a "field" for each value listed
    float stdev;        // in the "Homework Gradebook" table.
    uint8_t min;        // Note that the fields can be all different types
    uint8_t max;
    uint16_t subs;
}homework_t;

// Prototype. Add above main function, below the homework_t definition.
float remove_min_from_avg(homework_t *homework);

// Declaration. Add below main function
// This function calculates the average of a homework without the minimum grade.
// The function will return the value of the new average.
float remove_min_from_avg(homework_t *homework){
    float homework_sum = homework->average*homework->subs;
    homework_sum -= homework->min;
    return homework_sum/(homework->subs-1);
}

// Add global variables here, as needed.
homework_t homework;
homework_t array[5];

int main(void) /* Main Function */
{
    // Add local variables here, as needed.
//    homework.average = 94.2;
//    homework.stdev = 10.8;
//    homework.min = 55;
//    homework.max = 100;
//    homework.subs = 109;
    struct _homework_t homework = {94.2,10.8,55,100,109};
//    struct _homework_t homework_2 = {76.7,12.6,40,100,106};
//    struct _homework_t homework_3 = {84.5,15.9,25,100,101};
//    struct _homework_t homework_4 = {92.1,12.6,45,100,99};
//    struct _homework_t homework_5 = {66.3,27.3,10,100,99};
    array[0].average = 94.2;
    array[0].stdev = 10.8;
    array[0].min = 55;
    array[0].max = 100;
    array[0].subs = 109;
    array[1].average = 76.7;
    array[1].stdev = 12.6;
    array[1].min = 40;
    array[1].max = 100;
    array[1].subs = 106;
    array[2].average = 84.5;
    array[2].stdev = 15.9;
    array[2].min = 25;
    array[2].max = 100;
    array[2].subs = 101;
    array[3].average = 92.1;
    array[3].stdev = 12.6;
    array[3].min = 45;
    array[3].max = 100;
    array[3].subs = 99;
    array[4].average = 66.3;
    array[4].stdev = 27.3;
    array[4].min = 10;
    array[4].max = 100;
    array[4].subs = 99;


    // We always call the "SysInit()" first to set up the microcontroller
    // for how we are going to use it.
    SysInit();

    // Place initialization code (or run-once) code here
    printf("Homework 1 Stats\r\n"
           "    Average: %.2f\r\n"
           "  Std. Dev.: %.2f\r\n"
           "    Minimum: %u\r\n"
           "    Maximum: %u\r\n"
           "Submissions: %u\r\n",
           homework.average,homework.stdev,homework.min,
           homework.max,homework.subs);
    printf("\r\n");

    uint8_t i;
    for (i=0;i<5;i++){
        printf("Homework %u Stats\r\n"
                   "    Average: %.2f\r\n"
                   "  Std. Dev.: %.2f\r\n"
                   "    Minimum: %u\r\n"
                   "    Maximum: %u\r\n"
                   "Submissions: %u\r\n",
                   i+1,array[i].average,array[i].stdev,array[i].min,
                   array[i].max,array[i].subs);
    }
    printf("\r\n");

    float bar = remove_min_from_avg(&homework);
    printf("Homework 1 average without the minimum grade: %.2f\r\n",bar);

    printf("\r\n");

    for (i=0;i<5;i++){
        float bar = remove_min_from_avg(&array[i]);
        printf("Homework %u average without the minimum grade: %.2f\r\n",i+1,bar);
    }
    printf("\r\n");

    while(1){
        // Place code that runs continuously in here

    }
}

// Add function declarations here as needed

// Add interrupt functions last so they are easy to find
