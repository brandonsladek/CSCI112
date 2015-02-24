// Imports
#include <stdio.h>
#include <stdbool.h>

// Function prototypes
int get_input();
boolean is_valid(int num);
void print_pattern();

// Main function
void main() {

	// Good manners
	printf("Welcome to the Lab3 program for CSCI112.");
	
	// Get user input
	int input = get_input();
	
	printf("You entered %d.", input);
	
	// Return without errors
	return(0);
}

// Read in user input, odd integer 1-9 inclusive
int get_input() {
	int input = 0;
	
	while (is_valid(input) == 0) {
	
		printf("Enter an odd number 1-9 inclusive >>> ");
        
        // Save user input to input variable
		scanf("%d", &input);
	}
	return input;
}

// Return 1 if number is valid, 0 otherwise
int is_valid(int num) {	

	if (num >= 1 && num <= 9) {
		if (num % 2 != 0) {
		printf("%d is valid.", num);
		return 1;
	}
	
  } else if (num < 1) {
  		printf("You have entered a number less than one. Please try again.");
  		return 0;
  } else if (num > 9) {
  		printf("You have entered a number greater than nine. Please try again.");
  		return 0;
  } else if (num % 2 = 0) {
  		printf("You have entered an even number. Please try again.");
  		return 0;
  } // End of is_valid function
  
  // Return false by default
  return 0;
}

void print_pattern() {}