#include "SongArray.h"

SongArray::SongArray(){
	numSongs = 0;
	Songs = new Song*[MAX_ARRAY];

	
}


SongArray::~SongArray(){
	for(int i=0;i<numSongs;i++){
		delete Songs[i];
	}
	delete[] Songs;
}


bool SongArray::add(Song* s){
	//if (numSongs >= MAX_ARRAY) return false;
	Songs[numSongs] = s;
	numSongs++;
	return true;
}

bool SongArray::add(int i , Song* s){
    if (numSongs >= MAX_ARRAY) return false;
	if(i>=MAX_ARRAY || i < 0) return false;
	
	int temp = numSongs;

	while(temp>i){

		Songs[temp] = Songs[temp-1]; temp--;
	} 

    Songs[i] = s;
	numSongs += 1;

    return true;
}



bool SongArray::get(const string& artist, const string& title, Song** song){
    if (numSongs > MAX_ARRAY) return false;
    for(int i=0; i < numSongs; ++i){
        if(Songs[i]->getArtist()==artist && Songs[i]->getTitle()==title){
            *song = Songs[i];
            return true;
        }
    }
    return false;
}


bool SongArray::get(int i , Song** s){
    if (numSongs >= MAX_ARRAY) return false;
    if (i >= numSongs || i < 0) return false;
    *s = Songs[i];
    return true;

}


bool SongArray::remove(const string& artist, const string& title,Song** song){
    int i = 0;
	while(i < numSongs && (title != Songs[i]->getTitle()&& artist != Songs[i]->getArtist())){
		++i;
	}
	if(i==numSongs){return false;}
	*song = Songs[i];
	while(i < numSongs-1){
		Songs[i] = Songs[i+1];
		++i;
	}
	--numSongs;
	return true;
}

bool SongArray::remove(int i , Song** song){
    if (i >= numSongs|| i <0) return false;
	if(i>= MAX_ARRAY) return false;

    *song = Songs[i];
    while (i < numSongs - 1){
        Songs[i] = Songs[i + 1];
        ++i;
    }
    --numSongs;
    return true;

}



bool SongArray::isFull(){
	return numSongs >= MAX_ARRAY;
}

int SongArray::size(){
	return numSongs;
}

void SongArray::print(){
	for (int i = 0; i < numSongs; ++i){
		Songs[i]->print();
	}
}


