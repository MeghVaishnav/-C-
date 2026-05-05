#include <stdio.h> 
#include <string.h> 
struct Student { 
int rollNumber; 
char name[50]; 
float marks; 
}; 
int main() { 
int numStudents; 
printf("Enter the number of students: "); 
scanf("%d", &numStudents); 
struct Student students[numStudents]; // Dynamically allocate array 
//based on input 
// Get student details for each element in the array 
for (int i = 0; i < numStudents; i++) { 
printf("Enter details for student %d:\n", i + 1); 
printf("Roll Number: "); 
scanf("%d", &students[i].rollNumber); 
printf("Name: "); 
scanf(" %[^\n]", students[i].name); // Read entire name with spaces 
printf("Marks: "); 
scanf("%f", &students[i].marks); 
} 
printf("\nStudent Details:\n"); 
for (int i = 0; i < numStudents; i++) { 
printf("Student %d:\n", i + 1); 
printf("Roll Number: %d\n", students[i].rollNumber); 
printf("Name: %s\n", students[i].name); 
printf("Marks: %.2f\n", students[i].marks); 
} 
return 0; 
} 
