#include "header.h"
#include "PracticalSocket.h"
#include <thread>

using namespace std;

void main()
{
	string IP ("10.10.14.51");
	string PORT("65005");
	thread t1(ClientMain, IP, PORT);
	thread t2(ServerMain, PORT);
	
	t1.join();
	t2.join();
}