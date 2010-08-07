#include "parse.h"

void Endian::readFile(char *filename)
{

	FILE *fp;
	char *str;
	uint64_t temp;

	fp = fopen(filename, "r");

	fread(&tx_code, sizeof(uint16_t), 1, fp);
	tx_code = ntohs(tx_code);

	fread(&length, sizeof(uint32_t), 1, fp);
	length = ntohl(length);

	symbol = (char *)malloc(length + 1);
	fread(symbol, length, 1, fp);

	fread(&temp, sizeof(double), 1, fp);
	temp = (be64toh(temp));
	open = *((double *)(&temp));

	fread(&temp, sizeof(double), 1, fp);
	temp = (be64toh(temp));
	high = *((double *)(&temp));

	fread(&temp, sizeof(double), 1, fp);
	temp = (be64toh(temp));
	low  = *((double *)(&temp));

	fread(&temp, sizeof(double), 1, fp);
	temp = (be64toh(temp));
	last = *((double *)(&temp));

	fread(&last_traded_time, sizeof(uint32_t), 1, fp);
	last_traded_time = ntohl(last_traded_time);

	fread(&last_traded_volume, sizeof(uint32_t), 1, fp);
	last_traded_volume = ntohl(last_traded_volume);

	fread(&total_volume, sizeof(uint64_t), 1, fp);
	total_volume = be64toh(total_volume);

	fread(&temp, sizeof(double), 1, fp);
	temp = (be64toh(temp));
	ask_price = *((double *)(&temp));

	fread(&ask_size, sizeof(uint32_t), 1, fp);
	ask_size = ntohl(ask_size);

	fread(&temp, sizeof(double), 1, fp);
	temp = (be64toh(temp));
	bid_price = *((double *)(&temp));

	fread(&bid_size, sizeof(uint32_t), 1, fp);
	bid_size = ntohl(bid_size);

	fclose(fp);
}

void Endian::displayFields()
{
	cout << "code is " << tx_code << "\n"; 
	printf("length is %d\n", length);
	printf("symbol is %s\n", symbol);
	printf("open is %f\n", open);
	printf("high is %f\n", high);
	printf("low is %f\n", low);
	printf("last is %f\n", last);
	cout << "last traded time is " << last_traded_time << "\n";
	cout << "last traded volume is " << last_traded_volume << "\n";
	cout << "total volume is " << total_volume << "\n";
	printf("ask price is %f\n", ask_price);
	cout << "ask size is " << ask_size << "\n";
	cout << "bid price is " << bid_price << "\n";
	cout << "bid size is " << bid_size << "\n";
}

void Endian::getData()
{
	cin >> tx_code;
	cin >> length;
	symbol = (char *)malloc(length + 1);
	cin >> symbol;
	cin >> open;
	cin >> high;
	cin >> low;
	cin >> last;
	cin >> last_traded_time;
	cin >> last_traded_volume;
	cin >> total_volume;
	cin >> ask_price;
	cin >> ask_size;
	cin >> bid_price;
	cin >> bid_size;
} 

char *Endian::writeFile(char *filename)
{
	FILE *fp;
	uint64_t temp;
	uint32_t len;
	size_t no_of_bytes = 0;
	char *str;
        str = (char *)malloc(sizeof(Endian));

//	fp = fopen(filename, "w");

	tx_code = htons(tx_code);
	memcpy(str, (const void *)tx_code, sizeof(tx_code));
	str += sizeof(tx_code);
//	no_of_bytes += fwrite(&tx_code, sizeof(uint16_t), 1, fp);

	len = length;
	length = htonl(length);
	memcpy(str, (const void *)length, sizeof(length));

	str += sizeof(length);
//	no_of_bytes += fwrite(&length, sizeof(uint32_t), 1, fp);

	no_of_bytes += fwrite(symbol, len, 1, fp);

	temp = *((uint64_t *)(&open));
	temp = htobe64(temp);
//	no_of_bytes += fwrite(&temp, sizeof(double), 1, fp);

	temp = *((uint64_t *)(&high));
	temp = htobe64(temp);
//	no_of_bytes += fwrite(&temp, sizeof(double), 1, fp);

	temp = *((uint64_t *)(&low));
	temp = htobe64(temp);
//	no_of_bytes += fwrite(&temp, sizeof(double), 1, fp);

	temp = *((uint64_t *)(&last));
	temp = htobe64(temp);
//	no_of_bytes += fwrite(&temp, sizeof(double), 1, fp);

	last_traded_time = htonl(last_traded_time);
//	no_of_bytes += fwrite(&last_traded_time, sizeof(uint32_t), 1, fp);

	last_traded_volume = htonl(last_traded_volume);
//	no_of_bytes += fwrite(&last_traded_volume, sizeof(uint32_t), 1, fp);

	total_volume = htobe64(total_volume);
//	no_of_bytes += fwrite(&total_volume, sizeof(uint64_t), 1, fp);

	temp = *((uint64_t *)(&ask_price));
	temp = htobe64(temp);
//	no_of_bytes += fwrite(&temp, sizeof(double), 1, fp);

	ask_size = htonl(ask_size);
//	no_of_bytes += fwrite(&ask_size, sizeof(uint32_t), 1, fp);

	temp = *((uint64_t *)(&bid_price));
	temp = htobe64(temp);
//	no_of_bytes += fwrite(&temp, sizeof(double), 1, fp);

	bid_size = htonl(bid_size);
//	no_of_bytes += fwrite(&bid_size, sizeof(uint32_t), 1, fp);

//	fclose(fp);
}

ofstream& operator<<(ofstream &out, Endian ob) 
{
	char *str;
	str = ob.writeFile((char *)"end");
	string s(str);
//	out << s;
	return out;
}

