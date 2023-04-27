#pragma once
#include "CashMachine.h"


namespace constants {
	constexpr int BRANCH_SIZE{ 20 };
}

//template <typename T>
class Branch {
private:
	CashMachine cash_machines[constants::BRANCH_SIZE]{};
	int count_cash_machines{};
	int branch_id{};
	Branch* next{};
	//Branch* head{};

public:
	Branch();
	Branch(int branch_id);

	bool IsBranchFull();
	bool IsBranchEmpty();

	void SetCountCashMachines(int new_count);
	int GetCountCashMachines() const;
	void SetBranchId(int new_branch_id);
	int GetBranchId() const;
	Branch* GetNext() const;
	void SetNext(Branch* const new_branch);

	void InitBranch();
	void AddCashMachine(const std::string& adress, int new_cash_machine_id);
	void RemoveCashMachine(int id_to_remove);
	int FindCashMachine(int search_id);
	//// void PrintBranch(bool file_flag); ////

	void PrintBranchF(FILE* fp);
};
