

#ifndef DATA_CONTRACT_H
#define DATA_CONTRACT_H

#include <string>

class DataContract{
public:
	virtual ~DataContract(){}

	virtual void* get(std::string key) = 0; //TODO Return void* ?? Make it const ??

	virtual int set(std::string key, void* ptr) = 0;

}; //End DataContract class


#endif
