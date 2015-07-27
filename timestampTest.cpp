#include <muduo/base/Timestamp.h>
#include<stdio.h>
using namespace muduo;

int main()
{
	Timestamp timeStamp=Timestamp::now();
	printf("it's %lld microseconds from Epoch\n", timeStamp.microSecondsSinceEpoch());
	string str= timeStamp.toString();
	printf("sting format is %s\n", str.c_str());
	return 0;
}