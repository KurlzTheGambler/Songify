#include "AlbumArray.h"



AlbumArray::AlbumArray(){
	numAlbs = 0;
	albums = new Album*[MAX_ARRAY];

}

AlbumArray::~AlbumArray(){

	delete[] albums;

}


bool AlbumArray::add(Album* alb){
    if (numAlbs >= MAX_ARRAY) return false;

    int index = 0;
    //finds the right index for album
    while (index < numAlbs){
        if(alb->lessThan(*albums[index])){
            break;
        }
        ++index;
    }

    if(index>=MAX_ARRAY|| index<0) return false;

    for (int i = numAlbs; i > index; --i){
        albums[i] = albums[i-1];
    }

    albums[index] = alb;

    ++ numAlbs;
	 return true;
}



bool AlbumArray::get(const string& artist, const string& title, Album** alb){
    for(int i=0; i < numAlbs; ++i){
        if(albums[i]->getArtist()==artist && albums[i]->getTitle()==title){
            *alb = albums[i];
            return true;
        }
    }
    return false;

}


bool AlbumArray::get(int index, Album** alb){
    if (index < 0 || index >= numAlbs) return false;
    *alb = albums[index];
    return true;

}


bool AlbumArray::remove(const string& artist, const string& title,Album** alb){
    int i = 0;
	while(i < numAlbs && (title != albums[i]->getTitle()&& artist != albums[i]->getArtist())){
		++i;
	}
	if(i>=numAlbs){return false;}
	*alb = albums[i];
	while(i < numAlbs-1){
		albums[i] = albums[i+1];
		++i;
	}
	--numAlbs;
	return true;

}
bool AlbumArray::remove(int index, Album** alb){

    if (index >= numAlbs||index<0) return false;

    *alb = albums[index];
    while (index < numAlbs - 1){
        albums[index] = albums[index + 1];
        ++index;
    }
    --numAlbs;
    return true;

}

int AlbumArray::size(){
    return numAlbs;

}

bool AlbumArray::isFull(){
    return numAlbs >= MAX_ARRAY;

}

void AlbumArray::printShort(){

    for (int i = 0; i < numAlbs; ++i){
    albums[i]->printShort();
}


}