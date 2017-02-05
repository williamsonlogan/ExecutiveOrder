#include <iostream>
#include <string>
#include <stack>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

typedef struct exec_order
{
	unsigned int image_tag;
	int money;
	int happy;
	int military;
	int foreign;

}Order;

//Function that reads in one line from the CSV file of executive orders;
//Stores in an order, pushes onto the stack
void queue_exec_order(FILE *infile, stack<Order> orders);

//Function that queues every order in the file
//Basically, this function builds the stack of orders
void queue_all_orders(FILE *infile, stack<Order> orders);

