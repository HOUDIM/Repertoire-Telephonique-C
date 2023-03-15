#ifndef MAJ_H_INCLUDED
#define MAJ_H_INCLUDED

// MENU AJOUTER

LISTE_REP Ajout_tete_nouvel_tel(LISTE_REP LR)
{
    repertoire x;
    x=saisie_telephone(LR);
    LR=insere_tete_tel(LR,x);
    MessageBox(hwnd,"Votre ajout est effectue avec succes!","Confirmation!",MB_OK | MB_ICONINFORMATION);
    return LR;
}

LISTE_REP Ajout_queue_nouvel_tel(LISTE_REP LR)
{
    repertoire x;
    x=saisie_telephone(LR);
    LR=insere_queue_tel(LR,x);
    MessageBox(hwnd,"Votre ajout est effectue avec succes!","Confirmation!",MB_OK | MB_ICONINFORMATION);
    return LR;
}

LISTE_REP Ajout_position_nouvel_tel(LISTE_REP LR)
{
    int rep,pos ,t;
    repertoire x;
    t=taille_liste_rep(LR);
    do
    {
        printf("\n - Donnez une position entre 1 et %d : ", t+1);
        scanf("%d",&pos);
    }while(!(pos>=1 && pos<=t+1));
    x=saisie_telephone(LR);
    insere_pos_tel(LR,pos,x);
    MessageBox(hwnd,"Votre ajout est effectue avec succes!","Confirmation!",MB_OK | MB_ICONINFORMATION);
    return LR;
}

// MENU SUPPRIMER

LISTE_REP Suppresion_tete_tel ( LISTE_REP LR )
{
    LR=supprimer_tete_tel(LR);
    MessageBox(hwnd,"Votre suppression est effectuee avec succes!","Confirmation!",MB_OK | MB_ICONINFORMATION);
    return LR;
}

LISTE_REP Suppresion_queue_tel ( LISTE_REP LR )
{
    LR=supprimer_queue_tel(LR);
     MessageBox(hwnd,"Votre suppression est effectuee avec succes!","Confirmation!",MB_OK | MB_ICONINFORMATION);
    return LR;
}

LISTE_REP Suppresion_pos_tel ( LISTE_REP LR )
{
    int t,pos;
    t=taille_liste_rep(LR);
    do
    {
        gotoxy(9,15); printf("\n - Donnez une position ( > 1 et < %d ) : ", t+1);
        gotoxy(3,17); printf("+------------+---------------------+");
        gotoxy(3,18); printf("|Position    |                     |");
        gotoxy(3,19); printf("+------------+---------------------+");
        gotoxy(26,18); printf("                ");
        gotoxy(26,18);
        scanf("%d",&pos);
    }while(!(pos>=1 && pos<=t+1));
    supprimer_pos_tel(LR,pos);
    MessageBox(hwnd,"Votre suppression est avec succes!","Confirmation!",MB_OK | MB_ICONINFORMATION);
    return LR;
}

LISTE_REP Suppresion_tel_donnee ( LISTE_REP LR )
{
    char num[10];
    do
    {
        gotoxy(9,15);printf("\n - Donnez le telephone que vous voulez supprimer : ");
        gotoxy(3,17); printf("+---------------------+--------------------------+");
        gotoxy(3,18); printf("|Numero de telephone  |                          |");
        gotoxy(3,19); printf("+---------------------+--------------------------+");
        gotoxy(26,18); printf("                ");
        gotoxy(26,18);
        scanf("%s",&num);
    }while (test(LR,num)==0);

    LR=supprimer_tel_donnee(LR,num);
    MessageBox(hwnd,"Votre suppression est effectuee avec succes!","Confirmation!",MB_OK | MB_ICONINFORMATION);
    printf("\n\n\n");
    return LR;
}

// Suppression des telephones d'une ville donnee

LISTE_REP Suppr_tel_ville_donnee(LISTE_REP LR, char* x ,int*sup )
{
    LISTE_REP p=LR,q;
    int ok =0;
    if (LR == NULL)
        return LR;

    if(strcmp((p->info.adr.ville),x) == 0)
    {
        LR=p->suiv;
        free(p);
        *sup = 1;
    }
    else
    {
        while(p->suiv!=NULL)
            if(strcmp((p->suiv)->info.adr.ville,x) == 0)
            {
                ok=1;
                break;
            }
            else
                {p=p->suiv;}
        if(ok)
        {
            q=p->suiv;
            p->suiv=q->suiv;
            free(q);
            *sup = 1;
        }
    }
    return LR;
}

LISTE_REP Suppresion_tel_ville_donnee ( LISTE_REP LR )
{
    LISTE_REP p=LR,q;
    int ok =0, sup=0;
    char x[50];
        gotoxy(9,15);printf("\n - Donnez une ville  : ");
        gotoxy(3,17); printf("+----------+--------------------------+");
        gotoxy(3,18); printf("|Ville     |                          |");
        gotoxy(3,19); printf("+----------+--------------------------+");
        gotoxy(26,18); printf("                ");
        gotoxy(26,18);
        gets(x);
    do{
        sup=0;
        LR=Suppr_tel_ville_donnee(LR,x,&sup);
        int t =taille_liste_rep(LR);
    }while(sup);
     MessageBox(hwnd,"Votre suppression est effectuee avec succes!","Confirmation!",MB_OK | MB_ICONINFORMATION);
    return LR;
}




LISTE_REP recherche_indicatif(LISTE_REP LR, char indicatif[4])
{
    LISTE_REP p=LR;
    long int val,num;
    num=atol(indicatif);
    while(p)
    {
        val=atol(p->info.tel);
        if(val/1000000==num)
            return p;
        p=p->suiv;
    }
    return NULL;
}

LISTE_REP suppression_indicatif_donnee(LISTE_REP LR,char ind[])
{
    LISTE_REP p1=LR,p2=LR,p3=LR;
    long int val,val2,num;
    num=atol(ind);
    for (p3=LR;p3;p3=p3->suiv)
    {
        val=atol(p1->info.tel);
        if(val/1000000==num)
        {
            LR=supprimer_tete_tel(LR);
            p1=p1->suiv;
        }
        while(p1)
        {
            val2=atol(p1->info.tel);
            if(val2/1000000==num)
            {
                while(p2->suiv!=p1)
                p2=p2->suiv;
                p2->suiv=p1->suiv;
                free(p1);
            }
            p1=p1->suiv;
        }
        p1=LR;
    }
    return LR;
}

LISTE_REP Suppresion_tel_indicatif_donne (LISTE_REP LR)
{
    char indicatif[4];

    do
    {
        printf("\n\tDonner l'indicatif (2 chiffres): ");
        fflush(stdin);
        gets(indicatif);
    }while(!(strlen(indicatif)==2 && recherche_indicatif(LR,indicatif)));
    LR=suppression_indicatif_donnee(LR,indicatif);
     MessageBox(hwnd,"Votre suppression est effectuee avec succes!","Confirmation!",MB_OK | MB_ICONINFORMATION);
    return LR;
}


LISTE_REP recherche_tel(LISTE_REP LR, char tel[])
{
    LISTE_REP p=LR;
    while(p)
    {
        if(strcmp(p->info.tel,tel)==0)
            return p;
        p=p->suiv;
    }
    return NULL;
}

void affiche1(LISTE_REP l,char x[])
{
    LISTE_REP p=l;
    while(p)
    {
        if (strcmp(x,p->info.tel)==0)
        {
            printf("%s|%s|%s|%s|%s|%d|%s|%s\n",p->info.tel,p->info.nom,p->info.prenom,p->info.adr.rue,p->info.adr.ville,p->info.adr.codePostal,p->info.dateNaissance,p->info.email);
            break;
        }
        else
            p=p->suiv;
    }
}

void affiche_tel_donne(LISTE_REP l)
{
    char nump[10];
    do
    {
        printf("Donner le numero telephone du contact que vous voulez afficher: ");
        fflush(stdin);gets(nump);
    }while(!(recherche_tel(l,nump)&&strlen(nump)==8&&verif_chiffre(nump)!=0));
    printf("\nTel\t\tNom\tPrenom\t\tDate de naissance\tAdresse\t\t\tEmail\n\n");
    affiche1(l,nump);
}


void modification_tel_donne(LISTE_REP LR)
{
    LISTE_REP p1=LR;
    int ok=0;
    char nump[10],numnouv[10];
    do
    {
        printf("Donner le numero telephone du contact que vous voulez modifier: ");
        fflush(stdin);
        gets(nump);
    }while(!(recherche_tel(LR,nump)&&strlen(nump)==8&&verif_chiffre(nump)!=0));
    do
    {
        printf("\nDonner un nouveau telephone: ");
        fflush(stdin);gets(numnouv);
    }while(recherche_tel(LR,numnouv)||strlen(numnouv)!=8||verif_chiffre(numnouv)==0);
    while (p1&&ok==0)
    {
        if(strcmp(p1->info.tel,nump)==0)
        {
            strcpy(p1->info.tel,numnouv);
            ok=1;
        }
        else
            p1=p1->suiv;
    }
}

void modification_adresse_donnee(LISTE_REP LR)
{
    LISTE_REP p1=LR;
    int ok=0;
    char nump[10];
    adresse nvadresse;
    do
    {
        printf("Donner le numero telephone du contact que vous voulez modifier: ");
        fflush(stdin);gets(nump);
    }while(!(recherche_tel(LR,nump)&&strlen(nump)==8&&verif_chiffre(nump)!=0));
    printf("\n\n\t\tSAISIE DE LA NOUVELLE ADRESSE\n");
    printf("\n\tRue: ");
    fflush(stdin);gets(nvadresse.rue);
    do
    {
        printf("\n\tVille: ");
        fflush(stdin);gets(nvadresse.ville);
    }while(verif_carac(nvadresse.ville)==1);
     char x[6]="";
    do
    {
        printf("\n\tCode Postal: ");
        fflush(stdin);
        scanf("%d",&nvadresse.codePostal);

        itoa(nvadresse.codePostal,x,10);
    }while(test(LR,x)== 1 || strlen(x) != 4  || verif_chiffre(x)==0 || x[0]=='0');

    while (p1&&ok==0)
    {
        if(strcmp(p1->info.tel,nump)==0)
        {
            strcpy(p1->info.adr.rue,nvadresse.rue);
            strcpy(p1->info.adr.ville,nvadresse.ville);
            (p1->info.adr.codePostal)=nvadresse.codePostal;

            ok=1;
        }
        else
            p1=p1->suiv;
    }
}

void TRI(LISTE_REP LR)
{
    LISTE_REP p1,p2;
    repertoire aux;
    p1=LR;
    while(p1->suiv!=NULL)
    {
        p2=p1->suiv;
        while(p2!=NULL)
        {
            if(strcmp((p1->info.tel),(p2->info.tel))<0)
            {
                aux=p1->info;
                p1->info=p2->info;
                p2->info=aux;
            }
            p2=p2->suiv;
        }
        p1=p1->suiv;
    }
    affiche_liste(LR);
}

void affiche2(LISTE_REP LR)
{
 if(LR==NULL)
  printf("liste est vide ");
 else
 {
    printf("\nTel\t\tnom\tprenom\t\tdate naissance\tadresse\t\t\tmail\n\n");
    while(LR)
    {
        printf("%s|%s|%s|%s|%s|%d|%s|%s\n",LR->info.tel,LR->info.nom,LR->info.prenom,LR->info.adr.rue,LR->info.adr.ville,LR->info.adr.codePostal,LR->info.dateNaissance,LR->info.email);
        LR=LR->suiv;
    }
 }
}

LISTE_REP recherche_nom(LISTE_REP LR, char mat[])
{
    LISTE_REP p=LR;
    while(p)
    {
        if(strcmp(p->info.nom,mat)==0)
            return p;
        p=p->suiv;
    }
    return NULL;
}

void affiche_nom_donne(LISTE_REP LR)
{
    LISTE_REP p1=LR;
    char nvnom[10];
    do
    {
        printf("Donner le nom du contact que vous voulez afficher: ");
        fflush(stdin);gets(nvnom);
    }while( recherche_nom(LR,nvnom) || verif_carac(nvnom)==0);
    printf("\nTel\t\tNom\tPrenom\t\tDate de naissance\tAdresse\t\t\tEmail\n\n");
    while(p1)
    {
        if (strcmp(p1->info.nom,nvnom)==0)
            affiche1(LR,p1->info.tel);
        p1=p1->suiv;
    }
}

/******************Fonction Affiche d'un Indicatif Donne******************/
void affiche_indicatif_donne(LISTE_REP LR)
{
    LISTE_REP p1=LR;
    long int val,num;
    char ind[10];
    do
    {
        printf("Donner un indicatif du contact que vous voulez afficher (2 chiffres): ");
        fflush(stdin);gets(ind);
    }while(!(verif_chiffre(ind)!=0&&strlen(ind)==2&&recherche_indicatif(LR,ind)));
    num=atol(ind);
    printf("\nTel\t\tNom\tPrenom\t\tDate de naissance\tAdresse\t\t\tEmail\n\n");
    while(p1)
    {
        val=atol(p1->info.tel);
        if (val/1000000==num)
            affiche1(LR,p1->info.tel);
        p1=p1->suiv;
    }
}

LISTE_REP recherche_ville(LISTE_REP LR, char mat[])
{
    LISTE_REP p=LR;
    while(p)
    {
        if(strcmp(p->info.adr.ville,mat)==0)
            return p;
        p=p->suiv;
    }
    return NULL;
}


/******************Fonction Affiche d'une Ville Donnee******************/
void affiche_ville_donne(LISTE_REP LR)
{
    LISTE_REP p1=LR;
    adresse nv;
    do
    {
        printf("\n\tDonner la ville du contact que vous voulez afficher: ");
        fflush(stdin);gets(nv.ville);
    }while(!(recherche_ville(LR,nv.ville)&&verif_carac(nv.ville)!=0));
    printf("\nTel\t\tNom\tPrenom\t\tDate de naissance\tAdresse\t\t\tEmail\n\n");
    while(p1)
    {
        if (strcmp(p1->info.adr.ville,nv.ville)==0)
            affiche1(LR,p1->info.tel);
        p1=p1->suiv;
    }
}

#endif // MAJ_H_INCLUDED
