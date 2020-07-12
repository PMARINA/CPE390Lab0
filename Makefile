# This is a comment -- test

all: helloworld DebugDemo


helloworld: helloworld.cpp
	g++ $< -o $@

# helloworld: the name of the target
# helloworld.cpp: the dependency... what the target depends
# 	on. 
# $<: The list of dependencies
# $@: The name of the target

DebugDemo: DebugDemo.cpp
	g++ -g3 $<
# DebugDemo: again, the name of the target
# DebugDemo.cpp: Dependency... if the file is not
#		here, it literally won't build
# g++ -g $< -o $@: the command to build (see README.md)
# $<, 

# Here, we don't use a -o $@ because the settings file I've
# built automatically picks the default named executable

clean:
	@rm -f helloworld DebugDemo *.exe *.out
