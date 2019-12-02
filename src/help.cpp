#include "help.h"
#include "ANSI_include.h"

void printHelp() {
	std::cout <<
	"A utility for Shape files (*.mod) found in Pikmin 1."                           << std::endl <<
	""                                                                               << std::endl <<
	"TWEAKMOD errand \"filename\" [ errand \"filename\" ] [ ... ]"                   << std::endl <<
	""                                                                               << std::endl <<
	"  errand            Function to be performed"                                   << std::endl <<
	"                      iMOD  input a Shape file (*.mod)"                         << std::endl <<
	"                      oOBJ  output a Wavefront Object file (*.obj)"             << std::endl <<
	"                      oDMD  output a Dolphin Model file (*.dmd)"                << std::endl <<
	"                      oLOG  output to command window and log file"              << std::endl <<
	""                                                                               << std::endl <<
	"  filename          Name of file to perform errand on."                         << std::endl <<
	""                                                                               << std::endl <<
	"Only one input errand should be given."                                         << std::endl <<
	"Any number of output errands can be given."                                     << std::endl <<
	""                                                                               << std::endl <<
	"To bring up help information, pass /? as the only argument"                     << std::endl <<
	""                                                                               << std::endl <<
	"ERRORLEVELS:"                                                                   << std::endl <<
	"  -1  | Help prompt called"                                                     << std::endl <<
	"  -2  | Malformed arguments"                                                    << std::endl;
}

void printMalformedArgumentsErrorMsg() {
	std::cout <<
	"Malformed arguments (errand without filename)"                                  << std::endl;
}

void printStrSizeErrorMsg() { 
	std::cout
	<< "Replacement string too large!"                                               << std::endl;
}

void printStrNotFoundErrorMessage() { 
	std::cout
	<< "Current string not found!"                                                   << std::endl;
}
