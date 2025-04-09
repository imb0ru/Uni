#include <stdlib.h>
#include <iostream.h>
#include "mfset.h"
#include "mfset.cpp"
#include "mfset_servizio_def.cpp"

main()
	{
      insieme A=NUM;
      Mfset S;
      char ripeti='s';

   	cout<<"\n A={ \n";
      for(int i=0;i<NUM;i++)
	     	{
				if(i%10==0)
            	cout<<"\n     ";

            if(i<NUM)
         		cout<<i<<",";
            else
         		cout<<i;
         }
     	cout<<"\n\n   }";

  	   stampa_mfset(S);
      while(ripeti=='s')
      	{
            ripeti='?';
   	   	fondi_componenti(S);
	   	   stampa_mfset(S);
     			cout<<"\n Se vuoi operare un'altra fusione, digita 's': ";
				cin>>ripeti;
         }

      wait("\n Programma in stand by\n per continuare digita [Y]+[invio]: ");

		return 0;
   }
