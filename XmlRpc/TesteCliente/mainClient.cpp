
#include "XmlRpc.h" 
#include <iostream> 

using namespace std;
using namespace XmlRpc; 

int main(int argc, char* argv[]) 
{ 
    int port = 8000; 
   
    XmlRpcClient c("127.0.0.1", port); 

    XmlRpcValue noArgs, result; 

    if (c.execute("test", noArgs, result)) 
        std::cout << "\nResult:\n " << result << "\n\n"; 
    else 
        std::cout << "Error calling 'listMethods'\n\n"; 
        
    char* str;    
    cin >> str;    

    return 0; 
} 
