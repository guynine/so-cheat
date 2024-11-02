#include "bw_entities.hh"
#include "bw_globals.hh"
#include "bw_offsets.hh"
#include "../Addr.hh"

#define THISREAD(type,offset)  read<type>((unsigned long long)this + offset)

#define THISWRITE(type,offset,VALUE)  writem<type>((unsigned long long)this + offset,VALUE)

#include "wtypes.h"
#include <iostream>

using namespace std;

// Get the horizontal and vertical screen sizes in pixel
void GetDesktopResolution2(int& horizontal, int& vertical)
{
	RECT desktop;
	// Get a handle to the desktop window
	const HWND hDesktop = GetDesktopWindow();
	// Get the size of screen to the variable desktop
	GetWindowRect(hDesktop, &desktop);
	// The top left corner will have coordinates (0,0)
	// and the bottom right corner will have coordinates
	// (horizontal, vertical)
	horizontal_for_wts = desktop.right;
	vertical_for_wts = desktop.bottom;
}

Vector3 Entity::position()
{
	return THISREAD(Vector3, bw::Entity::pos);
}

void Entity::position_change(Vector3 value)
{
	writem((unsigned __int64)this + 0x40, &value, sizeof(decltype(value)));
}



PyModel* Entity::GetModel()
{
		auto Chunkatachment = THISREAD(uintptr_t, bw::Entity::Atachment);
	if (!Chunkatachment) 
		return nullptr;
	return read<PyModel*>(Chunkatachment + bw::ChunkAtachment::pymodel);
}





// Avatar


//\








// CameraImpl
CameraImpl* CameraImpl::Instance()
{
	return read<CameraImpl*>(game::umbra_camera);

}
void CameraImpl::CameraPosChange()
{
	static Matrix4x4 matrix;
	read((__int64)this + bw::CameraImpl::viewmatrix, &matrix, sizeof(Matrix4x4));
	cout << matrix.m[1][0] << " " << matrix.m[1][1] << " " << matrix.m[1][2] << " " << matrix.m[1][3] << endl;
	matrix.m[1][0] = matrix.m[1][0];
	matrix.m[1][1] = matrix.m[1][1];
	matrix.m[1][2] = matrix.m[1][2];
	matrix.m[1][3] = matrix.m[1][3] - 3;
	writem((unsigned __int64)this + 0x40, &matrix, sizeof(decltype(matrix)));
	
}
bool CameraImpl::ProjectWorldToScreen(Vector3 position, Vector2* screenpos, bool* cachematrix)
{
	//auto matrix = read<Matrix4x4>(&this->matrix); // 0x28 w 0x30 h resolution
	static Matrix4x4 matrix;
	if (!*cachematrix)
	{
		*cachematrix = read((__int64)this + bw::CameraImpl::viewmatrix, &matrix, sizeof(Matrix4x4));
	}
	GetDesktopResolution2(horizontal_for_wts, vertical_for_wts);
	float sw = horizontal_for_wts, sh = vertical_for_wts - ((vertical_for_wts / 100) * 3);
	float x = matrix.m[0][0] * position.x + matrix.m[0][1] * position.y + matrix.m[0][2] * position.z + matrix.m[0][3];
	float y = matrix.m[1][0] * position.x + matrix.m[1][1] * position.y + matrix.m[1][2] * position.z + matrix.m[1][3];
	float w = matrix.m[3][0] * position.x + matrix.m[3][1] * position.y + matrix.m[3][2] * position.z + matrix.m[3][3];
	if (w < 0.01f) return false;
	x *= 1.f / w;
	screenpos->x = (sw * 0.5f) + (0.5f * x * sw + 0.5f);
	if (screenpos->x > 10000 || screenpos->x < -10000) return false;
	y *= 1.f / w;
	screenpos->y = (sh * 0.5f) - (0.5f * y * sh + 0.5f);
	if (screenpos->y > 10000 || screenpos->y < -10000) return false;
	return true;
}








bool CameraImpl::ProjectWorldToRadar(Vector3 position, Vector3 player_position, Vector2* screenpos, int distance, bool* cachematrix)
{
	//auto matrix = read<Matrix4x4>(&this->matrix); // 0x28 w 0x30 h resolution
	//static Matrix4x4 matrix;
	//if (!*cachematrix)
	//{
	//	*cachematrix = read((__int64)this + bw::CameraImpl::viewmatrix, &matrix, sizeof(Matrix4x4));
	//}

	float sw = bw_globals2::Wscreen, sh = bw_globals2::Hscreen;
	float x = (player_position.z - position.z) / distance;
	float y = (player_position.x - position.x) / distance;
	screenpos->x = ((280 * 0.5f) + (0.5f * x * 280));
	if (screenpos->x > 243 || screenpos->x < 37) return false;
	screenpos->y = ((270 * 0.5f) - (0.5f * y * 270));
	if (screenpos->y > 233 || screenpos->y < 37) return false;
	return true;
}

//\






// EntityMapEntry
EntityMapEntry* EntityMapEntry::next()
{
	
	return THISREAD(EntityMapEntry*, bw::EntityManager::next);
}

Entity* EntityMapEntry::entity()
{
	auto ent = THISREAD(unsigned __int64, bw::EntityManager::Entity);
	return (Entity*)(ent) ; 
}

int EntityMapEntry::entityID()
{
	return THISREAD(int, bw::EntityManager::EntityID);
}
//\


// EntityManager
EntityManager* EntityManager::instance()
{
	return reinterpret_cast<EntityManager*>(game::g_entitymanager);
}

EntityMap EntityManager::Entities()
{
	return THISREAD(EntityMap, bw::EntityManager::enteredEntities_);
}
//\


#undef THISREAD