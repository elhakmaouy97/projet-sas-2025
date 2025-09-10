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


} joueur ;
joueur joueurs [MAX];

int compteur=0;
int nvId=1;

void Ajouter()
{
    printf("vous pouvez saisie les donner de votre joueur.\n ");
    if (compteur<MAX)
    {
        joueurs[compteur].id=nvId++;
        getchar();
        printf("le nom du joueur est : ");
        fgets(joueurs[compteur].nom,sizeof joueurs[compteur].nom,stdin);

        printf("le prenom du joueur est : ");
        fgets(joueurs[compteur].prenom,sizeof joueurs[compteur].prenom,stdin);

        printf("le numero de maillot est : ");
        scanf("%d",&joueurs[compteur].numeroMaillot);

        printf("le poste du joueur est : ");
        scanf("%s",joueurs[compteur].poste);

        printf("l age du joueur est : ");
        scanf("%d",&joueurs[compteur].age);

        printf("le nombre du buts marquent par le joueur sont : ");
        scanf("%d",&joueurs[compteur].buts);
        compteur++;
        printf("le joueur a ete ajouter .");
    }
    else
    {
        printf("l'equipe est plein .\n");

    }
};
void AjouterPlusieur()
{
    int nombre;
    printf("veuillez saisir le nombre des joueurs a ajouter :\n");
    scanf("%d",&nombre);
    for(int i=0; i<nombre; i++)
    {
        if (compteur>=MAX)
        {
            printf("l equipe est deja plein :  \n");
            break;

        }
        else
        {
            printf("a ajouter %d \n",i+1);
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
};


void supprimer()
{
    if (compteur==0)
    {

        printf("auccun joueur pour le moment merci de l ajouter .\n");
        return ;
    }
    int supprimerid;
    printf("veuillez saisir l id du joueur que vous souhaitez supprimer:\n");
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
            printf("joueur supprimer avec succes.\n");
            trouver=1;
            break;
        }




    }

}


/*void modifier()
{
*/








void rechercher()
{
    int choix=0;
    printf("------------menu recherche-----------\n");
    printf(" 1 - Rechercher un joueur par Identifiant.\n");
    printf(" 2 - Rechercher un joueur par Nom.\n");
    printf("merci de choisir un choix:\n");
    scanf("%d",&choix);
    getchar();
    if (compteur==0)
    {
        printf("auccun joueur pour le moment merci d'ajouter des joueurs .\n");
    return;
    }
    if(choix==1){
        int chercherId;
        printf("veuillez saisir l id de votre joueur:\n");
        scanf("%d",&chercherId);
        getchar();
        int trouver=0;
        for(int i=0;i<compteur;i++){
            if (joueurs[i].id==chercherId){
                printf("joueur trouve :id:%d       nom:%s      prenom:%s       maillot:%d      post:%s     age:%d      buts:%d  \n",
               joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,joueurs[i].numeroMaillot,joueurs[i].poste,
               joueurs[i].age,joueurs[i].buts);

            trouver =1 ;
            break;
            }
        }
            if (trouver!=0){

                printf("auccun joueurs avec l id %d",chercherId);
            }





    }else if (choix==2){

    char chercherNom[50];
    printf("veuillez saisir le nom de votre joueur:\n");
    fgets(chercherNom,sizeof chercherNom,stdin);

    int trouver=0;
    for(int i=0;i<compteur;i++){
        if(strcmp(joueurs[i].nom,chercherNom)==0){
        printf("joueur trouve:id:%d       nom:%s      prenom:%s       maillot:%d      post:%s     age:%d      buts:%d  \n",
               joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,joueurs[i].numeroMaillot,joueurs[i].poste,
               joueurs[i].age,joueurs[i].buts);
               trouver=1;
               break;
        }


        }
        if (trouver!=0){
            printf("auccun joueur trouver");
        }

    }

else{
    printf("choix invalide");
}
}








int main()
{
    int choix=0;

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

        printf("saisir votre choix : \n");
        scanf("%d",&choix);
        switch (choix)
        {
        case 1:
            AjouterPlusieur();
            break;
        case 2:
            Afficher();
            break;
        /*case 3:
            modifier();
            break;*/
        case 4:
            supprimer();
            break;
        case 5:
            rechercher();
            break;


        }





    }
    while (choix!=0);
    return 0;

}
