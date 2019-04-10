
/*
 **************************************
 *  implémentation du module maillon  *
*           (Modèle des LLC)          *
 **************************************
*/


#include <stdio.h>
#include <stdlib.h>	/// pour malloc et free
#include <string.h>
#include "utilisateur.h"


void creation_DataB ()
{

  /// Initialisation de la base de donnees
     /// Begin
    for (int i=0 ; i<26 ;i++)
        {
            tableau[i] = malloc( sizeof(utilisateur) );
        }

    printf("Initialisation de base de donnees : \n");
    printf("*********************************\n\n");
    int A = 65 ;
    for (int i=0 ; i<26 ;i++)
        {
            tableau[i]->nom[0] = A ;
            A++ ;
            tableau[i]->nom[1] = '\0' ;
            tableau[i]->suivant = NULL ;
            tableau[i]->precedent = NULL ;
        }

    /// End .

}
/*
 **************************************
 *          Machine abstraire         *
 *                                    *
 **************************************
*/
////////////////////////////////////////////////////////////////////////

void allouer( utilisateur** p )
/// c-a-d struct maillon **p
{
    *p = malloc( sizeof(utilisateur) );
}
///////////////////////////////////////////////////////////////////////

void liberer (utilisateur** p )
{
    free( *p );
}

//////////////////////////////////////////////////////////////////////

void aff_nom(utilisateur* p , char* name)
{
    strcpy(p->nom,name) ;
}
///////////////////////////////////////////////////////////////////////

void aff_ville(utilisateur* p , char* village)
{
    strcpy(p->ville,village);

}
///////////////////////////////////////////////////////////////////////
void aff_adr (utilisateur* p , utilisateur* q)
{
    p->suivant = q ;
}
///////////////////////////////////////////////////////////////////////

utilisateur* suivant (utilisateur* p )
{
            return p->suivant ;
}
//////////////////////////////////////////////////////////////////////////////

utilisateur* precedent (utilisateur* p )
{
            return p->precedent ;
}
///////////////////////////////////////////////////////////////////////
/*
 **************************************
 *        Autres Fonctions            *
 *                                    *
 **************************************
*/

utilisateur* detect_lettre (char* chaine )
{
    int i = -1 ; char charactere ; utilisateur* pointeur ;
    charactere = chaine[0] - 32 ; /// pour traduire la lettre en majuscule .
    do
    {
       i++ ;

    } while (charactere != tableau[i]->nom[0] || i > 26 );
    if ( i >= 26){ printf("\n\n     Desole , Mais la lettre entree n'est pas valide...") ;}
    else
    {
        pointeur = tableau[i] ;
    }

            return pointeur ;
}
///////////////////////////////////////////////////////////////////////////////7

utilisateur* creation_utilisateur(utilisateur* dernier_utilisateur ,char* name)
{
    utilisateur* q ;
    allouer(&q);
    aff_nom(q,name);
    printf("\n Nom de Ville  : ");
    scanf("%s",q->ville);
    printf("Centre d'interet (nombre binaire de 8 chiffres pr ex [11001100]): ") ;
    long interet;
    scanf("%ld",&interet);
    q->octet=interet ;
    aff_adr(dernier_utilisateur,q);
    q->precedent = dernier_utilisateur ;
    aff_adr(q,NULL) ;
    printf("\n                    \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
    printf("\n");


            return q ;

}
//////////////////////////////////////////////////////////////////////////////

void suppression (char* nom)
{
    utilisateur *first_lettre , *p , *q ;
    first_lettre = detect_lettre(nom);

    do
    {

       while(  ( strcmp(first_lettre->nom , nom)!= 0 )&& first_lettre!= NULL )
        {
            first_lettre = suivant(first_lettre);
        }

        if (first_lettre!=NULL)
        {
            p = first_lettre ;
            q = precedent(first_lettre);
            aff_adr(q, suivant(p));
            p=suivant(p);
        //  p->precedent = NULL ;
            liberer(&p);
            printf("\n\t\t\t ###L'utilisateur [%s] a ete supprimme ...###\n\n",nom);
            first_lettre = suivant(first_lettre);
        }else ( printf("\n\t\t\t ###L'utilisateur [%s] n'existe pas ...###\n\n",nom) );


    } while (first_lettre != NULL) ;



}

//////////////////////////////////////////////////////////////////////







