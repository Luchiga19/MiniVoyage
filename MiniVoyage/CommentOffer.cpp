#include "CommentOffer.h"
#include "Category.h"
#include <memory>
#include <vector>
#include <string>
#include <iostream>

using namespace std;


CommentOffer::CommentOffer(Offer& offer) {
	this->offerId = offer.getId();
}


void CommentOffer::addComment(std::string comment)  {
	
}


void CommentOffer::removeComment() {

}


