#include "Menu.h"

void Menu::PrintMenu() {
	std::cout << "������� ������ �������:" << std::endl;
	std::cout << "[Q] - ����� �� ���������." << std::endl;
	std::cout << "[P] - ������� ���������� �����." << std::endl;
	std::cout << "[F] - ��������� ���������� ����� �� �����." << std::endl;  ///
	std::cout << "[D] - ��������� ���������� ����� � ����." << std::endl;  ///
	std::cout << "[B] - �������� ����� ��������." << std::endl;
	std::cout << "[A] - �������� ����� ������." << std::endl;
	std::cout << "[R] - ������� ������ �� id." << std::endl;
	std::cout << "[I] - ������� �������� �� ������� � ����������� id." << std::endl;
	std::cout << "[N] - ����� ����� ������� � ����� �� ��� id." << std::endl;
	std::cout << "[U] - ����� ����� ��������� � ������� � ������������ id." << std::endl;
	std::cout << "[C] - �������� ��� �����." << std::endl;
}

void Menu::HandleCommand(char &command) {
	std::cin >> command;
	if ('A' <= command && command <= 'Z') {
		command -= ('a' - 'A');
	}
}

void Menu::HandlePrintBank(Bank &bank) {
	bank.PrintBankF(stdout);
}

void Menu::HandleFilePrintBank(Bank& bank) {
	FILE* fp{};
	fopen_s(&fp, "output.txt", "w");
	if (!fp) {
		std::cerr << "�� ������� ������� ���� ������." << std::endl;
		return;
	}
	bank.PrintBankF(fp);
	fclose(fp);
}

void Menu::HandleSetBankName(Bank &bank) {
	std::string bank_name{};
	std::cout << "������� ��� �����:" << std::endl;
	std::cin >> bank_name;
	bank.SetName(bank_name);
}

void Menu::HandleAddBranch(Bank& bank) {
	int new_branch_id{};
	std::cout << "������� id ������ �������:" << std::endl;
	new_branch_id = GetNumber();
	bank.AddBranch(new_branch_id);
}

void Menu::HandleAddCashMachine(Bank& bank) {
	if (bank.IsBankEmpty()) {
		std::cout << "���� ����." << std::endl;
		return;
	}
	int branch_id{};
	int cash_machine_id{};
	std::string adress{};
	std::cout << "������� id �������, � ������� ������ �������� ��������:" << std::endl;
	branch_id = GetNumber();
	std::cout << "������� id ��������� � ��� �����:" << std::endl;
	cash_machine_id = GetNumber();
	std::cin >> adress;
	bank.AddCashMachineToBranch(branch_id, cash_machine_id, adress);
}

void Menu::HandleRemoveBranch(Bank& bank) {
	if (bank.IsBankEmpty()) {
		std::cout << "���� ����." << std::endl;
		return;
	}
	int branch_id{};
	std::cout << "������� id ���������� �������:" << std::endl;
	std::cin >> branch_id;
	bank.RemoveBranch(branch_id);
}

void Menu::HandleRemoveCashMachine(Bank& bank) {
	if (bank.IsBankEmpty()) {
		std::cout << "���� ����." << std::endl;
		return;
	}
	int branch_id{}, cash_machine_id{};
	std::cout << "������� id �������, �� �������� ������ ������� ��������:" << std::endl;
	std::cin >> branch_id;
	std::cout << "������� id ����������:" << std::endl;
	std::cin >> cash_machine_id;
	bank.RemoveCashMachineFromBranch(branch_id, cash_machine_id);
}

void Menu::MenuRunLoop() {
	Bank bank{};
	char command{};
	while (true) {
		PrintMenu();
		HandleCommand(command);
		switch (command) {
			case 'q':
				return;
				break;
			case 'p':
				HandlePrintBank(bank);
				break;
			case 'b':
				HandleAddCashMachine(bank);
				break;
			case 'a':
				HandleAddBranch(bank);
				break;
			case 'r':
				HandleRemoveBranch(bank);
				break;
			case 'i':
				HandleRemoveCashMachine(bank);
				break;
			case 'c':
				HandleSetBankName(bank);
				break;
			case 'd':
				HandleFilePrintBank(bank);
				break;
			default:
				std::cout << "����� ������� ��� � ����, ��������� ����." << std::endl;
		}
	}
}

int Menu::GetNumber() {
	int a{};
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "\n������ �����, ������� �����.\n" << std::endl;
	}
	return a;
}