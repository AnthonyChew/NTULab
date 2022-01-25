#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define true 0
#define false !true

//NameCard struct
struct NameCard
{
    int NameCardID;
    char PersonName[20];
    char CompanyName[20];
};

//Functions
void ChoiceFromUser(int *userChoice);
void ListNameCards(struct NameCard allNameCards[5], int *cardsCount);
int AddNameCard(struct NameCard allNameCards[5], int *cardsCount);
int RemoveNameCard(struct NameCard allNameCards[5], int *cardsCount);
int GetNameCard(struct NameCard allNameCards[5], int *cardsCount);
void LowerAllChar(char value[]);
void SortById(struct NameCard allNameCards[5], int *cardsCount);

//Main Func
int main()
{
    //Initilization
    struct NameCard allNameCards[5];       //NameCard Array with 5 max capicity
    int userChoice = 999, cardsCount = -1; // User choice , Flag to check is card empty

    //Test case
    //struct NameCard allNameCards[5] = {{9, "PC Leong", "NTU"}, {5, "WC Tan", "NTU"}, {7, "Philip Fu", "NTU"} ,{10, "Philip Fu", "NTU"}};

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
        ChoiceFromUser(&userChoice);

        //Swtich case from user
        switch (userChoice)
        {

        case 1:
            printf("listNameCards(): \n");
            ListNameCards(allNameCards, &cardsCount);
            break;

        case 2:
            printf("addNameCard(): \n");
            AddNameCard(allNameCards, &cardsCount);
            break;

        case 3:
            printf("removeNameCard(): \n");
            RemoveNameCard(allNameCards, &cardsCount);
            break;

        case 4:
            printf("getNameCard(): \n");
            GetNameCard(allNameCards, &cardsCount);
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
void ChoiceFromUser(int *userChoice)
{
    char tempBuffer[9999];

    printf("Enter your choice: \n");

    fgets(tempBuffer,9999,stdin);
    *userChoice = atoi(tempBuffer);
}

//List all the card in struct array
void ListNameCards(struct NameCard allNameCards[5], int *cardsCount)
{
    //If card is empty
    if (*cardsCount == -1)
    {
        printf("The name card holder is empty\n");
    }
    else
    {
        //Loop through all index of allCards
        for (int i = 0; i <= *cardsCount; i++)
        {
            printf("nameCardID: %d\n"
                   "personName: %s\n"
                   "companyName: %s\n",
                   allNameCards[i].NameCardID, allNameCards[i].PersonName, allNameCards[i].CompanyName);
        }
    }
}

int AddNameCard(struct NameCard allNameCards[5], int *cardsCount)
{
    *cardsCount += 1;                     //current card amount
    int cardID, cardExistFlag = false;    // CardID for user input, Card Exist Flag to check does card exist
    char personName[20], companyName[20], *p , tempCardBuffer[9999]; // PersonName and CompanyName for user input

    //Ask for user input
    printf("Enter nameCardID:\n");
    fgets(tempCardBuffer, 9999,stdin);
    cardID = atoi(tempCardBuffer);
    
    printf("Enter personName:\n");
    fgets(personName, 20,stdin);
    if(p= strchr(personName,'\n')) *p = '\0'; // replace '\n'

    printf("Enter companyName:\n");
    fgets(companyName, 20,stdin);
    if(p= strchr(companyName,'\n')) *p = '\0'; // replace '\n'

    //If card less than 4
    if (*cardsCount <= 4)
    {
        //Loop through all index of allCards
        for (int i = 0; i < 5; i++)
        {
            //If any duplicated NameCardID
            if (allNameCards[i].NameCardID == cardID)
            {
                //Set Flag to true
                cardExistFlag = true;
            }
        }

        //If card not exist
        if (cardExistFlag == false)
        {
            allNameCards[*cardsCount].NameCardID = cardID;

            strcpy(allNameCards[*cardsCount].PersonName, personName);

            strcpy(allNameCards[*cardsCount].CompanyName, companyName);

            printf("The name card has been added successfully\n");

            //Sort after any inputs
            SortById(allNameCards, cardsCount);

            //Return success
            return true;
        }
        //Else reduce count to the previous and return false
        else
        {
            printf("The nameCardID has already existed\n");
            *cardsCount -= 1;

            //Return fail
            return false;
        }
    }
    //Else exit
    else
    {
        printf("The name card holder is full\n");

        //Return fail
        return false;
    }
}

int RemoveNameCard(struct NameCard allNameCards[5], int *cardsCount)
{
    int cardID;                                         // CardID for user input, Card Exist Flag to check does card exist
    char personName[20], tempChar[20] , *p; // PersonName and CompanyName for user input

    struct NameCard defualtNameCard = {99999, "", ""};
    //Ask for user input
    printf("Enter personName:\n");
    fgets(personName, 20,stdin);
    if(p = strchr(personName , '\n'))*p = '\0';

    LowerAllChar(personName);

    //If there is any card
    if (*cardsCount > -1)
    {
        //Loop through all index of allCards
        for (int i = 0; i <= *cardsCount; i++)
        {
            strcpy(tempChar, allNameCards[i].PersonName);

            LowerAllChar(tempChar);

            //If any duplicated NameCardID
            if (strcmp(tempChar, personName) == true)
            {
                printf("The name card is removed\n");

                printf("nameCardID: %d\n"
                        "personName: %s\n"
                        "companyName: %s\n" ,allNameCards[i].NameCardID,allNameCards[i].PersonName,allNameCards[i].CompanyName);

                allNameCards[i] = defualtNameCard;

                *cardsCount -= 1;

                //Sort after any inputs
                SortById(allNameCards, cardsCount);

                //Return success2
                return true;
            }
        }
    }
    //Else exit
    else
    {
        printf("The name card holder is empty\n");

        //Return fail
        return false;
    }

    printf("The target person name is not in the name card holder\n");

    //Return fail
    return false;
}

int GetNameCard(struct NameCard allNameCards[5], int *cardsCount)
{
    int cardID;                                         // CardID for user input, Card Exist Flag to check does card exist
    char personName[20], tempChar[20],*p; // PersonName and CompanyName for user input

    //Ask for user input
    printf("Enter personName:\n");
    fgets(personName,20,stdin);
    if(p=strchr(personName,'\n')) *p = '\0';

    LowerAllChar(personName);

    //If there is any card
    if (*cardsCount > -1)
    {
        //Loop through all index of allCards
        for (int i = 0; i <= *cardsCount; i++)
        {
            strcpy(tempChar, allNameCards[i].PersonName);

            LowerAllChar(tempChar);

            //If any duplicated NameCardID
            if (strcmp(tempChar, personName) == true)
            {
                printf("The target person name is found\n");

                printf("nameCardID: %d\n"
                        "personName: %s\n"
                        "companyName: %s\n" ,allNameCards[i].NameCardID,allNameCards[i].PersonName,allNameCards[i].CompanyName);

                //Return success2
                return true;
            }
        }
    }
    //Else exit
    else
    {
        printf("The name card holder is empty\n");

        //Return fail
        return false;
    }

    printf("The target person name is not found\n");

    //Return fail
    return false;
}

void LowerAllChar(char value[])
{
    for (int x = 0; x < strlen(value); x++)
    {
        value[x] = tolower(value[x]);
    }
}

//Bubble sort
void SortById(struct NameCard allNameCards[5], int *cardsCount)
{
    struct NameCard lNameCards, rNameCards;
    int sortFlag = false;

    while (1)
    {
        sortFlag = false;

        for (int i = 0; i < *cardsCount; i++)
        {
            lNameCards = allNameCards[i];
            rNameCards = allNameCards[i + 1];

            if ((lNameCards.NameCardID > rNameCards.NameCardID))
            {
                allNameCards[i + 1] = lNameCards;
                allNameCards[i] = rNameCards;

                sortFlag = true;
            }
        }

        if (sortFlag == false)
        {
            break;
        }
    }
}