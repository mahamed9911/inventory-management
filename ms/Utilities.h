#ifndef MS3_UTILITIES_H
#define MS3_UTILITIES_H

#include <string>

// header file for utilities.cpp

class Utilities {

private:
	size_t m_widthField = 1;
	static char m_delimiter;
public:
	Utilities();
	void setFieldWidth(size_t widthField);
	size_t getFieldWidth() const;
	const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(const char delimiter);
	const char getDelimiter() const;
};

#endif