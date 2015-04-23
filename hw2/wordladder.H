//  =============== BEGIN ASSESSMENT HEADER ================
/// Joshua Lai
/// 861163421
/// 22 April 2015
//  ================== END ASSESSMENT HEADER ===============
#ifndef WORDLADDER_H
#define WORDLADDER_H
#include <list>
#include <stack>
#include <queue>
#include <iostream>
#include <fstream>

using namespace std;

class WordLadder {
	private:
		list<string> diction;
		bool sCompare(const string first, const string second)
		{
			int count = 0;
			for(int i = 0; i < 5; i++)
			{
				if(first.at(i) != second.at(i))
					count++;
			}
			if(count == 1)
				return true;
			else
				return false;
		}
	public:
		WordLadder(const string listFile)
		{
			fstream inF;
			string word;
			
			inF.open(listFile.c_str());
			if(!inF.is_open())
				cout << "Error opening file." << endl;
			
			while(inF.good())
			{
				inF >> word;
				diction.push_back(word);
			}
		}
		void outputLadder(const string start, const string end)
		{
			stack<string> first;
			first.push(start);
			queue<stack<string> > chain;
			chain.push(first);
			
			while(!chain.empty())
			{
				for(list<string>::iterator it = diction.begin(); it != diction.end(); it++)
				{
					if(sCompare(*it, chain.front().top()))
					{
						if((*it).compare(end) == 0)
						{
							stack<string> print;
							print.push(*it);
							while(!chain.front().empty())
							{
								print.push(chain.front().top());
								chain.front().pop();
							}
							while(!print.empty())
							{
								cout << print.top() << ' ';
								print.pop();
							}
							
							return;
						}
						stack<string> copy(chain.front());
						copy.push(*it);
						chain.push(copy);
					}
				}
				chain.pop();
			}
			cout << "There is no word ladder from \"" << start 
			<< "\" to \"" << end << "\".\n";

		}
};

#endif