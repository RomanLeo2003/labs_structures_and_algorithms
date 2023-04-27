#pragma once
#include "Branch.h"

class Bank {
private:
	std::string bank_name{};
	Branch* branch_head{};
	int branch_count{};

public:
	Bank();
	Bank(const std::string& name);
	//Bank(const Bank &ref_Bank);
	~Bank();

	std::string& GetName();
	void SetName(const std::string& new_Bank_name);
	int GetCount();
	void SetCount(int new_branch_count);
	
	bool IsBankEmpty();
	void AddBranch(int branch_id);
	void RemoveBranch(int branch_id);
	std::pair<Branch*, int> FindBranch(int search_branch_id);
	void DestroyBank();
	void AddCashMachineToBranch(int branch_id, int cash_machine_id, const std::string& adress);
	void RemoveCashMachineFromBranch(int branch_id, int cash_machine_id);
	// void PrintBank(bool file_flag);
	void InputBankFromFile(FILE *fp);
	void PrintBankF(FILE *fp);
};
