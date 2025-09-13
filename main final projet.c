#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 50

typedef struct {

    int id;
    char nom[50];
    char prenom[50];
    int numeroMaillot;
    char poste[50];
    int age;
    int buts;
    char statut[50];
} joueur ;

joueur joueurs[50]= {
    {1, "Diallo", "Ousmane", 8, "Milieu", 24, 12, "Titulaire"},
    {2, "Benali", "Youssef", 3, "Defenseur", 27, 3, "Titulaire"},
    {3, "Fernandez", "Carlos", 11, "Attaquant", 22, 18, "Titulaire"},
    {4, "Muller", "Jonas", 1, "Gardien", 29, 0, "Titulaire"},
    {5, "Kouassi", "Jean", 5, "Défenseur", 21, 1, "Remplaçant"},
    {6, "Hamada", "Samir", 6, "Milieu", 23, 5, "Remplaçant"},
    {7, "Takahashi", "Kenji", 10, "Attaquant", 25, 20, "Titulaire"},
    {8, "Smith", "Jordan", 7, "Attaquant", 19, 8, "Remplaçant"}
};

int compteur=8;
int nvId=9;
void infojoueurs ()
{
    joueurs[compteur].id=nvId++; // 5 i++ ++i  1) ptint + incr 2) incre + prin
    getchar();
    printf("le nom du joueur est :");
    fgets(joueurs[compteur].nom,50,stdin);
    joueurs[compteur].nom[strcspn(joueurs[compteur].nom, "\n")] = '\0';

    printf("le prenom du joueur est :");
    fgets(joueurs[compteur].prenom,50,stdin);
    joueurs[compteur].prenom[strcspn(joueurs[compteur].prenom, "\n")] = '\0';

    printf("le numero de maillot est :");


    int nvnmmailloit;
    int trouver = 0;
    do{
        trouver = 0;
        scanf("%d",&nvnmmailloit);

         for(int i=0;i<compteur;i++){
            if (joueurs[i].numeroMaillot==nvnmmailloit){
                trouver=1;
                printf("numero existante merci choix un autre numero ");
                break;
            }
        }



    }while(trouver);
    joueurs[compteur].numeroMaillot = nvnmmailloit;
    getchar();




    printf("le poste du joueur est :");
    fgets(joueurs[compteur].poste,50,stdin);
    joueurs[compteur].poste[strcspn(joueurs[compteur].poste, "\n")] = '\0';

    printf("l age du joueur est :");
    scanf("%d",&joueurs[compteur].age);

    getchar();
    printf("le nombre de buts marquent par le joueur sont :");
    scanf("%d",&joueurs[compteur].buts);
    if(joueurs[compteur].buts>=10) {

        printf("\n**********STAR DE L EQUIPE**********\n %s %s avec %d buts \n",joueurs[compteur].prenom,joueurs[compteur].nom,joueurs[compteur].buts );
    }

    printf("\n le statut du joueur est:\n");
    fgets(joueurs[compteur].statut,50,stdin);
    joueurs[compteur].statut[strcspn(joueurs[compteur].statut, "\n")] = '\0';



    int choix_statut;
    do {

        printf(" 1-Titulaire \n");
        printf(" 2-Remplacant ");

        printf("\n saisir votre choix:\n");
        scanf("%d",&choix_statut);
        switch (choix_statut) {
        case 1 :
            strcpy(joueurs[compteur].statut,"Titulaire");
            break ;
        case 2 :
            strcpy(joueurs[compteur].statut,"Remplacent");
            break ;

        default :
            printf("choix invalide");
            break;
        }

    } while(choix_statut!=1&&choix_statut!=2);

}
void affiche_joueur(joueur j)
{
printf("id:%d | nom:%s | prenom:%s | maillot:%d | post:%s | age:%d | buts:%d | statut:%s\n",
           j.id, j.nom, j.prenom, j.numeroMaillot, j.poste, j.age, j.buts,j.statut);

}
void Ajouter()
{
    int choix;
    printf("----------menu ajouter-----------:\n");

    printf(" 1 - ajouter un seul joueur .\n");
    printf(" 2 - ajouter plusieur joueurs .\n");

    printf("veuillez entrez votre choix : ");
    scanf("%d",&choix);

    switch (choix) {
    case 1 :
        printf("entrez les donnes de votre joueur:\n");
        if (compteur<MAX) {
            infojoueurs();
            compteur++;
            printf("le joueur a ete ajouter .\n");
        } else {
            printf("\n l'equipe est pleine .\n");
        }
        break;
    case 2:
        int nombre;
        printf("veuillez saisir le nombre des joueurs a ajouter :\n");
        scanf("%d",&nombre);
        for(int i=0; i<nombre; i++) {
            if (compteur<MAX) {
                printf("Joueur %d\n",i+1);
                infojoueurs(compteur);
                compteur++;
                printf("le joueur a ete ajoute.\n");
            } else if
            (compteur>=MAX) {
                printf("equipe pleine.");
            }
        }
        break;
    default :
        printf("choix invalide.");
    }

}

void Afficher()
{
    int choix;

    if (compteur==0) {
        printf("aucun joueur pour le moment merci de l ajouter .\n");
        return;
    }
    printf("----------Menu d'affichage----------\n");
    printf(" 1 - Trier les joueurs par ordre alphabitique du nom .\n");
    printf(" 2 - Trier les joueurs par age .\n");
    printf(" 3 - Afficher les joueurs par poste.\n");

    printf("veuillez entrer votre choix :\n");
    scanf("%d",&choix);

    switch (choix) {

    case 1:
        joueur nomTemporaire;
        for(int i=0; i<compteur-1; i++) {
            for (int j=0; j<compteur-1-i; j++) {
                if (strcasecmp(joueurs[j].nom,joueurs[j+1].nom)>0) {
                    nomTemporaire=joueurs[j];
                    joueurs[j]=joueurs[j+1];
                    joueurs[j+1]=nomTemporaire;
                }
            }
        }
        for (int i=0; i<compteur; i++) {
            affiche_joueur(joueurs[i]);
        }
        break;
    case 2:
        joueur ageTemporaire ;

        for(int i=0; i<compteur-1; i++) {
            for (int j=0; j<compteur-1-i; j++) {
                if (joueurs[j].age<joueurs[j+1].age) {

                    ageTemporaire=joueurs[j];
                    joueurs[j]=joueurs[j+1];
                    joueurs[j+1]=ageTemporaire;

                }
            }
        }
        for (int i=0; i<compteur; i++) {
            affiche_joueur(joueurs[i]);
        }
        break;
    case 3:
        int trouver;
        int count=1;
        // gardian
        for(int i=0; i<compteur; i++) {

            if (strcasecmp(joueurs[i].poste,"gardien")==0) {
                printf("-----gardien-------");
                affiche_joueur(joueurs[i]);

                trouver =1;
            }


        }
        if (!trouver) {
            printf("aucun joueur trouver.\n");
        }
                // attacks

        for (int i=0; i<compteur; i++) {

            if (strcasecmp(joueurs[i].poste,"attaquant")==0) {
                printf("--------attaquant--------");
                affiche_joueur(joueurs[i]);

                trouver =1;
            }


        }
        if (!trouver) {
            printf("aucun joueur trouver.\n");
        }
        // defenseur
        for (int i=0; i<compteur; i++) {

            if (strcasecmp(joueurs[i].poste,"defenseur")==0) {
                printf("----------defenseur---------");
                affiche_joueur(joueurs[i]);

                trouver =1;
            }


        }
        if (!trouver) {
            printf("aucun joueur trouver.\n");
        }

        // Millieu
        for (int i=0; i<compteur; i++) {

            if (strcasecmp(joueurs[i].poste,"milieu")==0) {
                printf("----------milieu-----------");
                affiche_joueur(joueurs[i]);

                trouver =1;
            }


        }
        if (!trouver) {
            printf("aucun joueur trouver.\n");
        }


        break;
    default :
        printf("choix invalide");
    }

}

void supprimer()
{
    if (compteur==0) {

        printf("aucun joueur pour le moment merci de l ajouter .\n");
        return ;
    }
    int supprimerid;
    printf("veuillez saisir l id du joueur que vous souhaitez supprimer:\n");
    scanf("%d",&supprimerid);
    int trouver=0;
    for (int i=0; i<compteur; i++) {
        if (joueurs[i].id==supprimerid) {
            for (int j=i; j<compteur-1; j++) {
                joueurs[j]=joueurs[j+1];
            }
            compteur--;
            printf("joueur avec id %d supprimer avec succe.\n",supprimerid);
            trouver=1;
            break;
        }
    }
    if (trouver==0) {
        printf("aucun joueur trouver .\n");
    }


}


void rechercher()
{
    int trouver =0;
    if (compteur==0) {
        printf("aucun joueur pour le moment merci d'ajouter des joueurs .\n");
        return;
    }
    int choix=0;


    printf("------------menu recherche-----------\n");


    printf(" 1 - Rechercher un joueur par Identifiant.\n");
    printf(" 2 - Rechercher un joueur par Nom.\n");

    printf("merci de choisir un choix:\n");
    scanf("%d",&choix);
    getchar();

    switch(choix) {
    case 1:
        int chercherId;
        printf("veuillez saisir l id de votre joueur:\n");
        scanf("%d",&chercherId);
        getchar();

        for(int i=0; i<compteur; i++) {
            if (joueurs[i].id==chercherId) {
                printf("----------joueur trouve--------\n");
                affiche_joueur(joueurs[i]);
                trouver=1;
                break;
            }
        }
        if (trouver==0) {
            printf("aucun joueur avec l id %d",chercherId);
        }
        break;
    case 2:
        char chercherNom[50];
        printf("veuillez saisir le nom de votre joueur:\n ");
        fgets(chercherNom,50,stdin);
        chercherNom[strcspn(chercherNom, "\n")] = '\0';

        for(int i=0; i<compteur; i++) {
            if(strcasecmp(joueurs[i].nom,chercherNom)==0) {
                printf("joueur trouve:\n");
                affiche_joueur(joueurs[i]);
                trouver=1;
                break;
            }
        }

        if (trouver ==0) {
            printf("aucun joueur trouver par ce nom");
        }
    default:
        printf("choix invalide");
    }
}

void modifier()
{
    if (compteur==0) {
        printf("aucun joueur merci de l ajouter .\n");
    }
    int choix=0;
    printf("----------menu de modification----------\n");
    printf(" 1 - Modifier le poste d un joueur. \n");
    printf(" 2 - Modifier l age d un joueur._\n");
    printf(" 3 - Modifier le nombre de buts marques par un joueur. \n");
    printf("le choix est : ");
    scanf("%d",&choix);
    getchar();
    int joueurModifier;
    printf("merci de saisir l id du joueur a modifier.\n");
    scanf("%d",&joueurModifier);
    int trouver=0;
    switch (choix) {
    case 1:

    char nouveau_poste[50];
    for (int i=0;i<compteur;i++){
        if(joueurs[i].id==joueurModifier){
           trouver=1;
            printf("entrer le nouveau poste :");
            getchar();
            fgets(nouveau_poste,50,stdin);
            nouveau_poste[strcspn(nouveau_poste,"\n")]='\0';

            strcpy(joueurs[i].poste,nouveau_poste);
            printf("-----poste modifier----\n");
        }
    }
if (!trouver){
printf("aucun joueur trouve");
}


        break;
    case 2:
        for(int i=0; i<compteur; i++) {
            if (joueurs[i].id==joueurModifier) {
                trouver=1;
                printf("entrer le nouvel age:\n");
                scanf("%d",&joueurs[i].age);

            }
        }
        printf("-----age modifier------\n");
        break;
    case 3:
        for(int i=0; i<compteur; i++) {
            if (joueurs[i].id==joueurModifier) {
                trouver=1;
                printf("entrer le nouveau nombre de buts:\n");
                scanf("%d",&joueurs[i].buts);
                printf("-----nombre de buts a ete modifier------\n");

            }
        }


        break;

    default :
        printf("choix invalide.\n");

    }
}
void statistique()
{
    int choix;

    printf("-----------menu----------\n");

    printf("  1 - Afficher le nombre total de joueurs dans l equipe.\n");
    printf("  2 - Afficher l age moyen des joueurs.\n");
    printf("  3 - Afficher les joueurs ayant marque plus de X buts.\n");
    printf("  4 - Afficher le meilleur buteur de l equipe.\n");
    printf("  5 - Afficher le joueur le plus jeune et le plus age.\n");


    printf("merci de choisir un choix :\n");
    scanf("%d",&choix);


    switch (choix) {
    case 1:
        printf("le nombre total des joueurs dans l equipe est %d",compteur);

        break;
    case 2:
        int totalAge = 0;
        for(int i =0 ; i < compteur ; i++ ) {
            totalAge = totalAge + joueurs[i].age;
        }
        float moyenne = (float)totalAge / compteur;
        printf("la moyenne des ages de jouer %.2f \n", moyenne);
        break;

    case 3:
        int x;
        printf("veuillez saisir le nombre de buts a afficher:\n");
        scanf("%d",&x);
        for (int i=0; i<compteur; i++) {
            if  (joueurs[i].buts>=x) {
                affiche_joueur(joueurs[i]);
            }
        }
        break;
    case 4:
        int maxbuts=0;
        for(int i=0; i<compteur; i++) {


            if (joueurs[i].buts>maxbuts) {
               maxbuts = joueurs[i].buts;

            }

        }
        printf("le meilleur buteur : \n");
        for(int i=0; i<compteur; i++) {


            if(joueurs[i].buts == maxbuts) {
                affiche_joueur(joueurs[i]);
            }

        }
        break;

    case 5:
        int maxage=0;
        for(int i=0; i<compteur; i++) {
            if(joueurs[i].age>maxage) {
                maxage=joueurs[i].age;
            }

        }
        printf("le joueur le plus age est : \n");

        for(int i=0; i<compteur; i++) {
            if(joueurs[i].age==maxage) {
                affiche_joueur(joueurs[i]);
            }
        }

        int minage=joueurs[0].age;
        for(int i=1; i<compteur; i++) {
            if(joueurs[i].age<minage) {
                minage=joueurs[i].age;
            }

        }
        printf("le joueur le plus jeune : \n");

        for(int i=0; i<compteur; i++) {
            if(joueurs[i].age==minage) {
                affiche_joueur(joueurs[i]);
            }
        }
        break;
    }


}

int main()
{
    int choix;

    do {
        printf("\n----------Menu----------\n");

        printf(" 1 - Ajouter un joueur:\n");
        printf(" 2 - Afficher la liste de tous les joueurs:\n");
        printf(" 3 - Modifier un joueur:\n");
        printf(" 4 - Supprimer un joueur:\n");
        printf(" 5 - Rechercher un joueur:\n");
        printf(" 6 - Statistiques:\n");
        printf(" 0 - Quitter  :\n");

        printf("saisir votre choix : \n");



        if(scanf("%d",&choix)!=1){
            printf("choix invalide");
            while (getchar()!='\n');
            choix=-1;
            continue ;

        }
        switch (choix) {
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
        case 6:
            statistique();
            break;
        case 0:
            printf("AU REVOIR...!");

        default:
            printf("choix invalide.\n");
        }
    } while (choix!=0);
    return 0;
}

