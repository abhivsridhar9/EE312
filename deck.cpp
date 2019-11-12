//deck.cpp
#include "deck.h"
#include "card.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <fstream>
using namespace std;
	Deck::Deck()
	{
		
		int rank = 1;
		for(int i = 0; i < 13; i++){
			
			Card::Suit s;
			s = Card::spades;
			Card c(rank, s);
			//Card c();
			//string s1 = c.toString()
			myCards[i] = c;
			rank++;
		}
		rank = 1;
		for(int i = 0; i < 13; i++){
			Card::Suit s;
                        s = Card::hearts;
                        Card c(rank, s);
                        myCards[i+13] = c;
			rank++;
                }
		rank = 1;
		for(int i = 0; i < 13; i++){
			Card::Suit s;
                        s = Card::diamonds;
                        Card c(rank, s);
                        myCards[i+26] = c;
			rank++;
                }
		rank = 1;
		for(int i = 0; i < 13; i++){
			Card::Suit s;
                        s = Card::clubs;
                        Card c(rank, s);
                        myCards[i+39] = c;
			rank++;
                }
		myIndex = 0;
		srand((unsigned)time(0));
	}
        void Deck::shuffle()
        {
		for(int i = 0; i < 104; i++){
			int num1 = (rand() % 52);
                	int num2 = (rand() % 52);
			Card temp1 = myCards[num1];
			Card temp2 = myCards[num2];
			myCards[num1] = temp2;
			myCards[num2] = temp1;  
		}
        }
        Card Deck::dealCard()
        {
		Card temp = myCards[myIndex];
		myIndex++;
		return temp;
        }
        int Deck::size() const
        {
		int temp = 52 - myIndex;
		return temp;
        }
	void Deck::showDeck()
	{
		for(int i = 0; i < 52; i++){
			//oFile << myCards[i] << ", " << endl;
		}
	}
