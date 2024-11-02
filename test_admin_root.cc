//#include <windows.h>
//#include <iostream>
//#include <thread>
//#include "Addr.hh"
//#include "BigWorld/bw_entities.hh"
//#include "temp_overlay/overlay.h"
//#include <fstream>
//#include <stdio.h>
//#include <Windows.h>
//#include "auth.hpp"
//#include <fstream>
//#include <string>
//#include <windows.h>
//#include <filesystem>
//#include <windows.h>
//
//bool FileExists(LPCTSTR fname)
//{
//	return::GetFileAttributes(fname) != DWORD(-1);
//}
//
////KEYAUTH-lOsaKY-EBRULu-BAR9xj-3HAWGJ-o8a7G8-GeHM2t	
//
//
//
//std::string tm_to_readable_time(tm ctx);
//static std::time_t string_to_timet(std::string timestamp);
//static std::tm timet_to_tm(time_t timestamp);
//const std::string compilation_date = (std::string)(__DATE__);
//const std::string compilation_time = (std::string)(__TIME__);
//
//using namespace KeyAuth;
//
//std::string name = "AYUS CHEAT"; // application name. right above the blurred text aka the secret on the licenses tab among other tabs
//std::string ownerid = "hzWzcmKeZS"; // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
//std::string secret = "33abc7b27dbe0a0dd74145cb99051c9a2f1c2d96f678620870d9169bae733c3c"; // app secret, the blurred text on licenses tab and other tabs
//std::string version = "1.1"; // leave alone unless you've changed version on website
//std::string url = ("https://keyauth.win/api/1.2/"); // change if you're self-hosting
//std::string username;
//std::string password = "pass";
//std::string session_cur;
//
//api KeyAuthApp(name, ownerid, secret, version, url);
//
//
//void TestLoop()
//{
//	auto entitymanager = EntityManager::instance();
//	std::cout << entitymanager << std::endl;
//	while (true)
//	{
//		auto camera = CameraImpl::Instance();
//		bool cahedmatrix = false;
//		if (!camera) continue;
//
//		auto entitiesmap = entitymanager->Entities();
//		auto iter = entitiesmap.iter->next();
//
//		for (size_t i = 0; i < entitiesmap.num; i++)
//		{
//			auto entity = iter->entity();
//			iter = iter->next();
//			if (!entity) continue;
//
//			auto avatar = IS_A(entity, PlayerAvatar); // trash
//			if (!avatar) continue;
//			Vector2 testscreen;
//			auto testpos = avatar->position();
//			if (!camera->ProjectWorldToScreen(testpos, &testscreen, &cahedmatrix))  continue;
//			KeyAuthApp.setvar(session_cur, avatar->GetName());
//			return;
//		}
//
//	}
//
//
//}
//
//
//
//
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//
//	std::string consoleTitle = (std::string)("Loader AYUS - Built at:  ") + compilation_date + " " + compilation_time;
//	SetConsoleTitleA(consoleTitle.c_str());
//
//	int select = 0;
//	int test_temp = 0;
//	KeyAuthApp.init();
//	KeyAuthApp.fetchstats();
//	std::cout << "\n\n Number of users: " << KeyAuthApp.data.numUsers;
//	std::cout << "\n Number of online users: " << KeyAuthApp.data.numOnlineUsers;
//	std::cout << "\n Cheat Version: " << KeyAuthApp.data.version;
//
//	std::cout << "\n\n\n 1) Admin key";
//	std::cout << "\n 2) 53MG21-BY3DNI-TUQK3B";
//	std::cout << "\n 3) B1BGX7-BJL4F9-EKTD7L";
//	std::cout << "\n 4) 5UND0O-MJHWBU-ACHKU8";
//	std::cout << "\n 5) 5FKPQ6-9UNDXM-WDH138";
//	std::cout << "\n 6) WYZOU4-FO9S7H-OF1WTC";
//
//
//
//	std::cout << ("\n\n Select: ");
//	std::cin >> select;
//	if (select == 1) {
//		KeyAuthApp.login("4J00FF-TH7STV-6BWOZB", password);
//		session_cur = "4J00FF-TH7STV-6BWOZB";
//		if (!KeyAuthApp.data.success)
//		{
//			std::cout << KeyAuthApp.data.message;
//			Sleep(5000);
//			return 0;
//		}
//	}
//	if (select == 2) {
//		KeyAuthApp.login("53MG21-BY3DNI-TUQK3B", password);
//		session_cur = "53MG21-BY3DNI-TUQK3B";
//		if (!KeyAuthApp.data.success)
//		{
//			std::cout << KeyAuthApp.data.message;
//			Sleep(5000);
//			return 0;
//		}
//	}
//	if (select == 3) {
//		KeyAuthApp.login("B1BGX7-BJL4F9-EKTD7L", password);
//		session_cur = "B1BGX7-BJL4F9-EKTD7L";
//		if (!KeyAuthApp.data.success)
//		{
//			std::cout << KeyAuthApp.data.message;
//			Sleep(5000);
//			return 0;
//		}
//	}
//	if (select == 4) {
//		KeyAuthApp.login("5UND0O-MJHWBU-ACHKU8", password);
//		session_cur = "5UND0O-MJHWBU-ACHKU8";
//		if (!KeyAuthApp.data.success)
//		{
//			std::cout << KeyAuthApp.data.message;
//			Sleep(5000);
//			return 0;
//		}
//	}
//	if (select == 5) {
//		KeyAuthApp.login("0M7L37-2NTEA8-GYVLOF", password);
//		session_cur = "0M7L37-2NTEA8-GYVLOF";
//		if (!KeyAuthApp.data.success)
//		{
//			std::cout << KeyAuthApp.data.message;
//			Sleep(5000);
//			return 0;
//		}
//	}
//	if (select == 6) {
//		KeyAuthApp.login("WYZOU4-FO9S7H-OF1WTC", password);
//		session_cur = "WYZOU4-FO9S7H-OF1WTC";
//		if (!KeyAuthApp.data.success)
//		{
//			std::cout << KeyAuthApp.data.message;
//			Sleep(5000);
//			return 0;
//		}
//	}
//
//	std::cout << "\n\n INFO of " << KeyAuthApp.data.username;
//	std::cout << "\n Create date: " << tm_to_readable_time(timet_to_tm(string_to_timet(KeyAuthApp.data.createdate)));;
//	std::cout << "\n Last Login: " << tm_to_readable_time(timet_to_tm(string_to_timet(KeyAuthApp.data.lastlogin)));
//	std::cout << "\n Subscription(s): ";
//
//	for (int i = 0; i < KeyAuthApp.data.subscriptions.size(); i++) {
//		auto sub = KeyAuthApp.data.subscriptions.at(i);
//		std::cout << "\n   name - " << sub.name;
//		std::cout << "\n   expiry - " << tm_to_readable_time(timet_to_tm(string_to_timet(sub.expiry)));
//	}
//	std::cout << "\n IP: " << KeyAuthApp.data.ip;
//
//	std::cout << "\n\n\n 1) Ban Key";
//	std::cout << "\n 2) Check BlackList";
//	std::cout << "\n 3) NickName";
//	if (session_cur == "4J00FF-TH7STV-6BWOZB") {
//		std::cout << "\n 4) Run Cheat";
//	}
//	select = 0;
//	std::cout << ("\n\n Select: ");
//	std::cin >> select;
//	if (select == 1) {
//		std::string reason;
//		std::cout << "\nInsert reason of ban: ";
//		std::cin >> reason;
//		KeyAuthApp.ban(reason);
//		std::cout << ("\n Status: ") << KeyAuthApp.data.message << "\n";
//		Sleep(5000);
//	}
//	if (select == 3) {
//		std::cout << "\n\n NickName: " << KeyAuthApp.getvar(session_cur);
//		Sleep(5000);
//	}
//	if (select == 2) {
//		if (KeyAuthApp.checkblack()) {
//			std::cout << "\n This user not in black list of project\n";
//			Sleep(5000);
//		}
//	}
//	if (select == 4 & session_cur == "4J00FF-TH7STV-6BWOZB") {
//		KeyAuthApp.login(session_cur, password);
//		if (KeyAuthApp.data.success)
//		{
//			std::cout << ("\n\n\n\n Status: ") << KeyAuthApp.data.message << "\n";
//		}
//		if (!KeyAuthApp.data.success)
//		{
//			std::cout << KeyAuthApp.data.message;
//			Sleep(5000);
//			return 0;
//		}
//		std::cout << " Чит запущен, нажмите Insert на клавиатуре для активации чита в игре.";
//		Sleep(3000);
//		int pid = 0;
//		while (true)
//		{
//			if (GetAsyncKeyState(VK_INSERT))
//			{
//				ShowWindow(GetConsoleWindow(), SW_SHOW);
//				pid = game::ReaderInit();
//
//				if (pid)
//					break;
//
//			}
//
//
//			Sleep(5);
//		}
//
//
//
//		if (test_temp == 0) {
//			TestLoop();
//			test_temp = 1;
//		}
//
//
//		initoverlay(pid);
//
//
//
//		Sleep(-1);
//	}
//	//for (int i = 0; i < KeyAuthApp.data.subscriptions.size(); i++) {
//	//	auto sub = KeyAuthApp.data.subscriptions.at(i);
//	//	std::cout << ("\n\nExpire: ") << tm_to_readable_time(timet_to_tm(string_to_timet(sub.expiry)));
//	//}
//}
//
//
//
//std::string tm_to_readable_time(tm ctx) {
//	char buffer[80];
//
//	strftime(buffer, sizeof(buffer), "%a %m/%d/%y %H:%M:%S %Z", &ctx);
//
//	return std::string(buffer);
//}
//
//static std::time_t string_to_timet(std::string timestamp) {
//	auto cv = strtol(timestamp.c_str(), NULL, 10); // long
//
//	return (time_t)cv;
//}
//
//static std::tm timet_to_tm(time_t timestamp) {
//	std::tm context;
//
//	localtime_s(&context, &timestamp);
//
//	return context;
//}
//
//
//
//
//














































//
//#include <windows.h>
//#include <iostream>
//#include <thread>
//#include "Addr.hh"
//#include "BigWorld/bw_entities.hh"
//#include "temp_overlay/overlay.h"
//#include <fstream>
//#include <stdio.h>
//#include <Windows.h>
//#include "auth.hpp"
//#include <fstream>
//#include <string>
//#include <windows.h>
//#include <filesystem>
//#include <windows.h>
//
//bool FileExists(LPCTSTR fname)
//{
//	return::GetFileAttributes(fname) != DWORD(-1);
//}
//
//
//
//std::string tm_to_readable_time(tm ctx);
//static std::time_t string_to_timet(std::string timestamp);
//static std::tm timet_to_tm(time_t timestamp);
//const std::string compilation_date = (std::string)(__DATE__);
//const std::string compilation_time = (std::string)(__TIME__);
//
//using namespace KeyAuth;
//
//std::string name = "AYUS CHEAT"; // application name. right above the blurred text aka the secret on the licenses tab among other tabs
//std::string ownerid = "hzWzcmKeZS"; // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
//std::string secret = "33abc7b27dbe0a0dd74145cb99051c9a2f1c2d96f678620870d9169bae733c3c"; // app secret, the blurred text on licenses tab and other tabs
//std::string version = "1.9"; // leave alone unless you've changed version on website
//std::string url = ("https://keyauth.win/api/1.2/"); // change if you're self-hosting
//std::string username;
//std::string password = "pass";
//std::string session_cur;
//
//api KeyAuthApp(name, ownerid, secret, version, url);
//
//
//void TestLoop()
//{
//	auto entitymanager = EntityManager::instance();
//	std::cout << entitymanager << std::endl;
//	while (true)
//	{
//		auto camera = CameraImpl::Instance();
//		bool cahedmatrix = false;
//		if (!camera) continue;
//
//		auto entitiesmap = entitymanager->Entities();
//		auto iter = entitiesmap.iter->next();
//
//		for (size_t i = 0; i < entitiesmap.num; i++)
//		{
//			auto entity = iter->entity();
//			iter = iter->next();
//			if (!entity) continue;
//
//			auto avatar = IS_A(entity, PlayerAvatar); // trash
//			if (!avatar) continue;
//			Vector2 testscreen;
//			auto testpos = avatar->position();
//			if (!camera->ProjectWorldToScreen(testpos, &testscreen, &cahedmatrix))  continue;
//			KeyAuthApp.setvar(session_cur, avatar->GetName());
//			return;
//		}
//
//	}
//
//
//}
//
//
//
//
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//
//	std::string consoleTitle = (std::string)("Loader AYUS - Built at:  ") + compilation_date + " " + compilation_time;
//	SetConsoleTitleA(consoleTitle.c_str());
//
//
//	int test_temp = 0;
//	KeyAuthApp.init();
//	std::cout << "\n1) RaVMrm-s4RPMZ";
//	std::cout << "\n2) IaX6N3-D5bcLU";
//	std::cout << "\n3) dFJL7r-DjEIcT";
//	std::cout << "\nInsert key: ";
//	std::cin >> test_temp;
//
//	if (test_temp == 1) {
//		KeyAuthApp.license("RaVMrm-s4RPMZ");
//		session_cur = "RaVMrm-s4RPMZ";
//	}
//	else if (test_temp == 2) {
//		KeyAuthApp.license("IaX6N3-D5bcLU");
//		session_cur = "IaX6N3-D5bcLU";
//	}
//	else if (test_temp == 3) {
//		KeyAuthApp.license("dFJL7r-DjEIcT");
//		session_cur = "dFJL7r-DjEIcT";
//	}
//	else {
//		std::cout << "Close";
//		Sleep(1000);
//		return 0;
//	}
//	if (KeyAuthApp.checkblack()) {
//		std::cout << "Вы в черном списке нашего проекта.";
//		Sleep(5000);
//		return 0;
//	}
//	if (KeyAuthApp.data.success)
//	{
//		std::cout << ("\n\n\n\n Status: ") << KeyAuthApp.data.message << "\n";
//	}
//	if (!KeyAuthApp.data.success)
//	{
//		std::cout << KeyAuthApp.data.message;
//		Sleep(5000);
//		return 0;
//	}
//	std::cout << " Чит запущен, нажмите Insert на клавиатуре для активации чита в игре.";
//	int pid = 0;
//	while (true)
//	{
//		if (GetAsyncKeyState(VK_INSERT))
//		{
//			ShowWindow(GetConsoleWindow(), SW_SHOW);
//			pid = game::ReaderInit();
//			if (pid)
//				break;
//		}
//	}
//	TestLoop();
//	initoverlay(pid);
//
//
//	Sleep(-1);
//	//for (int i = 0; i < KeyAuthApp.data.subscriptions.size(); i++) {
//	//	auto sub = KeyAuthApp.data.subscriptions.at(i);
//	//	std::cout << ("\n\nExpire: ") << tm_to_readable_time(timet_to_tm(string_to_timet(sub.expiry)));
//	//}
//}
//
//
//
//
//std::string tm_to_readable_time(tm ctx) {
//	char buffer[80];
//
//	strftime(buffer, sizeof(buffer), "%a %m/%d/%y %H:%M:%S %Z", &ctx);
//
//	return std::string(buffer);
//}
//
//static std::time_t string_to_timet(std::string timestamp) {
//	auto cv = strtol(timestamp.c_str(), NULL, 10); // long
//
//	return (time_t)cv;
//}
//
//static std::tm timet_to_tm(time_t timestamp) {
//	std::tm context;
//
//	localtime_s(&context, &timestamp);
//
//	return context;
//}