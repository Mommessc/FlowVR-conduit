
#include <iostream>
#include <vector>
#include "DataContract.h"

class MyOutput : public DataContract{
public:
	MyOutput();
	MyOutput(std::vector<int> odd, std::vector<int> even);
	//~MyOutput();

	void* get(std::string key);

	int set(std::string key, void* ptr);

	void fun(){
		std::cout << "TOTO" << std::endl;
	}

private:
	    void* odd_;
		void* even_;

};
