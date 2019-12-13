#ifndef ARGS_H
#define ARGS_H

int seekStr( char* filename, c_str& cur, std::ios::pos_type& filePos );
int writeStr( char* filename, c_str& rep, std::ios::pos_type& filePos, unsigned int& tempLen );

#endif /* ARGS_H */
