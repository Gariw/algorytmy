#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <stack> // biblioteka do stosu
#include <queue> // biblioteka do kolejki
#include <list> // biblioteka do listy
//#include <vector> // tabele
#include <cstdlib>

using namespace std;

void menu(string napisy);
int kursor(int ile, int p, int poz);
void gotoxy(int x, int y);
void spr_klawisz(int klawisz, int klawisz2);
void wyswietl_liste(list <int> lista);
int main()
{
    bool koniec = false, koniec2;
    int wybor = 0, wybor1 = 0, pozycja, poz;
    string napisy_menu[7];
    fstream plik;
    poz = 4;
    napisy_menu[0] = " Rekord \n Tablica \n Lista \n Stos \n Kolejka \n Drzewo \n Graf \n WYJDZ";
    napisy_menu[1] = " Definicja \n Przyklad \n Powrót";
    napisy_menu[2] = " Definicja \n Przyklad \n Powrót";
    napisy_menu[3] = " push_front \n push_back \n pop_front \n pop_back \n size \n empty \n remove \n sort \n reverse \n Powrót";
    napisy_menu[4] = " push \n pop \n empty \n size \n top \n Zmiana 1 elementu stosu \n Powrót";
    napisy_menu[5] = " push \n pop \n empty \n size \n front \n back \n Powrót";
    napisy_menu[6] = "";
    while(koniec == false)
    {
        koniec2 = false;
        system("CLS");
        menu(napisy_menu[0]);
        wybor  = kursor(8,4,poz);
        switch(wybor)
        {

        //STRUKTURA ==================
        case 1:
            poz = 4;
            pozycja = 4;
            do
            {
                system("CLS");
                menu(napisy_menu[1]);
                wybor1 = kursor(3,4,pozycja);
                switch(wybor1)
                {
                case 1://definicja
                    gotoxy(1,10);
                    cout<<"Struktura lub rekord \nTo złożony typ danych występujący w wielu językach programowania,\ngrupujący logicznie powiązane ze sobą dane różnego typu w jednym obszarze"<<endl;
                    cout<<"pamięci. Składowe struktury - pola - są etykietowane, tj. mają swoje"<<endl;
                    cout<<"unikatowe nazwy; poprzez podanie nazwy otrzymuje się dostęp do danego pola"<<endl;
                    spr_klawisz(13,27);
                    pozycja = 4;
                break;
                case 2://przyklady
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    gotoxy(1,9);
                    cout<<"DEFINICJA\n\nstruct ciag\n{\n  char znak;\n};\n"<<endl;
                    cout<<"struct nazwa\n{\n  int a;\n  int b;\n  ciag c;\n}rcA = {1,1}, rcB = {3,4};";
                    gotoxy(20,1);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                    cout<<"Operacje na strukturze"<<endl;
                    gotoxy(22,3);
                    cout<<"int main(){"<<endl;
                    gotoxy(25,4);
                    cout<<"nazwa rcD;"<<endl;
                    gotoxy(25,5);
                    cout<<"rcD.a = 5;"<<endl;
                    gotoxy(25,6);
                    cout<<"rcD.b = 15;"<<endl;
                    gotoxy(25,7);
                    cout<<"nazwa rcC = rcB;";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
                    cout<<"    //rcC.a == 3 | rcC.b == 4"<<endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                    gotoxy(25,8);
                    cout<<"int liczba = rcC.a + rcC.b;";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
                    cout<<"  // liczba == 7"<<endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                    gotoxy(25,9);
                    cout<<"nazwa rcE = {2,3};";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
                    cout<<"  // rcE.a == 2 | rcE.b == 3"<<endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                    gotoxy(25,10);
                    cout<<"rcE.c.znak = 'a';  ";
                    gotoxy(22,11);
                    cout<<"}";
                    spr_klawisz(13,27);
                    pozycja = 5;
                break;
                case 3://koniec
                    koniec2 = true;
                    system("CLS");
                break;
                default:
                    system("CLS");
                    cout<<"Błąd";
                    system("CLS");
                    koniec2 = true;
                break;
                }
            }while(koniec2 == false);
        break;

        //TABLICA =================
        case 2:
            poz = 5;
            pozycja = 4;
            do
            {
                system("CLS");
                menu(napisy_menu[2]);
                wybor1 = kursor(3,4,pozycja);
                switch(wybor1)
                {
                case 1://definicja
                    gotoxy(1,10);
                    cout<<"Tablica \nKontener danych dostępnych, w ktcrym poszczegclne komcrki dostępne są \nza pomocą kluczy, które najczęściej przyjmują wartości numeryczne."<<endl;
                    cout<<"Rozmiar tablicy jest albo ustalony z góry (tablice statyczne), \nalbo może się zmieniać w trakcie wykonywania programu (tablice dynamiczne)"<<endl;
                    spr_klawisz(13,27);
                    pozycja = 4;
                break;
                case 2://przyklady
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    gotoxy(1,9);
                    cout<<"DEKLARACJA\n\nint tab[4][2];"<<endl;
                    cout<<"double *tab2;"<<endl;
                    cout<<"char tabela[2] = {};";
                    gotoxy(20,1);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                    cout<<"Operacje na tabelach"<<endl;
                    gotoxy(22,3);
                    cout<<"int main(){"<<endl;
                    gotoxy(25,4);
                    cout<<"tab2 = new int[14];";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
                    cout<<"    //tab2[0]... tab2[13]"<<endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                    gotoxy(25,5);
                    cout<<"tab[0][0] = 3;"<<endl;
                    gotoxy(25,6);
                    cout<<"tabela[1] = 'w';"<<endl;
                    gotoxy(25,7);
                    cout<<"tab[1][0] = tab[0] + 4;";
                    gotoxy(25,8);
                    cout<<"delete [] tab; ";
                    gotoxy(22,9);
                    cout<<"}";
                    spr_klawisz(13,27);
                    pozycja = 5;
                break;
                case 3://koniec
                    koniec2 = true;
                    system("CLS");
                break;
                default:
                    system("CLS");
                    cout<<"Błąd";
                    system("CLS");
                    koniec2 = true;
                break;
                }
            }while(koniec2 == false);
        break;

        //LISTA ===================
        case 3:
        {
            poz = 6;
            pozycja = 4;
            list <int> lista;
            do
            {
                system("CLS");
                menu(napisy_menu[3]);
                wyswietl_liste(lista);
                wybor1 = kursor(10,4,pozycja);
                int liczba_l;
                switch(wybor1)
                {
                case 1://push_front
                    gotoxy(30,4);
                    cout<<"Podaj liczbe: ";
                    cin>>liczba_l;
                    lista.push_front(liczba_l);
                    pozycja = 4;
                break;
                case 2://push_back
                    gotoxy(30,4);
                    cout<<"Podaj liczbe: ";
                    cin>>liczba_l;
                    lista.push_back(liczba_l);
                    pozycja = 5;
                break;
                case 3://pop_front
                    if(lista.empty())
                    {
                        gotoxy(30,4);
                        cout<<"Lista jest pusta";
                        spr_klawisz(13,27);
                    }
                    else
                    {
                        lista.pop_front();
                    }
                    pozycja = 6;
                break;
                case 4://pop_back
                    if(lista.empty())
                    {
                        gotoxy(30,4);
                        cout<<"Lista jest pusta";
                        spr_klawisz(13,27);

                    }
                    else
                    {
                        lista.pop_back();
                    }
                    pozycja = 7;
                break;
                case 5://size
                    gotoxy(30,4);
                    cout<<"Rozmiar listy: "<<lista.size();
                    spr_klawisz(13,27);
                    pozycja = 8;
                break;
                case 6://empty
                    gotoxy(30,4);
                    if(lista.empty())
                    {
                        cout<<"Lista pusta";
                    }
                    else
                    {
                        cout<<"lista nie pusta";
                    }
                    spr_klawisz(13,27);
                    pozycja = 9;
                break;
                case 7://remove
                    gotoxy(30,4);
                    cout<<"Usun z listy wszystkie liczby rowne: ";
                    cin>>liczba_l;
                    lista.remove(liczba_l);
                    pozycja = 10;
                break;
                case 8://sort
                    lista.sort();
                    pozycja = 11;
                break;
                case 9://sort
                    lista.reverse();
                    pozycja = 12;
                break;
                case 10://koniec
                    koniec2 = true;
                    system("CLS");
                break;
                default:
                    system("CLS");
                    cout<<"Błąd";
                    system("CLS");
                    koniec2 = true;
                break;
                }

            }while(koniec2 == false);
        }
        break;

        //STOS ==================
        case 4:
        {
            poz = 7;
            pozycja = 4;
            stack < int > stosLiczb;
            int liczba_s;
            do
            {
                system("CLS");
                menu(napisy_menu[4]);
                wybor1 = kursor(7,4,pozycja);

                switch(wybor1)
                {
                case 1://push
                    gotoxy(30,4);
                    cout<<"Podaj liczbe: ";
                    cin>>liczba_s;
                    stosLiczb.push(liczba_s);
                    pozycja = 4;
                break;
                case 2://pop
                    if(stosLiczb.empty())
                    {
                        gotoxy(30,4);
                        cout<<"Stos jest pusty. Nie moge zdjąć z niego liczby";
                    }
                    else
                    {
                        liczba_s = stosLiczb.top();
                        stosLiczb.pop();
                        gotoxy(30,4);
                        cout<<"Zdjęcie liczby: "<<liczba_s;
                    }
                    spr_klawisz(13,27);
                    pozycja = 5;
                break;
                case 3://empty
                    if(stosLiczb.empty())
                    {
                        gotoxy(30,4);
                        cout<<"Stos jest pusty";
                    }
                    else
                    {
                        gotoxy(30,4);
                        cout<<"Stos nie jest pusty";
                    }
                    spr_klawisz(13,27);
                    pozycja = 6;
                break;
                case 4://size
                    gotoxy(30,4);
                    cout<<"Stos zawiera "<<stosLiczb.size()<<" elementów";
                    spr_klawisz(13,27);
                    pozycja = 7;
                break;
                case 5://top
                    if(stosLiczb.empty())
                    {
                        gotoxy(30,4);
                        cout<<"Stos jest pusty. Nie moge wyswietlic 1 elementu";
                    }
                    else
                    {
                        gotoxy(30,4);
                        cout<<"Pierwszy element stosu to: "<<stosLiczb.top();
                    }
                    spr_klawisz(13,27);
                    pozycja = 8;
                break;
                case 6://zamiana
                    if(stosLiczb.empty())
                    {
                        gotoxy(30,4);
                        cout<<"Stos jest pusty.";
                        spr_klawisz(13,27);
                    }
                    else
                    {
                        gotoxy(30,4);
                        cout<<"Zamień elemęt: "<<stosLiczb.top()<<" na: ";
                        stosLiczb.pop();
                        cin>>liczba_s;
                        stosLiczb.push(liczba_s);
                    }

                    pozycja = 9;
                break;
                case 7://koniec
                    koniec2 = true;
                    system("CLS");
                break;
                default:
                    system("CLS");
                    cout<<"Błąd";
                    system("CLS");
                    koniec2 = true;
                break;
                }
            }while(koniec2 == false);
        }
        break;

        //KOLEJKA ==================
        case 5:
        {
            poz = 8;
            pozycja = 4;
            queue < int > kolejka;
            int liczba_k;
            do
            {
                system("CLS");
                menu(napisy_menu[5]);
                wybor1 = kursor(7,4,pozycja);

                switch(wybor1)
                {
                case 1://push
                    gotoxy(30,4);
                    cout<<"Podaj liczbe: ";
                    cin>>liczba_k;
                    kolejka.push(liczba_k);
                    pozycja = 4;
                break;
                case 2://pop
                    if(kolejka.empty())
                    {
                        gotoxy(30,4);
                        cout<<"Kolejka jest pusta. Nie moge zdjąć z niej liczby";
                    }
                    else
                    {
                        liczba_k = kolejka.front();
                        kolejka.pop();
                        gotoxy(30,4);
                        cout<<"Zdjęcie liczby: "<<liczba_k;
                    }
                    spr_klawisz(13,27);
                    pozycja = 5;
                break;
                case 3://empty
                    if(kolejka.empty())
                    {
                        gotoxy(30,4);
                        cout<<"Kolejka jest pusta";
                    }
                    else
                    {
                        gotoxy(30,4);
                        cout<<"Kolejka nie jest pusta";
                    }
                    spr_klawisz(13,27);
                    pozycja = 6;
                break;
                case 4://size
                    gotoxy(30,4);
                    cout<<"Kolejka zawiera "<<kolejka.size()<<" elementów";
                    spr_klawisz(13,27);
                    pozycja = 7;
                break;
                case 5://wyswietl 1
                    if(kolejka.empty())
                    {
                        gotoxy(30,4);
                        cout<<"Kolejka jest pusta. Nie moge wyswietlic 1 elementu";
                    }
                    else
                    {
                        gotoxy(30,4);
                        cout<<"Pierwszy element kolejki to: "<<kolejka.front();
                    }
                    spr_klawisz(13,27);
                    pozycja = 8;
                break;
                case 6://wyswietl ostatni
                    if(kolejka.empty())
                    {
                        gotoxy(20,4);
                        cout<<"Kolejka jest pusta. Nie moge wyswietlic ostatniego elementu";
                    }
                    else
                    {
                        gotoxy(30,4);
                        cout<<"Ostatni element kolejki to: "<<kolejka.back();
                    }
                    spr_klawisz(13,27);
                    pozycja = 9;
                break;
                case 7://loniec
                    koniec2 = true;
                    system("CLS");
                break;
                default:
                    system("CLS");
                    cout<<"Błąd";
                    system("CLS");
                    koniec2 = true;
                break;
                }
            }while(koniec2 == false);
        }
        break;
        //DRZEWO===================
        case 6:
        {
            poz = 9;
            pozycja = 4;
            do
            {
                system("CLS");
                menu(napisy_menu[5]);
                wybor1 = kursor(7,4,pozycja);

            }while(koniec2 == false);
        }
        break;
        //KONIEC ===================
        case 7:
            koniec = true;
            system("CLS");
            switch(wybor1)
            {
            case 7://loniec
                koniec2 = true;
                system("CLS");
            break;
            default:
                system("CLS");
                cout<<"Błąd";
                system("CLS");
                koniec2 = true;
            break;
            }
        break;
        //====================
        default:
            koniec = true;
            system("CLS");
            cout<<"ERROR 404"<<endl;
        break;
        }
    }


    return 0;
}

// Menu
void menu(string napisy)
{
    cout<<"==========="<<endl;
    cout<<"    MENU   "<<endl;
    cout<<"==========="<<endl;
    cout<<napisy<<endl;
}
//pozycja wyboru
int kursor(int ile, int p, int poz)
{
    int a = 1,b = poz, wyjscie;
    gotoxy(a,b);
    char z = 16;
    cout<<z;
    bool koniec = false;
    while( koniec == false )
    {
        unsigned char znak = getch();
        switch( znak )
        {
        case 0: //klawisze specjalne (czasem zero czasem 224 - zale?ne od pc'ta chyba)
        case 224: //klawisze specjalne
            znak = getch();
            switch( znak )
            {
            case 72: //strza3ka w gcre
                gotoxy(a,b);
                cout<<' ';
                b--;
                if(b == p-1)
                    b = b + ile;
                gotoxy(a,b);
                cout<<z;
            break;
            case 80: //strza3ka w dc3
                gotoxy(a,b);
                cout<<' ';
                b++;
                if(b == p + ile)
                    b = p;
                gotoxy(a,b);
                cout<<z;
            break;
            }
        znak = 0;
        break;
        case 13: //ENTER
            koniec = true;
            wyjscie = b - p + 1;
            break;
        case 27: //ESC
            koniec = true;
            wyjscie = ile;
            break;
        }
    }
    return(wyjscie);
}
//gotoxy
void gotoxy(int x, int y)
{
  COORD c;
  c.X=x-1;
  c.Y=y-1;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
//Sprawdza klawisz
void spr_klawisz(int klawisz, int klawisz2)
{
    int kontrola = 0;
    do
    {
        kontrola = getch();
        if(kontrola == klawisz2)
        {
            break;
        }

    }while(kontrola != klawisz);
}

void wyswietl_liste(list <int> lista)
{
    gotoxy(2,16);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
    cout<<"LISTA [ ";
    for(list<int>::iterator i=lista.begin(); i!= lista.end(); i++)
    {
       cout<<*i<<" ";
    }
    cout<<"]";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}
