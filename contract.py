from flowvrapp import *
#import traces


gen = Module("gen", cmdline = "bin/generator 0")
oOdd = gen.addPort("Oodd", direction = "out")
#oEven = gen.addPort("Oeven", direction = "out")

#gen_schema = "generator.json" #Don't know what to do with that.
# We need a "key checker" of the schemas form in and out when ports
# are connected in the python script


oddFil = Module("oddFilter", cmdline = "bin/oddFilter")
iGenOdd = oddFil.addPort("genI", direction = "in")

#oddFilter_schema = "oddFilter.json" #TODO fix this

#evenFil = Module("evenFilter", cmdline = "bin/evenFilter")
#iGenEven = evenFil.addPort("genI", direction = "in")

#oddFilter_schema = "oddFilter.json" #TODO fix this


oOdd.link(iGenOdd) #Outport Oodd of gen is connected to Inport genI of oddFil
#oEven.link(iGenEven)


app.generate_xml("contract")
