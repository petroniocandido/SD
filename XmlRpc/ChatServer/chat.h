#include <list>
#include <map>

using namespace std;

class mensagem {
      public:      
       char* remetente;
       char* corpo;
              
       mensagem(char* r, char* m) {
           remetente = r;
           corpo = m;
       }
};

class Usuario {
      private:
              list<mensagem> mensagens;
              char* nome;
      public:
             Usuario();
             Usuario(char* n);
             void adicionarMensagem(char* usr, char* corpo);
             void adicionarMensagem(mensagem msg);
             mensagem retornaMensagem();
              
};

class ChatServer {
      private:
              map<char*, Usuario> usuarios;
      public:
             void Registrar(char* usuario);
             char** Listar();
             void Enviar(char* usuario, char* destinatario, char* mensagem);
             void Enviar(char* destinatario, mensagem msg);
             mensagem Receber(char* usuario);
             void Sair(char* usuario); 
};
