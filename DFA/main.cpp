#include <bits/stdc++.h>

using namespace std;
int nrq, nrqf, nralfa, nrtranz;
int x,z; char y; bool b;

ifstream fin("input.in");
ofstream fout("input.out");

vector < int > q;
vector < char > alfa;

class DFA{
    map < pair < int, char >, int > tranzitie;
    set < int > starifinale;
    int starestart;
public :
    DFA (){ cout << " Automatul a fost creat cu succes "; }
    ~DFA ()
    {   tranzitie.clear();
        starifinale.clear();
        starestart = 0;
        cout << " Verificati in fisierul input.out rezultatele "; }
    void incarca_DFA();
    bool testare(string);
};

void DFA :: incarca_DFA()
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

    fin >> nrtranz;
    for ( int i = 0 ; i < nrtranz; i++)
    {
        fin >> x >> y >> z;
        tranzitie[make_pair(x, y)] = z;
    }
}

bool DFA :: testare(string s)
{
    int starecurenta = starestart;
    for (string :: iterator itr = s.begin(); itr!=s.end(); ++itr)
        starecurenta = tranzitie[make_pair(starecurenta, *itr)];
    return (starifinale.find(starecurenta) != starifinale.end());
}


int main()
{
    int n;
    DFA d;
    d.incarca_DFA();
    fin >> n;
    string s;
    for (int i = 1; i <= n; i++)
    {
        fin >> s;
        b = d.testare( s);
        if (b == 1 )
            fout << "DA" << "\n";
        else
            fout << "NU" << "\n";
    }

    return 0;
}
