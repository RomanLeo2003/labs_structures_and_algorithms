#pragma once
#include "Bank.h"

class Menu {
public:
	void PrintMenu();
	void MenuRunLoop();
	void HandlePrintBank(Bank &bank);
	void HandleFilePrintBank(Bank &bank);
	void HandleCommand(char &command);
	void HandleSetBankName(Bank &bank);
	void HandleAddBranch(Bank& bank);
	void HandleAddCashMachine(Bank& bank);
	void HandleRemoveBranch(Bank& bank);
	void HandleRemoveCashMachine(Bank& bank);
	int GetNumber();
};

