///================les include================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 50

///===============les declaration============= 
 int i,n,nb,j,choix,netudiant;

  struct etudiants{
      int num;
      char nom[30],prenom[30],filiere[30];
      float moy;
    };

 struct etudiants les_etudiants[max];

  struct trier{
        int z;
        char znom[30],zprenom[30],zfiliere[30];
        float zmoy;
    };

struct trier trier[max];

///========procedure de saisie==============
 void saisie_une_etudiant(){

printf("\n\n");
printf("Saisir les information de votre etudiant :  \n\n");
printf("Nemuro d'inscreption : ");
scanf("%d",&les_etudiants[n+1].num);
printf("Nom : ");
scanf("%s",&les_etudiants[n+1].nom);
printf("Prenom : ");
scanf("%s",&les_etudiants[n+1].prenom);
printf("Moyenne : ");
scanf("%f",&les_etudiants[n+1].moy);
printf("Filiere : ");
scanf("%s",&les_etudiants[n+1].filiere);
n=n+1;
printf("\n\n");}
                                   
void saisir_plusieur_etudiants(){
   printf("Entrer le nombre des etudiants que vous voullias saisie : ");
   scanf("%d",&nb);
   printf("\n\n");

 for(i=1;i<=nb;i++){

      printf("Saisir les information de l'etudiant numero %d :  \n\n",n+1);
      printf("Nemuro d'inscreption : ");
      scanf("%d",&les_etudiants[n+1].num);
      printf("Nom : ");
      scanf("%s",&les_etudiants[n+1].nom);
      printf("Prenom : ");
      scanf("%s",&les_etudiants[n+1].prenom);
      printf("Moyenne : ");
      scanf("%f",&les_etudiants[n+1].moy);
      printf("Filiere : ");
      scanf("%s",&les_etudiants[n+1].filiere);
         n=n+1;
  }}


void afficher_les_etudiants(){

    for(i=1;i<=n;i++){
        printf("L etudient Num :%d Son Nom : %s & Prenom : %s & Moy : %.2f & Filiere : %s \n\n",les_etudiants[i].num,les_etudiants[i].nom,les_etudiants[i].prenom,les_etudiants[i].moy,les_etudiants[i].filiere);
    }
}

void rechercher_une_etudiant_par_num(){
      int num;
      printf(" Saisir un numero : ");
      scanf("%d",&num);

       for(i=1;i<=n;i++){

           if(les_etudiants[i].num==num){
                  printf("\nRechercher un etudiant par sa numero : \n");
                  printf("Qullque informations sur les etudiants que vous avez recherche : \n");
                  printf("----------------------------------\n");
                  printf("Numero d'inscription : %d\n",num);
                  printf("Nom : %s\n",les_etudiants[i].nom);
                  printf("Prenom : %s\n",les_etudiants[i].prenom);
                  printf("Moyenne : %0.2f\n\n",les_etudiants[i].moy);
             }
         }
}

void rechercher_un_etudiant_par_nom(){

      printf("\nRechercher un etudiant par sa nom :\n");
      printf("--------------------------\n");
      char nom[15];
      printf("Entrer le nom d'etudiant : ");
      scanf("%s",&nom);

       for(i=1;i<=n;i++){
          if(strcmp(les_etudiants[i].nom,nom)==0){

             printf("\nRechercher par le nom : \n");
             printf("--------------------");
             printf("Informations sur l'etudient (%s) :\n",nom);
             printf("----------------------------------\n");
             printf("Numero d'inscription : %d\n",les_etudiants[i].num);
             printf("Nom : %s\n",les_etudiants[i].nom);
             printf("Prenom : %s\n",les_etudiants[i].prenom);
             printf("Moyenne : %0.2f\n",les_etudiants[i].moy);
             printf("Filiere : %s\n",les_etudiants[i].filiere);
          }
  }
}

void rechercher_un_etudiant_par_prn(){

     printf("\nRechercher un etudiant par sa prenom : \n");
     printf("---------------------------");
     char prenom[15];
     printf("Saisir un prenom : ");
     scanf("%s",&prenom);

     for(i=1;i<=n;i++){

         if(strcmp(les_etudiants[i].prenom,prenom)==0){

                printf("\nInformations sur l'etudient (%s) :\n",prenom);
                printf("----------------------------------\n");
                printf("Numero d'inscription : %d\n",les_etudiants[i].num);
                printf("Nom : %s\n",les_etudiants[i].nom);
                printf("Prenom : %s\n",les_etudiants[i].prenom);
                printf("Moyenne : %0.2f\n",les_etudiants[i].moy);
                printf("Filiere : %s\n",les_etudiants[i].filiere);
           }
       }
}
void afficher_les_etudiants_admet(){

    int j,k=1;
    printf("\n\nLes etudiant admest sont : \n\n");

     for(i=1;i<=n;i++){

           if(les_etudiants[i].moy>10){

               printf("Numero d'inscription : %d\n",les_etudiants[i].num);
               printf("Nom : %s\n",les_etudiants[i].nom);
               printf("Prenom : %s\n",les_etudiants[i].prenom);
               printf("Moyenne : %0.2f\n",les_etudiants[i].moy);
               printf("Filiere : %s\n",les_etudiants[i].filiere);
            }
       }
}

void afficher_les_etudiant_d_une_filiere(){

     char filiere[15];
     printf("Saisir une filiere : ");
     scanf("%s",&filiere);
     printf("Les etudiants de la filiere %s sont : \n\n",filiere);

     for(i=1;i<=n;i++){
           if(strcmp(les_etudiants[i].filiere,filiere)==0){

             printf("Numero d'inscription : %d\n",les_etudiants[i].num);
             printf("Nom : %s\n",les_etudiants[i].nom);
             printf("Prenom : %s\n",les_etudiants[i].prenom);
             printf("Moyenne : %0.2f\n",les_etudiants[i].moy);
             printf("Filiere : %s\n",les_etudiants[i].filiere);
}}}



void modifier(){
     int num,k;
     printf("Saisir la numero d insctiption de l etudient que vous voulai modifier : ");
     scanf("%d",&num);

     for(i=1;i<=n;i++){
           if(les_etudiants[i].num==num){
                   k=i;
      }}
    printf("Nemuro d'inscreption : ");
    scanf("%d",&les_etudiants[k].num);
    printf("Nom : ");
    scanf("%s",&les_etudiants[k].nom);
    printf("Prenom : ");
    scanf("%s",&les_etudiants[k].prenom);
    printf("Moyenne : ");
    scanf("%f",&les_etudiants[k].moy);
    printf("Filiere : ");
    scanf("%s",&les_etudiants[k].filiere);
 }

void supprimer(){

     int j,num,k;
     printf("Saisir le numero d insctiption de l etudient que vous voulai supprimier : ");
     scanf("%d",&num);

     for(i=1;i<=n;i++){
         if(les_etudiants[i].num==num){
                k=i;
                n=n-1;
                for(j=k;j<=n;j++){
                            les_etudiants[j]=les_etudiants[j+1];
                 }
     }}}

void trierr(){
     int h,t;
     do{
            h=0;
            for(i=1;i<=n-1;i++){
                     if(les_etudiants[i].num>les_etudiants[i+1].num){
                     trier[i].z=les_etudiants[i].num;
                     strcpy(trier[i].znom,les_etudiants[i].nom);
                     strcpy( trier[i].zprenom,les_etudiants[i].prenom);
                      trier[i].zmoy=les_etudiants[i].moy;
                     strcpy( trier[i].zfiliere,les_etudiants[i].filiere);
                     les_etudiants[i].num=les_etudiants[i+1].num;
                     strcpy( les_etudiants[i].nom,les_etudiants[i+1].nom);
                     strcpy( les_etudiants[i].prenom,les_etudiants[i+1].prenom);
                      les_etudiants[i].moy=les_etudiants[i+1].moy;
                     strcpy( les_etudiants[i].filiere,les_etudiants[i+1].filiere);
                      les_etudiants[i+1].num=trier[i].z;
                    strcpy(  les_etudiants[i+1].nom, trier[i].znom);
                     strcpy( les_etudiants[i+1].prenom,trier[i].zprenom);
                      les_etudiants[i+1].moy=trier[i].zmoy;
                     strcpy( les_etudiants[i+1].filiere,trier[i].zfiliere);
                     h++;}
                     }
        }while(h!=0);
     printf("Les etudiant trier par numero : \n\n");
     for(i=1;i<=n;i++){
                       printf(" %d     %d     %s      %s      %.2f      %s   \n\n",i,les_etudiants[i].num,les_etudiants[i].nom,les_etudiants[i].prenom,les_etudiants[i].moy,les_etudiants[i].filiere);
                       }
     }
void quitter(){
     system("cls");
 printf("\n\n        \t------------FIN-----------\n\n\n");
 printf("\n\n        \t------------MERCI-----------\n\n\n");
 }

int main(int argc, char *argv[])
{
  system("color 1A");
do{
           printf("\n        *******      Gestion des etudiants    ****** \n\n");
           printf("          ============================================= \n\n");
                     printf("  Totale des eleves : %d\n\n",n);
           printf("      <1.  Saisir un etudaint------------------------------ \n");
           printf("      <2.  Saisir plusiurs etudiants----------------------- \n");
           printf("      <3.  Afficher la list des etudiants------------------ \n");
           printf("      <4.  Rechercher un etudiant par numero--------------- \n");
           printf("      <5.  Rechercher un etudiant par nom------------------ \n");
           printf("      <6.  Rechercher un etudiants par prenom-------------- \n");
           printf("      <7.  Afficher les etudiants admet-------------------- \n");
           printf("      <8.  Afficher les etudiants d'une filiairexxw-------- \n");
           printf("      <9.  Modifier un etudiant---------------------------- \n");
           printf("      <10. Supprimier un etudiant-------------------------- \n");
           printf("      <11. Trier les etudiants----------------------------- \n");
           printf("      <12.  Quitter---------------------------------------- \n");
           printf("          ============================================== \n\n");
           printf("Entre votre choix : ");
           scanf("%d",&choix);
           printf("\n\n");
           switch(choix){
case 1: system("cls");saisie_une_etudiant();break;
case 2: system("cls");saisir_plusieur_etudiants();break;
case 3: system("cls");afficher_les_etudiants();break;
case 4: system("cls");rechercher_une_etudiant_par_num();break;
case 5: system("cls");rechercher_un_etudiant_par_nom();break;
case 6: system("cls");rechercher_un_etudiant_par_prn();break;
case 7: system("cls");afficher_les_etudiants_admet();break;
case 8: system("cls");afficher_les_etudiant_d_une_filiere();break;
case 9: system("cls");modifier();break;
case 10:system("cls");supprimer();break;
case 11:system("cls");trierr();break;
case 12:system("cls");quitter();break;
default : system("cls");printf("votre choix n'est pas valide !!!\n");
        }

        }while(choix!=12);


  system("PAUSE>null");
  return 0;
  }
