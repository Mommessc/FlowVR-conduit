#ifndef MYUTILS_HPP
#define MYUTILS_HPP

#include <unistd.h>
#include <fstream>
#include <conduit.hpp>

using namespace std;
using namespace conduit;

Node loadSchema(string filename);

template<typename T>
void printVector(std::vector<T> vector){
	for(unsigned int i=0; i<vector.size(); ++i){
		cout << vector[i] << endl;
	}
}


std::vector<std::string> getInputs(Node n);

std::vector<std::string> getOutputs(Node n);



#endif
