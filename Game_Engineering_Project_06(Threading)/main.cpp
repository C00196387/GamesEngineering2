#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

int x = 0;
const int n = 5;
std::mutex m_lock;
int buf, p = 0, c = 0;

void Counter() 
{
	while (x <= 10) 
	{
		m_lock.lock();
		x++;
		std::cout <<x << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
		m_lock.unlock();
	}
}

void producer()
{
	int a[n] = { 10, 10, 30, 40, 50 };
	bool run = true;
	while (p < n)
	{
		std::cout << "ID:" << std::this_thread::get_id() << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(2));
		while (!(p == c))
		{
		}
		buf = a[p];
		std::cout << a[p] << " depositied in buffer" << std::endl;
		p = p + 1;
	}
	std::cout << "Production Finished" << std::endl;
	run = false;
}

void consumer()
{
	int b[n];
	bool run = true;
	while (c < n)
	{
		std::cout << "ID:" << std::this_thread::get_id() << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
		while ((p <= c))
		{
		}
		b[c] = buf;
		std::cout << buf << " depositied in b[]" << std::endl;
		c = c + 1;
	}
	std::cout << "Consumption Finished" << std::endl;
	run = false;
}

int main() 
{
	std::thread producer(producer);
	std::thread consumer(consumer);

	producer.join();
	consumer.join();

	std::cin.get();
}