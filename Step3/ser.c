/*--------------------------------------
  Herman Vanstapel
  
  ex02\ser.c 
  
  Un serveur recevant une structure 
----------------------------------------*/

#include <stdio.h>
#include <string.h>
#include "../udplib/udplib.h"
#include "structure.h"
#include "LibSerNMBB.h"


void die(char *s)
{
    perror(s);
    exit(1);
}

int main(int argc,char *argv[])
{
 int rc ;
 int Desc ;
 struct sockaddr_in sthis ; /* this ce programme */
 struct sockaddr_in sos ; /* s = serveur */
 struct sockaddr_in sor ; /* r = remote */
 
 u_long  IpSocket ;
 u_short PortSocket ;
 
 int tm ;
 struct Requete UneRequete;
 struct VoitureNMBB UnRecord;

 memset(&sthis,0,sizeof(struct sockaddr_in)) ;
 memset(&sos,0,sizeof(struct sockaddr_in)) ; 
 memset(&sor,0,sizeof(struct sockaddr_in)) ; 
 
 printf("Ceci est le serveur\n") ;
 if ( argc!=3)
 {
  printf("ser ser port cli\n") ;
  exit(1) ;
 }
 
 /* Récupération IP & port   */
 IpSocket= inet_addr(argv[1]);
 PortSocket = atoi(argv[2]);
 // Desc = CreateSockets(&psoo,&psos,,atoi(argv[2]),argv[3],atoi(argv[4])) ;
 Desc=creer_socket(SOCK_DGRAM,&IpSocket,PortSocket,&sthis);
 
 if ( Desc == -1 )
    die("CreateSockets:") ;
 else
    fprintf(stderr,"CreateSockets %d\n",Desc) ;
 
 tm = sizeof(struct Requete) ;
 while(1){
 rc = ReceiveDatagram( Desc,&UneRequete ,tm, &sor ) ;
 if ( rc == -1 )
    die("ReceiveDatagram") ;
 else
   fprintf(stderr,"bytes recus:%d:%s\n",rc,UneRequete.Message ) ;
 
 printf("Type recu %d\n", UneRequete.Type) ;
 /* attention l'enum peut être codé en short */
 /* reponse avec psos */
 
 int verif;
 verif = RechercheVoitureNMBB("VoituresNMBB", UneRequete.Reference, &UnRecord) ;
 
 if (verif == 1)
 {
 	UneRequete.Reference = UnRecord.Reference;
 	strcpy(UneRequete.Marque, UnRecord.Marque);
 	strcpy(UneRequete.Modele, UnRecord.Modele);
 	UneRequete.Nombre = UnRecord.Nombre;
 	strcpy(UneRequete.Couleur, UnRecord.Couleur);
 	UneRequete.Type = OK;
 }
 else
 {
 	UneRequete.Type = Fail;
 }
 strcat(UneRequete.Message," Client") ;
 rc = SendDatagram(Desc,&UneRequete,sizeof(struct Requete) ,&sor ) ;
 if ( rc == -1 )
    die("SendDatagram:") ;
 else
   fprintf(stderr,"bytes envoyes:%d\n",rc ) ;
 }
 close(Desc) ;
}
