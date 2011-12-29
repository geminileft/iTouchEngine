#ifndef TERANDOMIZER
#define TERANDOMIZER

class TERandomizer {
private:
	unsigned int mNumber;

public:
	TERandomizer(unsigned int seed);
	unsigned int next();
};
#endif