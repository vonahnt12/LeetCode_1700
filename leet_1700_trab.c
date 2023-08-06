#include <stdio.h>
#include <stdlib.h>

int countStudents( int* students, int studentsSize, int* sandwiches, int sandwichesSizes );
int* RemoveElement( int* elements, int elementsSize );

int main()
{
    int *students, *sandwiches, stu[4] = {1,1,0,0}, san[4] = {0,1,0,1};
    int stusize = 4, sandsize = 4, num;

    students = ( int* ) malloc( stusize * sizeof( int ) );
    sandwiches = ( int* ) malloc( sandsize * sizeof( int ) );
    for( int i = 0; i < stusize; i++ ) {
        students[i] = stu[i];
        sandwiches[i] = san[i];
    }

    
    num = countStudents( students, stusize, sandwiches, sandsize );
    
    printf( "%d", num );
    

    return 0;
}

int countStudents( int* students, int studentsSize, int* sandwiches, int sandwichesSize ) {
    int moves = 0;
    while( moves < studentsSize && studentsSize > 0 ) {
        if( students[0] == sandwiches[0] ) {
            students = RemoveElement( students, studentsSize );
            sandwiches = RemoveElement( sandwiches, studentsSize );
            studentsSize--;
            moves = 0;
        } else {
            int firsStudent = students[0];
            for( int i = 0; i < studentsSize - 1; i++ ) {
                students[i] = students[i + 1];
            }
            students[studentsSize - 1] = firsStudent;
            moves++;
        }
    }
    
    return studentsSize;
}

int* RemoveElement( int* elements, int elementsSize ) {
    for( int i = 0; i < elementsSize - 1; i++ ) {
        elements[i] = elements[i + 1];
    }
    elements = ( int* )realloc( elements, ( elementsSize - 1 ) * sizeof( int* ) );
    return elements;

}