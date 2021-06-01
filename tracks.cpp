#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#define MAX_ID 50
#define MAX_NAME 512
// #define MAX_POPULARITY 10
// #define MAX_DURATION 300
// #define MAX_EXPLICIT 10
#define MAX_ARTISTS 512
#define MAX_ID_ARTISTS 50
#define MAX_RELEASE_DATE 20
// #define MAX_DANCEABILITY 10
// #define MAX_ENERGY 10
// #define MAX_KEY 10
// #define MAX_LOUDNESS 30
// #define MAX_MODE 10
// #define MAX_SPEECHINESS 10
// #define MAX_ACOUSTICNESS 10
// #define MAX_INSTRUMENTALNESS 10
// #define MAX_LIVENESS 10
// #define MAX_VALENCE 10
// #define MAX_TEMPO 20
// #define MAX_TIME_SIGNATURE 10

struct Track
{
    char id[MAX_ID];
    char name[MAX_NAME];
    int popularity;
    int duration;
    int explicitt; // explicit parece ser uma palavra reservada
    char artist[MAX_NAME];
    char idArtist[MAX_ID_ARTISTS];
    char releaseDate[MAX_RELEASE_DATE];
    float danceability;
    float energy;
    int key;
    float loudness;
    int mode;
    float speechiness;
    float acousticness;
    float instrumentalness;
    float liveness;
    float valence;
    float tempo;
    int timeSignature;
};

void Track_Save(Track &track, fstream &file){
    file.write(track.id, sizeof(track.id));
    file.write(track.name, sizeof(track.name));
    file.write((char*)&track.popularity, sizeof(track.popularity));
    file.write((char*)&track.duration, sizeof(track.duration));
    file.write((char*)&track.explicitt, sizeof(track.explicitt));
    file.write(track.artist, sizeof(track.artist));
    file.write(track.idArtist, sizeof(track.idArtist));
    file.write(track.releaseDate, sizeof(track.releaseDate));
    file.write((char*)&track.danceability, sizeof(track.danceability));
    file.write((char*)&track.energy, sizeof(track.energy));
    file.write((char*)&track.key, sizeof(track.key));
    file.write((char*)&track.loudness, sizeof(track.loudness));
    file.write((char*)&track.mode, sizeof(track.mode));
    file.write((char*)&track.speechiness, sizeof(track.speechiness));
    file.write((char*)&track.acousticness, sizeof(track.acousticness));
    file.write((char*)&track.instrumentalness, sizeof(track.instrumentalness));
    file.write((char*)&track.liveness, sizeof(track.liveness));
    file.write((char*)&track.valence, sizeof(track.valence));
    file.write((char*)&track.tempo, sizeof(track.tempo));
    file.write((char*)&track.timeSignature, sizeof(track.timeSignature));
}

void Track_Read(Track &track, fstream &file){
    file.read(track.id, sizeof(track.id));
    file.read(track.name, sizeof(track.name));
    file.read((char*)&track.popularity, sizeof(track.popularity));
    file.read((char*)&track.duration, sizeof(track.duration));
    file.read((char*)&track.explicitt, sizeof(track.explicitt));
    file.read(track.artist, sizeof(track.artist));
    file.read(track.idArtist, sizeof(track.idArtist));
    file.read(track.releaseDate, sizeof(track.releaseDate));
    file.read((char*)&track.danceability, sizeof(track.danceability));
    file.read((char*)&track.energy, sizeof(track.energy));
    file.read((char*)&track.key, sizeof(track.key));
    file.read((char*)&track.loudness, sizeof(track.loudness));
    file.read((char*)&track.mode, sizeof(track.mode));
    file.read((char*)&track.speechiness, sizeof(track.speechiness));
    file.read((char*)&track.acousticness, sizeof(track.acousticness));
    file.read((char*)&track.instrumentalness, sizeof(track.instrumentalness));
    file.read((char*)&track.liveness, sizeof(track.liveness));
    file.read((char*)&track.valence, sizeof(track.valence));
    file.read((char*)&track.tempo, sizeof(track.tempo));
    file.read((char*)&track.timeSignature, sizeof(track.timeSignature));
}

void Imprime_Track(Track &track){
    cout << "Id: " << track.id << endl;
    cout << "Name: " << track.name << endl;
    cout << "Popularity: " << track.popularity << endl;
    cout << "Duration: " << track.duration << endl;
    cout << "Explicit: " << track.explicitt << endl;
    cout << "Artist: " << track.artist << endl;
    cout << "Id artist: " << track.idArtist << endl;
    cout << "Release date: " << track.releaseDate << endl;
    cout << "Danceability: " << track.danceability << endl;
    cout << "Energy: " << track.energy << endl;
    cout << "Key: " << track.key << endl;
    cout << "Loudness: " << track.loudness << endl;
    cout << "Mode: " << track.mode << endl;
    cout << "Speechiness: " << track.speechiness << endl;
    cout << "Acousticness: " << track.acousticness << endl;
    cout << "Instrumentalness: " << track.instrumentalness << endl;
    cout << "Liveness: " << track.liveness << endl;
    cout << "Valence: " << track.valence << endl;
    cout << "Tempo: " << track.tempo << endl;
    cout << "Time signature: " << track.timeSignature << endl;
}

int main(){

    fstream srcFile;
    srcFile.open("tracks.csv");
    Track track;

    if(srcFile.is_open()){
        string temp;
        getline(srcFile,temp,',');
        strcpy(track.id, temp.c_str());

        getline(srcFile,temp,',');
        strcpy(track.name, temp.c_str());

        getline(srcFile,temp,',');
        track.popularity = atoi(temp.c_str());

        getline(srcFile,temp,',');
        track.duration = atoi(temp.c_str());

        getline(srcFile,temp,',');
        track.explicitt = atoi(temp.c_str());

        getline(srcFile,temp,',');
        strcpy(track.artist, temp.c_str());

        getline(srcFile,temp,',');
        strcpy(track.idArtist, temp.c_str());
    
        getline(srcFile,temp,',');
        strcpy(track.releaseDate, temp.c_str());

        getline(srcFile,temp,',');
        track.danceability = atof(temp.c_str());

        getline(srcFile,temp,',');
        track.energy = atof(temp.c_str());
    
        getline(srcFile,temp,',');
        track.key = atoi(temp.c_str());
    
        getline(srcFile,temp,',');
        track.loudness = atof(temp.c_str());
    
        getline(srcFile,temp,',');
        track.mode = atoi(temp.c_str());

        getline(srcFile,temp,',');
        track.speechiness = atof(temp.c_str());
    
        getline(srcFile,temp,',');
        track.acousticness = atof(temp.c_str());
    
        getline(srcFile,temp,',');
        track.instrumentalness = atof(temp.c_str());
    
        getline(srcFile,temp,',');
        track.liveness = atof(temp.c_str());
    
        getline(srcFile,temp,',');
        track.valence = atof(temp.c_str());
    
        getline(srcFile,temp,',');
        track.tempo = atof(temp.c_str());
    
        getline(srcFile,temp,'\n');
        track.timeSignature = atoi(temp.c_str());

        srcFile.close();
        cout << "Leitura de track: " << endl;
        Imprime_Track(track);
        cout << endl;
    }

    else{
        cout << "Erro ao abrir o arquivo";
        exit(1);
    }

    fstream binFile;
    binFile.open("tracks.bin", ios::in | ios::binary);
    if(binFile.is_open()){
        Track trackT;
        Track_Read(track,binFile);
        Imprime_Track(trackT);
        cout << "Leitura de track depois do bin: " << endl;
        binFile.close();
    }
    else{
        cout << "Erro ao abrir arquivo bin";
        exit(2);
    }

    return 0;
}