#include <windows.h>
#include <iostream>
#include <thread>
#include "Addr.hh"
#include "BigWorld/bw_entities.hh"
#include "temp_overlay/overlay.h"
#include <fstream>
#include <stdio.h>
#include <Windows.h>
#include "auth.hpp"
#include <fstream>
#include <string>
#include <windows.h>
#include <filesystem>
#include <windows.h>


bool FileExists(LPCTSTR fname)
{
	return::GetFileAttributes(fname) != DWORD(-1);
}



std::string tm_to_readable_time(tm ctx);
static std::time_t string_to_timet(std::string timestamp);
static std::tm timet_to_tm(time_t timestamp);
const std::string compilation_date = (std::string)(__DATE__);
const std::string compilation_time = (std::string)(__TIME__);

using namespace KeyAuth;

std::string name = "FULLPACK_SO"; // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = "hzWzcmKeZS"; // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = "3f93382f1606df878041278f0b10dd7c1adfacba4169a9c4a6e356e6ac0c25ac"; // app secret, the blurred text on licenses tab and other tabs
std::string version = "1.4"; // leave alone unless you've changed version on website
std::string url = ("https://keyauth.win/api/1.2/"); // change if you're self-hosting
std::string username;
std::string password = "pass";
std::string session_cur;
char buff[50];


api KeyAuthApp(name, ownerid, secret, version, url);


void TestLoop()
{
	auto entitymanager = EntityManager::instance();
	std::cout << entitymanager << std::endl;
	while (true)
	{
		auto camera = CameraImpl::Instance();
		bool cahedmatrix = false;
		if (!camera) continue;

		auto entitiesmap = entitymanager->Entities();
		auto iter = entitiesmap.iter->next();

		for (size_t i = 0; i < entitiesmap.num; i++)
		{
			auto entity = iter->entity();
			iter = iter->next();
			if (!entity) continue;

			auto avatar = IS_A(entity, PlayerAvatar); // trash
			if (!avatar) continue;
			Vector2 testscreen;
			auto testpos = avatar->position();
			KeyAuthApp.setvar(session_cur, avatar->GetName());
			return;
		}

	}


}



std::string randomStrGen(int length) {
	static std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
	std::string result;
	result.resize(length);

	srand(time(NULL));
	for (int i = 0; i < length; i++)
		result[i] = charset[rand() % charset.length()];

	return result;
}



int main()
{
	setlocale(LC_ALL, "Russian");

	std::string consoleTitle = (std::string)(randomStrGen(8));
	SetConsoleTitleA(consoleTitle.c_str());


	//int test_temp = 0;
	//KeyAuthApp.init();

	//std::ifstream fin("key.txt"); // ������� ���� ��� ������

	//fin >> session_cur; // ������� ������ ����� �� �����

	//KeyAuthApp.license(session_cur);
	//if (KeyAuthApp.checkblack()) {
	//	std::cout << "�� � ������ ������ ������ �������.";
	//	Sleep(5000);
	//	return 0;
	//}
	//if (KeyAuthApp.data.success)
	//{
	//	system("EAC_off.exe");
	//	for (int i = 0; i < KeyAuthApp.data.subscriptions.size(); i++) {
	//		auto sub = KeyAuthApp.data.subscriptions.at(i);
	//		std::cout << "\n ��������: " << sub.name;
	//		std::cout << "\n ����� ��: " << tm_to_readable_time(timet_to_tm(string_to_timet(sub.expiry)));
	//	}
	//}
	//if (!KeyAuthApp.data.success)
	//{
	//	
	//	fin.close();
	//	std::ofstream MyFile("key.txt");
	//	std::cout << "\nInsert key: ";
	//	std::cin >> session_cur;
	//	KeyAuthApp.license(session_cur);
	//	if (KeyAuthApp.checkblack()) {
	//		std::cout << "�� � ������ ������ ������ �������.";
	//		Sleep(5000);
	//		return 0;
	//	}
	//	if (KeyAuthApp.data.success)
	//	{
	//		MyFile << session_cur;
	//		MyFile.close();
	//		std::cout << "�������! ������������� ������";
	//		Sleep(5000);
	//		return 0;
	//	}
	//	if (!KeyAuthApp.data.success)
	//	{
	//		std::cout << KeyAuthApp.data.message;
	//		Sleep(5000);
	//		return 0;
	//	}
	//}
	//fin.close();

	std::cout << " \n��� �������, ������� Insert �� ���������� ��� ��������� ���� � ����.";

	int pid = 0;

	while (true)
	{
		if (GetAsyncKeyState(VK_INSERT))
		{
			//ShowWindow(GetConsoleWindow(), SW_HIDE);
			pid = game::ReaderInit();
			if (!pid) {
				system("taskkill /F /T /IM sogame.exe");
				MessageBox(GetActiveWindow(), "I can't find DBVM. \nPlease open this \nCheat Engine.exe - > Settings - > About CE - > Your system supports DBVM", "DBVM", MB_ICONERROR);
				exit(1);
			}
			if (pid)
				break;
		}
	}
	//TestLoop();
	initoverlay(pid);


	Sleep(-1);
	//for (int i = 0; i < KeyAuthApp.data.subscriptions.size(); i++) {
	//	auto sub = KeyAuthApp.data.subscriptions.at(i);
	//	std::cout << ("\n\nExpire: ") << tm_to_readable_time(timet_to_tm(string_to_timet(sub.expiry)));
	//}
}




std::string tm_to_readable_time(tm ctx) {
	char buffer[80];

	strftime(buffer, sizeof(buffer), "%a %m/%d/%y %H:%M:%S %Z", &ctx);

	return std::string(buffer);
}

static std::time_t string_to_timet(std::string timestamp) {
	auto cv = strtol(timestamp.c_str(), NULL, 10); // long

	return (time_t)cv;
}

static std::tm timet_to_tm(time_t timestamp) {
	std::tm context;

	localtime_s(&context, &timestamp);

	return context;
}