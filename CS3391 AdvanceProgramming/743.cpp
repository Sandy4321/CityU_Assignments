#include <iostream>
#include <string>
using namespace std;

class Node
{
  public:
	Node(char c, int index) : c(c), index(index) {prev=nullptr}
	void setPrev(Node *prev)
	{
		Node::prev = prev;
	}
	Node *getPrev()
	{
		return prev;
	}
	char getChar()
	{
		return c;
	}
	int getIndex()
	{
		return index;
	}

  private:
	Node *prev;
	char c;
	int index;
};

class Stack
{
  public:
	Stack(char first, int index)
	{
		curr = new Node(first, index);
		curr->setPrev(nullptr);
	}
	void push(char newChar, int index)
	{
		Node *n = new Node(newChar, index);
		n->setPrev(curr);
		curr = n;
	}
	char pop()
	{
		char c = curr->getChar();
		Node *n = curr;
		curr = curr->getPrev();
		delete n;
		return c;
	}
	int lastIndex()
	{
		if (curr == nullptr)
		{
			return -1;
		}
		else
		{
			int index;
			while (curr != nullptr)
			{
				index = curr->getIndex();
				curr = curr->getPrev();
			}
			return index;
		}
	}

  private:
	Node *curr;
};

int main()
{

	string s;
	Stack *st;
	bool notEnd;
	int i;
	while (getline(cin,s))
	{
		st = new Stack(s[0], 0);
		notEnd = true;
		for (i = 1; i < s.length() && notEnd; i++)
		{
			switch (s[i])
			{
			case '{':
			case '[':
			case '(':
				st->push(s[i], i);
				break;
			case '}':
				if (st->pop() != '{')
				{
					cout << i+1 << endl;
					notEnd = false;
				}
				break;
			case ']':
				if (st->pop() != '[')
				{
					cout << i+1 << endl;
					notEnd = false;
				}
				break;
			case ')':
				if (st->pop() != '(')
				{
					cout << i+1 << endl;
					notEnd = false;
				}
				break;
			}
		}
		if (notEnd) // read all the characters
		{
			int tempIndex = st->lastIndex(); // check if stack is empty
			if (tempIndex == -1) // stack is empty
			{
				cout << "Success" << endl;
			}
			else //  stack is not empty
			{
				cout << tempIndex+1 << endl;
			}
		}
	}

	return 0;
}

/*
}
*/