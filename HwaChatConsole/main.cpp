#include "header.h"
#include "PracticalSocket.h"
#include <thread>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>

using namespace std;

string ip("10.10.14.51");
string port("65005");

int main()
{
	string IP ("10.10.14.51");
	string PORT("65005");
	thread t1(ClientMain, IP, PORT);
	thread t2(ServerMain, PORT);
	
	t1.join();
	t2.join();
}