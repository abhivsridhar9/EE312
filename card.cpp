//card.cpp
#include "card.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

	Card::Card()
	{
		myRank = 1;
		mySuit = spades;
	}
        Card::Card(int rank, Suit s)
        {
		myRank = rank;
		mySuit = s;
        }
        string Card::toString() const
        {
		string output;
		output = rankString(myRank) + suitString(mySuit);
		return output; 
	}
        bool Card::sameSuitAs(const Card& c) const
        {
		if(mySuit == c.mySuit){
			return true;
		}
		else{
			return false;
		}
        }
        int Card::getRank() const
        {
		return myRank;
        }
        string Card::suitString(Suit s) const
        {
		string output;
		switch(s)
                {
                        case spades:
                        {
                                output = "S";
                                return output;
                        }
                        case hearts:
                        {
                                output = "H";
                                return output;
                        }
                        case diamonds:
                        {       
                                output = "D";
                                return output;
                        }
                        case clubs:
                        {
                                output = "C";
                                return output;
                        }

                }

        }
        string Card::rankString(int r) const
        {
		string output;
		switch(myRank)
                {
                        case 1:
                        {
                                output = "A";
                                return output;
                        }

                        case 11:
                        {
                                output = "J";
                                return output;
                        }


                        case 12:
                        {
                                output = "Q";
                                return output;
                        }

         
                        case 13:
                        {
                                output = "K" + output;
                                return output;
                        }
			default:
                        {
                                output = to_string(myRank);
                                return output;
                        }
		}


        }
        bool Card::operator==(const Card& rhs) const
        {
		if((myRank == rhs.myRank) && (mySuit == rhs.mySuit))
		{
			return true;
		}
		else{
			return false;
		}
        }
        bool Card::operator!=(const Card& rhs) const
        {
		if((myRank == rhs.myRank) && (mySuit == rhs.mySuit))
                {
                        return false;
                }
                else{
                        return true;
                }

        }
	Card& Card::operator=(const Card& rhs){
		myRank = rhs.myRank;
		mySuit = rhs.mySuit;
		return *this;
	}
        ostream& operator << (ostream& out, const Card& c)
        {
		out << c.toString();
		return out;
        }




