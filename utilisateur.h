
/*
 *********************************
 *  interface du module maillon  *
 *      (Modèle des LLC)         *
 *********************************
*/


#include <stdio.h>
#include <stdlib.h>	/// pour malloc et free
#include <string.h>

#ifndef UTILISATEUR
#define UTILISATEUR


/// Creation d'une structure d'enregistrement
///        pour chaque utilisateure
typedef struct utilisateur utilisateur ;
 ;
struct utilisateur
{
    char  nom[25] ;
    char  ville[100] ;
    long  octet ;
    utilisateur* followings ;
    utilisateur* suivant ;
    utilisateur* precedent ;
};

/// Creation de la base de donnees
utilisateur* tableau [26];

/// Declaration des fonctions
void creation_DataB ();
/*
 **************************************
 *          Machine abstraire         *
 *                                    *
 **************************************
*/
void Allouer( utilisateur** p );/// Creer un nouveau maillon .
void liberer (utilisateur** p );/// Liberer un maillon .
void aff_nom(utilisateur* p , char* nom) ; /// affecter le nom pour l'utilisateur
void aff_ville(utilisateur* p , char* ville) ; /// affecter la ville pour l'utilisateur
void aff_adr (utilisateur* p , utilisateur* q) ; /// indiquer que (q) et le suivant de (p) .
utilisateur* suivant (utilisateur* p );/// Donner le suivant du maillon .
utilisateur* precedent (utilisateur* p );/// Donner le precedent du maillon .
///////////////////////////////////////////////////////////////////////////////////////////////////
/*
 **************************************
 *        Autres Fonctions            *
 *                                    *
 **************************************
*/
utilisateur* detect_lettre (char* chaine );/// Detecter en quelle case[26 cases = 26 lettres] il faut stocker le nom d'utilisateur
utilisateur* creation_utilisateur(utilisateur* dernier_utilisateur,char* name) ; /// c est pour creer un nouveau utilisateur .
void suppression (char* nom) ; ///   c est pour supprimer un utilisateur .






#endif


