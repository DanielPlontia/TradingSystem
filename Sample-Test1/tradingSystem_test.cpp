#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../TradingSystem/StockBrockerDriver.cpp"

using namespace testing;

class StockMock : public StockDriver {
public:
	MOCK_METHOD(bool, login, (int id, int pass), (override));
	MOCK_METHOD(void, buy, (int code, int price, int count), (override));
	MOCK_METHOD(void, sell, (int code, int price, int count), (override));
	MOCK_METHOD(int, getPrice, (int code, time_t time), (override));
};

class StockFixture : public Test {
	StockMock mock;
	StockBrockerDriver sbd{ &mock };
};

TEST_F(StockBrockerTest, LoginSucess) {
	int id = 1234;
	int pass = 0000;

	EXPECT_CALL(mock, login)
		.WillRepeatedly(Return(true));

	bool bSuccess = sbd.login(id, pass);

	EXPECT_THAT(bSuccess, Eq(true));

}