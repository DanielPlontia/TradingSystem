#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../TradingSystem/StockBrockerDriver.cpp"

using namespace testing;

class StockMock : public StockDriver {
public:
	MOCK_METHOD(bool, login, (int id, int pass), (override));
	MOCK_METHOD(void, buy, (int code, int totalPrice, int count), (override));
	MOCK_METHOD(void, sell, (int code, int totalPrice, int count), (override));
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

TEST_F(StockBrockerTest, LoginFail) {
	int id = 1234;
	int pass = 0000;

	EXPECT_CALL(mock, login)
		.WillRepeatedly(Return(false));

	EXPECT_THROW(sbd.login(1234, 0000), std::exception);
}

TEST_F(StockBrockerTest, BuySomethingSuccess) {
	EXPECT_CALL(mock, buy(1, 200, 100))
		.Times(1);
	EXPECT_CALL(mock, getPrice(1, 0))
		.WillRepeatedly(Return(2));
	sbd.buy(1, 200, 100);
}

TEST_F(StockBrockerTest, BuySomethingFail) {
	EXPECT_CALL(mock, buy(1, 200, 100))
		.Times(1);
	EXPECT_CALL(mock, getPrice(1, 0))
		.WillRepeatedly(Return(100));
	EXPECT_THROW(sbd.buy(1, 200, 100), std::exception);
}

TEST_F(StockBrockerTest, SellSomethingSuccess) {
	EXPECT_CALL(mock, sell(1, 200, 100))
		.Times(1);
	EXPECT_CALL(mock, getPrice(1, 0))
		.WillRepeatedly(Return(2));
	sbd.sell(1, 200, 100);
}
TEST_F(StockBrockerTest, SellSomethingFail) {
	EXPECT_CALL(mock, buy(1, 200, 100))
		.Times(1);
	EXPECT_CALL(mock, getPrice(1, 0))
		.WillRepeatedly(Return(2));
	EXPECT_THROW(sbd.sell(1, 200, 100), std::exception);
}
