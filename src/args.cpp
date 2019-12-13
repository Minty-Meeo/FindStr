#include "ANSI_include.h"
#include "defines.h"
#include "help.h"

int seekStr( char* filename, c_str& cur, std::ios::pos_type& filePos ) {
	ifstream inFile;
	
	inFile.open( filename, std::ios::binary );		// Open input file
	if ( !inFile.is_open() ) {
		printFileNotFoundMsg();
		return;
	}
	inFile.seekg( filePos );						// Seek to offset (/offset argument)
	
	// Find string in file
	while( true ) {
		if ( inFile.peek() == cur.str[0] ) {				// If first char of "CURRENT STRING" is found in file
			filePos = inFile.tellg();						// Backup file position
			unsigned char curStrPadded[cur.truLen] = {0};	// Create temporary padded "CURRENT STRING" for memcpy function
			strcpy( curStrPadded, cur.str );				// Populate temporary padded "CURRENT STRING"
			unsigned char tempStr[cur.truLen] = {0};		// Create "TEMP STRING" to check for match
			inFile.read( tempStr, cur.truLen );				// Read from inFile into "TEMP STRING"
			if ( !memcmp( curStrPadded, tempStr, cur.truLen ) )		// Compare "CURRENT STRING" to "TEMP STRING"
				break;										// If it's a match, escape while loop with backup file position intact
			inFile.seekg( filePos );						// Otherwise, return to normal execution
		}
		inFile.get();										// Advance one character in file
		if ( inFile.eof() ) {								// Fail if EOF is reached
			filePos = -1;
			return;
		}
	}
	
	inFile.close();									// Close input file
}

int writeStr( char* filename, c_str& rep, std::ios::pos_type& filePos, unsigned int& tempLen ) {
	fstream outFile;
	
	outFile.open( filename, std::ios::in | std::ios::out | std::ios::binary );	// Open output file
	outFile.seekp( filePos );													// Seek to designated location
	unsigned char tempStr[tempLen] = {0};										// Make tempStr of correct length
	strcpy( tempStr, rep.str );													// Populate tempStr with REPLACEMENT STRING
	outFile.write( tempStr, tempLen );											// Write tempStr to file
	outFile.close();															// Close output file
}
