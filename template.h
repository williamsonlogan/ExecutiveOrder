#ifndef _H_AGK_TEMPLATE_
#define _H_AGK_TEMPLATE_

// Link to GDK libraries
#include "agk.h"

//Nates work and header files for stacks and crap

#include <iostream>
#include <string>
#include <stack>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <time.h>

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
//Helper function for queue_all_orders
void queue_exec_order(FILE *infile, stack<Order> orders);

//Function that queues every order in the file
//Basically, this function builds the stack of orders
void queue_all_orders(FILE *infile, stack<Order> orders);

//Function that peeks, pops, and returns the the order that was on top
Order Exec(stack<Order> orders);

//Function that shuffles all the orders in the stack
void shuffleAllTheDecks(stack<Order> orders);

//Function that modifies stats based on executive order decision
void update_stats(int result, int *global_money, int *global_happy, int *global_military, int *global_foreign,
	Order new_order);


#define DEVICE_WIDTH 720
#define DEVICE_HEIGHT 1280
#define FULLSCREEN false

// used to make a more unique folder for the write path
#define COMPANY_NAME "QuesoSoft"

// Global values for the app
class app
{
	public:

		// constructor
		app() { memset ( this, 0, sizeof(app)); }

		// main app functions - mike to experiment with a derived class for this..
		void Begin( void );
		int Loop( void );
		void End( void );
		void loadAssets();
		void gameScreenDraw();
		void newsFeedDraw(void);
		void helpScreenDraw(void);
};

extern app App;

#endif

// Allow us to use the LoadImage function name
#ifdef LoadImage
 #undef LoadImage
#endif
