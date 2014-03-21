/*
 * Created by : Rizky Agung Saputro
 * E1200267
 * Assignment 1 C++	*/
 
 #include <cstdlib>
#include <iostream>

using namespace std;

struct node{
	int num[6];
	char name[3];
	struct node *next;
};

typedef node *nodeptr;
void insert(nodeptr &head, int data[], char name[]);
nodeptr head = NULL;
int holder;

int main(){
	int i, j, spooler[6], input, *max, choice;
	max = &holder;
	char savedName[3];
	cout << "--------------------------------------------------";
	cout << "--------WELCOME TO RIZKY'S SORTING PROGRAM--------";
	cout << "--------------------------------------------------";
	cout << "1. Add New Node(s)";
	cout << "2. View Current Node(s)";
	cout << "3. Delete a Node";
	cout << "4. Edit a Node";
	cout << "How many times do you want this process to be repeated?" << '\t';
	cin >> *max;
	for (int count = 0; count < *max; count++){
		for(i = 0; i < 6; i++){
			cout << "type number no "<< (i+1) << '\t';
 			cin >> input;
			for(j = 0; j < i; j++){
				while (input == spooler[j]){
					cout << "duplicate number within this node, please input another number" << '\t';
					cin >> input;
					j=0;
				}
			}
			spooler[i] = input;
		}
		cout << "give a name for this struct" << '\t';
		cin >> savedName;
		insert (head,spooler,savedName);
		if (count != (*max)-1 )
			cout << "saved, new node below ..." << endl;
		else
			cout << "the result is as follows" << endl << endl;
	}
nodeptr temp = head;	
bool swap = true;
	int x = 0,y = 0, temporary;
	char tempName[3];
	for (i = 0; i < holder-1; i++){
		if (swap == true){
			if (temp->next != NULL){
				for (j = 0; j < 6; j++){
					x = x + temp->num[j];
					y = y + temp->next->num[j];
				}
				if (y < x){
					for (j = 0; j < 6; j++){
						temporary = temp->next->num[j];
						temp->next->num[j] = temp->num[j];
						temp->num[j] = temporary;
					}
					for (j = 0; j < 3; j++){
						tempName[j] = temp->next->name[j];
						temp->next->name[j] = temp->name[j];
						temp->name[j] = tempName[j];
					}
					swap = true;
					i = 0;
				}
			}
		}
		else
			{
				swap = false;
			}
			x = 0;
			y = 0;
			if (i < holder)
				swap = true;
		temp = temp->next;
	}
          temp = head;
          for (i = 0; i < holder; i++)
          {
              for (j = 0; j < 3; j++)
              {
                  tempName[j] = temp->name[j];
                  cout << tempName[j];
              }
			  if (i !=(*max) - 1)
				  cout << " -> ";
              temp = temp->next;
          }
return 0;
}
void insert(nodeptr &head, int data[], char name[]){
	nodeptr temp;
	int i = 0;
	temp = new node;
	for (i = 0; i < 3; i++)
	    temp->name[i] = name[i];
	for (i = 0; i < 6; i++)
		temp->num[i] = data[i];
	temp->next = NULL;
	
	if(head == NULL){
		head = temp;
	}
	else{
		temp->next=head;
		head=temp;
	}
}
