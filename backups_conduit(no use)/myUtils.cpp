#include "myUtils.hpp"

Node loadSchema(string filename){
	Node n;
	std::ifstream file(filename);
	std::string json_schema( (std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()) );

	//Generator g(json_schema, "conduit_json");
	//g.walk(n); //TODO check if it's the same as n.generate(json_schema);
	n.generate(json_schema); //seems to go the same thing

	return n;
}


std::vector<std::string> getInputs(Node n){
	return n["inputs"].child_names();
}

std::vector<std::string> getOutputs(Node n){
	return n["outputs"].child_names();
}

