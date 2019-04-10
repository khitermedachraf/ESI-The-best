#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilisateur.h"







int main()
{
    creation_DataB();
    int choix =0 ;
   do
   {


                /// Afficher le Menu initial.
            ///Begin
        printf("\n     #Services disponibles sur l'app : \n");
        printf("     *********************************\n\n");
        printf("\t\t\t\t\t\t\t\t Connection au tant qu'un administrateur systeme $:\n");
        printf("\t\t\t\t\t\t\t\t root@root@root@root@root@root@root@root@root@root@\n\n");
        printf("1- Creation d'un nouveau utilisateur .\n");
        printf("2- Suppression d'un utilisateur .\n");
        printf("3- Modification d'un utilisateur .\n");
        printf("4- Affichage d'un utilisateur .\n");
        printf("5- L'affichage de tous les contacts suivis par un utilisateur .\n") ;
        printf("99- Exit .\n\n");
        printf("     #Votre choix est : ");
        scanf("%d",&choix);
        printf("\n\n ");
        printf("\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" ) ;

            ///End .


/// Traitement d'information
        ///Begin

    switch (choix)
{
case 1: /// Creation d'un nouveau utilisateur
       printf("\n\n Nom d'utilisateur : ");
       char newname[25] ;
       scanf("%s",newname);
       utilisateur* tete ;
       tete = detect_lettre(newname);/// Detecter en quelle case[26 cases = 26 lettres] il faut stocker le nom d'utilisateur

       int cpt0= 1   ;
       static utilisateur* last_user = NULL; /// [static] pour que la variable sea creer juste pr la 1ere fois .
       utilisateur* pointeur0 ;
       pointeur0 = tete ;
       while (suivant(pointeur0 )!= NULL)
       {
           cpt0 ++ ;
           pointeur0 =suivant(pointeur0) ;

       }

       if (cpt0 == 1  )
       {

           last_user = tete ;
           last_user = creation_utilisateur(last_user,newname) ;
       }
     else { last_user = creation_utilisateur(last_user,newname) ; }




    break;
case 2:
   printf("\n\n Nom d'utilisateur : ");
    char newname1[25] ;
    scanf("%s",newname1);
    suppression(newname1);
  break;
case 3:
  printf("Salut jeune !");
  break;
case 4:
  printf("Salut ado !");
  break;
case 99:
  printf(" ");
  break;
default:
  printf("\n\n\t\tVous avez entrer un faux choix ... \n\n");
  printf("\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n\n" ) ;
  break;
}


        ///End.

   } while (choix!= 99) ;




    return 0;
}
