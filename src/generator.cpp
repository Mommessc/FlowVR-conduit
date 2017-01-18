
#include "flowvr/module.h"
#include <unistd.h>
#include <ctime>

#include "generatorOut.hpp"
#include "AugmentedOutport.hpp"

using namespace std;
using namespace flowvr;

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




// For each output port in the list of ports, checks the unions of key from the schemas and create+send the message accordingly
void publish(ModuleAPI* flowvr, generatorOut* pMyOut, std::vector<AugmentedOutport*> augPorts){
	std::string key;
	std::vector<int> toto;

	for (AugmentedOutport* pAug : augPorts){
		if(pAug->port()->isConnected()){
			MessageWrite m;
			key = "even";
			toto = *(std::vector<int>*) (pMyOut->get(key));
			m.data = flowvr->allocString(std::to_string(toto[0]));

			cout << key << " " << m.data.writeAccess() << endl;

			//flowvr->put(pAug->outport(), m);
		}
		else{
			cout << "port " << pAug->name() << " not connected" << endl;
		}

	}


//create a map<string key, Buffer> to store each get(key) that has been serialized
//for all port in my_ports:
	//TODO check for predicate here ??
	//BufferWrite mybuf();
	//for key in (list of keys of port):
	    //mybuf += map[key] (this concatenates each single buffer of key into mybuf
	//message.clear() (useful??)
	//message.data = mybuf;
	//flowvr->put(&port, message);

//clear the map.
}



int main(int argc, const char** argv)
{

	flowvr::OutputPort oOdd("Oodd");
	flowvr::OutputPort oEven("Oeven");
	std::vector<flowvr::Port*> ports; //Won't be useful anymore
	ports.push_back(&oOdd);
	ports.push_back(&oEven);
	flowvr::ModuleAPI* flowvr = flowvr::initModule(ports);

	if (flowvr == NULL)
	{
		return 1;
	}

	std::string filename = "generator.map"; //TODO give this as an argument of the main ?? TODO bis: .map is ok ???
	std::vector<AugmentedOutport*> my_AugPorts = AugmentedOutport::load_outputs(filename);

	for (AugmentedOutport* pAO : my_AugPorts){
		pAO->print();
	}


	std::srand(atoi(argv[1])+8);
	string history1, history2;
	int count1 = 0, count2 = 0, number = 0;

	std::vector<int> odds(5), evens(5);
	generatorOut* pMyOut = new generatorOut();

	//std::string my_schema = "generator.json"; // TODO THIS SHOULD BE GIVEN AS ARGUMENT OR FLOWVR KNOWS IT ALREADY ???

	int it=0;
	while (flowvr->wait())
	{
		//SIMULATION
		count1 = 0;
		count2 = 0;
		while(count1 != 5 || count2 != 5){
			number = std::rand() % 10000 + 1;
			if(count2 < 5 && (number % 2 == 0)){//Even
				evens[count2++] = number;
				history2.append(to_string(number)).append(" ");
			}
			else if(count1 < 5 && (number % 2 == 1) ){//odd
				odds[count1++] = number;
				history1.append(to_string(number)).append(" ");
			}
		}


		//END OF SIMU
		//WRITING IN OBJECT MYOUPTUT
		pMyOut->set("odd", &odds);
		pMyOut->set("even", &evens);

		//CALL TO flowvr->publish(pMO); SIMULATED BY THE FOLLOWING
		//publish(flowvr, pMyOut, my_AugPorts);
		MessageWrite m;
		m.data = flowvr->allocString(std::to_string(odds[0]));


		flowvr->put(&oOdd, m);

		sleep(sleep_time);
		++it;
		if(it == 2){
			break;
		}
	}

	cout << "Generator odds: " << history1 << endl;
	cout << "Generator evens: " << history2 << endl;

	//flowvr->close();
	delete(pMyOut);
	flowvr->abort();
	return 0;
}
