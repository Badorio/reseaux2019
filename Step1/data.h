#ifdef DATAH

#else


#define DATAH

struct VoitureNMBB { 
         int  Reference ;
	 char Marque[40] ;
         char Modele[40]  ;
	 int  Nombre ;
	} ;

struct FactureNMBB
       {
         int NumeroFacturation ;
         char NomClient[40] ;
	 int DateFacturation ;
         int Places ;
	 int Reference ;
	} ;  	
#endif
