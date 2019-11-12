#include "Song.h"

using namespace std;


	Song::Song(int _size)
	{
		title="";
		artist="";
		size=_size;

	}

	Song::Song(string _title, string _artist, int _size)
	{
		title=_title;
		artist=_artist;
		size=_size;
	}


	string Song::getTitle() const
	{
		return title;
	}

	void Song::setTitle(string _title)
	{
		title=_title;
	}

	string Song::getArtist() const
	{
		return artist;
	}

	void Song::setAritst(string _artist)
	{
		artist=_artist;
	}

	int Song::getSize() const
	{
		return size;
	}

	void Song::setSize(int _size)
	{
		size=_size;
	}

	bool Song::operator >(Song const &rhs)
	{
		if(title.compare(rhs.title)<=0)
			return false;

		return true;
	}

	bool Song::operator <(Song const &rhs)
	{
		if(title.compare(rhs.title)>=0)
			return false;

		return true;
	}

	bool Song::operator ==(Song const &rhs)
	{
		if(title.compare(rhs.title)!=0)
			return false;

		else if(title.compare(rhs.title)==0)
		{
			if(artist.compare(rhs.artist)!=0)
				return false;

			else if(artist.compare(rhs.artist)==0)
			{
				if(size!=rhs.size)
					return false;

				else
					return true;
			}

			
		}

	}

	Song::~Song()
	{
		cout<<"debug - in destructor for"<<title<<endl;//used to see when the destructor is called for each instance of the song class
	}


