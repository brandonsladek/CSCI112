// Import standard I/O library
#include <stdio.h>

// Function prototypes
int get_input();
int is_valid(int num);
void print_pattern();

// Main function
int main() {

	// Simple formatting
	printf("------------------------------------------------------\n");
	
	// Good manners
	printf("\nWelcome to the Lab3 program for CSCI112.\n\n");
	
	int cont = 1;
	
	while (cont == 1) {
	
		// Get user input
		int input = get_input();
	
		printf("\nYou entered %d.\n\n", input);
	
		// See function implementation
		print_pattern(input);
		
		printf("\n------------------------------------------------------\n");
		
		int answer;
		
		// Query user to loop through process again
		printf("Would you like to build a diamond with another number?\n");
		printf("Enter 1 for yes, 0 for no.\n\n");
		
		// Read in user input
		scanf("%d", &cont);
	
	} // End while loop
	
	// Good manners
	printf("\nGoodbye.\n\n");
}

// Read in user input, odd integer 1-9 inclusive
int get_input() {

	int input = 0;
	
	// Repeatedly query user until input is valid
	do {
		printf("Enter an odd number 1-9 inclusive >>> ");
        
        // Save user input to input variable
		scanf("%d", &input);
		
		// Input must be an odd integer between 1 and 9 inclusive
		if (input < 1) {
			printf("\nYou have entered a number less than 1. Please try again.\n\n");
		} else if (input > 9) {
			printf("\nYou have entered a number greater than 9. Please try again.\n\n");
		} else if (input % 2 == 0) {
			printf("\nYou have entered an even number. Please try again.\n\n");
		}
		
	// Check validity of number
	} while (is_valid(input) == 0);
	
	// Return valid input
	return input;
}

// Return 1 if number is valid, 0 otherwise
int is_valid(int num) {	

	// Number must be an odd integer between 1 and 9 inclusive
	if (num >= 1 && num <= 9) {
		if (num % 2 != 0) {
		return 1;
	}
  } 
  return 0;
  } // End of is_valid function
  
void print_pattern(int num) {

	// Print the top half of the diamond
	
	int i;
	
	for (i = 1; i <= num; i += 2) {
		printf("%*s", num - i, "");
		
		int j = 1;
		
		// While loop to print numbers
		while (j <= i) {
			printf("%d ", j);
			j++;
		}
		printf("%*s\n", num - i, "");
	} // End for loop
	
	// Print the bottom half of the diamond
	
	int z;
	
	for (z = num-2; z >= 1; z -= 2) {
		printf("%*s", num - z, "");
		
		int k = 1;
		
		// While loop to print numbers 
		while (k <= z) {
			printf("%d ", k);
			k++;
		}
		printf("%*s\n", num - z, "");
	} // End for loop
	
} // End print_pattern function

// End of file