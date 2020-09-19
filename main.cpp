#include <iostream>
#include <cstdlib>

using namespace std;


int main()
{
    int przystanki, pasazerowie; //n - przystanki, q - pasazerowie
    cout << "Wprowadz liczbe przystankow:" << endl;
    cin >> przystanki;
    cout << "Wprowadz liczbe pasazerow:" << endl;
    cin >> pasazerowie;

    int * kosztyodc = new int[przystanki-1]; //tab. dynamiczna - wielkosc tab. okreslona przez uzytkownika //--------------------------------- bardzo dobra nazwa
    int * sumakosztow = new int[przystanki];
    sumakosztow[0] = 0;

    for( int a = 0; a <= przystanki-2; a++) //--------------------------------- zwykle iteruje sie po indeksach i,j,k
    {
        cout << "Wprowadz koszt przejazdu dla odcinka: " << a+1 << endl;
        cin >> kosztyodc[a];

        sumakosztow[a+1] = sumakosztow[a] + kosztyodc[a]; //jak zrobie tab dynamiczna na sumekosztow to musi dodawac sumakosztow[0] = kosztyodc[1] | sumakosztow[1] = sumakosztow[0] + kosztyodc[2]
        //cout << "check ----->" << sumakosztow[a+1] << " / " << sumakosztow[a] << " / " << kosztyodc[a] << endl;

    }

    cout << "Jest " << pasazerowie;
    if (pasazerowie <= 1) cout << " pasazer. ";
    else cout << " pasazerow. ";
    cout << "O tym ile przystankow przejedzie dany pasazer "
    "zdecyduje (prawie) slepy los." << endl;

    srand(345345);

    for( int a = 0; a < pasazerowie; a++)
    {

        int koniec = (rand() % przystanki) + 1;
        int start = (rand() % przystanki) + 1;
        if (koniec < start)
            swap(start, koniec);

        cout << "Pasazer nr " << a+1 << " pojechal z przystanku " << start
        << " na przystanek " << koniec <<
        " i zaplacil ";

        cout << sumakosztow[koniec-1] - sumakosztow[start-1] << endl;

    }

    delete [] kosztyodc;
    delete [] sumakosztow;

    return 0;
}
