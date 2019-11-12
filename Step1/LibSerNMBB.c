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
		printf("Reference\tMarque\t\tModele\tNombre\n");
		printf("%d\t\t", UnRecord->Reference);
		printf("%s\t", UnRecord->Marque);
		printf("%s\t", UnRecord->Modele);
		printf("%d\t\n", UnRecord->Nombre);
		
	}
	fclose (fp);
	
	return ctrl;
}






