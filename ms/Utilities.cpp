#include "Utilities.h"


char Utilities::m_delimiter = ' ';


Utilities::Utilities() {
	m_widthField = 1;
}

void Utilities::setFieldWidth(size_t widthField) {
	m_widthField = widthField;
}


size_t Utilities::getFieldWidth() const {
	return m_widthField;
}


const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
	std::string extractedToken = str.substr(next_pos);
	size_t pos = extractedToken.find(m_delimiter);
	if (pos != std::string::npos) {
		extractedToken = extractedToken.substr(0, pos);
		next_pos += pos + 1;
		if (extractedToken == "")
			throw "There is not any token between delimiters";
		more = true;
	}
	else {
		more = false;
	}
	if (extractedToken.length() > m_widthField)
		setFieldWidth(extractedToken.length());

	return extractedToken;
}


void Utilities::setDelimiter(const char delimiter) {
	m_delimiter = delimiter;
}



const char Utilities::getDelimiter() const {
	return m_delimiter;
}