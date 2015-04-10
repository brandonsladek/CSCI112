// Import
#include <stdio.h>

// User-defined variables
#define MAX_ARRAY_SIZE 50

// Function prototypes
int populate_array( int array[] );                // Fill array with values from user
void print_array( int array[], int n );           // Print out the array values
void swap( int array[], int index1, int index2 ); // Swap two array elements
void quicksort( int array[], int low, int high ); // Sorting algorithm
int partition( int array[], int low, int high );  // Find the partition point

int main( void ) {
    
    // Declare array
    int arr[MAX_ARRAY_SIZE];
    
    // Populate array and get array size
    int n = populate_array( arr );
    
    // Print initial
    printf("\nThe initial array contains:\n");
    print_array( arr, n );
    
    // See quicksort function
    quicksort( arr, 0, n-1 );
    
    // Print final
    printf("\nThe array is now sorted:\n");
    print_array( arr, n );
    
    return 0;
} // End main


// Fill array with user input values
int populate_array( int array[] ) {
    
    // User inputs desired size of array
    int n = 1;
    
    do {
        if (n > MAX_ARRAY_SIZE) {
            printf("%d exceeds the maximum array size. Please try again.\n\n", n);
        }
        
        // Prompt user and save input to n
        printf("Enter the value of n > ");
        scanf("%d", &n);
        
    } while (n > MAX_ARRAY_SIZE);
    
    printf("Enter %d integers (positive, negative, or zero) >\n", n);
    
    int i;
    
    // Save user input values to array
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    
    return n;
} // End populate_array


// Print all the values in array with signs
void print_array( int array[], int n ) {
    
    int i;
    
    // Print values with leading sign
    for (i = 0; i < n; i++) {
        printf("%+5d\n", array[i]);
    }
} // End print_array

// Swap two values in array
void swap( int array[], int index1, int index2 ) {
    
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
} // End swap

// Perform quicksort algorithm on array
void quicksort( int array[], int low, int high ) {
    
    // Recursion bottoms out when low == high
    if (low < high) {
        
        int pivot = partition( array, low, high );
        quicksort( array, low, pivot-1 );
        quicksort( array, pivot+1, high );
    }
} // End quicksort

// Sort array elements by pivot
int partition( int array[], int low, int high ) {
    
    int pivot = array[high];
    int i = low - 1;
    int j;
    
    // Iterate through array and sort by pivot
    for (j = low; j < high; j++) {
        if ( array[j] <= pivot ) {
            i = i + 1;
            swap( array, i, j );
        }
    }
    swap( array, i + 1, high );
    
    return i + 1;
    
} // End partition

// End file
