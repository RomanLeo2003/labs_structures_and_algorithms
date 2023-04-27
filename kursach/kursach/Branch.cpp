#include "Branch.h"
#include "CashMachine.h"

Branch::Branch() : 
	count_cash_machines(0),
	branch_id(-1),
	next(nullptr)
{
	InitBranch();
}

Branch::Branch(int brunch_id) :
	count_cash_machines(0),
	branch_id(brunch_id),
	next(nullptr)
{
	InitBranch();
}

void Branch::InitBranch() {
	for (int i{ 0 }; i < constants::BRANCH_SIZE; i++) {
		cash_machines[i] = CashMachine();
	}
}

void Branch::SetBranchId(int new_branch_id) {
	branch_id = new_branch_id;
}

void Branch::SetCountCashMachines(int new_count_cash_machines) {
	count_cash_machines = new_count_cash_machines;
}

Branch* Branch::GetNext() const {
	return next;
}

void Branch::SetNext(Branch* const new_next) {
	next = new_next;
}

int Branch::GetBranchId() const {
	return branch_id;
}

int Branch::GetCountCashMachines() const {
	return count_cash_machines;
}

bool Branch::IsBranchFull() {
	return count_cash_machines == constants::BRANCH_SIZE;
}

bool Branch::IsBranchEmpty() {
	return count_cash_machines == 0;
}

void Branch::AddCashMachine(const std::string& adress, int cash_machine_id) {

	if (IsBranchFull()) {
		std::cout << "¬ филиал больше нельз€ добавить новые банкоматы." << std::endl;
		return;
	}
	CashMachine new_cash_machine = CashMachine(adress, cash_machine_id);
	if (IsBranchEmpty()) {
		cash_machines[0] = new_cash_machine;
	}
	else {
		int i{ 0 };
		for (i; i < count_cash_machines; i++) {
			if (cash_machines[i].GetId() > new_cash_machine.GetId()) {
				for (int j = count_cash_machines; j > i; j--) {
					cash_machines[j] = cash_machines[j - 1];
				}
				cash_machines[i] = new_cash_machine;
				break;
			}
		}
		if (i == count_cash_machines) {
			cash_machines[i] = new_cash_machine;
		}
	}
	count_cash_machines++;
}

int Branch::FindCashMachine(int search_id) {
	int first{ 0 };
	int last{ count_cash_machines - 1 };
	int mid{};
	while (first <= last) {
		mid = (first + last) / 2;
		if (cash_machines[mid].GetId() == search_id) {
			return mid;
		}
		else if (cash_machines[mid].GetId() > search_id) {
			last = mid - 1;
		}
		else {
			first = mid + 1;
		}
	}
	return -1;
}

void Branch::RemoveCashMachine(int id_to_remove) {
	int find_ind{ FindCashMachine(id_to_remove) };
	if (find_ind == -1) {
		std::cout << "Ѕанкомата с таким id не найдено." << std::endl;
		return;
	}
	cash_machines[find_ind] = CashMachine();
	for (int i = find_ind; i < count_cash_machines - 1; i++) {
		cash_machines[i] = cash_machines[i + 1];
	}
	count_cash_machines--;
}

//void Branch::PrintBranch(bool file_flag) {
//	std::streambuf* coutOldBuf = std::cout.rdbuf();
//	if (file_flag) {
//		std::ofstream file;
//		file.open("output.txt");
//		std::cout.rdbuf(file.rdbuf());
//	}
//	else {
//		std::cout.rdbuf(coutOldBuf);
//	}
//
//	std::cout << "\tCash machine id:\tadress:\n";
//
//	for (int i{ 0 }; i < count_cash_machines; i++) {
//		std::cout << "\t\t\t\t" << cash_machines[i].GetId() << "\t\t" << cash_machines[i].GetAdress() << "\n";
//	}
//}

void Branch::PrintBranchF(FILE* fp) {
	fprintf(fp, "\tCash machine id:\tadress:\n");
	for (int i{ 0 }; i < count_cash_machines; i++) {
		fprintf(fp, "\t\t\t\t%d\t\t%s\n", cash_machines[i].GetId(), cash_machines[i].GetAdress().c_str());
	}
}