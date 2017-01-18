import json


#TODO: this is a simple check version, need to perform typecheking instead of only checking the keys
# source and dest are filenames for the JSON schemas
# Checks if dest's inputs keys are a subset of source's outputs keys
def check_schema(source, dest):
	with open(source, "r") as fs:
		json_src = fs.read();
	schema_src = json.loads(json_src)
	if not "outputs" in schema_src:
		print "ERROR while checking schemas: %s has no outputs" % source
		return False

	with open(dest, "r") as fd:
		json_dest = fd.read();
	schema_dest = json.loads(json_dest)
	if not "inputs" in schema_dest:
		print "ERROR while checking schemas: %s has no inputs" % dest
		return False

	for key in schema_dest["inputs"].keys():
		if not key in schema_src["outputs"]:
			return False
		if not isSubtype(schema_src["outputs"][key]["dtype"], schema_dest["inputs"][key]["dtype"]):
			return False


	return True

#TODO define a partial order on the types and check if type of source can be cast to type of dest
# source and dest are strings representing types
# Checks if the type of dest is a subtype of source, i.e. if it can be properly casted from the type of source
# Supported types are int8/16/32/64, uint8/16/32/64, float32/64, char, char8_str
def isSubtype(source, dest):
	#Isolated case for strings
	if (source == "char8_str") and  (dest == "char8_str"):
		return True
	if (source == "char8_str") and  not (dest == "char8_str"):
		return False
	if (dest == "char8_str") and not (source == "char8_str"):
		return False

	if (source == "char"):
		if(dest[0] == 'u'): #if dest is unsigned
			return False
		return True
	#So far this has been tested


	#TODO to be continued...

	
	return True



if __name__ == '__main__':
	source = "generator.json"
	dest = "myfilter.json"

	a = check_schema(source, dest)

	print a