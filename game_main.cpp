// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides oFile and cin
#include <cstdlib>    
#include <fstream>
 // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main( )
{
	ofstream oFile;
	oFile.open("gofish_results.txt");
	int numCards = 7;
    
	Player p1("Joe");
	Player p2("Jane");
    
	Deck d;
	//create a deck of cards
	d.shuffle();
	dealHand(d, p1, numCards);
	dealHand(d, p2, numCards);
	oFile << p1.getName() <<" has : " << p1.showHand() << endl;
        oFile << p2.getName() <<" has : " << p2.showHand() << endl;
	//STEP 1: CHECK BOTH PLAYERS FOR BOOKS 
	Card book1;
	Card book2;
	bool checkbook = p1.checkHandForBook(book1, book2);
	//oFile << checkbook << endl;
	if(checkbook){
		oFile << "Booked Cards" << endl;
		p1.bookCards(book1, book2);
		oFile << book1 << " " << book2 << endl;
	}
	checkbook = p2.checkHandForBook(book1, book2);
        if(checkbook){
		oFile << "Booked Cards" << endl;
                p2.bookCards(book1, book2);
		oFile << book1 << " " << book2 << endl;
        }


	oFile << p1.getName() <<" has : " << p1.showHand() << endl;
	oFile << p2.getName() <<" has : " << p2.showHand() << endl;
	

	while(d.size() > 0){
		//oFile << d.size() << " size" << endl;
		oFile << p1.getName() <<" has : " << p1.showHand() << endl;
        	oFile << p2.getName() <<" has : " << p2.showHand() << endl;

		//STEP 2: PLAYER 1 ASKS 
		//Card c1 = p1.chooseCardFromHand();
	

		//STEP 3: CHECK TO SEE IF PLAYER 2 HAS CARD
		bool check2;
		Card c1;
		if(p1.getHandSize() == 0){
			check2 = false;
		}else{
			c1 = p1.chooseCardFromHand();
			oFile << p1.getName() << " asks - Do you have a " << c1.rankString(c1.getRank()) << endl;
			check2 = p2.cardInHand(c1);

		}
		while(check2){
			//YES, give card to player
			oFile << p2.getName() << " says - Yes. I have a " << c1.rankString(c1.getRank()) << endl;
			Card remove = p2.rankInHand(c1);
			remove = p2.removeCardFromHand(remove);
			p1.addCard(remove);
			checkbook = p1.checkHandForBook(book1, book2);
                        if(checkbook){
                                oFile << "Booked Cards" << endl;
                                p1.bookCards(book1, book2);
                                oFile << book1 << " " << book2 << endl;
                                oFile << p1.getName() <<" has : " << p1.showHand() << endl;
                                oFile << p2.getName() <<" has : " << p2.showHand() << endl;

                        }
			if(p1.getHandSize() == 0){
                        	check2 = false;
                	}else{
                        	c1 = p1.chooseCardFromHand();
				oFile << p1.getName() << " asks - Do you have a " << c1.rankString(c1.getRank()) << endl;
                        	check2 = p2.cardInHand(c1);
                	}


		}
			//No, GO FISH
			oFile << p2.getName() << " says No - Go Fish ! " << endl;
			Card draw;
			if(d.size() != 0){
                                draw = d.dealCard();
                                p1.addCard(draw);
                        }

        		checkbook = p1.checkHandForBook(book1, book2);
        		if(checkbook){
                		oFile << "Booked Cards" << endl;
                		p1.bookCards(book1, book2);
				oFile << book1 << " " << book2 << endl;
               			oFile << p1.getName() <<" has : " << p1.showHand() << endl;
                		oFile << p2.getName() <<" has : " << p2.showHand() << endl;
			
			}
        	

		//PLAYER 2 ASKS 
		Card c2;
		bool check1;
		if(p2.getHandSize() == 0){
                        check1 = false;
                }else{
                        c2 = p2.chooseCardFromHand();
                        oFile << p2.getName() << " asks - Do you have a " << c2.rankString(c2.getRank()) << endl;
			check1 = p1.cardInHand(c2);
                }

		while(check1){
			 //YES, give card to player
        	        oFile << p1.getName() << " says - Yes. I have a " << c2.rankString(c2.getRank()) << endl;
        	        Card remove = p1.rankInHand(c2);
        	        remove = p1.removeCardFromHand(remove);
        	        p2.addCard(remove);
			checkbook = p2.checkHandForBook(book1, book2);
                        if(checkbook){
                                oFile << "Booked Cards" << endl;
                                p2.bookCards(book1, book2);
                                oFile << book1 << " " << book2 << endl;
                                oFile << p1.getName() <<" has : " << p1.showHand() << endl;
                                oFile << p2.getName() <<" has : " << p2.showHand() << endl;

                        }
			if(p2.getHandSize() == 0){
                        	check1 = false;
        		}else{
                        	c2 = p2.chooseCardFromHand();
                       		oFile << p2.getName() << " asks - Do you have a " << c2.rankString(c2.getRank()) << endl;
                       		check1 = p1.cardInHand(c2);

                	}

		}
			//No, GO FISH 
			oFile << p1.getName() << " says No - Go Fish ! " << endl;
			if(d.size() != 0){
        	        	draw = d.dealCard();
        	        	p2.addCard(draw);
			}
		//CHECK FOR BOOKING
			checkbook = p2.checkHandForBook(book1, book2);
			if(checkbook){
                        	oFile << "Booked Cards" << endl;
                        	p2.bookCards(book1, book2);
				oFile << book1 << " " << book2 << endl;
                         	oFile << p1.getName() <<" has : " << p1.showHand() << endl;
                		oFile << p2.getName() <<" has : " << p2.showHand() << endl;

			}

		

	}
	//count num books for each and return winner	
	int numpair1 = p1.getBookSize()/2;
	int numpair2 = p2.getBookSize()/2;
	if(numpair1 > numpair2){
		oFile << p1.getName() << " is the Winner with " << numpair1 << " pairs" << endl;
		oFile << p2.getName() << " is the Loser with " << numpair2 << " pairs" << endl;
	}
	if(numpair2 > numpair1){
		oFile << p2.getName() << " is the Winner with " << numpair2 << " pairs" << endl;
		oFile << p1.getName() << " is the Loser with " << numpair1 << " pairs" << endl;
	}
	if(numpair2 == numpair1){
                oFile << p2.getName() << " is the Winner with " << numpair2 << " pairs" << endl;
                oFile << p1.getName() << " is the Winner with " << numpair1 << " pairs" << endl;
        }
	oFile.close();
	return EXIT_SUCCESS;  
}



void dealHand(Deck &d, Player &p, int numCards)
{
   	for (int i=0; i < numCards; i++)
		p.addCard(d.dealCard());
}
