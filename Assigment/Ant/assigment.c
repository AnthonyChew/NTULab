#include <stdio.h>

//NameCard struct
struct NameCard
{
 int nameCardID;
 char personName[20];
 char companyName[20];
};

//Functions
void choiceFromUser(int *userChoice); 
void listNameCards(struct NameCard allNameCards[5] , int *cardsEmptyFlag);

//Main Func
int main()
{
    //Initilization
    struct NameCard allNameCards[5] ; //NameCard Array with 5 max capicity
    int userChoice = 999 , cardsEmptyFlag = 0; // User choice , Flag to check is card empty

    //Test case
    //struct NameCard allNameCards[5] ={ {9,"PC Leong","NTU" } , {5,"WC Tan","NTU"} ,{7,"Philip Fu","NTU"} };
    
    //Welcome msg
    printf("NTU NAME CARD HOLDER MANAGEMENT PROGRAM:\n"
            "1: listNameCards() \n"
            "2: addNameCard() \n"
            "3: removeNameCard() \n"
            "4: getNameCard()  \n"
            "5: quit \n");
    
    //Keep looping until exit is 5
    while (1)
    {
        choiceFromUser(&userChoice);

        //Swtich case from user
        switch (userChoice)
        {

        case 1:
            listNameCards(allNameCards , &cardsEmptyFlag);
            break;

        case 2:
            /* code */
            break;

        case 3:
            /* code */
            break;

        case 4:
            /* code */
            break;
        
        //Exit when 5 is input
        case 5:
            printf("Exited!");
            return 0;
        
        //Anything else just ask again
        default:
            continue;
        }
    }
    

    return 0;
}

//Function to ask input from user
void choiceFromUser(int *userChoice)
{
    printf("Enter your choice: \n");

    scanf("%d", userChoice);
}

//List all the card in struct array
void listNameCards(struct NameCard allNameCards[5] , int *cardsEmptyFlag)
{
    //If card is empty 
    if(*cardsEmptyFlag == 1)
    {
        printf("The name card holder is empty\n");
    }
    else
    {
        //Loop through all index of allCards
        for(int i = 0; i< 4; i++)
        {
            //If all the input is default don't show
            if(allNameCards[i].nameCardID != 0 && allNameCards[i].personName != "" && allNameCards[i].companyName != "")
            {
                printf("nameCardID: %d\n"
                        "personName: %s\n"
                        "companyName: %s\n" 
                        , allNameCards[i].nameCardID , allNameCards[i].personName , allNameCards[i].companyName);
            }
        }

    }
}
