//threadpoolTest.cpp

#include <muduo/base/ThreadPool.h>
#include <muduo/base/CurrentThread.h>

#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>

#include <iostream>

using namespace muduo;

class TaskClass
{
public:
	TaskClass(int id):id_(id){}
	void Print()
	{
		std::cout<<"Task ID is: "<<id_<<", Thread ID is: "<<CurrentThread::tid()<<", Thread name is: "<<CurrentThread::name()<<std::endl;
	}
private:
	int id_;

};

void ThreadInitFunc()
{
	std::cout<<"Init Thread. "<<", Thread ID is: "<<CurrentThread::tid()<<", Thread name is: "<<CurrentThread::name()<<std::endl;
}

int main()
{
	ThreadPool pool;
	pool.setMaxQueueSize(20);
	pool.setMaxQueueSize(20);
	pool.setThreadInitCallback(boost::bind(ThreadInitFunc));
	pool.start(4);

	for(int i=0; i<20; ++i)
	{
		boost::shared_ptr<TaskClass> taskClass(new TaskClass(i));
		pool.run(boost::bind(&TaskClass::Print, taskClass));
	}
	sleep(3);
	pool.stop();

	return 0;
}