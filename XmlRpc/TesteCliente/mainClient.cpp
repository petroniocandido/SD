
#include "XmlRpc.h" 
#include <iostream> 

using namespace std;
using namespace XmlRpc; 

int main(int argc, char* argv[]) 
{ 
    int port = 8000; 
    
    /*
    char *server;
    
    cout << "Indique o servidor: " << endl;
    
    gets(server);
    
    cout << "Conectando ao servidor: " << server << endl;
   */
   
    XmlRpcClient c("192.168.0.159", port); 

    XmlRpcValue noArgs, result; 

    if (c.execute("test", noArgs, result)) 
        std::cout << "\nResult:\n " << result << "\n\n"; 
    else 
        std::cout << "Error calling 'listMethods'\n\n"; 
        
    XmlRpcValue valores;
    
    valores[0] = 2;
    valores[1] = 3;
    
    c.execute("somar", valores, result);
    
    cout << "Resultado: " << result << endl;
        
    char* str;    
    cin >> str;    

    return 0; 
} 
