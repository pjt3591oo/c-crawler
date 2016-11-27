#include "parse.h"

string* split(string strTarget, string token) {
	int     nCutPos;
	int     nIndex = 0;
	string* strResult = new string[30];

	while ((nCutPos = strTarget.find_first_of(token)) != strTarget.npos) {
		if (nCutPos > 0) {
			strResult[nIndex++] = strTarget.substr(0, nCutPos);
		}
		strTarget = strTarget.substr(nCutPos + 1);
	}

	if (strTarget.length() > 0) {
		strResult[nIndex++] = strTarget.substr(0, nCutPos);
	}

	return strResult;
}
