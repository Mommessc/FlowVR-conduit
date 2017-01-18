
#include "flowvr/module.h"
#include <unistd.h>
#include <ctime>

#include "MyOutput.hpp"
#include <memory>

using namespace std;

int sleep_time=1;


int isPrime(int number){
	unsigned int divisor;
	int bIsPrime;

	// Check divisibility :
	bIsPrime = 1;
	divisor = 3;
	while ( (bIsPrime) && (divisor < (number-1)) )
	{
		bIsPrime = number % divisor;
		divisor += 2; // An even number can't be prime, so no need to check even divisors too
	}

	return bIsPrime;
}



int main(int argc, const char** argv)
{

	flowvr::OutputPort pOut("generalOut");
	std::vector<flowvr::Port*> ports;
	ports.push_back(&pOut);

	flowvr::ModuleAPI* flowvr = flowvr::initModule(ports);

	if (flowvr == NULL)
	{
		return 1;
	}

	std::srand(atoi(argv[1])+8);
	string history;
	int count = 0, number = 0;
	std::vector<int> odds(5);
	MyOutput toto;
	std::shared_ptr<MyOutput> pshared = make_shared<MyOutput>(toto);

	void* ptr;
	//std::shared_ptr<MyOutput> myptr;

	//std::string json_schema = "generator.json"; // TODO THIS SHOULD BE GIVEN AS ARGUMENT

	flowvr::MessageWrite m;

	int it=0;
	while (flowvr->wait())
	{
		count = 0;
		while(count < 5){
			number = rand() % 10000 + 1;
			if(number % 2 == 1){
				odds[count] = number;
				history.append(std::to_string(odds[count]).append(" "));
				++count;
			}
		}

		pshared->set("odd", &odds);
		ptr = (void*)&pshared;

		m.data = flowvr->alloc(sizeof(pshared));
		memcpy(m.data.writeAccess(), ptr, sizeof(pshared));//TODO sizeof(pshared) or sizeof(ptr) ??

		cout << m.data.getSize() << " written" << endl;

		cout << &toto << " " << pshared << endl;

		flowvr->put(&pOut, m);
		m.clear();

		//myptr = *static_cast<std::shared_ptr<MyOutput>*>((void*)m.data.writeAccess());
		//cout << (*(std::vector<int>*)(myptr->get("odd")))[1] << endl;

		//toto = myptr.get();

		//pp = (vector<int>*)myptr->get("odd");

		//pshared.reset();

		//cout << "TOTOO " << pp->size() << endl;


		//ptr = malloc(m.data.getSize());
		//memcpy(ptr, m.data.writeAccess(), m.data.getSize());


		//flowvr->put(&pOut,m);
		//m.data.clear(); //to not clear the stamps

		//pp = (std::vector<int>*) pshared->get("odd");

		sleep(sleep_time);
		++it;
		if(it == 3){
			break;
		}
	}

	cout << "Generator sent " << history << endl;

	//flowvr->close();
	flowvr->abort();
	return 0;
}
