
#include <flowvr/module.h>
#include <unistd.h>

#include "generatorOut.hpp"
#include "AugmentedOutport.hpp"

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
	flowvr::InputPort pIn("genI");
	std::vector<flowvr::Port*> ports;
	ports.push_back(&pIn);

	flowvr::ModuleAPI* flowvr = flowvr::initModule(ports);
	if (flowvr == NULL)
	{
	return 1;
	}

	flowvr::Message mIn;
	std::string history;
	std::vector<int>* podds;


	string json_schema = "primefilter.json"; // TODO THIS SHOULD BE GIVEN AS ARGUMENT

	int it(0), count(0);
	while (flowvr->wait())
	{
	//receive message from gen
	mIn.clear();//clear only data, keep stamps
	flowvr->get(&pIn,mIn);

	if(!mIn.data.empty()){
		cout << mIn.data.getSize() << " read" << endl;

	}
	else{
		cout << "Message was empty" << endl;
	}

	//sleep(sleep_time);
	++it;
	}

	std::cout << "In Myfilter history is " << history << std::endl;

	//flowvr->close();
	flowvr->abort();

	return 0;
}
