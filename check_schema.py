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
		

	return True



if __name__ == '__main__':
	source = "generator.json"
	dest = "myfilter.json"

	a = check_schema(source, dest)

	print a