#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

// Déclaration des structures

typedef struct
{
    char rue[50];
    char ville[50];
    int codePostal;
}adresse;
typedef struct
{
    char tel[10];
    char nom[30], prenom[30];
    adresse adr;
    char dateNaissance[12];
    char email[50]
}repertoire;
struct cellule
{
    repertoire info;
    struct cellule *suiv;
};
typedef struct cellule* LISTE_REP;

#endif // STRUCTURE_H_INCLUDED
