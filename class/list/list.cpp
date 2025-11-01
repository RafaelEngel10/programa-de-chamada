#include <iostream>
#include <string.h>
#define null NULL
using namespace std;

typedef struct node {
    string value;
    struct node* next;
} *list;

list valueSet(list called) {
    list aux = called;
    list head = called;

    while (true) {
        cout << "Informe o nome (ou 0 para terminar): ";
        cin >> aux->value;

        if (aux->value == "0" || aux->value == "0-" || aux->value == "-0") {
            aux->value = "Fim da lista de nomes!\0";
            aux->next = NULL;
            break;
        }

        aux->next = new node;
        aux = aux->next;
    }

    cout << "Nomes validados com sucesso!" << endl;
    return head;
}

void showValues(list called) {
    list aux = called;
    int I = 1;

    while (aux != null) {
        if (aux->next == null) 
            cout << aux->value << endl;
        else 
            cout << I << "o nome: " << aux->value << ";" << endl;
        aux = aux->next;
        I++;
    }
}

list checkPresence(list called) {
    list aux = called;
    list head = new node;
    list paux = head;

    while (aux != NULL) {
        if (aux->value == "Fim da lista de nomes!\0") 
            break;
        else {
            cout << aux->value << " esta presente? (Sim/Nao): ";
            cin >> paux->value;
        }

        if (aux->next == NULL) {
            paux->next = NULL;
            break;
        } else {
            paux->next = new node;
            paux = paux->next;
        }

        aux = aux->next;
    }

    cout << "Chamada realizada com sucesso!" << endl;
    return head;
}

void showPresence(list called, list name, list presence) {
    list n = name;
    list p = presence;

    cout << endl << "=== Presencas ===" << endl;

    while (n != NULL && p != NULL) {
        if (n->value == "Fim da lista de nomes!\0") 
            break;
        cout << n->value << " esta presente? " << p->value << endl;
        n = n->next;
        p = p->next;
    }
}


int main() {
    list call;
    list classPresence;
    list names;
    int OP;

    call = new node;

    /* Comeco do menu de opcões */
    do {
        cout << endl << "====== Direcao  ======" << endl;
        cout << "= 0. Sair/terminar   =" << endl;
        cout << "= 1. Colocar nomes   =" << endl;
        cout << "= 2. Mostrar nomes   =" << endl;
        cout << "= 3. Fazer chamada   =" << endl;
        cout << "= 4. Mostrar chamada =" << endl;
        cout << "= 5. Lançar notas    =" << endl;
        cout << "= 6.                 =" << endl;
        cout << "======================" << endl;
        cout << "Digite uma opcao: "; 
        cin >> OP; 
        cout << endl;
        switch (OP) {
            case 0: 
                cout << "Saindo do programa..." << endl;
                break;
            case 1:
                names = valueSet(call);
                break;
            case 2:
                showValues(call);
                break;
            case 3: 
                classPresence = checkPresence(call);
                break;
            case 4: 
                showPresence(call, names, classPresence);
                break;
            case 5: 
                
                break;
            default:
                cout << "Digite um valor valido!" << endl;
                break;
        }
    } while (OP!=0);
    
    
    return 0; 
}