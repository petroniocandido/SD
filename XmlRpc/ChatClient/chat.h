#include "XmlRpc.h"
#include <string>
 
using namespace std; 
using namespace XmlRpc; 

class Chat {
      private:
             XmlRpcClient *rpc;
             string login;
      public:
             Chat(XmlRpcClient *c, string l) {
                this->rpc = c;
                this->login = l;
             }
             
             bool Registrar() {
                 XmlRpcValue result;
                 XmlRpcValue log;
                 log[0] = (string)login;
                 if (rpc->execute("registrar", log, result)) 
                    return true;
                else 
                    return false; 
             }
             
             bool Listar() {
                 XmlRpcValue noArg, result;
                 if (rpc->execute("listar", noArg, result)) {
                    int size = result.size();
                    for(int i = 0; i < size; i++)
                            cout << result[i] << endl;
                    return true;
                 }
                else 
                    return false;
            }
            
            bool Enviar(string dest, string msg) {
                XmlRpcValue params;
                params[0] = (string)login;
                params[1] = (string)dest; 
                params[2] = (string)msg;
                
                 XmlRpcValue result;
                 if (rpc->execute("enviar", params, result)) 
                    return true;
                else 
                    return false; 
            }
            
            bool Receber() {
                XmlRpcValue result;
                 XmlRpcValue log;
                 log[0] = (string)login;
                 if (rpc->execute("receber", log, result)) {
                    int size = result.size();
                    for(int i = 0; i < size; i++)
                            cout << result[i] << endl;
                    return true;
                 }
                else 
                    return false; 
            }
            
            bool Sair() {
                XmlRpcValue log;
                 log[0] = (string)login;
                 XmlRpcValue result;
                 if (rpc->execute("sair", log, result)) {
                    return true;
                 }
                else 
                    return false; 
            }
};
             
