#include "Menu.h"

void Menu::PrintMenu() {
	std::cout << "Введите нужную команду:" << std::endl;
	std::cout << "[Q] - выйти из программы." << std::endl;
	std::cout << "[P] - вывести содержимое банка." << std::endl;
	std::cout << "[F] - выгрузить содержимое банка из файла." << std::endl;  ///
	std::cout << "[D] - загрузить содержимое банка в файл." << std::endl;  ///
	std::cout << "[B] - добавить новый банкомат." << std::endl;
	std::cout << "[A] - добавить новый филиал." << std::endl;
	std::cout << "[R] - удалить филиал по id." << std::endl;
	std::cout << "[I] - удалить банкомат из филиала с опредленным id." << std::endl;
	std::cout << "[N] - найти номер филиала в банке по его id." << std::endl;
	std::cout << "[U] - найти номер банкомата в филиале с определенным id." << std::endl;
	std::cout << "[C] - изменить имя банка." << std::endl;
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
		std::cerr << "Не удалось открыть файл вывода." << std::endl;
		return;
	}
	bank.PrintBankF(fp);
	fclose(fp);
}

void Menu::HandleSetBankName(Bank &bank) {
	std::string bank_name{};
	std::cout << "Введите имя банка:" << std::endl;
	std::cin >> bank_name;
	bank.SetName(bank_name);
}

void Menu::HandleAddBranch(Bank& bank) {
	int new_branch_id{};
	std::cout << "Введите id нового филиала:" << std::endl;
	new_branch_id = GetNumber();
	bank.AddBranch(new_branch_id);
}

void Menu::HandleAddCashMachine(Bank& bank) {
	if (bank.IsBankEmpty()) {
		std::cout << "Банк пуст." << std::endl;
		return;
	}
	int branch_id{};
	int cash_machine_id{};
	std::string adress{};
	std::cout << "Введите id филиала, в который хотите добавить банкомат:" << std::endl;
	branch_id = GetNumber();
	std::cout << "Введите id банкомата и его адрес:" << std::endl;
	cash_machine_id = GetNumber();
	std::cin >> adress;
	bank.AddCashMachineToBranch(branch_id, cash_machine_id, adress);
}

void Menu::HandleRemoveBranch(Bank& bank) {
	if (bank.IsBankEmpty()) {
		std::cout << "Банк пуст." << std::endl;
		return;
	}
	int branch_id{};
	std::cout << "Введите id удаляемого филиала:" << std::endl;
	std::cin >> branch_id;
	bank.RemoveBranch(branch_id);
}

void Menu::HandleRemoveCashMachine(Bank& bank) {
	if (bank.IsBankEmpty()) {
		std::cout << "Банк пуст." << std::endl;
		return;
	}
	int branch_id{}, cash_machine_id{};
	std::cout << "Введите id филиала, из которого хотите удалить банкомат:" << std::endl;
	std::cin >> branch_id;
	std::cout << "Введите id банктомата:" << std::endl;
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
				std::cout << "Такой команды нет в меню, повторите ввод." << std::endl;
		}
	}
}

int Menu::GetNumber() {
	int a{};
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "\nОшибка ввода, введите число.\n" << std::endl;
	}
	return a;
}