#include  <ql/quantlib.hpp>;
#include < boost/math/distributions.hpp >;
#include <stdio.h>;
#include <sqlapi.h>;

using namespace QuantLib;


int main(int argc, char* argv[])
{
    SAConnection con; 
    SACommand cmd(&con,"select top 100 securityID, Date from zzz_risk");
    try
    {
        con.Connect("vita.ieor.columbia.edu@ivy", "ivyuser", "resuyvi", SA_SQLServer_Client);
		cmd.Execute();

		while(cmd.FetchNext())
        {
			printf("Row fetched: securityID = %ld",
                cmd.Field("securityID").asLong());
                
        }





        con.Disconnect();

        printf("We are disconnected!\n");
		std::getchar();
    }
    catch(SAException &x)
    {
        // SAConnection::Rollback()
        // can also throw an exception
        // (if a network error for example),
        // we will be ready
        try
        {
            // on error rollback changes
            con.Rollback();
        }
        catch(SAException &)
        {
        }
        // print error message
        printf("%s\n", (const char*)x.ErrText());
    }
    
	
	std::getchar();
    return 0;
}



//int main ( int argc, const char* argv[] ) {
//	Real spot =100.0;
//	Rate r =0.03;
//	Time tau =0.5;
//	Volatility vol =0.20;
//	Real strike =110.0;
//	Real a= strike , b= strike *10.0;
//	boost :: function < Real ( Real )> ptrF ;
//	ptrF = boost :: bind (& callFunc , spot , strike ,r , vol , tau , _1 );
//	Real absAcc =0.00001;
//	Size maxEval =1000;
//	SimpsonIntegral numInt ( absAcc , maxEval );
//	std :: cout << "Call Value: " << numInt ( ptrF ,a ,b) << std :: endl ;
//	std :: getchar(); 
//	DateTesting2() ;
//	std :: getchar(); 
//	return 0;
//}