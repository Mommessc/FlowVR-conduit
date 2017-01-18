#ifndef AUGMENTED_PORT_H
#define AUGMENTED_PORT_H

#include "flowvr/module.h" //TODO verify if this is not too much includes, maybe need only to include Ports
#include <string>
#include <vector>
#include <iostream>

typedef unsigned char Direction; //TODO check if it's correct to define like this or there is better way to do it
#define DIR_IN 0x01
#define DIN_OUT 0x02

class AugmentedPort{
public:
	virtual ~AugmentedPort(){}

	std::string name(){return name_;}
	Direction direction(){return direction_;}
	flowvr::Port* port(){return pPort_;}
	std::vector<std::string> keys(){return list_keys_;}

	void print(){
		std::string s(name_ + ":");
		//s += ":";
		for(std::string key : list_keys_){
			s+= " " + key;
		}
		std::cout << s << std::endl;
	}

protected:
	std::string name_;
	Direction direction_;
	flowvr::Port* pPort_;
	std::vector<std::string> list_keys_;
	//std::string predicate; //TODO define a class Predicate? with a test method taking as argument the it number

}; //End AugmentedPort class

#endif
