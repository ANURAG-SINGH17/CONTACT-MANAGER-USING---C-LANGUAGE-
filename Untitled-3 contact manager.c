// contact manager mini project 

#include<stdio.h>
#include<string.h>

#define MAX_CONTACT 100

struct contact{
    char name[50];
    char number[15];
    char email[50];
};

struct contact contacts[MAX_CONTACT];

int numcontacts = 0;

void displaymenu();
void addcontact();
void viewcontact();
void searchcontact();


int main() {
    int choice ;
    do{
        displaymenu();
        printf("Enter your Choice : ");
        scanf("%d",&choice);

        switch (choice) {
             case 1 : 
             addcontact();
             break;

             case 2:
             viewcontact();
             break;

             case 3 :
             searchcontact();
             break;

             case 4 :
             printf("Exiting The Contact Manager Good Bye : ) \n ");
             break;

             default :
             printf("Invalid Number \n");
             break;
        }

    } while (choice != 4);

    return 0;
}


void displaymenu() {
    printf("\n======== CONTACT MANAGER ========\n");
    printf("1. Add Contact\n");
    printf("2. View Contact\n");
    printf("3. Search Contact\n");
    printf("4. exit \n ");
}

void addcontact() {
    if (numcontacts <  MAX_CONTACT){
    printf("Enter Contact Name : ");
    scanf("%s", contacts[numcontacts].name);

    printf("Enter Contact Number : ");
    scanf("%s", contacts[numcontacts].number);

    printf("Enter Contact Email : ");
    scanf("%s", contacts[numcontacts].email);

    numcontacts++;
    printf("Add Successfully\n");
    } 
    else {
        printf("Contact list is Full\n");
    }
}

void viewcontact() {
    if ( numcontacts > 0 ){
        printf("\n======CONTACT LIST======\n");
        for (int i = 0; i < numcontacts; i++){
            printf("%d. Name : %s\n  Number : %s\n  Email : %s\n" , i+1 , contacts[i].name , 
            contacts[i].number, contacts[i].email);
        }
    }
    else{
        printf("Contact list Empty");
    }
}

void searchcontact() {
    if ( numcontacts > 0 ) {
        char searchname[50];
        printf("Enter the to search : ");
        scanf("%s",searchname);

        int found = 0;
        for (int i = 0; i < numcontacts ; i++) {
            if (strcmp( contacts[i].name , searchname ) == 0){
                printf("Name: %s\n  Number: %s\n  Email: %s\n ",
                contacts[i].name , contacts[i].number, contacts[i].email);

                found = 1;
                break;
            }
        }
        if (!found){
            printf("Not found\n");

        }
    }
    else{
        printf("contact list is empty\n");
    }
}