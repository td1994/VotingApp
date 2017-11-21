#ifndef ITEM_H
#define ITEM_H

#include <string>
using std::string;

class Item
{
private:
	int count;
	int ranks;
	string name;
	int votes;
public:
	Item();
	Item(string name);
	string getName();
	int getVotes();
	int getCount();
	double getAverage();
	void addVotes(int voteValue);
	void setName(string name);
	void resetVotes();
};

#endif