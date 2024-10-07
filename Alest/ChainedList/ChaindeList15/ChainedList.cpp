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
    }
};

int main(){

    Node *head = nullptr, *tail = nullptr, *aux;
    char c;
    bool fim = false;
    unsigned pos;
    cout << "'<' = PUSH_FRONT / '>' = PUSH_BACK / '{' = POP_FRONT / '}' = POP_BACK '+' = INSERT / '-' = REMOVE / '.' = QUIT" << endl;
    while (!fim)
    {
        aux = head; // Mostra a lista
        while (aux != nullptr)
        {
            cout << "|" << aux->info;
            aux = aux->next;
        }
        cout << "|" << endl;
        cin >> c;
        switch (c)
        {
        case '<':
            cin >> c; 
            aux = new Node(c);
            if(head == nullptr) { head = tail= aux;}
            else {aux ->next = head; head = aux; }
            break;
        case '>':
            cin >> c; /* ... */
            break;
        case '+':
            cin >> c >> pos; /* ... */
            break;
        case '}': /* ... */
            break;
        case '{': /* ... */
            break;
        case '-':
            cin >> pos; /* ... */
            break;
        case '.':
            fim = true;
            break;
        }
    }
    while (head != nullptr)
    {
        aux = head;
        head = head->next;
        delete aux;
    } // Desaloca a lista
    return 0;
}