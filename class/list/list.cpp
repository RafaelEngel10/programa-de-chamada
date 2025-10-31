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

    while (aux != null) {
        cout << "Informe o nome: ";
        cin >> aux->value;
        if (aux->value != "0")
            aux->next = new node;
        else 
            aux->next = null;

        if (aux->value == "0" || aux->value == "0-" || aux->value == "-0") 
            aux->value = "Fim da lista de nomes!\0";
        
        aux = aux->next;
    }
    cout << "Nomes colocados com sucesso!" << endl;
    return aux;
}

void showValues(list called) {
    list aux = called;
    int I = 1;

    while (aux != null) {
        if (aux->next == null) /* Condiciona o valor "Fim da lista de nomes!" */
            cout << aux->value << endl;
        else 
            cout << I << "o nome: " << aux->value << ";" << endl;
        aux = aux->next;
        I++;
    }
}

list checkPresence(list called) {
    list aux = called;
    list presence;
    presence = new node;

    while (aux != null) {
        cout << aux->value << " esta presente? " << endl;
        cin >> presence->value;
        if (presence->value == "Sim" || presence->value == "sim")
            cout << "Presenca confirmada!" << endl << endl;
        else
            cout << "Ausencia registrada!" << endl << endl;
        aux = aux->next;
        if (aux->value == "Fim da lista de nomes!\0") 
            break;
    }
    cout << "Chamada realizada com sucesso! Verifique as presencas/ausencias no menu de opcoes." << endl;
    return presence;
}

void showPresence(list called, list name, list presence) {
    list aux = called;

    while (aux != null) {
        cout << name->value << "está" << presence->value << endl;

        name = name->next;
        presence = presence->next;
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
        cout << "= 5.                 =" << endl;
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
            default:
                cout << "Digite um valor valido!" << endl;
                break;
        }
    } while (OP!=0);
    
    

}