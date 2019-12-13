// -fpermissive must be disabled for this to compile

#include "ANSI_include.h"
#include "defines.h"
#include "args.h"
#include "help.h"

int main( unsigned int argc, unsigned char* argv[] ) {
	
	if ( argc == 1 || !strcmp( argv[1], "/?" ) ) {				// Help Info
		printHelp();	
		return 0;
	}
	
	c_str cur;				// CURRENT STRING
	c_str rep;				// REPLACEMENT STRING
	operationMode opMode;

	for ( unsigned int i = 2; i < argc; i++ ) {
		/**/ if ( !strcmp( argv[i], "/curStr" ) ) 			{
																cur.str = argv[i+1];
																cur.len = strlen( cur.str );
																cur.truLen = cur.len;
																opMode.tempLen = cur.truLen;
																opMode.seek = true; i++;
															}
		else if ( !strcmp( argv[i], "/repStr" ) ) 			{
																rep.str = argv[i+1];
																rep.len = strlen( rep.str );
																rep.truLen = rep.len;
																opMode.write = true; i++;
															}
		else if ( !strcmp( argv[i], "/offset" ) ) 			{
																opMode.filePos = strtol( argv[i+1], NULL, 0 );
																i++;
															}
		else if ( !strcmp( argv[i], "/nullBytes" ) ) 		{
																unsigned int multiple = strtol( argv[i+1], NULL, 0 );
																cur.truLen = cur.len + ( multiple - ( cur.len % multiple ) );
																rep.truLen = rep.len + ( multiple - ( rep.len % multiple ) );
																opMode.tempLen = cur.truLen;
																i++;
															}
		else if ( !strcmp( argv[i], "/blind" ) ) 			{
																opMode.blind = true;
															}
		else												{
																printMalformedArgumentsErrorMsg();
																return 0;
															}
	}
	
	
	if ( opMode.seek == false && opMode.blind == false ) {
		printImpossible();
		return 0;
	}
	
	if ( opMode.seek == true )			// Seek a string
		seekStr( argv[1], cur, opMode.filePos );
	
	if ( opMode.filePos == -1 ) {		// Failsafe for string not found
		printStrNotFoundErrorMessage();
		return 0;
	}
	
	if ( opMode.write == true ) {			// Write a string
		if ( opMode.blind == false ) {			// Replacing a string found by searching
			if ( rep.truLen > cur.truLen ) {		// Fail if rep.str is too large
				printStrSizeErrorMsg();
				return 0;
			}
			writeStr( argv[1], rep, opMode.filePos, opMode.tempLen );
		} else {								// Replacing a string blindly
			writeStr( argv[1], rep, opMode.filePos, rep.truLen );
		}
	}
	std::cout << opMode.filePos << std::endl;
	return opMode.filePos;				// Return filePos for future use in a script
	

}
