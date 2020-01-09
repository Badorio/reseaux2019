#include "LibSerNMBB.h"


void AProposServeurNMBB(char *Version,char *Nom1,char* Nom2)
{
 printf("Version : %s \n",Version ) ;
 printf("Nom1 : %s \n",Nom1 ) ;
 printf("Nom2 : %s \n",Nom2 ) ;
}

int RechercheVoitureNMBB(char* NomFichier, int Reference, struct VoitureNMBB *UnRecord)
{
	FILE *fp;
	int ctrl = 0;
	char Tampon[80];
	
	fp = fopen (NomFichier, "rb");
	
	if (fp == (FILE *) NULL)
	{
		printf("Erreur lors de l'ouverture du fichier\n");
	}
	else
	{
		fread (UnRecord, sizeof(struct VoitureNMBB), 1, fp);
		
		while (feof(fp) == 0 && ctrl == 0)
		{
			if (Reference == UnRecord->Reference)
			{
				ctrl = 1;
			}
			
			if (ctrl == 0)
			{
				fread (UnRecord, sizeof(struct VoitureNMBB), 1, fp);
			}
		}
	}
	
	if (ctrl == 1)
	{
		AfficheEnteteVoitureNMBB() ;
		AfficheVoitureNMBB( UnRecord) ;		
	}
	fclose (fp);
	
	return ctrl;
}



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
 sprintf(Tampon,"%s", "Couleur"); MonPrintf(Tampon, 30, strlen(Tampon));
 printf("\n") ;
}

void AfficheVoitureNMBB(struct VoitureNMBB   *UnRecord)
{
 char Tampon[80] ;
 sprintf(Tampon,"%d",UnRecord->Reference ) ; MonPrintf(Tampon,4,strlen(Tampon)) ;
 sprintf(Tampon,"%s",UnRecord->Marque) ; MonPrintf(Tampon,30,strlen(Tampon)) ;
 sprintf(Tampon,"%s",UnRecord->Modele) ; MonPrintf(Tampon,30,strlen(Tampon)) ;
 sprintf(Tampon,"%d",UnRecord->Nombre) ; MonPrintf(Tampon,6,strlen(Tampon)) ;
 sprintf(Tampon,"%s", UnRecord->Couleur); MonPrintf(Tampon, 30, strlen(Tampon));
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
printf("Saisie Couleur : ");
 fgets(UnRecord->Couleur,sizeof UnRecord->Couleur,stdin ) ;
 UnRecord -> Nombre = atoi(Tampon) ;
 
 DelNewLine(UnRecord->Marque) ;
 DelNewLine(UnRecord->Modele) ;
 DelNewLine(UnRecord->Couleur);
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


int Reservation (char *NomFichier, int Reference, int Nombre)
{
	FILE *fp;
	int nb, i=0, ctrl=0;
	struct VoitureNMBB UnRecord;
	
	ctrl = RechercheVoitureNMBB (NomFichier, Reference, &UnRecord);
	
	if (ctrl == 0)
	{
		printf("La seance n'existe pas !\n");
	}
	else
	{
		if (Nombre > UnRecord.Nombre)
		{
			printf("Nombre de places insuffisants\n");
			ctrl=0;
		}
		else
		{
			fp = fopen (NomFichier, "r+");
			if (fp == (FILE *) NULL)
			{
				printf("Erreur lors de l'ouverture du fichier\n");
			}
			else
			{
				
				 fread(&UnRecord, sizeof(struct VoitureNMBB),1, fp);
				 while(UnRecord.Reference != Reference && feof(fp)==0)
				 {	
				 	fread(&UnRecord, sizeof(struct VoitureNMBB),1, fp); 	
				}
				
				if((feof(fp)==0) || ((feof(fp)!=0) && (UnRecord.Reference == Reference)) )
				{
					UnRecord.Nombre-= Nombre;
					fseek(fp, -(sizeof(struct VoitureNMBB)), SEEK_CUR);
					fwrite(&UnRecord,sizeof(struct VoitureNMBB ),1,fp) ;
					ctrl = 1;
				}
					
			}
			fclose (fp);
		}
	}
	
	return ctrl;
}

int Facturation (char NomFichier[80], char NomClient[60], int Date, int Nombre, int Reference)
{
	FILE *fp;
	struct FactureNMBB UneFacture;
	int ctrl=1;
	
	fp = fopen (NomFichier, "ab");
	
	if (fp == (FILE *)NULL)
	{
		printf("Erreur lors de l'ouverture du fichier\n");
		ctrl = 0;
	}
	else
	{
		UneFacture.NumeroFacturation = ftell (fp) / sizeof(struct FactureNMBB)+1;
		strcpy (UneFacture.NomClient, NomClient);
		UneFacture.DateFacturation = Date;
		UneFacture.Reference = Reference;
		UneFacture.Places = Nombre;
		
		fwrite (&UneFacture, sizeof (struct FactureNMBB), 1, fp);
		
	}
	
	fclose(fp);
	return ctrl;
}





