#include "Item.h"

Item::Item()
{
	votes = 0;
	name = "";
}
Item::Item(string name)
{
	votes = 0; 
	this->name = name;
}

void Item::setName(string name)
{
	this->name = name;
}

string Item::getName()
{
	return name;
}

int Item::getVotes()
{
	return votes;
}

int Item::getCount()
{
	return count;
}

double Item::getAverage()
{
	return ranks / count;
}

void Item::addVotes(int voteValue)
{
	count++;
	ranks += voteValue;
	if(voteValue > 0 && voteValue <= 5)
	{
		votes += 6 - voteValue;
	}
}

void Item::resetVotes()
{
	votes = 0;
}