#include "XmlRpc.h" 
#include <stdlib.h> 
#include <iostream> 

using namespace std; 
using namespace XmlRpc; 

XmlRpcServer s; 

class TestMethod : public XmlRpcServerMethod 
{ 
public: 
    TestMethod(XmlRpcServer* s1) : XmlRpcServerMethod("test", s1) {} 

    void execute(XmlRpcValue& params, XmlRpcValue& result) 
    { 
        result = "Hello World RPC"; 
        
        cout << "Método invocado!" << endl;
    } 

} test(&s); 


int main(int argc, char* argv[]) 
{ 
    int port = 8000; 

    s.bindAndListen(port); 

    cout << "Escutando por clientes" << endl;

    s.enableIntrospection(true); 

    s.work(-1.0); 

    return 0; 
} 
