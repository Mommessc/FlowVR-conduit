
#include "DataContract.h"
#include <iostream>
#include <vector>


class generatorOut : public DataContract{
public:
	generatorOut();
	generatorOut(std::vector<int> odd, std::vector<int> even);
	//~generatorOut();

	void* get(std::string key);

	int set(std::string key, void* ptr);

	void fun(){
		std::cout << "IN FUN " << odd_ << std::endl;
		//std::cout << (*(std::vector<int>*)odd_).size() << std::endl;
	}

private:
	    void* odd_;
		void* even_;

};
