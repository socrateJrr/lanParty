#include "lanPartyLib.h"
void createList(Node **head, int *numberOfTeams, char **argv)
{
    FILE *in = fopen(argv[2], "rt");
    fscanf(in, "%d", &(*numberOfTeams));
    for (int i = 0; i < (*numberOfTeams); i++)
        addAtBeginning(&(*head), in);
    fclose(in);
}
void addAtBeginning(Node **head, FILE *in)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    int num;
    char nameOfTeam[100], sir[100];
    fscanf(in, "%d", &num);
    fgets(nameOfTeam, 100, in);
    strcpy(sir, nameOfTeam + 1);
    strcpy(nameOfTeam, sir);
    newNode->team.numberOfPlayers = num;
    newNode->team.TeamName = (char *)malloc((strlen(nameOfTeam) + 1) * sizeof(char));
    strcpy(newNode->team.TeamName, nameOfTeam);
    int sum = 0;
    newNode->team.player = (Player *)malloc(num * sizeof(Player));
    for (int i = 0; i < num; i++)
    {
        int pnts;
        char first[20], second[20];
        fscanf(in, "%s", first);
        fscanf(in, "%s", second);
        fscanf(in, "%d", &pnts);
        newNode->team.player->points = pnts;
        newNode->team.player->firstName = (char *)malloc((strlen(first) + 1) * sizeof(char));
        newNode->team.player->secondName = (char *)malloc((strlen(second) + 1) * sizeof(char));
        strcpy(newNode->team.player->firstName, first);
        strcpy(newNode->team.player->secondName, second);
        sum = sum + pnts;
    }
    // printf("%d\n",sum);
    newNode->team.totalPoints = sum;
    newNode->next = *head;
    *head = newNode;
}
void printList(Node *head, char **argv)
{
    FILE *out = fopen(argv[3], "wt");
    while (head)
    {
        fprintf(out, "%s", head->team.TeamName);
        head = head->next;
    }
    fclose(out);
}
int power(int n)
{
    while (n % 2 == 0)
        n = n / 2;
    if (n == 1)
        return 1;
    else
        return 0;
}
int lowestScor(Node *head)
{
    Node *headCopy = head;
    int min = headCopy->team.totalPoints;
    // headCopy = headCopy->next;
    while (headCopy)
    {
        if (headCopy->team.totalPoints < min)
            min = headCopy->team.totalPoints;
        headCopy = headCopy->next;
    }
    return min;
}
void deleteOneTeam(Node **head, int *numberOfTeams)
{
    int min = lowestScor(*head);
    printf("%d  ", (*numberOfTeams));
    Node *headCopy = *head;
    Node *aux = *head;
    /*while (headCopy)
    {
        if (headCopy->team.totalPoints != min)
        {
            aux = headCopy;
            headCopy = headCopy->next;
        }
        else
        {
            // printf("%s  ", aux->team.TeamName);
            if (aux == *head)
                *head = headCopy->next;
            else
                aux->next = headCopy->next;
            return;
            // free(headCopy);
        }
    }*/
    (*numberOfTeams)--;
}
void deleteTeams(Node **head, int *numberOfTeams)
{
    printf("hello delia");
    deleteOneTeam(&(*head), &(*numberOfTeams));
    while (power(*numberOfTeams) == 0)
        deleteOneTeam(&(*head), &(*numberOfTeams));
}
