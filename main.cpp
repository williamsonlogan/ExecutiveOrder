#include "hackathon_executiveorder_queue.h"

int main()
{
	stack <Order> executive_orders;
	FILE *orders_file = fopen("orders.csv", "r");
	
	queue_all_orders(orders_file, executive_orders);

	return 0;
}