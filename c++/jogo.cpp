#include <iostream>
#include <stdlib.h>
#include <string>
#include <unistd.h>
using namespace std;

string minusculo(string);  // Todos os caracteres e strings do programa serÃ£o passados para letras minÃºsculas.

int main()
{

    string letras_erradas, palavra, secreta, sletra;
    char letra;
    int tam, i, chances, acertos, space[10], j;
    bool acerto;

    chances = 6;
    tam = 0;
    i = 0;
    j = 0;
    acerto = false;
    acertos = 0;

    cout << "Digite a palavra secreta: \n";
    getline(cin, palavra);
    system("cls");
	
    tam = palavra.size();

    for (i = 0; i < palavra.size(); i++)
    {
        if (palavra[i] == ' ')
        {
            space[j] = i;
            tam--;
            j++;
        }
    }
    j = 0;

    for (i = 0; i < palavra.size(); i++)
    {
        if (i == space[j])
        {
            j++;
            secreta[i] = ' ';
        }
        else
        {
            secreta[i] = '_';
        }
    }
    while ((chances > 0) && (acertos < tam))
    {
        cout << "Chances restantes: " << chances << "\n\n";
        cout << "Palavra secreta: ";
        for (i = 0; i < palavra.size(); i++)
        {
            cout << secreta[i];
        }
        cout << "\n\nLetras erradas: " << letras_erradas << endl;
        cout << "\n\nDigite uma letra: ";

        cin >> sletra;
        sletra = minusculo(sletra);
        letra = sletra[0];  // Isso resolve o problema de colocar mais de 1 letra.
        for (i = 0; i < palavra.size(); i++)
        {
            if (palavra[i] == letra)
            {
                if (palavra[i] == secreta[i])
                {
                    cout << "\n\nAtencao! Esta letra ja foi digitada !";
                    chances--;
                    acerto = true;
                    sleep(2);
                    break;
                }
                else
                {
                    acerto = true;
                    secreta[i] = palavra[i];
                    acertos++;
                }
            }
        }
        if (!acerto)
        {
            chances--;
            letras_erradas += letra;
            letras_erradas += ", ";
            cout << "Letras erradas: " << letras_erradas << endl;
        }
        acerto = false;
        system("cls");
    }
    if (acertos == tam)
    {
        cout << "Parabens, Voce venceu! A palavra era: " << palavra << "\n";
    }
    else
    {
        cout << "Voce perdeu! A palavra era: " << palavra << "\n";
    }
    return 0;
}
string minusculo(string nome)
{
    int tam;
    string str;
    tam = nome.size();
    str = nome;
    for (int j = 0; j < tam; j++)
    {
        str[j] = tolower(nome[j]);
    }
    return str;
}