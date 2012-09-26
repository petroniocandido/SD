#include "chat.h"
#include <iostream>

using namespace std;

Usuario::Usuario(){
     this->nome = "";
}

Usuario::Usuario(char* n){
     this->nome = n;
}

Usuario::Usuario(string n){
     this->nome = (char *)n.c_str();
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

void ChatServer::Registrar(string usuario){
     Usuario usr(usuario);
     char* key = (char*)usuario.c_str();
     usuarios[key] = usr;
}

vector<char*> ChatServer::Listar(){
        vector<char *> usrs;
        map<char*, Usuario>::iterator it;
        for(it = usuarios.begin(); it != usuarios.end(); it++)
               usrs.push_back((*it).first);
        
        return usrs;
        
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
