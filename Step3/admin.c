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
   case '3': printf("Entrez un numero de référence : ");
   	     
  	     scanf("%d", &Numero);
  	     int retour = RechercheVoitureNMBB("VoituresNMBB", Numero, &UnRecord);
  	     if (retour != 1)
  	     	printf("Aucun résultat !\n");
          
             break ;
   case '5': ListingFacturesNMBB("FactureNMBB") ;
	     break ;
   case '6': AProposNMBB("V 1","Massart","Belluz") ;
             break ;
   
	
   case '7': exit(0) ; 
  }
 }
}
