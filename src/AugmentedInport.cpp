
#include "AugmentedInport.hpp"

#include <iostream>
#include <fstream>
#include <boost/algorithm/string.hpp>


/*
std::vector<AugmentedInport*> AugmentedInport::load_inputs(std::string filename){
	std::vector<AugmentedInport*> my_list;
	std::ifstream file(filename);

	if(!file.is_open()){
		std::cerr << "ERROR while openning file " << filename << std::endl;
		return my_list;
	}

	std::string line;
	std::vector<std::string> temp;
	AugmentedInport* pAug;

	while(std::getline(file, line)){
		boost::split(temp, line, boost::is_any_of(";"));
		pAug = new AugmentedInport(temp[0]);
		boost::split(pAug->list_keys_, temp[1], boost::is_any_of(" "));

		my_list.push_back(pAug);
	}


	return my_list;
}
*/
