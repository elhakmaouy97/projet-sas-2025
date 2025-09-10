#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 50

typedef struct
{

    int id;
    char nom[50];
    char prenom[50];
    int numeroMaillot;
    char poste[50];
    int age;
    int buts;
} Joueur ;

Joueur joueurs[MAX];
int compteur=0;
int nvId=1;

void Ajouter()
{
    printf("vous pouvez saisie les donner de votre joueur.\n ");
    if (compteur<MAX)
    {
        joueurs[compteur].id=nvId++;

        printf("le nom du joueur est : ");
        fgets(joueurs[compteur].nom,50,stdin);
        joueurs[compteur].nom[strcspn(joueurs[compteur].nom, "\n")] = '\0';

        printf("le prenom du joueur est : ");
        fgets(joueurs[compteur].prenom,50,stdin);
        getchar();

        printf("le numero de maillot est : ");
        scanf("%d",&joueurs[compteur].numeroMaillot);
        getchar();

        printf("le poste du joueur est : ");
        fgets(joueurs[compteur].poste,50,stdin);

        printf("l age du joueur est : ");
        scanf("%d",&joueurs[compteur].age);
        getchar();
        printf("le nombre du buts marquent par le joueur sont : ");
        scanf("%d",&joueurs[compteur].buts);
        getchar();
        compteur++;
        printf("le joueur a ete ajouter .\n");
    }
    else
    {
        printf("\n l'equipe est plein .\n");

    }
}

void AjouterPlusieur()
{
    int nombre;
    printf("veuillez saisir le nombre des joueurs a ajouter :\n");
    scanf("%d",&nombre);
    getchar();
    for(int i=0; i<nombre; i++)
    {
        if (compteur>=MAX)
        {
            printf("l equipe est deja plein :  \n");
            break;

        }
        else
        {
            printf("\n le joueur %d a etait ajouter \n",i+1);
            Ajouter();
        }
    }

}

void Afficher()
{
    if (compteur==0)
    {

        printf("auccun joueur pour le moment merci de l ajouter .\n");
        return;
    }
    for (int i=0; i<compteur; i++)
    {
        printf("id:%d       nom:%s      prenom:%s       maillot:%d      post:%s     age:%d      buts:%d  \n",
               joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,joueurs[i].numeroMaillot,joueurs[i].poste,
               joueurs[i].age,joueurs[i].buts);

    }
}


void supprimer()
{
    if (compteur==0)
    {

        printf("auccun joueur pour le moment merci de l ajouter .\n");
        return ;
    }
    int supprimerid;
    printf("veuillez saisir l id du joueur que vous souhaitez supprimer:");
    scanf("%d",&supprimerid);
    int trouver=0;
    for (int i=0; i<compteur; i++)
    {
        if (joueurs[i].id==supprimerid)
        {
            for (int j=i; j<compteur-1; j++)
            {
                joueurs[j]=joueurs[j+1];
            }
            compteur--;
            printf("joueur avec id %d supprimer avec succe.\n",supprimerid);
            trouver=1;
            break;
        }
    }
    if (trouver==0)
    {
        printf("aucun joeurs trouver .");
    }


}



void rechercher()
{   int trouver =0;
    if (compteur==0)
    {
        printf("aucun joueur pour le moment merci d'ajouter des joueurs .\n");
        return;
    }
    int choix=0;


    printf("------------menu recherche-----------\n");
    printf(" 1 - Rechercher un joueur par Identifiant.\n");
    printf(" 2 - Rechercher un joueur par Nom.\n");
    printf("merci de choisir un choix:");
    scanf("%d",&choix);
    getchar();

    switch(choix)
    {
    case 1:
        int chercherId;
        printf("veuillez saisir l id de votre joueur:");
        scanf("%d",&chercherId);
        getchar();

        for(int i=0; i<compteur; i++)
        {
            if (joueurs[i].id==chercherId)
            {
                printf("joueur trouve :\n id:%d       nom:%s      prenom:%s       maillot:%d      post:%s     age:%d      buts:%d  \n",
                       joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,joueurs[i].numeroMaillot,joueurs[i].poste,
                       joueurs[i].age,joueurs[i].buts);
                trouver =1 ;
                break;
            }
        }
        if (trouver==0)
        {
            printf("aucun joueur avec l id %d",chercherId);
        }
        break;
    case 2:
        char chercherNom[50];
        printf("veuillez saisir le nom de votre joueur: ");
        fgets(chercherNom,50,stdin);
        chercherNom[strcspn(chercherNom, "\n")] = '\0';

        for(int i=0; i<compteur; i++)
        {
            if(strcmp(joueurs[i].nom,chercherNom)==0)
            {
                printf("joueur trouve:\n");
                printf("id:%d       nom:%s      prenom:%s       maillot:%d      post:%s     age:%d      buts:%d  \n",
                       joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,joueurs[i].numeroMaillot,joueurs[i].poste,
                       joueurs[i].age,joueurs[i].buts);
                trouver=1;
                break;
            }
        }

        if (trouver ==0)
        {
            printf("aucun joueur trouver par ce nom");
        }
    }}

/*void modifier()  {
int postejoueur;
int choix=0;
printf("----------menu de modification----------");
printf(" 1 - Modifier le poste d’un joueur. ");
printf(" 2 - Modifier l’âge d’un joueur.");
printf(" 3 - Modifier le nombre de buts marqués par un joueur. ");
printf("le choix est : ");
scanf("%d",&choix);

switch (choix){
case 1 :
    for (int i=0;i<compteur;i++){


    }


}



}

}*/


int main()
    {
        int choix;

        do
        {
            printf("----------Menu----------\n");

            printf(" 1 - Ajouter un joueur:\n");
            printf(" 2 - Afficher la liste de tous les joueurs:\n");
            printf(" 3 - Modifier un joueur:\n");
            printf(" 4 - Supprimer un joueur:\n");
            printf(" 5 - Rechercher un joueur:\n");
            printf(" 6 - Statistiques:\n");
            printf(" 7 - Quitter  :\n");

            printf("saisir votre choix (0 pour arrete): ");
            scanf("%d",&choix);
            switch (choix)
            {
            case 1:
                AjouterPlusieur();
                break;
            case 2:
                Afficher();
                break;
            case 3:
                //modifier();
                break;
            case 4:
                supprimer();
                break;
            case 5:
                rechercher();
                break;
            case 6:

                break;
            case 7:

                break;
            default:
                printf("choix invalide");
            }
        }
        while (choix!=0);
        return 0;
    }
