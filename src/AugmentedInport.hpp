#ifndef AUGMENTEDOUTPORT_H
#define AUGMENTEDOUTPORT_H

#include "AugmentedPort.h"

class AugmentedInport : public AugmentedPort{
public:
	//AugmentedInport(){}
	AugmentedInport(std::string name, std::vector<std::string> list_keys = std::vector<std::string>() ) {
		name_ = name;
		list_keys_ = list_keys;
		pPort_ = new flowvr::OutputPort(name);
	}

	//~AugmentedInport(){};


	//static std::vector<AugmentedInport*> load_inputs(std::string filename); //TODO ??

};



#endif
