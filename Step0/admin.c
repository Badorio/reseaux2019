/******************************************
  Herman Vanstapel
  2017 Basé sur Fichiers
*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "data.h"
#include "LibSerHV.h"

void AProposHV(char *Version,char *Nom1,char* Nom2)
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

void AfficheEnteteVoitureHV()
{
 char Tampon[80] ;
 sprintf(Tampon,"%s","Ref" ) ; MonPrintf(Tampon,4,strlen(Tampon)) ;
 sprintf(Tampon,"%s","Marque") ; MonPrintf(Tampon,30,strlen(Tampon)) ;
 sprintf(Tampon,"%s","Modele") ; MonPrintf(Tampon,30,strlen(Tampon)) ;
 sprintf(Tampon,"%s","Nombre") ; MonPrintf(Tampon,6,strlen(Tampon)) ;
 printf("\n") ;
}

void AfficheVoitureHV(struct VoitureHV   *UnRecord)
{
 char Tampon[80] ;
 sprintf(Tampon,"%d",UnRecord->Reference ) ; MonPrintf(Tampon,4,strlen(Tampon)) ;
 sprintf(Tampon,"%s",UnRecord->Marque) ; MonPrintf(Tampon,30,strlen(Tampon)) ;
 sprintf(Tampon,"%s",UnRecord->Modele) ; MonPrintf(Tampon,30,strlen(Tampon)) ;
 sprintf(Tampon,"%d",UnRecord->Nombre) ; MonPrintf(Tampon,6,strlen(Tampon)) ;
 printf("\n") ;
}

void SaiSieVoitureHV(int Reference, struct VoitureHV *UnRecord )
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
 AfficheEnteteVoitureHV() ;
 AfficheVoitureHV(UnRecord) ;
 printf("-----------------------\n") ;
 return ;
}

int NombreVoituresHV(char *NomFichier)
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
 return (ftell(sortie)/ sizeof(struct VoitureHV )) ;
}

void CreationAjoutVoitureHV(char *NomFichier,struct VoitureHV *UnRecord )
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
  nbr = fwrite(UnRecord,sizeof(struct VoitureHV ),1,sortie) ;
  fflush(sortie) ;
 fclose(sortie) ;
}



void AfficheFacture(struct FactureHV *UneFacture)
{
 char Tampon[80] ;
 sprintf(Tampon,"%d",UneFacture->NumeroFacturation ) ; MonPrintf(Tampon,4,strlen(Tampon)) ;
 sprintf(Tampon,"%s",UneFacture->NomClient) ; MonPrintf(Tampon,60,strlen(Tampon)) ;
 sprintf(Tampon,"%d",UneFacture->Places ) ; MonPrintf(Tampon,4,strlen(Tampon)) ;
 sprintf(Tampon,"%d",UneFacture->Reference) ; MonPrintf(Tampon,4,strlen(Tampon)) ;
 sprintf(Tampon,"%d",UneFacture->DateFacturation ) ; MonPrintf(Tampon,8,strlen(Tampon)) ;
 
 printf("\n") ;
}

void ListingVoituresHV(char *NomFichier)
{
 struct VoitureHV  UnRecord ;
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

 AfficheEnteteVoitureHV() ;
 nbr = fread(&UnRecord,sizeof(UnRecord),1,sortie) ;
 
 while ( !feof(sortie) )
 {
//  fprintf(stderr,"Record lu %d et Position actuelle dans le fichier %ld\n",nbr,ftell(sortie)) ;
  AfficheVoitureHV( &UnRecord) ;
  nbr = fread(&UnRecord,sizeof(UnRecord),1,sortie) ;
 }
 fclose(sortie) ;
}

void ListingFacturesHV(char *NomFichier)
{
 struct FactureHV UneFacture ;
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

 
 nbr = fread(&UneFacture,sizeof(struct FactureHV),1,sortie) ;
 
 while ( !feof(sortie) )
 {
  fprintf(stderr,"Record lu %d et Position actuelle dans le fichier %ld\n",nbr,ftell(sortie)) ;
  AfficheFacture( &UneFacture) ;
  nbr = fread(&UneFacture,sizeof(struct FactureHV ),1,sortie) ;
 }
 fclose(sortie) ;
}

int main()
{
 char Choix ;
 char Tampon[80] ;
 int res ;
 struct VoitureHV UnRecord ;
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
              struct VoitureHV  UnRecord ;
 	     FILE *sortie ;
             char Redo ;
		
             Redo='y' ;
 	    while ( Redo=='Y' || Redo=='y')
 	    { 
             int Nombre ;
             Nombre= NombreVoituresHV("VoituresHV") ;
  	     SaiSieVoitureHV(Nombre+1, &UnRecord ) ;
  	     CreationAjoutVoitureHV("VoituresHV",&UnRecord) ; 
  	     printf("Encoder une autre (Y/N) ?)") ;
  	     Redo=ReadChar() ;
 	   }
 
	     break ;	
             }
   case '2': ListingVoituresHV("VoituresHV") ;
             break ;
   case '3': 	
             break ;
   case '5': ListingFacturesHV("FactureHV") ;
	     break ;
   case '6': AProposHV("V 1","Herman","Vanstapel") ;
             break ;
   
	
   case '7': exit(0) ; 
  }
 }
}
