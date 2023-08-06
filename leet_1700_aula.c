#include <stdio.h>

int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize);
int main()
{
    printf("Hello World!\n");

    return 0;
}

int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize){
    int i, j, count = 0, square, circ, n;
    for(i = 0; i < sandwichesSize; i++){
        if(sandwiches[i] == 0){
            count++;
        }
    }
    circ = count;
    square = sandwichesSize - circ;

    for(j = 0; j < studentsSize; j++){
        if(students[j] == 0){
            circ--;
        }
        else{
            square--;
        }
    }
   

    n = circ + square;
    return n;
}
