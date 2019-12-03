/*---------------------------------------------------------------
   Vanstapel Herman
   ex02\cli.c

 Le client dit bonjour en utilisant un structure  et
 le serveur fait de même
------------------------------------------------------------------*/
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

int main(int argc, char *argv[])
{
 int rc ;
 int Desc ;
 int tm ; 
 char Choix;
 char Client[60], Tampon[80];
 int Numero, Nombre;
 struct VoitureNMBB UnRecord;
 
 u_long  IpSocket , IpServer;
 u_short PortSocket, PortServer ; 
 
 struct sockaddr_in sthis ; /* this ce programme */
 struct sockaddr_in sos ; /* s = serveur */
 struct sockaddr_in sor ; /* r = remote */
 struct Requete UneRequete ;

 memset(&sthis,0,sizeof(struct sockaddr_in)) ;
 memset(&sos,0,sizeof(struct sockaddr_in)) ; 
 memset(&sor,0,sizeof(struct sockaddr_in)) ; 
 
 if (argc!=5)
  
{
    printf("cli client portc serveur ports\n") ;
    exit(1) ;
 }
 
 /* Récupération IP & port   */
 IpSocket= inet_addr(argv[1]);
 PortSocket = atoi(argv[2]);
 
 IpServer = inet_addr(argv[3]) ;
 PortServer = atoi(argv[4]);
 
 // Desc = CreateSockets(&psoo,&psos,,atoi(argv[2]),argv[3],atoi(argv[4])) ;
 Desc=creer_socket(SOCK_DGRAM,&IpSocket,PortSocket,&sthis);
 
 if ( Desc == -1 )
    die("CreateSockets:") ; 
 else
    fprintf(stderr,"CreateSockets %d\n",Desc) ;
 
  sos.sin_family = AF_INET ;
  sos.sin_addr.s_addr= IpServer ;
  sos.sin_port = htons(PortServer) ;
  
  int ref;
  while(1)
  {
     printf("1) Demander une référence\n");
     printf("2) Acheter une voiture\n");
     printf("3) Quitter\n");
     Choix = ReadChar();
   switch(Choix)
   {
      case '1':
         printf("Entrez la reference du vehicule : ");
         scanf("%d", &ref);
         
         UneRequete.Reference = ref;
         UneRequete.Type = Question ; 
         strncpy(UneRequete.Message , "Avec une structure: Bonjour" , sizeof(UneRequete.Message)) ;
         
         rc = SendDatagram(Desc,&UneRequete,sizeof(struct Requete) ,&sos ) ;

         if ( rc == -1 )
            die("SendDatagram") ;
         else
            fprintf(stderr,"Envoi de %d bytes\n",rc ) ;
         
         memset(&UneRequete,0,sizeof(struct Requete)) ;
         tm = sizeof(struct Requete) ;
         
         rc = ReceiveDatagram( Desc, &UneRequete,tm, &sor ) ;
         if ( rc == -1 )
            die("ReceiveDatagram") ;
         else
            fprintf(stderr,"bytes recus:%d:%s\n",rc,UneRequete.Message ) ;
            
            if (UneRequete.Type == OK)
            {
               UnRecord.Reference  = UneRequete.Reference;
            strcpy(UnRecord.Marque, UneRequete.Marque);
            strcpy(UnRecord.Modele, UneRequete.Modele);
            UnRecord.Nombre = UneRequete.Nombre;
            strcpy(UnRecord.Couleur, UneRequete.Couleur);
               printf("Voici votre résultat : \n");
               AfficheEnteteVoitureNMBB();
               AfficheVoitureNMBB(&UnRecord);
               
            }
            else
            {
               printf("Aucun résultat trouvé !\n");
            }

         
         break;
      case '2':
      		printf("Nom de client : ");
   		fgets (Tampon, sizeof Tampon, stdin);
   		strcpy (Client, Tampon);
   		
   		printf("Entrez la reference de la voiture : ");
	   	fgets (Tampon, sizeof Tampon, stdin);
	        Numero = atoi(Tampon);
 	     
 	        printf("Entrez le nombre de voiture : ");
 	        fgets (Tampon, sizeof Tampon, stdin);
 	        Nombre = atoi(Tampon);
 	        
 	         UneRequete.Reference = Numero;
 	         strcpy(UneRequete.NomClient, Client);
 	         UneRequete.Nombre = Nombre;
		 UneRequete.Type = Achat; 
		 strncpy(UneRequete.Message , "On achète une voiture !" , sizeof(UneRequete.Message)) ;
		 
		 rc = SendDatagram(Desc,&UneRequete,sizeof(struct Requete) ,&sos ) ;

		 if ( rc == -1 )
		    die("SendDatagram") ;
		 else
		    fprintf(stderr,"Envoi de %d bytes\n",rc ) ;
		 
		 memset(&UneRequete,0,sizeof(struct Requete)) ;
		 tm = sizeof(struct Requete) ;
		 
		 rc = ReceiveDatagram( Desc, &UneRequete,tm, &sor ) ;
		 if ( rc == -1 )
		    die("ReceiveDatagram") ;
		 else
		    fprintf(stderr,"bytes recus:%d:%s\n",rc,UneRequete.Message ) ;
		    
		 if (UneRequete.Type == OK)
		 	printf ("Reservation et Facturation OK\n");   
	 	 else
	 	 	printf("Erreur !\n");
 	        
	    
          break;
      case '3':
            close(Desc) ;
            exit(0);
            break;
      default:
         printf("\n\nMAUVAIS CHOIX!!\n");
         break;
      
   }

  }
}
