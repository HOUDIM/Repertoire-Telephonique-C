#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <myconio.h>
#include <stdio.h>
#include <windows.h>
#include <wchar.h>
#include "creation.h"
#include "enregistrer_recuperer.h"
#include "fonctions_generales.h"
#include "MaJ.h"
#include "recherche_aff.h"
#include "structure.h"


char * nomfichier;
char x[50];
LISTE_REP LR;

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
void addmenus(HWND);
void CreateBtt(HWND hwnd) ;

HWND hname ,hage,hout,hogo,Add,Finnish;
 HDC hdc;
HMENU hmenu ;

HBITMAP hlogoImage , hgenerateImage;
int intro=1 ;
char ch[30] ;
long p ;
/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("my project");

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND+7;


    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("My Project_DIMASSI Houssem_DIMASSI Khouloud"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           1250,                 /* The programs width */
           768,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */



LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{static HBITMAP  hBmp;


   /* if(intro)
    {
        system("start test.exe") ;
        intro=0;
    }*/

    switch (message)                  /* handle the messages */
    {

        case WM_COMMAND:
        switch(wParam)
        {
            case 1:

                if (LR != NULL)
                {
                    MessageBox(hwnd,"Il existe deja une liste!","Attention!",MB_OK | MB_ICONWARNING);
                    system("cls");
                }
                else
                {
                    system("color F3");
                    ShowWindow(hwnd,SW_HIDE);
                    gotoxy(25,5);
                    printf(" ***** CREATION D'UN NOUVEAU REPERTOIRE ***** \n\n\n");
                    LR=creation(LR);
                    system("pause");
                    ShowWindow(hwnd,SW_NORMAL);
                    system("cls");
                }
                    break;
            case 2:

                    if (LR == NULL)
                    {
                        if (MessageBox(hwnd,"La liste est vide! Voulez-vous recuperer la liste?","Attention!",MB_YESNO | MB_ICONQUESTION ) == IDYES)
                            {
                                LR=recuperation(LR);
                                MessageBox(hwnd,"La liste est recuperee","Confirmation!",MB_OK | MB_ICONINFORMATION );
                                system("cls");
                            }
                    }
                    else
                    {
                        system("color F3");
                        ShowWindow(hwnd,SW_HIDE);
                        gotoxy(25,5);
                        printf(" ***** AJOUT EN TETE D'UN NOUVEL TELEPHONE ***** \n\n\n");
                        LR=Ajout_tete_nouvel_tel(LR);
                        system("pause");
                        ShowWindow(hwnd,SW_NORMAL);
                        system("cls");
                    }

                    break;
            case 3:
                    if (LR == NULL)
                    {
                        if (MessageBox(hwnd,"La liste est vide! Voulez-vous recuperer la liste?","Attention!",MB_YESNO | MB_ICONQUESTION ) == IDYES)
                            {
                                LR=recuperation(LR);
                                MessageBox(hwnd,"La liste est recuperee","Confirmation!",MB_OK | MB_ICONINFORMATION );
                                system("cls");
                            }
                    }
                    else
                    {
                    system("color F3");
                    ShowWindow(hwnd,SW_HIDE);
                    gotoxy(25,5);
                    printf(" ***** AJOUT EN QUEUE D'UN NOUVEL TELEPHONE ***** \n\n\n");
                    LR=Ajout_queue_nouvel_tel(LR);
                    system("pause");
                    ShowWindow(hwnd,SW_NORMAL);
                    system("cls");
                    }

                    break;
            case 4:
                    if (LR == NULL)
                    {
                        if (MessageBox(hwnd,"La liste est vide! Voulez-vous recuperer la liste?","Attention!",MB_YESNO | MB_ICONQUESTION ) == IDYES)
                            {
                                LR=recuperation(LR);
                                MessageBox(hwnd,"La liste est recuperee","Confirmation!",MB_OK | MB_ICONINFORMATION );
                                system("cls");
                            }
                    }
                    else
                    {
                    system("color F3");
                    ShowWindow(hwnd,SW_HIDE);
                    gotoxy(25,5);
                    printf(" ***** AJOUT D'UN NOUVEL TELEPHONE A UNE POSITION DONNEE ***** \n\n\n");
                    LR=Ajout_position_nouvel_tel(LR);
                    system("pause");
                    ShowWindow(hwnd,SW_NORMAL);
                    system("cls");
                    }
                    break;
            case 5:
                    if (LR == NULL)
                    {
                        if (MessageBox(hwnd,"La liste est vide! Voulez-vous recuperer la liste?","Attention!",MB_YESNO | MB_ICONQUESTION ) == IDYES)
                            {
                                LR=recuperation(LR);
                                MessageBox(hwnd,"La liste est recuperee","Confirmation!",MB_OK | MB_ICONINFORMATION );
                                system("cls");
                            }
                    }
                    else
                    {
                    system("color F3");
                    ShowWindow(hwnd,SW_HIDE);
                    gotoxy(25,5);
                    printf(" ***** SUPPRESSION EN TETE D'UN TELEPHONE ***** \n\n\n");
                    LR=Suppresion_tete_tel(LR);
                    system("pause");
                    ShowWindow(hwnd,SW_NORMAL);
                    system("cls");
                    }
                    break;
            case 6:
                    if (LR == NULL)
                    {
                        if (MessageBox(hwnd,"La liste est vide! Voulez-vous recuperer la liste?","Attention!",MB_YESNO | MB_ICONQUESTION ) == IDYES)
                            {
                                LR=recuperation(LR);
                                MessageBox(hwnd,"La liste est recuperee","Confirmation!",MB_OK | MB_ICONINFORMATION );
                                system("cls");
                            }
                    }
                    else
                    {
                    system("color F3");
                    ShowWindow(hwnd,SW_HIDE);
                    gotoxy(25,5);
                    printf(" ***** SUPPRESSION EN QUEUE D'UN TELEPHONE ***** \n\n\n");
                    LR=Suppresion_queue_tel ( LR );
                    system("pause");
                    ShowWindow(hwnd,SW_NORMAL);
                    system("cls");
                    }
                    break;
            case 7:
                    if (LR == NULL)
                    {
                        if (MessageBox(hwnd,"La liste est vide! Voulez-vous recuperer la liste?","Attention!",MB_YESNO | MB_ICONQUESTION ) == IDYES)
                            {
                                LR=recuperation(LR);
                                MessageBox(hwnd,"La liste est recuperee","Confirmation!",MB_OK | MB_ICONINFORMATION );
                                system("cls");
                            }
                    }
                    else
                    {
                    system("color F3");
                    ShowWindow(hwnd,SW_HIDE);
                    gotoxy(25,10);
                    printf(" ***** SUPPRESSION D'UN TELEPHONE A PARTIR D'UNE POSITION DONNEE ***** \n\n\n");
                    LR=Suppresion_pos_tel(LR);
                    system("pause");
                    ShowWindow(hwnd,SW_NORMAL);
                    system("cls");
                    }
                    break;
            case 8:
                    if (LR == NULL)
                    {
                        if (MessageBox(hwnd,"La liste est vide! Voulez-vous recuperer la liste?","Attention!",MB_YESNO | MB_ICONQUESTION ) == IDYES)
                            {
                                LR=recuperation(LR);
                                MessageBox(hwnd,"La liste est recuperee","Confirmation!",MB_OK | MB_ICONINFORMATION );
                                system("cls");
                            }
                    }
                    else
                    {
                    system("color F3");
                    ShowWindow(hwnd,SW_HIDE);
                    gotoxy(25,10);
                    printf(" ***** SUPPRESSION D'UN TELEPHONE DONNEE ***** \n\n\n");
                    LR=Suppresion_tel_donnee(LR);
                    system("pause");
                    ShowWindow(hwnd,SW_NORMAL);
                    system("cls");
                    }
                    break;
            case 9:
                    if (LR == NULL)
                    {
                        if (MessageBox(hwnd,"La liste est vide! Voulez-vous recuperer la liste?","Attention!",MB_YESNO | MB_ICONQUESTION ) == IDYES)
                            {
                                LR=recuperation(LR);
                                MessageBox(hwnd,"La liste est recuperee","Confirmation!",MB_OK | MB_ICONINFORMATION );
                                system("cls");
                            }
                    }
                    else
                    {
                    system("color F3");
                    ShowWindow(hwnd,SW_HIDE);
                    gotoxy(25,10);
                    printf(" ***** SUPPRESSION D'UN TELEPHONE D'UNE VILLE DONNEE ***** \n\n\n");
                    LR=Suppresion_tel_ville_donnee(LR);
                    system("pause");
                    ShowWindow(hwnd,SW_NORMAL);
                    system("cls");
                    }
                    break;
            case 10:
                    if (LR == NULL)
                    {
                        if (MessageBox(hwnd,"La liste est vide! Voulez-vous recuperer la liste?","Attention!",MB_YESNO | MB_ICONQUESTION ) == IDYES)
                            {
                                LR=recuperation(LR);
                                MessageBox(hwnd,"La liste est recuperee","Confirmation!",MB_OK | MB_ICONINFORMATION );
                                system("cls");
                            }
                    }
                    else
                    {
                    system("color F3");
                    ShowWindow(hwnd,SW_HIDE);
                    gotoxy(25,10);
                    printf(" ***** SUPPRESSION D'UN TELEPHONE D'UN INDICATIF DONNEE ***** \n\n\n");
                    LR=Suppresion_tel_indicatif_donne (LR);
                    system("pause");
                    ShowWindow(hwnd,SW_NORMAL);
                    system("cls");
                    }
                    break;
            case 11:
                    if (LR == NULL)
                    {
                        if (MessageBox(hwnd,"La liste est vide! Voulez-vous recuperer la liste?","Attention!",MB_YESNO | MB_ICONQUESTION ) == IDYES)
                            {
                                LR=recuperation(LR);
                                MessageBox(hwnd,"La liste est recuperee","Confirmation!",MB_OK | MB_ICONINFORMATION );
                                system("cls");
                            }
                    }
                    else
                    {
                    system("color F3");
                    ShowWindow(hwnd,SW_HIDE);
                    gotoxy(25,10);
                    printf(" ***** MODIFICATION D'UNE ADRESSE ***** \n\n\n");
                    modification_adresse_donnee(LR);
                    system("pause");
                    ShowWindow(hwnd,SW_NORMAL);
                    system("cls");
                    }
                    break;
            case 12:
                if (LR == NULL)
                    {
                        if (MessageBox(hwnd,"La liste est vide! Voulez-vous recuperer la liste?","Attention!",MB_YESNO | MB_ICONQUESTION ) == IDYES)
                            {
                                LR=recuperation(LR);
                                MessageBox(hwnd,"La liste est recuperee","Confirmation!",MB_OK | MB_ICONINFORMATION );
                            }
                    }
                    else
                    {
                    system("color F3");
                    ShowWindow(hwnd,SW_HIDE);
                    gotoxy(25,10);
                    printf(" ***** MODIFICATION D'UN TELEPHONE ***** \n\n\n");
                    modification_tel_donne(LR);
                    system("pause");
                    ShowWindow(hwnd,SW_NORMAL);
                    system("cls");
                    }
                    break;
            case 13:
                if (LR == NULL)
                    {
                        if (MessageBox(hwnd,"La liste est vide! Voulez-vous recuperer la liste?","Attention!",MB_YESNO | MB_ICONQUESTION ) == IDYES)
                            {
                                LR=recuperation(LR);
                                MessageBox(hwnd,"La liste est recuperee","Confirmation!",MB_OK | MB_ICONINFORMATION );
                            }
                    }
                    else
                    {
                    system("color F3");
                    ShowWindow(hwnd,SW_HIDE);
                    gotoxy(25,10);
                    printf(" ***** CONTENU DE LA LISTE DES TELEPHONES ***** \n\n\n");
                    affiche_liste (LR);
                    system("pause");
                    ShowWindow(hwnd,SW_NORMAL);
                    system("cls");
                    }
                    break;
            case 14:
                if (LR == NULL)
                    {
                        if (MessageBox(hwnd,"La liste est vide! Voulez-vous recuperer la liste?","Attention!",MB_YESNO | MB_ICONQUESTION ) == IDYES)
                            {
                                LR=recuperation(LR);
                                MessageBox(hwnd,"La liste est recuperee","Confirmation!",MB_OK | MB_ICONINFORMATION );
                            }
                    }
                    else
                    {
                    system("color F3");
                    ShowWindow(hwnd,SW_HIDE);
                    gotoxy(25,10);
                    printf(" ***** RECHERCHE PAR NUMERO TELEPHONE ***** \n\n\n");
                    affiche_tel_donne(LR);
                    system("pause");
                    ShowWindow(hwnd,SW_NORMAL);
                    system("cls");
                    }
                    break;
            case 15:
               if (LR == NULL)
                    {
                        if (MessageBox(hwnd,"La liste est vide! Voulez-vous recuperer la liste?","Attention!",MB_YESNO | MB_ICONQUESTION ) == IDYES)
                            {
                                LR=recuperation(LR);
                                MessageBox(hwnd,"La liste est recuperee","Confirmation!",MB_OK | MB_ICONINFORMATION );
                            }
                    }
                    else
                    {
                    system("color F3");
                    ShowWindow(hwnd,SW_HIDE);
                    gotoxy(25,10);
                    printf(" ***** RECHERCHE PAR NOM ***** \n\n\n");
                    affiche_nom_donne(LR);
                    system("pause");
                    ShowWindow(hwnd,SW_NORMAL);
                    system("cls");
                    }
                    break;
            case 16:
                if (LR == NULL)
                    {
                        if (MessageBox(hwnd,"La liste est vide! Voulez-vous recuperer la liste?","Attention!",MB_YESNO | MB_ICONQUESTION ) == IDYES)
                            {
                                LR=recuperation(LR);
                                MessageBox(hwnd,"La liste est recuperee","Confirmation!",MB_OK | MB_ICONINFORMATION );
                            }
                    }
                    else
                    {
                    system("color F3");
                    ShowWindow(hwnd,SW_HIDE);
                    gotoxy(25,10);
                    printf(" ***** RECHERCHE PAR INDICATIF TELEPHONE ***** \n\n\n");
                    affiche_indicatif_donne(LR);
                    system("pause");
                    ShowWindow(hwnd,SW_NORMAL);
                    system("cls");
                    }
                    break;
            case 17:
                if (LR == NULL)
                    {
                        if (MessageBox(hwnd,"La liste est vide! Voulez-vous recuperer la liste?","Attention!",MB_YESNO | MB_ICONQUESTION ) == IDYES)
                            {
                                LR=recuperation(LR);
                                MessageBox(hwnd,"La liste est recuperee","Confirmation!",MB_OK | MB_ICONINFORMATION );
                            }
                    }
                    else
                    {
                    system("color F3");
                    ShowWindow(hwnd,SW_HIDE);
                    gotoxy(25,10);
                    printf(" ***** RECHERCHE PAR VILLE ***** \n\n\n");
                    affiche_ville_donne(LR);
                    system("pause");
                    ShowWindow(hwnd,SW_NORMAL);
                    system("cls");
                    }
                    break;
            case 18:
                if (LR == NULL)
                    {
                        if (MessageBox(hwnd,"La liste est vide! Voulez-vous recuperer la liste?","Attention!",MB_YESNO | MB_ICONQUESTION ) == IDYES)
                            {
                                LR=recuperation(LR);
                                MessageBox(hwnd,"La liste est recuperee","Confirmation!",MB_OK | MB_ICONINFORMATION );
                            }
                    }
                    else
                    {
                    system("color F3");
                    ShowWindow(hwnd,SW_HIDE);
                    gotoxy(25,10);
                    printf(" ***** TRI PAR ORDRE DECROISSANT DU NUMERO DE TELEPHONE ***** \n\n\n");
                    TRI(LR);
                    system("pause");
                    ShowWindow(hwnd,SW_NORMAL);
                    system("cls");
                    }
                    break;
            case 19:
                    if (MessageBox(hwnd,"Voulez vous enregistrer votre modification!","Attention!",MB_YESNO | MB_ICONQUESTION)==IDYES)
                    {
                        system("color F3");
                        ShowWindow(hwnd,SW_HIDE);
                        gotoxy(25,10);
                        printf(" ***** ENREGISTREMENT ***** \n\n\n");
                        enregistrement(LR,"repertoire.txt");
                        system("pause");
                        ShowWindow(hwnd,SW_NORMAL);
                        system("cls");
                    }
                    break;
            case 20:
                    if (LR != NULL)
                    {
                        MessageBox(hwnd,"Vous avez deja recupere la liste!","Attention!",MB_YESNO | MB_ICONQUESTION);
                    }
                    else
                    {
                    LR=recuperation ("repertoire.txt");
                    MessageBox(hwnd,"Liste recupree avec succes!","Recuperation",MB_OK | MB_ICONASTERISK);

                    system("cls");
                    }
                    break;
            case 21:
                    ShellExecute(NULL,"open","projet.pdf",NULL,NULL,SW_SHOWNORMAL);
                    break;

            case 22:
                    ShellExecute(NULL,"open","repertoire.txt",NULL,NULL,SW_SHOWNORMAL);
                    break;


        case 23:
                if (MessageBox(hwnd,"       Vous voulez quitter ?", "QUITTER", MB_YESNO | MB_ICONQUESTION ) == IDYES)
                {

                    DestroyWindow(hwnd);
                    system("cls");
                }
            break;
        }
    case WM_CREATE :
        addmenus(hwnd);
//         CreateBtt(hwnd) ;
            /*****************ajouter fond **********************/
            hBmp=LoadImage(NULL,"PL.bmp",IMAGE_BITMAP,1370,700,LR_LOADFROMFILE);

            break;

        case WM_PAINT :
            {
         PAINTSTRUCT ps;
            hdc = BeginPaint(hwnd, &ps);

            DrawState(hdc,NULL,NULL,(long)hBmp,0,0,0,0,0,DST_BITMAP);

            EndPaint(hwnd, &ps);}
        break;
        case WM_DESTROY:
            PostQuitMessage (0);        /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

void addmenus(HWND hwnd)
{
    hmenu=CreateMenu();
    HMENU update=CreateMenu();
    HMENU add_num=CreateMenu();
    HMENU remove_num=CreateMenu();
    HMENU modify=CreateMenu();
    HMENU search=CreateMenu();
    HMENU plus=CreateMenu();
    HMENU record=CreateMenu();

    //AppendMenu(hmenu,MF_STRING,0,"création du repertoire");
    /*******************************************************/
    AppendMenu(hmenu,MF_STRING,1,"Création du répertoire téléphonique");
/***************************************************************/
    AppendMenu(hmenu,MF_POPUP,(UINT_PTR)update,"Mise à jour des téléphones");
        AppendMenu(update,MF_POPUP,(UINT_PTR)add_num,"Ajouter téléphone");
            AppendMenu(add_num,MF_STRING,2,"Ajout en tête");
            AppendMenu(add_num,MF_STRING,3,"Ajout en queue");
            AppendMenu(add_num,MF_STRING,4,"Ajout dans une position");
        AppendMenu(update,MF_POPUP,(UINT_PTR)remove_num,"Supprimer un téléphone");
            AppendMenu(remove_num,MF_STRING,5,"Suppression en tête");
            AppendMenu(remove_num,MF_STRING,6,"Suppression en queue");
            AppendMenu(remove_num,MF_STRING,7,"Suppression à partir d'une position");
            AppendMenu(remove_num,MF_STRING,8,"Suppression d'un téléphone donné");
            AppendMenu(remove_num,MF_STRING,9,"Suppression des téléphones d'une ville donnée");
            AppendMenu(remove_num,MF_STRING,10,"Suppression des télépohnes d'un indicatif donné");
        AppendMenu(update,MF_POPUP,(UINT_PTR)modify,"Modifier les données d'un téléphone");
            AppendMenu(modify,MF_STRING,11,"Modifier adresse");
            AppendMenu(modify,MF_STRING,12,"Modifier téléphone");
/***************************************************************/
     AppendMenu(hmenu,MF_POPUP,(UINT_PTR)search,"Recherche affichage et tri");
        AppendMenu(search,MF_STRING,13,"Contenu de la liste des téléphones");
        AppendMenu(search,MF_STRING,14,"Recherche par numéro de téléphone");
        AppendMenu(search,MF_STRING,15,"Recherche par nom");
        AppendMenu(search,MF_STRING,16,"Recherche par indicatif téléphone");
        AppendMenu(search,MF_STRING,17,"Recherche par ville");
        AppendMenu(search,MF_STRING,18,"Tri 1");
/***************************************************************/
    AppendMenu(hmenu,MF_POPUP,(UINT_PTR)record,"Enregistrement et récupération");
        AppendMenu(record,MF_STRING,19,"Enregistrement");
        AppendMenu(record,MF_STRING,20,"Récupération");
    AppendMenu(hmenu,MF_POPUP,(UINT_PTR)plus,"Plus++");
        AppendMenu(plus,MF_STRING,21,"Enoncé du projet");
        AppendMenu(plus,MF_STRING,22,"Ouvrir le fichier texte du répertoire");

/***************************************************************/
    AppendMenu(hmenu,MF_STRING,23,"Quitter");
    SetMenu(hwnd,hmenu);
}

