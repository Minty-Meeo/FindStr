#include "help.h"
#include "ANSI_include.h"

void printHelp() {
	std::cout <<
	"A tool for replacing C-Strings in binary files."                                << std::endl <<
	""                                                                               << std::endl <<
	"FINDSTR \"filename\" /curStr \"str\" [/repStr \"str\"] [/nullBytes int] [/offset int]"       << std::endl <<
	"[/blind]"                                                                       << std::endl <<
	""                                                                               << std::endl <<
	"  filename          Name of file to open"                                       << std::endl <<
	""                                                                               << std::endl <<
	"  /curStr           Search for a string and update the File Position with its"  << std::endl <<
	"                    location."                                                  << std::endl <<
	"     str | String to search for"                                                << std::endl <<
	""                                                                               << std::endl <<
	"  /repStr           Write a string at the File Position, given it is smaller"   << std::endl <<
	"                    than the string given by the /curStr argument."             << std::endl <<
	"     str | Replacement string"                                                  << std::endl <<
	""                                                                               << std::endl <<
	"  /nullBytes        Operate under the assumption that null bytes pad out the"   << std::endl <<
	"                    curStr and repStr strings to the next multiple of given"    << std::endl <<
	"                    value.  For hexadecimal, prefix with 0x."                   << std::endl <<
	"     int | Given value"                                                         << std::endl <<
	""                                                                               << std::endl <<
	"  /offset           Manually update the File Position before doing anything."   << std::endl <<
	"                    For hexadecimal, prefix with 0x."                           << std::endl <<
	"     int | File Position offset"                                                << std::endl <<
	""                                                                               << std::endl <<
	"  /blind            Disregard curStr length and even allows /repStr argument"   << std::endl <<
	"                    to function without a /curStr argument."                    << std::endl <<
	""                                                                               << std::endl <<
	""                                                                               << std::endl <<
	"To bring up help information, pass /? as the only argument"                     << std::endl <<
	""                                                                               << std::endl <<
	"ERRORLEVELS:"                                                                   << std::endl <<
	"  The File Position after program execution is returned via the errorlevel."    << std::endl <<
	"  In the event of a failure, 0 will be returned."                               << std::endl;
}

void printMalformedArgumentsErrorMsg() {
	std::cout <<
	"Malformed arguments!"                                                           << std::endl;
}

void printStrSizeErrorMsg() { 
	std::cout
	<< "Replacement string too large!"                                               << std::endl;
}

void printStrNotFoundErrorMessage() { 
	std::cout
	<< "Current string not found!"                                                   << std::endl;
}

void printFileNotFoundMsg() { 
	std::cout
	<< "File not found!"                                                             << std::endl;
}

void printImpossible() { 
	std::cout
	<< "Incomplete request!  Impossible!"                                            << std::endl;
}
