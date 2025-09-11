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
void infojoueurs (int compteur){
joueurs[compteur].id=nvId++;
getchar();
            printf("le nom du joueur est : \n");
            fgets(joueurs[compteur].nom,50,stdin);
            getchar();
            printf("le prenom du joueur est : \n");
            fgets(joueurs[compteur].prenom,50,stdin);
            getchar();

            printf("le numero de maillot est : \n");
            scanf("%d",&joueurs[compteur].numeroMaillot);
            getchar();

            printf("le poste du joueur est : \n");
            fgets(joueurs[compteur].poste,50,stdin);
            joueurs[compteur].poste[strcspn(joueurs[compteur].poste, "\n")] = '\0';

            printf("l age du joueur est : \n");
            scanf("%d",&joueurs[compteur].age);
            getchar();

            printf("le nombre du buts marquent par le joueur sont : \n");
            scanf("%d",&joueurs[compteur].buts);
            getchar();
}
void Ajouter()
{
    int choix;
    printf("----------menu ajouter-----------:\n");

    printf(" 1 - ajouter un seul joueur .\n");
    printf(" 2 - ajouter plusieur joueurs .\n");

    printf("veuillez entrez votre choix :\n");
    scanf("%d",&choix);

    switch (choix)
    {
    case 1 :
        printf("entrez les donnes de votre joueur:\n");
        if (compteur<MAX)
        {
            infojoueurs(compteur);
            compteur++;
            printf("le joueur a ete ajouter .\n");
        }
        else{
            printf("\n l'equipe est plein .\n");}
        break;
    case 2:
        int nombre;
        printf("veuillez saisir le nombre des joueurs a ajouter :\n");
        scanf("%d",&nombre);
    for(int i=0;i<nombre;i++){
        if (compteur<MAX){
                printf("Joueur %d\n",i+1);
            infojoueurs(compteur);
        compteur++;
        printf("le joueur a ete ajoute.\n");
        }
        else if
        (compteur>=MAX){
            printf("equipe pleine");}
    }
    default :
        printf("choix invalide");
}

}
void Afficher()
{
    int choix;

    if (compteur==0)
    {
        printf("aucun joueur pour le moment merci de l ajouter .\n");
        return;
    }
    printf("----------Menu d'affichage----------\n");
    printf(" 1 - Trier les joueurs par ordre alphabitique du nom .\n");
    printf(" 2 - Trier les joueurs par age .\n");
    printf(" 3 - Afficher les joueurs par poste.\n");

    printf("veuillez entrer votre choix :\n");
    scanf("%d",&choix);

    switch (choix)
    {

    case 1:
        Joueur nomTemporaire;
        for(int i=0; i<compteur-1; i++)
        {
            for (int j=0; j<compteur-1-i; j++)
            {
                if (strcasecmp(joueurs[j].nom,joueurs[j+1].nom)>0)
                {
                    nomTemporaire=joueurs[j];
                    joueurs[j]=joueurs[j+1];
                    joueurs[j+1]=nomTemporaire;
                }
            }
        }
        for (int i=0; i<compteur; i++)
        {
            printf(" id:%d|  nom:%s| prenom:%s| maillot:%d| post:5%s| age:5%d| buts:5%d  \n",
                   joueurs[i].id,
                   joueurs[i].nom,
                   joueurs[i].prenom,
                   joueurs[i].numeroMaillot,
                   joueurs[i].poste,
                   joueurs[i].age,
                   joueurs[i].buts);
        }
        break;
    case 2:
        Joueur ageTemporaire ;

        for(int i=0; i<compteur-1; i++)
        {
            for (int j=0; j<compteur-1-i; j++)
            {
                if (joueurs[j].age<joueurs[j+1].age)
                {

                    ageTemporaire=joueurs[j];
                    joueurs[j]=joueurs[j+1];
                    joueurs[j+1]=ageTemporaire;

                }
            }
        }
        for (int i=0; i<compteur; i++)
        {

            printf(" id:%d       nom:%s      prenom:%s       maillot:%d      post:%s     age:%d      buts:%d  \n",
                   joueurs[i].id,
                   joueurs[i].nom,
                   joueurs[i].prenom,
                   joueurs[i].numeroMaillot,
                   joueurs[i].poste,
                   joueurs[i].age,
                   joueurs[i].buts);
        }
        break;
    case 3:
            char posteprecise[50];
            int trouver=0;
            printf("saisir le poste que vous volue trouve :");
            getchar();
            fgets(posteprecise,50,stdin);

            for(int i=0; i<compteur; i++)
            {

                if (strcasecmp(joueurs[i].poste,posteprecise)==0)
                {
                    printf(" id:%d       nom:%s      prenom:%s       maillot:%d      post:%s     age:%d      buts:%d  \n",
                           joueurs[i].id,
                           joueurs[i].nom,
                           joueurs[i].prenom,
                           joueurs[i].numeroMaillot,
                           joueurs[i].poste,
                           joueurs[i].age,
                           joueurs[i].buts);

                    trouver =1;
                }


            }
            if (!trouver)
            {
                printf("aucun joueur trouver.");
            }


        break;
    default :
        printf("choix invalide");
    }

}

void supprimer()
{
    if (compteur==0)
    {

        printf("aucun joueur pour le moment merci de l ajouter .\n");
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
{
    int trouver =0;
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
                trouver=1;
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
            if(strcasecmp(joueurs[i].nom,chercherNom)==0)
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
    default:
        printf("choix invalide");
    }
}

void modifier()
{
    if (compteur==0){
        printf("aucun joueur merci de l ajouter .\n");
    }
    int choix=0;
    printf("----------menu de modification----------");
    printf(" 1 - Modifier le poste d’un joueur. ");
    printf(" 2 - Modifier l’âge d’un joueur.");
    printf(" 3 - Modifier le nombre de buts marqués par un joueur. ");
    printf("le choix est : ");
    scanf("%d",&choix);
getchar();
  int joueurModifier;
            printf("merci de saisir l id du joueur a modifier.");
            scanf("%d",&joueurModifier);
            int trouver=0;
    switch (choix)
    {
        case 1:

            for(int i=0; i<compteur; i++)
            {
                if (joueurs[i].id==joueurModifier)
                {
                    trouver=1;
                    printf("entrer le nouveau poste :");
                    fgets(joueurs[i].poste,50,stdin);
                    printf("-----poste modifier----");
                    }
            }
          break;
    case 2:
            for(int i=0; i<compteur; i++)
            {
                if (joueurs[i].id==joueurModifier)
                {
                    trouver=1;
                    printf("entrer le nouveau age");
                    scanf("%d",&joueurs[i].age);
                    printf("-----age modifier------");
                }
            }
        break;
    case 3:
      for(int i=0; i<compteur; i++)
            {
                if (joueurs[i].id==joueurModifier)
                {
                    trouver=1;
                    printf("entrer le nouveau nombre de buts");
                    scanf("%d",&joueurs[i].buts);
                    printf("-----nombre de buts a ete modifier------");
                }
            }
        break;

    default :
        printf("choix invalide.");

}
}
void statistique()
{
    int choix;

    printf("-----------menu----------\n");
    printf("  1 - Afficher le nombre total de joueurs dans l equipe.");
    printf("  2 - Afficher l age moyen des joueurs.");
    printf("  3 - Afficher les joueurs ayant marqué plus de X buts");
    printf("  4 - Afficher le meilleur buteur de l equipe.");
    printf("  5 - Afficher le joueur le plus jeune et le plus age.");


    printf("merci de choisir un choix :\n");
    scanf("%d",&choix);


    switch (choix)
    {
    case 1:
        printf("le nombre total des joueurs dans l equipe est %d",compteur);

        break;
    case 2:
        if(compteur==0){
        printf("aucun joueur pour calcule l age moyenne .\n");
        }
if (compteur<MAX){
    int sommeage;

}
        printf("l age moyen des joueurs est :");
        break;

    case 3:f h
        break;
    case 4:
        break;

    case 5:
        break;
    }


}


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
        printf(" 0 - Quitter  :\n");

        printf("saisir votre choix : ");
        scanf("%d",&choix);
        switch (choix)
        {
        case 1:
            Ajouter();
            break;
        case 2:
            Afficher();
            break;
        case 3:
            modifier();
            break;
        case 4:
            supprimer();
            break;
        case 5:
            rechercher();
            break;
        /*case 6:
            statistique();
            break;*/

        default:
            printf("choix invalide");
        }
    }
    while (choix!=0);
    return 0;
}
