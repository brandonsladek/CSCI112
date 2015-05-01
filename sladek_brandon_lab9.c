// Imports
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defined constants
#define LINE_SIZE 100

// Global variable for CSV file delimiter
const char delim[2] = ",";

// Function prototypes
void read_merge_write( FILE *f1, FILE *f2, FILE *f3 );
void find_element( char *input );


// Main function
int main ( int argc, char *argv[] ) {
    
    // File pointers
    FILE *elements_file1;
    FILE *elements_file2;
    FILE *elements;
    
    // Open files
    elements_file1 = fopen("elements_file1.csv", "r");
    elements_file2 = fopen("elements_file2.csv", "r");
    elements = fopen("elements.csv", "w");
    
    // Check if files opened correctly
    if ( elements_file1 == NULL || elements_file2 == NULL || elements == NULL ) {
        printf("Error loading files...\n");
        exit(1); // Exit with an error
    }
    
    // See function implementation
    read_merge_write( elements_file1, elements_file2, elements );
    
    // Close files
    fclose(elements_file1);
    fclose(elements_file2);
    fclose(elements);
    
    int i;
    
    // Iterate through arguments
    for (i = 1; i < argc; i++) {
        // See function implementation
        find_element(argv[i]);
    }
    
} // End main


// Function to read two files, merge them, and write to third file
void read_merge_write( FILE *f1, FILE *f2, FILE *f3 ) {
    
    // Strings to hold current lines in first two files
    char current_content_f1[LINE_SIZE];
    char current_content_f2[LINE_SIZE];
    
    // Copies of previous two string variables to hold copies of those variables
    char current_content_f1_COPY[LINE_SIZE];
    char current_content_f2_COPY[LINE_SIZE];
    
    // Save line content to current_content variables
    fgets( current_content_f1, LINE_SIZE, f1 );
    fgets( current_content_f2, LINE_SIZE, f2 );
        
    // Copy the strings to copy variables
    strcpy( current_content_f1_COPY, current_content_f1 );
    strcpy( current_content_f2_COPY, current_content_f2 );
    
    // Loop through files until end of file is found in one of them
    while ( feof(f1) != 1 && feof(f2) != 1 ) {
        
        // Declare two string variables for atomic numbers
        char *atomic_number_1_STRING;
        char *atomic_number_2_STRING;
        
        // Get atomic numbers from file lines (first token of each line)
        atomic_number_1_STRING = strtok( current_content_f1, delim );
        atomic_number_2_STRING = strtok( current_content_f2, delim );
        
        // Declare two int variables for atomic numbers
        int atomic_number_1;
        int atomic_number_2;
        
        // Convert string variables to integers
        atomic_number_1 = atoi( atomic_number_1_STRING );
        atomic_number_2 = atoi( atomic_number_2_STRING );
        
        if ( atomic_number_1 < atomic_number_2 ) {
            // Print line to output file
            fprintf( f3, "%s", current_content_f1_COPY );
            // Reset line string variable
            current_content_f1[0] = '\0';
            // Get next line
            fgets( current_content_f1, LINE_SIZE, f1 );
            // Copy next line to copy line string variable
            strcpy( current_content_f1_COPY, current_content_f1 );
        } else {
            // Do same as above except with the second file
            fprintf( f3, "%s", current_content_f2_COPY );
            current_content_f2[0] = '\0';
            fgets( current_content_f2, LINE_SIZE, f2 );
            strcpy( current_content_f2_COPY, current_content_f2 );
        }
    } // End while
    
    // If the first file is the exhausted one
    if ( feof(f1) ) {
        // Iterate through rest of second file
        while ( feof(f2) != 1 ) {
            fgets( current_content_f2, LINE_SIZE, f2 );
            fprintf( f3, "%s", current_content_f2 );
        }
    } else {
        // Otherwise, iterate through rest of first file
        while ( feof(f1) != 1 ) {
            fgets( current_content_f1, LINE_SIZE, f1 );
            fprintf( f3, "%s", current_content_f1 );
        }
    }
    
    printf("\nFile merging complete.\n\n");
    
} // End read_merge_write


// Finds an element and prints its information
void find_element( char *input ) {
    
    // File pointer
    FILE *file;
    
    // Open elements.csv file as read only
    file = fopen( "elements.csv", "r" );
    
    // Check if file opened correctly
    if (file == NULL) {
        printf("Error loading elements.csv file...\n");
        exit(1); // Exit with an error
    }
    
    // String to hold current line in file
    char current_content[LINE_SIZE];
    
    // Copy of previous string variable
    char current_content_COPY[LINE_SIZE];
    
    // String declarations for element information
    char *atomic_number;
    char *atomic_weight;
    char *element_name;
    char *element_symbol;
    char *year_discovered;
    char *element_category;
    
    // Iterate through file
    while ( feof(file) != 1 ) {
        
        // Skip the line if it is null
        if ( fgets( current_content, LINE_SIZE, file ) == NULL ) {
            continue;
        }
        
        // Copy line to copy variable
        strcpy( current_content_COPY, current_content );
        
        // Save line tokens to element information variables
        atomic_number = strtok( current_content_COPY, delim );
        atomic_weight = strtok( NULL, delim );
        element_name = strtok( NULL, delim );
        element_symbol = strtok( NULL, delim );
        year_discovered = strtok( NULL, delim );
        element_category = strtok( NULL, delim );
        
        // If the element's symbol matches the input symbol
        if ( strcmp( element_symbol, input ) == 0 ) {
            // Print the element's information
            printf("Element: %s\n", element_name);
            printf(" Symbol: %s\n", element_symbol);
            printf(" Atomic Number: %s\n", atomic_number);
            printf(" Atomic Weight: %s\n", atomic_weight);
            
            // If the year the element was discovered is not ancient, print the year
            if ( strcmp( year_discovered, "ancient" ) != 0 ) {
                printf(" Discovered in: %s\n", year_discovered);
            }
            
            printf("\n");
            
            // Break out of loop to end function
            break;
        } // End double if
        
        // Reset line string variable
        current_content[0] = '\0';
        
    } // End while
    
    // Close file
    fclose(file);
    
} // End find_element


// End file
