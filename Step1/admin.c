/******************************************
  Herman Vanstapel
  2017 Basé sur Fichiers
*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "data.h"
#include "LibSerNMBB.h"

void AProposNMBB(char *Version,char *Nom1,char* Nom2)
{
 printf("Version : %s \n",Version ) ;
 printf("Nom1 : %s \n",Nom1 ) ;
 printf("Nom2 : %s \n",Nom2 ) ;
}

void DelNewLine(char *Chaine)
{
 Chaine[strlen(Chaine)-1] = 0 ;
}

char ReadChar()
{
 char Tampon[80] ;
 fgets(Tampon,sizeof Tampon,stdin ) ;
 return Tampon[0] ;
} 

void MonPrintf(char* tempo, int espace,int taille )
{
 int Count ;
 printf("%s",tempo) ; 
 Count = espace-taille ;
 while ( Count>0 )
 {
       printf(" ");
       Count-- ;
 }
}

void AfficheEnteteVoitureNMBB()
{
 char Tampon[80] ;
 sprintf(Tampon,"%s","Ref" ) ; MonPrintf(Tampon,4,strlen(Tampon)) ;
 sprintf(Tampon,"%s","Marque") ; MonPrintf(Tampon,30,strlen(Tampon)) ;
 sprintf(Tampon,"%s","Modele") ; MonPrintf(Tampon,30,strlen(Tampon)) ;
 sprintf(Tampon,"%s","Nombre") ; MonPrintf(Tampon,6,strlen(Tampon)) ;
 printf("\n") ;
}

void AfficheVoitureNMBB(struct VoitureNMBB   *UnRecord)
{
 char Tampon[80] ;
 sprintf(Tampon,"%d",UnRecord->Reference ) ; MonPrintf(Tampon,4,strlen(Tampon)) ;
 sprintf(Tampon,"%s",UnRecord->Marque) ; MonPrintf(Tampon,30,strlen(Tampon)) ;
 sprintf(Tampon,"%s",UnRecord->Modele) ; MonPrintf(Tampon,30,strlen(Tampon)) ;
 sprintf(Tampon,"%d",UnRecord->Nombre) ; MonPrintf(Tampon,6,strlen(Tampon)) ;
 printf("\n") ;
}

void SaiSieVoitureNMBB(int Reference, struct VoitureNMBB *UnRecord )
{
 char Tampon[80] ;

 printf("Reference :%d \n",Reference) ;
 UnRecord->Reference = Reference ; 
 printf("Saisie Marque :") ;
 fgets(UnRecord->Marque,sizeof UnRecord->Marque,stdin ) ;
printf("Saisie Modele :") ;
 fgets(UnRecord->Modele,sizeof UnRecord->Modele,stdin ) ;
 printf("Saisie Nombre :") ;
 fgets(Tampon,sizeof Tampon,stdin ) ;
 UnRecord -> Nombre = atoi(Tampon) ;
 
 DelNewLine(UnRecord->Marque) ;
 DelNewLine(UnRecord->Modele) ;
 AfficheEnteteVoitureNMBB() ;
 AfficheVoitureNMBB(UnRecord) ;
 printf("-----------------------\n") ;
 return ;
}

int NombreVoituresNMBB(char *NomFichier)
{
 FILE *sortie ;
 sortie = fopen(NomFichier,"r") ; /* Si le fichier existe, on le cree sinon on ajoute */
 if ( sortie == NULL )
    {
     fprintf(stderr,"Pas de fichier\n") ;
     return 0 ;
    }
 else
    fprintf(stderr,"Ouverture reussie \n") ;
 fseek(sortie, 0, SEEK_END ) ;
 return (ftell(sortie)/ sizeof(struct VoitureNMBB )) ;
}

void CreationAjoutVoitureNMBB(char *NomFichier,struct VoitureNMBB *UnRecord )
{
 FILE *sortie ;
 char Redo ;
 int nbr ;

 sortie = fopen(NomFichier,"a") ; /* Si le fichier existe, on le cree sinon on ajoute */
 if ( sortie == NULL )
    {
     fprintf(stderr,"Echec Ouverture\n") ;
     exit(0) ;
    }
 else
    fprintf(stderr,"Ouverture reussie \n") ;

 
  printf("Position actuelle dans le fichier %ld\n",ftell(sortie)) ;
  nbr = fwrite(UnRecord,sizeof(struct VoitureNMBB ),1,sortie) ;
  fflush(sortie) ;
 fclose(sortie) ;
}



void AfficheFacture(struct FactureNMBB *UneFacture)
{
 char Tampon[80] ;
 sprintf(Tampon,"%d",UneFacture->NumeroFacturation ) ; MonPrintf(Tampon,4,strlen(Tampon)) ;
 sprintf(Tampon,"%s",UneFacture->NomClient) ; MonPrintf(Tampon,60,strlen(Tampon)) ;
 sprintf(Tampon,"%d",UneFacture->Places ) ; MonPrintf(Tampon,4,strlen(Tampon)) ;
 sprintf(Tampon,"%d",UneFacture->Reference) ; MonPrintf(Tampon,4,strlen(Tampon)) ;
 sprintf(Tampon,"%d",UneFacture->DateFacturation ) ; MonPrintf(Tampon,8,strlen(Tampon)) ;
 
 printf("\n") ;
}

void ListingVoituresNMBB(char *NomFichier)
{
 struct VoitureNMBB  UnRecord ;
 FILE *sortie ;
 char Tampon[80] ;
 int  Numero ;
 int  nbr ;

 sortie = fopen(NomFichier,"r") ; /* Si le fichier existe, on le cree sinon on ajoute */
 if ( sortie == NULL )
    {
     fprintf(stderr,"Echec Ouverture\n") ;
     exit(0) ;
    }
 else
    fprintf(stderr,"Ouverture reussie \n") ;

 AfficheEnteteVoitureNMBB() ;
 nbr = fread(&UnRecord,sizeof(UnRecord),1,sortie) ;
 
 while ( !feof(sortie) )
 {
//  fprintf(stderr,"Record lu %d et Position actuelle dans le fichier %ld\n",nbr,ftell(sortie)) ;
  AfficheVoitureNMBB( &UnRecord) ;
  nbr = fread(&UnRecord,sizeof(UnRecord),1,sortie) ;
 }
 fclose(sortie) ;
}

void ListingFacturesNMBB(char *NomFichier)
{
 struct FactureNMBB UneFacture ;
 FILE *sortie ;
 char Tampon[80] ;
 int  Numero ;
 int  nbr ;

 sortie = fopen(NomFichier,"r") ; /* Si le fichier existe, on le cree sinon on ajoute */
 if ( sortie == NULL )
    {
     fprintf(stderr,"Echec Ouverture\n") ;
     exit(0) ;
    }
 else
    fprintf(stderr,"Ouverture reussie \n") ;

 
 nbr = fread(&UneFacture,sizeof(struct FactureNMBB),1,sortie) ;
 
 while ( !feof(sortie) )
 {
  fprintf(stderr,"Record lu %d et Position actuelle dans le fichier %ld\n",nbr,ftell(sortie)) ;
  AfficheFacture( &UneFacture) ;
  nbr = fread(&UneFacture,sizeof(struct FactureNMBB ),1,sortie) ;
 }
 fclose(sortie) ;
}

int main()
{
 char Choix ;
 char Tampon[80] ;
 int res ;
 struct VoitureNMBB UnRecord ;
 int Numero ;
 while(1)
 {
  printf("----------------------\n") ;
  printf("1) Ajout              \n") ;
  printf("2) Voitures           \n") ;  
  printf("3) Recherche          \n") ;   
  printf("4) Achat              \n") ;  
  printf("5) Factures           \n") ;
  printf("6) A propos           \n") ;
  printf("7) exit               \n") ; 
  printf("----------------------\n") ; 
  Choix=ReadChar() ;
  switch(Choix)
  {
   case '1': 
             {
              struct VoitureNMBB  UnRecord ;
 	     FILE *sortie ;
             char Redo ;
		
             Redo='y' ;
 	    while ( Redo=='Y' || Redo=='y')
 	    { 
             int Nombre ;
             Nombre= NombreVoituresNMBB("VoituresNMBB") ;
  	     SaiSieVoitureNMBB(Nombre+1, &UnRecord ) ;
  	     CreationAjoutVoitureNMBB("VoituresNMBB",&UnRecord) ; 
  	     printf("Encoder une autre (Y/N) ?)") ;
  	     Redo=ReadChar() ;
 	   }
 
	     break ;	
             }
   case '2': ListingVoituresNMBB("VoituresNMBB") ;
             break ;
   case '3': printf("Entrez un numero de reference : ");
  	     scanf("%d", &Numero);
  	     RechercheVoitureNMBB("VoituresNMBB", Numero, &UnRecord);
             break ;
   case '5': ListingFacturesNMBB("FactureNMBB") ;
	     break ;
   case '6': AProposNMBB("V 1","Massart","Belluz") ;
             break ;
   
	
   case '7': exit(0) ; 
  }
 }
}
