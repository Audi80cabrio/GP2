#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<double> coord(3);            // Deklaration eines Vektors mit 3 Elementen
    coord[0] = 1.0;
    coord[1] = 1.5;
    coord[2] = 2.0;
    cout << coord[0] << ' ' << coord[1] << ' ' << coord[2] << ' ' << '\n';

    vector<double> coord2{1.0, 1.5, 2.0}; // Deklaration mit Initialisierung
    cout << coord2[0] << ' ' << coord2[1] << ' ' << coord2[2] << ' ' << '\n';

    coord.push_back(0.5);               // Vektoren koennen vergroessert werden
    cout << coord[0] << ' ' << coord[1] << ' ' << coord[2] << ' ' << '\n';

    int no;                             // Die initiale Groesse muss nicht zur
    cin >> no;                          // Compile-Zeit festgelegt werden
    vector<double> v(no);

    // Mit size kann die Laenge ermittelt werden und z.B. in einer Schleife
    // ueber den Vektor verwendet werden
    for (size_t i = 0; i < coord.size(); i++)
        cout << coord[i] << ' ';
    cout << '\n';

    // Alternativ geht auch die Funktion ssize (C++20). Sie liefert
    // praktischerweise ein int statt ein size_t.
    for (int i = 0; i < ssize(coord); i++)
        cout << coord[i] << ' ';
    cout << '\n';

    // Noch einfacher ist die verallgemeinerte for-Schleife (oder foreach-Schleife)
    for (const auto iter : coord)
        cout << iter << ' ';
    cout << '\n';
    // Die Laufvariable iter ist lokal, d.h. Aenderungen wirken sich nicht auf den
    // Vektor aus. Deshalb ist sollte die Laufvariable mit const deklariert werden.
    // auto bedeutet, dass der Datentyp vom Compiler ermittelt wird.

    // Wenn Aenderungen auf den Vektor durchschlagen sollen, ist eine Referenz
    // erforderlich. Dann ohne const.
    for (auto& iter : coord)
        iter = iter + 1.0;
    for (const auto iter : coord)
        cout << iter << ' ';
    cout << '\n';

    // Vektoren koennen sortiert werden. Erforderlich ist #include <algorithm>.
    // ranges befindet sich im Namesraum std.
    //ranges::sort(coord);
    for (const auto iter : coord)
        cout << iter << ' ';
    cout << '\n';

    return 0;
}
