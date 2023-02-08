#include "Album.h"



Album::Album(string artist, string title ){
    this->title = title;
    this->artist = artist;
    songarr = new SongArray();
}


Album::Album(Album& alb): artist(alb.artist), title(alb.title){ 
    songarr = new SongArray();
        Song * s;
    for(int index=0;index<alb.songarr->size();index++){
        if(alb.songarr->get(index,&s)){
            Song* Scopy = new Song(s->getArtist(),s->getTitle(),s->getContent());
            songarr->add(Scopy);

        }
        
    }
}

Album::~Album(){
    delete songarr;
}


const string& Album::getTitle(){return title;}
const string& Album::getArtist(){return artist;}

bool Album::matches(string artist , string title){
        if(this-> artist == artist && this-> title == title){
        return true;
    }
    return false;
}


bool Album::lessThan(Album& alb){
    if(this->artist.compare(alb.artist)<0){
        return true;
    }
    if(this->artist.compare(alb.artist)==0){
        if(this->title.compare(alb.title)<0){
            return true;
        }
    }
    return false;
}


bool Album::addSong(Song*song){
    if(song->getArtist()==artist){
        if(songarr->add(song)){
            return true;
        }
        
    }
    return false;

}
bool Album::addSong(int index, Song* song){
    if(song->getArtist()==artist){
        if(songarr->add(index , song)){
            return true;
        }
        
    }
    return false;

}


bool Album::getSong(string title, Song** song){
    return songarr->get(artist,title,song);

}


bool Album::getSong(int index, Song** song){
    if(index<0||index>=MAX_ARRAY) return false;
    return songarr->get(index,song);
}


bool Album::removeSong(string title, Song** song){
    return songarr -> remove(artist, title, song);

}

bool Album::removeSong(int index, Song** song){
    if(index<0||index>=MAX_ARRAY) return false;
    return songarr->remove(index, song);
}


void Album::print(){

    cout<<"Album Artist: "<<artist<<"Album Title: "<<title<<endl;
    songarr->print();


}

void Album::printShort(){

    cout<<"Album Artitst name: "<<artist<<"Album Title: "<<title<<endl;

}
