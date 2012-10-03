#include <iostream> 
#include <stdio.h>
#include <string.h>
#include "chat.h"
using namespace std;

void teste() {
     char *log;
     
     log = "teste"; 
        
    int port = 8000; 
   
    XmlRpcClient c("127.0.0.1", port); 

    cout << "Entre com o seu login " << endl;
        
    cout << "Conectando com o login: " << log << "." <<endl;

    Chat chat(&c, (string)log);
    
    bool status = false;
    
    cout << "Conectando..." << endl;
    
    status = chat.Registrar();
    
    status = chat.Listar();
    
    status = chat.Enviar("teste","msg teste");
    
   status = chat.Receber();
   
   status = chat.Sair();
}

void main_loop() {
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
    
    bool menu = true;
    
    while(menu){
   
                // Receber mensagens 
                
                    
                cout << "\nm)mostrar mensagens l) listar usuários; e) enviar mensagem; q) sair" << endl;
                
                gets(input);
                
                if(strcmp(input,"l")==0){
                         cout << "\nUsuários registrados: " << endl;
                         status = chat.Listar();
                }
                else if(strcmp(input,"e")==0){
                     char dest[16], msg[200];
                     cout << "Para quem:" << endl;
                     gets(dest);
                     cout << "Mensagem [finaliza com enter]:" << endl;
                     gets(msg);
                     status = chat.Enviar(dest, msg);
                     cout << "Mensagem enviada!" << endl;
                }
                else if(strcmp(input,"m")==0){
                     status = chat.Receber();
                }
                else if(strcmp(input,"q")==0){
                     status = chat.Sair();
                     menu = false;
                }
                else {
                     cout << "Opção inválida:" << input << "." << endl;
                }
    }    
}

int main(int argc, char* argv[]) 
{ 
    //teste();
    
    main_loop();

    return 0; 
} 


