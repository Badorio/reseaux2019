#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "data.h"

void AProposServeurNMBB(char *Version,char *Nom1,char* Nom2);
int RechercheVoitureNMBB(char* NomFichier, int Reference ,struct VoitureNMBB *UnRecord) ;
void AProposNMBB(char *Version,char *Nom1,char* Nom2);
void DelNewLine(char *Chaine);
char ReadChar();
void MonPrintf(char* tempo, int espace,int taille );
void AfficheEnteteVoitureNMBB();
void AfficheVoitureNMBB(struct VoitureNMBB   *UnRecord);
void SaiSieVoitureNMBB(int Reference, struct VoitureNMBB *UnRecord );
int NombreVoituresNMBB(char *NomFichier);
void CreationAjoutVoitureNMBB(char *NomFichier,struct VoitureNMBB *UnRecord );
void AfficheFacture(struct FactureNMBB *UneFacture);
void ListingVoituresNMBB(char *NomFichier);
void ListingFacturesNMBB(char *NomFichier);