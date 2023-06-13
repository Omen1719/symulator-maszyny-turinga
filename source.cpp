#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <Windows.h>

using namespace std;



// Struktura odpowiedzialna za przechowywanie każdej linijki polecenia
struct command {
    string Q1;
    char v1;
    string arrow;
    string Q2;
    char v2;
    char shiftmove;
};

int main() {
    int i, x,b=0,j;
    char done;
    char przesuniecia[] = {'L', 'l', 'R', 'r', 'P', 'p', 'S', 's', 'N', 'n'};

//Wprowadzenie stanów wykorzystywanych w maszynie
    string positions;
    cout << "Wprowadz stany: "<<endl;
    getline(cin, positions);
    int n = positions.size();
    string QQ;
    int N = 0;
    string* Q = new string[n];



//Wydzielenie ze stringa poszczególnych stanów odzielonych spacjami, bądź przecinkami - pozwala to użytkownikowi na dużą swobodność w metodzie wprowadzania stanów
    for (char c : positions) {
    if (c != ',' && c != ' ')
        QQ += c;
    else if (!QQ.empty()) {
        bool exists = false;
        for (i = 0; i < N; i++) {
            if (Q[i] == QQ) {
                exists = true;
                break;
            }
        }

        if (!exists) {
            Q[N] = QQ;
            N++;
        }

        QQ.clear();
    }
}

    if (!QQ.empty()) {
        bool exists = false;
        for (i = 0; i < N; i++) {
            if (Q[i] == QQ) {
                exists = true;
                break;
            }
        }

        if (!exists) {
            Q[N] = QQ;
            N++;
        }

        QQ.clear();
    }

//Utworzenie finalnej tablicy stanów o odpowiedniej wielkości
    string* Q1 = new string[N];
    for (i = 0; i < N; i++) {
        Q1[i]=Q[i];
    }
delete[] Q;
int positionssize=N;






//Wprowadzenie dopuszczalnych znaków wykorzystywanych w maszynie, jako że maszyna Turinga operuje tylko na jednym znaku na raz, znaki te muszę się składać z pojedynczego znaku
    string signs;
    cout << "Wprowadz znaki: "<<endl;
    getline(cin, signs);
     n = signs.size();
    char* sign=new char[n];
     N = 0;

//Przeniesienie znaków ze stringu do tablic charów pomijając przecinki i spacje
    for (i = 0; i < n; i++) {
        if (signs[i] != ',' && signs[i] != ' ') {
           bool exists = false;
            for (int j = 0; j < N; j++) {
                if (sign[j] == signs[i]) {
                    exists = true;
                    break;
                }
            }

            if (!exists) {
                sign[N] = signs[i];
                N++;
            }
        }
    }

//Finalna tablica charów o poprawnej wielkości
    char* sign1=new char[N];
    for (i = 0; i < N; i++) {
        sign1[i]=sign[i];
    }
    delete[] sign;
    int signssize = N;

//Stan początkowy
cout << "Wprowadz stan poczatkowy nalezacy do wpisanych stanow: ";
string q,q1,q2;
do {
    b=0;
    cin>>q;
    for (i = 0; i < positionssize; i++) {
        if (q==Q1[i]){
            b++;
        }
    }
    if (b!=1){cout<<"ERROR: stan nie istnieje, wprowadz jeszcze raz: ";}
}while (b!=1);
q2=q;

//Znak pusty
cout<< "Wprowadz znak pusty nalezacy do wpisanych znakow: ";
char R;
do {
    b=0;
    cin>> R;
    for (i = 0; i < signssize; i++) {
        if (R==sign1[i]){
            b++;
        }
    }
    if (b!=1){cout<<"ERROR: znak nie istnieje, wprowadz jeszcze raz: ";}
}while (b!=1);

//Wprowadzenie taśmy na której będą wykonywane operacje
string tape;





bool validInput = false;
do {
    cout << "Wprowadz tasme: ";
    cin >> tape;
    n = tape.size();

//Zamiana na tablicę charów, ważne dla późniejszego porównywania
    char tape1[n];
    for (i = 0; i < n; i++) {
            tape1[i]=tape[i];
    }


//Sprawdzenie czy wszystkie znaki na taśmie są zgodne z dozwolonymi znakami wpisanymi wcześniej, jeśli nie, program każe wpisać użytkownikowi taśmę jeszcze raz
    for ( i = 0; i < n; i++) {
        for (x = 0; x < N; x++) {
            if (sign1[x]==tape1[i]) {
                break;
            }
        }
        if (x == N) {
            cout << "ERROR: bledny znak, wprowadz jeszcze raz: " ;
            validInput = false;
            break;
        }
    }

    if (x != N) {
        validInput = true;
    }
} while (!validInput);
char tape1[n];
for (i = 0; i < n; i++) {
            tape1[i]=tape[i];
    }
int tapesize=n;


    int variable;
    cout<<"Wprowadz miejsce na tasmie z ktorego chcesz zaczac (zaczynajac od 1): ";
    cin >>variable;
//Sprawdzenie czy miejsce zaczęcia na taśmie istnieje na taśmie
    if (variable > 0 && variable <= tapesize) {
    variable--;
    } else {

    cout<<"ERROR: bledne miejsce na tasmie, wprowadz jeszcze raz: ";
    cin >>variable;
    }


    vector<command> structures;
int errorCount;


cout << "Q: ";
    for (i = 0; i < positionssize; i++) {
        cout << Q1[i] <<" ";
    }
cout <<endl;

cout << "Symbole: ";
    for (i = 0; i < signssize; i++) {
        cout << sign1[i] << " ";
    }
cout<< endl;
cout<< "Tasma: " << tape <<endl;



cout << "Wprowadz polecenia: "<<endl;


//Wpisywanie poleceń do maszyny Turinga
    for (i = 0; i < positionssize*signssize; i++) {
        command commandline;
        bool found = false;
        errorCount = 0;
        do {
        errorCount = 0;
            cin >> commandline.Q1;
            cin >> commandline.v1;
            cin >> commandline.arrow;
            cin >> commandline.Q2;
            cin >> commandline.v2;
            cin >> commandline.shiftmove;
//Sprawdzenie, czy stan wpisany znajduje się w tablicy dozwolonych stanów
            for (j = 0; j < positionssize; j++) {
                if (commandline.Q1 == Q1[j]) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "ERROR: bledny stan 1" << endl;
                errorCount++;
            }


//Sprawdzenie, czy wartość wpisana znajduje się w tablicy dozwolonych wartości
            found=false;

            for (j = 0; j < signssize; j++) {
                if (commandline.v1 == sign1[j]) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "ERROR: bledna wartosc 1" << endl;
                errorCount++;
            }

//Sprawdzenie, czy stan wpisany znajduje się w tablicy dozwolonych stanów
            found=false;

            for (j = 0; j < positionssize; j++) {
                if (commandline.Q2 == Q1[j]) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "ERROR: bledny stan 2" << endl;
                errorCount++;
            }

//Sprawdzenie, czy wartość wpisana znajduje się w tablicy dozwolonych wartości
            found=false;

            for (j = 0; j < signssize; j++) {
                if (commandline.v2 == sign1[j]) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "ERROR: bledna wartosc 2" << endl;
                errorCount++;
            }

//Sprawdzenie, czy przesuniecie wpisane, znajduje sie w tablicy dozwolonych przesuniec
            found=false;

            for (j = 0; j < 10; j++) {
                if (commandline.shiftmove == przesuniecia[j]) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "ERROR: bledne przesuniecie" << endl;
                errorCount++;
            }

            if (errorCount > 0) {

            cout<< "Wprowadz dane ponownie: ";
            }


        } while (errorCount > 0);



        structures.push_back(commandline);
    }


//Zmienne potrzebne do struktury
    char shift;
    char v3,v4;

while (true) {
    bool commandFound = false;
    for (auto& structure : structures) {
        if (q == structure.Q1 && structure.v1 == tape1[variable]) {
            q1 = q;
            q = structure.Q2;
            v3 = structure.v1;
            v4 = structure.v2;
            tape1[variable] = structure.v2;
            shift = structure.shiftmove;
            commandFound = true;
            break;
        }
    }

    if (!commandFound) {
        cout << "ERROR: Brak polecenia dla kombinacji stanu i wartości na tasmie" << endl;
        break;
    }
    //Wypisanie zmian
    cout << endl;
    cout << q1 << "->" << q << " " << v3 << "->" << v4 <<endl;

    //Czerwona strzałka zaznaczająca obecny stan na taśmie
    for (i = 0; i < tapesize; i++) {
    if (i == variable) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        putch(25);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    } else {
        cout << " ";
    }
}



cout << endl;

for (i = 0; i <tapesize; i++) {
    cout << tape1[i];
}

cout << endl;

    if ((shift == 'L') || (shift == 'l')) {
        variable--;
         if (variable < 0) {
// Dodanie znaku pustego na początku taśmy
                char newTape[tapesize + 1];
                newTape[0] = R;
                for (i = 0; i < tapesize; i++) {
                    newTape[i + 1] = tape1[i];
                }
                tapesize++;
                for (i = 0; i < tapesize + 1; i++) {
                    tape1[i] = newTape[i];
                }
                variable = 0;
            }

    }
    else if ((shift == 'R') || (shift == 'r') || (shift == 'P') || (shift == 'p')) {
        variable++;
        if (variable > tapesize-1) {

// Dodanie znaku pustego na końcu taśmy
    char newTape[tapesize + 1];
    for (i = 0; i < tapesize; i++) {
        newTape[i] = tape1[i];
    }
    newTape[tapesize] = R;
    tapesize++;

    for (i = 0; i < tapesize; i++) {
        tape1[i] = newTape[i];
    }

    variable = tapesize-1;
}
    }
    else if ((shift == 'S') || (shift == 's') || (shift == 'N') || (shift == 'n')) {
        break;
    }



}
do {
        q=q2;
        bool valid = false;
        while (!valid) {
            std::cout << "Czy chcesz wpisac kolejna tasme? (T/N): ";
            std::cin >> done;
            if (done == 'T' || done == 'N') {
                valid = true;
            } else {
                std::cout << "Error: nieprawidlowa wartosc, wprowadz jeszcze raz: ";
            }
        }

        if (done == 'N') {
            break;
        }

        std::string tape;
        std::cout << "Wprowadz tasme: ";
        std::cin >> tape;
        int n = tape.size();

        // Zamiana na tablicę charów, ważne dla późniejszego porównywania
        char tape1[n];
        for (int i = 0; i < n; i++) {
            tape1[i] = tape[i];
        }

        // Sprawdzenie czy wszystkie znaki na taśmie są zgodne z dozwolonymi znakami wpisanymi wcześniej
        bool validInput = true;
        for (int i = 0; i < n; i++) {
            bool found = false;
            for (int x = 0; x < N; x++) {
                if (sign1[x] == tape1[i]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "ERROR: bledny znak, wprowadz jeszcze raz: " << std::endl;
                validInput = false;
                break;
            }
        }

        if (!validInput) {
            continue;
        }

        int tapesize = n;
        int variable;
        std::cout << "Wprowadz miejsce na tasmie z ktorego chcesz zaczac (zaczynajac od 1): ";
        std::cin >> variable;
        // Sprawdzenie czy miejsce zaczęcia na taśmie istnieje na taśmie
        if (variable > 0 && variable <= tapesize) {
            variable--;
        } else {
            std::cout << "ERROR: bledne miejsce na tasmie, wprowadz jeszcze raz: ";
            std::cin >> variable;
        }

        std::cout << "Q: ";
        for (int i = 0; i < positionssize; i++) {
            std::cout << Q1[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Symbole: ";
        for (int i = 0; i < signssize; i++) {
            std::cout << sign1[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Tasma: " << tape << std::endl;

        while (true) {
            bool commandFound = false;
            for (const auto& structure : structures) {
                if (q == structure.Q1 && structure.v1 == tape1[variable]) {
                    q1 = q;
                    q = structure.Q2;
                    v3 = structure.v1;
                    v4 = structure.v2;
                    tape1[variable] = structure.v2;
                    shift = structure.shiftmove;
                    commandFound = true;
                    break;
                }
            }

            if (!commandFound) {
                std::cout << "ERROR: Brak polecenia dla kombinacji stanu i wartosci na tasmie" << std::endl;
                break;
            }

            // Wypisanie zmian
            std::cout << std::endl;
            std::cout << q1 << "->" << q << " " << v3 << "->" << v4 << std::endl;

            // Czerwona strzałka zaznaczająca obecny stan na taśmie
            for (int i = 0; i < tapesize; i++) {
                if (i == variable) {
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    putch(25);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                } else {
                    std::cout << " ";
                }
            }

            std::cout << std::endl;

            for (int i = 0; i < tapesize; i++) {
                std::cout << tape1[i];
            }

            std::cout << std::endl;

            if (shift == 'L' || shift == 'l') {
                variable--;
                if (variable < 0) {
                    // Dodanie znaku pustego na początku taśmy
                    char newTape[tapesize + 1];
                    newTape[0] = R;
                    for (int i = 0; i < tapesize; i++) {
                        newTape[i + 1] = tape1[i];
                    }
                    tapesize++;
                    for (int i = 0; i < tapesize + 1; i++) {
                        tape1[i] = newTape[i];
                    }
                    variable = 0;
                }
            } else if (shift == 'R' || shift == 'r' || shift == 'P' || shift == 'p') {
                variable++;
                if (variable >= tapesize) {
                    // Dodanie znaku pustego na końcu taśmy
                    char newTape[tapesize + 1];
                    for (int i = 0; i < tapesize; i++) {
                        newTape[i] = tape1[i];
                    }
                    newTape[tapesize] = R;
                    tapesize++;

                    for (int i = 0; i < tapesize; i++) {
                        tape1[i] = newTape[i];
                    }

                    variable = tapesize - 1;
                }
            } else if (shift == 'S' || shift == 's' || shift == 'N' || shift == 'n') {
                break;
            }
        }
    } while (done != 'N');
    delete[] Q1;
    delete[] sign1;
    return 0;
}
