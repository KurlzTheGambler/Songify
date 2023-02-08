#include "Client.h"




Client::Client(){
    
    albumarr = new AlbumArray();
}

Client::~Client(){

    Album* alb;
    while(albumarr->size()>0){
        if(albumarr->remove(0,&alb)){
            delete alb;
            
        }
    }
    delete albumarr;

}

bool Client::download(Songify* sfy, const string& artist, const string& albumtitle){
    Album* ptr;

    if(sfy->downloadAlbum(artist, albumtitle, &ptr)){
        Album* heapcopy = new Album(*ptr);
        if(albumarr->add(heapcopy)){
            return true;
        }
        else{
            delete heapcopy;
        }
    }
    
    cout<<"Cannot download."<<endl;
    return false;

}


bool Client::stream(Songify* sfy, const string& artist, const string& albumtitle, const string& songtitle){
    Song* s;
    if(sfy->streamSong(artist, albumtitle, songtitle,&s)){
        s->play();
        return true;
    }
    cout<<"Cannot stream";
    return false;
}

bool Client::playLocal(const string& artist, const string& albumtitle, const string& songtitle){
    Album* alb;
    Song* s;
    if(albumarr->get(artist, albumtitle,&alb)){
        if(alb->getSong(songtitle,&s)){
            s->play();
            return true;
        }

    }
    cout<<"Cannot Play."<<endl;
    return false;

}


void Client::printAlbums(){

    Album* alb;

    for(int i=0; i <= albumarr->size(); i++){
        if(albumarr->get(i, &alb)){
            alb->printShort();
        }
    }


}




void Client::printSongs(){


    Album* alb;

    for(int i=0; i <= albumarr->size(); i++){
        if(albumarr->get(i, &alb)){
            alb->print();
        }
    }


}