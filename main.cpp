#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#define MAX_NAME 512
#define MAX_ID 50
#define MAX_FOLLOWERS 10
#define MAX_POPULARITY 10


struct Artista
{
    char id[MAX_ID]; 
    float followers;
    char name[MAX_NAME]; 
    int popularity;
};


void artista_Save(Artista &art, ofstream &fileOut) 
{
    fileOut.write(art.id, sizeof(art.id));
    fileOut.write((char*)&art.followers, sizeof(art.followers));
    fileOut.write(art.name, sizeof(art.name));
    fileOut.write((char*)&art.popularity, sizeof(art.popularity));
}

void artista_Read(Artista &art, ifstream &fileI)
{
    Artista artR;

    fileI.read(artR.id, sizeof(art.id));
    fileI.read((char*)&artR.followers, sizeof(art.followers));
    fileI.read(artR.name, sizeof(art.name));
    fileI.read((char*)&artR.popularity, sizeof(art.popularity));

    cout << "\nLendo dados de arquivo binario: " << endl;
    cout << "id: " << artR.id << endl;
    cout << "followers: " <<  artR.followers << endl;
    cout << "name: " << artR.name << endl;
    cout << "popularity: " << artR.popularity << endl << endl;
}

void imprime_Artista(Artista &art)
{
    cout << "\nLendo dados de struct Artista: " << endl;
    cout << "id: " << art.id << endl;
    cout << "followers: " <<  art.followers << endl;
    cout << "name: " << art.name << endl;
    cout << "popularity: " << art.popularity << endl << endl;
}

int main()
{
    //pega dados de .csv e salva em struct
    ifstream fileIn;
    fileIn.open("artistas.csv");
    Artista art1;


    if(fileIn.is_open())
    {
        string tmp;

        getline(fileIn, tmp, ',');
        strcpy(art1.id, tmp.c_str());

        getline(fileIn, tmp, ',');
        //strcpy(art1.followers, tmp.c_str());
        art1.followers = atof(tmp.c_str());

        getline(fileIn, tmp, ',');
        strcpy(art1.name, tmp.c_str());

        getline(fileIn, tmp, '\n');
        //strcpy(art1.popularity, tmp.c_str());
        art1.popularity = atoi(tmp.c_str());

        imprime_Artista(art1);

        fileIn.close();
    }
    else
    {
        cout << "Erro" << endl;
        exit(1);
    } 

    //pega o q tá no struct e salva em arquivo binário
    ofstream fileOut;
    fileOut.open("artistas.bin", ios::out | ios::binary); 

    if(fileOut.is_open())
    {
        artista_Save(art1, fileOut);
        fileOut.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo" << endl;
        exit(1);
    } 

    //lê o que tá no arquivo binário artistas.bin
    ifstream fileI;
    fileI.open("artistas.bin", ios::in | ios::binary);

    if(fileI.is_open())
    {
        artista_Read(art1, fileI);
        fileI.close();
    }
    else
    {
        cout << "Erro" << endl;
        exit(1);
    } 



return 0;
}