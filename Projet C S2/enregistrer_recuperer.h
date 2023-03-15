#ifndef ENREGISTRER_RECUPERER_H_INCLUDED
#define ENREGISTRER_RECUPERER_H_INCLUDED

HWND hwnd;

void enregistrement(LISTE_REP LR, char * nomfichier)
{
    FILE *file;
    LISTE_REP p=LR;


    file = fopen(nomfichier,"w");

    while(p)
    {
        fprintf(file,"%s|%s|%s|%s|%s|%d|%s|%s\n",p->info.tel,p->info.nom,p->info.prenom,p->info.adr.rue,p->info.adr.ville,p->info.adr.codePostal,p->info.dateNaissance,p->info.email);
        p=p->suiv;

    }
    fclose(file);

}

LISTE_REP recuperation ()
{
    repertoire x;

    FILE *fp;
    LISTE_REP LR=NULL;
    fp = fopen("repertoire.txt","r");

    if (fp == NULL)
        MessageBox(hwnd,"Le fichier est vide!","Attention!",MB_YESNO | MB_ICONQUESTION );
     else
        {
        while(!feof(fp))
            {
                fscanf(fp,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d|%[^|]|%s\n",x.tel,x.nom,x.prenom,x.adr.rue,x.adr.ville,&x.adr.codePostal,x.dateNaissance,x.email);
                LR=insere_queue_tel(LR,x);
            }
    }


    fclose(fp);
    return LR;
}




#endif // ENREGISTRER_RECUPERER_H_INCLUDED
