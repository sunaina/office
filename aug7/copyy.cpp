#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<arpa/inet.h>
#include<endian.h>
#include<algorithm>
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
	struct level1_data_t ob;
	char *str;

	fp = fopen("data", "r");

	fread(&ob.tx_code, sizeof(uint16_t), 1, fp);
	cout << "code is " << ntohs(ob.tx_code) << "\n"; 

	fread(&ob.length, sizeof(uint32_t), 1, fp);
	printf("length is %d\n", ntohl(ob.length));

	ob.symbol = (char *)malloc(4);
	fread(ob.symbol, 4, 1, fp);
	printf("symbol is %s\n", ob.symbol);

	uint64_t temp;
	fread(&temp, sizeof(double), 1, fp);
	temp = (be64toh(temp));
	ob.open = *((double *)(&temp));
	printf("open is %f\n", ob.open);

	fread(&temp, sizeof(double), 1, fp);
	temp = (be64toh(temp));
	ob.high = *((double *)(&temp));
	printf("high is %f\n", ob.high);

	fread(&temp, sizeof(double), 1, fp);
	temp = (be64toh(temp));
	ob.low  = *((double *)(&temp));
	printf("low is %f\n", ob.low);

	fread(&temp, sizeof(double), 1, fp);
	temp = (be64toh(temp));
	ob.last = *((double *)(&temp));
	printf("last is %f\n", ob.last);

	fread(&ob.last_traded_time, sizeof(uint32_t), 1, fp);
	cout << "last traded time is " << ntohl(ob.last_traded_time) << "\n";

	fread(&ob.last_traded_volume, sizeof(uint32_t), 1, fp);
	cout << "last traded volume is " << ntohl(ob.last_traded_volume) << "\n";

	fread(&ob.total_volume, sizeof(uint64_t), 1, fp);
	cout << "total volume is " << be64toh(ob.total_volume) << "\n";

	fread(&temp, sizeof(double), 1, fp);
	temp = (be64toh(temp));
	ob.ask_price = *((double *)(&temp));
	printf("ask price is %f\n", ob.ask_price);

	fread(&ob.ask_size, sizeof(uint32_t), 1, fp);
	cout << "ask size is " << ntohl(ob.ask_size) << "\n";

	fread(&temp, sizeof(double), 1, fp);
	temp = (be64toh(temp));
	ob.bid_price = *((double *)(&temp));
	cout << "bid price is " << ob.bid_price << "\n";

	fread(&ob.bid_size, sizeof(uint32_t), 1, fp);
	cout << "bid size is " << ntohl(ob.bid_size) << "\n";

	fclose(fp);
	return 0;
}

