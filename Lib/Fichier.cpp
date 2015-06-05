#include "Fichier.h"

Fichier::Fichier(const string name) 
{
    NameFile = name;
    stream.open(name.c_str());
}

Fichier::Fichier(Fichier & f) 
{
    if(f.isOpen())
    {
        stream.open(f.NameFile.c_str());
        stream.seekg(f.stream.tellg());
    }
}

Fichier::~Fichier() 
{
    this->stream.close();
}

string Fichier::readLine() 
{
    string line;
    getline(this->stream, line, '\n');
    return line;
}

ListeS<string> Fichier::readLine(char splitchar)
{
    string line;
    // cout << "debut split" << endl;
    getline(this->stream, line);
    // cout << "ligne recup : " << line << endl;
    string elem;
    ListeS<string> list;

    for (int i = 0 ; i < line.size() ; ++i) 
    {
        if (line.at(i) == splitchar) 
        {
            // cout << elem << endl;
            list.insere(elem);
            elem.clear();
            continue;
        }
        elem += line.at(i);
    }

    if (elem != "")
    {
        // cout << elem << endl;
        list.insere(elem);
    }

    // cout << "this is the split list in file" << endl;
    // list.affiche();
    return list;
}

ListeS<string> Fichier::readLines() 
{
    ListeS<string> lines;

    string line = readLine();
    while (!this->end()) 
    {
        lines.insere(line);
        line = this->readLine();
    }

    return lines;
}
