// -fpermissive must be disabled for this to compile

#include "ANSI_include.h"
#include "defines.h"
#include "help.h"

using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;

int main( unsigned int argc, unsigned char* argv[] ) {
	
	if ( argc == 1 || !strcmp( argv[1], "/?" ) ) {				// Help Info
		printHelp();		
		return 0;
	}
	
	operationMode opMode;
	switch ( argc ) {
		case 3: opMode = mode1; break;
		case 4: opMode = mode2; break;
		case 5: opMode = mode3; break;
		default:
			printMalformedArgumentsErrorMsg();
			return 0;
	}
	
	
	ifstream inFile;		// inFile
	fstream outFile;		// outFile
	c_str cur;				// CURRENT STRING
	c_str rep;				// REPLACEMENT STRING
	std::ios::pos_type filePos = 0;	// File Position
	
	rep.truLen = 0;
	
	switch ( opMode ) {											// Internalize Data
		case mode3:		// File Position
			filePos = atoi( argv[4] );
		case mode2:		// REPLACEMENT STRING
			rep.str = argv[3];
			rep.len = strlen( rep.str );
			rep.truLen = rep.len + ( 4 - ( rep.len % 4 ) );
		case mode1:		// CURRENT STRING
			cur.str = argv[2];
			cur.len = strlen( cur.str );
			cur.truLen = cur.len + ( 4 - ( cur.len % 4 ) );
	}
	
	if ( rep.truLen > cur.truLen ) {	// Fail if rep.str is too large
		printStrSizeErrorMsg();
		return 0;
	}
	
	/*Find in File*/ {
		inFile.open( argv[1], std::ios::binary );		// Open input file
		inFile.seekg( filePos );						// Seek to offset (mode3)
		
		// Find string in file 
		while( true ) {
			if ( inFile.peek() == cur.str[0] ) {		// If first char of "CURRENT STRING" is found in file
				filePos = inFile.tellg();				// Backup file position
				unsigned char tempStr[cur.truLen];		// Create "TEMP STRING" to check for match
				inFile.read( tempStr, cur.truLen );		// Read from inFile into "TEMP STRING"
				if ( !strcmp( cur.str, tempStr ) )		// Compare "CURRENT STRING" to "TEMP STRING"
					break;								// If it's a match, escape while loop with backup file position intact
				inFile.seekg( filePos );				// Otherwise, return to normal execution
			}
			inFile.get();								// Advance one character in file
			if ( inFile.eof() ) {						// Fail if EOF is reached
				printStrNotFoundErrorMessage();
				return 0;
			}
		}
		
		inFile.close();									// Close input file
	}
	
	if ( opMode == mode1 ) return filePos;
	
	/*Write to File*/ {
		outFile.open( argv[1], std::ios::in | std::ios::out | std::ios::binary );	// Open output file
		outFile.seekp( filePos );													// Seek to designated location
		unsigned char tempStr[cur.truLen] = {0};									// Make tempStr of correct length
		strcpy( tempStr, rep.str );													// Populate tempStr with REPLACEMENT STRING
		outFile.write( tempStr, cur.truLen );										// Write tempStr to file
		outFile.close();															// Close output file
	}
}
