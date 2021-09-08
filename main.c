#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct team
{
    char name[30];
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
    scanf("%[^\n]",t.name);
    printf("Enter Games played by Team: ");
    scanf("%d",&t.gamesPlayed);
    printf("Enter Games Won by Team: ");
    scanf("%d",&t.gamesWon);
    printf("Enter Games Lost by Team: ");
    scanf("%d",&t.gamesLost);
    printf("Enter Games Drawn by Team: ");
    scanf("%d",&t.gamesDrawn);
    t.points = t.gamesWon*3+t.gamesDrawn;
    printf("you've entered is %s\t%d\t%d\t%d\t%d",t.name,t.gamesPlayed,t.gamesWon,t.gamesLost,t.gamesDrawn,t.points);//+"\t"+footballTeam.gamesPlayed+"\t"+footballTeam.gamesWon+"\t"+footballTeam.gamesLost+"\t"footballTeam.gamesDrawn+"\t"+footballTeam.points);
    getch();
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

void AddDataInFile()
{
    FILE *filePointer;
    char dataToBeWritten[50] = "\nHello guys chae pilo \n usususu garam hai!";

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



