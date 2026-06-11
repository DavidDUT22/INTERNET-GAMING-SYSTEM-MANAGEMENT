// The Vanguard Gaming Center
/*  1. include Library
    2.Outside main FUCNTION
      A). - Declare the constance variable : #totalCostumer 50, #totalPC 10
          - Globle variable such as pcStatus[], list[], tatalEarning.
      B). Create struct of Costumer with {CostumerID, Name, PC(1-10), Package, payment}
      C). Write functions
        a/.bool login()
          char username[20]; char password[20];
          bool isValid= false;
          if username == Admin && password== Admin168 bool isValid = true; else isValid == false;
          return isValid;
          #note : using string compare (strcmp() not ==)
        b/.void showMenu()
           print all 6 choices for admin.
           print let admin enter choice(1-6).
        c/.void showPCstation()       
        int pc;
        print some decoration text.
        for loop if pc==0 -> available else occupied.
        d/.void checkIn()
        char costumerID[20], char costumerName[20], int pcNUM, int package, float price;
        get userInformation
        let them choose pcStations
        let them choose package
        1 Hour              $1.50
        2 Hours	            $3.00
        3 Hours	            $4.50
        4 Hours	            $6.00
        5 Hours Promotion	$6.50
        Overnight Promotion	$10.00
        let them pay
        *money auto charge when costumer choose package no refund.
        then save costumer infomation into list.
        addition: Mark pc as occupied && add total earning 
        create 1 file name myCustomer.txt to stored costumer infomation
        e/.void checkOut()
        int pcNUM;
        let user input pcNUM;
	    then release that pc from occupied to available
        f/. void viewProfits()
        just print total customers and total profits that stored in our list.
        create 1 file use fopen and fclose to stored profits of the day
    3. Inside main FUNCTION
        int choice, int pc.
        set all pc to available
        showMenu()
        use do while to show all options
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//constance Variable
#define maxPC 10
#define maxCOSTUMER 50
//structure
struct costumer{
    char customerID[20];
    char customerName[20];
    int pc;
    int package;
    float payment;
};

//globle variable
int pcStatus[maxPC + 1];    //only count from 1-10 PCs
struct costumer list[maxCOSTUMER]; //maxCOSTUMER =50
int totalcustomer=0;
float profits=0;

//implement functions
bool login(){
    char username[20]; char password[20];   
    printf(" === VANGUARD GAMING CENTER ===\n");
    printf("username : ");
    scanf("%s", username);
    printf("password : ");
    scanf("%s", password);
    
    if(strcmp(username, "adminzin")==0 && strcmp(password, "admin168")==0){
        printf("[OK] Login Successfully\n");
        return true;
    }else {
        printf("[LOL] wrong username or password \n");
        return false;
    }
    
}
void showMenu(){
    printf("\n");
    printf(" WELCOME TO VANGUARD GAMING CENTER\n");
    printf(" 1. Customer Check In\n");
    printf(" 2. Customer Check Out\n");
    printf(" 3. View Gaming Stations\n");
    printf(" 4. Search Customer\n");
    printf(" 5. View Total Earnings\n");
    printf(" 6. Exit\n");
    printf(" Please Enter choice (1-6): ");
}
void pcStaions(){
    int pc;
    printf(" === VANGUARD GAMING CENTER ===\n");
    for(int pc=1; pc<maxPC+1; pc++){
        if(pcStatus[pc]==0){
            printf("PC %2d is Available \n", pc);
        }else{
            printf("PC %2d is Occupied \n", pc);
        }
    }
     printf("\n");
}
void checkIn(){
    char customerID[20];
    char customerName[20];
    int pcNum, package;
    float price;
    //let user input info and make sure it;s valid
    printf("please Enter costumerID(A001-A0011): ");
    scanf("%s", customerID);
    if (strcmp(customerID, "A001") != 0 &&
    strcmp(customerID, "A002") != 0 &&
    strcmp(customerID, "A003") != 0 &&
    strcmp(customerID, "A004") != 0 &&
    strcmp(customerID, "A005") != 0 &&
    strcmp(customerID, "A006") != 0 &&
    strcmp(customerID, "A007") != 0 &&
    strcmp(customerID, "A008") != 0 &&
    strcmp(customerID, "A009") != 0 &&
    strcmp(customerID, "A010") != 0 &&
    strcmp(customerID, "A0011") != 0){
    printf("[LOL]: Invalid Customer ID!\n");
    return;
}
    printf("please Enter customerName: ");
    scanf("%s", customerName);
    printf("please Enter pc number(1-10): ");
    scanf("%d", &pcNum);
    if(pcNum<1 || pcNum>10){
    printf("[LOL]: Invalid pc numbers!\n");
    return;
    }
    
    printf("\n--- Special Packages ---\n");
    printf("  1. 1 Hour              - $1.50\n");
    printf("  2. 2 Hours             - $3.00\n");
    printf("  3. 3 Hours             - $4.50\n");
    printf("  4. 4 Hours             - $6.00\n");
    printf("  5. 5 Hours Promotion   - $6.50\n");
    printf("  6. Overnight Promotion - $10.00\n");
    printf("Choose package (1-6): ");
    scanf("%d", &package);
    if(package<1 || package >6){
    printf("[LOL]: Invalid package please choose (1-6)!\n");    
    return;
    }
    // price range for the package
     if (package == 1) price = 1.50;
    else if (package == 2) price = 3.00;
    else if (package == 3) price = 4.50;
    else if (package == 4) price = 6.00;
    else if (package == 5) price = 6.50;
    else price = 10.00;
    //save all the infomation 
    strcpy(list[totalcustomer].customerID, customerID);
    strcpy(list[totalcustomer].customerName, customerName);
    list[totalcustomer].pc =pcNum;
    list[totalcustomer].package=package;
    list[totalcustomer].payment=price;
    totalcustomer+=1;
    //markPC occupied
    pcStatus[pcNum]=1;

    //profit
    profits+=price;
    printf("[DAYUM] Check-in done!\n");

    //let create file to stored the customer information 
    FILE *myfile;
    myfile = fopen("myCustomer.txt", "a");
    if(myfile==NULL){
        return;    //make sure the program not crashing
    }
    fprintf(myfile, "ID         : %s\n", customerID);
    fprintf(myfile, "Name       : %s\n", customerName);
    fprintf(myfile, "PC         : %d\n", pcNum);
    fprintf(myfile, "Package    : %d\n", package);
    fprintf(myfile, "payments   : %.2f\n", price);
    fprintf(myfile, "--------------------------------------------------------\n");
    fclose(myfile);
}
void checkOut(){
int pcNUM;
    printf("Please enter your pc number(1-10) ");
    scanf("%d", &pcNUM);
    if(pcNUM<1 || pcNUM>10){
    printf("[LOL]: Invalid pc numbers!\n");
    return;
     }
    pcStatus[pcNUM] = 0;
    printf("[DAYUM] Check-Out done!\n");
}
void searchCustomer(){
    char findcustomerID[20];
    int Isfound=0;
    printf("Please enter customerID: ");
    scanf("%s",findcustomerID);
    for(int i=0; i<totalcustomer; i++){
        if(strcmp(list[i].customerID,findcustomerID)==0){
            printf("\n--- Yoo! Customer Found ---\n");
            printf("ID       :%s\n", list[i].customerID);
            printf("Name     :%s\n", list[i].customerName);
            printf("PC       :%d\n", list[i].pc);
            printf("Package  :%d\n", list[i].package);
            printf("Payment  :%.2f\n", list[i].payment);
            Isfound=1;
            break;
        }
  }
    //make sure when notfound ID just break
    if(Isfound==0){
            printf("[LOL] No customer found with ID %s.\n", findcustomerID);
        }
}
void viewProfits(){
    printf("\n--- TOTAL PROFITS ---\n");
    printf("TOTAL CUSTOMERS : %d\n", totalcustomer);
    printf("TOTAL PROFITS   : $%.2f\n", profits);
    FILE *pfile;
    pfile = fopen("myProfit.txt", "a");
    if(pfile == NULL) {
        return;
    }
    fprintf(pfile, "\n----------------- TOTAL PROFITS -----------------\n");
    fprintf(pfile, "TOTAL CUSTOMERS       : %d\n", totalcustomer);
    fprintf(pfile, "TOTAL PROFITS         : $%.2f\n",profits );
    fprintf(pfile, "---------------------------------------------------\n");
    fclose (pfile);
}

int main(){
    int choice;
    int pc;
    //set all pc to available
    for (pc = 1; pc <= maxPC; pc++) {
        pcStatus[pc] = 0;
    }
    //login page
    if (login()==false) { 
        return 0;
    }  
     do {
        showMenu();
        scanf("%d", &choice);

        if (choice == 1) {
            checkIn();           
        }else if (choice == 2){
            checkOut();          
        }else if (choice == 3){
            pcStaions();
        }else if(choice == 4){
            searchCustomer();
        }else if (choice == 5) {
            viewProfits();        
        }else if (choice == 6){
            printf("\nGoodbye! Thank you for using Vanguard Gaming Center.\n");
        }
        else {
            printf("[LOL] Please enter a number from 1 to 6.\n");
        }
        
        }while (choice!=6);

    return 0;
}