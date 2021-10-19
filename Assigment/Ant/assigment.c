#include <stdio.h>
#include <string.h>

#define true 0
#define false !true

//NameCard struct
struct NameCard
{
    int nameCardID;
    char personName[20];
    char companyName[20];
};

//Functions
void choiceFromUser(int *userChoice);
void listNameCards(struct NameCard allNameCards[5], int *cardsCount);
int addNameCard(struct NameCard allNameCards[5], int *cardCount);

//Main Func
int main()
{
    //Initilization
    struct NameCard allNameCards[5];       //NameCard Array with 5 max capicity
    int userChoice = 999, cardsCount = -1; // User choice , Flag to check is card empty

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
            printf("listNameCards(): \n");
            listNameCards(allNameCards, &cardsCount);
            break;

        case 2:
            printf("addNameCard(): \n");
            addNameCard(allNameCards, &cardsCount);
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
void listNameCards(struct NameCard allNameCards[5], int *cardsCount)
{
    //If card is empty
    if (*cardsCount == -1)
    {
        printf("The name card holder is empty\n");
    }
    else
    {
        printf("%d\n" , *cardsCount);
        //Loop through all index of allCards
        for (int i = 0; i <=  *cardsCount; i++)
        {
                printf("nameCardID: %d\n"
                       "personName: %s\n"
                       "companyName: %s\n",
                       allNameCards[i].nameCardID, allNameCards[i].personName, allNameCards[i].companyName);
        }
    }
}

int addNameCard(struct NameCard allNameCards[5], int *cardCount)
{
    *cardCount += 1; //current card amount
    int cardID, cardExistFlag = false;// CardID for user input, Card Exist Flag to check does card exist
    char personName[20], companyName[20];// PersonName and CompanyName for user input 

    //Ask for user input
    printf("Enter nameCardID:\n");
    scanf("%d", &cardID);

    printf("Enter personName:\n");
    scanf(" %[^\n]s", personName);

    printf("Enter companyName:\n");
    scanf(" %[^\n]s", companyName);
    
    //If card less than 4
    if (*cardCount <= 4)
    {
        //Loop through all index of allCards
        for (int i = 0; i < 5; i++)
        {
            //If any duplicated NameCardID
            if (allNameCards[i].nameCardID == cardID)
            {   
                //Set Flag to true
                cardExistFlag = true;
            }
        }
        
        //If card not exist
        if (cardExistFlag == false)
        {
            //check is card bigger or smaller than card
            allNameCards[*cardCount].nameCardID = cardID;

            strcpy(allNameCards[*cardCount].personName ,personName);
            
            strcpy(allNameCards[*cardCount].companyName ,companyName);

            printf("The name card has been added successfully\n");
            return true;
        }
        //Else reduce count to the previous and return false
        else
        {
            printf("The nameCardID has already existed\n");
            *cardCount -= 1;
            return false;
        }
    }
    //Else exit
    else
    {
        return false;
    }
    
}
