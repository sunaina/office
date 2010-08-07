#ifndef __PARSE_H__
#define __PARSE_H__

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<arpa/inet.h>
#include<stdint.h>
#include<stdio.h>
#include<endian.h>
#include<string.h>

using namespace std;

class Endian
{
	public:

        uint16_t tx_code;
        uint32_t length; // Length of ‘symbol’ field.
        char *symbol;
        double open;
        double high;
        double low;
        double last;
        uint32_t last_traded_time;
        uint32_t last_traded_volume;
        uint64_t total_volume;
        double ask_price;
        uint32_t ask_size;
        double bid_price;
	uint32_t bid_size;

		void readFile(char *);
		void displayFields();
		char *writeFile(char *);
		void getData();
};
#endif /*  __PARSE_H__ */
