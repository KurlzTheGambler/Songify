
#ifndef SONGARRAY_H
#define SONGARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Song.h"
#include "defs.h"

using namespace std;

class SongArray {
		
	public:
		//constructor
		SongArray();
		
		//destructor
		~SongArray();
		
		//other

		//1.
        bool add(Song*);
            bool add(int i , Song*);
        //2.
		bool get(const string& artist, const string& title, Song** song);
            bool get(int i , Song**);
        //3.
		bool remove(const string& artist, const string& title, Song** song);
            bool remove(int i , Song**);


		int size();
		bool isFull();
		void print();
	
	private:
		
		int numSongs;
		Song** Songs;
};
#endif
