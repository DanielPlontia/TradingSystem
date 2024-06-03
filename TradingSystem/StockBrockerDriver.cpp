#include "StockDriver.h"
#include <string>
#include "KiwerAPI.cpp"
#include "NemoAPI.cpp"

using std::string;

class KiwerStockDriver : public StockDriver {
private:
	KiwerAPI api;
public:
	// StockDriver을(를) 통해 상속됨
	bool login(int id, int pass) override
	{
		if (id == pass)
		{ 
			api.login(std::to_string(id), std::to_string(pass));
			return true;
		}
		else return true;
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
private:
	NemoAPI api;

public:
	// StockDriver을(를) 통해 상속됨
	bool login(int id, int pass) override
	{
		if (id > pass)
		{
			api.certification(std::to_string(id), std::to_string(pass));
			return true;
		}
		else return false;
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
		return userStock->login(id, pass);
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