// Imports
#include <stdio.h>
#include <stdlib.h>

// Maximum name size constant
#define NAME_SIZE 25

// Struct for student records
typedef struct {
    int sid;                           // Student ID
    char last_name[NAME_SIZE];         // Last name char array
    char first_name[NAME_SIZE];        // First name char array
    float *list_of_grades;             // Array of float values
    float gpa;                         // Float gpa value
} student;
// End struct

// Function prototypes
student input_student_info( int num_grades );
float calculate_gpa( student stu, int num );
void print_student_info ( student *students, int num_students, int num_grades );


// Main function
int main( void ) {
    
    // Declare important variables
    int num_students;
    int num_grades;
    
    printf("Enter the number of students:> ");
    scanf("%d", &num_students);
    
    printf("Enter the number of grades to track:> ");
    scanf("%d", &num_grades);
    
    printf("\nThere are %d students.", num_students);
    printf("\nThere are %d grades.\n", num_grades);
    
    // Malloc an array of students
    student *students = (student *) malloc(num_students * sizeof(student));
    
    // Input student information
    int i;
    for (i = 0; i < num_students; i++) {
        *(students + i) = input_student_info(num_grades);
    }
    
    // Print student information
    print_student_info(students, num_students, num_grades);
    
    printf("\n");
    
}
// End main


// Function to input student information
student input_student_info( int num_grades ) {
    
    // Struct variable for student
    student student_to_update;
    
    // Pointer variable for saving info to struct
    student * p = &student_to_update;
    
    printf("\nEnter information for student:\n");
    printf("\tEnter SID:> ");
    // Save input to sid
    scanf("%d", &(p->sid));
    
    printf("\tEnter last name:> ");
    // Save input to last_name
    scanf("%s", &(p->last_name));
    
    printf("\tEnter first name:> ");
    // Save input to first_name
    scanf("%s", &(p->first_name));
    
    // Initialize an array for list of grades
    float *list_of_grades = malloc(num_grades * sizeof(float));
    
    printf("\tEnter grades (separated by space):> ");
    
    // Save list of grades
    int i;
    for(i = 0; i < num_grades; i++) {
        scanf("%f", &*(list_of_grades + i));
    }
    
    // Save array to student struct grades array
    student_to_update.list_of_grades = list_of_grades;
    
    // Calculate gpa and save it to student struct gpa
    float gpa = calculate_gpa( student_to_update, num_grades );
    student_to_update.gpa = gpa;
    
    // Return student struct
    return student_to_update;
    
}
// End input_student_info


// Function to calculate gpa
float calculate_gpa( student stu, int num ) {
    
    // Declare variables
    float total_grade_sum = 0.0;
    float gpa;
    
    // Calculate grade sum
    int i;
    for(int i = 0; i < num; i++) {
        total_grade_sum = total_grade_sum + stu.list_of_grades[i];
    }
    
    // Calculate gpa as average of all grades
    gpa = total_grade_sum / num;
    
    // Return gpa
    return gpa;
}
// End calculate_gpa

// Function to print student information
void print_student_info ( student *students, int num_students, int num_grades ) {
    
    int i;
    for (i = 0; i < num_students; i++) {
        
        // Select student from students array
        student current_student = *(students + i);
        
        // Give one extra space if first student
        if (i == 0) {
        printf("\n\nStudent ID #%d:", current_student.sid);
        } else {
            printf("\nStudent ID #%d:", current_student.sid);
        }
        printf("\n\tName:\t %s %s", current_student.first_name, current_student.last_name);
        printf("\n\tGrades:\t ");
        
        // Print list of student's grades
        int j;
        for (j = 0; j < num_grades; j++) {
            printf("%.1f ", current_student.list_of_grades[j]);
        }
        
        printf("\n\tGPA:\t %.2f", current_student.gpa);
    }
}
// End print_student_info

// End file
