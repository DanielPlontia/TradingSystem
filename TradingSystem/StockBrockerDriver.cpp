#include "StockDriver.h"
#include <string>

using std::string;

class KiwerStockDriver : public StockDriver {
	// StockDriver��(��) ���� ��ӵ�
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
	// StockDriver��(��) ���� ��ӵ�
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

class StockBrockerDriver {
private:
	StockDriver* userStock;

public:

	StockDriver* selectStockBrocker(string stock)
	{
		if (stock == "Kiwer") return new KiwerStockDriver();
		if (stock == "Nemo") return new NemoStockDriver();
		else return nullptr;
	}

};