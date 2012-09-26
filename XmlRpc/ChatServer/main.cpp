#include "XmlRpc.h" 
#include <stdlib.h> 
#include <iostream> 
#include "chat.h"


using namespace std; 
//using namespace XmlRpc; 

/*XmlRpcServer s; 





class TestMethod : public XmlRpcServerMethod 
{ 
public: 
    TestMethod(XmlRpcServer* s1) : XmlRpcServerMethod("test", s1) {} 

    void execute(XmlRpcValue& params, XmlRpcValue& result) 
    { 
        result = "It Works! Yahooooooooooo!"; 
        
        cout << "Método invocado!" << endl;
    } 

} test(&s); 
*/

int main(int argc, char* argv[]) 
{ 
    
    ChatServer server;
    
    char *usr1 = "teste1";
    char *usr2 = "teste2";
    
    server.Registrar(usr1);
    
    server.Registrar(usr2);
    
    mensagem msg(usr1, (char *)"Teste");
    
    server.Enviar(usr2, mensagem(usr1, (char *)"Teste1"));
    server.Enviar(usr2, mensagem(usr1, (char *)"Teste2"));
    server.Enviar(usr2, mensagem(usr1, (char *)"Teste3"));
    
    mensagem m1 = server.Receber(usr2);    
    
    cout << m1.corpo << endl;

int i;
 cin >> i;

    return 0; 

/*int port = 8000; 

    //XmlRpc::setVerbosity(5); 

    s.bindAndListen(port); 

    s.enableIntrospection(true); 

    s.work(-1.0); 
*/

} 
