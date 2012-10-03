#include <list>
#include <vector>
#include <map>
#include <string>

using namespace std;

class mensagem {
      public:      
       string remetente;
       string corpo;
              
       mensagem(string r, string m) {
           remetente = r;
           corpo = m;
       }
};

class Usuario {
      private:
              list<mensagem> mensagens;
              string nome;
      public:
             Usuario();
             Usuario(string n);
             void adicionarMensagem(string usr, string corpo);
             void adicionarMensagem(mensagem msg);
             mensagem retornaMensagem();
              
};

class ChatServer {
      private:
              map<string, Usuario> usuarios;
      public:
             void Registrar(string usuario);
             vector<string> Listar();
             void Enviar(string usuario, string destinatario, string mensagem);
             void Enviar(string destinatario, mensagem msg);
             mensagem Receber(string usuario);
             void Sair(string usuario); 
};
