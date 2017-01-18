#ifndef AUGMENTEDOUTPORT_H
#define AUGMENTEDOUTPORT_H

#include "AugmentedPort.h"

class AugmentedOutport : public AugmentedPort {
public:
	//AugmentedOutport(){}
	AugmentedOutport(std::string name, std::vector<std::string> list_keys = std::vector<std::string>() ) {
		name_ = name;
		list_keys_ = list_keys;
		pPort_ = new flowvr::OutputPort(name);
	}

	//~AugmentedOutport(){};

	static std::vector<AugmentedOutport*> load_outputs(std::string filename);

};



#endif
