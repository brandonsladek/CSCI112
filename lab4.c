// Imports
#include <stdio.h>
#include <math.h>

// User-defined type definitions
#define PI 3.14159
#define LOOP_LIMIT 90

// Function prototypes
void sine();
void cosine();
void tangent();

// Enumeration for user menu options
typedef enum {
	SIN,
	COS,
	TAN,
	QUIT
} menu_t;

// Main function
int main() {

	// Option that user chooses
	menu_t chosen_option;
	
	// User control loop
	do {
		// Prompt user to pick option
		printf("\nPlease choose an option: (0) Sine (1) Cosine (2) Tangent (3) QUIT\n");
		printf("Enter your choice > ");
	
		// Read in user input to menu_t variable
		scanf("%d", &chosen_option);
		
		// Execute different functions based on user input
		switch (chosen_option) {
	
			case SIN:
				// See sine function implementation
				sine();
				break;
				
			case COS:
				// See cosine function implementation
				cosine();
				break;
				
			case TAN:
				// See tangent function implementation
				tangent();
				break;
				
			case QUIT:
				// Good manners
				printf("You chose QUIT. Thank you, come again!\n");
				break;
				
			default:
				// Notify user of invalid entry
				printf("%d is an invalid option. Please try again.\n", chosen_option);
				break;
			
		} // End of switch statement
		
	// Continuously loop until user wants to quit
	} while (chosen_option != QUIT);
	
} // End of main function

// Compute sine
void sine() {

	// Variable declarations for for loop
	int i;
	double rad;
	
	// Print out sine values
	for (i = 0; i <= LOOP_LIMIT; i += 15) {
	
		rad = (i * PI) / 180;
		printf("\tsin(%d) = %.4f\n", i, sin(rad));
		
	} // End for loop
	
} // End of sine function

// Compute cosine
void cosine() {

	// Variable declarations for for loop
	int i;
	double rad;
	
	// Print out cosine values
	for (i = 0; i <= LOOP_LIMIT; i += 15) {
	
		rad = (i * PI) / 180;
		printf("\tcos(%d) = %.4f\n", i, cos(rad));
		
	} // End for loop
} // End of cosine function

// Compute tangent
void tangent() {
	
	// Variable declarations for for loop
	int i;
	double rad;
	
	// Print out tangent values
	for (i = 0; i <= LOOP_LIMIT; i += 15) {
	
		rad = (i * PI) / 180;
		
		// Tangent of 90 and 270 is undefined
		if (i == 90 || i == 270) {
			printf("\ttan(%d) is UNDEFINED\n", i);
		} else {
			printf("\ttan(%d) = %.4f\n", i, tan(rad));
		}
		
	} // End for loop
} // End of tangent function

// End of file