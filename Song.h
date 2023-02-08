#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>
#include "defs.h"

using namespace std;

class Song{
  public:
    //constructors
    Song();

    Song(const Song& song);

    ~Song();

    Song(const string& artist, const string& title, const string& content);

    //getters
     string getArtist();
     string getTitle();
     string getContent();


     //function

     bool matches(const string& artist , const string& title);

    //other
    void print();
    void play();
  private:
     string artist;
     string title;
     string content;
};
#endif