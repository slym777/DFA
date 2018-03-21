/// DFA
#include <bits/stdc++.h>

using namespace std;

int nrq, nrqf, nralfa, nrtranz;
int x,z; string y; bool b;

ifstream fin("input.in");
ofstream fout("input.out");

vector < int > q;
vector < string > alfa;

class DFA{
    map < pair < int, string >, int > tranzitie;
    set < int > starifinale;
    int starestart;
public :
    DFA ();
    ~DFA ();
    bool testare(int);
};

DFA :: DFA ()
{
     fin >> nrq;                          /// nr de stari
    q.resize(nrq);
    for ( int i = 0; i < nrq; i++)      /// vectorul de stari
        {
            fin >> x;
            q.push_back(x);
        }

    fin >> nralfa;                      /// nr elementelor distincte din alfabet
    alfa.resize(nralfa);                 /// alfabetul propriu-zis
    for ( int i = 0; i < nralfa; i++ )
        {
            fin >> y;
            alfa.push_back(y);
        }

    fin >> starestart;                     /// stare initiala

    fin >> nrqf;                             /// nr starilor finale
    for ( int i = 0 ; i < nrqf ; i++)       /// vectorul de stari finale
    {
        fin >> x;
        starifinale.insert(x);
    }

    fin >> nrtranz;                           /// nr de tranzitii
    for ( int i = 0 ; i < nrtranz; i++)       /// tranzitiile
    {
        fin >> x >> y >> z;
        tranzitie[make_pair(x, y)] = z;
    }
    cout << " AFD a fost creat cu succes" << endl;
}

DFA :: ~DFA()
{
    tranzitie.clear();
    starifinale.clear();
    starestart = 0;
    cout << " Verificati in fisierul input.out rezultatele " << endl;
}

bool DFA :: testare(int n)
{
    int starecurenta = starestart;
    for (int i = 0 ; i < n ; i++)
    {
        fin >> y;
        starecurenta = tranzitie[make_pair(starecurenta, y)];
    }
    return (starifinale.find(starecurenta) != starifinale.end());
}

int main()
{
    int n,nr;
    DFA d;
    fin >> nr;
    for ( int i = 0 ; i < nr; i++)
    {
        fin >> n;
        b = d.testare(n);
        if (b == 1 )
            fout << "DA" << "\n";
        else
            fout << "NU" << "\n";
    }
    return 0;
}
