#ifdef DATAH

#else


#define DATAH

struct VoitureHV { 
         int  Reference ;
	 char Marque[40] ;
         char Modele[40]  ;
	 int  Nombre ;
	} ;

struct FactureHV
       {
         int NumeroFacturation ;
         char NomClient[40] ;
	 int DateFacturation ;
         int Places ;
	 int Reference ;
	} ;  	
#endif
