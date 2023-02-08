#include "Song.h"


Song::Song(){ 
    artist = "ali";
    title = "one";
    content = "RCMP";

}

Song::Song(const string& artist, const string& title, const string& content){
  this->artist = artist;
  this->title = title;
  this->content = content;
}

Song::Song(const Song& song){
    this -> artist = song.artist;
    this -> title = song.title;
    this -> content = "RCMP";


}


Song::~Song(){}

string Song::getArtist(){
    return artist;
}


string Song::getTitle(){
    return title;
}


string Song::getContent(){
    return content;
}



bool Song::matches(const string& artist , const string& title){
    if(this-> artist == artist && this-> title == title){
        return true;
    }
    return false;
}




void Song::print(){

    cout<<"Song Name: "<<title<<" Song artist: "<<artist<<endl;
}


void Song::play(){
    print();
    cout<<content<<endl;
}
