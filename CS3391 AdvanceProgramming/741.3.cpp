#include <iostream>
#include <string>
#include <vector>
using namespace std;

int nOfRow;
int nOfCol;
int **a;

int *nextStep;
int minCost;


void print()
{
	for (int r = 0; r < nOfRow; r++)
	{
		for (int c = 0; c < nOfCol; c++)
		{
			cout << a[r][c] << " ";
		}
		cout << endl;
	}
}

int calculateCost() {

	int cost = 0;

	for (int i = 0; i < nOfRow;i++) {
		for (int j = 0;j < nOfCol; j++) {
			if (a[i][j] == 0) {
				cost++;
			}
		}
	}

	//if (cost > (nOfRow * nOfCol) / 2) {
	//	cost = nOfRow * nOfCol - cost;
	//}

	if (cost < minCost) {
		minCost = cost;
	}
	return cost;
}



void flipRow(int row)
{

	for (int i = 0; i < nOfCol; i++)
	{
		a[row][i] = a[row][i] ? 0 : 1;
	}
}
void flipCol(int col)
{
	for (int i = 0; i < nOfRow; i++)
	{
		a[i][col] = a[i][col] ? 0 : 1;
	}
}

void flip(int i) {
	if (i != -1) {
		if (i < nOfRow) {
			flipRow(i);
		}
		else {
			flipCol(i - nOfRow);
		}
	}
	//cout << i  <<endl;
	
}

class Node {
	int index;

	int cost;

	vector<Node*> childs;
	Node *parent;

public:
	//static Node *minNode;

	Node(int index, Node*parent ):index(index),parent(parent) {
		Node * s;
		s = parent;
		vector<int> temp;
		flip(index);
		while ( s != nullptr) {
			temp.push_back(s->getIndex());
			flip(s->getIndex());
			s = s->getParent();
		}
		cost = calculateCost();
		//cout << endl;
		//print();
		//cout << "cost : " << cost << endl;

		for (int i = 0; i < temp.size(); i++) {
			flip(temp[i]);
		}
		flip(index);
		//cout << endl;

	}

	int getIndex() {
		return index;
	}

	Node * getParent() {
		return parent;
	}

	int getCost() {
		return cost;
	}

	void findNode() {
		int childI =0;
		Node *temp;
		while ( childI < nOfRow + nOfCol) {
			temp = new Node(childI, this);
			if (temp->getCost() < cost) {
				if (childs.size() > 0) {
					childs.push_back(temp);

					/*else if (temp->getCost() == ) {
						childs.push_back(temp);
					}*/
				}
				else {
					childs.push_back(temp);
				}
			}
			childI++;
		}
	}
	vector<Node*> getChilds() {
		return childs;
	}

};


int main()
{
	while (cin >> nOfRow >> nOfCol)
	{
		a = new int *[nOfRow];

		minCost = 100 * 10 + 1; // maximum cost possible

		string s;
		for (int r = 0; r < nOfRow; r++)
		{
			a[r] = new int[nOfCol];
			cin >> s;
			for (unsigned int c = 0; c < nOfCol; c++)
			{
				a[r][c] = s[c] - 48;
			}
		}

		Node * start = new Node(-1,nullptr);

		/*for (int i = 0; i < start->getChilds().size(); i++) {
			cout << start->getChilds()[i]->getCost() << endl;
			start->getChilds()[i]->findNode();
			for (int j = 0; j < start->getChilds()[i]->getChilds().size(); j++) {
				cout << start->getChilds()[i]->getChilds()[j]->getCost() << endl;
			}
		}*/

		int x = 0;
		vector<Node*> stack;
		stack.push_back(start);
		Node *curr;
		while (x++ < 80 && stack.size()) {
			curr = stack[0];
			stack.erase(stack.begin());
			curr->findNode();
			for (int i = 0; i < curr->getChilds().size(); i ++) {
				stack.push_back(curr->getChilds()[i]);
			}
			//cout << '[';
			//for (int i = 0; i < stack.size(); i++) {
			//	cout << stack[i]<<",";
			//}
			//cout << ']' << endl;
		}

		/*cout << endl;
		print();*/

		/*int total = 0;

		for (int i = 0; i < nOfRow; i++)
		{
			for (int j = 0; j < nOfCol; j++)
			{
				total += a[i][j];
			}
		}*/
		cout << nOfRow*nOfCol - minCost<< endl;
	}

	return 0;
}