#include <iostream>
#include <string>

using namespace std;

int main() {
    string nome1, nome2;

    cout << "Digite o primeiro nome: ";
    cin >> nome1;

    cout << "Digite o segundo nome: ";
    cin >> nome2;

    cout<< "Ordem dos nomes: \n";
    if (nome1 < nome2)
      cout << nome1 << ", " << nome2 << endl;
    else 
      cout << nome2 << ", " << nome1 << endl;

    return 0;
}
