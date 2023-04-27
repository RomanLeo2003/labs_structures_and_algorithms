#include "CashMachine.h"


CashMachine::CashMachine():
	adress("DEFAULT"),
	id(-1)
{
}

CashMachine::CashMachine(const std::string& adress, int id) :
	adress(adress),
	id(id)
{
}

std::string& CashMachine::GetAdress() {
	return adress;
}

/* 
 double CashMachine::GetMoney() const {
	return money;
}
void CashMachine::SetMoney(double new_money) {
	money = new_money;
}

void CashMachine::WithdrawMoney(double money_to_withdraw) {
	money -= money_to_withdraw;
}

void CashMachine::AddMoney(double money_to_add) {
	money += money_to_add;
}
*/

void CashMachine::SetAdress(const std::string &new_adress) {
	adress = new_adress;
}


void CashMachine::SetId(int new_id) {
	id = new_id;
}

int CashMachine::GetId() const {
	return id;
}

/*void CashMachine::PrintCashMachine() {
	std::count 
}*/

