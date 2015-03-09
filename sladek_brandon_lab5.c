// Imports
#include <stdio.h>
#include <math.h>

// Variable declarations
int user_choice;
float position_initial;
float position_final;
float velocity_initial;
float velocity_final;
float acceleration;
float time;
	
// Function prototypes
int user_menu();
void equation1(float *);
void equation2(float *);
void equation3(float *);
void equation4(float *);

float get_position_initial(void);
float get_position_final(void);
float get_velocity_initial(void);
float get_velocity_final(void);
float get_acceleration(void);
float get_time(void);

// Main function
int main (void) {
	
	// Good manners
	printf("\nWelcome to the MOTION EQUATION CALCULATOR\n\n");
	
	do {
		// Get user input
		user_choice = user_menu();
		
		// Final result variable and pointer
		float result;
		float *r;
		r = &result;
		
		// Transfer control based on user input
		switch (user_choice) {
			case 1:
				equation1(r);
				printf("Your result is %.4f.\n\n", result);
				break;
			case 2:
				equation2(r);
				printf("Your result is %.4f.\n\n", result);
				break;
			case 3:
				equation3(r);
				printf("Your result is %.4f.\n\n", result);
				break;
			case 4:
				equation4(r);
				printf("Your result is %.4f.\n\n", result);
				break;
			case 5:
				// Good manners
				printf("Thank you for using the MOTION EQUATION CALCULATOR. Goodbye.\n");
				return 0;
				break;
		}
	} while (user_choice != 5);
	
	return 0;
} // End of main function

// Prompt user to select which equation to compute, or quit
int user_menu(void) {

	// For invalid entry checking purposes
	user_choice = 1;
	
	do {
		// Check if user input is invalid
		if (user_choice < 1 || user_choice > 5) {
			printf("Invalid option. Please try again.\n\n");
		}
		printf("Choose a motion equation 1-4 or choose 5 to QUIT > ");
		// Save user input to user_choice variable
		scanf("%d", &user_choice);
		
	} while (user_choice < 1 || user_choice > 5);
	
// Return user input
return user_choice;		
} // End of user_menu function

// Compute first equation
void equation1(float *answer) {

	// Determine variables by user input
	float velocity_initial = get_velocity_initial();
	float acceleration = get_acceleration();
	float time = get_time();
	
	// Compute equation
	float velocity_final = velocity_initial + acceleration * time;
	
	// Save value to pointer argument
	*answer = velocity_final;
	
} // End of equation1 function

// Compute second equation
void equation2(float *answer) {

	// Determine variables by user input
	float position_initial = get_position_initial();
	float velocity_initial = get_velocity_initial();
	float time = get_time();
	float acceleration = get_acceleration();
	
	// Compute equation
	float position_final = position_initial + (velocity_initial * time) + (0.5 * acceleration * powf(time, 2));
	
	// Save value to pointer argument
	*answer = position_final;
	
} // End of equation2 function

// Compute third equation
void equation3(float *answer) {
	
	// Determine variables by user input
	float velocity_initial = get_velocity_initial();
	float acceleration = get_acceleration();
	float position_final = get_position_final();
	float position_initial = get_position_initial();
	
	// Compute equation
	float velocity_final = sqrt(powf(velocity_initial, 2) + 2 * (acceleration * (position_final - position_initial)));
	
	// Save value to pointer argument
	*answer = velocity_final;
	
} // End of equation3 function

// Compute fourth equation
void equation4(float *answer) {
	
	// Determine variables by user input
	float position_initial = get_position_initial();
	float velocity_final = get_velocity_final();
	float velocity_initial = get_velocity_initial();
	float time = get_time();
	
	// Compute equation
	float position_final = position_initial + (0.5 * (velocity_final + velocity_initial) * time);
	
	// Save value to pointer argument
	*answer = position_final;
	
} // End of equation4 function

// Prompt user for initial position
float get_position_initial(void) {
	printf("\tEnter initial position > ");
	scanf("%f", &position_initial);
}

// Prompt user for final position
float get_position_final(void) {
	printf("\tEnter final position > ");
	scanf("%f", &position_final);
}

// Prompt user for initial velocity
float get_velocity_initial(void) {
	printf("\tEnter initial velocity > ");
	scanf("%f", &velocity_initial);
}

// Prompt user for final velocity
float get_velocity_final(void) {
	printf("\tEnter final velocity > ");
	scanf("%f", &velocity_final);
}

// Prompt user for acceleration
float get_acceleration(void) {
	printf("\tEnter acceleration > ");
	scanf("%f", &acceleration);
}

// Prompt user for time
float get_time(void) {
	printf("\tEnter time > ");
	scanf("%f", &time);
}