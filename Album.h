#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include <string>
#include "defs.h"
#include "SongArray.h"


using namespace std;


class Album{
    public:

        Album(string, string);
        Album(Album&);
        ~Album();
        //getters
        const string& getTitle();
        const string& getArtist();
        //other

        bool matches(string artist, string title);
        bool addSong(Song* Song);
        bool addSong(int index , Song* song);
        bool getSong(string title, Song** song);
        bool getSong(int index, Song** song);
        bool lessThan(Album& alb);
        bool removeSong(string title, Song** song);
        bool removeSong(int index, Song** song);

        void print();
        void printShort();

    private:

        string title;
        string artist;
        SongArray *songarr;

};





#endif