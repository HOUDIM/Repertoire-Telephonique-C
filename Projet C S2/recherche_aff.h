#ifndef RECHERCHE_AFF_H_INCLUDED
#define RECHERCHE_AFF_H_INCLUDED



































/*void recherche_par_numero (LISTE_REP LR)
{
    int i,r=0;
    char num[50];
    int n;
    n=taille_liste_rep(LR);
    printf("Entrer le numero : ");
    scanf("%s",&num);
    if(n>0){
        for(i=0;i<n;i++)
            {
                if(strcmp(LR->info.tel,num)==0){
                    r=1;
                  }
                else
                    r=0;
               if(r==1){
                    printf("\n----------------------------------------------------\n\n");
                    printf("\nNumero : %s\tNom : %s\t  Prenom : %s\tRue : %s\tVille : %d\tCode Podtal : %s\tDate de naissance : %s\tAdresse e-mail : %s \n",LR->info.tel,LR->info.nom,LR->info.prenom,LR->info.adr.rue,LR->info.adr.ville,LR->info.adr.codePostal,LR->info.dateNaissance,LR->info.email);
                    printf("\n----------------------------------------------------\n\n");
                    break;
               }
               else
               printf("\n Ce numero n'existe pas dans le repertoire.\n\n");
            }
        }
        else printf("\n\n Repertoire vide\n\n");
}

liste_rep recherche_tel(liste_rep l, char mat[])
{
    liste_rep p=l;
    while(p)
    {
        if(strcmp(p->info.numtel,mat)==0)
            return p;
        p=p->suiv;
    }
    return NULL;
}

void recherche_par_ville (LISTE_REP LR)
{
    int t=0,i,r=0;
    char ville[50];
    int n;
    n=taille_liste_rep(LR);
    printf("\n%d\n",n);
    printf("Entrez une ville : ");
    scanf("%s",&ville);

    if(n>0){
            printf("\ndok\n");
        for(i=0;i<n;i++)
            {
                if(strcmp(LR->info.adr.ville,ville)==0){
                    r=1;
                    printf("\nrok\n");
                  }
                else
                    printf("\nlok\n");
                    r=0;
               if(r==1){
                    printf("\nmok\n");
                    printf("\n----------------------------------------------------\n\n");
                    printf("\nNumero : %s\tNom : %s\t  Prenom : %s\tRue : %s\tVille : %d\tCode Podtal : %s\tDate de naissance : %s\tAdresse e-mail : %s \n",LR->info.tel,LR->info.nom,LR->info.prenom,LR->info.adr.rue,LR->info.adr.ville,LR->info.adr.codePostal,LR->info.dateNaissance,LR->info.email);
                    printf("\n----------------------------------------------------\n\n");
               }
               else
               printf("\nyok\n");
                t=t+1;
            }
            if (t==n-1)
            {
                printf("\nok\n");
              printf("\n Cette ville n'existe pas dans le repertoire.\n\n");
            }
        }
        else printf("\n\n Repertoire vide\n\n");
}*/

























#endif // RECHERCHE_AFF_H_INCLUDED
