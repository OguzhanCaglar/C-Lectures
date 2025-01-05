// Write a C program to read the roll no, name and marks of three subjects and calculate the total, percentage and division.

// Output:
// Input the Roll Number of the student: 12
// Input the Name of the Student: Tom
// Input the marks of Physics, Chemistry and Computer Science: 50 60 70

// Roll No: 12
// Name Of Student: Tom
// Marks in Physics: 50
// Marks in Chemistry: 60
// Marks in Computer Science: 70
// Total Marks = 180
// Percentage = 60.00
// Division = First

#include <stdio.h>
#include <string.h>

int main()
{
    int roll_no = 0, physics = 0, chemistry = 0, computer_science = 0, total = 0;
    float percentage = 0.0;
    char name[20], division[10];

    printf("Input the Roll Number of the student: ");
    scanf("%d", &roll_no);

    printf("Input the Name of the Student: ");
    scanf("%s", name);

    printf("Input the marks of Physics, Chemistry and Computer Science: ");
    scanf("%d %d %d", &physics, &chemistry, &computer_science);

    total = physics + chemistry + computer_science;
    percentage = total / 3.0; // calculate percentage

    if(percentage >= 60)
    {
        strcpy(division, "First");
    }
    else if(percentage < 60 && percentage >= 48)
    {
        strcpy(division, "Second");
    }
    else if(percentage < 48 && percentage >= 36)
    {
        strcpy(division, "Pass");
    }
    else
    {
        strcpy(division, "Fail");
    }

    printf("\nRoll No: %d\n", roll_no);
    printf("Name Of Student: %s\n", name);
    printf("Marks in Physics: %d\n", physics);
    printf("Marks in Chemistry: %d\n", chemistry);
    printf("Marks in Computer Science: %d\n", computer_science);
    printf("Total Marks = %d\n", total);
    printf("Percentage = %.2f\n", percentage);
    printf("Division = %s\n", division);

    return 0;
}