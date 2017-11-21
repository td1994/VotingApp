#include "Item.h"

#include <iostream>
#include <fstream>
#include <string>

using std::ifstream;
using std::string;
using std::getline;
using std::cout;

int main()
{
	int voteValue = 0;
	int count = 0;
	string name = "";
	Item games[100];
	ifstream in("votes.txt");
	in >> voteValue;
	in.ignore(200, '\t');
	getline(in, name, '\n');
	while(!in.fail())
	{
		bool exists = false;
		for(int i = 0; i < count && !exists; i++)
		{
			if(name == games[i].getName())
			{
				games[i].addVotes(voteValue);
				exists = true;
			}
		}
		if(!exists)
		{
			games[count].setName(name);
			games[count].addVotes(voteValue);
			count++;
		}
		in >> voteValue;
		in.ignore(200, '\t');
		getline(in, name, '\n');
	}

	for(int i = 0; i < count - 1; i++)
	{
		for(int j = 0; j < count - i - 1; j++)
		{
			if(games[j].getVotes() < games[j + 1].getVotes())
			{
				Item temp = games[j + 1];
				games[j + 1] = games[j];
				games[j] = temp;
			}
			else if(games[j].getVotes() == games[j + 1].getVotes())
			{
				if(games[j].getCount() < games[j + 1].getVotes())
				{
					Item temp = games[j + 1];
					games[j + 1] = games[j];
					games[j] = temp;
				}
				else if(games[j].getCount() == games[j + 1].getVotes())
				{
					if(games[j].getAverage() > games[j + 1].getAverage())
					{
						Item temp = games[j + 1];
						games[j + 1] = games[j];
						games[j] = temp;
					}
				}
			}
		}
	}

	cout << "Rank\tTitle\t\t\tPoints" << std::endl;
	for(int i = 0; i < count; i++)
	{
		cout << i + 1 << "\t" << games[i].getName() << '\t' << games[i].getVotes() << std::endl;
	}

}
