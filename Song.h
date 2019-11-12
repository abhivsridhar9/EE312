#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>

using namespace std;

class Song {

private:
	string title;
	string artist;
	int size;

	

public:
	Song(int _size);
	Song(string _title, string _artist, int _size);


	string getTitle() const;
	
	void setTitle(string _title);

	string getArtist() const;

	void setArtist(string _artist);

	int getSize() const;

	void setSize(int _size);

	bool operator>(Song const &rhs);
	bool operator <(Song const &rhs); 
    bool operator ==(Song const &rhs);


    ~Song();


}


#endif