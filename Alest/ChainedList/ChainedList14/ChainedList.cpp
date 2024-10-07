#include <iostream>
using namespace std;
struct Node
{
    char info;
    Node *next;
    Node(char i)
    {
        info = i;
        next = nullptr;
        cout << "+ Node(" << info << ") criado..." << endl;
    }
    ~Node() { cout << "- Node(" << info << ") destruido..." << endl; }
};
int main()
{
    Node *head = nullptr, *tail = nullptr; // Criação
    for (char l = 'B'; l <= 'F'; l++)
    {
        if (l == 'D')
            continue; // Evita que o Node com a info 'D' seja inserido na lista...
        Node *aux = new Node(l);
        if (tail == nullptr)
        {
            head = tail = aux;
        }
        else
        {
            tail->next = aux;
            tail = aux;
        }
    }

    // Coloque a solução aqui!
    Node *a = new Node('A'); // inserir no inicio
    a->next = head;
    head = a;

    Node *d = new Node('D'); // inserir no meio
    Node *aux = head, *ant = nullptr;
     while(aux != nullptr && d->info > aux->info){
      ant = aux;
      aux = aux->next;

  }
  if(ant ==nullptr) {d->next = head; head = d;}//inserção no inicio
  else if(aux == nullptr){ tail->next = d; tail = d;}//inserção no final
    ant->next = d;
    d->next = aux;

    Node *g = new Node('G'); // inserir no final
    tail->next = g;
    tail = g;
    cout << ant->info << endl;
    cout << aux->info << endl;

    cout << "head--> "; // Exibição
    for (Node *aux = head; aux != nullptr; aux = aux->next)
        cout << "|" << aux->info << (aux->next == nullptr ? "|X| " : "|| -> ");
    cout << " <--tail" << endl;
    while (head != nullptr)
    {
        Node *aux = head;
        head = head->next;
        delete aux;
    } // Desalocação
    return 0;
}