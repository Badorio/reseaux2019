
enum TypeRequete {
       Consultation = 1 ,
       Achat  = 2 ,
       Livraison = 3,
       OK = 4,
       Fail = 5,
       Reponse = 6,
       Question = 7
     } ;

struct Requete
{
  enum TypeRequete Type ;
  int Numero ; //contient le numéro de la requete
  int NumeroFacture;
  int Date; //utilisé à partir de l'étape 6
  int Reference; //référence produit
  int Nombre;
  int Prix;
  char Marque[80];
  char Modele[80];
  char NomClient[80];
  char Couleur[80];
  char Message[80];
} ; 
