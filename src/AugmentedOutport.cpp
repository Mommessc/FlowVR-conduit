
#include "AugmentedOutport.hpp"

#include <fstream>
#include <boost/algorithm/string.hpp>



std::vector<AugmentedOutport*> AugmentedOutport::load_outputs(std::string filename){
	std::vector<AugmentedOutport*> my_list;
	std::ifstream file(filename);

	if(!file.is_open()){
		std::cerr << "ERROR while openning file " << filename << std::endl;
		return my_list;
	}

	std::string line;
	std::vector<std::string> temp;
	AugmentedOutport* pAug;

	while(std::getline(file, line)){
		boost::split(temp, line, boost::is_any_of(";"));
		pAug = new AugmentedOutport(temp[0]);
		boost::split(pAug->list_keys_, temp[1], boost::is_any_of(" "));

		my_list.push_back(pAug);
	}


	return my_list;
}
