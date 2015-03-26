// Imports
#include <stdio.h>

// Function prototypes
int calculate_odd_positions(int arr[]);
int calculate_even_positions(int arr[]);
int calculate_check_digit(int sum);
int check_match(int check_digit, int final_digit);

// Main function
int main(void) {
	
	// Array to hold bar code digits
	int bar_code[12];
	
	// Char array for user input
	char input[30];
	
	// Variable for do-while loop
	int user_choice;
	
	// Loop while user wants to check another bar code
	do {
	
		// Prompt user for input
		printf("\nEnter a bar code to check. Separate digits with a space >\n");
	
		// Save user input to input variable (all characters until newline)
		scanf(" %[^\n]", &input);
	
		// Display user input
		printf("\nYou entered the code: %s\n", input);
	
		int i;
		int j = 0;
	
		// Loop through char array, fill bar_code array with integers
		for (i = 0; i < 30; i++) {
			// If value is an integer, convert input to integer and put in bar_code array
			if (input[i] >= 48 && input[i] <= 57) {
				bar_code[j] = input[i] - '0';
				j += 1;
			}
		}
		
		// Integer variables for each step of algorithm
		int step_1;
		int step_2;
		int step_3;
		int step_4;
		int step_5;
	
		// Do step 1
		step_1 = calculate_odd_positions(bar_code);
		printf("STEP 1: Sum of odds times 3 is %d\n", step_1);
	
		// Do step 2
		step_2 = calculate_even_positions(bar_code);
		printf("STEP 2: Sum of the even digits is %d\n", step_2);
	
		// Do step 3
		step_3 = step_1 + step_2;
		printf("STEP 3: Total sum is %d\n", step_3);
	
		// Do step 4
		step_4 = calculate_check_digit(step_3);
		printf("STEP 4: Calculated check digit is %d\n", step_4);
	
		// Do step 5
		step_5 = check_match(step_4, bar_code[11]);
		if (step_5 == 1) {
			printf("STEP 5: Check digit and last digit match\nBarcode is VALID.\n");
		} else {
			printf("STEP 5: Check digit and last digit do NOT match\nBarcode is INVALID.\n");
		}
	
		// Prompt user to continue do-while loop or quit
		printf("\nWould you like to check another bar code? (1 for yes, 0 for no) >\n");
		scanf("%d", &user_choice);
	
	// Continue do-while loop if user doesn't enter 0
	} while (user_choice != 0);
	
	// Good manners
	printf("\nGoodbye.\n");
	
	// End
	return 0;
}

// Calculate the sum of the digits in the odd-numbered positions and multiply by three
int calculate_odd_positions(int arr[]) { 

	int sum = 0;
	int i;
	
	// Iterate through array and calculate correct sum 
	for (i = 0; i < 12; i+=2) {
		sum = sum + arr[i];
	}
	
	// Multiply sum by 3
	sum = sum * 3;
	
	return sum;
}

// Calculate the sum of the digits in the even-numbered positions
int calculate_even_positions(int arr[]) {

	int sum = 0;
	int i;
	
	// Iterate through array and calculate correct sum
	for (i = 1; i < 11; i+=2) {
		sum = sum + arr[i];
	}
	
	return sum;
}

// Calculate the check digit
int calculate_check_digit(int sum) { 

	int final_digit;
	int check_digit;
	
	// Extract last digit of sum
	final_digit = sum % 10;
	
	// Compute check digit
	if (final_digit == 0) {
		check_digit = 0;
	} else {
		check_digit = 10 - final_digit;
	}
	
	return check_digit;
}

// Check if check digit matches last digit of bar code
int check_match(int check_digit, int final_digit) {

	// Return true if they match
	if (check_digit == final_digit) {
		return 1;
	} else {
		return 0;
	}
}

// End of file