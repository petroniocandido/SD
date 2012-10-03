#include "chat.h"
#include <iostream>

using namespace std;

Usuario::Usuario(){
     this->nome = "";
}

Usuario::Usuario(string n){
     this->nome = n;
}


void Usuario::adicionarMensagem(string usr, string corpo){
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
     usuarios[(string)usuario] = usr;
}

void ChatServer::Registrar(string usuario){
     Usuario usr(usuario);
//     char* key = (char*)usuario.c_str();
     cout << "Usuario registrado: " << usuario << "." << endl;  
     usuarios[usuario] = usr;
}

vector<string> ChatServer::Listar(){
         //Usuario scnd = usuarios["teste"];
        vector<string> usrs;
        map<string, Usuario>::iterator it;
        for(it = this->usuarios.begin(); it != this->usuarios.end(); ++it){
               string fst = it->first;
               Usuario scnd = it->second;
               usrs.push_back(fst);
               cout << "Listar: " << fst << endl;
        }
        
        return usrs;
        
}

void ChatServer::Enviar(string usuario, string destinatario, string mensagem){
        Usuario usr = usuarios[destinatario];
        usr.adicionarMensagem(usuario, mensagem);
        usuarios[destinatario] = usr;
}

void ChatServer::Enviar(string destinatario, mensagem msg){
        Usuario usr = usuarios[(string)destinatario];
        usr.adicionarMensagem(msg);
        usuarios[destinatario] = usr;
}

mensagem ChatServer::Receber(string usuario){
       Usuario usr = usuarios[usuario];
       mensagem msg = usr.retornaMensagem();
       usuarios[usuario] = usr;
       return msg;
}

void ChatServer::Sair(string usuario){
     usuarios.erase(usuario);
        
}
