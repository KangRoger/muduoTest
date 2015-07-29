#include <muduo/base/BlockingQueue.h>
#include <muduo/base/Thread.h>

#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>

#include <iostream>
using namespace muduo;

using namespace boost;

void Produce(shared_ptr<BlockingQueue<int> > queue)
{
	while(true)
	{
		int product=rand()%1000+1;
		std::cout<<"Produce: "<<product<<std::endl;
		queue->put(product);
		sleep(rand()%5);
	}
	
}
void Consome(shared_ptr<BlockingQueue<int> > queue)
{
	while(true)
	{
		int product=queue->take();
		std::cout<<"Consome: "<<product<<std::endl;
	}
}
int main()
{
	shared_ptr<BlockingQueue<int> > blockingQueue(new BlockingQueue<int>);
	Thread t1(boost::bind(Produce, blockingQueue));
	Thread t2(boost::bind(Consome, blockingQueue));

	t1.start();
	t2.start();

	t1.join();
	t2.join();

	return 0;
}