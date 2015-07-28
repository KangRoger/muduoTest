#include <muduo/base/Logging.h>
#include <muduo/base/Thread.h>

#include <boost/bind.hpp>

#include <errno.h>

using namespace muduo;

void thread1()
{
    LOG_TRACE << "Thread 1. TRACE  LEVEL";
    LOG_DEBUG << "Thread 1 . DEBUG LEVEL";
    LOG_INFO << "Thread 1. INFO LEVEL";
    LOG_WARN << "Thread 1. WARN LEVEL";
    LOG_ERROR << "Thread 1. ERROR LEVEL";
    errno = 1;
    LOG_SYSERR << "Thread 1. SYSERR LEVEL";

}
void thread2()
{
    LOG_TRACE << "Thread 2. TRACE  LEVEL";
    LOG_DEBUG << "Thread 2 . DEBUG LEVEL";
    LOG_INFO << "Thread 2. INFO LEVEL";
    LOG_WARN << "Thread 2. WARN LEVEL";
    LOG_ERROR << "Thread 2. ERROR LEVEL";
    errno = 2;
    LOG_SYSERR << "Thread 1. SYSERR LEVEL";
   

}
int main()
{
	Thread t1(boost::bind(thread1), "thread 1");
	Thread t2(boost::bind(thread2), "thread 2");
	t1.start();
	t2.start();

	t1.join();
	t2.join();

	return 0;
}