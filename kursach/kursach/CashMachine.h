#pragma once
#include <string>
#include <iostream>
#include <fstream>

class CashMachine {
private:
	std::string adress{};
	int id{};
	//double money{};

public:
	CashMachine();
	CashMachine(const std::string& adress, int id);

	int GetId() const;
	void SetId(int new_id);
	void SetAdress(const std::string& new_adress);
	//void SetMoney(double new_money);
	std::string& GetAdress();
	//double GetMoney() const;

	//void PrintCashMachine();
	//void WithdrawMoney(double money_to_withdraw);
	//void AddMoney(double money_to_add);
};