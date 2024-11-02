#include <windows.h>
#include <iostream>
#include <tlhelp32.h>
#include <psapi.h>
#include <dwmapi.h>
#include <d3d9.h>
#include <string>
#pragma comment (lib, "d3dx9.lib")
#include "menu_vars.hh"
#include "Imgui/imgui.h"
#include "Imgui/imgui_impl_dx9.h"
#include "Imgui/imgui_impl_win32.h"	
#include "../BigWorld/bw_entities.hh"
#include "Direct3d/d3dx9core.h"
#include <vector>
#include <math.h>
#include <cmath>
#include <fstream>
#include <winbase.h>
#include <windows.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <vector>
#include "wtypes.h"
#include <iostream>
#include <screensize.h>
#include "../Addr.hh"
#include "../common/dbvm.h"

using namespace std;


int tabb = 1;


// Get the horizontal and vertical screen sizes in pixel
void GetDesktopResolution(int& horizontal, int& vertical)
{
	RECT desktop;
	// Get a handle to the desktop window
	const HWND hDesktop = GetDesktopWindow();
	// Get the size of screen to the variable desktop
	GetWindowRect(hDesktop, &desktop);
	// The top left corner will have coordinates (0,0)
	// and the bottom right corner will have coordinates
	// (horizontal, vertical)
	horizontal = desktop.right;
	vertical = desktop.bottom;
}

using namespace std;

bool freeze;





void disable_off(bool state) {
	espent::esp_nick = state;
	espent::esp_radar = state;
	espent::esp_clanName = state;
	espent::esp_creature_live = state;
	espent::esp_creature_dead = state;
	espent::esp_npc_name = state;
	espent::esp_anomaly = state;
	espent::esp_Container = state;
	espent::esp_artefact = state;
	menu_vars2::aim_player = state;
	menu_vars2::aim_clan_player = state;
	menu_vars3::aim_creature = state;
	espent::esp_creature_distance = state;
	espent::esp_people_distance = state;
	espent::esp_npc_distance = state;
	espent::esp_anomaly_distance = state;
	espent::esp_container_distance = state;
	menu_vars4::aim_radius_p = state;
	menu_vars4::aim_radius_n = state;
	menu_vars4::aim_radius_c = state;
	menu_vars4::esp_kills_people = state;
	menu_vars4::esp_karma_people = state;
	menu_vars4::esp_cantakedamage_people = state;
	menu_vars4::esp_accesslevel_people = state;
	menu_vars4::esp_blacklist_people = state;
	exploit::freeze_packets = state;
	exploit::magnit_anomaly = state;
	snapline_menu::anomaly_snapline = state;
	snapline_menu::creature_snapline = state;
	snapline_menu::players_snapline = state;
	snapline_menu::npc_snapline = state;
	snapline_menu::artefact_snapline = state;
	snapline_menu::container_snapline = state;

}






std::vector<int> checked_anomalies;
std::vector<int> artefacts_in_anomalies;
int farm_obj_int = 0;
int farm_obj_dead_int = 0;
int farm_obj_count_health = 0;
int farm_obj_count_weapon = 0;
int farm_obj_f_temp_isnt_looted = 0;
int farm_obj_f_temp_is_looted = 0;
std::string player_name;
int temp_anomaly_magnit = 0;
int temp_tp;
std::string tp_people_name;
std::string tp_name_mob;
int tp_distance_mob;
int temp_artefacts_in_anomalies;


void speed()	
{
	//if (GetAsyncKeyState(VK_CAPITAL)) {
	//	if (menu_vars4::speedhack_legit) {
	//		if (!GetAsyncKeyState(0x57)) {
	//			return;
	//		}
	//	}
	//	//std::stringstream stream;
	//	//stream << std::hex << your_int;
	//	//std::string result(stream.str());
	//	//read<int>(read<int>(140697452093720))
	//	//std::cout<<std::stoi(TEST/*a hexadecimal string*/, nullptr, 16 /*hexadecimal*/);
	//	DWORD addr = read<int>(read<int>(140697452093720)) + 0x294;//здесь адрес из Cheat Engine, обратите внимание я поставил впереди 0х и потом адрес
	//	DWORD pid;//pid процесса
	//	float data;//эту переменную я буду использовать для записи и чтения
	//	

	//	HWND hwd = FindWindow(0, "SO official game client ");
	//	cout << hwd;
	//	GetWindowThreadProcessId(hwd, &pid);
	//	if (!hwd) {
	//		std::cout << "Couldn't open this window!" << endl;
	//		//printf("oppa");
	//		system("pause");
	//		return;
	//	}
	//	HANDLE hnd = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
	//	if (!hnd) {
	//		std::cout << "Error!" << endl;
	//		system("pause");
	//	}
	//	ReadProcessMemory(hnd, (LPVOID)addr, &data, sizeof(float), 0);
	//	std::cout << read<int>(read<int>(140697452093720)) << " - " << data << endl;
	//	data = menu_vars4::speed_sh;
	//	WriteProcessMemory(hnd, (LPVOID)addr, &data, sizeof(int), 0);
	//}


	//DETECTED FUNCTION
	//auto drawlist = ImGui::GetForegroundDrawList();
	//auto entitymanager = EntityManager::instance();
	//auto camera = CameraImpl::Instance();
	//if (!camera) return;

	//auto entitiesmap = entitymanager->Entities();
	//auto iter = entitiesmap.iter->next();
	//bool cahedmatrix = false;
	//for (size_t i = 0; i < entitiesmap.num; i++)
	//{
	//	//cout << iter->entity()->ob_type()->fullname() << endl;
	//	auto entity = iter->entity();
	//	iter = iter->next();

	//	//cout << iter->entity()->ob_type()->tp_name() << endl;

	//	if (!entity) continue;

	//	auto avatar2 = IS_A(entity, PlayerAvatar);
	//	//avatar2->dump();
	//	Vector2 testscreen;
	//	if (!avatar2) continue;
	//	if (!avatar2->is_enter()) {
	//		temp_tp = 0;
	//		return;
	//	}
	//	if (avatar2->is_dead()) {
	//		if (GetAsyncKeyState(VK_CAPITAL)) {
	//			if (temp_tp == 0) {
	//				for (int i = 0; i < 13000000; i++) {
	//					avatar2->position_change(Vector3{ avatar2->position().x, avatar2->position().y - 100, avatar2->position().z });
	//				}
	//				temp_tp = 1;
	//				return;
	//			}
	//			if (temp_tp == 1) {
	//				system("taskkill /F /T /IM sogame.exe");
	//				MessageBox(GetActiveWindow(), "You can't use teleport twice for a row. \nPlease rejoin to the world for again using", "WARNING TELEPORT", MB_ICONERROR);
	//				exit(1);
	//			}
	//		}
	//	}
	//}
}


# define M_PI           3.14159265358979323846

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "dwmapi.lib")
bool CreateConsole = true;
constexpr auto menu_key = VK_INSERT;

struct CurrentProcess {
	DWORD ID;
	HANDLE Handle;
	HWND Hwnd;
	WNDPROC WndProc;
	int WindowWidth;
	int WindowHeight;
	int WindowLeft;
	int WindowRight;
	int WindowTop;
	int WindowBottom;
	LPCSTR Title;
	LPCSTR ClassName;
	LPCSTR Path;
}Process;
struct OverlayWindow {
	WNDCLASSEX WindowClass;
	HWND Hwnd;
	LPCSTR Name;
}Overlay;
struct DirectX9Interface {
	IDirect3D9Ex* IDirect3D9 = NULL;
	IDirect3DDevice9Ex* pDevice = NULL;
	D3DPRESENT_PARAMETERS pParameters = { NULL };
	MARGINS Margin = { -1 };
	MSG Message = { NULL };

}DirectX9;

Vector3 player_pos;
int player_count;
int creature_count;
int anomaly_count;
int container_count;
int npc_count;
std::string temp_player_aim = "";
int temp_aim = 0;
int temp_freeze = 0;
int p_current_key;
int c_current_key;
int n_current_key;
int c_aim_key;
int p_aim_key;
int n_aim_key;
int min_dist;
int min_dist_dead;
int min_dist_anomaly;
int temp_checked_anomaly;
int temp_checked_magnit_anomaly;
int temp_creature_aim;
Vector3 min_dist_anomaly_pos;
//long py_string_hash(const char* a)
//{
//	auto len = strlen(a);
//	auto lencopy = len;
//	auto p = (unsigned char*)a;
//	long x = *p << 7;
//	while (--len >= 0)
//		x = (1000003 * x) ^ *p++;
//	x ^= lencopy;
//	if (x == -1)
//		x = -2;
//	return x;
//}


//
//long py_string_hash(std::string a)
//{
//	auto len = a.size();
//	auto lencopy = len;
//	auto p = (unsigned char*)a.c_str();
//	long x = *p << 7;
//	while (--len >= 0)
//		x = (1000003 * x) ^ *p++;
//	x ^= lencopy;
//	if (x == -1)
//		x = -2;
//	return x;
//}

int GetDistance(auto Coords1, auto Coords2)
{
	const auto Difference = (Coords1.x - Coords2.x) * (Coords1.x - Coords2.x) + (Coords1.y - Coords2.y) * (Coords1.y - Coords2.y) + (Coords1.z - Coords2.z) * (Coords1.z - Coords2.z);
	return sqrt(Difference);
}



void AimAtPos(float x, float y, float AimSpeed, float smooth)
{
	//By fredaikis
	float ScreenCenterX = (horizontal / 2);
	float ScreenCenterY = (vertical / 2);
	float TargetX = 0;
	float TargetY = 0;

	if (x != 0)
	{
		if (x > ScreenCenterX)
		{
			TargetX = -(ScreenCenterX - x);
			TargetX /= AimSpeed;
			if (TargetX + ScreenCenterX > ScreenCenterX * 2) TargetX = 0;
		}

		if (x < ScreenCenterX)
		{
			TargetX = x - ScreenCenterX;
			TargetX /= AimSpeed;
			if (TargetX + ScreenCenterX < 0) TargetX = 0;
		}
	}
	if (y != 0)
	{
		if (y > ScreenCenterY)
		{
			TargetY = -(ScreenCenterY - y);
			TargetY /= AimSpeed;
			if (TargetY + ScreenCenterY > ScreenCenterY * 2) TargetY = 0;
		}

		if (y < ScreenCenterY)
		{
			TargetY = y - ScreenCenterY;
			TargetY /= AimSpeed;
			if (TargetY + ScreenCenterY < 0) TargetY = 0;
		}
	}
	if (!smooth)
	{
		mouse_event(0x0001, (int)(TargetX), (int)(TargetY), NULL, 0);
		return;
	}
	TargetX /= 10;
	TargetY /= 10;
	if (abs(TargetX) < 1)
	{
		if (TargetX > 0)
		{
			TargetX = 1;
		}
		if (TargetX < 0)
		{
			TargetX = -1;
		}
	}
	if (abs(TargetY) < 1)
	{
		if (TargetY > 0)
		{
			TargetY = 1;
		}
		if (TargetY < 0)
		{
			TargetY = -1;
		}
	}
	mouse_event(0x0001, (int)TargetX, (int)TargetY, NULL, 0);
}

void auto_aim(Vector3 player_position, Vector3 avatar_position) {
	//menu_vars2::size_p = 45 + menu_vars2::aim_high_circle + GetDistance(player_position, avatar_position) / 100 * 0.4;

	menu_vars2::aim_high = menu_vars2::aim_high_circle * 100 / (GetDistance(player_position, avatar_position)+0.1);
	
	if (GetDistance(player_position, avatar_position) < 3) {
		menu_vars2::size_p = 50 + menu_vars2::aim_high_circle + GetDistance(player_position, avatar_position) / 100 * 0.4;
		menu_vars2::aim_high = 325;
	}
	if (GetDistance(player_position, avatar_position) >= 3 && GetDistance(player_position, avatar_position) < 5) {
		menu_vars2::size_p = 50 + menu_vars2::aim_high_circle + GetDistance(player_position, avatar_position) / 100 * 0.4;
		menu_vars2::aim_high = 245;
	}
	if (GetDistance(player_position, avatar_position) >= 5 && GetDistance(player_position, avatar_position) <= 8) {
		menu_vars2::size_p = 50 + menu_vars2::aim_high_circle + GetDistance(player_position, avatar_position) / 100 * 0.4;
		menu_vars2::aim_high = 205;
	}
	if (GetDistance(player_position, avatar_position) > 8 && GetDistance(player_position, avatar_position) <= 10) {
		menu_vars2::size_p = 50 + menu_vars2::aim_high_circle + GetDistance(player_position, avatar_position) / 100 * 0.4;
		menu_vars2::aim_high = 155 + menu_vars2::aim_high_circle;
	}
	
	if (GetDistance(player_position, avatar_position) >= 10 && GetDistance(player_position, avatar_position) < 15) {
		menu_vars2::size_p = 50 + menu_vars2::aim_high_circle + GetDistance(player_position, avatar_position) / 100 * 0.4;
		menu_vars2::aim_high = 135 + menu_vars2::aim_high_circle;
	}
	/*
	if (GetDistance(player_position, avatar_position) >= 15 && GetDistance(player_position, avatar_position) < 20) {
		menu_vars2::aim_high = 95 + menu_vars2::aim_high_circle;
	}
	if (GetDistance(player_position, avatar_position) >= 20 && GetDistance(player_position, avatar_position) < 30) {
		menu_vars2::aim_high = 63 + menu_vars2::aim_high_circle;
	}
	if (GetDistance(player_position, avatar_position) >= 30 && GetDistance(player_position, avatar_position) < 40) {
		menu_vars2::aim_high = 55 + menu_vars2::aim_high_circle;
	}
	if (GetDistance(player_position, avatar_position) >= 40 && GetDistance(player_position, avatar_position) < 50) {
		menu_vars2::aim_high = 47 + menu_vars2::aim_high_circle;
	}
	if (GetDistance(player_position, avatar_position) >= 50 && GetDistance(player_position, avatar_position) < 60) {
		menu_vars2::aim_high = 39 + menu_vars2::aim_high_circle;
	}
	if (GetDistance(player_position, avatar_position) >= 60 && GetDistance(player_position, avatar_position) < 70) {
		menu_vars2::aim_high = 31 + menu_vars2::aim_high_circle;
	}
	if (GetDistance(player_position, avatar_position) >= 70 && GetDistance(player_position, avatar_position) < 80) {
		menu_vars2::aim_high = 25 + menu_vars2::aim_high_circle;
	}
	if (GetDistance(player_position, avatar_position) >= 80 && GetDistance(player_position, avatar_position) < 90) {
		menu_vars2::aim_high = 19 + menu_vars2::aim_high_circle;
	}
	if (GetDistance(player_position, avatar_position) >= 90 && GetDistance(player_position, avatar_position) < 100) {
		menu_vars2::aim_high = 19 + menu_vars2::aim_high_circle;
	}
	if (GetDistance(player_position, avatar_position) >= 100 && GetDistance(player_position, avatar_position) < 110) {
		menu_vars2::aim_high = 19 + menu_vars2::aim_high_circle;
	}
	if (GetDistance(player_position, avatar_position) >= 110 && GetDistance(player_position, avatar_position) < 120) {
		menu_vars2::aim_high = 18 + menu_vars2::aim_high_circle;
	}
	if (GetDistance(player_position, avatar_position) >= 120 && GetDistance(player_position, avatar_position) < 130) {
		menu_vars2::aim_high = 18 + menu_vars2::aim_high_circle;
	}
	if (GetDistance(player_position, avatar_position) >= 130 && GetDistance(player_position, avatar_position) < 140) {
		menu_vars2::aim_high = 17 + menu_vars2::aim_high_circle;
	}
	if (GetDistance(player_position, avatar_position) >= 140 && GetDistance(player_position, avatar_position) < 150) {
		menu_vars2::aim_high = 17 + menu_vars2::aim_high_circle;
	}
	if (GetDistance(player_position, avatar_position) >= 150 && GetDistance(player_position, avatar_position) < 160) {
		menu_vars2::aim_high = 15 + menu_vars2::aim_high_circle;
	}
	if (GetDistance(player_position, avatar_position) >= 160 && GetDistance(player_position, avatar_position) < 170) {
		menu_vars2::aim_high = 13 + menu_vars2::aim_high_circle;
	}
	if (GetDistance(player_position, avatar_position) >= 170 && GetDistance(player_position, avatar_position) < 180) {
		menu_vars2::aim_high = 11 + menu_vars2::aim_high_circle;
	}
	if (GetDistance(player_position, avatar_position) >= 180 && GetDistance(player_position, avatar_position) < 190) {
		menu_vars2::aim_high = 10 + menu_vars2::aim_high_circle;
	}
	if (GetDistance(player_position, avatar_position) >= 190 && GetDistance(player_position, avatar_position) < 200) {
		menu_vars2::aim_high = 10 + menu_vars2::aim_high_circle;
	}*/
}



void SwitchON() {
	std::string cmd = "powershell \"New-NetQosPolicy -Name \"GyzaoV2\" -AppPathNameMatchCondition \"sogame.exe\" -ThrottleRateActionBitsPerSecond \"" + std::to_string(exploit::kilobyte_rate) + "\"kb -PolicyStore ActiveStore\"";
	WinExec(cmd.c_str(), 0);
	return;
}
void SwitchOFF() {
	std::string cmd2 = "powershell Remove-NetQosPolicy -PolicyStore ActiveStore -Confirm:$false";
	WinExec(cmd2.c_str(), 0);
}


bool check_key(int key_current) {
	if (key_current == 0) {
		if (GetAsyncKeyState(0x72) != 0) {
			return 1;
		}
		if (GetAsyncKeyState(0x72) == 0) {
			return 0;
		}
	}
	if (key_current == 1) {
		if (GetAsyncKeyState(0x73) != 0) {
			return 1;
		}
		if (GetAsyncKeyState(0x73) == 0) {
			return 0;
		}
	}
	if (key_current == 2) {
		if (GetAsyncKeyState(0x06) != 0) {
			return 1;
		}
		if (GetAsyncKeyState(0x06) == 0) {
			return 0;
		}
	}
	if (key_current == 3) {
		if (GetAsyncKeyState(0x05) != 0) {
			return 1;
		}
		if (GetAsyncKeyState(0x05) == 0) {
			return 0;
		}
	}
	if (key_current == 4) {
		if (GetAsyncKeyState(0x02) != 0) {
			return 1;
		}
		if (GetAsyncKeyState(0x02) == 0) {
			return 0;
		}
	}
}

bool remove_line(const char* filename, size_t index) {
	std::vector<std::string> vec;
	std::ifstream file(filename);
	if (file.is_open())
	{
		std::string str;
		while (std::getline(file, str))
			vec.push_back(str);
		file.close();
		if (vec.size() < index)
			return false;
		vec.erase(vec.begin() + index);
		std::ofstream outfile(filename);
		if (outfile.is_open())
		{
			std::copy(vec.begin(), vec.end(),
				std::ostream_iterator<std::string>(outfile, "\n"));
			outfile.close();
			return true;
		}
		return false;
	}
	return false;
}

void PlayerAvatar_func() {
	auto entitymanager = EntityManager::instance();
	auto camera = CameraImpl::Instance();
	if (!camera) return;

	auto entitiesmap = entitymanager->Entities();
	auto iter = entitiesmap.iter->next();
	bool cahedmatrix = false;
	for (size_t i = 0; i < entitiesmap.num; i++)
	{
		//cout << iter->entity()->ob_type()->fullname() << endl;
		auto entity = iter->entity();
		iter = iter->next();

		//if (iter->entity()->ob_type()->tp_name() != "DrawWell")
		//if (iter->entity()->ob_type()->tp_name() != "AvatarDummy")
		//if (iter->entity()->ob_type()->tp_name() != "Creature")
		//	if (iter->entity()->ob_type()->tp_name() != "Avatar")
		//		if (iter->entity()->ob_type()->tp_name() != "NPC")
		//			if (iter->entity()->ob_type()->tp_name() != "PostProcessZone")
		//				if (iter->entity()->ob_type()->tp_name() != "PlayerAvatar")
		//					if (iter->entity()->ob_type()->tp_name() != "Anomaly")
		//						if (iter->entity()->ob_type()->tp_name() != "ObjectInfo")
		//							if (iter->entity()->ob_type()->tp_name() != "QuestEntity")
		//								if (iter->entity()->ob_type()->tp_name() != "DrawWell")
		//									if (iter->entity()->ob_type()->tp_name() != "ClientTrigger")
		//										if (iter->entity()->ob_type()->tp_name() != "SoundNode")
		//											if (iter->entity()->ob_type()->tp_name() != "SoundRainNode")
		//												if (iter->entity()->ob_type()->tp_name() != "ClientTestTriggerTime")
		//													if (iter->entity()->ob_type()->tp_name() != "TriggerObject")
		//														if (iter->entity()->ob_type()->tp_name() != "ForestSoundNode")
		//cout << iter->entity()->ob_type()->tp_name() << endl;

		if (!entity) continue;

		auto avatar2 = IS_A(entity, PlayerAvatar);

		if (!avatar2) {
			continue;
		}

		//avatar2->dump();


		if (avatar2) {
			auto avatar2pos = avatar2->position();
			if (exploit::no_clip) {
				if (GetAsyncKeyState(VK_F8)) {
					camera->CameraPosChange();
				}
			}
			//std::cout << avatar2pos.x << std::endl;
			// 
			// DETECTED FUNCTION
			//if (exploit::no_clip) {
			//	if (GetAsyncKeyState(0x57) & GetAsyncKeyState(VK_F8)) {
			//		for (int i = 0; i < 13000000; i++) {
			//			avatar2->position_change(Vector3{ player_pos.x + exploit::no_clip_distance, player_pos.y, player_pos.z });
			//		}
			//		return;
			//	}
			//	if (GetAsyncKeyState(0x53) & GetAsyncKeyState(VK_F8)) {
			//		for (int i = 0; i < 13000000; i++) {
			//			avatar2->position_change(Vector3{ player_pos.x - exploit::no_clip_distance, player_pos.y, player_pos.z });
			//		}
			//		return;
			//	}
			//	if (GetAsyncKeyState(0x41) & GetAsyncKeyState(VK_F8)) {
			//		for (int i = 0; i < 13000000; i++) {
			//			avatar2->position_change(Vector3{ player_pos.x, player_pos.y, player_pos.z + exploit::no_clip_distance });
			//		}
			//		return;
			//	}
			//	if (GetAsyncKeyState(0x44) & GetAsyncKeyState(VK_F8)) {
			//		for (int i = 0; i < 13000000; i++) {
			//			avatar2->position_change(Vector3{ player_pos.x, player_pos.y, player_pos.z - exploit::no_clip_distance });
			//		}
			//		return;
			//	}
			//}
			player_pos = avatar2pos;
			//std::cout << player_pos.x<< " " << player_pos.y << " " << player_pos.z << endl;
			player_name = avatar2->GetName();
		}
	}
}

size_t searcher(const std::string& w, std::istream& input)
{
	std::string line;
	size_t k = 0;
	while (std::getline(input, line))
	{
		++k;
		if (line.find(w) != std::string::npos)
			return k;
	}
	return 0;
}






void autofarm(string name_creature, bool is_dead, Vector3 testpos, bool trup, bool is_looted, Vector2 testscreen, bool vis) {

	//Проверка кабан или нет
	if (name_creature == "Молодой кабан" || name_creature == "Кабан") {
		//cout << testscreen.x << " " << testscreen.y << endl;
		
		
		//Нахождение дистанции до самого близкого живого моба
		if (min_dist == 0 & !is_dead) {
			min_dist = GetDistance(testpos, player_pos);
		}
		if (GetDistance(testpos, player_pos) < min_dist & !is_dead) {
			min_dist = GetDistance(testpos, player_pos);
		}
		//Нахождение дистанции до самого близкого мертвого моба
		if (min_dist_dead == 0 & is_dead) {
			min_dist_dead = GetDistance(testpos, player_pos);
		}
		if (GetDistance(testpos, player_pos) < min_dist_dead & is_dead) {
			min_dist_dead = GetDistance(testpos, player_pos);
		}
		//Проверка если мертвый моб является тем до которого минимальная дистанция, то выполняется алгоритм
		if (GetDistance(testpos, player_pos) == min_dist_dead) {
			//проверка на то лежит ли моб на земле
			if (trup == 0) {
				min_dist_dead = GetDistance(testpos, player_pos);
				//если мертв то
				if (is_dead) {
					//если не залутаный то
					if (is_looted == 0) {
						if (min_dist_dead > 1) {
							keybd_event(0x57,
								0x45,
								KEYEVENTF_EXTENDEDKEY | 0,
								0);
						}
						AimAtPos(testscreen.x, testscreen.y - 90, 0.8, 0.8);
						if (min_dist_dead < 1) {
							if (farm_obj_f_temp_is_looted <= 8) {
								keybd_event(0x46,
									0x45,
									KEYEVENTF_EXTENDEDKEY | 0,
									0);
								keybd_event(0x46,
									0x45,
									KEYEVENTF_KEYUP,
									0);
								farm_obj_f_temp_is_looted += 1;
							}
						}
						farm_obj_dead_int = 0;
					}
				}
				//если мертв то
				if (is_dead) {
					//если залутаный то
					if (is_looted == 1) {
						//Если дистнция меньше одного метра то забрать лут и выставить дистанцию для живых мобов обратно на 200 для нового поиска цели
							//Нажатие клавиши F чтобы начать лутать
						if (min_dist_dead < 1) {
							if (farm_obj_f_temp_isnt_looted <= 8) {
								keybd_event(0x46,
									0x45,
									KEYEVENTF_EXTENDEDKEY | 0,
									0);
								keybd_event(0x46,
									0x45,
									KEYEVENTF_KEYUP,
									0);
								farm_obj_f_temp_isnt_looted += 1;
							}
							if (farm_obj_f_temp_is_looted > 8) {
								farm_obj_f_temp_is_looted = 0;
							}
							if (farm_obj_f_temp_isnt_looted > 8) {
								farm_obj_f_temp_isnt_looted = 0;
							}
						}

						//Если дистанция меньше 2 метров, то приподнять прицел вышел и отойти назад
						if (min_dist_dead <= 2) {

							//Поднятие камеры на -5 по Y за каждый цикл пока дистанция не будет больше 2 метров
							mouse_event(0x0001, (int)(0), (int)(-3), NULL, 0);
							keybd_event(0x57,
								0x45,
								KEYEVENTF_KEYUP,
								0);
							if (farm_obj_count_weapon == 1) {
								keybd_event(0x52,
									0x45,
									KEYEVENTF_EXTENDEDKEY | 0,
									0);
								keybd_event(0x52,
									0x45,
									KEYEVENTF_EXTENDEDKEY | 0,
									0);
								farm_obj_count_weapon = 0;
							}
							if (farm_obj_count_health == 2) {
								keybd_event(0x34,
									0x45,
									KEYEVENTF_EXTENDEDKEY | 0,
									0);
								keybd_event(0x52,
									0x45,
									KEYEVENTF_EXTENDEDKEY | 0,
									0);
								farm_obj_count_health = 0;
							}
							//Нажатие клавиши S
							keybd_event(0x53,
								0x45,
								KEYEVENTF_EXTENDEDKEY | 0,
								0);
							keybd_event(0x53,
								0x45,
								KEYEVENTF_KEYUP,
								0);
						}
						min_dist = 200;
						min_dist_dead = 200;
						farm_obj_int = 0;

					}
				}
			}
			
		}
		if (GetDistance(testpos, player_pos) == min_dist) {
			//cout << testscreen.x << " " << testscreen.y << endl;
			if (farm_obj_int == 0) {
				min_dist = GetDistance(testpos, player_pos);
				if (testscreen.x > 0 & testscreen.x < 1890 & testscreen.y > 0 & testscreen.y < 990) {

					if (!is_dead) {
						AimAtPos(testscreen.x, testscreen.y - 90, 0.8, 0.8);
					}
					if (min_dist <= 15) {
						if (vis) {
							if (!is_dead) {
								keybd_event(VK_LBUTTON,
									0x01,
									KEYEVENTF_EXTENDEDKEY | 0,
									0);
								keybd_event(VK_LBUTTON,
									0x01,
									KEYEVENTF_KEYUP,
									0);
							}
							if (is_dead) {
								if (!is_looted) {
									farm_obj_count_weapon += 1;
									farm_obj_count_health += 1;
									farm_obj_int = 1;
									farm_obj_dead_int = 0;
								}
							}
						}
					}

					if (min_dist > 1) {
						keybd_event(0x57,
							0x45,
							KEYEVENTF_EXTENDEDKEY | 0,
							0);
						keybd_event(0x57,
							0x45,
							KEYEVENTF_KEYUP,
							0);
					}
					if (min_dist <= 3) {
						keybd_event(0x53,
							0x45,
							KEYEVENTF_EXTENDEDKEY | 0,
							0);
						keybd_event(0x53,
							0x45,
							KEYEVENTF_KEYUP,
							0);
					}

					//0x57 - W
					//0x53 - S
					//0x52 - R
					//0x46 - F
					//0x34 - Клавиша 4
				}
				else {
					mouse_event(0x0001, (int)(-5), (int)(0), NULL, 0);
				}
				//if (testscreen.x > horizontal) {
				//	mouse_event(0x0001, (int)(5), (int)(0), NULL, 0);
				//}
				//if (testscreen.y < 0) {
				//	mouse_event(0x0001, (int)(-5), (int)(0), NULL, 0);
				//}
				//if (testscreen.y > vertical) {
				//	mouse_event(0x0001, (int)(5), (int)(0), NULL, 0);
				//}
			}

		}
	}
}






//=========================== Container ==================================
void ContainerESP()
{

	auto drawlist = ImGui::GetForegroundDrawList();
	auto entitymanager = EntityManager::instance();

	auto camera = CameraImpl::Instance();
	if (!camera) return;

	auto entitiesmap = entitymanager->Entities();
	auto iter = entitiesmap.iter->next();
	bool cahedmatrix = false;

	auto color_full = ImColor{ 255, 196, 0, 255 };
	auto color_looted = ImColor{ 55, 196, 200, 255 };

	for (size_t i = 0; i < entitiesmap.num; i++)
	{
		auto entity = iter->entity();
		iter = iter->next();
		if (!entity) continue;
		auto avatar = IS_A(entity, Container); // trash
		//auto avatar =  (Avatar*)entity; // trash
		if (!avatar) continue;
		//auto avatar =  (NPC*)Entity;
		auto testpos = avatar->position();
		if (avatar) {
			container_count += 1;
			//std::cout << testpos.x << std::endl;
		}
		
		//avatar->dump();

		Vector2 testscreen;

		if (!camera->ProjectWorldToScreen(testpos, &testscreen, &cahedmatrix))  continue;

		auto model = avatar->GetModel();
		if (!model) continue;
		auto vis = model->IsVisible();


		auto name_Container = avatar->GetName();
		auto is_container_looted = avatar->is_looted();
		// 	str = avatar->ob_type()->tp_name();
		//	auto team = avatar->GetTeam();
		if (name_Container.size() == 0)
		{
			name_Container = avatar->ob_type()->tp_name().c_str();
		}
		//str += std::string(" ")+ std::to_string(team);

		if (avatar) {
			if (GetDistance(avatar->position(), player_pos) < 200) {
				if (espent::esp_container_distance == true) {
					drawlist->AddText({ testscreen.x,testscreen.y + 12 }, ImColor{ 255, 255, 255, 155 }, (std::string("[") + std::to_string(GetDistance(testpos, player_pos)) + std::string("m] ")).c_str());
				}

				if (is_container_looted == 0) {
					std::string name_c = name_Container + " (full)";
					if (snapline_menu::container_snapline == true) {
						drawlist->AddLine({ testscreen.x, testscreen.y }, { float(horizontal) / 2, float(vertical) }, color_full);
					}
					drawlist->AddText({ testscreen.x,testscreen.y }, color_full, name_c.c_str());
				}
				if (is_container_looted == 1) {
					std::string name_c = name_Container + " (looted)";
					drawlist->AddText({ testscreen.x,testscreen.y }, color_looted, name_c.c_str());
				}
			}
		}
	}
	//drawlist->AddText({ 20,407 }, color_full, "КОНТЕЙНЕРЫ:");
	//drawlist->AddText({ 20,427 }, color_full, std::to_string(container_count).c_str());
	container_count = 0;
}
//===========================================

//=========================== Anomaly ==================================
void AnomalyESP()
{

	auto drawlist = ImGui::GetForegroundDrawList();
	auto entitymanager = EntityManager::instance();

	auto camera = CameraImpl::Instance();
	if (!camera) return;

	auto entitiesmap = entitymanager->Entities();
	auto iter = entitiesmap.iter->next();
	bool cahedmatrix = false;

	auto color_name = ImColor{ 255, 128, 0, 255 };



	for (size_t i = 0; i < entitiesmap.num; i++)
	{
		auto entity = iter->entity();
		iter = iter->next();
		if (!entity) continue;
		auto avatar = IS_A(entity, Anomaly); // trash
		if (!avatar) continue;
		//auto avatar =  (NPC*)Entity;
		auto testpos = avatar->position();

		if (avatar) {
			anomaly_count += 1;
			//std::cout << testpos.x << std::endl;
		}
		Vector2 testscreen;

		//avatar->dump();
		// 
		// 
		//if (exploit::legit_magnit_anomaly) {
		//	if (player_count != 0) {
		//		exploit::magnit_anomaly = false;
		//	}
		//}

		if (!camera->ProjectWorldToScreen(testpos, &testscreen, &cahedmatrix))  continue;

		auto model = avatar->GetModel();
		if (!model) continue;
		auto vis = model->IsVisible();



		//auto name_anomaly = avatar->GetName();
		auto id_anomaly = avatar->id_anomaly(); //id аномалий для CheckedAnomaly
		auto type_anomaly = avatar->GetAnomalyType();
		auto art_anomaly = avatar->GetArtefact();
		auto state_anomaly = avatar->GetState();
		// 	str = avatar->ob_type()->tp_name();
		//	auto team = avatar->GetTeam();
		//if (name_anomaly.size() == 0)
		//{
			//name_anomaly = avatar->ob_type()->tp_name().c_str();
		//}
		//str += std::string(" ")+ std::to_string(team);

		testscreen.y -= 15;
		auto color_artefact = ImColor(230, 130, 14, 255);



		if (exploit::magnit_anomaly) {
			
			if (GetDistance(testpos, player_pos) < exploit::distance_magnit) {
				drawlist->AddRect(ImVec2(horizontal / 2 - exploit::radius_magnit, vertical / 2 - exploit::radius_magnit), ImVec2(horizontal / 2 + exploit::radius_magnit, vertical / 2 + exploit::radius_magnit), ImColor(200, 200, 200, 155));
				std::string detected_artefacts_text = (std::string("[") + std::to_string(artefacts_in_anomalies.size()) + std::string("] ")).c_str();
				drawlist->AddText(ImVec2(horizontal / 2 - 60, vertical / 2 - exploit::radius_magnit), ImColor{ 0, 200, 254, 255 }, std::string("Detected artefacts: " + detected_artefacts_text).c_str());
				if (testscreen.x < horizontal / 2 + exploit::radius_magnit && testscreen.y < vertical / 2 + exploit::radius_magnit && testscreen.x > horizontal / 2 - exploit::radius_magnit && testscreen.y > vertical / 2 - exploit::radius_magnit) {
					if (type_anomaly != 0 & type_anomaly != 28 & type_anomaly != 27 & type_anomaly != 72 & type_anomaly != 70 & type_anomaly != 74 & type_anomaly != 71 & type_anomaly != 73 & type_anomaly != 99 & type_anomaly != 26) {
						//if (!GetAsyncKeyState(VK_MBUTTON)) {
						//	drawlist->AddText(ImVec2(horizontal / 2 - 135, vertical / 2 - 10), ImColor{ 0, 200, 254, 255 }, "УДЕРЖИВАЙТЕ СРЕДНЮЮ КЛАВИШУ МЫШИ И \nКИДАЙТЕ КАМЕНЬ ДЛЯ АКТИВАЦИИ АНОМАЛИЙ");
						//}
						//drawlist->AddCircle(ImVec2(horizontal / 2, vertical / 2), exploit::radius_magnit - i, ImColor(230, 130, 14, 255));
						//drawlist->AddRectFilled(ImVec2(horizontal / 2 - exploit::radius_magnit, vertical / 2 - exploit::radius_magnit), ImVec2(horizontal / 2 + exploit::radius_magnit, vertical / 2 + exploit::radius_magnit), ImColor(230, 230, 230, 50));

						
						if (GetAsyncKeyState(VK_MBUTTON)) {
							exploit::anomaly_protect = false;
							if (avatar->GetState() != 2) {
								for (int i = 0; i < checked_anomalies.size(); i++) {
									if (checked_anomalies[i] == id_anomaly) {
										temp_checked_magnit_anomaly = 1;
									}
								}
								for (int i = 0; i < artefacts_in_anomalies.size(); i++) {
									if (artefacts_in_anomalies[i] == id_anomaly) {
										temp_checked_magnit_anomaly = 1;
									}
								}
								if (temp_checked_magnit_anomaly == 0) {
									avatar->position_change(player_pos);
									continue;
								}
								if (temp_checked_magnit_anomaly == 1) {
									temp_checked_magnit_anomaly = 0;
								}
							}
						}
						if (!GetAsyncKeyState(VK_MBUTTON)) {
							exploit::anomaly_protect = true;
						}
					}
				}
			}
		}

		


		if (avatar) {
			if (exploit::anomaly_protect) {
				if (type_anomaly != 0 & type_anomaly != 28 & type_anomaly != 27 & type_anomaly != 72 & type_anomaly != 70 & type_anomaly != 74 & type_anomaly != 71 & type_anomaly != 73 & type_anomaly != 99 & type_anomaly != 26){
					if (GetDistance(avatar->position(), player_pos) < 5) {
						keybd_event(0x57,
							0x45,
							KEYEVENTF_KEYUP,
							0);
						keybd_event(0x53,
							0x45,
							KEYEVENTF_EXTENDEDKEY | 0,
							0);
						keybd_event(0x53,
							0x45,
							KEYEVENTF_KEYUP,
							0);
					}
				}
			}
			if (GetDistance(avatar->position(), player_pos) < 200) {
				std::string distance_an = (std::string("[") + std::to_string(GetDistance(testpos, player_pos)) + std::string("m] ")).c_str();
				if (espent::esp_checked_anomaly == true) {
					if (state_anomaly == 2) { //активирована аномалия или нет, если да то изменяется цвет на зелёный
						for (int i = 0; i < checked_anomalies.size(); i++) {
							if (checked_anomalies[i] == id_anomaly) {
								temp_checked_anomaly = 1;
							}
						}
						if (temp_checked_anomaly == 0) {
							checked_anomalies.push_back(id_anomaly);
						}
						if (temp_checked_anomaly == 1) {
							temp_checked_anomaly = 0;
						}
					}
					for (int i = 0; i < checked_anomalies.size(); i++) {
						if (checked_anomalies[i] == id_anomaly) {
							color_name = ImColor{ 0, 255, 80, 255 };
							break;
						}
					}
				}
				if (menu_vars4::memorizer_artefacts == true) {
					if (art_anomaly != 0) {
						for (int i = 0; i < artefacts_in_anomalies.size(); i++) {
							if (artefacts_in_anomalies[i] == id_anomaly) {
								temp_artefacts_in_anomalies = 1;
							}
						}
						if (temp_artefacts_in_anomalies == 0) {
							artefacts_in_anomalies.push_back(id_anomaly);
						}
						if (temp_artefacts_in_anomalies == 1) {
							temp_artefacts_in_anomalies = 0;
						}
					}
					for (int i = 0; i < artefacts_in_anomalies.size(); i++) {
						if (artefacts_in_anomalies[i] == id_anomaly) {
							if (state_anomaly == 2) {
								if (art_anomaly == 0) {
									artefacts_in_anomalies.erase(artefacts_in_anomalies.begin() + i);
									continue;
								}
							}
							if (snapline_menu::artefact_snapline == true) {
								drawlist->AddLine({ testscreen.x, testscreen.y + 24 }, { float(horizontal) / 2, 0 }, ImColor{ 255,10,10,255 });
							}
							drawlist->AddText({ testscreen.x-40,testscreen.y+12 }, ImColor{255,10,10,255}, "Artefact is detected");
							break;
						}
					}
				}








				if (state_anomaly == 2) { //активирована аномалия или нет, если да то изменяется цвет на зелёный
					color_name = ImColor{ 0, 255, 80, 255 };
				}
				if (snapline_menu::anomaly_snapline == true) {
					drawlist->AddLine({ testscreen.x, testscreen.y }, { float(horizontal) / 2, float(vertical) }, color_name);
				}
				if (menu_vars4::name_anomalies == false) { 
					type_anomaly = 0;
				}
				if (type_anomaly == 14 || type_anomaly == 15 || type_anomaly == 13) {
					std::string name_an = "Microwave " + distance_an;
					drawlist->AddText({ testscreen.x-25,testscreen.y }, color_name, name_an.c_str());
				}
				else if (type_anomaly == 24 || type_anomaly == 23 || type_anomaly == 22) {
					std::string name_an = "Green Rot " + distance_an;
					drawlist->AddText({ testscreen.x-35,testscreen.y }, color_name, name_an.c_str());
				}
				else if (type_anomaly == 3 || type_anomaly == 2 || type_anomaly == 1) {
					std::string name_an = "Crusher " + distance_an;
					drawlist->AddText({ testscreen.x-20,testscreen.y }, color_name, name_an.c_str());

				}
				else if (type_anomaly == 106) {
					std::string name_an = "Snow Press " + distance_an;
					drawlist->AddText({ testscreen.x-35,testscreen.y }, color_name, name_an.c_str());
				}
				else if (type_anomaly == 105) {
					std::string name_an = "Snow Crusher " + distance_an;
					drawlist->AddText({ testscreen.x-35,testscreen.y }, color_name, name_an.c_str());
				}
				else if (type_anomaly == 104) {
					std::string name_an = "Snow Catapult " + distance_an;
					drawlist->AddText({ testscreen.x-35,testscreen.y }, color_name, name_an.c_str());
				}
				else if (type_anomaly == 5 || type_anomaly == 4 || type_anomaly == 6) {
					std::string name_an = "Catapult " + distance_an;
					drawlist->AddText({ testscreen.x-20,testscreen.y }, color_name, name_an.c_str());
				}
				else if (type_anomaly == 72 || type_anomaly == 70 || type_anomaly == 74 || type_anomaly == 71 || type_anomaly == 73 || type_anomaly == 99 || type_anomaly == 26) {
					std::string name_an = "Radiation " + distance_an;
					drawlist->AddText({ testscreen.x-25,testscreen.y }, color_name, name_an.c_str());
				}
				else if (type_anomaly == 17 || type_anomaly == 16 || type_anomaly == 19 || type_anomaly == 20 || type_anomaly == 21) {
					std::string name_an = "Electra " + distance_an;
					drawlist->AddText({ testscreen.x-20,testscreen.y }, color_name, name_an.c_str());
				}
				else if (type_anomaly == 109) {
					std::string name_an = "Snowy " + distance_an;
					drawlist->AddText({ testscreen.x-15,testscreen.y }, color_name, name_an.c_str());
				}
				else if (type_anomaly == 7 || type_anomaly == 8 || type_anomaly == 9) {
					std::string name_an = "Press " + distance_an;
					drawlist->AddText({ testscreen.x - 15,testscreen.y }, color_name, name_an.c_str());
				}
				else if (type_anomaly == 25) {
					std::string name_an = "Curse " + distance_an;
					drawlist->AddText({ testscreen.x - 15,testscreen.y }, color_name, name_an.c_str());
				}
				else if (type_anomaly == 27) {
					std::string name_an = "Positive twin " + distance_an;
					drawlist->AddText({ testscreen.x - 35,testscreen.y }, color_name, name_an.c_str());
				}
				else if (type_anomaly == 28) {
					std::string name_an = "Negative twin " + distance_an;
					drawlist->AddText({ testscreen.x - 35,testscreen.y }, color_name, name_an.c_str());
				}
				else if (type_anomaly == 107) {
					std::string name_an = "Special anomaly " + distance_an;
					drawlist->AddText({ testscreen.x - 35,testscreen.y }, color_name, name_an.c_str());
				}
				else if (type_anomaly == 41) {
					std::string name_an = "Teleport " + distance_an;
					drawlist->AddText({ testscreen.x - 20,testscreen.y }, color_name, name_an.c_str());
				}
				else if (type_anomaly == 10 || type_anomaly == 11 || type_anomaly == 12) {
					std::string name_an = "Fire " + distance_an;
					drawlist->AddText({ testscreen.x - 15,testscreen.y }, color_name, name_an.c_str());
				}
				
				else if (type_anomaly == 0) {
					std::string name_an = "Anomaly " + distance_an;
					drawlist->AddText({ testscreen.x-20,testscreen.y }, color_name, name_an.c_str());
				}
				else {
					drawlist->AddText({ testscreen.x,testscreen.y - 15 }, color_artefact, std::to_string(type_anomaly).c_str());
				}
				color_name = ImColor{ 255, 128, 0, 255 };
				if (espent::esp_artefact == true) {
					if (art_anomaly != 0) {
						if (snapline_menu::artefact_snapline == true) {
							drawlist->AddLine({ testscreen.x, testscreen.y + 24 }, { float(horizontal) / 2, 0 }, ImColor{ 255,10,10,255 });
						}
						
						drawlist->AddText({ testscreen.x - 40,testscreen.y + 12 }, ImColor{ 255,10,10,255 }, "Artefact is detected");
						//drawlist->AddCircleFilled({ testscreen.x, testscreen.y - 15 }, 15, color_artefact);
					}
				}
			}
		}
		//drawlist->AddText({ testscreen.x,testscreen.y - 55 }, color_artefact, std::to_string(test_anomaly).c_str()); // Это айди аномалии для CheckedAnomaly

	}
	//drawlist->AddText({ 20,367 }, color_name, "АНОМАЛИИ:");
	//drawlist->AddText({ 20,387 }, color_name, std::to_string(anomaly_count).c_str());
	anomaly_count = 0;
}
//===========================================

//================== Creature ==================
void CreatureLiveESP()
{

	auto drawlist = ImGui::GetForegroundDrawList();
	auto entitymanager = EntityManager::instance();

	auto camera = CameraImpl::Instance();
	if (!camera) return;

	auto entitiesmap = entitymanager->Entities();
	auto iter = entitiesmap.iter->next();
	bool cahedmatrix = false;

	auto color_live = ImColor{ 38, 255, 233, 255 };
	auto color_dead = ImColor{ 38, 53, 255, 100 };

	for (size_t i = 0; i < entitiesmap.num; i++)
	{
		auto entity = iter->entity();
		iter = iter->next();
		if (!entity) continue;
		auto avatar = IS_A(entity, Creature); // trash
		//auto avatar =  (Avatar*)entity; // trash
		if (!avatar) continue;
		//auto avatar =  (NPC*)Entity;
		auto testpos = avatar->position();
		if (avatar) {
			creature_count += 1;
			//std::cout << testpos.x << std::endl;
		}

		//avatar->dump();

		Vector2 testscreen;

		if (exploit::tp_creature) {
			if (!GetAsyncKeyState(0x44) & !GetAsyncKeyState(0x53) & !GetAsyncKeyState(0x57) & !GetAsyncKeyState(0x41)) {
				if (tp_name_mob.size() != 0) {
					std::string name_mob_tp = "Selected mutant: " + tp_name_mob;
					drawlist->AddText(ImVec2(horizontal / 2 - 70, 137), ImColor{ 255,110,0,255 }, name_mob_tp.c_str());
				}
				if (GetAsyncKeyState(0x46)) {
					if (!camera->ProjectWorldToScreen(testpos, &testscreen, &cahedmatrix))  continue;
					if (testscreen.x < horizontal / 2 + menu_vars2::size_p && testscreen.y - menu_vars2::aim_high < vertical / 2 + menu_vars2::size_p && testscreen.x > horizontal / 2 - menu_vars2::size_p && testscreen.y + menu_vars2::aim_high > vertical / 2 - menu_vars2::size_p) {
						tp_name_mob = avatar->GetName();
					}
				}
				if (GetAsyncKeyState(0x48)) {
					if (avatar->GetName() == tp_name_mob) {
						if (!avatar->is_dead()) {
							tp_distance_mob = 0;
							for (int i = 0; i < 150000; i++) {
								avatar->position_change(Vector3{ player_pos.x + 1, player_pos.y, player_pos.z + 1 });
							}
							return;
						}
					}
				}
			}
		}






		if (!camera->ProjectWorldToScreen(testpos, &testscreen, &cahedmatrix))  continue;





		auto model = avatar->GetModel();
		if (!model) continue;
		auto vis = model->IsVisible();


		auto name_creature = avatar->GetName();
		auto is_looted = avatar->is_looted();
		auto is_dead = avatar->is_dead();
		auto trup = avatar->type_m();
		if (name_creature.size() > 100)
		{
			name_creature = "Mutant";
		}





		testscreen.y -= 20;


		//Автоматический фарм кабанов
		if (menu_vars4::auto_farm_kaban) {
			//Функция алгоритма фарма
			drawlist->AddText({ 990, 60 }, ImColor{255,20,35,250}, "АПТЕЧКА ДОЛЖНА ЛЕЖАТЬ В СЛОТЕ НА КНОПКУ 4, ДЛЯ КОРРЕКТНОЙ РАБОТЫ АВТОФАРМА");
			autofarm(name_creature, is_dead, testpos, trup, is_looted, testscreen, vis);
		}

		// 	str = avatar->ob_type()->tp_name();
		//	auto team = avatar->GetTeam();

		//str += std::string(" ")+ std::to_string(team);

		if (menu_vars3::aim_creature) {
			if (!is_dead) {
				if (testscreen.x < horizontal / 2 + menu_vars3::size_c && testscreen.y < vertical / 2 + menu_vars3::size_c && testscreen.x > horizontal / 2 - menu_vars3::size_c && testscreen.y > vertical / 2 - menu_vars3::size_c) {
					//std::cout << "xy: " << testscreen.x << " " << testscreen.y << "screen xy: " << horizontal / 2 << " " << vertical / 2 << "\n";
					if (check_key(c_current_key) != 0) {
						AimAtPos(testscreen.x, testscreen.y-menu_vars2::aim_creature_high_circle, menu_vars3::aim_speed_creature, menu_vars3::aim_smooth_creature);
					}
				}
			}
		}
		std::string name_c = name_creature + " (looted)";
		if (espent::esp_creature_live == true) {
			if (is_dead == 0) {
				if (avatar) {
					if (GetDistance(testpos, player_pos) < 200) {
						if (espent::esp_creature_distance == true) {
							drawlist->AddText({ testscreen.x,testscreen.y+12 }, ImColor{ 255, 255, 255, 155 }, ( std::string("[") + std::to_string(GetDistance(testpos, player_pos)) + std::string("m] ")).c_str());
						}
						if (snapline_menu::creature_snapline == true) {
							drawlist->AddLine({ testscreen.x, testscreen.y }, { float(horizontal) / 2, float(vertical) }, color_live);
						}
						drawlist->AddText({ testscreen.x,testscreen.y }, color_live, name_creature.c_str());
					}
				}

			}
		}
		if (espent::esp_creature_dead == true) {
			if (is_dead) {
				if (avatar) {
					if (GetDistance(testpos, player_pos) < 200) {
						if (espent::esp_creature_distance == true) {
							drawlist->AddText({ testscreen.x,testscreen.y+12 }, ImColor{ 255, 255, 255, 155 }, (std::string("[") + std::to_string(GetDistance(testpos, player_pos)) + std::string("m] ")).c_str());
						}
						if (is_looted == 1) {
							std::string name_c = name_creature + " (looted)";
							drawlist->AddText({ testscreen.x,testscreen.y }, color_dead, name_c.c_str());
						}
						if (is_looted == 0) {
							drawlist->AddText({ testscreen.x,testscreen.y }, color_dead, name_creature.c_str());
						}
					}
				}

			}
		}
	}
	//drawlist->AddText({ 20,327 }, color_live, "МУТАНТЫ:");
	//drawlist->AddText({ 20,347 }, color_live, std::to_string(creature_count).c_str());
	creature_count = 0;
}



//============= NickName and AccessLevel ==============
void NickNameESP()
{

	auto drawlist = ImGui::GetForegroundDrawList();
	auto entitymanager = EntityManager::instance();
	//auto camera = CameraImpl::Instance();
	//if (!camera) return;

	auto entitiesmap = entitymanager->Entities();
	auto iter = entitiesmap.iter->next();
	std::cout << entitiesmap.num << std::endl;
	


	bool cahedmatrix = false;
	//цвет надписи dead
	auto color_isdead = ImColor{ 0, 179, 255, 255 };
	//цвет значений статистики
	auto color_kd = ImColor{ 222, 216, 46, 255 };
	//цвет имён людей
	auto color_namePeople = ImColor{ 255, 255, 0, 255 };
	auto color_red_namePeople = ImColor{ 255, 0, 0, 255 };
	//цвет уровня прав доступа людей
	auto color_accessPeople = ImColor{ 255, 255, 255, 255 };
	//цвет клантега
	auto color = ImColor{ 255,210,67,255 };
	for (size_t i = 0; i < entitiesmap.num; i++)
	{
		auto entity = iter->entity();
		iter = iter->next();
		if (!entity) continue;
		auto avatar = IS_A(entity, Avatar); // trash

		if (!avatar) continue;

		//auto avatar =  (NPC*)Entity;
		auto testpos = avatar->position();
		if (avatar) {
			player_count += 1;
			//std::cout << testpos.x << std::endl;
		}

		//avatar->dump();

		Vector2 testscreen;

		if (exploit::tp_people) {
			if (!GetAsyncKeyState(0x44) & !GetAsyncKeyState(0x53) & !GetAsyncKeyState(0x57) & !GetAsyncKeyState(0x41)) {
				if (tp_people_name.size() != 0) {
					std::string name_people_tp = "Selected player: " + tp_people_name;
						drawlist->AddText(ImVec2(horizontal / 2 - 70, 117), ImColor{ 255,110,0,255 }, name_people_tp.c_str());
				}
				if (GetAsyncKeyState(0x46)) {
					//if (!camera->ProjectWorldToScreen(testpos, &testscreen, &cahedmatrix))  continue;
						if (testscreen.x < horizontal / 2 + menu_vars2::size_p && testscreen.y - menu_vars2::aim_high < vertical / 2 + menu_vars2::size_p && testscreen.x > horizontal / 2 - menu_vars2::size_p && testscreen.y + menu_vars2::aim_high > vertical / 2 - menu_vars2::size_p) {
							tp_people_name = avatar->GetName();
						}
				}
				if (GetAsyncKeyState(VK_F5)) {

					if (avatar->GetName() == tp_people_name) {
						for (int i = 0; i < 150000; i++) {
							avatar->position_change(Vector3{ player_pos.x + 1, player_pos.y, player_pos.z + 1 });
						}
						return;
					}
				}
			}
		}

		




		//if (!camera->ProjectWorldToScreen(testpos, &testscreen, &cahedmatrix))  continue;



		auto model = avatar->GetModel();
		if (!model) continue;
		auto vis = model->IsVisible();

		if (menu_vars4::esp_cantakedamage_people == true) {
			if (avatar->CTD() == 0) {
				continue;
			}
		}
		//Значение CanTakeDamage игрока
		auto ctd_people = avatar->CTD();
		//Значение Name игрока
		auto name_people = avatar->GetName();
		//Значение уровня доступа игрока
		auto accessLevel_people = avatar->GetAccessLevel();
		//Значение количества смертей
		auto karma_people = avatar->GetKarma();
		//Значение количества киллов
		auto frags_people = avatar->GetFrags();
		//Имя клана
		auto clanName_people = avatar->GetClanName();

















		// 	str = avatar->ob_type()->tp_name();
		//	auto team = avatar->GetTeam();
		if (name_people.size() == 0)
		{
			name_people = "Avatar";
			//name_people = avatar->ob_type()->tp_name().c_str();
		}

		if (menu_vars4::esp_blacklist_people == true) {
			std::ifstream file("blacklist.txt");
			//=============================
			//	ПРОВЕРКА ЧЕРНОГО СПИСКА
			while (file) {
				std::string str;
				std::getline(file, str);
				if (name_people.c_str() == str) {
					color_namePeople = ImColor{ 255,56,255,255 };
				}
			}
			//=============================
		}
		//str += std::string(" ")+ std::to_string(team);

		//if (menu_vars4::freeze_packets == true) {
		//	if (GetAsyncKeyState(0x42) != 0 && temp_freeze == 0) {
		//		std::cout << "off" << std::endl;
		//		WinExec("ipconfig /release", 0);
		//		temp_freeze = 1;
		//		std::string cmd = "powershell \"New-NetQosPolicy -Name \"GyzaoV2\" -AppPathNameMatchCondition \"sogame.exe\" -ThrottleRateActionBitsPerSecond \"" + std::to_string(menu_vars4::kilobyte_rate) + "\"kb -PolicyStore ActiveStore\"";
		//		system(cmd.c_str());
		//		Sleep(500);
		//		if (GetAsyncKeyState(0x42) == 0) {
		//			system("powershell Remove-NetQosPolicy -PolicyStore ActiveStore -Confirm:$false");
		//		}
			//}
			//if (GetAsyncKeyState(0x42) != 0 && temp_freeze == 1) {
			//	std::cout << "on" << std::endl;
			//	WinExec("ipconfig /renew", 0);
			//	temp_freeze = 0;
			//}
		//	if (GetAsyncKeyState(0x42) == 0) {
		//		system("powershell Remove-NetQosPolicy -PolicyStore ActiveStore -Confirm:$false");
		//	}
		//}


		//AIM




		testscreen.y -= 15;
		float radius_aimbox = 3 + 10 / (GetDistance(avatar->position(), player_pos)+0.1);
		
		if (menu_vars2::aim_clan_player == true) {
			auto_aim(avatar->position(), player_pos);
			if (clanName_people.size() > 1) {
				if (menu_vars4::esp_cantakedamage_people == false) {
					if (!avatar->is_dead()) {
						if (menu_vars2::aim_player) {
							if (testscreen.x < horizontal / 2 + menu_vars2::size_p && testscreen.y - menu_vars2::aim_high < vertical / 2 + menu_vars2::size_p && testscreen.x > horizontal / 2 - menu_vars2::size_p && testscreen.y + menu_vars2::aim_high > vertical / 2 - menu_vars2::size_p) {
								//std::cout << "xy: " << testscreen.x << " " << testscreen.y << "screen xy: " << horizontal / 2 << " " << vertical / 2 << "\n";
								if (temp_aim == 0) {
									temp_aim += 1;
									if (check_key(p_current_key) != 0 && temp_player_aim != avatar->GetName()) {
										temp_player_aim = avatar->GetName();
										if (menu_vars2::no_speed_no_smooth) {
											mouse_event(0x0001, (float)testscreen.x, (float)testscreen.y - menu_vars2::aim_high + 5.5, NULL, 0);
										}
										if (!menu_vars2::no_speed_no_smooth) {
											AimAtPos(testscreen.x, testscreen.y - menu_vars2::aim_high + 5.5, menu_vars2::aim_speed_people, menu_vars2::aim_smooth_people);
										}
									}
								}
								if (temp_aim == 1) {
									if (check_key(p_current_key) != 0 && temp_player_aim == avatar->GetName()) {
										temp_player_aim = avatar->GetName();
										if (menu_vars2::no_speed_no_smooth) {
											mouse_event(0x0001, (float)testscreen.x, (float)testscreen.y - menu_vars2::aim_high + 5.5, NULL, 0);
										}
										if (!menu_vars2::no_speed_no_smooth) {
											AimAtPos(testscreen.x, testscreen.y - menu_vars2::aim_high + 5.5, menu_vars2::aim_speed_people, menu_vars2::aim_smooth_people);
										}
									}
									if (check_key(p_current_key) == 0 && temp_player_aim != avatar->GetName()) {
										temp_player_aim = avatar->GetName();
									}
								}
								auto draw2 = ImGui::GetBackgroundDrawList();
								if (espent::esp_aimbox) {
									draw2->AddCircle(ImVec2(testscreen.x, testscreen.y - menu_vars2::aim_high), radius_aimbox, IM_COL32(255, 0, 0, 255), 100);
								}
							}
						}
					}
				}
				if (menu_vars4::esp_cantakedamage_people == true) {
					if (!avatar->is_dead()) {
						if (ctd_people == 1) {
							if (menu_vars2::aim_player) {
								if (testscreen.x < horizontal / 2 + menu_vars2::size_p && testscreen.y - menu_vars2::aim_high < vertical / 2 + menu_vars2::size_p && testscreen.x > horizontal / 2 - menu_vars2::size_p && testscreen.y + menu_vars2::aim_high > vertical / 2 - menu_vars2::size_p) {
									//std::cout << "xy: " << testscreen.x << " " << testscreen.y << "screen xy: " << horizontal / 2 << " " << vertical / 2 << "\n";
									if (temp_aim == 0) {
										temp_aim += 1;
										if (check_key(p_current_key) != 0 && temp_player_aim != avatar->GetName()) {
											temp_player_aim = avatar->GetName();
											if (menu_vars2::no_speed_no_smooth) {
												mouse_event(0x0001, (float)testscreen.x, (float)testscreen.y - menu_vars2::aim_high + 5.5, NULL, 0);
											}
											if (!menu_vars2::no_speed_no_smooth) {
												AimAtPos(testscreen.x, testscreen.y - menu_vars2::aim_high + 5.5, menu_vars2::aim_speed_people, menu_vars2::aim_smooth_people);
											}
										}
									}
									if (temp_aim == 1) {
										if (check_key(p_current_key) != 0 && temp_player_aim == avatar->GetName()) {
											temp_player_aim = avatar->GetName();
											if (menu_vars2::no_speed_no_smooth) {
												mouse_event(0x0001, (float)testscreen.x, (float)testscreen.y - menu_vars2::aim_high + 5.5, NULL, 0);
											}
											if (!menu_vars2::no_speed_no_smooth) {
												AimAtPos(testscreen.x, testscreen.y - menu_vars2::aim_high + 5.5, menu_vars2::aim_speed_people, menu_vars2::aim_smooth_people);
											}
										}
										if (check_key(p_current_key) == 0 && temp_player_aim != avatar->GetName()) {
											temp_player_aim = avatar->GetName();
										}
									}
									auto draw2 = ImGui::GetBackgroundDrawList();
									if (espent::esp_aimbox) {
										draw2->AddCircle(ImVec2(testscreen.x, testscreen.y - menu_vars2::aim_high), radius_aimbox, IM_COL32(255, 0, 0, 255), 100);
									}
								}
							}
						}
					}
				}
			}
		}
		if (menu_vars2::aim_clan_player == false) {
			auto_aim(avatar->position(), player_pos);
			if (menu_vars4::esp_cantakedamage_people == false) {
				if (!avatar->is_dead()) {
					if (menu_vars2::aim_player) {
						if (testscreen.x < horizontal / 2 + menu_vars2::size_p && testscreen.y - menu_vars2::aim_high < vertical / 2 + menu_vars2::size_p && testscreen.x > horizontal / 2 - menu_vars2::size_p && testscreen.y + menu_vars2::aim_high > vertical / 2 - menu_vars2::size_p) {
							//std::cout << "xy: " << testscreen.x << " " << testscreen.y << "screen xy: " << horizontal / 2 << " " << vertical / 2 << "\n";
							if (temp_aim == 0) {
								temp_aim += 1;
								if (check_key(p_current_key) != 0 && temp_player_aim != avatar->GetName()) {
									temp_player_aim = avatar->GetName();
									if (menu_vars2::no_speed_no_smooth) {
										mouse_event(0x0001, (float)testscreen.x, (float)testscreen.y - menu_vars2::aim_high + 5.5, NULL, 0);
									}
									if (!menu_vars2::no_speed_no_smooth) {
										AimAtPos(testscreen.x, testscreen.y - menu_vars2::aim_high + 5.5, menu_vars2::aim_speed_people, menu_vars2::aim_smooth_people);
									}
									auto draw2 = ImGui::GetBackgroundDrawList();
									if (espent::esp_aimbox) {
										draw2->AddCircle(ImVec2(testscreen.x, testscreen.y - menu_vars2::aim_high), radius_aimbox, IM_COL32(255, 0, 0, 255), 100);
									}
								}
							}
							if (temp_aim == 1) {
								if (check_key(p_current_key) != 0 && temp_player_aim == avatar->GetName()) {
									temp_player_aim = avatar->GetName();
									if (menu_vars2::no_speed_no_smooth) {
										mouse_event(0x0001, (float)testscreen.x, (float)testscreen.y - menu_vars2::aim_high + 5.5, NULL, 0);
									}
									if (!menu_vars2::no_speed_no_smooth) {
										AimAtPos(testscreen.x, testscreen.y - menu_vars2::aim_high + 5.5, menu_vars2::aim_speed_people, menu_vars2::aim_smooth_people);
									}
								}
								if (check_key(p_current_key) == 0 && temp_player_aim != avatar->GetName()) {
									temp_player_aim = avatar->GetName();
								}
							}
							auto draw2 = ImGui::GetBackgroundDrawList();
							if (espent::esp_aimbox) {
								draw2->AddCircle(ImVec2(testscreen.x, testscreen.y - menu_vars2::aim_high), radius_aimbox, IM_COL32(255, 0, 0, 255), 100);
							}
						}
					}
				}
			}
			if (menu_vars4::esp_cantakedamage_people == true) {
				if (!avatar->is_dead()) {
					if (ctd_people == 1) {
						if (menu_vars2::aim_player) {
							if (testscreen.x < horizontal / 2 + menu_vars2::size_p && testscreen.y - menu_vars2::aim_high < vertical / 2 + menu_vars2::size_p && testscreen.x > horizontal / 2 - menu_vars2::size_p && testscreen.y + menu_vars2::aim_high > vertical / 2 - menu_vars2::size_p) {
								auto_aim(avatar->position(), player_pos);
								//std::cout << "xy: " << testscreen.x << " " << testscreen.y << "screen xy: " << horizontal / 2 << " " << vertical / 2 << "\n";
								if (temp_aim == 0) {
									temp_aim += 1;
									if (check_key(p_current_key) != 0 && temp_player_aim != avatar->GetName()) {
										temp_player_aim = avatar->GetName();
										AimAtPos(testscreen.x, testscreen.y - menu_vars2::aim_high + 5.5, menu_vars2::aim_speed_people, menu_vars2::aim_smooth_people);
									}
								}
								if (temp_aim == 1) {
									if (check_key(p_current_key) != 0 && temp_player_aim == avatar->GetName()) {
										temp_player_aim = avatar->GetName();
										AimAtPos(testscreen.x, testscreen.y - menu_vars2::aim_high + 5.5, menu_vars2::aim_speed_people, menu_vars2::aim_smooth_people);
									}
									if (check_key(p_current_key) == 0 && temp_player_aim != avatar->GetName()) {
										temp_player_aim = avatar->GetName();
									}
								}
								auto draw2 = ImGui::GetBackgroundDrawList();
								//draw2->AddCircle(ImVec2(testscreen.x, testscreen.y - menu_vars2::aim_high), menu_vars2::size_p, IM_COL32(255, 0, 0, 255), 100);
							}
						}
					}
				}
			}
		}


		//ESP
		if (avatar) {
			if (GetDistance(avatar->position(), player_pos) < 200) {
				if (menu_vars4::esp_cantakedamage_people == false) {
					if (espent::esp_clanName == true) {
						drawlist->AddText({ testscreen.x,testscreen.y - 12 }, color, clanName_people.c_str());
					}
					if (espent::esp_people_distance == true) {
						drawlist->AddText({ testscreen.x,testscreen.y + 12 }, ImColor{ 255, 255, 255, 155 }, (std::string("[") + std::to_string(GetDistance(testpos, player_pos)) + std::string("m] ")).c_str());
					}
					if (menu_vars4::esp_karma_people == true) {
						drawlist->AddText({ testscreen.x, testscreen.y - 27 }, color_kd, std::format("Karma: {}", karma_people).c_str());
					}
					if (menu_vars4::esp_kills_people == true) {
						drawlist->AddText({ testscreen.x, testscreen.y - 40 }, color_kd, std::format("Kills: {}", frags_people).c_str());
					}
					if (menu_vars4::esp_accesslevel_people == true) {
						if (accessLevel_people == 0)
							drawlist->AddText({ testscreen.x,testscreen.y - 15 }, color_accessPeople, "Player");
						if (accessLevel_people != 0) {
							drawlist->AddText({ testscreen.x,testscreen.y - 15 }, color_accessPeople, "Admin");
						}
					}
					if (karma_people >= 200) {
						if (snapline_menu::players_snapline == true) {
							drawlist->AddLine({ testscreen.x, testscreen.y }, { float(horizontal) / 2, float(vertical) }, color_red_namePeople);
						}
						if (avatar->is_dead()) {
							std::string name_people_dead = name_people + " [DEAD]";
							drawlist->AddText({ testscreen.x,testscreen.y }, color_red_namePeople, name_people_dead.c_str());
						}
						if (!avatar->is_dead()) {
							drawlist->AddText({ testscreen.x,testscreen.y }, color_red_namePeople, name_people.c_str());
						}
					}
					if (karma_people < 200) {
						if (espent::esp_visible_players) {
							if (vis) {
								color_namePeople = ImColor{ 255,100,50,105 };
							}
							if (!vis) {
								color_namePeople = ImColor{ 255,255,0,255 };
							}
						}
						if (snapline_menu::players_snapline == true) {
							drawlist->AddLine({ testscreen.x, testscreen.y }, { float(horizontal) / 2, float(vertical) }, color_namePeople);
						}
						if (avatar->is_dead()) {
							std::string name_people_dead = name_people + " [DEAD]";
							drawlist->AddText({ testscreen.x,testscreen.y }, color_namePeople, name_people_dead.c_str());
						}
						if (!avatar->is_dead()) {
							drawlist->AddText({ testscreen.x,testscreen.y }, color_namePeople, name_people.c_str());
						}
					}
					float dis = GetDistance(avatar->position(), player_pos);
					float width = (horizontal / 100 + 500) / (dis + 3);
					float height = (vertical / 100 + 2600) / (dis + 3);
					if (!avatar->is_dead()) {
						if (GetDistance(avatar->position(), player_pos) > 8) {
							if (espent::esp_people_box) {
								drawlist->AddRect({ testscreen.x + (width / 2), testscreen.y }, { testscreen.x - width, testscreen.y - height }, color_namePeople, 1.0F);
							}
							if (espent::esp_people_fill_box) {
								drawlist->AddRectFilled({ testscreen.x + (width / 2), testscreen.y }, { testscreen.x - width, testscreen.y - height }, color_namePeople, 1.0F);
							}
						}
					}
					color_namePeople = ImColor{ 255,255,0,255 };
				}
			}	
		}
		if (avatar) {
			if (GetDistance(avatar->position(), player_pos) < 200) {
				if (menu_vars4::esp_cantakedamage_people == true) {
					if (ctd_people == 1) {
						if (espent::esp_clanName == true) {
							drawlist->AddText({ testscreen.x,testscreen.y - 12 }, color, clanName_people.c_str());
						}
						
						if (espent::esp_people_distance == true) {
							drawlist->AddText({ testscreen.x,testscreen.y + 12 }, ImColor{ 255, 255, 255, 155 }, (std::string("[") + std::to_string(GetDistance(testpos, player_pos)) + std::string("m] ")).c_str());
						}
						if (menu_vars4::esp_karma_people == true) {
							drawlist->AddText({ testscreen.x, testscreen.y - 27 }, color_kd, std::format("Karma: {}", karma_people).c_str());
						}
						if (menu_vars4::esp_kills_people == true) {
							drawlist->AddText({ testscreen.x, testscreen.y - 40 }, color_kd, std::format("Kills: {}", frags_people).c_str());
						}



						if (menu_vars4::esp_accesslevel_people == true) {
							if (accessLevel_people == 0)
								drawlist->AddText({ testscreen.x,testscreen.y - 15 }, color_accessPeople, "Player");
							else
								drawlist->AddText({ testscreen.x,testscreen.y - 15 }, color_accessPeople, "Admin");
						}



						if (karma_people >= 200) {
							if (snapline_menu::players_snapline == true) {
								drawlist->AddLine({ testscreen.x, testscreen.y }, { float(horizontal) / 2, float(vertical) }, color_red_namePeople);
							}
							drawlist->AddText({ testscreen.x,testscreen.y }, color_red_namePeople, name_people.c_str());
						}
						if (karma_people < 200) {
							if (espent::esp_visible_players) {
								if (vis) {
									color_namePeople = ImColor{ 255,100,50,105 };
								}
								if (!vis) {
									color_namePeople = ImColor{ 255,255,0,255 };
								}
							}
							if (snapline_menu::players_snapline == true) {
								drawlist->AddLine({ testscreen.x, testscreen.y }, { float(horizontal) / 2, float(vertical) }, color_namePeople);
							}
							if (avatar->is_dead()) {
								std::string name_people_dead = name_people + " [DEAD]";
								drawlist->AddText({ testscreen.x,testscreen.y }, color_namePeople, name_people_dead.c_str());
							}
							if (!avatar->is_dead()) {
								drawlist->AddText({ testscreen.x,testscreen.y }, color_namePeople, name_people.c_str());
							}
						}
					}
					float dis = GetDistance(avatar->position(), player_pos);
					float width = (horizontal / 100 + 500) / (dis + 3);
					float height = (vertical / 100 + 2600) / (dis + 3);
					if (!avatar->is_dead()) {
						if (GetDistance(avatar->position(), player_pos) > 8) {
							if (espent::esp_people_box) {
								drawlist->AddRect({ testscreen.x + (width / 2), testscreen.y }, { testscreen.x - width, testscreen.y - height }, color_namePeople, 1.0F);
							}
							if (espent::esp_people_fill_box) {
								drawlist->AddRectFilled({ testscreen.x + (width / 2), testscreen.y }, { testscreen.x - width, testscreen.y - height }, color_namePeople, 1.0F);
							}
						}
					}
					color_namePeople = ImColor{ 255,255,0,255 };
				}
			}
		}
	}
	if (espent::esp_radar) {
		drawlist->AddText({ 110,260 }, ImColor(230, 230, 230, 255), "PLAYERS:");
		drawlist->AddText({ 171,260 }, ImColor(230, 230, 230, 255), std::to_string(player_count).c_str());
	}
	if (exploit::legit_magnit_anomaly) {
		if (player_count > exploit::player_count_limit) {
			exploit::magnit_anomaly = false;
		}
		if (player_count == exploit::player_count_limit || player_count == 0) {
			exploit::magnit_anomaly = true;
		}
	}
	player_count = 0;
}


//==============================================

//============= NPC ==============
void NPC_ESP()
{

	auto drawlist = ImGui::GetForegroundDrawList();
	auto entitymanager = EntityManager::instance();
	auto camera = CameraImpl::Instance();
	if (!camera) return;

	auto entitiesmap = entitymanager->Entities();
	auto iter = entitiesmap.iter->next();
	bool cahedmatrix = false;

	auto color_nameNPC = ImColor{ 0, 255, 26, 155 };

	for (size_t i = 0; i < entitiesmap.num; i++)
	{
		auto entity = iter->entity();
		iter = iter->next();
		if (!entity) continue;
		auto avatar = IS_A(entity, NPC);

		if (!avatar) {
			continue;
		}
		if (avatar) {
			npc_count += 1;
		}
		auto testpos = avatar->position();

		//avatar->dump();

		Vector2 testscreen;


		if (!camera->ProjectWorldToScreen(testpos, &testscreen, &cahedmatrix))  continue;
		auto model = avatar->GetModel();
		if (!model) continue;
		auto vis = model->IsVisible();

		//if (exploit::tp_people) {
		//	if (GetAsyncKeyState(VK_F8)) {
		//		if (avatar->GetName() == "Хромцов") {
		//			for (int i = 0; i < 33000000; i++) {
		//				avatar->position_change(Vector3{ player_pos.x + 1, player_pos.y, player_pos.z + 1 });
		//			}
		//			return;
		//		}

		//	}
		//}

		//Значение Name NPC
		auto name_NPC = avatar->GetName();

		//цвет имён NPC
		auto color_nameNPC = ImColor{ 0, 255, 26, 155 };

		if (name_NPC.size() > 100 || name_NPC.size() == 0)
		{
			name_NPC = "NPC";
		}

		testscreen.y -= 15;

		if (avatar) {
			if (GetDistance(avatar->position(), player_pos) < 200) {
				if (espent::esp_npc_distance == true) {
					drawlist->AddText({ testscreen.x,testscreen.y + 12 }, ImColor{ 255, 255, 255, 155 }, (std::string("[") + std::to_string(GetDistance(testpos, player_pos)) + std::string("m] ")).c_str());
				}
				if (snapline_menu::npc_snapline == true) {
					drawlist->AddLine({ testscreen.x, testscreen.y }, { float(horizontal) / 2, float(vertical) }, color_nameNPC);
				}
				drawlist->AddText({ testscreen.x,testscreen.y }, color_nameNPC, name_NPC.c_str());
			}
		}
	}
	//drawlist->AddText({ 20,247 }, color_nameNPC, "НПС:");
	//drawlist->AddText({ 20,267 }, color_nameNPC, std::to_string(npc_count).c_str());
	npc_count = 0;
}
//==============================================



//========================= LOOT =============================

void LOOT_ESP()
{

	auto drawlist = ImGui::GetForegroundDrawList();
	auto entitymanager = EntityManager::instance();
	auto camera = CameraImpl::Instance();
	if (!camera) return;

	auto entitiesmap = entitymanager->Entities();
	auto iter = entitiesmap.iter->next();
	bool cahedmatrix = false;

	for (size_t i = 0; i < entitiesmap.num; i++)
	{
		auto entity = iter->entity();
		iter = iter->next();

		

		if (!entity) continue;
		auto avatar = IS_A(entity, DroppedItem);

		if (!avatar) {
			continue;
		}
		auto testpos = avatar->position();

		//avatar->dump();

		Vector2 testscreen;

		if (!camera->ProjectWorldToScreen(testpos, &testscreen, &cahedmatrix))  continue;

		auto name = avatar->GetName();

		auto color_name = ImColor{ 250, 190, 180, 255 };

		//if (name.size() > 100)
		//{
		//	name = "Item";
		//}
		if (snapline_menu::loot_snapline == true) {
			drawlist->AddLine({ testscreen.x, testscreen.y }, { float(horizontal) / 2, float(vertical) }, color_name);
		}
		drawlist->AddText({ testscreen.x,testscreen.y }, color_name, name.c_str());
	}
}

//===========================================================








//========================= QuestEntity =============================

void QuestObjects_ESP()
{

	auto drawlist = ImGui::GetForegroundDrawList();
	auto entitymanager = EntityManager::instance();
	auto camera = CameraImpl::Instance();
	if (!camera) return;

	auto entitiesmap = entitymanager->Entities();
	auto iter = entitiesmap.iter->next();
	bool cahedmatrix = false;

	for (size_t i = 0; i < entitiesmap.num; i++)
	{
		auto entity = iter->entity();
		iter = iter->next();

		if (!entity) continue;
		auto avatar = IS_A(entity, QuestEntity);

		if (!avatar) {
			continue;
		}
		auto testpos = avatar->position();

		//avatar->dump();

		Vector2 testscreen;

		if (!camera->ProjectWorldToScreen(testpos, &testscreen, &cahedmatrix))  continue;

		auto color_name = ImColor{ 255, 0, 120, 195 };

		if (GetDistance(avatar->position(), player_pos) < 200) {
			drawlist->AddText({ testscreen.x,testscreen.y }, color_name, "Quest Object");

			drawlist->AddText({ testscreen.x,testscreen.y + 12 }, ImColor{ 255, 255, 255, 155 }, (std::string("[") + std::to_string(GetDistance(testpos, player_pos)) + std::string("m] ")).c_str());
		}
	}
}

//===========================================================



//========================= TriggerObject =============================

void TriggerObjects_ESP()
{

	auto drawlist = ImGui::GetForegroundDrawList();
	auto entitymanager = EntityManager::instance();
	auto camera = CameraImpl::Instance();
	if (!camera) return;

	auto entitiesmap = entitymanager->Entities();
	auto iter = entitiesmap.iter->next();
	bool cahedmatrix = false;

	for (size_t i = 0; i < entitiesmap.num; i++)
	{
		auto entity = iter->entity();
		iter = iter->next();

		if (!entity) continue;
		auto avatar = IS_A(entity, TriggerObject);

		if (!avatar) {
			continue;
		}
		auto testpos = avatar->position();
		
		//avatar->dump();

		Vector2 testscreen;

		if (!camera->ProjectWorldToScreen(testpos, &testscreen, &cahedmatrix))  continue;

		auto name = avatar->GetName();
		auto quest = avatar->is_quest();
		auto color_name = ImColor{ 255, 0, 120, 195 };

		if (GetDistance(avatar->position(), player_pos) < 200) {
			drawlist->AddText({ testscreen.x,testscreen.y-15 }, color_name, "Trigger Object");
			drawlist->AddText({ testscreen.x,testscreen.y + 12 }, ImColor{ 255, 255, 255, 155 }, (std::string("[") + std::to_string(GetDistance(testpos, player_pos)) + std::string("m] ")).c_str());
		}
	}
}

//===========================================================






//========================= ObjectInfo =============================

void objectinfo_ESP()
{

	auto drawlist = ImGui::GetForegroundDrawList();
	auto entitymanager = EntityManager::instance();
	auto camera = CameraImpl::Instance();
	if (!camera) return;

	auto entitiesmap = entitymanager->Entities();
	auto iter = entitiesmap.iter->next();
	bool cahedmatrix = false;

	for (size_t i = 0; i < entitiesmap.num; i++)
	{
		auto entity = iter->entity();
		iter = iter->next();

		if (!entity) continue;
		auto avatar = IS_A(entity, ObjectInfo);

		if (!avatar) {
			continue;
		}
		auto testpos = avatar->position();

		//avatar->dump();

		Vector2 testscreen;

		if (!camera->ProjectWorldToScreen(testpos, &testscreen, &cahedmatrix))  continue;

		auto name = avatar->GetName();

		auto color_name = ImColor{ 255, 225, 200, 195 };

		if (GetDistance(avatar->position(), player_pos) < 200) {
			drawlist->AddText({ testscreen.x,testscreen.y }, color_name, name.c_str());
			drawlist->AddText({ testscreen.x,testscreen.y + 12 }, ImColor{ 255, 255, 255, 155 }, (std::string("[") + std::to_string(GetDistance(testpos, player_pos)) + std::string("m] ")).c_str());
		}
	}
}

//===========================================================





//========================= SoundNode =============================

void SoundNode_ESP()
{

	auto drawlist = ImGui::GetForegroundDrawList();
	auto entitymanager = EntityManager::instance();
	auto camera = CameraImpl::Instance();
	if (!camera) return;

	auto entitiesmap = entitymanager->Entities();
	auto iter = entitiesmap.iter->next();
	bool cahedmatrix = false;

	for (size_t i = 0; i < entitiesmap.num; i++)
	{
		auto entity = iter->entity();
		iter = iter->next();

		if (!entity) continue;
		auto avatar = IS_A(entity, SoundNode);

		if (!avatar) {
			continue;
		}
		auto testpos = avatar->position();

		//avatar->dump();

		Vector2 testscreen;

		if (!camera->ProjectWorldToScreen(testpos, &testscreen, &cahedmatrix))  continue;

		auto color_name = ImColor{ 255, 0, 120, 195 };

		if (GetDistance(avatar->position(), player_pos) < 200) {
			drawlist->AddText({ testscreen.x,testscreen.y }, color_name, "Sound");
			drawlist->AddText({ testscreen.x,testscreen.y + 12 }, ImColor{ 255, 255, 255, 155 }, (std::string("[") + std::to_string(GetDistance(testpos, player_pos)) + std::string("m] ")).c_str());
		}
	}
}

void SoundRainNode_ESP()
{

	auto drawlist = ImGui::GetForegroundDrawList();
	auto entitymanager = EntityManager::instance();
	auto camera = CameraImpl::Instance();
	if (!camera) return;

	auto entitiesmap = entitymanager->Entities();
	auto iter = entitiesmap.iter->next();
	bool cahedmatrix = false;

	for (size_t i = 0; i < entitiesmap.num; i++)
	{
		auto entity = iter->entity();
		iter = iter->next();

		if (!entity) continue;
		auto avatar = IS_A(entity, SoundRainNode);

		if (!avatar) {
			continue;
		}
		auto testpos = avatar->position();

		//avatar->dump();

		Vector2 testscreen;

		if (!camera->ProjectWorldToScreen(testpos, &testscreen, &cahedmatrix))  continue;

		auto color_name = ImColor{ 255, 0, 120, 195 };

		if (GetDistance(avatar->position(), player_pos) < 200) {
			drawlist->AddText({ testscreen.x,testscreen.y }, color_name, "Sound Rain");
			drawlist->AddText({ testscreen.x,testscreen.y + 12 }, ImColor{ 255, 255, 255, 155 }, (std::string("[") + std::to_string(GetDistance(testpos, player_pos)) + std::string("m] ")).c_str());
		}
	}
}
void ForestSoundNode_ESP()
{

	auto drawlist = ImGui::GetForegroundDrawList();
	auto entitymanager = EntityManager::instance();
	auto camera = CameraImpl::Instance();
	if (!camera) return;

	auto entitiesmap = entitymanager->Entities();
	auto iter = entitiesmap.iter->next();
	bool cahedmatrix = false;

	for (size_t i = 0; i < entitiesmap.num; i++)
	{
		auto entity = iter->entity();
		iter = iter->next();

		if (!entity) continue;
		auto avatar = IS_A(entity, ForestSoundNode);

		if (!avatar) {
			continue;
		}
		auto testpos = avatar->position();

		//avatar->dump();

		Vector2 testscreen;

		if (!camera->ProjectWorldToScreen(testpos, &testscreen, &cahedmatrix))  continue;

		auto color_name = ImColor{ 255, 0, 120, 195 };

		if (GetDistance(avatar->position(), player_pos) < 200) {
			drawlist->AddText({ testscreen.x,testscreen.y }, color_name, "Sound Forest");
			drawlist->AddText({ testscreen.x,testscreen.y + 12 }, ImColor{ 255, 255, 255, 155 }, (std::string("[") + std::to_string(GetDistance(testpos, player_pos)) + std::string("m] ")).c_str());
		}
	}
}
//===========================================================


//========================= UserFire =============================

void UserFire_ESP()
{

	auto drawlist = ImGui::GetForegroundDrawList();
	auto entitymanager = EntityManager::instance();
	auto camera = CameraImpl::Instance();
	if (!camera) return;

	auto entitiesmap = entitymanager->Entities();
	auto iter = entitiesmap.iter->next();
	bool cahedmatrix = false;

	for (size_t i = 0; i < entitiesmap.num; i++)
	{
		auto entity = iter->entity();
		iter = iter->next();

		if (!entity) continue;
		auto avatar = IS_A(entity, UserFire);

		if (!avatar) {
			continue;
		}
		auto testpos = avatar->position();

		//avatar->dump();

		Vector2 testscreen;

		if (!camera->ProjectWorldToScreen(testpos, &testscreen, &cahedmatrix))  continue;

		auto name = avatar->GetName();
		auto color_name = ImColor{ 250, 190, 180, 255 };

		if (GetDistance(avatar->position(), player_pos) < 200) {
			drawlist->AddText({ testscreen.x,testscreen.y }, color_name, name.c_str());
			drawlist->AddText({ testscreen.x,testscreen.y + 12 }, ImColor{ 255, 255, 255, 155 }, (std::string("[") + std::to_string(GetDistance(testpos, player_pos)) + std::string("m] ")).c_str());
		}
	}
}

//===========================================================


//========================= Workbenches =============================

void Workbenches_ESP()
{

	auto drawlist = ImGui::GetForegroundDrawList();
	auto entitymanager = EntityManager::instance();
	auto camera = CameraImpl::Instance();
	if (!camera) return;

	auto entitiesmap = entitymanager->Entities();
	auto iter = entitiesmap.iter->next();
	bool cahedmatrix = false;

	for (size_t i = 0; i < entitiesmap.num; i++)
	{
		auto entity = iter->entity();
		iter = iter->next();

		if (!entity) continue;
		auto avatar = IS_A(entity, Workbench);

		if (!avatar) {
			continue;
		}
		auto testpos = avatar->position();

		//avatar->dump();

		Vector2 testscreen;

		if (!camera->ProjectWorldToScreen(testpos, &testscreen, &cahedmatrix))  continue;

		auto name = avatar->GetName();
		auto color_name = ImColor{ 250, 190, 180, 255 };

		if (name.size() == 0 || name.size() > 100) {
			name = "Table";
		}

		if (GetDistance(avatar->position(), player_pos) < 200) {
			drawlist->AddText({ testscreen.x,testscreen.y }, color_name, name.c_str());
			drawlist->AddText({ testscreen.x,testscreen.y + 12 }, ImColor{ 255, 255, 255, 155 }, (std::string("[") + std::to_string(GetDistance(testpos, player_pos)) + std::string("m] ")).c_str());
		}
	}
}

void WeaponWorkbenches_ESP()
{

	auto drawlist = ImGui::GetForegroundDrawList();
	auto entitymanager = EntityManager::instance();
	auto camera = CameraImpl::Instance();
	if (!camera) return;

	auto entitiesmap = entitymanager->Entities();
	auto iter = entitiesmap.iter->next();
	bool cahedmatrix = false;

	for (size_t i = 0; i < entitiesmap.num; i++)
	{
		auto entity = iter->entity();
		iter = iter->next();

		if (!entity) continue;
		auto avatar = IS_A(entity, WeaponWorkbench);

		if (!avatar) {
			continue;
		}
		auto testpos = avatar->position();

		//avatar->dump();

		Vector2 testscreen;

		if (!camera->ProjectWorldToScreen(testpos, &testscreen, &cahedmatrix))  continue;

		auto name = avatar->GetName();
		auto color_name = ImColor{ 250, 190, 180, 255 };

		if (name.size() == 0 || name.size() > 100) {
			name = "Weapon Table";
		}

		if (GetDistance(avatar->position(), player_pos) < 200) {
			drawlist->AddText({ testscreen.x,testscreen.y }, color_name, name.c_str());
			drawlist->AddText({ testscreen.x,testscreen.y + 12 }, ImColor{ 255, 255, 255, 155 }, (std::string("[") + std::to_string(GetDistance(testpos, player_pos)) + std::string("m] ")).c_str());
		}
	}
}

//===========================================================



//========================= Ladders =============================

void Ladders_ESP()
{

	auto drawlist = ImGui::GetForegroundDrawList();
	auto entitymanager = EntityManager::instance();
	auto camera = CameraImpl::Instance();
	if (!camera) return;

	auto entitiesmap = entitymanager->Entities();
	auto iter = entitiesmap.iter->next();
	bool cahedmatrix = false;

	for (size_t i = 0; i < entitiesmap.num; i++)
	{
		auto entity = iter->entity();
		iter = iter->next();

		if (!entity) continue;
		auto avatar = IS_A(entity, VerticalLadder);

		if (!avatar) {
			continue;
		}
		auto testpos = avatar->position();

		//avatar->dump();

		Vector2 testscreen;

		if (!camera->ProjectWorldToScreen(testpos, &testscreen, &cahedmatrix))  continue;

		auto name = avatar->GetName();
		auto color_name = ImColor{ 250, 190, 180, 255 };

		if (name.size() == 0 || name.size() > 100) {
			name = "Ladders";
		}

		if (GetDistance(avatar->position(), player_pos) < 200) {
			drawlist->AddText({ testscreen.x,testscreen.y }, color_name, name.c_str());
			drawlist->AddText({ testscreen.x,testscreen.y + 12 }, ImColor{ 255, 255, 255, 155 }, (std::string("[") + std::to_string(GetDistance(testpos, player_pos)) + std::string("m] ")).c_str());
		}
	}
}

//===========================================================



//========================= VerminSpawners =============================

void VerminSpawners_ESP()
{

	auto drawlist = ImGui::GetForegroundDrawList();
	auto entitymanager = EntityManager::instance();
	auto camera = CameraImpl::Instance();
	if (!camera) return;

	auto entitiesmap = entitymanager->Entities();
	auto iter = entitiesmap.iter->next();
	bool cahedmatrix = false;

	for (size_t i = 0; i < entitiesmap.num; i++)
	{
		auto entity = iter->entity();
		iter = iter->next();

		if (!entity) continue;
		auto avatar = IS_A(entity, VerminSpawner);

		if (!avatar) {
			continue;
		}
		auto testpos = avatar->position();

		//avatar->dump();

		Vector2 testscreen;

		if (!camera->ProjectWorldToScreen(testpos, &testscreen, &cahedmatrix))  continue;

		auto name = avatar->GetName();
		auto color_name = ImColor{ 250, 190, 180, 255 };

		if (GetDistance(avatar->position(), player_pos) < 200) {
			drawlist->AddText({ testscreen.x,testscreen.y }, color_name, "Spawner");
			drawlist->AddText({ testscreen.x,testscreen.y + 12 }, ImColor{ 255, 255, 255, 155 }, (std::string("[") + std::to_string(GetDistance(testpos, player_pos)) + std::string("m] ")).c_str());
		}
	}
}

//===========================================================





//========================= Recommendations =============================

void Recommendations_ESP()
{

	auto drawlist = ImGui::GetForegroundDrawList();
	auto entitymanager = EntityManager::instance();
	auto camera = CameraImpl::Instance();
	if (!camera) return;

	auto entitiesmap = entitymanager->Entities();
	auto iter = entitiesmap.iter->next();
	bool cahedmatrix = false;

	for (size_t i = 0; i < entitiesmap.num; i++)
	{
		auto entity = iter->entity();
		iter = iter->next();



		if (!entity) continue;
		auto avatar = IS_A(entity, ZoneEffects);

		if (!avatar) {
			continue;
		}
		auto testpos = avatar->position();
		auto is_in_area = avatar->is_player_in_area();
		auto is_active = avatar->effectID();
		if (is_in_area) {
			if (is_active == 86) {
				drawlist->AddText({ 876,20 }, ImColor{ 255, 30, 30, 255 }, "IT'S DANGEROUS HERE PUT ON A GAS MASK");
			}
			
		}

		//avatar->dump();

		Vector2 testscreen;

		if (!camera->ProjectWorldToScreen(testpos, &testscreen, &cahedmatrix))  continue;

		auto color_name = ImColor{ 180, 255, 106, 255 };


		if (is_active == 9) {
			if (is_in_area) {
				drawlist->AddText({ testscreen.x - 85,testscreen.y - 15 }, color_name, "YOU WARM UP FROM THE FIRE AND REPLENISH YOUR STRENGTH");
			}
			drawlist->AddText({ testscreen.x - 25,testscreen.y }, color_name, "HERE YOU CAN RELAX");
		}
		else if (is_active == 86) {
			drawlist->AddText({ testscreen.x,testscreen.y }, color_name, "Polluted air");
		}
		else if (is_active == 70) {
			if (is_in_area) {
				drawlist->AddText({ testscreen.x - 85,testscreen.y - 15 }, color_name, "PUT ON A CLOSED-TYPE GAS MASK, YOU CAN GET AN EYE BURN");
			}
			drawlist->AddText({ testscreen.x,testscreen.y }, color_name, "Toxic fumes");
		}
		else {
			drawlist->AddText({ testscreen.x,testscreen.y-30 }, color_name, std::to_string(is_active).c_str());
		}	
		drawlist->AddText({ testscreen.x,testscreen.y + 12 }, ImColor{ 255, 255, 255, 155 }, (std::string("[") + std::to_string(GetDistance(testpos, player_pos)) + std::string("m] ")).c_str());
	}
}

void PostProcessZone_ESP()
{

	auto drawlist = ImGui::GetForegroundDrawList();
	auto entitymanager = EntityManager::instance();
	auto camera = CameraImpl::Instance();
	if (!camera) return;

	auto entitiesmap = entitymanager->Entities();
	auto iter = entitiesmap.iter->next();
	bool cahedmatrix = false;

	for (size_t i = 0; i < entitiesmap.num; i++)
	{
		auto entity = iter->entity();
		iter = iter->next();



		if (!entity) continue;
		auto avatar = IS_A(entity, PostProcessZone);

		if (!avatar) {
			continue;
		}
		auto testpos = avatar->position();


		//avatar->dump();

		Vector2 testscreen;

		if (!camera->ProjectWorldToScreen(testpos, &testscreen, &cahedmatrix))  continue;


		auto name = avatar->GetName();
		auto in_area = avatar->in_area();
		auto color_name = ImColor{ 180, 255, 106, 255 };

		if (GetDistance(avatar->position(), player_pos) < 210) {
			if (name == "press") {
				if (in_area) {
					drawlist->AddText({ testscreen.x - 85,testscreen.y - 15 }, color_name, "BE CAREFUL YOU ARE IN THE ZONE OF TEMPTATION");
				}
				drawlist->AddText({ testscreen.x - 25,testscreen.y }, color_name, "Temptation");
			}
			else {
				drawlist->AddText({ testscreen.x - 25,testscreen.y }, color_name, name.c_str());
			}
			drawlist->AddText({ testscreen.x,testscreen.y + 12 }, ImColor{ 255, 255, 255, 155 }, (std::string("[") + std::to_string(GetDistance(testpos, player_pos)) + std::string("m] ")).c_str());
		}
	}
}

void DrawWell_ESP()
{

	auto drawlist = ImGui::GetForegroundDrawList();
	auto entitymanager = EntityManager::instance();
	auto camera = CameraImpl::Instance();
	if (!camera) return;

	auto entitiesmap = entitymanager->Entities();
	auto iter = entitiesmap.iter->next();
	bool cahedmatrix = false;

	for (size_t i = 0; i < entitiesmap.num; i++)
	{
		auto entity = iter->entity();
		iter = iter->next();



		if (!entity) continue;
		auto avatar = IS_A(entity, DrawWell);

		if (!avatar) {
			continue;
		}
		auto testpos = avatar->position();


		//avatar->dump();

		Vector2 testscreen;

		if (!camera->ProjectWorldToScreen(testpos, &testscreen, &cahedmatrix))  continue;


		auto name = avatar->GetName();
		auto color_name = ImColor{ 180, 255, 106, 255 };


		if (GetDistance(avatar->position(), player_pos) < 210) {
			drawlist->AddText({ testscreen.x,testscreen.y }, color_name, name.c_str());
			if (GetDistance(avatar->position(), player_pos) < 8) {
				drawlist->AddText({ testscreen.x - 65,testscreen.y - 15 }, color_name, "HERE YOU CAN COLLECT OR DRINK WATER");
			}
			drawlist->AddText({ testscreen.x,testscreen.y + 12 }, ImColor{ 255, 255, 255, 155 }, (std::string("[") + std::to_string(GetDistance(testpos, player_pos)) + std::string("m] ")).c_str());
		}
	}
}

//===========================================================






//=================== NOTES =====================
void Notes_ESP()
{

	auto drawlist = ImGui::GetForegroundDrawList();
	auto entitymanager = EntityManager::instance();
	auto camera = CameraImpl::Instance();
	if (!camera) return;

	auto entitiesmap = entitymanager->Entities();
	auto iter = entitiesmap.iter->next();
	bool cahedmatrix = false;

	for (size_t i = 0; i < entitiesmap.num; i++)
	{
		auto entity = iter->entity();
		iter = iter->next();

		if (!entity) continue;
		auto avatar = IS_A(entity, StoriesEntity);

		if (!avatar) {
			continue;
		}
		auto testpos = avatar->position();

		//avatar->dump();

		Vector2 testscreen;

		if (!camera->ProjectWorldToScreen(testpos, &testscreen, &cahedmatrix))  continue;

		auto name = avatar->GetName();
		auto is_active = avatar->IsActive();
		auto color_name = ImColor{ 250, 190, 180, 255 };

		if (name.size() == 0 || name.size() > 100) {
			name = "Note";
		}
		if (menu_vars4::esp_only_active_notes) {
			if (!is_active) {
				if (GetDistance(avatar->position(), player_pos) < 200) {
					drawlist->AddText({ testscreen.x,testscreen.y }, color_name, name.c_str());
					drawlist->AddText({ testscreen.x,testscreen.y + 12 }, ImColor{ 255, 255, 255, 155 }, (std::string("[") + std::to_string(GetDistance(testpos, player_pos)) + std::string("m] ")).c_str());
				}
			}
		}
		if (!menu_vars4::esp_only_active_notes) {
			if (GetDistance(avatar->position(), player_pos) < 200) {
				drawlist->AddText({ testscreen.x,testscreen.y }, color_name, name.c_str());
				drawlist->AddText({ testscreen.x,testscreen.y + 12 }, ImColor{ 255, 255, 255, 155 }, (std::string("[") + std::to_string(GetDistance(testpos, player_pos)) + std::string("m] ")).c_str());
			}
		}
	}
}

//==========================================================





void testESP()
{

	auto drawlist = ImGui::GetForegroundDrawList();
	auto entitymanager = EntityManager::instance();
	auto camera = CameraImpl::Instance();
	if (!camera) return;

	auto entitiesmap = entitymanager->Entities();
	auto iter = entitiesmap.iter->next();
	bool cahedmatrix = false;

	for (size_t i = 0; i < entitiesmap.num; i++)
	{
		auto entity = iter->entity();
		iter = iter->next();

		if (!entity) continue;
		auto avatar = IS_A(entity, ClientTrigger);

		if (!avatar) {
			continue;
		}
		auto testpos = avatar->position();

		//avatar->dump();

		Vector2 testscreen;

		if (!camera->ProjectWorldToScreen(testpos, &testscreen, &cahedmatrix))  continue;

		auto name = avatar->GetName();
		auto color_name = ImColor{ 250, 190, 180, 255 };

		drawlist->AddText({ testscreen.x,testscreen.y }, color_name, name.c_str());
		drawlist->AddText({ testscreen.x,testscreen.y + 12 }, ImColor{ 255, 255, 255, 155 }, (std::string("[") + std::to_string(GetDistance(testpos, player_pos)) + std::string("m] ")).c_str());
	}
}













void RADAR_ESP_N() {
	auto drawlist = ImGui::GetForegroundDrawList();
	auto entitymanager = EntityManager::instance();
	auto camera = CameraImpl::Instance();
	if (!camera) return;

	auto entitiesmap = entitymanager->Entities();
	auto iter = entitiesmap.iter->next();
	bool cahedmatrix = false;

	auto color_nameNPC = ImColor{ 0, 255, 26, 155 };

	for (size_t i = 0; i < entitiesmap.num; i++)
	{
		auto entity = iter->entity();
		iter = iter->next();
		if (!entity) continue;
		auto avatar = IS_A(entity, NPC);
		if (!avatar) continue;

		auto testpos = avatar->position();

		//avatar->dump();

		Vector2 testscreen;

		if (!camera->ProjectWorldToRadar(testpos, player_pos, &testscreen, espent::esp_radar_radius, &cahedmatrix))  continue;
		drawlist->AddText({ testscreen.x,testscreen.y }, color_nameNPC, "N");
		//auto avatar =  (NPC*)Entity;


	}
}
void RADAR_ESP_P() {
	auto drawlist = ImGui::GetForegroundDrawList();
	auto entitymanager = EntityManager::instance();
	auto camera = CameraImpl::Instance();
	if (!camera) return;

	auto entitiesmap = entitymanager->Entities();
	auto iter = entitiesmap.iter->next();
	bool cahedmatrix = false;

	auto color_namePeople = ImColor{ 255, 255, 0, 155 };

	for (size_t i = 0; i < entitiesmap.num; i++)
	{
		auto entity = iter->entity();
		iter = iter->next();
		if (!entity) continue;
		auto avatar = IS_A(entity, Avatar);
		if (!avatar) continue;

		auto testpos = avatar->position();

		//avatar->dump();

		Vector2 testscreen;

		if (!camera->ProjectWorldToRadar(testpos, player_pos, &testscreen, espent::esp_radar_radius, &cahedmatrix))  continue;
		drawlist->AddText({ testscreen.x,testscreen.y }, color_namePeople, "P");
		//auto avatar =  (NPC*)Entity;


	}
}
void RADAR_ESP_M() {
	auto drawlist = ImGui::GetForegroundDrawList();
	auto entitymanager = EntityManager::instance();
	auto camera = CameraImpl::Instance();
	if (!camera) return;

	auto entitiesmap = entitymanager->Entities();
	auto iter = entitiesmap.iter->next();
	bool cahedmatrix = false;

	auto color_nameMobs = ImColor{ 0, 255, 235, 155 };
	auto color_dead = ImColor{ 38, 53, 255, 100 };

	for (size_t i = 0; i < entitiesmap.num; i++)
	{
		auto entity = iter->entity();
		iter = iter->next();
		if (!entity) continue;
		auto avatar = IS_A(entity, Creature);
		if (!avatar) continue;

		auto testpos = avatar->position();

		//avatar->dump();

		Vector2 testscreen;

		if (!camera->ProjectWorldToRadar(testpos, player_pos, &testscreen, espent::esp_radar_radius, &cahedmatrix))  continue;
		if (avatar->is_dead()) {
			drawlist->AddText({ testscreen.x,testscreen.y }, color_dead, "M");
			continue;
		}
			
		drawlist->AddText({ testscreen.x,testscreen.y }, color_nameMobs, "M");
		//auto avatar =  (NPC*)Entity;


	}
}
void RADAR_ESP_A() {
	auto drawlist = ImGui::GetForegroundDrawList();
	auto entitymanager = EntityManager::instance();
	auto camera = CameraImpl::Instance();
	if (!camera) return;

	auto entitiesmap = entitymanager->Entities();
	auto iter = entitiesmap.iter->next();
	bool cahedmatrix = false;

	auto color_nameAnomalies = ImColor{ 255, 128, 0, 255 };

	for (size_t i = 0; i < entitiesmap.num; i++)
	{
		auto entity = iter->entity();
		iter = iter->next();
		if (!entity) continue;
		auto avatar = IS_A(entity, Anomaly);
		if (!avatar) continue;

		auto testpos = avatar->position();

		//avatar->dump();

		Vector2 testscreen;

		if (!camera->ProjectWorldToRadar(testpos, player_pos, &testscreen, espent::esp_radar_radius, &cahedmatrix))  continue;

		drawlist->AddText({ testscreen.x,testscreen.y }, color_nameAnomalies, "A");
		//auto avatar =  (NPC*)Entity;


	}
}



void RADAR_ESP_PA() {
	auto drawlist = ImGui::GetForegroundDrawList();
	auto entitymanager = EntityManager::instance();
	auto camera = CameraImpl::Instance();
	if (!camera) return;

	auto entitiesmap = entitymanager->Entities();
	auto iter = entitiesmap.iter->next();
	bool cahedmatrix = false;


	for (size_t i = 0; i < entitiesmap.num; i++)
	{
		auto entity = iter->entity();
		iter = iter->next();
		if (!entity) continue;
		auto avatar = IS_A(entity, PlayerAvatar);
		if (!avatar) continue;

		auto testpos = avatar->position();

		//avatar->dump();

		Vector2 testscreen;

		if (!camera->ProjectWorldToRadar(testpos, player_pos, &testscreen, espent::esp_radar_radius, &cahedmatrix))  continue;
		drawlist->AddText({ testscreen.x,testscreen.y }, ImColor{255,255,255,255}, "*");
		//auto avatar =  (NPC*)Entity;


	}
}









void test() {
	auto drawlist = ImGui::GetForegroundDrawList();
	auto entitymanager = EntityManager::instance();
	auto camera = CameraImpl::Instance();
	if (!camera) return;

	auto entitiesmap = entitymanager->Entities();
	auto iter = entitiesmap.iter->next();
	bool cahedmatrix = false;


	for (size_t i = 0; i < entitiesmap.num; i++)
	{
		auto entity = iter->entity();
		iter = iter->next();
		if (!entity) continue;
		auto avatar = IS_A(entity, Stone);
		if (!avatar) continue;

		//avatar->dump();

		Vector2 testscreen;
		avatar->position_change(min_dist_anomaly_pos);
		if (!camera->ProjectWorldToScreen(avatar->position(), &testscreen, &cahedmatrix))  continue;
		
		drawlist->AddText({ testscreen.x,testscreen.y }, ImColor{ 255,255,255,255 }, "stone");
		drawlist->AddText({ testscreen.x,testscreen.y-15 }, ImColor{ 255,255,255,255 }, std::to_string(avatar->entity_id()).c_str());
		//auto avatar =  (NPC*)Entity;


	}
}



struct Config
{
	int distance_magnit = exploit::distance_magnit;
	int radius_magnit = exploit::radius_magnit;
	int player_count_limit = exploit::player_count_limit;
	int kilobyte_rate = exploit::kilobyte_rate;
	float aim_speed_creature = menu_vars3::aim_speed_creature;
	float aim_smooth_creature = menu_vars3::aim_smooth_creature;
	float aim_high = menu_vars2::aim_high;
	float aim_speed_people = menu_vars2::aim_speed_people;
	float aim_smooth_people = menu_vars2::aim_smooth_people;
	float size_c = menu_vars3::size_c;
	int bright_int = exploit::bright_int;
	int esp_radar_radius = espent::esp_radar_radius;
	

	bool esp_nick = espent::esp_nick;
	bool esp_radar = espent::esp_radar;
	bool esp_radar_p = espent::esp_radar_p;
	bool esp_radar_n = espent::esp_radar_n;
	bool esp_radar_m = espent::esp_radar_m;
	bool esp_clanName = espent::esp_clanName;
	bool esp_creature_live = espent::esp_creature_live;
	bool esp_creature_dead = espent::esp_creature_dead;
	bool esp_npc_name = espent::esp_npc_name;
	bool esp_anomaly = espent::esp_anomaly;
	bool esp_Container = espent::esp_Container;
	bool esp_artefact = espent::esp_artefact;
	bool esp_aimbox = espent::esp_aimbox;
	bool esp_people_box = espent::esp_people_box;
	bool esp_people_fill_box = espent::esp_people_fill_box;
	bool esp_notes = espent::esp_notes;
	bool esp_loot = espent::esp_loot;
	bool esp_recommendations = espent::esp_recommendations;
	bool esp_radar_a = espent::esp_radar_a;
	bool esp_checked_anomaly = espent::esp_checked_anomaly;
	bool esp_ladders = espent::esp_ladders;
	bool esp_tables = espent::esp_tables;
	bool esp_fires = espent::esp_fires;
	bool esp_info = espent::esp_info;
	bool esp_spawner = espent::esp_spawner;
	bool esp_quest_objects = espent::esp_quest_objects;
	bool esp_sound_objects = espent::esp_sound_objects;
	bool esp_trigger_objects = espent::esp_trigger_objects;
	bool esp_visible_players = espent::esp_visible_players;
	bool aim_player = menu_vars2::aim_player;
	bool aim_clan_player = menu_vars2::aim_clan_player;
	bool aim_creature = menu_vars3::aim_creature;
	bool esp_kills_people = menu_vars4::esp_kills_people;
	bool esp_karma_people = menu_vars4::esp_karma_people;
	bool esp_cantakedamage_people = menu_vars4::esp_cantakedamage_people;
	bool esp_accesslevel_people = menu_vars4::esp_accesslevel_people;
	bool esp_blacklist_people = menu_vars4::esp_blacklist_people;
	bool freeze_packets = exploit::freeze_packets;
	bool anomaly_protect = exploit::anomaly_protect;
	bool legit_magnit_anomaly = exploit::legit_magnit_anomaly;
	bool magnit_anomaly = exploit::magnit_anomaly;
	bool tp_people = exploit::magnit_people;
	bool tp_creature = exploit::tp_creature;
	bool anomaly_snapline = snapline_menu::anomaly_snapline;
	bool artefact_snapline = snapline_menu::artefact_snapline;
	bool container_snapline = snapline_menu::container_snapline;
	bool creature_snapline = snapline_menu::creature_snapline;
	bool loot_snapline = snapline_menu::loot_snapline;
	bool npc_snapline = snapline_menu::npc_snapline;
	bool players_snapline = snapline_menu::players_snapline;
	bool bright = exploit::bright;
	bool panic_key = menu_vars4::panic_key;
	bool name_anomalies = menu_vars4::name_anomalies;
	bool memorizer_artefacts = menu_vars4::memorizer_artefacts;
};




void SaveConfig(Config* ArGa)
{
	DWORD dwBytesWritten;
	HANDLE hOut = CreateFileA("Config.panel", GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hOut != INVALID_HANDLE_VALUE) {
		WriteFile(hOut, *&ArGa, sizeof(Config), &dwBytesWritten, NULL);
		CloseHandle(hOut);
	}
}

void ReadConfig(Config* ArGa)
{
	DWORD dwBytesWritten;
	HANDLE hOut = CreateFileA("Config.panel", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hOut != INVALID_HANDLE_VALUE) {
		ReadFile(hOut, *&ArGa, sizeof(Config), &dwBytesWritten, NULL);
		espent::esp_nick = ArGa[0].esp_nick;
		espent::esp_radar = ArGa[0].esp_radar;
		espent::esp_radar_p = ArGa[0].esp_radar_p;
		espent::esp_radar_m = ArGa[0].esp_radar_m;
		espent::esp_radar_n = ArGa[0].esp_radar_n;
		espent::esp_clanName = ArGa[0].esp_clanName;
		espent::esp_creature_live = ArGa[0].esp_creature_live;
		espent::esp_creature_dead = ArGa[0].esp_creature_dead;
		espent::esp_npc_name = ArGa[0].esp_npc_name;
		espent::esp_anomaly = ArGa[0].esp_anomaly;
		espent::esp_Container = ArGa[0].esp_Container;
		espent::esp_artefact = ArGa[0].esp_artefact;
		menu_vars2::aim_player = ArGa[0].aim_player;
		menu_vars2::aim_clan_player = ArGa[0].aim_clan_player;
		menu_vars3::aim_creature = ArGa[0].aim_creature;
		menu_vars4::esp_kills_people = ArGa[0].esp_kills_people;
		menu_vars4::esp_karma_people = ArGa[0].esp_karma_people;
		menu_vars4::esp_cantakedamage_people = ArGa[0].esp_cantakedamage_people;
		menu_vars4::esp_accesslevel_people = ArGa[0].esp_accesslevel_people;
		menu_vars4::esp_blacklist_people = ArGa[0].esp_blacklist_people;
		exploit::freeze_packets = ArGa[0].freeze_packets;
		exploit::magnit_anomaly = ArGa[0].magnit_anomaly;
		exploit::tp_people = ArGa[0].tp_people;
		exploit::tp_creature = ArGa[0].tp_creature;
		snapline_menu::anomaly_snapline = ArGa[0].anomaly_snapline;
		snapline_menu::creature_snapline = ArGa[0].creature_snapline;
		snapline_menu::players_snapline = ArGa[0].players_snapline;
		snapline_menu::npc_snapline = ArGa[0].npc_snapline;
		snapline_menu::loot_snapline = ArGa[0].loot_snapline;
		snapline_menu::artefact_snapline = ArGa[0].artefact_snapline;
		snapline_menu::container_snapline = ArGa[0].container_snapline;
		CloseHandle(hOut);
	}
}

Config con[10];




void ReadParametrss(Config test[]) {
	test[0].esp_nick = espent::esp_nick;
	test[0].esp_radar = espent::esp_radar;
	test[0].esp_radar_p =espent::esp_radar_p;
	test[0].esp_radar_n = espent::esp_radar_n;
	test[0].esp_radar_m = espent::esp_radar_m;
	test[0].esp_clanName = espent::esp_clanName;
	test[0].esp_creature_live = espent::esp_creature_live;
	test[0].esp_creature_dead = espent::esp_creature_dead;
	test[0].esp_npc_name = espent::esp_npc_name;
	test[0].esp_anomaly = espent::esp_anomaly;
	test[0].esp_Container = espent::esp_Container;
	test[0].esp_artefact = espent::esp_artefact;
	test[0].aim_player = menu_vars2::aim_player;
	test[0].aim_clan_player = menu_vars2::aim_clan_player;
	test[0].aim_creature = menu_vars3::aim_creature;
	test[0].esp_kills_people = menu_vars4::esp_kills_people;
	test[0].esp_karma_people = menu_vars4::esp_karma_people;
	test[0].esp_cantakedamage_people = menu_vars4::esp_cantakedamage_people;
	test[0].esp_accesslevel_people = menu_vars4::esp_accesslevel_people;
	test[0].esp_blacklist_people = menu_vars4::esp_blacklist_people;
	test[0].freeze_packets = exploit::freeze_packets;
	test[0].anomaly_protect = exploit::anomaly_protect;
	test[0].legit_magnit_anomaly = exploit::legit_magnit_anomaly;
	test[0].magnit_anomaly = exploit::magnit_anomaly;
	test[0].tp_people = exploit::magnit_people;
	test[0].tp_creature = exploit::tp_creature;
	test[0].anomaly_snapline = snapline_menu::anomaly_snapline;
	test[0].artefact_snapline = snapline_menu::artefact_snapline;
	test[0].container_snapline = snapline_menu::container_snapline;
	test[0].creature_snapline = snapline_menu::creature_snapline;
	test[0].loot_snapline = snapline_menu::loot_snapline;
	test[0].npc_snapline = snapline_menu::npc_snapline;
	test[0].players_snapline = snapline_menu::players_snapline;
}




void draw_esp()
{
	auto drawlist = ImGui::GetForegroundDrawList();
	auto fps = std::to_string(ImGui::GetIO().Framerate);
	//drawlist->AddText({ 20,20 }, ImColor{ 255,255,255,255 }, fps.c_str());

	if (espent::esp_loot) {
		LOOT_ESP();
	}
	//DETECTED FUNCTION
	//if (menu_vars4::speed_key) {
	//	speed();
	//}
	if (espent::esp_nick)
	{
		NickNameESP();
	}
	//if (menu_vars4::mza_bot)
	//{
	//	test();
	//}
	if (espent::esp_npc_name)
	{
		NPC_ESP();
	}
	if (espent::esp_creature_live) {
		CreatureLiveESP();
	}
	if (espent::esp_anomaly)
	{
		AnomalyESP();
	}
	if (espent::esp_Container)
	{
		ContainerESP();
	}
	if (espent::esp_test)
	{
		testESP();
	}
	if (espent::esp_notes)
	{
		Notes_ESP();
	}
	if (espent::esp_quest_objects) {
		QuestObjects_ESP();
	}
	if (espent::esp_trigger_objects) {
		TriggerObjects_ESP();
	}
	if (espent::esp_info) {
		objectinfo_ESP();
	}
	if (espent::esp_sound_objects) {
		SoundNode_ESP();
		ForestSoundNode_ESP();
		SoundRainNode_ESP();
	}
	if (espent::esp_fires) {
		UserFire_ESP();
	}
	if (espent::esp_ladders) {
		Ladders_ESP();
	}
	if (espent::esp_spawner) {
		VerminSpawners_ESP();
	}
	if (espent::esp_tables) {
		Workbenches_ESP();
		WeaponWorkbenches_ESP();
	}
	if (espent::esp_recommendations) {
		Recommendations_ESP();
		PostProcessZone_ESP();
		DrawWell_ESP();
	}
	if (!espent::esp_checked_anomaly) {
		checked_anomalies.clear();
	}
	if (!menu_vars4::memorizer_artefacts) {
		artefacts_in_anomalies.clear();
	}
	if (espent::esp_radar) {
		auto drawlist = ImGui::GetForegroundDrawList();
		RADAR_ESP_PA();
		//for (int i = 0; i < 5; i++) {
		//	drawlist->AddCircle(ImVec2{ 150, 150 }, 150 - i, ImColor(250, 250, 250, 255));
		//}
		std::string radius_of_radar_text = (std::string("[") + std::to_string(espent::esp_radar_radius) + std::string("m]")).c_str();
		drawlist->AddText(ImVec2( 33, 33 ), ImColor(250, 250, 250, 255), radius_of_radar_text.c_str());
		for (int i = 0; i < 3; i++) {
			drawlist->AddRect({ float(30 - i), float(30 - i) }, { float(250+i), float(250 + i) }, ImColor(230, 230, 230, 255));
		}
		drawlist->AddRectFilled({ 30, 30 }, { 250, 250}, ImColor(230, 230, 230, 55));
		if (espent::esp_radar_n) {
			RADAR_ESP_N();
		}
		if (espent::esp_radar_p) {
			RADAR_ESP_P();
		}
		if (espent::esp_radar_a) {
			RADAR_ESP_A();
		}
		if (espent::esp_radar_m) {
			RADAR_ESP_M();
		}
	}
	if (exploit::freeze_packets > 20 || exploit::freeze_packets < 0) {
		exploit::freeze_packets = 0;
	}
	if (exploit::distance_magnit > 100 || exploit::distance_magnit < 0) {
		exploit::distance_magnit = 0;
	}
	if (exploit::radius_magnit < 100 || exploit::radius_magnit > 1500) {
		exploit::radius_magnit = 0;
	}
	if (espent::esp_radar_radius > 210 || espent::esp_radar_radius < 0) {
		espent::esp_radar_radius = 0;
	}
	if (exploit::player_count_limit > 4 || exploit::player_count_limit < 0) {
		exploit::player_count_limit = 0;
	}
	if (settings::size_sh < 12 || settings::size_sh > 25) {
		settings::size_sh = 12;
	}
	if (exploit::no_clip_distance < 1 || exploit::no_clip_distance > 50) {
		exploit::no_clip_distance = 1;
	}
	if (temp_tp == 1) {
		auto drawlist = ImGui::GetForegroundDrawList();
		drawlist->AddText(ImVec2(horizontal / 2 - 220, 57), ImColor{ 255,170,0,255 }, "ВНИМАНИЕ ЧТОБЫ СНОВА ТЕЛЕПОРТИРОВАТЬСЯ НА СПАВН, НУЖНО ПЕРЕЗАЙТИ В ИГРОВОЙ МИР");
	}
	if (exploit::bright == true) {
		drawlist->AddRectFilled(ImVec2(0, 0), ImVec2(horizontal, vertical), ImColor(255, 255, 255, exploit::bright_int));
	}
	if (exploit::bright_int < 0) {
		exploit::bright_int = 0;
	}
	if (exploit::bright_int > 30) {
		exploit::bright_int = 0;
	}
	if (exploit::freeze_packets == true) {
		if (temp_freeze == 1) {
			drawlist->AddText(ImVec2(horizontal / 2 - 40, 77 ), ImColor{ 255,170,0,255 }, "Freeze ON ");
		}
		if (GetAsyncKeyState(VK_F1) != 0) {
			temp_freeze = 1;
			SwitchON();
		}
		if (GetAsyncKeyState(VK_F2) != 0) {
			temp_freeze = 0;
			SwitchOFF();
		}

	}
	if (exploit::tp_people){
		drawlist->AddText({ float(horizontal / 2) - 20,10 }, ImColor{ 255,170,0,255 }, "WARNING !");
		drawlist->AddText({ float(horizontal / 2) - 130,25 }, ImColor{ 0,220,189,255 }, "Teleport in beta test, please use this function very carefully");
		drawlist->AddText({ float(horizontal / 2) - 220,40 }, ImColor{ 0,220,189,255 }, "Do not use this when moving and do not spam the teleportation hotkey and WASD, you may get banned");
	}
	if (espent::test) {
		PlayerAvatar_func();
	}
	if (menu_vars4::crosshair)
	{
		auto draw2 = ImGui::GetBackgroundDrawList();
		draw2->AddCircle(ImVec2(horizontal / 2, vertical / 2), 95, IM_COL32(235, 255, 235, 55), 150);
	}
}


void update_vsync()
{
	D3DPRESENT_PARAMETERS params;
	IDirect3DSwapChain9* swapchain; // D3DPRESENT_PARAMETERS*
	DirectX9.pDevice->GetSwapChain(0, &swapchain);
	if (swapchain)
	{
		swapchain->GetPresentParameters(&params);

		params.PresentationInterval = espent::overlay_vsync ? D3DPRESENT_INTERVAL_DEFAULT : D3DPRESENT_INTERVAL_IMMEDIATE;
		DirectX9.pDevice->Reset(&params);
	}
}
void update_resolution()
{
	D3DPRESENT_PARAMETERS params;
	IDirect3DSwapChain9* swapchain; // D3DPRESENT_PARAMETERS*
	DirectX9.pDevice->GetSwapChain(0, &swapchain);
	if (swapchain)
	{
		swapchain->GetPresentParameters(&params);
		if (params.BackBufferWidth != Process.WindowWidth)
		{
			params.BackBufferWidth = Process.WindowWidth;
			horizontal = Process.WindowWidth;
			params.BackBufferHeight = Process.WindowHeight;
			vertical = Process.WindowHeight;
			DirectX9.pDevice->Reset(&params);
		}

	}
}


void draw_menu()
{

	if (main::show_menu)
	{
		static int corner = 0;
		ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize;
		ImGui::SetNextWindowBgAlpha(0.75f); // Transparent background
		if (ImGui::Begin("  TERAGEN CHEAT", &main::show_menu, window_flags))
		{
			ImGui::SetWindowPos(ImVec2(horizontal / 2 - ImGui::GetWindowSize().x / 2, vertical / 2 - ImGui::GetWindowSize().y / 2));
			ImGui::SetWindowSize(ImVec2(486, 559.3));
			ImGui::TextColored(ImVec4(255, 255, 255, 1), " MENU");
			if (ImGui::Button("WallHack", ImVec2(80.f, 30.f))) {
				tabb = 1;
			}
			ImGui::SameLine(0.f, 13.f);
			if (ImGui::Button("SnapLines", ImVec2(80.f, 30.f))) {
				tabb = 5;
			}
			ImGui::SameLine(0.f, 13.f);
			if (ImGui::Button("AimBot", ImVec2(80.f, 30.f))) {
				tabb = 2;
			}
			ImGui::SameLine(0.f, 13.f);
			if (ImGui::Button("Exploits", ImVec2(80.f, 30.f))) {
				tabb = 3;
			}
			ImGui::SameLine(0.f, 13.f);
			if (ImGui::Button("Misc", ImVec2(80.f, 30.f))) {
				tabb = 4;
			}
			//ImGui::BeginGroup();
			//ImGui::TextColored(ImVec4(255, 255, 255, 1), "Config Settings");
			//if (ImGui::Button("Save Config")) {
			//	ReadParametrss(con);
			//	SaveConfig(con);
			//}
			//ImGui::SameLine(0.f, 13.f);
			//if (ImGui::Button("Load Config")) {
			//	ReadConfig(con);
			//}
			//ImGui::Text("");
			//ImGui::EndGroup();
			ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.12f, 0.12f, 0.13f, 0.0f));
			if (ImGui::BeginChild("Scrolling", ImVec2(-0.3, 0), true)) {
				if (tabb == 1) {
					ImGui::TextColored(ImVec4(255, 255, 255, 1), " ESP");
					ImGui::Checkbox("ESP Players", &espent::esp_nick);
					ImGui::Checkbox("ESP AIM Point", &espent::esp_aimbox);
					ImGui::Checkbox("ESP Filled BOX", &espent::esp_people_fill_box);
					ImGui::Checkbox("ESP BOX", &espent::esp_people_box);
					ImGui::Checkbox("ESP Visibles", &espent::esp_visible_players);
					ImGui::Checkbox("ESP ClanTag", &espent::esp_clanName);
					ImGui::Checkbox("ESP NPC", &espent::esp_npc_name);
					ImGui::Checkbox("ESP Alive mobs", &espent::esp_creature_live);
					ImGui::Checkbox("ESP Dead mobs", &espent::esp_creature_dead);
					ImGui::Checkbox("ESP Anomaly", &espent::esp_anomaly);
					ImGui::Checkbox("ESP Artefact", &espent::esp_artefact);
					ImGui::Checkbox("ESP Containers", &espent::esp_Container);
					ImGui::Checkbox("ESP Loot", &espent::esp_loot);
					ImGui::Checkbox("ESP Quest objects", &espent::esp_quest_objects);
					ImGui::Checkbox("ESP Sound objects", &espent::esp_sound_objects);
					ImGui::Checkbox("ESP Trigger objects", &espent::esp_trigger_objects);
					ImGui::Checkbox("ESP Fires of players", &espent::esp_fires);
					ImGui::Checkbox("ESP Crafting tables", &espent::esp_tables);
					ImGui::Checkbox("ESP Tips", &espent::esp_recommendations);
					ImGui::Checkbox("ESP Signs", &espent::esp_info);
					ImGui::Checkbox("ESP Notes", &espent::esp_notes);
					ImGui::Checkbox("ESP Ladders", &espent::esp_ladders);
					ImGui::Checkbox("ESP Spawners", &espent::esp_spawner);
					ImGui::Text("");
				}
				if (tabb == 5) {
					ImGui::TextColored(ImVec4(255, 255, 255, 1), " SnapLine");
					ImGui::Checkbox("Player", &snapline_menu::players_snapline);
					ImGui::Checkbox("Mob", &snapline_menu::creature_snapline);
					ImGui::Checkbox("NPC", &snapline_menu::npc_snapline);
					ImGui::Checkbox("Anomaly", &snapline_menu::anomaly_snapline);
					ImGui::Checkbox("Artefact", &snapline_menu::artefact_snapline);
					ImGui::Checkbox("Container", &snapline_menu::container_snapline);
					ImGui::Checkbox("Loot", &snapline_menu::loot_snapline);
				}
				if (tabb == 2) {
					ImGui::TextColored(ImVec4(255, 255, 255, 1), " PLAYERS AimBot");
					ImGui::Checkbox("Activate", &menu_vars2::aim_player);
					ImGui::Checkbox("Only clan players", &menu_vars2::aim_clan_player);
					ImGui::SliderFloat("Speed", &menu_vars2::aim_speed_people, 0.0, 10, "%.3f");
					ImGui::SliderFloat("Smooth", &menu_vars2::aim_smooth_people, 0.0, 10, "%.3f");
					//ImGui::Checkbox("Максимальная скорость", &menu_vars2::no_speed_no_smooth);
					ImGui::SliderInt("High", &menu_vars2::aim_high_circle, 0, 95, "%.3f");
					if (p_current_key == 0) {
						ImGui::Text("Selected key F3");
					}
					if (p_current_key == 1) {
						ImGui::Text("Selected key F4");
					}
					if (p_current_key == 2) {
						ImGui::Text("Selected key MOUSE 5");
					}
					if (p_current_key == 3) {
						ImGui::Text("Selected key MOUSE 4");
					}
					if (p_current_key == 4) {
						ImGui::Text("Selected key MOUSE 2");
					}
					if (ImGui::Button("F3")) {
						p_current_key = 0;
					}
					if (ImGui::Button("F4")) {
						p_current_key = 1;
					}
					if (ImGui::Button("MOUSE 5")) {
						p_current_key = 2;
					}
					if (ImGui::Button("MOUSE 4")) {
						p_current_key = 3;
					}
					if (ImGui::Button("MOUSE 2")) {
						p_current_key = 4;
					}
					ImGui::Text("");
					ImGui::TextColored(ImVec4(255, 255, 255, 1), " MOBS AimBot");
					ImGui::Checkbox("Activate ", &menu_vars3::aim_creature);
					ImGui::SliderFloat("Speed ", &menu_vars3::aim_speed_creature, 0.0, 10, "%.3f");
					ImGui::SliderFloat("Smooth ", &menu_vars3::aim_smooth_creature, 0.0, 10, "%.3f");
					ImGui::SliderInt("High ", &menu_vars2::aim_creature_high_circle, 0, 95, "%.3f");
					ImGui::SliderFloat("Radius of aim ", &menu_vars3::size_c, 35, 140, "%.3f");
					if (c_current_key == 0) {
						ImGui::Text("Selected key F3");
					}
					if (c_current_key == 1) {
						ImGui::Text("Selected key F4");
					}
					if (c_current_key == 2) {
						ImGui::Text("Selected key MOUSE 5");
					}
					if (c_current_key == 3) {
						ImGui::Text("Selected key MOUSE 4");
					}
					if (ImGui::Button("F3 ")) {
						c_current_key = 0;
					}
					if (ImGui::Button("F4 ")) {
						c_current_key = 1;
					}
					if (ImGui::Button("MOUSE 5 ")) {
						c_current_key = 2;
					}
					if (ImGui::Button("MOUSE 4 ")) {
						c_current_key = 3;
					}
				}
				if (tabb == 3) {
					ImGui::TextColored(ImVec4(255, 255, 255, 1), " Exploits");
					ImGui::Checkbox("Freeze", &exploit::freeze_packets);
					ImGui::SliderInt("Level of freeze", &exploit::kilobyte_rate, 0, 20, "%.3f");
					ImGui::Text("Button to activate F1 to disable F2");
					ImGui::Text("");
					ImGui::Checkbox("Anomaly Damage Protection", &exploit::anomaly_protect);
					ImGui::Text("The cheat will not let you into the area of the anomaly");
					ImGui::Text("");
					ImGui::Checkbox("Activator anomalies", &exploit::magnit_anomaly);
					ImGui::Checkbox("Legit activator", &exploit::legit_magnit_anomaly);
					if (exploit::legit_magnit_anomaly) {
						ImGui::SliderInt("Limit player", &exploit::player_count_limit, 0, 4, "%.3f");
					}
					ImGui::SliderInt("Radius of activator", &exploit::radius_magnit, 100, 1500, "%.3f");
					ImGui::SliderInt("Distance activation", &exploit::distance_magnit, 0, 100, "%.3f");
					ImGui::Text("Hold the middle mouse button and throw a stone in front of you");
					ImGui::Text("");
					//ImGui::Checkbox("Просмотреть внутрь текстур", &exploit::no_clip);
					//ImGui::SliderInt("Дистанция прохода", &exploit::no_clip_distance, 1, 50, "%.3f");
					//ImGui::Text("Удерживайте левый ALT и нажимайте поочереди на кнопки A S D W");
					//ImGui::Text("");
					//ImGui::Checkbox("Телепортация на спавн", &menu_vars4::speed_key);
					//ImGui::Text("Нажмите на клавишу CAPSLOCK чтобы телепортироваться на спавн");
					//ImGui::Text("");
					ImGui::Checkbox("Teleport players", &exploit::tp_people);
					ImGui::Text("Press the F key to select a player");
					ImGui::Text("and then press the F5 key to teleport it to yourself");
					ImGui::Text("");
					ImGui::Checkbox("Teleport mobs", &exploit::tp_creature);
					ImGui::Text("Press the F key to select the type of mutant");
					ImGui::Text("and then press the H key to teleport it to yourself");
					ImGui::Text("");
					ImGui::Checkbox("Bright", &exploit::bright);
					ImGui::SliderInt("Level of bright", &exploit::bright_int, 0, 30, "%.3f");
					ImGui::Text("");
				}
				if (tabb == 4) {
					ImGui::TextColored(ImVec4(255, 255, 255, 1), "Misc");
					ImGui::Checkbox("Crosshair", &menu_vars4::crosshair);
					ImGui::Checkbox("Karma", &menu_vars4::esp_karma_people);
					ImGui::Checkbox("Kills", &menu_vars4::esp_kills_people);

					ImGui::Checkbox("CheckerAdmin", &menu_vars4::esp_accesslevel_people);
					ImGui::Checkbox("CanTakeDamage", &menu_vars4::esp_cantakedamage_people);
					ImGui::Checkbox("Name of anomalies", &menu_vars4::name_anomalies);
					ImGui::Text("");
					ImGui::Checkbox("RADAR", &espent::esp_radar);
					ImGui::SliderInt("Radius of radar", &espent::esp_radar_radius, 10, 210, "%.3f");
					ImGui::Checkbox("Anomalies on radar", &espent::esp_radar_a);
					ImGui::Checkbox("Mobs on radar", &espent::esp_radar_m);
					ImGui::Checkbox("NPC on radar", &espent::esp_radar_n);
					ImGui::Checkbox("Player on radar", &espent::esp_radar_p);
					ImGui::Text("You will be able to see the enemy approaching you using radar");
					ImGui::Text("");
					ImGui::Checkbox("Checked Anomalies", &espent::esp_checked_anomaly);
					ImGui::Text("Anomalies that you have checked are displayed in green");
					ImGui::Text("");
					ImGui::Checkbox("Memorizer Artefacts", &menu_vars4::memorizer_artefacts);
					ImGui::Text("Cheat remembers in which anomalies the artifacts lie");
					ImGui::Text("");

					//ImGui::Checkbox("Отображать только доступные записки", &menu_vars4::esp_only_active_notes);
					//ImGui::Text("Чит будет отображать только те записки которые вы ещё не брали");
					//ImGui::Text("");
					//ImGui::Checkbox("Автоматический фарм кабанов", &menu_vars4::auto_farm_kaban);
					//ImGui::Text("Чит будет сам фармить кабанов");
					//ImGui::Text("");
					//ImGui::Checkbox("Легитный взлом (предотвращает бег задним ходом)", &menu_vars4::speedhack_legit);
					//ImGui::SliderFloat("Скорость", &menu_vars4::speed_sh, 0, 9.5, "%.3f");
					//ImGui::Text("Кнопка по умолчанию CAPSLOCK");
					ImGui::Checkbox("PanicKey", &menu_vars4::panic_key);
					ImGui::Text("If you want to stop cheat press END");
					ImGui::Text("");
					ImGui::Checkbox("BlackList", &menu_vars4::esp_blacklist_people);
					ImGui::InputText(" ", menu_vars4::nickname_blacklist, 64);
					if (ImGui::Button("Add to BL", ImVec2(75, 25))) {
						//=============================
						//	ПРОВЕРКА ЧЕРНОГО СПИСКА
						std::fstream f;
						f.open("blacklist.txt", std::ios::app);
						if (f)
						{
							std::string str = menu_vars4::nickname_blacklist;
							f << str << "\n";
						}
						//=============================
					}
					if (ImGui::Button("Delete", ImVec2(75, 25))) {
						int temp = 0;
						std::ifstream f("blacklist.txt");
						std::string word = menu_vars4::nickname_blacklist;
						// вводите  word и filename и инициализируйте std::ifstream oleg
						if (size_t line = searcher(word, f))
						{
							remove_line("blacklist.txt", line - 1);
						}

					}
					ImGui::Text("");
				}
				ImGui::EndChild();
				ImGui::PopStyleColor();
			}

		}
		ImGui::End();
	}
}




void InputHandler() {
	for (int i = 0; i < 5; i++) {
		ImGui::GetIO().MouseDown[i] = false;
	}

	int Button = -1;
	if (GetAsyncKeyState(VK_LBUTTON)) {
		Button = 0;
	}

	if (Button != -1) {
		ImGui::GetIO().MouseDown[Button] = true;
	}
}



void Render() {
	if (GetAsyncKeyState(menu_key) & 1) espent::show_menu = !espent::show_menu;
	if (GetAsyncKeyState(VK_END) && menu_vars4::panic_key == true) {
		exit(1);
	}

	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	ImGui::GetIO().MouseDrawCursor = espent::show_menu;
	draw_esp();
	if (espent::show_menu == true) {
		InputHandler();
		draw_menu();
		SetWindowLong(Overlay.Hwnd, GWL_EXSTYLE, WS_EX_TOOLWINDOW);
		UpdateWindow(Overlay.Hwnd);
		SetFocus(Overlay.Hwnd);
	}
	else {
		SetWindowLong(Overlay.Hwnd, GWL_EXSTYLE, WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW);
		UpdateWindow(Overlay.Hwnd);
	}


	ImGui::EndFrame();

	DirectX9.pDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);
	if (DirectX9.pDevice->BeginScene() >= 0) {
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
		DirectX9.pDevice->EndScene();
	}

	HRESULT result = DirectX9.pDevice->Present(NULL, NULL, NULL, NULL);
	if (result == D3DERR_DEVICELOST && DirectX9.pDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET) {
		ImGui_ImplDX9_InvalidateDeviceObjects();
		DirectX9.pDevice->Reset(&DirectX9.pParameters);
		ImGui_ImplDX9_CreateDeviceObjects();
	}
}

void MainLoop() {
	static RECT OldRect;
	ZeroMemory(&DirectX9.Message, sizeof(MSG));
	while (DirectX9.Message.message != WM_QUIT) {

		HWND ForegroundWindow = GetForegroundWindow();

		if (PeekMessage(&DirectX9.Message, Overlay.Hwnd, 0, 0, PM_REMOVE)) {
			TranslateMessage(&DirectX9.Message);
			DispatchMessage(&DirectX9.Message);
		}

		if (ForegroundWindow == Process.Hwnd) {
			HWND TempProcessHwnd = GetWindow(ForegroundWindow, GW_HWNDPREV);
			SetWindowPos(Overlay.Hwnd, TempProcessHwnd, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		}

		RECT TempRect;
		POINT TempPoint;
		ZeroMemory(&TempRect, sizeof(RECT));
		ZeroMemory(&TempPoint, sizeof(POINT));

		GetClientRect(Process.Hwnd, &TempRect);
		ClientToScreen(Process.Hwnd, &TempPoint);

		TempRect.left = TempPoint.x;
		TempRect.top = TempPoint.y;
		ImGuiIO& io = ImGui::GetIO();

		io.ImeWindowHandle = Process.Hwnd;

		if (TempRect.left != OldRect.left || TempRect.right != OldRect.right || TempRect.top != OldRect.top || TempRect.bottom != OldRect.bottom) {
			OldRect = TempRect;
			Process.WindowWidth = TempRect.right;
			Process.WindowHeight = TempRect.bottom;
			DirectX9.pParameters.BackBufferWidth = Process.WindowWidth;
			DirectX9.pParameters.BackBufferHeight = Process.WindowHeight;
			SetWindowPos(Overlay.Hwnd, (HWND)0, TempPoint.x, TempPoint.y, Process.WindowWidth, Process.WindowHeight, SWP_NOREDRAW);
			DirectX9.pDevice->Reset(&DirectX9.pParameters);
		}
		Render();
	}
	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
	if (DirectX9.pDevice != NULL) {
		DirectX9.pDevice->EndScene();
		DirectX9.pDevice->Release();
	}
	if (DirectX9.IDirect3D9 != NULL) {
		DirectX9.IDirect3D9->Release();
	}
	DestroyWindow(Overlay.Hwnd);
	UnregisterClass(Overlay.WindowClass.lpszClassName, Overlay.WindowClass.hInstance);
}


void set_style()
{

	ImGuiStyle& s = ImGui::GetStyle();
	const ImColor accentCol = ImColor(255, 0, 0, 255);
	const ImColor bgSecondary = ImColor(0, 0, 0, 255);
	s.ScaleAllSizes(1.5);
	s.Colors[ImGuiCol_WindowBg] = ImColor(0, 0, 0, 255);
	s.Colors[ImGuiCol_ChildBg] = bgSecondary;
	s.Colors[ImGuiCol_FrameBg] = ImColor(0, 0, 0, 255);
	s.Colors[ImGuiCol_FrameBgActive] = ImColor(0, 0, 0, 255);
	s.Colors[ImGuiCol_Border] = ImColor(250, 250, 250, 105);
	s.Colors[ImGuiCol_CheckMark] = ImColor(230, 230, 230, 105);
	s.Colors[ImGuiCol_SliderGrab] = ImColor(230, 230, 230, 105);
	s.Colors[ImGuiCol_SliderGrabActive] = ImColor(230, 230, 230, 105);
	s.Colors[ImGuiCol_ResizeGrip] = ImColor(24, 24, 24, 105);
	s.Colors[ImGuiCol_Header] = ImColor(250, 250, 250, 105);
	s.Colors[ImGuiCol_HeaderHovered] = ImColor(250, 250, 250, 105);
	s.Colors[ImGuiCol_HeaderActive] = ImColor(250, 250, 250, 105);
	s.Colors[ImGuiCol_TitleBg] = ImColor(230, 230, 230, 105);
	s.Colors[ImGuiCol_TitleBgCollapsed] = ImColor(0, 0, 0, 105);
	s.Colors[ImGuiCol_TitleBgActive] = ImColor(250, 250, 250, 105);
	s.Colors[ImGuiCol_FrameBgHovered] = ImColor(230, 230, 230, 105);
	s.Colors[ImGuiCol_ScrollbarBg] = ImColor(250, 250, 250, 105);
	s.Colors[ImGuiCol_ScrollbarGrab] = ImColor(255, 255, 255, 105);
	s.Colors[ImGuiCol_ScrollbarGrabHovered] = ImColor(255, 255, 255, 105);
	s.Colors[ImGuiCol_ScrollbarGrabActive] = ImColor(255, 255, 255, 105);
	s.Colors[ImGuiCol_Header] = ImColor(230, 230, 230, 105);
	s.Colors[ImGuiCol_HeaderHovered] = ImColor(250, 250, 250, 105);
	s.Colors[ImGuiCol_HeaderActive] = ImColor(250, 250, 250, 105);
	s.Colors[ImGuiCol_PopupBg] = ImColor(230, 230, 230, 105);
	s.Colors[ImGuiCol_Button] = ImColor(205, 205, 205, 105);
	s.Colors[ImGuiCol_ButtonHovered] = ImColor(250, 250, 250, 105);
	s.Colors[ImGuiCol_ButtonActive] = ImColor(250, 250, 250, 105);
	s.Colors[ImGuiCol_Text] = ImColor(255, 255, 255, 195);

	s.AntiAliasedFill = false;
	s.AntiAliasedLines = false;

	s.ChildRounding = 4.0f;
	s.FrameBorderSize = 1.0f;
	s.FrameRounding = 0.2f;
	s.PopupRounding = 0.2f;
	s.ScrollbarRounding = 0.0f;
	s.ScrollbarSize = 8.2f;
	s.TabRounding = 1.2f;
	s.WindowRounding = 0.0F;
}

bool DirectXInit() {
	if (FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &DirectX9.IDirect3D9))) {
		return false;
	}



	D3DPRESENT_PARAMETERS Params = { 0 };

	Params.Windowed = TRUE;
	Params.SwapEffect = D3DSWAPEFFECT_DISCARD;
	Params.hDeviceWindow = Overlay.Hwnd;
	Params.MultiSampleQuality = D3DMULTISAMPLE_NONE;
	Params.BackBufferFormat = D3DFMT_A8R8G8B8;
	Params.BackBufferWidth = Process.WindowWidth;
	Params.BackBufferHeight = Process.WindowHeight;
	horizontal = Process.WindowWidth;
	vertical = Process.WindowHeight;
	Params.EnableAutoDepthStencil = TRUE;
	Params.AutoDepthStencilFormat = D3DFMT_D16;
	Params.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
	Params.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	if (FAILED(DirectX9.IDirect3D9->CreateDeviceEx(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, Overlay.Hwnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &Params, 0, &DirectX9.pDevice))) {
		DirectX9.IDirect3D9->Release();
		return false;
	}

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGuiStyle& s = ImGui::GetStyle();
	io.IniFilename = NULL;
	io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\tahoma.ttf", 16.3F, NULL, io.Fonts->GetGlyphRangesCyrillic());


	ImGui_ImplWin32_Init(Overlay.Hwnd);
	ImGui_ImplDX9_Init(DirectX9.pDevice);
	ImGui_ImplDX9_CreateDeviceObjects();
	set_style();
	DirectX9.IDirect3D9->Release();


	return true;
}

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	if (ImGui_ImplWin32_WndProcHandler(hWnd, Message, wParam, lParam))
		return true;
	switch (Message) {
	case WM_DESTROY:
		if (DirectX9.pDevice != NULL) {
			DirectX9.pDevice->EndScene();
			DirectX9.pDevice->Release();
		}
		if (DirectX9.IDirect3D9 != NULL) {
			DirectX9.IDirect3D9->Release();
		}
		PostQuitMessage(0);
		exit(4);
		break;
	case WM_SIZE:
		if (DirectX9.pDevice != NULL && wParam != SIZE_MINIMIZED) {
			ImGui_ImplDX9_InvalidateDeviceObjects();
			DirectX9.pParameters.BackBufferWidth = LOWORD(lParam);
			DirectX9.pParameters.BackBufferHeight = HIWORD(lParam);
			HRESULT hr = DirectX9.pDevice->Reset(&DirectX9.pParameters);
			if (hr == D3DERR_INVALIDCALL)
				update_resolution();
			ImGui_ImplDX9_CreateDeviceObjects();
		}
		break;
	default:
		return DefWindowProc(hWnd, Message, wParam, lParam);
		break;
	}
	return 0;
}

void SetupWindow() {
	Overlay.WindowClass = {
		sizeof(WNDCLASSEX), 0, WinProc, 0, 0, nullptr, LoadIcon(nullptr, IDI_APPLICATION), LoadCursor(nullptr, IDC_ARROW), nullptr, nullptr, Overlay.Name, LoadIcon(nullptr, IDI_APPLICATION)
	};

	RegisterClassEx(&Overlay.WindowClass);
	if (Process.Hwnd) {
		static RECT TempRect = { NULL };
		static POINT TempPoint;
		GetClientRect(Process.Hwnd, &TempRect);
		ClientToScreen(Process.Hwnd, &TempPoint);
		TempRect.left = TempPoint.x;
		TempRect.top = TempPoint.y;
		Process.WindowWidth = TempRect.right;
		Process.WindowHeight = TempRect.bottom;
	}

	Overlay.Hwnd = CreateWindowEx(NULL, Overlay.Name, Overlay.Name, WS_POPUP | WS_VISIBLE, Process.WindowLeft, Process.WindowTop, Process.WindowWidth, Process.WindowHeight, NULL, NULL, 0, NULL);
	DwmExtendFrameIntoClientArea(Overlay.Hwnd, &DirectX9.Margin);
	SetWindowLong(Overlay.Hwnd, GWL_EXSTYLE, WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW);
	//Выключить чит на оверлеях
	SetWindowDisplayAffinity(Overlay.Hwnd, WDA_EXCLUDEFROMCAPTURE);
	ShowWindow(Overlay.Hwnd, SW_SHOW);
	UpdateWindow(Overlay.Hwnd);
}

std::string RandomString(int length) {
	static std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
	std::string result;
	result.resize(length);

	srand(time(NULL));
	for (int i = 0; i < length; i++)
		result[i] = charset[rand() % charset.length()];

	return result;
}

int initoverlay(int pid) {
	if (CreateConsole == false)
		ShowWindow(GetConsoleWindow(), SW_SHOW);
	GetDesktopResolution(horizontal, vertical);
	static auto gpid = pid;
	bool WindowFocus = false;
	while (WindowFocus == false) {
		DWORD ForegroundWindowProcessID;
		GetWindowThreadProcessId(GetForegroundWindow(), &ForegroundWindowProcessID);
		if (gpid == ForegroundWindowProcessID) {
			Process.ID = GetCurrentProcessId();
			Process.Handle = GetCurrentProcess();
			Process.Hwnd = GetForegroundWindow();

			RECT TempRect;
			GetWindowRect(Process.Hwnd, &TempRect);
			Process.WindowWidth = TempRect.right - TempRect.left;
			Process.WindowHeight = TempRect.bottom - TempRect.top;
			Process.WindowLeft = TempRect.left;
			Process.WindowRight = TempRect.right;
			Process.WindowTop = TempRect.top;
			Process.WindowBottom = TempRect.bottom;

			char TempTitle[MAX_PATH];
			GetWindowText(Process.Hwnd, TempTitle, sizeof(TempTitle));
			Process.Title = TempTitle;

			char TempClassName[MAX_PATH];
			GetClassName(Process.Hwnd, TempClassName, sizeof(TempClassName));
			Process.ClassName = TempClassName;

			char TempPath[MAX_PATH];
			GetModuleFileNameEx(Process.Handle, NULL, TempPath, sizeof(TempPath));
			Process.Path = TempPath;

			WindowFocus = true;
		}
	}

	static auto name = RandomString(10);
	Overlay.Name = name.c_str();
	SetupWindow();
	DirectXInit();

	while (TRUE) {
		MainLoop();
	}
}