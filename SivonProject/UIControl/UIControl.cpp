/*
 * UIControl.cpp
 *
 *  Created on: 13.10.2013
 *      Author: Hristo
 */

#include "UIControl.h"
#include <string.h>
#include <algorithm>
#include <string>
#include <sstream>

#define IDENT(n) for (int i = 0; i < n; ++i) printf("    ")

void print(json_value *value, int ident = 0)
{
	IDENT(ident);
	if (value->name) printf("\"%s\" = ", value->name);
	switch(value->type)
	{
	case JSON_NULL:
		printf("null\n");
		break;
	case JSON_OBJECT:
	case JSON_ARRAY:
		printf(value->type == JSON_OBJECT ? "{\n" : "[\n");
		for (json_value *it = value->first_child; it; it = it->next_sibling)
		{
			print(it, ident + 1);
		}
		IDENT(ident);
		printf(value->type == JSON_OBJECT ? "}\n" : "]\n");
		break;
	case JSON_STRING:
		printf("\"%s\"\n", value->string_value);
		break;
	case JSON_INT:
		printf("%d\n", value->int_value);
		break;
	case JSON_FLOAT:
		printf("%f\n", value->float_value);
		break;
	case JSON_BOOL:
		printf(value->int_value ? "true\n" : "false\n");
		break;
	}
}

bool parse(char *source)
{
	char *errorPos = 0;
	char *errorDesc = 0;
	int errorLine = 0;
	block_allocator allocator(1 << 10);

	json_value *root = json_parse(source, &errorPos, &errorDesc, &errorLine, &allocator);
	if (root)
	{
		print(root);
		return true;
	}

	printf("Error at line %d: %s\n%s\n\n", errorLine, errorDesc, errorPos);
	return false;
}

bool replace(std::string& str, const std::string& from, const std::string& to) {
	size_t start_pos = str.find(from);
	if(start_pos == std::string::npos)
		return false;
	str.replace(start_pos, from.length(), to);
	return true;
}

UIControl::UIControl()
{
}

UIControl::~UIControl() {
}

std::string UIControl::FormatSendData(sVarsIn * data) {
	std::stringstream sDigitalArray, sAnalogArray;
	sMapIn *d = &data->Names;
	for (int i=0; i<7; i++) {
		for (int j=0; j<16; j++) {
			if ((i!=0)||(j!=0)) sDigitalArray << ", ";
			bool val = (d->Digital[i]&(1<<j)) ? 1:0;
			sDigitalArray << (int)val;
			//			printf("%d ", val);
		}
	}
	for (int i=0; i<54; i++) {
		if (i!=0) sAnalogArray << ", ";
		sAnalogArray << data->Names.Analog[i];
	}
	std::string sendData = jsonText;
	replace(sendData, "sDigitalArray", sDigitalArray.str().c_str());
	replace(sendData, "sAnalogArray", sAnalogArray.str().c_str());
//	std::cout << sendData << std::endl;
	SerialComm::uidata = sendData;
	return sendData;
}

void UIControl::ParseData(std::string data) {
	char *errorPos = 0;
	char *errorDesc = 0;
	int errorLine = 0;
	block_allocator allocator(1 << 10);
	sMapOut * vals = &vars.Names;
	//
	std::replace( data.begin(), data.end(), '\'', '"');
	//	parse((char *)data.c_str());
	json_value *val = json_parse((char *)data.c_str(), &errorPos, &errorDesc, &errorLine, &allocator);
	if (val) {
		std::string arrName = "";
		int j=0, bit=0, k=0;
		for (json_value *it = val->first_child; it; it = it->next_sibling)
		{
			if (!strcmp(it->name, "Temp"))
			{
				printf("Temp=%d\n", it->int_value);
			}
			if (it->type == JSON_ARRAY) {
				//				arrName = it->name;
				for (json_value *it2 = it->first_child; it2; it2 = it2->next_sibling)
				{
//					printf("name: %s val: %hd\n", it->name, (short)it2->int_value);
					printf("%d ", it2->int_value);
					if (!strcmp(it->name, "Digital"))
					{
						if (j<7) {
							if (it2->int_value >= 1)
							{
								vals->Digital[j] |= (1 << bit++);
							} else {
								vals->Digital[j] &= ~(1 << bit++);
							}
							if (bit>=16) { bit=0; j++; }
						}

					}
					if (!strcmp(it->name, "Analog"))
					{
						if (k<42)
						{
							vals->Analog[k++] = (short) it2->int_value;
						}
					}

				}
			}
			//printf("%d\n", it->int_value);
		}
	}
	printf("\n");
}

void UIControl::ReadData(sVarsOut * const data) {
	*data = vars;
}
