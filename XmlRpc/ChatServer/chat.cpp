#include "chat.h"
#include <iostream>

using namespace std;

Usuario::Usuario(){
     this->nome = "";
}

Usuario::Usuario(char* n){
     this->nome = n;
}

void Usuario::adicionarMensagem(char* usr, char* corpo){
     mensagem msg( usr, corpo );
     mensagens.push_back(msg);
     
     cout << "Msgs" << mensagens.size()  << endl;
}

void Usuario::adicionarMensagem(mensagem msg){
    
     mensagens.push_back(msg);
     
     cout << mensagens.size() << endl;
}

mensagem Usuario::retornaMensagem() {
         mensagem msg = mensagens.front();
         mensagens.pop_front();
        
         return msg;
}

void ChatServer::Registrar(char* usuario){
     Usuario usr(usuario);
     usuarios[usuario] = usr;
}

char** ChatServer::Listar(){
        return NULL;
}

void ChatServer::Enviar(char* usuario, char* destinatario, char* mensagem){
        Usuario usr = usuarios[destinatario];
        usr.adicionarMensagem(usuario, mensagem);
        usuarios[destinatario] = usr;
}

void ChatServer::Enviar(char* destinatario, mensagem msg){
        Usuario usr = usuarios[destinatario];
        usr.adicionarMensagem(msg);
        usuarios[destinatario] = usr;
}

mensagem ChatServer::Receber(char* usuario){
       Usuario usr = usuarios[usuario];
       mensagem msg = usr.retornaMensagem();
       usuarios[usuario] = usr;
       return msg;
}

void ChatServer::Sair(char* usuario){
     usuarios.erase(usuario);
        
}
