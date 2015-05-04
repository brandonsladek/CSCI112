// Imports
#include <stdio.h>
#include <stdlib.h>

typedef struct bank_account account;

// Struct for bank account information
struct bank_account {
    char *last_name;
    char *first_name;
    int account_number;
    int checking_balance;
    int savings_balance;
    account *next;
    account *prev;
};

// Function prototypes
account *find_head( account *node );
void link_new_account( account *head, account *to_link );
account *search_list( account *head, int account_num );
void add_account( account *head );
void delete_account( account *head, account *del_node );
void print_account_info( account *acc );
void print_all_accounts( account *head );
account *search_specific( account *head, int account_num );


// Main function
int main( void ) {

    printf("\nWelcome to Sladek Ventures Bank.\n\n");
    
    // Pointer to head of linked list
    account *head;
    
    // -----------------------------------------------------
    
    // Populate linked list with five accounts...
    account *first_account;
    account *second_account;
    account *third_account;
    account *fourth_account;
    account *fifth_account;
    
    // Allocate memory for first account
    first_account = (account *) malloc( sizeof(account));
    
    // Hardcode account info
    first_account->last_name = "Sladek";
    first_account->first_name = "Brandon";
    first_account->account_number = 12345678;
    first_account->checking_balance = 2340532;
    first_account->savings_balance = 2304028;
    first_account->next = NULL;
    first_account->prev = NULL;
    
    // Update head pointer
    head = first_account;
    
    // Allocate memory for second account
    second_account = (account *) malloc( sizeof(account));
    
    // Hardcode account info
    second_account->last_name = "Jobs";
    second_account->first_name = "Steve";
    second_account->account_number = 23498022;
    second_account->checking_balance = 101;
    second_account->savings_balance = 29;
    
    // Link new account to linked list
    link_new_account( head, second_account );
    
    // Update head pointer
    head = find_head( second_account );
    
    // Allocate memory for third account
    third_account = (account *) malloc( sizeof(account));
    
    // Hardcode account info
    third_account->last_name = "Gates";
    third_account->first_name = "Bill";
    third_account->account_number = 34589230;
    third_account->checking_balance = 28;
    third_account->savings_balance = 7;
    
    // Link new account to linked list
    link_new_account( head, third_account );
    
    // Update head pointer
    head = find_head( third_account );
    
    // Allocate memory for fourth account
    fourth_account = (account *) malloc( sizeof(account));
    
    // Hardcode account info
    fourth_account->last_name = "Zuckerberg";
    fourth_account->first_name = "Mark";
    fourth_account->account_number = 40982320;
    fourth_account->checking_balance = 47;
    fourth_account->savings_balance = 1;
    
    // Link new account to linked list
    link_new_account( head, fourth_account );
    
    // Update head pointer
    head = find_head( fourth_account );
    
    // Allocate memory for fifth account
    fifth_account = (account *) malloc( sizeof(account));
    
    // Hardcode account info
    fifth_account->last_name = "Page";
    fifth_account->first_name = "Larry";
    fifth_account->account_number = 57823982;
    fifth_account->checking_balance = 84;
    fifth_account->savings_balance = 76;
    
    // Link new account to linked list
    link_new_account( head, fifth_account );
    
    // Update head pointer
    head = find_head( fifth_account );
    
    // -----------------------------------------------------
    
    // Variable for user choice from menu options
    int user_choice = 0;
    
    do {
        printf("Enter an option number below.\n\n");
    
        printf("1) CREATE new account\n");
        printf("2) SEARCH for an account\n");
        printf("3) DELETE an account\n");
        printf("4) DISPLAY all accounts\n");
        printf("5) QUIT\n");
        
        printf("\n>>> ");
        
        scanf("%d", &user_choice);
        
        // Skip this iteration of loop if user input is invalid
        if (user_choice < 1 || user_choice > 5) {
            printf("\nInvalid entry. Please try again.\n");
            continue;
        }
        
        account *acc_search;
        int acc_num = 0;
        
        // Else, switch user input
        switch( user_choice ) {
                
            case 1:
                add_account( head );
                head = find_head( first_account );
                break;
                
            case 2:
                printf("\nEnter the account number (must be 8 digits):");
                scanf("%d", &acc_num);
                acc_search = search_specific( head, acc_num );
                
                if( acc_search != NULL ) {
                    if( acc_search->account_number == acc_num ) {
                        printf("\nFOUND EXACT RESULT:\n");
                        print_account_info( acc_search );
                    } else {
                        printf("\nFOUND NEAREST RESULT:\n");
                        print_account_info( acc_search );
                    }
                }
                break;
                
            case 3:
                printf("\nEnter the account number (must be 8 digits):");
                scanf("%d", &acc_num);
                acc_search = search_specific( head, acc_num );
                delete_account( head, acc_search );
                break;
                
            case 4:
                print_all_accounts( head );
                break;
                
            case 5:
                user_choice = 5;

        } // End switch
        
    } while (user_choice != 5);
    
    printf("\nThank you for visiting Sladek Ventures Bank.\n");
    
    printf("\nGoodbye...\n");
    
} // End main


// Function to find head of linked list
account *find_head( account *node ) {
    account *n = node;
    while( n->prev != NULL ) {
        n = n->prev;
    }
    return n;
} // End find_head


// Function to link a new account to the linked list
void link_new_account( account *head, account *to_link ) {
    
    account *prev;
    account *next;
    
    // Find correct spot in linked list for second account
    prev = search_list( head, to_link->account_number );
    next = prev->next;
    
    // If account is not already in linked list
    if (next == NULL || next->account_number != to_link->account_number ) {
        
        // Add account to linked list
        prev->next = to_link;
        to_link->prev = prev;
        to_link->next = next;
        
    } else {
        printf("Account number already exists!\n");
        // Free up space allocated for new account
        free(to_link);
    }
} // End link_new_account


// Function to search linked list
account *search_list( account *head, int account_num ) {
    
    // Pointers to previous and current nodes
    account *prev;
    account *curr;
    
    // Previous starts at head of list
    prev = head;
    curr = prev->next;
    
    // Traverse until end of list or current account number is greater than search number
    while( curr != NULL && curr->account_number < account_num ) {
        prev = curr;
        curr = curr->next;
    }
    
    // Return closest account
    return prev;
    
} // End search_list


// Function to search for specific account
account *search_specific( account *head, int account_num ) {
    account *prev;
    account *curr;
    prev = head;
    curr = prev->next;
    
    while( curr != NULL && curr->account_number != account_num ) {
        prev = curr;
        curr = curr->next;
    }
    
    if( curr != NULL ) {
        return curr;
    } else {
        return prev;
    }
} // End search_specific


// Function to add a new account to the linked list
void add_account( account *head ) {
    
    account *new_account;
    
    // Allocate memory for new account
    new_account = (account *) malloc( sizeof(account));
    
    // Prompt user to input new_account info
    printf("Enter account owner last name:");
    scanf("%s", &(new_account->last_name));
    
    printf("Enter account owner first name:");
    scanf("%s", &(new_account->first_name));
    
    printf("Enter account number (8 digits):");
    scanf("%d", &(new_account->account_number));
    
    printf("Enter checking balance:");
    scanf("%d", &(new_account->checking_balance));
    
    printf("Enter savings balance:");
    scanf("%d", &(new_account->savings_balance));
    
    print_account_info(new_account);
    
    link_new_account( head, new_account );
    
} // End add_account


// Function to delete an account from the linked list
void delete_account( account *head, account *del_node ) {
    
    account *node;
    
    node = search_specific( head, del_node->account_number );
    
    // If node_to_delete is the correct node
    if (node != NULL && node->account_number == del_node->account_number) {
        // Link out node and free up memory
        node->prev->next = node->next;
        node->next->prev = node->prev;
        free(node);
    } else {
        printf("Account not found in database!\n");
    }
} // End delete_account


// Function to print out account info
void print_account_info( account *acc ) {
    printf("\nACCOUNT NUMBER: %d\n", acc->account_number);
    printf("\tName: %s, %s\n", acc->last_name, acc->first_name);
    printf("\tChecking balance: %d\n", acc->checking_balance);
    printf("\tSavings balance: %d\n", acc->savings_balance);
    printf("\n");
} // End print_account_info


// Function to print out all the accounts in the linked list
void print_all_accounts( account *head ) {
    
    account *prev;
    account *next;
    
    // Start at head of linked list
    prev = head;
    next = prev->next;
    
    // Iterate through linked list and print info for each account
    while( next != NULL ) {
        print_account_info(prev);
        
        // Update account pointers
        prev = next;
        next = next->next;
    }
    
    print_account_info(prev);
    
} // End print_all_accounts

// End file
