#include "XmlRpc.h" 
#include <stdlib.h> 
#include <iostream> 
#include <sstream>
#include <string>
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
                
        string login = params[0];
        
        chat.Registrar(login);
       
        cout << "Registrando: " << login << endl;
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
        vector<char*> list = chat.Listar();
        for(int i = 0; i < list.size(); i++)
               result[i] = list[i];
         
        cout << "Listando: " << list.size() <<  endl;
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
        
        string usr = params[0];
        string dest = params[1];
        string msg = params[2];
        
        chat.Enviar((char*)usr.c_str(),(char*)dest.c_str(),(char*)msg.c_str());
        
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
        
        string login = params[0];
        
        mensagem msg = chat.Receber((char*)login.c_str());
        
        result[0] = (string)msg.remetente;
        result[1] = (string)msg.corpo;
        
        
        cout << "Receber: " <<  endl;
    } 

} receber(&s); 


int main(int argc, char* argv[]) 
{
    cout << "=========================================================" << endl;
    cout << "===               CHAT SERVER XMLRPC                  ===" << endl;
    cout << "===          Prof. Me. Petr�nio C�ndido               ===" << endl;
    cout << "===      Sistemas Distribu�dos, FACIT 2012            ===" << endl;
    cout << "=========================================================" << endl;
    
    int port = 8000; 

    XmlRpc::setVerbosity(5); 

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
