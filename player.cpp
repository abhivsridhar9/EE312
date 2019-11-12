//player.cpp
#include "player.h"
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
	Player::Player()
	{
		srand((unsigned)time(0));
	}
        void Player:: addCard(Card c)
        {
		myHand.push_back(c);
        }
        void Player:: bookCards(Card c1, Card c2)
        {
		myBook.push_back(c1);
		myBook.push_back(c2);
		for(int i = 0; i < myHand.size(); i++){
			if(myHand[i] == c1){
				
				myHand.erase(myHand.begin()+i);
			}
			if(myHand[i] == c2){

                                myHand.erase(myHand.begin()+i);
                        }


		}
        }
        bool Player::checkHandForBook(Card &c1, Card &c2)
        {
		for(int i = 0; i < myHand.size(); i++){
		
			for(int j = 0; j < myHand.size(); j++){
				if(i != j){
					if(myHand[i].getRank() == myHand[j].getRank()){
						c1 = myHand[i];
						c2 = myHand[j];
						return true;
					}
				}
			}
		}
		return false;
        }
        Card Player::rankInHand(Card c) const
        {
		for(int i = 0; i < myHand.size(); i++){
			if(myHand[i].getRank() == c.getRank()){
				return myHand[i];
			}
		}
		return c; 
        }
        Card Player::chooseCardFromHand() const
        {
		int num = (rand() % (myHand.size()));
		Card temp = myHand[num];
		//oFile << myName << " asks - Do you have a " << temp.rankString(temp.getRank()) << endl;
		return temp;
        }
	//void Player::drawCard()
	//{
	//	Card dealt = d.dealCard();
	//	addcard(dealt);
		//oFile << myName << " draws a " << dealt << endl;
	//}
        bool Player::cardInHand(Card c) const
        {
		
		for(int i = 0; i < myHand.size(); i++){
			
			if(myHand[i].getRank() == c.getRank()){
				//oFile << myName<< " says - Yes. I have a "<< c.rankString(c.getRank())<< endl;
				
				return true;
			}
			
		
		}
		//oFile<<myName<<" says - Go Fish"<<endl;
		return false;
        }
        Card Player::removeCardFromHand(Card c)
        {
		for(int i = 0; i < myHand.size(); i++){
			if(myHand[i] == c){
				myHand.erase(myHand.begin()+i);
			}
		}
		return c;
        }
        string Player::showHand() const
        {
		string temp;
		for(int i = 0; i <myHand.size(); i++){
                        temp+=myHand[i].toString()+" ";
                }
		return temp;
		
        }
        string Player::showBooks() const
        {
		string temp;
                for(int i = 0; i <myHand.size(); i++){
                        temp+=myBook[i].toString()+" ";
               }
		return temp;

        }
        int Player::getHandSize() const
        {
		return myHand.size();
        }
        int Player::getBookSize() const
        {
		return myBook.size();
        }
        bool Player::sameRankInHand(Card c) const
        {

        }

