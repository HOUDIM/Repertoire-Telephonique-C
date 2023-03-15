#ifndef CREATION_H_INCLUDED
#define CREATION_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "fonctions_generales.h"

HWND hwnd;

// Test de verifictaion d'existance de num telephone

int test(LISTE_REP LR , char num[50])
{
    LISTE_REP p=LR;
    while(p!=NULL)
    {
        if (strcmp(p->info.tel,num)==0)
            return 1;
        p=p->suiv;
    }
    return 0;
}

// Test de verification des chiffres

int verif_chiffre (char num[])
{
    int i;
    for(i=0;i<strlen(num);i++)
    {
        if (isdigit(num[i])== 0)
            return 0;
    }
    return 1;
}

// Test de verification des caracteres

int verif_carac (char num[])
{
    int i;
    for(i=0;i<strlen(num);i++)
    {
        if (isalpha(num[i])!= 0)
            return 0;
    }
    return 1;
}

// verification de date de naissance

int convert(char date[50]) {
    char string[50] ;
    strcpy(string,date);
    int tab[3];
    int day;
    int month;
    int year;

    char * token = strtok(string, "/");
    int i=0;
    while( token != NULL ) {
        tab[i]= atoi(token);
        i++;
        if(i>2){
            break;
        }
        token = strtok(NULL, "/");
    }

    if(tab[0]<1 || tab[0]>31){
        return 0;
      }
    if(tab[1]<1 || tab[1]>12){
        return 0;
    }
    if(tab[2]<1){
        return 0;
    }
    if(tab[0] ==29 && tab[1]==2 && tab[2]%4==0){
        return 1;
      }
    if(tab[0] >29 && tab[1]==2 && tab[2]%4==0){
        return 0;
      }
    if(tab[0] >28 && tab[1]==2 && tab[2]%4!=0){
        return 0;
    }

}


int verif_date(char d[50])
{
    int sl=0;

    for(int j=0; j < strlen(d); j++)
    {
        if (d[j]=='/')                 // compter le nbr de '/'
            sl++;
    }
    if (sl!=2)                         // la chaine ne doit contenir que 2 '/'
        return 0;
    else
    {
        if( d[2]!='/' || d[5]!='/')     // les '/' doivent etre aux 3eme et 6eme positions
            return 0;
        else
        {
            convert(d);
        }
    }
}


//Verification de l'adresse e-mail

int verif_email(char x[])
{
    int i,adrr=0,y,j,point_ap=0,point_av=0,espace=0;

    for (int s=0;s<strlen(x);s++)
    {
        if (x[s]==' ')
                espace++;      // nombre des espaces tout au long de la chaine
    }
    if (espace!=0)          // l'adresse e-mail ne doit contenir aucun espace
        return 0;
    else
    {

    for (j=0;j<strlen(x);j++)  // compter le nombre de '@'
    {
        if (x[j]=='@')
            {
                adrr++;
                y=j;            // garder la position de '@'
            }
    }
    if (adrr!=1)              // verification de nombre d'existence de '@'
        return 0;
    else
    {
        for (int t=0; t < y; t++)
        {
            if (x[t]=='.')
                point_av++;        //compter le nombre de '.' qui existent avant '@'
        }
        if (point_av > 1 || point_av < 0)            //le nombre de '.' qui existent avant '@' ne doit etre egal qu'au plus a 1
            return 0;
        else
        {
            if (x[0]=='@' || isdigit(x[0])==1 || x[0] == '.' ) // le premier caractere doit etre different de '.' , '@' ou un chiffre
                return 0;
            else
            {
                if ( x[y+1] == '.' || x[y-1] == '.')   // les caracteres avant et apres '@' ne doivent pas etre des '.'
                    return 0;
                else
                {
                    for (int z=y; z <= strlen(x) ; z++)
                    {
                        if ( x[z] == '.')
                            point_ap++;                 // compter le nombre de '.' qui se trouvent apres '@'
                    }
                    if (point_ap!=1)                    // le nombre de '.' ne doit etre égal que a 1
                        return 0;
                    else
                        return 1;
            }
        }
        }
    }

    }

}

// verification de l'espace

int verif_espace(char x[])
{
    for (int i=0;i<strlen(x)-1;i++)
    {
        if ( x[i]==' '&& x[i+1]==' ' )
            return 0;
    }
            return 1;
}

// Affichage et saisie des donnees

repertoire saisie_telephone(LISTE_REP LR)
{
    repertoire rep;
    char x[6];

    gotoxy(3,9);  printf("+---------------------+---------------------------------------------------------------+");
    gotoxy(3,10); printf("|Numero de telephone  |                                    ");
    gotoxy(3,11); printf("+---------------------+---------------------------------------------------------------+");
    gotoxy(3,12); printf("|                    Nom et prenom                         ");
    gotoxy(3,13); printf("+---------------------+---------------------------------------------------------------+");
    gotoxy(3,14); printf("|Nom                  |                                    ");
    gotoxy(3,15); printf("+---------------------+---------------------------------------------------------------+");
    gotoxy(3,16); printf("|Prenom               |                                    ");
    gotoxy(3,17); printf("+---------------------+---------------------------------------------------------------+");
    gotoxy(3,18); printf("|                       Adresse                            ");
    gotoxy(3,19); printf("+---------------------+---------------------------------------------------------------+");
    gotoxy(3,20); printf("|Rue                  |                                    ");
    gotoxy(3,21); printf("+---------------------+---------------------------------------------------------------+");
    gotoxy(3,22); printf("|Ville                |                                    ");
    gotoxy(3,23); printf("+---------------------+---------------------------------------------------------------+");
    gotoxy(3,24); printf("|Code postal          |                                    ");
    gotoxy(3,25); printf("+---------------------+---------------------------------------------------------------+");
    gotoxy(3,26); printf("|                   Date de naissance                      ");
    gotoxy(3,27); printf("+---------------------+---------------------------------------------------------------+");
    gotoxy(3,28); printf("|Date de naissance    |                                    ");
    gotoxy(3,29); printf("+---------------------+---------------------------------------------------------------+");
    gotoxy(3,30); printf("|                   Adresse e-mail                         ");
    gotoxy(3,31); printf("+---------------------+---------------------------------------------------------------+");
    gotoxy(3,32); printf("|Adresse e-mail       |                                    ");
    gotoxy(3,33); printf("+---------------------+---------------------------------------------------------------+");

    //saisie de telephone

    do
    {

        gotoxy(27,10);printf("                          ");
        gotoxy(27,10);
        fflush(stdin);
        gets(rep.tel);
    }while (test(LR,rep.tel)== 1 || strlen(rep.tel) != 8  || verif_chiffre(rep.tel)==0);

    //saisie de nom

    do
    {
        gotoxy(27,14);printf("                                  ");
        gotoxy(27,14);
        fflush(stdin);
        gets(rep.nom);
    }while (verif_carac(rep.nom)==1 || verif_espace(rep.nom)==0);


    //saisie de prenom

    do
    {
        gotoxy(27,16);printf("                                  ");
        gotoxy(27,16);
        fflush(stdin);
        gets(rep.prenom);;
    }while (verif_carac(rep.prenom)==1 || verif_espace(rep.prenom)==0);


    //saisie de rue

    do
    {
        gotoxy(27,20);printf("                                  ");
        gotoxy(27,20);
        fflush(stdin);
        gets(rep.adr.rue);
    }while (verif_espace(rep.adr.rue)==0);


    //saisie de ville

    do
    {
        gotoxy(27,22);printf("                                  ");
        gotoxy(27,22);
        fflush(stdin);
        gets(rep.adr.ville);
    }while (verif_carac(rep.adr.ville)==1 || verif_espace(rep.adr.ville)==0 );


    //saisie de code postal

     do
    {
        gotoxy(27,24);printf("                                  ");
        gotoxy(27,24);
        fflush(stdin);
        scanf("%d",&rep.adr.codePostal);
        itoa(rep.adr.codePostal,x,10);
    }while (test(LR,x)== 1 || strlen(x) != 4  || verif_chiffre(x)==0 || (rep.adr.codePostal < 1000 && rep.adr.codePostal > 9999));


    // saisie de date de naissance

    do
    {
        gotoxy(27,28);printf("                                  ");
        gotoxy(27,28);
        fflush(stdin);
        gets(rep.dateNaissance);
    }while ( strlen(rep.dateNaissance) != 10 || verif_date(rep.dateNaissance)==0 );

    // saisie de l'adresse e-mail
    do
    {
      gotoxy(27,32);printf("                                  ");
    gotoxy(27,32);
    fflush(stdin);
    gets(rep.email);

    }while(verif_email(rep.email)==0);


    return rep;
}


LISTE_REP creation(LISTE_REP LR)
{
    int rep,pos ,t;

    repertoire x;
    do
    {
        x=saisie_telephone(LR);
        LR=insere_tete_tel(LR,x);
        do
        {
            printf("\n\n Voulez vous ajouter un autre contact? ( saisissez 1 pour confirmer / 0 pour annuler ) :");
            scanf("%d",&rep);
        }while(!(rep==1 || rep==0));

    }while(rep);
    MessageBox(hwnd,"Creation de repertoire terminee!","Confirmation!",MB_OK | MB_ICONINFORMATION);
    printf("\n\n");
    system("cls");
    return LR;
}




#endif // CREATION_H_INCLUDED
