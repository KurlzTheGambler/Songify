
#ifndef ALBUMARRAY_H
#define ALBUMARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Album.h"
#include "defs.h"

using namespace std;

class AlbumArray {

    public:

        AlbumArray();

        ~AlbumArray();


        bool add(Album* );
        bool get(const string& artist, const string& title, Album**);
        bool get(int index, Album**);
        bool remove(const string& artist, const string& title,Album**);
        bool remove(int index, Album**);

        int size();

        bool isFull();
        
        void printShort();



	private:
		
		int numAlbs;
		Album** albums;


};



#endif