#include "XmlRpc.h" 
#include <stdlib.h> 
#include <iostream> 
#include "chat.h"


using namespace std; 
using namespace XmlRpc; 

XmlRpcServer s; 
ChatServer chat;



/**************************************************************
 *                   REGISTRAR
 **************************************************************/

class RegistrarMethod : public XmlRpcServerMethod 
{ 
public: 
    RegistrarMethod(XmlRpcServer* s1) : XmlRpcServerMethod("registrar", s1) {} 

    void execute(XmlRpcValue& params, XmlRpcValue& result) 
    { 
        result = "OK!"; 
        
        chat.Registrar((string)params);
        
        cout << "Registrando: " << params << endl;
    } 

} registrar(&s); 


/**************************************************************
 *                   LISTAR
 **************************************************************/

class ListarMethod : public XmlRpcServerMethod 
{ 
public: 
    ListarMethod(XmlRpcServer* s1) : XmlRpcServerMethod("listar", s1) {} 

    void execute(XmlRpcValue& params, XmlRpcValue& result) 
    { 
        result = "OK!"; 
        
        cout << "Listando: " <<  endl;
    } 

} listar(&s); 

/**************************************************************
 *                   ENVIAR
 **************************************************************/

class EnviarMethod : public XmlRpcServerMethod 
{ 
public: 
    EnviarMethod(XmlRpcServer* s1) : XmlRpcServerMethod("enviar", s1) {} 

    void execute(XmlRpcValue& params, XmlRpcValue& result) 
    { 
                  
        result = "OK!"; 
        
        cout << "Enviando: " << params[0] << " -> " << params[1] <<  endl;
    } 

} enviar(&s);

/**************************************************************
 *                   RECEBER
 **************************************************************/ 

class ReceberMethod : public XmlRpcServerMethod 
{ 
public: 
    ReceberMethod(XmlRpcServer* s1) : XmlRpcServerMethod("receber", s1) {} 

    void execute(XmlRpcValue& params, XmlRpcValue& result) 
    { 
        result = "OK!"; 
        
        cout << "Receber: " <<  endl;
    } 

} receber(&s); 


int main(int argc, char* argv[]) 
{
    
    int port = 8000; 

    //XmlRpc::setVerbosity(5); 

    s.bindAndListen(port); 

    s.enableIntrospection(true); 

    s.work(-1.0); 
 
    
    /*ChatServer server;
    
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
*/

    return 0; 



} 
