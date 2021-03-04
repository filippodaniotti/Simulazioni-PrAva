#include <iostream>
#include <vector>
#include <list>
#include <cmath>

#define MIN -500
#define MAX 500
using namespace std;

int random (int max, int min)
{
    return rand() % (max - min + 1) + min;
}

class File
{
private:
    string nome;
    int dimensione;
public:
    File (string _n, int _d);
    ~File ();
    friend ostream& operator << (ostream& os, const File& f);
};

File::File (string _n, int _d)
{
    nome = _n;
    if (_d > 0)
        dimensione = _d;
    else
        throw "Dimensione negativa!";
}

File::~File () {}

ostream& operator << (ostream& os, const File& f)
{
    return os << "File " << f.nome << " dim=" << f.dimensione;
}

class Directory
{
private:
    string nome;
    int dimensione;
    list<File*> files;
public:
    Directory (string _n);
    ~Directory ();
    void addFile (string _n, int _d);
    friend ostream& operator << (ostream& os, const Directory& dir);
};

Directory::Directory (string _n)
{
    nome = _n;
    dimensione = 0;
}

Directory::~Directory () {}

void Directory::addFile (string _n, int _d)
{
    try {
        files.push_back(new File(_n, _d));
        dimensione += _d;
    } catch (const char* ex) {
        cout << ex << endl;
        files.push_back(new File(_n, abs(_d)));
        dimensione += abs(_d);
    }
}

ostream& operator << (ostream& os, const Directory& dir)
{
    os << "Directory " << dir.nome << " ";
    if (dir.dimensione > 0) {
        os << "dim=" << dir.dimensione << " files:" << endl;
        for (auto f : dir.files) {
            cout << ">>> " << *f << endl;
        }
    } else {
        os << "non possiede alcun file!";
    }
    return os;
}

int main() {

    vector<Directory> dirs;

    dirs.push_back(Directory("DirA"));
    dirs.push_back(Directory("DirB"));
    dirs.push_back(Directory("DirC"));

    dirs[0].addFile("esame.txt", random(MAX, MIN));
    dirs[0].addFile("vacanza.txt", random(MAX, MIN));
    dirs[0].addFile("looking glass.txt", random(MAX, MIN));
    dirs[1].addFile("complotto.txt", random(MAX, MIN));
    dirs[1].addFile("viulenza.txt", random(MAX, MIN));
    dirs[1].addFile("hybris.txt", random(MAX, MIN));
    dirs[2].addFile("ovidio.txt", random(MAX, MIN));
    dirs[2].addFile("marc bloch.txt", random(MAX, MIN));
    dirs[2].addFile("dulce et decorum est pro patria mori.txt", random(MAX, MIN));

    for (auto dir : dirs) {
        cout << dir << endl;
    }

    return 0;
}