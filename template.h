#ifndef _H_AGK_TEMPLATE_
#define _H_AGK_TEMPLATE_

// Link to GDK libraries
#include "AGK.h"

//Nates work and header files for stacks and crap

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
		void gameScreenDraw(void);
		void newsFeedDraw(void);
		void helpScreenDraw(void);
};

extern app App;

#endif

// Allow us to use the LoadImage function name
#ifdef LoadImage
 #undef LoadImage
#endif