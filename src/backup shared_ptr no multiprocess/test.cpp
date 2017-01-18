
#include "flowvr/module.h"
#include <unistd.h>
#include <ctime>

#include "MyOutput.hpp"
#include <boost/interprocess/managed_shared_memory.hpp>

using namespace std;
using namespace boost::interprocess;

int sleep_time=1;


int main(int argc, const char** argv)
{
managed_shared_memory shm(open_or_create, "tatooo", 1024);

	cout << "DEBUT " << shm.get_num_named_objects() << endl;

	if(atoi(argv[1]) == 1){
		if(shm.get_num_named_objects() == 1){
			cout << "want to destroy" << endl;
			shm.destroy<MyOutput>("myoutput");
			cout << "destroyed" << endl;
			return 0;
		}
		MyOutput* pMO = shm.find_or_construct<MyOutput>("myoutput")();

		cout << "MID " << shm.get_num_named_objects() << endl;
		return 0;
	}
	else if(atoi(argv[1]) == 2){
		if(shm.get_num_named_objects() < 1){
			cout << "returning2" << endl;
			return 0;
		}

		MyOutput* pMO = shm.find<MyOutput>("myoutput").first;
		cout << "A" << endl;
		std::vector<int> odds(5,1);
		pMO->set("odd", &odds);
		cout << "correctly set " << &odds << endl;
	}
	else{
		if(shm.get_num_named_objects() < 1){
			cout << "returning3" << endl;
			return 0;
		}

		MyOutput* pMO = shm.find<MyOutput>("myoutput").first;
		cout << "A" << endl;
		pMO->fun();
	}

	//remove("to0");
/*
	try{

	MyOutput* pMO = shm.find<MyOutput>("toto").first;

	if(pMO == 0){
		cout << "ERROR" << endl;

		pMO = shm.construct<MyOutput>("toto")();

		return 1;
	}
	else{
		cout << pMO << endl;
		shm.destroy<MyOutput>("toto");
		return 0;
	}

	}
	catch(exception const& e){
		cout << e.what() << endl;
	}
*/
	return 0;
}
