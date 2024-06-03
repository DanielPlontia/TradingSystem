#pragma once
#include <ctime>
#define interface struct
 
interface StockDriver {
	virtual bool login(int id, int pass) = 0;
	virtual void buy(int code, int price, int count) = 0;
	virtual void sell(int code, int price, int count) = 0;
	virtual int getPrice(int code, time_t time) = 0;
};
