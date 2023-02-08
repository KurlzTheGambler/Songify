#include "Songify.h"



Songify::Songify(){

    AlbArrs = new AlbumArray();
}

Songify::~Songify(){
    Album* alb;

    while(AlbArrs->size()>0){
        if(AlbArrs->remove(0,&alb)){
            delete alb;
            
        }
    }

    delete AlbArrs;
}


bool Songify::addAlbum(const string& Artist, const string& albumtitle){
    if(AlbArrs->isFull()){
        cout<<"failed to add album"<<endl;
        return false;
    }
    Album* albumarr = new Album(Artist, albumtitle);
    if(AlbArrs->add(albumarr)){
        return true;
    }

    cout<<"failed to add album"<<endl;
    delete AlbArrs;
    return false;
}

bool Songify::removeAlbum(const string& Artist, const string& albumtitle){
    Album* alb;
    for(int i =0; i< AlbArrs->size(); i++){
        if(AlbArrs->remove(Artist, albumtitle, &alb)){
            delete alb;
            return true;
        }
    }
    cout<<"failed to remove song"<<endl;
    return false;
}

bool Songify::addSong(const string& albumtitle , Song song){
    Album* alb;
    Song* heapcpy = new Song(song.getArtist() ,song.getTitle(), song.getContent());
    if(AlbArrs->get(heapcpy->getArtist(), albumtitle, &alb)){
        if(alb->addSong(heapcpy)){
            return true;
        }
    }
    cout<<"failed to add song to album"<<endl;
    delete heapcpy;
    return false;
}


bool Songify::removeSong(const string& Artist, const string& albumtitle, const string& songtitle){
    Album* alb;
    Song* songheap;

    if(AlbArrs->get(Artist, albumtitle,&alb)){
        if(alb->getArtist() == Artist && alb->getTitle()==albumtitle){
            if(alb->removeSong(songtitle, &songheap)){

                delete songheap;
                return true;

            }
        }
    }

    cout<<"failed to remove song"<<endl;
    return false;

}
 bool Songify::downloadAlbum(const string& artist, const string& albumtitle, Album** alb){
    
    if(AlbArrs->get(artist, albumtitle,alb)){
        if((*alb)->getTitle()== albumtitle && (*alb)->getArtist() == artist){
            return true;
        }
    }
    cout<<"no such album"<<endl;
    return false;


 }

bool Songify::streamSong(const string& artist, const string& albumtitle, const string& songtitle, Song** song){
    Album* alb;

    if(AlbArrs->get(artist, albumtitle,&alb)){
        if(alb->getTitle()== albumtitle && alb->getArtist() == artist){
            if(alb->getSong(songtitle , song)){
                return true;
            }

        }
    }
    cout<<"Unable to stream song"<<endl;
    return false;

}

void Songify::printAlbums(){

    Album* alb;

    for(int i=0; i <= AlbArrs->size(); i++){
        if(AlbArrs->get(i, &alb)){
            alb->printShort();
        }
    }

}

void Songify::printSongs(){
    
    Album* alb;

    for(int i=0; i <= AlbArrs->size(); i++){
        if(AlbArrs->get(i, &alb)){
            alb->print();
        }
    }


}