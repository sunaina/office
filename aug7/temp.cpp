#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<arpa/inet.h>
#include<endian.h>
using namespace std;

struct level1_data_t {
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
};

int main()
{
	FILE *fp;
	char *str;
	int length;
	uint16_t *ptr;
	struct level1_data_t ob;

	fp = fopen("data", "r");
	fseek(fp, 0, SEEK_END);
	length = ftell(fp);
	cout << "length is " << length << "\n";
	fseek(fp, 0, SEEK_SET);

	str = (char *)malloc(length + 1);

	fread(str, length, 1, fp);
	fclose(fp);

	cout << "string is\n";
	for(int i = 0; i < length; i++) 
		printf("%d ", str[i]);

/*	cout << "\ncode is ";
	ob.tx_code = ntohs(*((uint16_t *)str));
	cout << ob.tx_code << "\n";

	str += 2;
	ob.length = ntohl(*((uint32_t *)str));
	printf("length is %d\n", ob.length);

	ob.symbol = (char *)malloc(4);
	str += 4;
	int j = 0;

	for(; j < 4; j++)
		ob.symbol[j] = str[j];
	ob.symbol[j] = '\0';
	cout << "symbol is " << ob.symbol << "\n";

	str += 4;

	printf("asd %d\n", str[0]);

	ob.open = (*((double *)str));
	printf("%f\n", ob.open);

	str += 8;
	ob.high = *((double *)str);
	printf("%f\n", ob.high);

	str += 8;
	ob.low = *((double *)str);
	printf("%f\n", ob.low);

	str += 8;
	ob.last = *((double *)str);
//	printf("%f\n", ob.last);

	str += 8;

	printf("asdf %d\n", str[0]);
	ob.last_traded_time = ntohl(*((uint32_t *)str));
	cout << "last traded time is " << ob.last_traded_time << "\n";
//	printf("last traded time %d\n", ob.last_traded_time);

	str += 4; 
	ob.last_traded_volume = ntohl(*((uint32_t *)str));
	cout << "last traded volume is " << ob.last_traded_volume << "\n";

	str += 4;
	ob.total_volume = be64toh(*((uint64_t *)str));
	cout << "total volume is " << ob.total_volume << "\n";

	str += 8;
	ob.ask_price = *((double *)str);
	printf("ask price is %f\n", ob.ask_price);

	str += 8;
	ob.ask_size = ntohl(*((uint32_t *)str));
	cout << "ask size is " << ob.ask_size << "\n";

	str += 4;
	ob.bid_price = *((double *)str);
	cout << "bid price is " << ob.bid_price << "\n";

	str += 8;
	ob.bid_size = ntohl(*((uint32_t *)str));
	cout << "bid size is " << ob.bid_size << "\n"; */


//	cout << "open is " << ob.open << "\n";

	return 0;
}

