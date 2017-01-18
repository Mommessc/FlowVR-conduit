
#include "MyOutput.hpp"

    MyOutput::MyOutput(){
		odd_ = 0;
		even_ = 0;
	}

	//MyOutput::~MyOutput(){}

	// Returns the pointer to the data
	void* MyOutput::get(std::string key){
		if(key == "odd"){
			return odd_;
		}
		if(key == "even"){
			return even_;
		}

		std::cout << "Error key " << key << " does not match in getter" << std::endl;
		return 0;//returns a null pointer in case the string does not match
	}

	int MyOutput::set(std::string key, void* ptr){
		if(key == "odd"){
			odd_ = ptr;
			return 0;
		}
		if(key == "even"){
			even_ = ptr;
			return 0;
		}

		std::cout << "ERROR key " << key << " does not match in setter" << std::endl;
		return 1;
	}
