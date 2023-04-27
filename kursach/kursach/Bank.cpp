#include "Bank.h"
#include "Branch.h"
#include "CashMachine.h"

Bank::Bank():
	bank_name("DEFAULT"),
	branch_head(nullptr), ////
	branch_count(0)
{}

Bank::Bank(const std::string& name):
	bank_name(name),
	branch_head(nullptr), ////
	branch_count(0)
{}


/*
Bank::Bank(const Bank& ref_bank) {
	Branch* ref_cur{ ref_bank.branch_head };
	// Branch* prev{ ref_bank.branch_head };
	branch_count = ref_bank.branch_count;
	branch_head = ref_cur;
	Branch* cur{ branch_head };
	while (ref_cur) {
		ref_cur = ref_cur->GetNext();
		cur->SetNext(ref_cur);
		cur = cur->GetNext();
	}
}

*/

Bank::~Bank() {
	DestroyBank();
}

bool Bank::IsBankEmpty() {
	return branch_head == nullptr;
}

std::string& Bank::GetName() {
	return bank_name;
}

int Bank::GetCount() {
	return branch_count;
}

void Bank::SetName(const std::string &new_bank_name) {
	bank_name = new_bank_name;
}

void Bank::SetCount(int new_branch_count) {
	branch_count = new_branch_count;
}

void Bank::AddBranch(int new_branch_id) {
	Branch* new_branch{ new Branch(new_branch_id) };
	Branch* cur{ branch_head };
	Branch* prev{ branch_head };
	// 
	// if (cur) cur = cur->GetNext();
	if (IsBankEmpty()) {
		branch_head = new_branch;
	}
	else if (new_branch_id <= branch_head->GetBranchId()) {
		new_branch->SetNext(branch_head);
		branch_head = new_branch;
	}
	else {
		if (cur) cur = cur->GetNext();
		while (cur && cur->GetBranchId() < new_branch_id) {
			cur = cur->GetNext();
			prev = prev->GetNext();
		}
		if (!cur) {
			prev->SetNext(new_branch);
		}
		else {
			new_branch->SetNext(cur);
			prev->SetNext(new_branch);
		}
	}
	branch_count++;
}

std::pair<Branch*, int> Bank::FindBranch(int search_branch_id) {
	Branch* cur{ branch_head };
	int branch_ind = 0;
	if (IsBankEmpty()) {
		std::cout << "Банк пуст." << std::endl;
		return {branch_head, -1};
	}
	while (cur && cur->GetBranchId() != search_branch_id) {
		cur = cur->GetNext();
		branch_ind++;
	}

	//if (cur != nullptr) std::cout << "Искомый элемент найден под индексом: " << branch_ind << "." << std::endl;
	//else std::cout << "Филиал с таким id не найден в банке." << std::endl;
	if (!cur) {
		std::cout << "Филиал с таким id не найден." << std::endl;
		return { nullptr, -1 };
	}
	return { cur, branch_ind };
}

void Bank::DestroyBank() {
	Branch* cur{ branch_head };
	while (branch_head) {
		branch_head = branch_head->GetNext();
		delete cur;
		cur = branch_head;
	}
}

void Bank::RemoveBranch(int branch_id) {
	if (IsBankEmpty()) {
		std::cout << "Банк пуст, удалять нечего." << std::endl;
		return;
	}
	Branch* cur{ branch_head };
	if (branch_head->GetBranchId() == branch_id) {
		branch_head = branch_head->GetNext();
		delete cur;
		branch_count--;
		return;
	}

	Branch* prev{ branch_head };
	if (cur) cur = cur->GetNext();
	while (cur && cur->GetBranchId() != branch_id) {
		cur = cur->GetNext();
		prev = prev->GetNext();
	}
	
	if (!cur) {
		std::cout << "Филиал с таким id не найден." << std::endl;
		return;
	}

	prev->SetNext(cur->GetNext());
	delete cur;
	branch_count--;
}

void Bank::RemoveCashMachineFromBranch(int branch_id, int cash_machine_id) {
	std::pair<Branch*, int> p{ FindBranch(branch_id) };
	p.first->RemoveCashMachine(cash_machine_id);
}

/*
void Bank::PrintBank(bool file_flag) {
	std::streambuf* coutOldBuf = std::cout.rdbuf();
	if (file_flag) {
		std::ofstream file;
		// меняем буфер cout для вывода в файл
		file.open("output.txt");
		std::cout.rdbuf(file.rdbuf());
	}
	else {
		std::cout.rdbuf(coutOldBuf);
	}
	if (IsBankEmpty()) {
		// branch_head->GetNext()->PrintBranch(fp);
		std::cout << "Банк пуст, выводить нечего." << "\n";
		return;
	}
	std::cout << "Банк: " << this->GetName() << "\n";
	std::cout << "Branch id:\n";
	Branch* cur{ branch_head };
	while (cur) {
		std::cout << "\t" << cur->GetBranchId();
		cur->PrintBranch(file_flag);
		std::cout << "\n";
		cur = cur->GetNext();
	}
}
*/

void Bank::PrintBankF(FILE* fp) {
	if (IsBankEmpty()) {
		fprintf(fp, "Банк пуст, выводить нечего.\n");
		return;
	}
	fprintf(fp, "Банк: %s\n", this->bank_name.c_str());
	fprintf(fp, "Branch id:\n");
	Branch* cur{ branch_head };
	while (cur) {
		fprintf(fp, "%d\t", cur->GetBranchId());
		cur->PrintBranchF(fp);
		fprintf(fp, "\n");
		cur = cur->GetNext();
	}
}

void Bank::InputBankFromFile(FILE* fp) {

}

void Bank::AddCashMachineToBranch(int branch_id, int cash_machine_id, const std::string& adress) {
	std::pair<Branch*, int> p{ FindBranch(branch_id) };
	if (p.second != -1) {
		p.first->AddCashMachine(adress, cash_machine_id);
	}
}