/**********************************************************************/
// ENGR-2350 Activity-Array
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


// Add global variables here, as needed.
uint32_t array1[] = {1,2,3,4,5,6,7,8,9,10};
uint32_t array2[];
uint32_t l = 15;
uint32_t array2d[15][15];

int main(void) /* Main Function */
{
    // Add local variables here, as needed.

    // We always call the "SysInit()" first to set up the microcontroller
    // for how we are going to use it.
    SysInit();

    // Place initialization code (or run-once) code here
    uint8_t i,j;        // Two loop variables
    for(i=0;i<l;i++){  // Outer loop
        for(j=0;j<l;j++){  // Inner loop
            array2d[i][j] = rand()%21;// In here we can use i and j to loop through elements,
            // where i and j will be the row/column index of the 2d matrix
        }
    }
    // This portion prints one of the input arrays column header (horizontal)


    printf("\n\n\t");   // Move down a couple lines and skip the first "column"
    for(i=0;i<l;i++){
        printf("\t%u",i+1); // Print each element in the array, one each column (tab)
    }
    printf("\r\n"); // move to the next line to print the table

    // This portion prints the other input array as the row headers (vertical)
    // and the multiplication table (2D array)
    for(i=0;i<l;i++){
        printf("\t%u",i+1); // Print the i-th element of the input array
        for(j=0;j<l;j++){
            printf("\t%u",array2d[i][j]); // print all the elements of the i-th row for the table
        }
        printf("\r\n"); // move to next line
    }
    while(1){
        // Place code that runs continuously in here

    }
}

// Add function declarations here as needed

// Add interrupt functions last so they are easy to find
