#ifndef FONCTIONS_GENERALES_H_INCLUDED
#define FONCTIONS_GENERALES_H_INCLUDED

#include <stdio.h>
#include "structure.h"


// Taille de répertoire

int taille_liste_rep(LISTE_REP LR)
{
    LISTE_REP p=LR;
    int t=0;
    while(p!=NULL)
    {   t++;
        p=p->suiv;
    }
    return  t;
}

// Insertion tete / queue / position

LISTE_REP insere_tete_tel(LISTE_REP LR, repertoire x )
{
    LISTE_REP p;
    p=(struct cellule*)malloc(sizeof(struct cellule));
    p->suiv=LR;
    p->info=x;
    LR=p;
    return LR;
}

LISTE_REP insere_queue_tel( LISTE_REP LR, repertoire x )
{
   LISTE_REP p1,p2;
    p1=(struct cellule*)malloc(sizeof(struct cellule));
    p1->info=x;
    p1->suiv=NULL;
    if(LR==NULL)
        LR=p1;
    else
    {
        p2=LR;
        while(p2->suiv!=NULL)
            p2=p2->suiv;
        p2->suiv=p1;
    }
    return LR;
}

void insere_pos_tel(LISTE_REP LR, int pos,repertoire x )
{
    LISTE_REP p2,p1=LR;
    int i=1;

    while(i<pos-1)
    {
      p1=p1->suiv;
      i++;
    }
    p2=(struct cellule*)malloc(sizeof(struct cellule));
    p2->info=x;
    p2->suiv=p1->suiv;
    p1->suiv=p2;

}

// Suppression tete / queue / position

LISTE_REP supprimer_tete_tel ( LISTE_REP LR )
{
    LISTE_REP p=LR;
    if ( LR==NULL)
    printf ( " liste vide \n " ) ;
    else
    {
        LR=LR ->suiv;
        free ( p );
    }
    return LR;
}

LISTE_REP supprimer_queue_tel ( LISTE_REP LR )
{
    LISTE_REP p=LR ;
    if ( LR==NULL)
        printf ( " Suppression impossible \n " );
    else
        if ( LR->suiv==NULL)
        {
            LR=LR->suiv;
            free ( p );
        }
        else
        {
            while ( ( p->suiv )->suiv != NULL )
                p=p->suiv;
            free ( p->suiv );
            p->suiv=NULL;
        }
    return LR ;
}

void supprimer_pos_tel ( LISTE_REP LR, int pos )
{
    LISTE_REP p1=LR , p2;
    int i =LR;
    if ( pos !=LR && pos!= taille_liste_rep(LR) )
    {
        while (i<pos-1)
        {
            i ++;
            p1=p1->suiv;
        }
        p2=p1->suiv;
        p1->suiv=p2->suiv;
        free (p2);
    }
}


// Suppression d'un telephone donne

LISTE_REP supprimer_tel_donnee(LISTE_REP LR, char x[] )
{
    LISTE_REP p1=LR,p2;
    int ok=0;

    if(strcmp(p1->info.tel,x)==0)
        LR=supprimer_tete_tel(LR);
    else
    {
        while(p1->suiv)
        {
            if(strcmp(p1->suiv->info.tel,x)==0)
            {
                ok=1;
                break;
            }
            else
                p1=p1->suiv;
        }

        if(ok==1)
        {
            p2=p1->suiv;
            p1->suiv=p2->suiv;
            free(p2);
        }
    }
    return LR;
}


// ffichage des informations de la liste

void affiche_liste (LISTE_REP LR)
{
    repertoire x;
    int taille = taille_liste_rep(LR);

                        gotoxy(1,12); printf("+----------+----------------+---------------+-----------------------------+----------------+-------------+------------------+-----------------------------------------+");
                        gotoxy(1,14); printf("|Telephone |Nom             |Prenom         |Rue                          |Ville           |Code postal  |Date de naissance |Adresse e-mail                           |");
                        gotoxy(1,16); printf("+----------+----------------+---------------+-----------------------------+----------------+-------------+------------------+-----------------------------------------+");
int z=18,i=0;
                        for(int y=0;y<taille;y++)
                        {
                            gotoxy(1,z+i); printf("                           ");
                            i=i+2;
                            gotoxy(1,z+i); printf("+----------+----------------+---------------+-----------------------------+----------------+-------------+------------------+-----------------------------------------+");
                            i=i+2;
                        }
z=18,i=0;
        while(LR!=NULL)
        {
                        gotoxy(1,z+i); printf("|%8s ",LR->info.tel);
                        gotoxy(12,z+i); printf("|%s ",LR->info.nom);
                        gotoxy(29,z+i); printf("|%s ",LR->info.prenom);
                        gotoxy(45,z+i); printf("|%s ",LR->info.adr.rue);
                        gotoxy(75,z+i); printf("|%s ",LR->info.adr.ville);
                        gotoxy(92,z+i); printf("|%d ",LR->info.adr.codePostal);
                        gotoxy(106,z+i); printf("|%s ",LR->info.dateNaissance);
                        gotoxy(125,z+i); printf("|%s ",LR->info.email);
                        LR=LR->suiv;
                        i=i+4;
        }
        printf("\n\n\n\n");

}










#endif // FONCTIONS_GENERALES_H_INCLUDED
