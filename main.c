#include <conio.h>
#include <stdio.h>
#include <stdlib.h>                         // headers
#include <string.h>

typedef struct team
{
    char name[20];
    int gamesPlayed;
    int gamesWon;                           // structure of a single Team.
    int gamesLost;
    int gamesDrawn;
    int points;
}footballTeam;


int main()
{
    printf("--------------------------------------------------------WELCOME--------------------------------------------------------\n\n");
    while(1){
        if(!start())
        {
            printf("--------------------------------------------------------BYE BYE--------------------------------------------------------\n");
            getch();
            break;
        }
    system("cls");                          // clean the console.
    }
    return 0;
}

int start()                                // First Method call just after main shows menu
{
    int choice_1;
    printf("\n--------------------------------------------------------MENU-----------------------------------------------------------\n");
    printf("1 : Show File Data\n2 : Add New Records in File\n3 : exit\nEnter your choice : ");
    scanf("%d",&choice_1);
    if(choice_1<1 || choice_1>3)
    {
        printf("Invalid Choice, Please select a valid number.");
        getch();
    }
    if(choice_1 == 1)
    {
        showFileData();             //  file data read.
    }
    if(choice_1 ==2)
    {
        AddNewRecord();             // Add new records in file.
    }
    if(choice_1==3)
        return 0;                   // Exit
    return 1;                       // Invalid Choice
}

void AddNewRecord()
{
    char teamName[100],temp;         // initially we've taken for maximum of 100 different teams we can extend it.
    footballTeam t;
    printf("\n--------------------------------------------------------Enter Team Details-------------------------------------------------------\n");
    printf("Enter Team Name: ");
    scanf("%c",&temp);
    scanf("%[^\n]",t.name); // to clear buffer
    printf("Enter Games played by Team: ");
    scanf("%d",&t.gamesPlayed);
    if(t.gamesPlayed<0)
    {
        printf("Invalid Values Given!");
        getch();                                    // invalid game played number.
        return;
    }
    printf("Enter Games Won by Team: ");
    scanf("%d",&t.gamesWon);
    if(t.gamesWon<0 || t.gamesPlayed < t.gamesWon)
    {
        printf("Invalid Values Given!");
        getch();                                    // invalid game Won number.
        return;
    }
    printf("Enter Games Lost by Team: ");
    scanf("%d",&t.gamesLost);
    if(t.gamesLost<0 || t.gamesPlayed < t.gamesLost)
    {
        printf("Invalid Values Given!");
        getch();
        return;                                     // invalid game Lost number.
    }
    printf("Enter Games Drawn by Team: ");
    scanf("%d",&t.gamesDrawn);
    if(t.gamesDrawn<0 || t.gamesPlayed < t.gamesDrawn)
    {
        printf("Invalid Values Given!");
        getch();                                    // invalid game Drawn number.
        return;
    }
    if(!(t.gamesPlayed == (t.gamesLost + t.gamesDrawn + t.gamesWon)))
    {
        printf("Values are not correct!");
        getch();                                    // invalid game points.
        return;
    }
    t.points = t.gamesWon*3+t.gamesDrawn;
    printf("You have Entered The Following Details for Team -----> %s\n\tPlayed -----> %d\n\tWon --------> %d\n\tLose -------> %d\n\tDraw -------> %d\n\tPoints -----> %d\n",t.name,t.gamesPlayed,t.gamesWon,t.gamesLost,t.gamesDrawn,t.points);
    printf("Confirm with pressing 1 to add to file : ");
    int choice_2;
    scanf("%d",&choice_2);
    if(choice_2==1){
        AddDataInFile(t);                       // add data to file after confirming
    }
}

void showFileData()                         // methods that read data from file
{
    FILE *filePointer;
    char dataToBeRead[50];                  // amount of data read at once

    filePointer = fopen("ScoreBoard.txt","r");

    if( filePointer == NULL)
    {
        printf("Specified file not found!");
    }
    else{
        printf("\n--------------------------------------------------------SCORES--------------------------------------------------------\n");
        while(fgets( dataToBeRead, 50, filePointer))
        {
            printf("%s",dataToBeRead);
        }
        fclose(filePointer);
    }
    getch();
}

void AddDataInFile(footballTeam t)              // writing data into file.
{
    char gP[10],gW[10],gL[10],gD[10],P[10];

    itoa(t.gamesPlayed,gP,10);
    itoa(t.gamesWon,gW,10);                     // integer to string conversion
    itoa(t.gamesLost,gL,10);
    itoa(t.gamesDrawn,gD,10);
    itoa(t.points,P,10);

    char query[100]="\n\t";
    char spacing[10]="\t\t";
    strcat(query,t.name);
    if(strlen(t.name)<=4)
    {
        strcat(query,spacing);
        strcat(query,spacing);
    }
    else if(strlen(t.name)<=8)
    {
        strcat(query,spacing);
    }
    else
    {
        strcat(query,spacing);
    }
    strcat(query,gP);
    strcat(query,spacing);
    strcat(query,gW);
    strcat(query,spacing);
    strcat(query,gL);
    strcat(query,spacing);
    strcat(query,gD);
    strcat(query,spacing);
    strcat(query,P);


    FILE *filePointer;
    char dataToBeWritten[50]="\t";                  //amount of data written at once in file.

    strcat(dataToBeWritten,query);

    filePointer = fopen("ScoreBoard.txt","a");

    if( filePointer == NULL)
    {
        printf("Specified file not found!");
    }
    else{
        if( strlen( dataToBeWritten) > 0)
        {
            fputs(dataToBeWritten, filePointer);
            fputs("\n",filePointer);
        }
        fclose(filePointer);
    }
    getch();
}










/*
All Rights Reserved for this Project in under HRITIK SINGH and TEAM
*/
