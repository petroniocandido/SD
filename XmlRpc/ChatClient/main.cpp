#include <iostream> 
#include <stdio.h>
#include "chat.h"
using namespace std;

int main(int argc, char* argv[]) 
{ 
    char log[16]; 
        
    int port = 8000; 
   
    XmlRpcClient c("127.0.0.1", port); 

    cout << "Entre com o seu login " << endl;
    
    gets(log);
    
    cout << "Conectando com o login: " << log << "." <<endl;

    Chat chat(&c, log);
    
    bool status = false;
    
    cout << "Conectando..." << endl;
    
    status = chat.Registrar();
    
    if(status)
        cout << "Conectado e registrado!" << endl;
    else
        cout << "Erro!" << endl;
    
    char input[100];
    
    while(input != "q"){
   
                // Receber mensagens 
                
    
                cout << "l) listar usuários; e) enviar mensagem; q) sair" << endl;
                
                gets(input);
                
                if(input == "l"){
                         status = chat.Listar();
                }
                else if(input == "e"){
                }
                else if(input == "q"){
                }
                else {
                     cout << "Opção inválida:" << input << "." << endl;
                }
    }    

    return 0; 
} 


