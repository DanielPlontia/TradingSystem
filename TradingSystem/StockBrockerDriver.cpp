#include "StockDriver.h"
#include <string>

using std::string;

class KiwerStockDriver : public StockDriver {
	// StockDriver을(를) 통해 상속됨
	bool login(int id, int pass) override
	{


		return false;
	}
	void buy(int code, int price, int count) override
	{
	}
	void sell(int code, int price, int count) override
	{
	}
	int getPrice(int code, time_t time) override
	{
		return 0;
	}
};

class NemoStockDriver : public  StockDriver{
	// StockDriver을(를) 통해 상속됨
	bool login(int id, int pass) override
	{
		return false;
	}
	void buy(int code, int price, int count) override
	{
	}
	void sell(int code, int price, int count) override
	{
	}
	int getPrice(int code, time_t time) override
	{
		return 0;
	}
};

class StockBrockerDriver : public StockDriver{
private:
	StockDriver* userStock;

public:

	void selectStockBrocker(string stock)
	{
		if (stock == "Kiwer") userStock = new KiwerStockDriver();
		if (stock == "Nemo") userStock = new NemoStockDriver();
	}

	bool login(int id, int pass) override
	{
		return false;
	}
	void buy(int code, int price, int count) override
	{
	}
	void sell(int code, int price, int count) override
	{
	}
	int getPrice(int code, time_t time) override
	{
		return 0;
	}
};