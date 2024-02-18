#include<stdio.h>   /// include standard input/output library
#include<string.h>  /// include string manipulation library
#include<time.h>    /// include time library
#include<stdlib.h> /// include standard library
#include<ctype.h>   /// library contains functions  prototype for string manipulation for testing and mapping characters
#define PASSWORD "wallacetrixie17112"
#define USERNAME "Trixie"
struct details
{
    char name[100];    /// define a structure for user details
};

void encrypt(char* message, int key) /// function to encrypt a message
{
    int i=0;  ///initializing counter variable
    while(message[i]!='\0')   /// loop through message string until the end
    {
        if(message[i]>='a' && message[i]<='z') /// checks if character is a lowercase letter
        {
            message[i]=(message[i]-'a'+key)%26+'a'; /// encrypts lowercase letter with a key
        }
        else if(message[i]>='A' && message[i]<='Z') ///checks if character is an uppercase letter
        {
            message[i]=(message[i]-'A'+key)%26+'A'; ///encrypts the uppercase character with a key
        }
        i++;    /// increments the counter variable
    }
}

///function to decrypt the password
    void decrypt(char* message, int key)
    {
        encrypt(message,26-key); ///reversing the encryption function
    }
/// function to check if password is weak or strong
int isPasswordStrong(char password[])
{
    int len=strlen(password);
    int hasUpperCase = 0;
    int hasLowerCase = 0;
    int hasDigit = 0;
    int hasSpecialChar = 0;
    
      /// Check each character in the password
    for(int i=0; i<len; i++) 
    {
        char c = password[i];
        if(isupper(c)) 
        {
            hasUpperCase = 1;
        } 
        else if(islower(c)) 
        {
            hasLowerCase = 1;
        } 
        else if(isdigit(c)) 
        {
            hasDigit = 1;
        } 
        else 
        {
            hasSpecialChar = 1;
        }
    }

    /// Check if the password meets the strength requirements
    if(len >= 8 && hasUpperCase && hasLowerCase && hasDigit && hasSpecialChar) 
        {
        return 1; /// Strong password
        } 
    else 
      {
        return 0; /// Weak password
      }
}

int main()
{
    int key;
    char message[1000];
    int choice;
    while(1==1)
    {
        printf("Choose 1 for encryption and decryption:\n");
        printf("Choose 2 for viewing sample accounts:\n");
        printf("Chose 3 for generating passwords:\n");
        printf("Chose 4 for creating a user account:\n");      ///prints menu option
        printf("Chose 5 for user account authentication:\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        getchar(); /// consume the newline character left in the input buffer
        
        switch (choice)
        {
            case 1: 
            {
                printf("Enter a message to encrypt:\n"); ///prompts the user to enter message to encrypt
                fgets(message, 1000, stdin);
                printf("Enter a key (0-26):\n");
                scanf("%d",&key);
                if(key>26||key<1)        ///condition to check the range of the key
                {
                    printf("Out of range,key must be between 0 and 26:");
                    return 0;   ///program terminates if key is out of range
                }
                else
                {
                    
                encrypt(message, key);
                printf("The encrypted message is: %s\n", message);

                decrypt(message, key);
                printf("The decrypted message is: %s\n", message);
                }
                break;
            }
            case 2: 
            {
                struct details account1;
                struct details account2;          ///declares user account structure
                struct details account3;
                struct details account4;
                struct details account5;

                strcpy(account1.name, "Lucy angel");
                strcpy(account2.name, "Marion kim");
                strcpy(account3.name, "Virginia Maya");   ///initializes user account names
                strcpy(account4.name, "John Paul");
                strcpy(account5.name, "Steven Seagal");

                char domain[15] = "@hotmail.com";

                strcat(account1.name, domain);
                strcat(account2.name, domain);
                strcat(account3.name, domain);    ///appends the user account names with domain
                strcat(account4.name, domain);   
                strcat(account5.name, domain);

                printf("Sample account is: %s\n", account1.name);
                printf("Sample account is: %s\n", account2.name);
                printf("Sample account is: %s\n", account3.name); ///prints sample user accounts
                printf("Sample account is: %s\n", account4.name);
                printf("Sample account is:%s\n",account5.name);
                
                ///Open a file named "sample_accounts.txt" in read mode
                
                 FILE *fp;
                 fp = fopen("sample_accounts.txt", "r");
                 
                /// If the file doesn't exist, print an error message and return 0
                 if(fp == NULL)
            {
                 printf("Failed to create file\n");
                 return 0;
            }
                        /// Write the names of 5 sample accounts to the file using fprintf()
                         fprintf(fp, "Sample account is: %s\n", account1.name);
                         fprintf(fp, "Sample account is: %s\n", account2.name);
                         fprintf(fp, "Sample account is: %s\n", account3.name);
                         fprintf(fp, "Sample account is: %s\n", account4.name);
                         fprintf(fp, "Sample account is: %s\n", account5.name);
                         fclose(fp);
                        printf("Sample accounts saved to file 'sample accounts.txt'\n");

                  break;

            }

            case 3: 
            {
                /// Declaration of variables
                char names[100][50];
                int number_of_accounts;
                char *symbols = "!@#$%^&*()_+-={}[]\\|;:'\"<>,.?/";
                int num_symbols = strlen(symbols);

                /// Prompt user for number of accounts and read input
                printf("Enter the number of accounts you want to generate passwords for:\n");
                scanf("%d", &number_of_accounts);

                ///Prompt user for names of each account and read input
                printf("Now Enter the User names for each account:\n");
                for (int k = 0; k < number_of_accounts; k++)
                {
                    scanf("%s", names[k]);
                }

                /// Generate and prints random passwords for each account
                srand(time(NULL));
                
                for (int i = 0; i < number_of_accounts; i++)
                {
                    char password[13];
                    for (int j = 0; j < 12; j++)
                    {
                        int random_value = rand() % 4;

                        /// Assign a lowercase letter
                        if (random_value == 0)
                        {
                            password[j] = 'a' + rand() % 26;
                        }
                            /// Assign an uppercase letter
                        else if (random_value == 1)
                        {
                            password[j] = 'A' + rand() % 26;
                        }
                            /// Assign a digit
                        else if (random_value == 2) {
                            password[j] = '0' + rand() % 10;
                        }
                            /// Assign a symbol
                        else 
                        {
                            password[j] = symbols[rand() % num_symbols];
                        }

                    }
                    password[12] = '\0';

                    printf("%s, the password for your account is: \"%s\"\n", names[i], password);
                }
                break;
            }
            case 5: 
                {
                    char pass[20];
                    char user[20];
                    printf("Key in your credentials to log in:\n");
                    printf("Enter user name:\n");
                    scanf("%s", &user);
                    printf("Key in your password:\n");
                    scanf("%s", &pass);
                    ///compares if the pasword entered and user name matches the original one
                    if (strcmp(pass, PASSWORD) == 0 && strcmp(user, USERNAME) == 0)
                    {
                        printf("Successful log in,welcome to your account:%s\n", USERNAME);
                        printf(" ------***PERSONAL INFORMATION***------\n");
                        printf("Name:wallace Wambulwa"
                               "Age:19 years\n"
                               "marital status:single\n"
                               "Level of education:Bachelors\n"
                               "Employment status:employed,civil servant\n"
                               "salary:1000$\n"
                               "competency:penetration tester\n"
                               "country:kenya\n"
                               "mobile:0705103864\n"
                               "email:wallacewambulwa@gmail.com\n"
                               "residence:nairobi");
                    } else 
                    {
                        printf("***INCORRECT USERNAME OR PASSWORD,PLEASE TRY AGAIN***\n");
                    }
                    break;
                }
                
            case 4:
                {
                    char username[50];
                    char password[50];
                    char password2[50];

                    /// Prompt the user to enter a username 
                    printf("Enter your username: ");
                    scanf("%s", username);

                    /// Prompt the user to enter a password and verify it
                     while(1) 
                        {
                          printf("Enter a password: ");
                          scanf("%s", password);

                          printf("Enter the password again: ");
                          scanf("%s", password2);
                          /// Passwords match, check if the password is strong or weak
                          if(strcmp(password, password2) == 0)  
                        {
                          if(isPasswordStrong(password))
                            {
                               printf("***Your password is strong*** Congratulations!\n");
                               printf("***Account created successfully***\n");
                               printf("Your user name is: %s\n", username);
                               printf("Your Password is: %s\n", password);
                          return 0;
                            } 
                          else {
                               printf("Your password is weak,Please create a strong password\n");
                               }
                        } 
                          else 
                            {
                                   /// if Passwords do not match, prompt the user to re-enter the password
                                    printf("The passwords do not match. Please try again:\n");
                            }
                        }
                        return 0;
                }
        }

        
    }
}
