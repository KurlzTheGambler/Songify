#ifndef SONGIFY_H
#define SONGIFY_H

#include <iostream>
#include <string>
#include "defs.h"
#include "AlbumArray.h"




class Songify{


    public:
        //constructor
        Songify();
        //destructor
        ~Songify();
        //add and remove
        bool addAlbum(const string& Artist, const string& albumtitle);
        bool addSong(const string& albumtitle , Song song);
        bool removeAlbum(const string& Artist, const string& albumtitle);
        bool removeSong(const string& Artist, const string& albumtitle, const string& songtitle);
        //Client services
        bool downloadAlbum(const string& artist, const string& albumtitle, Album** alb);
        bool streamSong(const string& artist, const string& albumtitle, const string& songtitle, Song** song);
        //print
        void printAlbums();
        void printSongs();
    private:
    AlbumArray * AlbArrs;

};




#endif