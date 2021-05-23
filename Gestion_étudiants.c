///================les include================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOMBRE_MAXIMUN_D_ETUDIANT 100

///===============les declaration============= 
int nombre_d_etudiant_sauvegarder, choix;

struct Etudiant{
    int numero_d_inscription;
    char nom[30], prenom[30], filiere[30];
    float moyenne;
};

struct Etudiant list_des_etudiant[NOMBRE_MAXIMUN_D_ETUDIANT];

struct trier{
    int z;
    char znom[30], zprenom[30], zfiliere[30];
    float zmoy;
};

struct trier trier[NOMBRE_MAXIMUN_D_ETUDIANT];

void sauvegarder_la_liste_des_etudiant() {
    FILE * file = fopen("./data/sauvegarde", "wb");
    fwrite(list_des_etudiant, sizeof(struct Etudiant), NOMBRE_MAXIMUN_D_ETUDIANT, file);
    fclose(file);
}

void charger_la_liste_des_etudiant() {
    FILE * file = fopen("./data/sauvegarde", "rb");
    fread(list_des_etudiant, sizeof(struct Etudiant), NOMBRE_MAXIMUN_D_ETUDIANT, file);
    fclose(file);
}

void recuperer_le_nombre_d_etudiant_sauvegarder() {
    FILE * file = fopen("data/configuration", "r");
    fscanf(file, "%d", &nombre_d_etudiant_sauvegarder);
    fclose(file);
}

int sauvegarder_le_nombre_d_etudiant_sauvegarder() {
    FILE * file = fopen("./data/configuration", "w");
    fprintf(file, "%d", nombre_d_etudiant_sauvegarder);
    fclose(file);
}

void charger_savegarde() {
    FILE * file = fopen("sauvegarde.data", "a+");
    signed char data[255];
    fgets(data, 255, file);
    printf("%s data");
    fclose(file);
}

///========procedure de saisie==============
void ajouter_un_etudiant() {
    printf("Nemuro d'inscreption : ");
    scanf("%d", &list_des_etudiant[nombre_d_etudiant_sauvegarder].numero_d_inscription);
    printf("Nom : ");
    scanf("%s", &list_des_etudiant[nombre_d_etudiant_sauvegarder].nom);
    printf("Prenom : ");
    scanf("%s", &list_des_etudiant[nombre_d_etudiant_sauvegarder].prenom);
    printf("Moyenne : ");
    scanf("%f", &list_des_etudiant[nombre_d_etudiant_sauvegarder].moyenne);
    printf("Filiere : ");
    scanf("%s", &list_des_etudiant[nombre_d_etudiant_sauvegarder].filiere);
    nombre_d_etudiant_sauvegarder++;
}
                                   
void ajouter_plusieur_etudiants() {
    int nombre_d_etudiant_a_ajouter;
    printf("Entrer le nombre des etudiants que vous voullez ajouter: ");
    scanf("%d", &nombre_d_etudiant_a_ajouter);

    for(int i=0; i < nombre_d_etudiant_a_ajouter; i++) {
        printf("\nSaisir les information de l'etudiant numero %d :  \n", i + 1);
        printf("Nemuro d'inscreption : ");
        scanf("%d",&list_des_etudiant[nombre_d_etudiant_sauvegarder].numero_d_inscription);
        printf("Nom : ");
        scanf("%s",&list_des_etudiant[nombre_d_etudiant_sauvegarder].nom);
        printf("Prenom : ");
        scanf("%s",&list_des_etudiant[nombre_d_etudiant_sauvegarder].prenom);
        printf("Moyenne : ");
        scanf("%f",&list_des_etudiant[nombre_d_etudiant_sauvegarder].moyenne);
        printf("Filiere : ");
        scanf("%s",&list_des_etudiant[i].filiere);
        nombre_d_etudiant_sauvegarder++;
    }
}


void afficher_list_des_etudiant(){
    printf("-------------------------------------------------------------------------------\n");
    for(int i=0; i < nombre_d_etudiant_sauvegarder; i++) {
        printf("Numero dinscription: %d\n", list_des_etudiant[i].numero_d_inscription);
        printf("Prenom: %s\n", list_des_etudiant[i].prenom);
        printf("Nom: %s\n", list_des_etudiant[i].nom);
        printf("Moyenne: %.2f\n", list_des_etudiant[i].moyenne);
        printf("Filiere: %s\n", list_des_etudiant[i].filiere);
        printf("-------------------------------------------------------------------------------\n");
    }
}

void recherche_etudiant_par_numero_d_inscription(){
    int numero_a_recherche;
    printf("Entrez le numero d'inscrption: ");
    scanf("%d", &numero_a_recherche);

    for(int i=0; i < nombre_d_etudiant_sauvegarder; i++){
        if(list_des_etudiant[i].numero_d_inscription == numero_a_recherche){
            printf("----------------------------------\n");
            printf("Numero d'inscription : %d\n", numero_a_recherche);
            printf("Nom : %s\n",list_des_etudiant[i].nom);
            printf("Prenom : %s\n",list_des_etudiant[i].prenom);
            printf("Moyenne : %0.2f\n\n",list_des_etudiant[i].moyenne);
            printf("Filiaire : %0.2f\n\n",list_des_etudiant[i].filiere);
        }
    }
}

void rechercher_un_etudiant_par_nom() {
    printf("\nRechercher un etudiant par sa nom :\n");
    printf("--------------------------\n");
    char nom[30];
    printf("Entrer le nom d'etudiant : ");
    scanf("%s",&nom);

    for(int i = 0; i < nombre_d_etudiant_sauvegarder; i++) {
        if(strcmp(list_des_etudiant[i].nom,nom) == 0) {
            printf("--------------------");
            printf("Informations sur l'etudient (%s) :\n", nom);
            printf("----------------------------------\n");
            printf("Numero d'inscription : %d\n",list_des_etudiant[i].numero_d_inscription);
            printf("Nom : %s\n",list_des_etudiant[i].nom);
            printf("Prenom : %s\n",list_des_etudiant[i].prenom);
            printf("Moyenne : %0.2f\n",list_des_etudiant[i].moyenne);
            printf("Filiere : %s\n",list_des_etudiant[i].filiere);
        }
    }
}

void rechercher_un_etudiant_par_prenom(){

    printf("\nRechercher un etudiant par sa prenom : \n");
    printf("---------------------------");
    char prenom[15];
    printf("Saisir un prenom : ");
    scanf("%s", &prenom);

    for(int i = 0; i < nombre_d_etudiant_sauvegarder; i++){

        if(strcmp(list_des_etudiant[i].prenom,prenom)==0){

            printf("\nInformations sur l'etudient (%s) :\n",prenom);
            printf("----------------------------------\n");
            printf("Numero d'inscription : %d\n",list_des_etudiant[i].numero_d_inscription);
            printf("Nom : %s\n",list_des_etudiant[i].nom);
            printf("Prenom : %s\n",list_des_etudiant[i].prenom);
            printf("Moyenne : %0.2f\n",list_des_etudiant[i].moyenne);
            printf("Filiere : %s\n",list_des_etudiant[i].filiere);
        }
    }
}

void afficher_list_des_etudiant_admis() {

    printf("\n\nLes etudiant admest sont : \n\n");

    for(int i = 0; i < nombre_d_etudiant_sauvegarder; i++){

        if(list_des_etudiant[i].moyenne > 10){

            printf("Numero d'inscription : %d\n",list_des_etudiant[i].numero_d_inscription);
            printf("Nom : %s\n",list_des_etudiant[i].nom);
            printf("Prenom : %s\n",list_des_etudiant[i].prenom);
            printf("Moyenne : %0.2f\n",list_des_etudiant[i].moyenne);
            printf("Filiere : %s\n",list_des_etudiant[i].filiere);
        }
    }
}

void afficher_les_etudiant_d_une_filiere(){

    char filiere[15];
    printf("Saisir une filiere : ");
    scanf("%s", &filiere);
    printf("Les etudiants de la filiere %s sont : \n\n", filiere);

    for(int i = 0; i < nombre_d_etudiant_sauvegarder; i++){
        if(strcmp(list_des_etudiant[i].filiere, filiere) == 0){
            printf("Numero d'inscription : %d\n",list_des_etudiant[i].numero_d_inscription);
            printf("Nom : %s\n",list_des_etudiant[i].nom);
            printf("Prenom : %s\n",list_des_etudiant[i].prenom);
            printf("Moyenne : %0.2f\n",list_des_etudiant[i].moyenne);
            printf("Filiere : %s\n",list_des_etudiant[i].filiere);
        }
    }
}



void modifier_un_etudiant(){
    int num,k;
    printf("Saisir la numero d insctiption de l etudient que vous voulai modifier : ");
    scanf("%d", &num);

    for(int i = 0; i < nombre_d_etudiant_sauvegarder; i++){
        if(list_des_etudiant[i].numero_d_inscription == num){
            k=i;
        }
    }
    printf("Nemuro d'inscreption : ");
    scanf("%d",&list_des_etudiant[k].numero_d_inscription);
    printf("Nom : ");
    scanf("%s",&list_des_etudiant[k].nom);
    printf("Prenom : ");
    scanf("%s",&list_des_etudiant[k].prenom);
    printf("Moyenne : ");
    scanf("%f",&list_des_etudiant[k].moyenne);
    printf("Filiere : ");
    scanf("%s",&list_des_etudiant[k].filiere);
 }

void supprimer_un_etudiant(){

    int j,num,k;
    printf("Saisir le numero d insctiption de l etudient que vous voulai supprimier : ");
    scanf("%d",&num);

    for(int i = 0; i < nombre_d_etudiant_sauvegarder; i++){
        if(list_des_etudiant[i].numero_d_inscription == num) {
            k=i;
            nombre_d_etudiant_sauvegarder--;
            for( j=k ;j <= nombre_d_etudiant_sauvegarder; j++){
                list_des_etudiant[j]=list_des_etudiant[j+1];
            }
        }
    }
}

// void trierr(){
//      int h,t;
//      do{
//             h=0;
//             for(i=1;i<=n-1;i++){
//                      if(list_des_etudiant[i].num>list_des_etudiant[i+1].num){
//                      trier[i].z=list_des_etudiant[i].num;
//                      strcpy(trier[i].znom,list_des_etudiant[i].nom);
//                      strcpy( trier[i].zprenom,list_des_etudiant[i].prenom);
//                       trier[i].zmoy=list_des_etudiant[i].moy;
//                      strcpy( trier[i].zfiliere,list_des_etudiant[i].filiere);
//                      list_des_etudiant[i].num=list_des_etudiant[i+1].num;
//                      strcpy( list_des_etudiant[i].nom,list_des_etudiant[i+1].nom);
//                      strcpy( list_des_etudiant[i].prenom,list_des_etudiant[i+1].prenom);
//                       list_des_etudiant[i].moy=list_des_etudiant[i+1].moy;
//                      strcpy( list_des_etudiant[i].filiere,list_des_etudiant[i+1].filiere);
//                       list_des_etudiant[i+1].num=trier[i].z;
//                     strcpy(  list_des_etudiant[i+1].nom, trier[i].znom);
//                      strcpy( list_des_etudiant[i+1].prenom,trier[i].zprenom);
//                       list_des_etudiant[i+1].moy=trier[i].zmoy;
//                      strcpy( list_des_etudiant[i+1].filiere,trier[i].zfiliere);
//                      h++;}
//                      }
//         }while(h!=0);
//      printf("Les etudiant trier par numero : \n\n");
//      for(i=1;i<=n;i++){
//                        printf(" %d     %d     %s      %s      %.2f      %s   \n\n",i,list_des_etudiant[i].num,list_des_etudiant[i].nom,list_des_etudiant[i].prenom,list_des_etudiant[i].moy,list_des_etudiant[i].filiere);
//                        }
//      }

void quitter(){
    sauvegarder_la_liste_des_etudiant();
    sauvegarder_le_nombre_d_etudiant_sauvegarder();
}

int main(int argc, char *argv[])
{
    system("color 1A");
    recuperer_le_nombre_d_etudiant_sauvegarder();
    charger_la_liste_des_etudiant();
    do{
        printf("\n\t\t*******\t\tGestion des etudiants\t\t*******\n\n");
        printf("\t\t=========================================================\n\n");
        printf("\t\t<1.  Saisir un etudaint------------------------------ \n");
        printf("\t\t<2.  Saisir plusiurs etudiants----------------------- \n");
        printf("\t\t<3.  Afficher la list des etudiants------------------ \n");
        printf("\t\t<4.  Rechercher un etudiant par numero--------------- \n");
        printf("\t\t<5.  Rechercher un etudiant par nom------------------ \n");
        printf("\t\t<6.  Rechercher un etudiants par prenom-------------- \n");
        printf("\t\t<7.  Afficher les etudiants admet-------------------- \n");
        printf("\t\t<8.  Afficher les etudiants d'une filiairexxw-------- \n");
        printf("\t\t<9.  Modifier un etudiant---------------------------- \n");
        printf("\t\t<10. Supprimier un etudiant-------------------------- \n");
        printf("\t\t<11. Trier les etudiants----------------------------- \n");
        printf("\t\t<12.  Quitter---------------------------------------- \n");
        printf("\t\t=========================================================\n\n");
        printf("Entre votre choix : ");
        scanf("%d", &choix);
        switch(choix) {
            case 1: system("cls");ajouter_un_etudiant();break;
            case 2: system("cls");ajouter_plusieur_etudiants();break;
            case 3: system("cls");afficher_list_des_etudiant();break;
            case 4: system("cls");recherche_etudiant_par_numero_d_inscription();break;
            case 5: system("cls");rechercher_un_etudiant_par_nom();break;
            case 6: system("cls");rechercher_un_etudiant_par_prenom();break;
            case 7: system("cls");afficher_list_des_etudiant_admis();break;
            case 8: system("cls");afficher_les_etudiant_d_une_filiere();break;
            case 9: system("cls");modifier_un_etudiant();break;
            case 10:system("cls");supprimer_un_etudiant();break;
            // case 11:system("cls");trierr();break;
            case 12:system("cls");quitter();break;
            default : system("cls");printf("votre choix n'est pas valide !!!\n");
        }

        } while(choix != 12);
    system("PAUSE>null");
    return 0;
}
