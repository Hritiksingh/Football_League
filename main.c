#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct team
{
    char name[20];
    int gamesPlayed;
    int gamesWon;
    int gamesLost;
    int gamesDrawn;
    int points;
}footballTeam;


int main()
{
    printf("----------------------------------------------WELCOME----------------------------------------------\n\n");
    while(1){
        if(!start())
        {
            printf("----------------------------------------------BYE BYE----------------------------------------------\n");
            getch();
            break;
        }
    system("cls");
    }
    return 0;
}

int start()
{
    int choice_1;
    printf("\n----------------------------------------------MENU-------------------------------------------------\n");
    printf("1 : Show File Data\n2 : Add New Records in File\n3 : exit\nEnter your choice : ");
    scanf("%d",&choice_1);
    if(choice_1<1 || choice_1>3)
    {
        printf("Invalid Choice, Please select a valid number.");
        getch();
    }
    if(choice_1 == 1)
    {
        showFileData();
    }
    if(choice_1 ==2)
    {
        //AddDataInFile();
        AddNewRecord();
    }
    if(choice_1==3)
        return 0;
    return 1;
}

void AddNewRecord()
{
    char teamName[50],temp;
    footballTeam t;
    printf("\n----------------------------------------------Enter Team Details---------------------------------------------\n");
    printf("Enter Team Name: ");
    scanf("%c",&temp);
    scanf("%[^\n]",t.name); // to clear buffer
    printf("Enter Games played by Team: ");
    scanf("%d",&t.gamesPlayed);
    printf("Enter Games Won by Team: ");
    scanf("%d",&t.gamesWon);
    printf("Enter Games Lost by Team: ");
    scanf("%d",&t.gamesLost);
    printf("Enter Games Drawn by Team: ");
    scanf("%d",&t.gamesDrawn);
    t.points = t.gamesWon*3+t.gamesDrawn;
    //printf("you've entered is %s\t%d\t%d\t%d\t%d\t%d\n",t.name,t.gamesPlayed,t.gamesWon,t.gamesLost,t.gamesDrawn,t.points);
    printf("You have Entered The Following Details for Team -----> %s\n\tPlayed -----> %d\n\tWon --------> %d\n\tLose -------> %d\n\tDraw -------> %d\n\tPoints -----> %d\n",t.name,t.gamesPlayed,t.gamesWon,t.gamesLost,t.gamesDrawn,t.points);
    printf("Confirm with pressing 1 to add to file : ");
    int choice_2;
    scanf("%d",&choice_2);
    if(choice_2==1){
        AddDataInFile(t);
    }
}

void showFileData()
{
    FILE *filePointer;
    char dataToBeRead[50];

    filePointer = fopen("ScoreBoard.txt","r");

    if( filePointer == NULL)
    {
        printf("Specified file not found!");
    }
    else{
        printf("\n----------------------------------------------SCORES----------------------------------------------\n");
        while(fgets( dataToBeRead, 50, filePointer))
        {
            printf("%s",dataToBeRead);
        }
        fclose(filePointer);
    }
    getch();
}

void AddDataInFile(footballTeam t)
{
    //printf("You have Entered The Following Details for a The Team\nTeam Name\t\tPlayed\t\tWon\t\tLose\t\tDraw\t\tPoints\n%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",t.name,t.gamesPlayed,t.gamesWon,t.gamesLost,t.gamesDrawn,t.points);
    char gP[10],gW[10],gL[10],gD[10],P[10];

    itoa(t.gamesPlayed,gP,10);
    itoa(t.gamesWon,gW,10);
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
    char dataToBeWritten[50]="\t";

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



