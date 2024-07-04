#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    
    char palavra[30], letra[1], secreta[30];
    int tam, i, chances, acertos;
    bool acerto;
    
    chances = 6;
    tam = 0;
    i = 0;
    acerto = false;
    acertos = 0;
    
    cout << "Digite a palavra secreta: \n";
    cin >> palavra;
    system ("clear");
    
    while (palavra[i] != '\0'){
        i++;
        tam++;
    }
    
    for(i=0; i<tam; i++){
        secreta[i] = '-';
    }
    
    while ((chances > 0) && (acertos < tam)){
        cout << "Chances restantes: " << chances << "\n\n";
        cout << "Palvra secreta: ";
        for(i=0; i<tam; i++){
            cout << secreta[i];
        }
        cout << "\n\nDigite uma letra: ";
        cin >> letra[0];
        for(i=0; i<tam; i++){
            if (palavra[i] == letra[0]){
                acerto = true;
                secreta[i] = palavra[i];
                acertos++;
            }
        }
        if (!acerto){
            chances--;
        }
        acerto = false;
        system("clear");
    }
    if (acertos==tam){
        cout << "Você venceu!\n";
        
    }else{
        cout << "Você perdeu! A palavra era: " << palavra << "\n"; 
    }
    return 0;
    
}