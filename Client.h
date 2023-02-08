#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>


#include "Songify.h"


class Client{



    public:
    //constructor
    Client();
    //destructor
    ~Client();

    bool download(Songify* sfy, const string& artist, const string& albumtitle);
    bool stream(Songify* sfy, const string& artist, const string& albumtitle, const string& songtitle);
    bool playLocal(const string& artist, const string& albumtitle, const string& songtitle);
    void printAlbums();
    void printSongs();


    private:

    AlbumArray* albumarr;





};
#endif