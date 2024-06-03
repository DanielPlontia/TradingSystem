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
		userStock->sell(code, price, count);
		int selledprice = userStock->getPrice(code, now);
		if (price != selledprice)
			throw std::logic_error("�ֽ��� ���������� �ȸ��� �ʾҽ��ϴ�.");
	}
};