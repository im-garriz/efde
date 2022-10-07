#https://courses.cs.duke.edu/cps108/fall02/resources/MakefileInfo/sample.html
##############################################################################
# Application-specific variables
# TARGET is the name of the executable file
# SRC_FILES is a list of all source code files that must be linked
#           to create the executable
##############################################################################

TARGET = test.out
SRC_FILES = unitTestConfig.cpp test_DifferentialEvolution.cpp ../DifferentialEvolution.cpp \
			../utils/fitnessFunctions.cpp

##############################################################################
# Compiler specifications
# These match the variable names given in /usr/share/lib/make/make.rules
# so that make's generic rules work to compile our files.
# gmake prefers CXX and CXXFLAGS for c++ programs
##############################################################################

# Compiler
CXX = g++

# Flags
DEBUG_LEVEL     = -g
EXTRA_CXXFLAGS  = -Wall -static
CXXFLAGS        = $(DEBUG_LEVEL) $(EXTRA_CXXFLAGS)

# What flags should be passed to the linker
#   In other words, where should we look for libraries to link with - note,
#   you should never need to include compiler specific directories here
#   because each compiler already knows where to look for its system files.

LDFLAGS = -L/usr/local/lib/

# What libraries should be linked with.
# For example, -lm links with libm.so, the math library.
# If you make a library of your own, say, libscandir.a, you have to link it
# in by adding -lscandir here.

LDLIBS = -lboost_unit_test_framework

# All source files have associated object files.
# This line sets `OFILES' to have the same value as `SRC_FILES' but
# with all the .cc's changed into .o's.
O_FILES         = $(SRC_FILES:%.cpp=%.o)

###########################################################################
# Additional rules make should know about in order to compile our files
###########################################################################

# all is the default rule
all: $(TARGET)

# exec depends on the object files
# It is made automagically using the LDFLAGS and LOADLIBES variables.
# The .o files are made automagically using the CXXFLAGS variable.
$(TARGET): $(O_FILES)
	$(CXX) $(CXXFLAGS) $(SRC_FILES) $(LDFLAGS) $(LDLIBS) -o $(TARGET)

# to use `makedepend', the target is `depend'
depend:
	makedepend -- $(CXXFLAGS) -- -Y $(SRC_FILES)

# clean up after you're done
clean_o:
	$(RM) $(O_FILES) core *.rpo

clean: clean_o
	$(RM) $(TARGET)

