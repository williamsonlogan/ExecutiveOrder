#include "template.h"

//Function that reads in one line from the CSV file of executive orders;
//Pushes one order onto the 
void queue_exec_order(FILE *infile, stack<Order>& orders)
{
	//New order initialized
	Order new_order;

	//Reads everything in; stores in; holder string declared
	char line[50];
	char *temp;
	int data = 0;
	fgets(line, 50, infile);

	//Parses the line
	temp = strtok(line, ",");
	new_order.image_tag = atoi(temp); //Stores the image tag
	temp = strtok(NULL, ",");
	new_order.money = atoi(temp); //Stores the money
	temp = strtok(NULL, ",");
	new_order.happy = atoi(temp); //Stores the happy level
	temp = strtok(NULL, ",");
	new_order.military = atoi(temp); //Stores the military value
	temp = strtok(NULL, ",");
	new_order.foreign = atoi(temp); //Stores the foreign value
	

/*	//Test that it was read correctly (debugging)
	cout << "IMG #: " << new_order.image_tag << endl;
	cout << new_order.money << endl;
	cout << new_order.happy << endl;
	cout << new_order.military << endl;
	cout << new_order.foreign << endl;
	cout << endl;
*/
	//Pushes the new node onto the stack
	orders.push(new_order);

}

//Function that queues every order in the file
//Basically, this function builds the stack of orders
void queue_all_orders(FILE *infile, stack<Order>& orders)
{
	
	while (!feof(infile))
	{
		queue_exec_order(infile, orders);
	}
	agk::Print("Success");
}

/*
new_order.image_tag = stoi(item); //Stores the image tag
getline(infile, item, ',');
new_order.money = stoi(item); //Stores the money
getline(infile, item, ',');
new_order.happy = stoi(item); //Stores the happiness
getline(infile, item, ',');
new_order.military = stoi(item); //Stores the military value
getline(infile, item, ',');
new_order.foreign = stoi(item); //Stores the foreign value
*/

void shuffleAllTheDecks(stack<Order> orders)
{
	srand(time(NULL)); int decider;
	stack<Order> shuffleOne, shuffleTwo;
	int deckSize = 0;
	deckSize = orders.size()/2;
	//place half the deck into each stack
	for(int i = orders.size(); i != 0; i++)
	{
		shuffleOne.push(orders.top());
		orders.pop();
		shuffleTwo.push(orders.top());
		orders.pop();
		i = orders.size();
	}
	do
	{
		decider = rand() % 2;
		switch(decider)
		{
				case 0:
					if(shuffleOne.size() != 0)
					{
						orders.push(shuffleOne.top());
						orders.pop();
					}
						break;
				case 1:
					if(shuffleTwo.size() != 0)                                  
					{                                                           
						orders.push(shuffleTwo.top());                          
						orders.pop();                                       
					} 
						break;
		}
	} while ((shuffleOne.size() != 0) || (shuffleTwo.size() != 0));
}

Order Exec(stack<Order> &executive_orders)
{
	Order phil;
	phil = executive_orders.top();
	executive_orders.pop();
	return phil;
}

//Function that modifies stats based on executive order decision
void update_stats(int result, int *global_money, int *global_happy, int *global_military, int *global_foreign,
	Order new_order)
{
	if (result == 1)
	{
		*global_money += new_order.money;
		*global_happy += new_order.happy;
		*global_military += new_order.military;
		*global_foreign += new_order.foreign;
	}
}




