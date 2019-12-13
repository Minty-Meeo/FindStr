#ifndef DEFINES_H
#define DEFINES_H

struct c_str {
	unsigned char* str;
	size_t len = 0;
	size_t truLen = 0;
};

struct operationMode {
	bool seek = false;
	bool write = false;
	bool blind = false;
	std::ios::pos_type filePos = 0;
	unsigned int tempLen;
};

#endif /* DEFINES_H */
