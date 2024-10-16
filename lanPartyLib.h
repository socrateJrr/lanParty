#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char *firstName;
    char *secondName;
    int points;
} Player;
typedef struct
{
    char *TeamName;
    int numberOfPlayers;
    int totalPoints;
    Player *player;
} Team;
typedef struct Elem
{
    Team team;
    struct Elem *next;
} Node;
void createList(Node **head, int *numberOfTeams, char **argv);
void addAtBeginning(Node **head, FILE *in);
void printList(Node *head, char **argv);
int power(int n);
int lowestScor(Node *head);
void deleteOneTeam(Node **head, int *numberOfTeams);
void deleteTeams(Node **head, int *numberOfTeams);
