#include <stdexcept>
#include "StockDriver.h"


class StockBrockerDriver {
private:
	StockDriver* userStock;

public:
	StockBrockerDriver(StockDriver *stockDriver):
	userStock(stockDriver){

	}

	void sell(int code, int price, int count) {
		time_t now = std::time(nullptr);
		int eachPrice = price / count;
		userStock->sell(code, eachPrice, count);
		int selledprice = userStock->getPrice(code, now);
		if (price != selledprice)
			throw std::logic_error("Stock selling fail.");
	}
};