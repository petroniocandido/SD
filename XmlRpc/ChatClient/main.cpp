#include <iostream> 
#include "chat.h"
using namespace std;


int main(int argc, char* argv[]) 
{ 
    char *login;
        
    int port = 8000; 
   
    XmlRpcClient c("127.0.0.1", port); 

    cout << "Entre com o seu login " << endl;
    
    cin.getline(login, 16);

    Chat chat(&c, login);
    
    chat.Registrar();

    char* str;    
    cin >> str;    

    return 0; 
} 


