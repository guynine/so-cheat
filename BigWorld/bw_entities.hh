#pragma once

#include <format>
#include "bw_python.hh"
#include "Vectors.hh"

	/*BoundingBox bb;
			models_[i]->localBoundingBox( bb, false );
			Moo::rc().world( models_[i]->worldTransform() );
			Geometrics::wireBox( bb, 0xff0000ff );
			Moo::rc().world( Matrix::identity );*/
//struct pYmodel
//{
// 0x120 BoneNameVector
//};
//  ChunkEmbodiment : ChunkItem  
//struct ChunkEmbodiment
//{
//
//};


struct Entity : public PyObject
{
	Vector3 position();
	void position_change(Vector3 value);
	void speed_change(float value);
	//ChunkEmbodiment ChunkAttachment();
	
	PyModel* GetModel();
	
		// 0x98  -> ChunkAttachment  0xd0 -> PyModel
	// PyModel -> 0x100 SuperModel -> 0x98 moo::skeleton
};
struct Avatar : public Entity
{
	Py_dicthead;
	Py_AttributeHASH(Avatar,PyUnicodeObject*, name); // Py_AttributeHASH Py_AttributePRIVATE

	Py_AttributeHASH(Avatar,PyINT8Object*, dead);

	//Py_AttributeHASH(Avatar,PyINT8Object*, teamID);

	Py_AttributeHASH(Avatar, PyStringObject*, clanName);

	Py_AttributeHASH(Avatar, PyINT8Object*, clientAccessLevel);

	Py_AttributeHASH(Avatar, PyINT8Object*, canTakeDamage);

	Py_AttributeHASH(Avatar, PyINT32Object*, frags);

	Py_AttributeHASH(Avatar, PyINT32Object*, karma);
	
	Py_AttributeHASH(Avatar, PyINT8Object*, shooting); //_AvatarTrackers__start_sprint

	/*
	shooting
	respawn_timer_type
	_playing_animation_loot*/

	DumpAttribute(Avatar);

//хЛЪ ХЦПНЙЮ
std::string GetName()
	{
		auto n = name();
		if (!n)
			return std::string();
		auto utf = n->to_string();
		return utf;
	}

//лЕПРБ КХ
bool is_dead()
	{
		auto isdeadproperty = this->dead();
		return isdeadproperty->get();
	}
//аЕФХР КХ
bool is_sprint()
{
	auto isdeadproperty = this->shooting();
	return isdeadproperty->get();
}
//сПНБЕМЭ ДНЯРСОЮ
long long GetAccessLevel()
{
	auto prop = this->clientAccessLevel();
	return prop->get();
}

//йНК-БН ЙХККНБ
long long GetFrags()
{
	auto prop = this->frags();
	return prop->get();
}
//йНК-БН ЙЮПЛШ
long long GetKarma()
{
	auto prop = this->karma();
	return prop->get();
}

//CanTakeDamage
long long CTD()
{
	auto prop = this->canTakeDamage();
	return prop->get();
}

//хЛЪ ЙКЮМЮ
std::string GetClanName()
{
	auto n = clanName();
	if (!n)
		return std::string();
	auto utf = n->to_string();
	return utf;
}


/*
_AvatarTrackers__last_tracker_key tuple 00000000556301F8
_is_fix_action_sprint bool 00007FF676130F18
_anim_action_out NoneType 00007FF676133040
flashLightID long 00000000F84A6670
_hand_wepon_providers_recreted bool 00007FF676130F18
autogunModelVisible bool 00007FF6761310B8
GUNMover_nodeInfo GUNMover 00000000BDAB2B88
_FootPrinter__timer_reatt int 000000002DA52E28
color_alphas collections.defaultdict 000000010A508E88
_async_load_counter int 0000000007A68B90
face_controller FaceController 0000000102947278
ActiveWeaponSet2 PyFixedDictDataInstance 000000009EA01858
_last_in_pot_notification NoneType 00007FF676133040
torsoProvider_entity EntityDirProvider 00000000AA83E658
BellyItemID long 00000000815E15F0
headProvider_serverLook PyMatrix 00000000BF7C9B78
used_item_on_target int 0000000007A68B90
_looped_action NoneType 00007FF676133040
tracked_wanted NoneType 00007FF676133040
_leftFreeHandProvider HandFreeProvider 00000000BDAB3588
set_ch_HitPointsRegeneration functools.partial 00000000EE7DF048
_particles_burn NoneType 00007FF676133040
EquipModes int 0000000007A68B90
<dummy key> ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл 0000000000000000
_inAir bool 00007FF676130F18
tracker_arm_right Tracker 000000008BE3C3F8
emblems_colors dict 0000000055F84CA8
set_ch_Defence functools.partial 000000008BFC1F98
headProvider_to_target NoneType 00007FF676133040
_foot_rotate_limit float 000000001D378C48
_belly_to_right_played bool 00007FF676130F18
frags int 000000004D076890
_fence_played bool 00007FF676130F18
ActiveGadgetList PyArrayDataInstance 000000009EA02458
personality PyFixedDictDataInstance 000000009EA03718
last_space_name str 00000000C0E49F10
_fake_color_delegates list 0000000101BF1FC8
_old_end_shot_sfx NoneType 00007FF676133040
_to_track_progress bool 00007FF676130F18
_dry_start_time NoneType 00007FF676133040
sfx_enabled bool 00007FF6761310B8
_action_callback NoneType 00007FF676133040
_usingItemSound NoneType 00007FF676133040
_UsingItemAnimation__current_action NoneType 00007FF676133040
_potted int 0000000007A68B78
_end_stop_radio_anim bool 00007FF676130F18
fniRight FootNodeInfo 00000000B3EBAA48
_using_attach_model NoneType 00007FF676133040
_party_status int 0000000007A68B60
_prev_cheked_key tuple 00000000A695FB40
lock_move_by_jump bool 00007FF676130F18
_min_stain_index int 0000000007A68B90
_hips_offset_by_rotate float 000000001D378B40
showNameCallbacker NoneType 00007FF676133040
foots list 00000000F849B348
hideNameCallbacker NoneType 00007FF676133040
name unicode 00000000968EF0C0
_Gestures__current_gesture_actions NoneType 00007FF676133040
usingGesture int 0000000007A68B90
_FootPrinter__foot_cue_models dict 000000010A5088E8
crouching_or_crawling int 0000000007A68B90
_cd_id int 0000000007A68B90
torso_nodeinfo TorsoTrackerNodeInfo 00000000A0D981C8
_foot_settings_path str 000000002CB2C870
current_effects dict 00000000F91EC3E8
is_crafting bool 00007FF676130F18
_restore_bellyweapon_delay float 000000002BB14290
headProvider_cam_dcursor EntityDirProvider 00000000AA83E658
_callbackOnThrow NoneType 00007FF676133040
_putting_item_replace NoneType 00007FF676133040
_last_wound_time float 0000000081789738
hand_cotrol_wait_tmp bool 00007FF676130F18
headProvider_cam_self EntityDirProvider 00000000AA83E658
eyes_controller instance 00000000F849BB88
footTriggers list 0000000104678C48
is_throwing bool 00007FF676130F18
_last_ladder_action bool 00007FF676130F18
_rightFreeHandProvider HandFreeProvider 00000000BDAB2D88
_draw_pickup bool 00007FF676130F18
ch_Defence dict 00000000BFCC3768
dead int 0000000007A68B90
_prev_weapon_slots dict 000000010A4D7688
heli_weapon NoneType 00007FF676133040
set_ch_HitPoints functools.partial 00000000EE7DF2C8
ENABLE_MovingActionMather bool 00007FF6761310B8
set_ch_MoveSpeed functools.partial 00000000EE7DF0E8
candle int 0000000007A68B90
moving_locked bool 00007FF676130F18
head_nodeInfo HeadNodeInfo 00000000B36678A8
_AvatarTrackers__saved_yaw NoneType 00007FF676133040
transformationProperty PyArrayDataInstance 000000009EA036B8
_current_action NoneType 00007FF676133040
set_ch_MaxStamina functools.partial 00000000EE7DF138
_AvatarTrackers__last_xtorso_data NoneType 00007FF676133040
set_ch_CombatPoints functools.partial 00000000EE7DF228
_lock_bleed dict 00000000BE743298
_last_grenade_type int 0000000007A68B90
test_nodeInfo_gunrw GUNRWCentrMover 000000007F21AB08
tracker_head Tracker 000000008BE44938
invulnerable int 0000000007A68B90
_soak_enabled bool 00007FF676130F18
_isGasMaskSoundBreathing bool 00007FF676130F18
hoisting_flag NoneType 00007FF676133040
_HandControl__reload_weapon_progress bool 00007FF676130F18
_putting_item_on NoneType 00007FF676133040
teamID int 0000000007A68B90
set_ch_StaminaRegeneration functools.partial 000000008BFC1A98
_dry_controller NoneType 00007FF676133040
waterListenerHips int 000000004D064200
_tracker_is_init bool 00007FF6761310B8
_total_vertices_number int 0000000007A68B90
tracker_weaponback instance 00000000F849BBC8
_stopped_action NoneType 00007FF676133040
isBleending bool 00007FF676130F18
_hvat_actions dict 000000010A504E68
_tuck_coroutine NoneType 00007FF676133040
_AvatarTrackers__saved_hands NoneType 00007FF676133040
radiometer Radiometer 00000000F8488588
EquippedVisibleAttaches PyFixedDictDataInstance 000000009EA029F8
_AvatarTrackers__last_data_trackers NoneType 00007FF676133040
gesture_played_out bool 00007FF676130F18
tracker_gun Tracker 000000008BE44C78
_stuck bool 00007FF676130F18
gunnodeInfo TrackerWeaponNodeInfo 00000000B33C21E8
_left_to_right_played bool 00007FF676130F18
hp_barrel_node NoneType 00007FF676133040
_burn_world_model NoneType 00007FF676133040
enable_pitch bool 00007FF676130F18
_hd_end_burn_smoke NoneType 00007FF676133040
_todo_useanim_lock_foot bool 00007FF676130F18
active_weapon ClWeapon 00000000F84A0860
_HandControl__reload_weapon_osn_anmation bool 00007FF676130F18
_fence_id bool 00007FF676130F18
_need_enable_look bool 00007FF676130F18
_waitSnowTexture dict 000000010A508FA8
grenadeArmed bool 00007FF676130F18
_playing_animation_device bool 00007FF676130F18
_headlight Headlight 00000000F84A2A20
set_ch_Penetration functools.partial 000000008BFC1F48
_weapon_to_attached str 0000000027EBEC60
right_hand_model_sound_node NoneType 00007FF676133040
_Avatar__SFXSeries_callbacks list 00000000F849E148
_anim_callback_id NoneType 00007FF676133040
_members_subscribed bool 00007FF676130F18
nodeInfoL HandTrackerNodeInfo 00000000828619F8
_is_lader_action_played bool 00007FF676130F18
_in_hand_model_left NoneType 00007FF676133040
coloriseEmblems PyArrayDataInstance 000000009EA02A58
EquippedArmor PyFixedDictDataInstance 000000009EA02698
waterListenerHead int 000000004D05EAD0
_FootPrinter__cue_model_to_node dict 000000006E6708B8
posteffects dict 00000000F91EAA08
_is_lader_end_action_played bool 00007FF676130F18
_center_ladder NoneType 00007FF676133040
kickBackTimer NoneType 00007FF676133040
right_weapon_prov HandToWeaponProvider 00000000BEF67D48
_end_use_radio_anim bool 00007FF676130F18
_slope_eff_settings dict 0000000059419CB8
nodeInfoR HandTrackerNodeInfo 0000000082862938
collider_boxes dict 000000010A4D7D48
_putting_item_off NoneType 00007FF676133040
_ignorGravityAnimation bool 00007FF676130F18
_burn_sound NoneType 00007FF676133040
set_ch_DamageAbsorb functools.partial 000000008BFC1EF8
_fake_item_dress_types dict 00000000F91FA3C8
_dung_timer_end int 0000000007A68B90
collider_nodes dict 000000010A4D82E8
event_current_music NoneType 00007FF676133040
weaponProvider_entity EntityDirProvider 00000000AA83E658
_HandControl__isEquipProgress bool 00007FF676130F18
head_look_cam bool 00007FF676130F18
pvpFlag int 0000000007A68B90
_Avatar__gun_anim_callback_id2 NoneType 00007FF676133040
_is_jump bool 00007FF676130F18
_water_level NoneType 00007FF676133040
_new_turn instance 00000000F849BE48
_cue_filter dict 0000000102DD5C98
megaLodInOutDistanceInited bool 00007FF6761310B8
_burn_tick_id int 0000000007A68B90
_anim_action_in NoneType 00007FF676133040
_tucking_item NoneType 00007FF676133040
_UsingItemAnimation__dealyed_timer int 0000000007A68B90
_colorise_emblems_cache NoneType 00007FF676133040
_AvatarTrackers__head_from_server bool 00007FF676130F18
_async_load_callback int 0000000007A68B90
_stain_index int 0000000007A68B90
friendsList list 00000000F849E088
_pygunnode instance 00000000AA303748
binoculing int 0000000007A68B90
_raise_flag_id int 0000000007A68B90
headProvider_entity EntityDirProvider 00000000AA83E658
_isBurn NoneType 00007FF676133040
active_weapon_model PyModel 000000010A5EED08
_model_pistol_holster NoneType 00007FF676133040
set_ch_CombatPointsRegeneration functools.partial 000000008BFC18B8
_visual_callback NoneType 00007FF676133040
_slope int 0000000007A68B90
canTakeDamage int 0000000007A68B90
_prereqs_model_key list 00000000F849E248
throwing_node PyModelNode 00000000B36923F8
set_ch_MaxWeight functools.partial 000000008BFC19F8
_stopped_action_played NoneType 00007FF676133040
_prev_matrix NoneType 00007FF676133040
is_burning int 0000000007A68B90
AgrFlag int 0000000007A68B90
fniLeft FootNodeInfo 00000000B3EA4108
_pygunRWnode instance 00000000F849B248
_sound_only_for_me NoneType 00007FF676133040
_head_exist bool 00007FF6761310B8
_in_hand_model_right NoneType 00007FF676133040
_pot_controller int 00000000817AD378
_playing_animation_item bool 00007FF676130F18
last_grenade_damage int 0000000007A68B90
_particles_burn_smoke NoneType 00007FF676133040
_subscribed_to_boat bool 00007FF676130F18
_Avatar__gun_anim_callback_id NoneType 00007FF676133040
_equipped_armor_dirty bool 00007FF676130F18
_auto_clear_callback_id int 000000004D0644E8
_foot_nodes dict 0000000081317BC8
effects_sfxes dict 00000000F91ED708
_equipped_modes_cache NoneType 00007FF676133040
_frame_index int 0000000007A68B90
_spayer_tid int 0000000007A68B90
last_model_list dict 00000000F91EED88
_AvatarTrackers__head_from_server_timer int 0000000007A68B90
_UsingItemAnimation__wait_models dict 00000000A1959818
isUseItemAnimationPlayed function 00000000586E6898
_by_anim_weapon_to NoneType 00007FF676133040
transformationID int 0000000007A68B90
deathDrawn bool 00007FF6761310B8
_anim_action_loop NoneType 00007FF676133040
_wound_enabled bool 00007FF676130F18
dataParentParamAvatar NoneType 00007FF676133040
end_shot_sfx NoneType 00007FF676133040
_todo_useanim_lock_head bool 00007FF676130F18
armorColliderConroller ArmorCollider 00000000EE7F5F60
listeners _Listeners 00000000F84886D8
_by_anim_has_lock bool 00007FF676130F18
tracker_torso Tracker 000000008BE411F8
_on_step_sound_additional NoneType 00007FF676133040
_teleport_positions_towait NoneType 00007FF676133040
_tick_controller_id NoneType 00007FF676133040
_throw_need bool 00007FF676130F18
_visual_armor_cache NoneType 00007FF676133040
left_weapon_prov HandToWeaponProvider 00000000BEF69788
clanEmblemID int 0000000007A68B90
_crafting_callback NoneType 00007FF676133040
_foot_settings dict 000000007CE81E28
_restore_bellyweapon_callback NoneType 00007FF676133040
weaponStatus int 0000000007A68B90
deaths int 0000000007A68B90
_FootPrinter__water_volume_enable bool 00007FF6761310B8
EquippedGasMaskCond dict 000000010A506F08
test_tracker_gunrw Tracker 000000008BE47378
cellClanID long 00000000F84A6B90
waterListener int 000000004D064230
_AvatarTrackers__saved_action_queue NoneType 00007FF676133040
tracker_weaponback2 instance 00000000F849B548
_HandControl__lock_progress_by_on_hand_weapon bool 00007FF676130F18
_tracker_locks dict 000000010A5064E8
vert_ladder_info PyFixedDictDataInstance 000000009EA04558
_soak_water_listener NoneType 00007FF676133040
shooting bool 00007FF676130F18
_totally_hidden_slots set 00000000B1B9ED68
set_ch_MaxCombatPoints functools.partial 00000000EE7DF1D8
_last_action_type str 000000001D437870
tracker_belly instance 00000000815D9148
_foot_twist_lock set 00000000AEB593C8
_leg_rotate_outside float 000000001D378B10
set_ch_Stamina functools.partial 00000000EE7DF188
set_ch_MaxHitPoints functools.partial 00000000EE7DF278
_UsingItemAnimation__tmp_time float 00000000810546D0
kickbackValue float 000000002BB1C0D8
fix_roll_left_hand bool 00007FF6761310B8
tracker_gun_mover Tracker 000000008BE41538
waterListenerKnee int 00000000817AC3E8
effectsVisibleForAll PyArrayDataInstance 000000009EA026F8
hp_barrel NoneType 00007FF676133040
_leg_rotate_inside float 000000001D378B28
_playing_animation_loot bool 00007FF676130F18
_AvatarTrackers__last_complexItemType int 00000000817AD390
_cabcarsitdata dict 00000000F91EDCA8
effects_posteffects dict 00000000F91EAB28
_hand_blend_prov_complete bool 00007FF6761310B8
_last_model_yaw NoneType 00007FF676133040
colliderNames dict 00000000F91EE908
_processed_vertices list 000000008A1F39C8
_using_item_action_name str 0000000003A75030
_boxgroups NoneType 00007FF676133040
_isBurn_smoke NoneType 00007FF676133040
weapon_slots dict 00000000BEDF65C8
respawn_timer_type long 00000000F84A6B30
_todo_useanim_lock_torso bool 00007FF676130F18
isMovingTest int 0000000007A68B78
_Builder__pull_data_blocks dict 00000000F91EB1E8
_craft_animation bool 00007FF676130F18
_last_hips_cache NoneType 00007FF676133040
tracker_arm_left Tracker 000000008BE3F7F8
_Thrower__throw_ready bool 00007FF676130F18
_last_wound_point NoneType 00007FF676133040
EquippedCond2 list 00000000F849B508
autogunModel NoneType 00007FF676133040
use_gesture bool 00007FF676130F18
set_ch_Accuracy functools.partial 00000000EE7DF098
_end_throw_t int 0000000007A68B90
_AvatarTrackers__start_sprint int 0000000007A68B90
_playing_animation_loot_cam_pos bool 00007FF676130F18
_hidden_item_dress_types set 00000000C0E3C9E8
xTorso TorsoX 0000000102947208
_trackers set 000000007CA4A208
_torso_disbale_by_lookaround bool 00007FF676130F18
_orig_serverLook NoneType 00007FF676133040
colorDelegates PyArrayDataInstance 000000009EA02518
_active_spots set 00000000B1B9E048
ActiveItemID long 000000007DB5F760
_spayer_clouds list 00000000A1037DC8
pvppkstat list 00000000F849E048
need_ladder_yaw NoneType 00007FF676133040
karma int 0000000007A68B90
_FootPrinter__last_surfaceHeight float 000000002C90EEA0
deadCallback NoneType 00007FF676133040
belly_weapon NoneType 00007FF676133040
_hand_gravity_enabled bool 00007FF676130F18
ExchangeProperties PyFixedDictDataInstance 000000009EA02578
transport_seat int 0000000007A68B90
clanName str 0000000003A75030
_AvatarTrackers__last_tracker_key tuple 0000000102955E58
_is_fix_action_sprint bool 00007FF676130F18
_anim_action_out NoneType 00007FF676133040
flashLightID long 00000000AA101630
_hand_wepon_providers_recreted bool 00007FF676130F18
autogunModelVisible bool 00007FF6761310B8
GUNMover_nodeInfo GUNMover 00000001042A6EA8
_FootPrinter__timer_reatt int 00000000363AA1E8
color_alphas collections.defaultdict 0000000055F8CF28
_async_load_counter int 0000000007A68B90
face_controller FaceController 0000000102956198
ActiveWeaponSet2 PyFixedDictDataInstance 000000008BE82938
_last_in_pot_notification NoneType 00007FF676133040
torsoProvider_entity EntityDirProvider 00000000C103D6E8
BellyItemID long 00000000AA101470
headProvider_serverLook PyMatrix 00000000C103D758
used_item_on_target int 0000000007A68B90
_looped_action NoneType 00007FF676133040
tracked_wanted NoneType 00007FF676133040
_leftFreeHandProvider HandFreeProvider 00000001042A74A8
set_ch_HitPointsRegeneration functools.partial 00000000EE7E7368
_particles_burn NoneType 00007FF676133040
EquipModes int 0000000007A68B90
<dummy key> ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл 0000000000000000
_inAir bool 00007FF676130F18
tracker_arm_right Tracker 000000007D2F16E8
emblems_colors dict 0000000055F74688
set_ch_Defence functools.partial 00000000EE7E74A8
headProvider_to_target NoneType 00007FF676133040
_foot_rotate_limit float 000000001D378C48
frags int 00000000C032AFB8
_fence_played bool 00007FF676130F18
ActiveGadgetList PyArrayDataInstance 000000008BE82338
personality PyFixedDictDataInstance 000000008BE81EB8
last_space_name str 00000000C0E49F10
_fake_color_delegates list 00000000C1A404C8
_old_end_shot_sfx NoneType 00007FF676133040
_to_track_progress bool 00007FF676130F18
_dry_start_time NoneType 00007FF676133040
sfx_enabled bool 00007FF6761310B8
_action_callback NoneType 00007FF676133040
_usingItemSound NoneType 00007FF676133040
_UsingItemAnimation__current_action NoneType 00007FF676133040
_potted int 0000000007A68B78
_end_stop_radio_anim bool 00007FF676130F18
fniRight FootNodeInfo 00000000A9BFC248
_using_attach_model NoneType 00007FF676133040
_party_status int 0000000007A68B60
_prev_cheked_key tuple 0000000102955B40
lock_move_by_jump bool 00007FF676130F18
_min_stain_index int 0000000007A68B90
_hips_offset_by_rotate float 000000001D378B40
showNameCallbacker NoneType 00007FF676133040
foots list 00000000B1BD7E88
hideNameCallbacker NoneType 00007FF676133040
name unicode 00000000968EF930
_Gestures__current_gesture_actions NoneType 00007FF676133040
usingGesture int 0000000007A68B90
_FootPrinter__foot_cue_models dict 0000000055F86D48
crouching_or_crawling int 0000000007A68B90
torso_nodeinfo TorsoTrackerNodeInfo 000000004D028A58
_foot_settings_path str 000000002CB2C870
current_effects dict 0000000102DDDF18
is_crafting bool 00007FF676130F18
_restore_bellyweapon_delay float 000000002BB14290
headProvider_cam_dcursor EntityDirProvider 00000000C103D6E8
_callbackOnThrow NoneType 00007FF676133040
_putting_item_replace NoneType 00007FF676133040
_last_wound_time float 0000000081064060
hand_cotrol_wait_tmp bool 00007FF676130F18
headProvider_cam_self EntityDirProvider 00000000C103D6E8
eyes_controller instance 00000000B1BD7EC8
footTriggers list 00000001046704C8
is_throwing bool 00007FF676130F18
_last_ladder_action bool 00007FF676130F18
_rightFreeHandProvider HandFreeProvider 00000001042A76A8
_draw_pickup bool 00007FF676130F18
ch_Defence dict 0000000102DDD858
dead int 0000000007A68B90
_prev_weapon_slots dict 0000000055F8DB88
heli_weapon NoneType 00007FF676133040
set_ch_HitPoints functools.partial 00000000EE7E70E8
ENABLE_MovingActionMather bool 00007FF6761310B8
set_ch_MoveSpeed functools.partial 00000000EE7E72C8
candle int 0000000007A68B90
moving_locked bool 00007FF676130F18
head_nodeInfo HeadNodeInfo 00000000CA333DC8
_AvatarTrackers__saved_yaw NoneType 00007FF676133040
transformationProperty PyArrayDataInstance 000000008BE82218
_current_action NoneType 00007FF676133040
set_ch_MaxStamina functools.partial 00000000EE7E7278
_AvatarTrackers__last_xtorso_data NoneType 00007FF676133040
set_ch_CombatPoints functools.partial 00000000EE7E7188
_lock_bleed dict 0000000102DDD198
_last_grenade_type int 0000000007A68B90
test_nodeInfo_gunrw GUNRWCentrMover 00000001003669B8
tracker_head Tracker 000000007D2F3768
invulnerable int 0000000007A68B90
_soak_enabled bool 00007FF676130F18
_isGasMaskSoundBreathing bool 00007FF676130F18
hoisting_flag NoneType 00007FF676133040
_HandControl__reload_weapon_progress bool 00007FF676130F18
_putting_item_on NoneType 00007FF676133040
teamID int 0000000007A68B90
set_ch_StaminaRegeneration functools.partial 00000000EE7E73B8
_dry_controller NoneType 00007FF676133040
waterListenerHips int 000000002DA5BC30
_tracker_is_init bool 00007FF6761310B8
_total_vertices_number int 0000000007A68B90
tracker_weaponback instance 00000000B1BD7748
_stopped_action NoneType 00007FF676133040
isBleending bool 00007FF676130F18
_hvat_actions dict 0000000102DDE398
_tuck_coroutine NoneType 00007FF676133040
_AvatarTrackers__saved_hands NoneType 00007FF676133040
radiometer Radiometer 00000000EE7E6978
EquippedVisibleAttaches PyFixedDictDataInstance 000000008BE82AB8
_AvatarTrackers__last_data_trackers NoneType 00007FF676133040
tracker_gun Tracker 000000007D2F2A68
_stuck bool 00007FF676130F18
gunnodeInfo TrackerWeaponNodeInfo 00000001049F4F38
hp_barrel_node NoneType 00007FF676133040
_burn_world_model NoneType 00007FF676133040
enable_pitch bool 00007FF676130F18
_hd_end_burn_smoke NoneType 00007FF676133040
active_weapon ClWeapon 0000000102953C88
_HandControl__reload_weapon_osn_anmation bool 00007FF676130F18
_fence_id bool 00007FF676130F18
_need_enable_look bool 00007FF676130F18
_waitSnowTexture dict 0000000055F88188
grenadeArmed bool 00007FF676130F18
_playing_animation_device bool 00007FF676130F18
_headlight Headlight 00000000EE7E2C50
set_ch_Penetration functools.partial 00000000EE7E74F8
_weapon_to_attached str 0000000027E205A0
right_hand_model_sound_node NoneType 00007FF676133040
_Avatar__SFXSeries_callbacks list 00000000A1025C88
_anim_callback_id NoneType 00007FF676133040
_members_subscribed bool 00007FF676130F18
nodeInfoL HandTrackerNodeInfo 0000000082864018
_is_lader_action_played bool 00007FF676130F18
_in_hand_model_left NoneType 00007FF676133040
coloriseEmblems PyArrayDataInstance 000000008BE82098
EquippedArmor PyFixedDictDataInstance 000000008BE80658
waterListenerHead int 00000000C02FFD58
_FootPrinter__cue_model_to_node dict 0000000055F86328
posteffects dict 0000000102DDD4F8
_is_lader_end_action_played bool 00007FF676130F18
_center_ladder NoneType 00007FF676133040
kickBackTimer NoneType 00007FF676133040
right_weapon_prov HandToWeaponProvider 0000000104A7EDB8
_end_use_radio_anim bool 00007FF676130F18
_slope_eff_settings dict 0000000059419CB8
nodeInfoR HandTrackerNodeInfo 000000007D6523C8
collider_boxes dict 0000000055F8BE48
_putting_item_off NoneType 00007FF676133040
_ignorGravityAnimation bool 00007FF676130F18
_burn_sound NoneType 00007FF676133040
set_ch_DamageAbsorb functools.partial 00000000EE7E7548
_fake_item_dress_types dict 0000000055F748C8
_dung_timer_end int 0000000007A68B90
collider_nodes dict 0000000055F8C088
event_current_music NoneType 00007FF676133040
weaponProvider_entity EntityDirProvider 00000000C103D6E8
_HandControl__isEquipProgress bool 00007FF676130F18
head_look_cam bool 00007FF676130F18
pvpFlag int 0000000007A68B90
_Avatar__gun_anim_callback_id2 NoneType 00007FF676133040
_is_jump bool 00007FF676130F18
_water_level NoneType 00007FF676133040
_new_turn instance 00000000C20257C8
_cue_filter dict 0000000055FA9908
megaLodInOutDistanceInited bool 00007FF6761310B8
_burn_tick_id int 0000000007A68B90
_anim_action_in NoneType 00007FF676133040
_tucking_item NoneType 00007FF676133040
_UsingItemAnimation__dealyed_timer int 0000000007A68B90
_colorise_emblems_cache NoneType 00007FF676133040
_async_load_callback int 0000000007A68B90
_stain_index int 0000000007A68B90
friendsList list 000000010468B088
_pygunnode instance 00000000B1BCB0C8
binoculing int 0000000007A68B90
_raise_flag_id int 0000000007A68B90
headProvider_entity EntityDirProvider 00000000C103D6E8
_isBurn NoneType 00007FF676133040
active_weapon_model PyModel 00000000F91524E8
_model_pistol_holster NoneType 00007FF676133040
set_ch_CombatPointsRegeneration functools.partial 00000000EE7E7408
_visual_callback NoneType 00007FF676133040
canTakeDamage int 0000000007A68B90
_prereqs_model_key list 00000000A1025BC8
throwing_node PyModelNode 00000000CA32D678
set_ch_MaxWeight functools.partial 00000000EE7E7458
_stopped_action_played NoneType 00007FF676133040
_prev_matrix NoneType 00007FF676133040
is_burning int 0000000007A68B90
AgrFlag int 0000000007A68B90
fniLeft FootNodeInfo 00000000A9BF62A8
_pygunRWnode instance 00000000B1BD72C8
_sound_only_for_me NoneType 00007FF676133040
_head_exist bool 00007FF6761310B8
_in_hand_model_right NoneType 00007FF676133040
_pot_controller int 00000000363AA0E0
_playing_animation_item bool 00007FF676130F18
last_grenade_damage int 0000000007A68B90
_particles_burn_smoke NoneType 00007FF676133040
_subscribed_to_boat bool 00007FF676130F18
_Avatar__gun_anim_callback_id NoneType 00007FF676133040
_equipped_armor_dirty bool 00007FF676130F18
_auto_clear_callback_id int 00000000817AD210
_foot_nodes dict 0000000081317BC8
effects_sfxes dict 0000000102DDB338
_equipped_modes_cache NoneType 00007FF676133040
_frame_index int 0000000007A68B90
_spayer_tid int 0000000007A68B90
last_model_list dict 0000000102DDF118
_by_anim_weapon_to NoneType 00007FF676133040
transformationID int 0000000007A68B90
deathDrawn bool 00007FF6761310B8
_anim_action_loop NoneType 00007FF676133040
_wound_enabled bool 00007FF676130F18
dataParentParamAvatar NoneType 00007FF676133040
end_shot_sfx NoneType 00007FF676133040
armorColliderConroller ArmorCollider 0000000102953D30
listeners _Listeners 00000000EE7E6518
_by_anim_has_lock bool 00007FF676130F18
tracker_torso Tracker 000000007D2F7868
_on_step_sound_additional str 000000001B015370
_teleport_positions_towait NoneType 00007FF676133040
_tick_controller_id NoneType 00007FF676133040
_throw_need bool 00007FF676130F18
_visual_armor_cache NoneType 00007FF676133040
left_weapon_prov HandToWeaponProvider 0000000104A7FD78
clanEmblemID int 0000000007A68B90
_crafting_callback NoneType 00007FF676133040
_foot_settings dict 000000007CE81E28
_restore_bellyweapon_callback NoneType 00007FF676133040
weaponStatus int 0000000007A68B90
deaths int 0000000007A68B90
_FootPrinter__water_volume_enable bool 00007FF6761310B8
EquippedGasMaskCond dict 0000000102DDB0F8
test_tracker_gunrw Tracker 000000007D2F0D28
cellClanID long 00000000AA101350
waterListener int 000000002DA5BC00
_AvatarTrackers__saved_action_queue NoneType 00007FF676133040
tracker_weaponback2 instance 00000000B1BD75C8
_HandControl__lock_progress_by_on_hand_weapon bool 00007FF676130F18
_tracker_locks dict 0000000102DDE4B8
vert_ladder_info PyFixedDictDataInstance 000000008BE82CF8
_soak_water_listener NoneType 00007FF676133040
shooting bool 00007FF676130F18
_totally_hidden_slots set 00000000B39C8D68
set_ch_MaxCombatPoints functools.partial 00000000EE7E71D8
tracker_belly instance 0000000101BC9F08
_foot_twist_lock set 0000000101BCC748
_leg_rotate_outside float 000000001D378B10
set_ch_Stamina functools.partial 00000000EE7E7228
set_ch_MaxHitPoints functools.partial 00000000EE7E7138
_UsingItemAnimation__tmp_time float 000000008104D6E0
kickbackValue float 000000002BB1C0D8
fix_roll_left_hand bool 00007FF6761310B8
tracker_gun_mover Tracker 000000007D2F3428
waterListenerKnee int 000000002DA5BC18
effectsVisibleForAll PyArrayDataInstance 000000008BE80718
hp_barrel NoneType 00007FF676133040
_leg_rotate_inside float 000000001D378B28
_playing_animation_loot bool 00007FF676130F18
_AvatarTrackers__last_complexItemType int 00000000C0303B80
_cabcarsitdata dict 0000000102DDEED8
effects_posteffects dict 0000000102DDE938
_hand_blend_prov_complete bool 00007FF6761310B8
_last_model_yaw NoneType 00007FF676133040
colliderNames dict 0000000055F87F48
_processed_vertices list 000000010468B948
_using_item_action_name str 0000000003A75030
_boxgroups NoneType 00007FF676133040
_isBurn_smoke NoneType 00007FF676133040
weapon_slots dict 0000000055F87768
respawn_timer_type long 00000000AA101E50
isMovingTest int 0000000007A68B78
_Builder__pull_data_blocks dict 0000000102DDD078
_craft_animation bool 00007FF676130F18
_last_hips_cache NoneType 00007FF676133040
tracker_arm_left Tracker 000000007D2F6EA8
_Thrower__throw_ready bool 00007FF676130F18
_last_wound_point NoneType 00007FF676133040
EquippedCond2 list 000000010468B348
autogunModel NoneType 00007FF676133040
use_gesture bool 00007FF676130F18
set_ch_Accuracy functools.partial 00000000EE7E7318
_end_throw_t int 0000000007A68B90
_playing_animation_loot_cam_pos bool 00007FF676130F18
_hidden_item_dress_types set 00000000B39C8BA8
xTorso TorsoX 0000000102956160
_trackers set 00000000AEB59048
_torso_disbale_by_lookaround bool 00007FF676130F18
colorDelegates PyArrayDataInstance 000000008BE82B18
_active_spots set 00000000AA48C9E8
ActiveItemID long 00000000C2020D78
_spayer_clouds list 000000010468B188
pvppkstat list 000000010468BE88
need_ladder_yaw NoneType 00007FF676133040
karma int 0000000007A68B90
_FootPrinter__last_surfaceHeight float 000000002C90EEA0
deadCallback NoneType 00007FF676133040
belly_weapon NoneType 00007FF676133040
_hand_gravity_enabled bool 00007FF676130F18
ExchangeProperties PyFixedDictDataInstance 000000008BE827B8
transport_seat int 0000000007A68B90

*/


/*Avatar.Entity.PyObjectPlus.object
{
INT8 lock_cancel_trade
INT64 DelayedPutOnItemID
FLOAT32 ItemsWeight
INT32 CreditNumber
UINT8 HushNotifications
INT64 ActiveItemID
 BLOB ActiveWeaponSet2
ARRAY ActiveGadgetList
ARRAY ActiveArtifactList
ARRAY FakeActiveGadgetList
ARRAY CarryingItems
ARRAY KnowingRecipes
INT8 CanShoot
INT8 CanUse
PYTHON neededIDFunction
 BLOB ExchangeProperties
MAILBOX ExchangeOpponentMB
INT32 LastExchangeID
ARRAY pendingItems
INT32 GoldCreditNumber
ARRAY ActiveItemPollutions
INT64 BellyItemID
INT64 flashLightID
ARRAY BatteryConsumers
ARRAY StoredItems
ARRAY coloriseEmblems
ARRAY colorDelegates
ARRAY myEmblems
UINT8 is_use_extractor
INT64 radio_working
UINT8 dead
UINT8 canTakeDamage
UINT8 invulnerable
UINT8 mobNoAggr
ARRAY allowedDamagers
ARRAY damage_restrictions
UINT8 canDamage
ARRAY effects
FLOAT32 HPKoeff
ARRAY effectsVisibleForAll
INT8 crouching_or_crawling
UINT8 binoculing
INT8 weaponStatus
UNICODE_STRING name
INT32 frags
INT32 deaths
ARRAY EquippedCond2
 BLOB EquippedArmor
 BLOB EquippedVisibleAttaches
 BLOB EquippedVisibleAttachesIDS
INT8 EquipModes
INT32 transport_seat
INT32 lastGlobalMessagesPoll
 BLOB TP_params
 BLOB TP_previous_position
UINT8 TP_params_changed
FLOAT32 chanceModCD
FLOAT32 powerModCD
INT16 sturdinessMod
UINT8 ExpCoefficient
UINT8 CharacterCombatLevel
UINT8 CharacterSurvivalLevel
UINT8 CharacterOtherLevel
INT8 CharacterClass      
UINT32 CombatExperience
UINT32 SurvivalExperience
UINT32 OtherExperience
INT32 CombatSkillPoints
INT32 SurvivalSkillPoints
INT32 OtherSkillPoints
INT32 CombatPerkPoints
INT32 SurvivalPerkPoints
INT32 OtherPerkPoints
FLOAT32 PlayerDefaultCounter
ARRAY WeaponAdaptations
INT32 WeaponAdaptationCounter
ARRAY defences
INT32 SocialStatus
 BLOB CombatSkills
 BLOB SurvivalSkills
 BLOB OtherSkills
ARRAY mobs
INT8 mobsType
STRING mobs_subtype
FLOAT64 lastMobDeathTime
ARRAY st_avatars
INT8 pend_state
ARRAY CellQuestPersistProp
PYTHON QuestPersistentData
PYTHON pers_data_base
ARRAY questsPendingRemoval
ARRAY QuestsCounters
 BLOB PVPInfo
 BLOB QuestsList
ARRAY favoriteList
ARRAY CellQuests
ARRAY _effect_quests
 BLOB savePoint
ARRAY questTakenTime
ARRAY questScenariesOnTest
ARRAY questScenaries
ARRAY lastDialogs
INT64 restoreDialog
INT32 lastInterlocutorID
INT16 tutorial_phase
ARRAY quest_listeners
 BLOB autofailblob
ARRAY _visited_events
STRING clanName
ARRAY clanEnemies
ARRAY clanAlliancesIDs
INT32 clanEmblemID
INT64 clanID
INT64 cellClanID
INT64 localBaseClanID
INT64 clanRights
STRING nameBaseToCapture
STRING underatack_base_name
INT64 ownerBase
 BLOB base_tracker
 BLOB reinfp_tracker
INT8 show_tracker
MAILBOX party
ARRAY member_ids
ARRAY party_quests
ARRAY visited_npcs
 BLOB lastSpatialInfo
 BLOB ch_HitPoints
 BLOB ch_MaxHitPoints
 BLOB ch_CombatPoints
 BLOB ch_MaxCombatPoints
 BLOB ch_Stamina
 BLOB ch_MaxStamina
 BLOB ch_MoveSpeed
 BLOB ch_Accuracy
 BLOB ch_HitPointsRegeneration
 BLOB ch_StaminaRegeneration
 BLOB ch_CombatPointsRegeneration
 BLOB ch_MaxWeight
 BLOB ch_Defence
 BLOB ch_Penetration
 BLOB ch_DamageAbsorb
 BLOB ch_Strength
 BLOB ch_Agility
 BLOB ch_Perception
 BLOB ch_Intelligence
 BLOB ch_Endurance
 BLOB ch_Psy
ARRAY paint_items
ARRAY relations
ARRAY fraction_relations_copy
FLOAT32 lastWriteTime
ARRAY relationsWithFractions
ARRAY friends_list
ARRAY blackList
 BLOB __base_timer_controllers__
 BLOB __base_call_once_controllers__
PYTHON __base_args_by_user_data__
 BLOB __timer_controllers__
 BLOB __call_once_controllers__
PYTHON __args_by_user_data__
ARRAY instanceSave
UINT8 dungeon_id
INT8 teamID
UINT8 inPVPinstance
MAILBOX csRoom
MAILBOX csRoomCell
ARRAY gifts
ARRAY sentgifts
ARRAY mqWinner
UINT16 transformationID
ARRAY transformationProperty
ARRAY saved_pos
ARRAY saved_time
FLOAT32 last_maxspeed
FLOAT32 current_maxspeed
VECTOR3 _ring_disp
INT32 vacant_positions
ARRAY attackers_data
INT32 current_event_id
INT32 tmp_grenade_thr
UINT8 account_is_frod
 BLOB personality
MAILBOX specMBspace
UINT8 candle
UINT8 is_burning
 BLOB vert_ladder_info
UINT8 im_in_jail
INT8 usingGesture
UINT8 cellPrintDebug
INT8 CountWaitChetsResponse
STRING parentAccountName
INT32 randomKeyListProccess
STRING lastHWID
INT64 parentAccountDBID_cell
INT32 proximity_id
INT32 anomaly_proxy_id
INT8 prem_id
INT8 boost_id
INT8 ninjaMode
UINT8 isAdrenaline
PYTHON ListInvite
PYTHON friendsList
UINT8 AgrFlag
UNICODE_STRING HUNTER_killerName
STRING HUNTER_killerClanName
INT8 HUNTER_killerWanted
INT8 HUNTER_iWanted
INT8 HUNTER_iFiledHunting
INT32 HUNTER_killerKarma
ARRAY HUNTER_listOfWanted
ARRAY HUNTER_lostListOfWanted
FLOAT32 hungryValuePrivate
FLOAT32 thirstValuePrivate
UINT8 isPlayerInHotRegion
UINT8 speak_area_captured
FLOAT32 hungry
FLOAT32 thirst
UINT8 gun_invul
 BLOB last_shot
 BLOB shootFairness
ARRAY restrictions
INT64 dbID_on_cell
ARRAY mapNotes
ARRAY visitedSpaces
INT64 chat_off_until
UINT8 chat_off
UINT8 cell_chat_off
INT64 cell_chat_off_until
UINT8 haveWebClient
FLOAT64 userCommandLastUse
INT64 fPlayerWiped
INT64 parentAccountDBID
UNICODE_STRING nameOnBase
MAILBOX parentAccount
MAILBOX cellParentAccount
INT32 logoutTimer
MAILBOX spawnerBase
UINT8 createByDev
UINT8 baseAccessLevel
UINT8 cellAccessLevel
UINT8 UserFromMasterPassword
UINT8 baseUserFromMasterPassword
UINT8 clientAccessLevel
UINT8 sprinting
INT8 pvpFlag
UINT8 pvpFree
INT32 pvpCounter
FLOAT64 lastLogInTime
FLOAT64 lastLogOutTime
INT32 pkCounter
INT32 karma
INT32 worldLoadTimoutTimer
INT32 worldLoad
STRING lastSpace
INT64 groupID
UINT8 in_combat
FLOAT32 waterHeight
INT32 waterType
ARRAY visitedSpawnAreas
STRING mainSpawnArea
 BLOB mainSpawnAreaConfig
STRING prevSpawnArea
INT32 artifactVisionControllerID
ARRAY Possibilities
ARRAY quickSlotBars
INT32 quickSlotActiveLineNumber
 BLOB gps_teleport_info
UINT8 used_item_on_target
INT64 respawn_timer_type
ARRAY weather_stack_value
ARRAY weather_stack_id
INT8 lie_down_counter
FLOAT64 safe_exit_time
BLOB looting_info
ARRAY current_safe_info
INT64 filters
BLOB use_heal_item
UINT8 isMovingTest
FLOAT32 stamina_delta_usage
ARRAY converted_items_counters
UINT8 radio_talking
MAILBOX _cabman_seat
 BLOB lastTransportPos
INT32 base_space_id

}*/




};



struct CursorCamera : public PyObject // CursorCamera : BaseCamera : PyObjectPlus : object
{

};
struct CameraImpl  // CursorCamera : BaseCamera : PyObjectPlus : object
{
	bool ProjectWorldToScreen(Vector3 target, Vector2* screenpos,bool* cachematrix);
	bool ProjectWorldToRadar(Vector3 target, Vector3 player_position, Vector2* screenpos, int distance, bool* cachematrix);
	static CameraImpl* Instance();
	void CameraPosChange();
};






struct PlayerAvatar : public Entity
{
	Py_dicthead;
	Py_AttributeHASH(PlayerAvatar, PyUnicodeObject*, name); 
	Py_AttributeHASH(PlayerAvatar, PyINT8Object*, enteredWorld);
	Py_AttributeHASH(PlayerAvatar, PyINT8Object*, dead);

	DumpAttribute(PlayerAvatar);

	int speed();

	//Py_Attribute(PlayerAvatar, CursorCamera*, AvatarCam); // CursorCamera : BaseCamera : PyObjectPlus : object
	std::string GetName()
	{
		auto n = name();
		if (!n)
			return std::string();
		auto utf = n->to_string();
		return utf;
	}

	bool is_enter() {
		auto isenter = this->enteredWorld();
		return isenter->get();
	}
	bool is_dead()
	{
		auto isdeadproperty = this->dead();
		return isdeadproperty->get();
	}
};
/*
CarryingItems PyArrayDataInstance FFFFFFFFDCD42004
_prev_cheked_key tuple 00000000228AB805
uf_item NoneType 000000005DBAA806
AvatarCam CursorCamera 000000000917F009
ch_MaxCombatPoints PyFixedDictDataInstance FFFFFFFFE63B6811
KnowingRecipes PyArrayDataInstance 0000000004DD1012
_loop_anim_dwn_test_id int FFFFFFFFC6C96AAE
_need_torso_roll_value int 000000007FD716DF
inPVPinstance int 000000005DD8D01D
used_item_on_target int 000000003DE89020
_looped_action NoneType FFFFFFFF98F8F021
artefactExtractor NoneType 00000000130734D7
_uf_player_pos NoneType 0000000005E9FA7F
_t_lo_off int 000000002B78D828
last_shot_time NoneType FFFFFFFF827EE02B
_last_anomaly_drag float 000000007324C82C
clanID long 000000000509482D
_tucking_item NoneType 000000003A7F382F
isTogleCursor bool FFFFFFFFAC35B830
tracker_arm_right Tracker FFFFFFFFA01D7031
_AvatarTrackers__last_tracker_key tuple FFFFFFFFFE51B009
_uf_position NoneType 0000000079D26838
_belly_to_right_played bool FFFFFFFFA7AE1AB4
itemChangeTimer int 0000000036C3855F
_todo_useanim_lock_foot bool 0000000030DF46DE
_old_end_shot_sfx NoneType FFFFFFFFEFE9C042
_to_anim bool 00000000566DF844
_unl_magz_id int FFFFFFFF9F905430
marks_data MarksData FFFFFFFFCD3DA04B
_fade_inventory_filter_function NoneType FFFFFFFFD33C684F
_DialogActions__dialog_sound NoneType 000000005FED1852
NPCBarterItemList list FFFFFFFF93445855
previous_fallingvelocity float FFFFFFFFC17A0056
craftItemList list 0000000005F4585A
damageDoneTexts list FFFFFFFF81170EBA
_velocity_hook_value_to NoneType 00000000687104B9
_fake_color_delegates list FFFFFFFFA8FC8060
_StoreHouse__cashe_avatar_dbid int FFFFFFFF9E6E9862
GUNMover_nodeInfo GUNMover FFFFFFFFD6866811
crouching_or_crawling int FFFFFFFFBA31286B
_end_finish_dead_id NoneType FFFFFFFFB6B8C06C
lazy_minimap_controller MinimapController FFFFFFFFBEDCD012
_foot_settings_path str 000000001C41386E
_talk_entity NPC FFFFFFFFF263FEBD
last_space_name str 00000000491AE968
ninjaMode int FFFFFFFFA1F8D874
_last_wound_time float FFFFFFFFE310B875
_wait_real_stop_id int 0000000045E41078
quickSlotActiveLineNumber int 000000004903E07B
_play_sound_put_item_timer int 000000004CB44ADF
_trade_screen instance FFFFFFFFA20B907F
torso_roll_value int FFFFFFFF8CE4016B
footTriggers list 000000006ECE6087
_anim_to_played bool 0000000077F1F88D
_start_time_slope float 000000005F72208E
_camera_isWeapon int 00000000594FD095
_Climb__last_pos_tmp Math.Vector3 FFFFFFFFFFF56899
_AvatarTrackers__saved_yaw NoneType FFFFFFFFF942809C
set_ch_MaxStamina functools.partial 000000006887C0A1
_dung_timer_end int 000000004505F8A4
_last_grenade_type int FFFFFFFF8B0F98A5
antiSpeedGearCallback NoneType 000000006EAF80A8
_areas_counter AreaCounter FFFFFFFFF6C448AC
is_olive_fun_srd NoneType FFFFFFFF89EE3C7E
_HandControl__reload_weapon_progress bool FFFFFFFFC2B6981D
snipingScopeType int FFFFFFFF98D568B0
teamID int FFFFFFFF9D94C8B2
EnableTargettingCallback NoneType 0000000076E148B3
_stopped_action NoneType FFFFFFFFC51380BC
isBleending bool 0000000042A010BD
hp_barrel_node NoneType FFFFFFFFFD86F6CC
is_crafting bool FFFFFFFFDA1388CE
_hd_end_burn_smoke NoneType FFFFFFFFCF1060CF
_locked_action_items list 00000000426990D3
_last_token str FFFFFFFFA8C1BECE
_waitSnowTexture dict FFFFFFFFAED3C8D6
_DialogActions__dialog_camera NoneType 0000000024BE38D9
_playing_animation_device bool 0000000038CE18DC
_headlight Headlight FFFFFFFFA26DF8DD
_uf_err_code int FFFFFFFFCD0DC0DE
_timerFakeDamageID int FFFFFFFFBA1DA8DF
reload_from_sprint bool FFFFFFFF8CA368E3
_members_subscribed bool 00000000686560E4
movingLeft bool 000000001CBA88EB
movingBackward bool 000000005FFCA0EF
_is_lader_end_action_played bool 000000003F3780F0
_AvatarJump__down_duration_left float FFFFFFFF9F1E50F4
moveUpDamagesTimer int FFFFFFFFD98D10F7
CreditNumber int FFFFFFFF94CEF0FC
_ignorGravityAnimation bool FFFFFFFFA9E5F0FE
activeAnomaly int 0000000001980100
collider_nodes dict 0000000056A1D904
pvpFlag int FFFFFFFFB1C6390F
torso_nodeinfo TorsoTrackerNodeInfo 000000007EC6D912
_water_level NoneType FFFFFFFFAF983913
tutorial_phase int 000000006BDC9118
_e_hib_id int FFFFFFFFEDF4C119
transformationProperty PyArrayDataInstance 0000000073B5891A
_potted bool FFFFFFFFB4FCE11C
_danger_coroutine instance 00000000640FC120
shotlog collections.deque FFFFFFFF97DD0121
_async_load_callback int 0000000028E40922
gotten_barter_item_types collections.defaultdict FFFFFFFFADABC126
client_respawn_timer_value int 0000000061418ECA
controlLocks dict FFFFFFFF9C3E392D
_visual_callback NoneType FFFFFFFF89B3B12F
set_ch_MaxWeight functools.partial FFFFFFFFB77D2935
_jmp_up_position Math.Vector3 0000000047C5B936
EquippedGasMaskCond PyFixedDictDataInstance FFFFFFFFFC427189
_tick_ret_dcursor_id int 000000005CB4D939
last_model_list dict 000000001606E13A
hand_cotrol_wait_tmp bool FFFFFFFFA9C0313B
fniLeft FootNodeInfo 0000000073F7713D
_PlayerMovement__slope_material_id int 000000005E90C140
_sound_only_for_me NoneType FFFFFFFFADCCE944
_protect_counter NoneType 0000000065672945
visited_spaces PyArrayDataInstance 0000000069FF4146
_in_hand_model_right NoneType 00000000137E9947
_pot_controller NoneType FFFFFFFF894AA948
_playing_animation_item bool 0000000011155149
_DialogActions__rotate_step int 000000000FDCE14F
_cd_id int FFFFFFFFBA171950
__sfx_model__ PyModel FFFFFFFF9B940152
relationshipClanParam dict FFFFFFFFF86E011C
_knowledge_requesters dict 000000001F102C88
_jmp_down_played bool 000000006882595B
_spayer_tid int FFFFFFFFC905215C
old_cl tuple 000000005830595D
deathDrawn bool FFFFFFFFE266E968
_anim_action_loop NoneType FFFFFFFFCE02716B
_last_ladder_action bool 000000006F6E296C
_breathing_sound NoneType FFFFFFFFD6AD0173
tracker_torso Tracker 000000007EE82175
_on_step_sound_additional NoneType 000000001D397176
lazy_data_loader DataLoader 0000000041962EE9
_throw_need bool 00000000249A243F
canDamage int FFFFFFFFAA7EB97C
_sniping_key_pressed bool FFFFFFFFA42AA57A
_PlayerAvatar__antiPingCallback int FFFFFFFFF7AA217F
blockEscAfterInventoryClosed bool FFFFFFFFE5872180
clanEmblemID int FFFFFFFFC403A181
_HandControl__x2 float 0000000029C532EB
_world_load_time float FFFFFFFFAE315984
_stop_time_slope float FFFFFFFFD5E43985
weaponStatus int 0000000067F2E186
_FootPrinter__water_volume_enable bool FFFFFFFFF4B24988
_stopped_action_played NoneType FFFFFFFFAAFD4989
quickSlotBars PyArrayDataInstance FFFFFFFFF36CD98A
acResultEvent _Event 000000004A3F798C
_PlayerAvatar__played_damage_sound float 000000007DFD0042
_putting_item_off NoneType FFFFFFFFADE7C98F
_UsingItemAnimation__wait_models dict 000000002FE96190
lie_down_counter int FFFFFFFFB2148194
vert_ladder_info PyFixedDictDataInstance FFFFFFFFAF30E197
_soak_water_listener NoneType FFFFFFFFC842C998
set_ch_MaxCombatPoints functools.partial FFFFFFFFE28CE99E
_last_shot_time float FFFFFFFFBE78669D
possible_barter_count int 0000000002A739A1
_Climb__need_add_up float 000000004D33DD9B
ch_DamageAbsorb PyFixedDictDataInstance 000000006DB699A7
waterListenerKnee int FFFFFFFFFFD231AD
_need_torso_roll_left bool 0000000065DC1DA0
ToolTipRepairIDFunc NoneType 0000000025B759B4
spiderModelsDict dict FFFFFFFFD159B1B5
hideNameCallbacker NoneType FFFFFFFFE577D1BB
head_nodeInfo HeadNodeInfo 0000000040F611BC
firstPersonCamera int FFFFFFFFE28A51BD
fraction_relations_copy PyArrayDataInstance FFFFFFFFA189A1BF
colliderNames dict 00000000688319C1
ch_Defence PyFixedDictDataInstance FFFFFFFFC49299C2
_boxgroups NoneType FFFFFFFFFF9359C4
isTrade bool FFFFFFFF9A2B19C5
_talk_pot NoneType 000000005F74F9C8
_player_current_fov float FFFFFFFFFBF699C9
weapon_slots dict 000000003A01C9CA
movingRight bool FFFFFFFFC2A711CF
_danger_pp_id NoneType 000000006F840C4E
clanEnemies PyArrayDataInstance FFFFFFFFB48039D7
_cancel_action_func NoneType 00000000525211D8
use_gesture bool 00000000300801DE
tracker_head Tracker 000000007DB85371
_npc_id_talk int FFFFFFFFDF3E81E1
cheatCount int FFFFFFFFFD14B8F0
_is_walk bool 000000000AA5F6FD
ch_Accuracy PyFixedDictDataInstance FFFFFFFFC76B21F0
cacheMode NoneType 00000000031489F2
clanAlliances PyArrayDataInstance FFFFFFFFE04909F3
need_ladder_yaw NoneType FFFFFFFFE4B231F4
ExpCoefficient int 000000003E9FB9F6
_ViewControl__torso bool FFFFFFFF969C79F9
pvpFree int FFFFFFFFAF8CE1FB
updateInventoryTimer NoneType FFFFFFFF849019FC
ExchangeProperties PyFixedDictDataInstance 0000000004EE89FE
client_respawn_timer_type int 00000000763BE200
_raw_packet_gen NoneType FFFFFFFFCE1ADA06
_is_fix_action_sprint bool 000000000061820A
_Inventory__unload_ammo_last_time NoneType FFFFFFFFCEB5220B
flashLightID long 000000004E14020D
_rep_data dict 000000001B430A0E
_id_partially_upd int FFFFFFFFC5CDD212
color_alphas collections.defaultdict FFFFFFFFD8FBCA13
matrixAddPosTargetMatrix PyMatrix FFFFFFFF974D8E52
lookingaround_smooth bool 00000000404B4215
base_tracker PyFixedDictDataInstance FFFFFFFF847CD216
tracked_wanted NoneType FFFFFFFFFE34E21A
torsoProvider_entity EntityDirProvider FFFFFFFFA328221C
BellyItemID long FFFFFFFFE958EA1D
headProvider_serverLook PyMatrix 00000000004FBA1F
runEnabled bool FFFFFFFFCC1BA220
weaponProvider_entity EntityDirProvider FFFFFFFFBA53B706
ch_MoveSpeed PyFixedDictDataInstance 000000004BF53A28
_danger_pp NoneType 000000000FDD47BB
_equipped_modes_cache NoneType 0000000022AF722F
PCTradeItems list 0000000041E2F231
_PerkUser__callbacks list 00000000581E8234
_cam_sprint_value float FFFFFFFFD219D060
_new_turn instance 000000006AB22A42
_ViewControl__foot bool 000000000C0D3B0B
items_in_shop list FFFFFFFF81046A44
_dry_start_time NoneType FFFFFFFFBEAB9A4E
_dry_controller NoneType FFFFFFFFC3496252
set_ch_MaxHitPoints functools.partial FFFFFFFF97F4CA5A
_leftFreeHandProvider HandFreeProvider 0000000037A2D25B
_last_jump_conf NoneType FFFFFFFFDCC00A5C
_min_stain_index int FFFFFFFFD3134A5E
_cabcarsitdata dict 00000000458511BB
pongChecker NoneType FFFFFFFF8768EA64
name unicode 0000000000E56A65
_Gestures__current_gesture_actions NoneType 00000000306A2266
_outside_shell int 00000000190BBA69
_need_play_action_down_move bool FFFFFFFFE5BA3F7B
_last_killer_avatar_data dict 000000006BCAEA6C
_head_node PyModelNode FFFFFFFFD60A5F12
breath_holding_sound Sound 00000000389E726E
reloading int FFFFFFFFC1635A70
headProvider_cam_dcursor MatrixProvider 000000002DFDB272
magnitude float FFFFFFFFA8B1BA73
_putting_item_replace NoneType FFFFFFFF8A7BBA74
autogunModelVisible bool 00000000094E0A75
nedd_restore_run_after_crouch bool FFFFFFFF849D54CB
_PlayerAvatar__hp_timer_id int 0000000044442277
_velocitytickID int FFFFFFFF8CED8A79
cl_isMovingTest bool FFFFFFFFE7A2427D
_friends_online CaseInsensitiveStringListSet FFFFFFFFF7CBCA7F
eyes_controller instance 00000000381F9286
callbackUpdateEntitiesMarks NoneType 0000000003612288
moving_repeat bool 0000000000500289
RestrictionActionNames dict 000000001A5EF28A
_draw_pickup bool FFFFFFFFB5504A8C
_processed_vertices list 00000000140649C2
_prev_weapon_slots dict 000000001B972A8F
heli_weapon NoneType FFFFFFFFB47F1290
set_ch_HitPoints functools.partial 0000000023FAEA91
_danger_blend instance 000000004B762A93
ENABLE_MovingActionMather bool 000000003BB59A96
_Avatar__shot_played bool 0000000046E5F298
moving_locked bool FFFFFFFF813F2A9A
_foot_settings dict FFFFFFFF89206A9B
inputlock bool 00000000320AAAA0
finish_dead_entity_id NoneType 000000004AE802A1
_todo_useanim_lock_torso bool 00000000167F12A2
set_ch_CombatPoints functools.partial 00000000284BB2A3
_lock_bleed dict FFFFFFFFB203A2A4
lastdirection Math.Vector3 000000002FC4AAA6
ch_Stamina PyFixedDictDataInstance 000000006F3082A9
FakeActiveGadgetList PyArrayDataInstance FFFFFFFFDD521AAD
thirst float 00000000506A2AAE
_putting_item_on NoneType 0000000025589AB0
ch_StaminaRegeneration PyFixedDictDataInstance 000000006A1841C8
_quests_tracker QuestsTracker FFFFFFFFECE8A2B4
debugEnabled bool 000000005D99A2B8
_can_fade bool 000000002462F2B9
_ViewControl__send_head_prev tuple 000000003662E7FC
UserFromMasterPassword int FFFFFFFF8B230ABE
_fader_sound_ambient Fader 000000000876DAC0
camera_in_interior bool FFFFFFFFA40CB2C2
_last_maxSpeed float FFFFFFFFCD90CAC3
_is_weapon_collide_off_time float 0000000008D2DAC6
gunnodeInfo TrackerWeaponNodeInfo 0000000060BED2C9
last_target int FFFFFFFFD0131ACB
_fader_sound_weather Fader FFFFFFFFCBC9C2CC
_PlayerAvatar__bl_ret_dcursor instance FFFFFFFFD914C2CD
kickBackTimer NoneType FFFFFFFF9B92B2D3
_slope int FFFFFFFF9FECC2D6
_param_msg_id long 000000002D956ADD
GoldCreditNumber int 0000000065CDEADE
_weapon_to_attached str 0000000030BCF2DF
weapon_was_in_hands_type int FFFFFFFFD43C8F26
_is_lader_action_played bool 0000000074F24AE6
_in_hand_model_left NoneType 0000000039AB92E7
_head_matr_by_animation PyMatrix FFFFFFFFF08B4AE8
_controller_id int FFFFFFFF8DDD2AEB
_prev_move_vec Math.Vector3 000000003A9DDAED
_FootPrinter__cue_model_to_node dict 000000000BF4CAEE
_DialogActions__dialog_callback NoneType 00000000518BC2F3
right_weapon_prov HandToWeaponProvider FFFFFFFFE07BD2F4
_end_use_radio_anim bool 000000007FFA42F5
exchangePot NoneType 00000000691DF2F7
_looking_around_mult float FFFFFFFF805474C7
_burn_sound NoneType FFFFFFFF8A1282FF
_reload_coroutine NoneType FFFFFFFFBAE99B02
_checkInShellID int FFFFFFFFF9BBDB06
targetObjects dict FFFFFFFFDA182B08
TraderID int FFFFFFFFA9465B0B
msgFromShop list 0000000005F46FFC
_radio_stop_callback NoneType FFFFFFFFFCB30313
_cue_filter dict FFFFFFFFF8942316
ItemsWeight float 000000005A20BB17
_PlayerAvatar__cur_vec Math.Vector3 FFFFFFFF956A4B1C
waterListenerHips int FFFFFFFFD1C1A31E
context_menu_item dict FFFFFFFF84FE8320
_fence_id int FFFFFFFFF07CC323
friendsList list 0000000075BCBB24
_sprintsoundid int FFFFFFFFA9195325
canTakeDamage int FFFFFFFFFEC6B331
kickbackValue float 0000000068CC532B
active_weapon_model PyModel FFFFFFFFEE103B2C
_slope_sound_loopid int FFFFFFFF87B32B2D
_need_stop_actions bool FFFFFFFFA71F9C88
_is_sprinting_action bool 0000000059A4DB33
radio_working long 0000000078B37B38
_Climb__down_start_delay int 000000001A280B39
AgrFlag int 0000000037FAEB3B
_loaded_inventoryPos dict 0000000066263B41
_Inventory__unload_ammo_callback NoneType 0000000014488343
_particles_burn_smoke NoneType 00000000551AB34B
_colorise_emblems_cache NoneType FFFFFFFFC4667351
_is_jump_up_or_fly bool FFFFFFFFE00DB08E
h_crawl_left_hand_anim bool 000000007AADF1FE
_is_tired_after_sprint bool FFFFFFFFD4FD035C
_destroy_counters_controller_id NoneType FFFFFFFFC7313B5F
_ready_attemts int 000000003D56CB3B
transformationID int FFFFFFFFE58AE364
dataParentParamAvatar NoneType 000000003CB0136D
_DialogActions__last_npc_weapon NoneType 000000007EF2A36E
_under_water_sound NoneType 000000000EF9A371
listeners _Listeners 0000000012AB1B72
boost_id int FFFFFFFFDFA7D373
_weapon_settings dict 000000001DF79B7D
_Climb__need_add_fw float 000000004E55C895
left_weapon_prov HandToWeaponProvider 000000003904D380
_isBurn NoneType 000000006013FB87
angle_phy_cur int FFFFFFFFCFA9838B
_dialog_npc NoneType 0000000028DCB38C
test_tracker_gunrw Tracker 000000004BFC238D
_last_iswanted_data tuple FFFFFFFFCED7E391
_PlayerBuilder__buffer_blocks list FFFFFFFFBDDACB43
_HandControl__lock_progress_by_on_hand_weapon bool 000000001119A394
_tracker_locks dict 0000000056E3EB96
_AvatarTrackers__saved_action_queue NoneType 000000006F30AB98
_leg_rotate_inside float FFFFFFFF95B00B9E
_prev_ft_to dict 000000001C5C5BA0
cacheObjectID NoneType FFFFFFFFFF7253A1
ch_Penetration PyFixedDictDataInstance FFFFFFFFACFB33A5
_anomaly_counter NoneType FFFFFFFFCF8ADBAB
_last_weapon_model PyModel FFFFFFFFA34979F6
_achiv_ids set 00000000444363AD
camerainwater_listeners list FFFFFFFFCA7E83B0
prem_id int FFFFFFFFFAE4F1F3
ping_average float 0000000032214BB4
_AvatarTrackers__tired_end_timer_id int 000000004DD6D9F4
_send_blocks_timer int 00000000158DBBBA
effects_posteffects dict 00000000228B63BC
_Climb__curr_add_up int FFFFFFFFF1A673BF
weapon_was_in_hands_id long FFFFFFFFFD8BEB4B
RestrictionCallbacks dict FFFFFFFFDEFA81F6
ClientChannelServerWaiting dict 000000005D3D8BC6
_Climb__vec_add Math.Vector3 FFFFFFFFE18CC8A1
respawn_timer_type long 00000000253B23CB
_Builder__pull_data_blocks dict 000000007CA0E74D
_press_reload_time float FFFFFFFFF58DBD46
worldLoad int 000000003F6223D1
_stop_sprinting_auto_id int 0000000019BA93D3
tracker_arm_left Tracker FFFFFFFFDBCBFBD5
autogunModel NoneType FFFFFFFFBEE1E3DC
NPCBarterSelectedList int 0000000045DC0BDF
set_ch_Accuracy functools.partial 000000006C58ABE1
_last_mov_time float FFFFFFFF9DFF1BE2
_Avatar__brust_id int 0000000034EDC1FB
sprinting int FFFFFFFFD9AB2BE5
_trackers set 00000000390A43E9
targetMatrix MatrixProduct 0000000019055BEC
hungry float 00000000018B6BED
binocularMode int FFFFFFFFC18C0BEF
pvppkstat tuple 000000002BF32BF2
_lensback_node NoneType FFFFFFFFD0DEE3F3
_Avatar__gun_anim_callback_id2 NoneType 000000001B652C5A
myEmblems PyArrayDataInstance 00000000556FD9FE
_FootPrinter__last_surfaceHeight float FFFFFFFFCEAE8BF6
_start_jtime float 00000000522C7CA9
_Inventory__quest_cache_for_items list 0000000013DA23F8
minimap_controller MinimapController FFFFFFFFF762DBFA
transport_seat int FFFFFFFF8AFB2BFF
_fav_relations list 000000004C32B40A
effects_sfxes dict FFFFFFFFCD7D0F57
_HandControl__x float FFFFFFFFE542240C
ch_MaxWeight PyFixedDictDataInstance 000000000B2AA412
_HandControl__climb_command NoneType FFFFFFFF92D86EE9
radio RadioGadget 000000000C136414
ActiveWeaponSet2 PyFixedDictDataInstance FFFFFFFFB1C2B418
emblems_colors dict 00000000162D241A
_ViewControl__disable_particle bool FFFFFFFFF65A4C1E
no_weapon_in_hands bool 000000003D2CA41F
_npc_client_talk_entity NoneType FFFFFFFFD43D6424
to_use_item_ids list FFFFFFFFAD9C4427
set_ch_HitPointsRegeneration functools.partial FFFFFFFFE71FBC28
_sound_dealy_id int 000000000840E42D
_inAir int FFFFFFFFC7824430
set_ch_Defence functools.partial 000000007E64BC35
clientAccessLevel int 000000000BE41436
headProvider_to_target NoneType 0000000065F36C37
throwing_node PyModelNode 0000000033A18C3A
_fence_played bool 00000000248FFC3D
ActiveGadgetList PyArrayDataInstance 000000000BF0FC3E
personality PyFixedDictDataInstance 000000001EA5243F
personal_marks_loaded instancemethod 000000001C81A444
_Climb__addphy_coro NoneType FFFFFFFFB0F91449
need_stay_after_crouch bool 00000000143B5C4A
ch_CombatPoints PyFixedDictDataInstance 000000000D6DFC4E
SellMode int 000000005651FA0D
_usingItemSound NoneType FFFFFFFFEC0CB452
_UsingItemAnimation__current_action ActionQueuer FFFFFFFFAC319453
_hand_wepon_providers_recreted bool 000000001083220E
_end_stop_radio_anim bool 00000000090DF457
fniRight FootNodeInfo FFFFFFFFDE1C9459
_using_attach_model NoneType 000000006A2A145A
_party_status int 0000000029473C5B
angle_phy int 0000000068C2245C
lock_move_by_jump bool 000000003A6AE45D
clanRights long 0000000016D3945F
showNameCallbacker NoneType FFFFFFFFEDF04460
_dialog_hide_areas list 000000005EAFB463
_totally_hidden_slots set 000000006D1C7466
_Climb__curr_add_fw int FFFFFFFFF0E01611
_wt_neck PyModelNode FFFFFFFFC222246C
ReportChangedItemDict dict FFFFFFFFA63FAC6E
current_effects dict 000000003E57A46F
_listeners list 000000001F955C70
exchange_selected_item NoneType 000000002DC59213
h_crawl_anim_played bool FFFFFFFFDB7BD475
_prev_slope_material_id int FFFFFFFFF3A494BF
_trade_pot NoneType FFFFFFFFB78A647D
battleLogTargetEntity NoneType 00000000631FCADF
_send_head_ts float FFFFFFFFB9A4C47F
lastTargetedAvatar NoneType 0000000008193C81
_AvatarTrackers__last_data_trackers NoneType 0000000040BAAC83
PCTradeMoney int 0000000020FF3CC1
is_throwing bool 00000000255FF488
_foot_rotate_limit float FFFFFFFF9AA40489
lasttimekey float 000000007411E48B
_foot_nodes dict 000000003B7CFC8E
creatureDebugInfo dict FFFFFFFFB49E1D2D
block_channel_items bool FFFFFFFFC082C495
pcoro instance 00000000527F049A
_end_throw_t float 0000000007011A1A
control_locked bool FFFFFFFFB21A249E
bboardPot NoneType FFFFFFFFB84E64A2
_todo_useanim_lock_head bool FFFFFFFFB6EE14A4
armorColliderConroller ArmorCollider 000000006A40A371
invulnerable int 000000001CBEFCA9
_soak_enabled bool 00000000411EECAA
colorDelegates PyArrayDataInstance 000000007BEADBED
_dead_cam instance FFFFFFFF87170CAC
set_ch_StaminaRegeneration functools.partial 0000000034D80CB3
localBaseClanID long FFFFFFFFEDFD445A
_cam_anim_factor float 000000001E47FCB6
lookingaround bool FFFFFFFFC986BCB9
_getup_animation_played bool 0000000049AEF24E
_perks_actions_cache dict 000000005B6FF775
_ViewControl__last_time float FFFFFFFFC0CB84C0
_AvatarTrackers__saved_hands NoneType 00000000017AACC1
_temp_item_type_added list FFFFFFFFC82D04C2
showEntitiesMarks bool 00000000366B3CE5
savedPitch float FFFFFFFFE63BFCC7
_left_to_right_played bool 00000000139C8CCA
collide_blend instance 000000001A363CCB
_hidden_item_dress_types set 0000000047AAACCD
_lensfront_node NoneType FFFFFFFFBC8EBCD0
active_weapon ClWeapon FFFFFFFFC611FF78
userCommandLastUse float FFFFFFFFA7CF04D3
multiplier float 000000000481ECD7
EquippedVisibleAttachesIDS PyFixedDictDataInstance FFFFFFFFADA454D8
_moving_to_creature_loot bool FFFFFFFFB64DC4DA
isInWorld bool 000000005B2B6CDE
restrictions list FFFFFFFFFD4E9CE1
_anim_callback_id int 000000006F38ECE3
nodeInfoL HandTrackerNodeInfo 000000000555E4E5
coloriseEmblems PyArrayDataInstance 0000000015429CE8
_paramloopid int 000000007E7894EB
inventoryFilter int 000000001D27CCED
ch_CombatPointsRegeneration PyFixedDictDataInstance 000000006934D4EF
_client_restrictions dict FFFFFFFF83B81A28
nodeInfoR HandTrackerNodeInfo 000000000555E4FB
collider_boxes dict 0000000034A47CFC
_lock_gravity_by_attach_weapon bool FFFFFFFFD2F5762A
reload_from_bored bool 0000000051B05504
event_current_music NoneType FFFFFFFFC0F6D505
clanRoster dict 0000000063B07D07
famousStories PyArrayDataInstance FFFFFFFFE7566D0B
_last_seen_converted_counter PyArrayDataInstance FFFFFFFFF348BD0D
worldLoadStatusCode int 0000000056F76D0E
_rr_id int 00000000111C350F
inventoryPositionList list FFFFFFFFB7EF9510
lazy_trigger_markers list 000000004663B94F
megaLodInOutDistanceInited bool 000000004FED7D18
_is_sprinting_breathing bool FFFFFFFFEA263D1A
_slope_off_time float 000000000F53751D
NPCbarterHideUnaffordable bool FFFFFFFFF92F2D1F
_wt_neck_aim PyModelNode FFFFFFFF94D6CD22
locked_items dict FFFFFFFFE9938523
binoculing int 0000000030D41D28
_raise_flag_id int 000000004F6588DC
_visual_armor_cache NoneType FFFFFFFFBB3BF52B
_online_clan_members dict 000000002E22652D
set_ch_CombatPointsRegeneration functools.partial 000000003CF9A52E
_AvatarTrackers__start_sprint int 00000000521FB52F
_UserFirePlace__tidcr int 000000000A4EF912
_pygunRWnode instance FFFFFFFF8F3F4535
_inventory_pos_callback NoneType 000000000E12DD37
manipulatePot int 00000000045D5538
_moving_to_point bool FFFFFFFFF89E4D3C
itemcacheFilter int 0000000060B85540
PCTradeGold int 0000000020D5CD42
client_respawn_time int 0000000015A0EB8B
_leg_rotate_outside float FFFFFFFFA2EAAD46
fix_roll_left_hand bool FFFFFFFFCCF6ED47
_StoreHouse__cashe_consumables list FFFFFFFF99405549
_distance_counter NoneType 000000001DA4F54A
_subscribed_to_boat bool FFFFFFFF98CD254D
_PlayerAvatar__cr_near_gui instance FFFFFFFFC0383B8D
_equipped_armor_dirty bool 00000000089DAD50
items_to_drop list FFFFFFFFB2453D51
common_marks_loaded instancemethod 0000000029FF2CE3
movingForward bool FFFFFFFFA8119554
items_on_workbench list FFFFFFFFEB84811C
_max_weight float FFFFFFFFB624855D
_last_pivotMaxDist float 000000003DFEA55E
test_nodeInfo_gunrw GUNRWCentrMover FFFFFFFFA42A929A
pinger int FFFFFFFFE7CF6563
blackbox_holyday_config PyFixedDictDataInstance 000000006DAB2565
_pending_data dict 0000000069754D66
_restore_bellyweapon_delay float FFFFFFFFDAAA3D68
acLock _RLock 000000002DF95D6B
_wound_enabled bool 000000006371C56C
_cam_sprint_factor int 0000000023F3756D
_cr_chbreath NoneType 000000001476318C
shootRestrictions list 000000002682AD71
tracker_weaponback instance FFFFFFFFCF72C574
gesture_played_out bool 0000000039BE6D76
_tick_controller_id NoneType FFFFFFFF81EFD57A
belly_weapon NoneType FFFFFFFFDA3972FF
_crafting_callback NoneType 000000007F422583
_id_partially_index int FFFFFFFFB5ED0589
_Inventory__unload_ammo_magaz_id NoneType FFFFFFFF9C02F58E
_frame_index int FFFFFFFF8A26958F
waterListener int 000000000E1FAB98
tracker_weaponback2 instance 0000000072E7F593
_physics_ready bool 000000007A470594
converted_items_counters PyArrayDataInstance FFFFFFFFE7EBFD95
_velocity_hook NoneType 00000000230B9D96
_respawn_timer_id int FFFFFFFFDEF1FB64
_dc_return_t_left int 000000005DF93DFD
craftAutofill bool 000000002C87AD9D
_last_action_type str FFFFFFFFBE01F2DE
_seller_id int 000000001CCC30F0
_foot_twist_lock set 0000000043526F9B
savedTurningHalfLife float FFFFFFFFBF7B45A5
set_ch_Stamina functools.partial FFFFFFFFD48C2DA6
_ViewControl__head bool FFFFFFFFA15E4CF1
_UsingItemAnimation__tmp_time float 00000000119AA5A8
tracker_gun_mover Tracker 000000001C3925AC
_dialog_npc_action NoneType FFFFFFFFAEFC15AE
_ViewControl__send_head_init bool FFFFFFFFB6583F9D
_collide_detected bool FFFFFFFFFAEA95B1
effectsVisibleForAll PyArrayDataInstance 000000000E2B25B2
store_house_items_count int 000000001406C5BC
_hand_blend_prov_complete bool FFFFFFFFB5E1DDBD
_last_model_yaw NoneType 00000000594A85BE
damageTakenTexts list 0000000075B78BA0
_using_item_action_name str 000000006713EDC3
_isFPS bool 000000005F0795C6
_isBurn_smoke NoneType 00000000421895C7
_slope_eff_settings dict 00000000626F40F7
isMovingTest bool 0000000039C3BDCE
StoredItems PyArrayDataInstance FFFFFFFFFBECFDD0
_friends_offline CaseInsensitiveStringListSet 00000000461ACDD2
_last_hips_cache NoneType 000000004E241DD3
lastsource_data PyFixedDictDataInstance 0000000062C98DD5
trigger_markers list 0000000026CDD5D7
_last_wound_point NoneType FFFFFFFF949E9DD9
battleLogSwitchedOn bool 000000003CE8ADDB
_headLArovider HeadLArovider 000000004EDC3FA5
_PlayerAvatar__old_vec_dc_dir Math.Vector3 FFFFFFFFEE3545E0
ActiveItemPollutions PyArrayDataInstance FFFFFFFFB18FB5E2
craftSelectedReceipt int 0000000066AC7CFB
account_is_frod int 000000000F706651
_dung_timer_text NoneType 000000000B75ADE9
onThrStart instancemethod FFFFFFFF9BE33FA7
hp_barrel NoneType FFFFFFFF8C404A52
_active_spots set FFFFFFFFACCFADEE
ActiveItemID long 0000000013E98DF0
_PlayerAvatar__is_bursted bool FFFFFFFFA0E0AFA8
_AchUser__listeners list 0000000022FD0DF6
_detain_blender NoneType FFFFFFFF8FE105FC
RM_curr float 00000000583A45FD
_weapon_reloader NoneType FFFFFFFF99C4A604
clanName str FFFFFFFFD0F61E05
_need_torso_roll_right bool FFFFFFFFA8EC3606
onPhysCallTp instancemethod 000000004CF24607
acCurrentTask NoneType FFFFFFFFF4E0C6A9
_anim_action_out NoneType FFFFFFFFBFEF460C
_gunr_limit_node PyModelNode FFFFFFFFB46BA60E
_key_down_look_around NoneType 0000000041E65658
_FootPrinter__timer_reatt int 0000000023424E12
_async_load_counter int FFFFFFFFE6143616
tracker_gun Tracker FFFFFFFFDB8BFE18
_last_in_pot_notification NoneType 0000000058F96E1A
_burn_world_model NoneType FFFFFFFFFF706622
last_target_time int FFFFFFFF94905E24
_StoreHouse__cashe_avatar_consumables list 0000000067611E26
_wcolide_point Math.Vector3 000000004B51DE29
trade_callback NoneType 000000004226CE2A
_particles_burn NoneType 0000000020CA762B
EquipModes int 000000003556162E
ch_HitPointsRegeneration PyFixedDictDataInstance 0000000027DE662F
_target_items list FFFFFFFFEBEFFE30
frags int 000000000363863A
_UserFirePlace__tid int FFFFFFFFC347963F
_last_start_graw_id int 0000000037E2F641
PVPInfo PyFixedDictDataInstance FFFFFFFF94608645
_to_track_progress bool FFFFFFFFCED92E48
sfx_enabled bool 0000000042A49E50
_action_callback NoneType 000000006AFAF651
_fake_item_dress_types dict FFFFFFFFE99D1C12
_ViewControl__bolt_anim bool 000000007A4C0263
_t_apinc int FFFFFFFFE3E95E55
playerExchangeInProgress bool 000000000A125658
face_controller FaceController 000000001A000659
_ViewControl__send_head_timer int FFFFFFFFEE3EEE5B
wanted_ids PyArrayDataInstance 00000000323D9E5C
_Climb__delta_need_down int FFFFFFFF8841079B
savedPosition Math.Vector3 000000005427BA65
_AvatarTrackers__last_xtorso_data NoneType 000000003B9B586D
foots list FFFFFFFFF5CE6662
_disable_camera_aimtoweapon bool FFFFFFFFB84ADE63
clientAccuracy float 000000000D47CFBC
headProvider_cam_self DiffDirProvider 000000003C44466B
_after_jump_landing_state bool FFFFFFFF86A2766D
context_menu_slot NoneType FFFFFFFF92A9CE71
_callbackOnThrow NoneType 00000000024C8673
_FootPrinter__foot_cue_models dict 000000003A9C4E69
_Climb__down_all_time int 000000002C193679
_isGasMaskSoundBreathing bool FFFFFFFFF058E4C7
_anomaly_drag bool FFFFFFFFCE2CD682
_HandControl__isEquipProgress bool FFFFFFFFEDE4FE6B
_rightFreeHandProvider HandFreeProvider 000000007D9C3E8B
RM_max float 000000000E6CBFC2
dead int FFFFFFFFE14C468E
_cam_fps_node_pivot MatrixBlend FFFFFFFFD4FEA26D
_Avatar__looting_target_id int FFFFFFFFF01546DE
_need_return_incombat bool FFFFFFFFCA0B8693
_PlayerAvatar__trigger_timer int FFFFFFFF8FDE3E95
set_ch_MoveSpeed functools.partial FFFFFFFFB34A1E97
usingGesture int 0000000034B0CE99
_Climb__addphy_push_time float 0000000024AE269B
EquippedCond2 PyArrayDataInstance 000000005799D91A
_current_action NoneType 0000000000262EA0
camera_horiz float FFFFFFFFC69AA052
_velocity Math.Vector3 00000000297AA6A7
_UsingItemAnimation__dealyed_timer int FFFFFFFFEE34A91C
hoisting_flag NoneType FFFFFFFFEA7C86AD
reinfp_tracker PyFixedDictDataInstance 000000000486B6B3
_respawned_recently bool FFFFFFFFE5841EB6
_total_vertices_number int 000000002499DEB7
ActiveArtifactList PyArrayDataInstance FFFFFFFFC4845EBA
_Avatar__shot_played_left bool FFFFFFFFF7C59EBD
_hvat_actions dict 0000000077BCE6BF
_tuck_coroutine NoneType 00000000653646C0
radiometer Radiometer FFFFFFFFED5A36C2
EquippedVisibleAttaches PyFixedDictDataInstance 0000000049230EC3
_stuck bool 0000000012087EC7
isrun int 0000000022C02ECA
_near_npc dict 00000000550FD6CC
actionFunctions dict 000000001E7A8122
enable_pitch bool FFFFFFFF9155AECE
_HandControl__reload_weapon_osn_anmation bool FFFFFFFFC20E5ED2
grenadeArmed bool 00000000685B96D7
_PlayerAvatar__teleport_direction Math.Vector3 FFFFFFFF99B507CF
set_ch_Penetration functools.partial 000000001845B6DE
_relation_cache dict FFFFFFFFA1A966DF
right_hand_model_sound_node PyModel 0000000059D06EE0
_Avatar__SFXSeries_callbacks list FFFFFFFFEEE10EE1
exchange_timer_id int 0000000014B76126
EquippedArmor PyFixedDictDataInstance FFFFFFFF96E076E9
posteffects dict 000000003A086EEF
_center_ladder NoneType FFFFFFFFAB60C6F1
perks PyArrayDataInstance 0000000018B6FEF2
_subscribers dict FFFFFFFFDA7D4EF4
lazy_marks_data MarksData FFFFFFFFABCA76FB
_add_friend_timeout dict FFFFFFFFF9C63EFC
_PlayerMovement__t float 0000000032820EFD
disablePlayerTrade int FFFFFFFF9D91A3D5
_capture_counter NoneType 00000000550C4706
_active_create_box_id int 000000005FCDBFD7
head_look_cam bool 000000002F338F0D
_model_pistol_holster NoneType FFFFFFFFBAF0492D
_is_jump bool FFFFFFFFC454AF12
_time_press NoneType FFFFFFFF9730CF13
_slope_detect_by_angle bool 000000001472F714
_phy_blend_rot instance 000000007D8E3F18
_burn_tick_id int FFFFFFFF929F6F19
_anim_action_in NoneType 0000000063696F1A
isUseItemAnimationPlayed function 0000000077A6752F
_shot_number int FFFFFFFFB7E7371D
_stain_index int FFFFFFFFC1E0BF23
snipingScopeTypeCrosshair int FFFFFFFFB5408F25
_pygunnode instance FFFFFFFFCC6E5726
headProvider_entity EntityDirProvider FFFFFFFFB1F53F2A
_restore_bellyweapon_callback NoneType 000000004BC6472D
_using_item bool FFFFFFFF99B09F2E
_CandleUser__water_listener int 000000007A5C7F34
acResultChecker NoneType 0000000033FE8F37
_prev_matrix NoneType 000000007D73C738
is_burning int FFFFFFFFF6374F3A
_by_anim_weapon_to NoneType 00000000169F173B
playerExperience long FFFFFFFF823A6743
_PlayerAvatar__to_bored_delay float FFFFFFFFCFE2C748
last_grenade_damage int FFFFFFFFC193C74A
_prereqs_model_key list FFFFFFFFD43E4F4D
_auto_clear_callback_id int 00000000129E9751
_current_jmp NoneType 0000000001D1C752
fav_users list FFFFFFFFF039CFE3
_ramid int 000000003B3E3F54
sniping_callback_id int FFFFFFFF855FBF55
ch_MaxHitPoints PyFixedDictDataInstance 000000001E38B757
clanRosterUpdateCall NoneType 000000000676875A
<dummy key> ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл 000000001575975D
_vel_naklon int 0000000073AB57E5
acTasks list FFFFFFFFEA580761
_avatars_ids_set set 0000000008C82A91
_ViewControl__reload_anim bool FFFFFFFFAF10A38B
end_shot_sfx NoneType FFFFFFFFE38ED76E
_hips_offset_by_rotate float FFFFFFFFD0A2F265
_tmp_hl_model NoneType 000000004B598772
_sprint_key_pressed NoneType 000000004D88EF77
_by_anim_has_lock bool FFFFFFFFED99DF74
_cam_fps_offset MatrixBlend FFFFFFFFF3286F75
_trade_state int 00000000567D33E9
_teleport_positions_towait NoneType FFFFFFFFBEE3EF78
_player_press_crouch bool 000000005A666779
acResult NoneType 000000004A28DF7B
deaths int 0000000078BBDF87
_slope_all_particles NoneType 0000000079B5ABEC
data_loader DataLoader 0000000065AE2F8D
_dbd_id int 00000000419A4F8E
cellClanID long FFFFFFFFF0C7E3ED
_PlayerAvatar__cr_to_stay_coroutine NoneType FFFFFFFFDB5B2792
scopeMode int 0000000074A56794
waterListenerHead int FFFFFFFFD8A5EF96
candle int FFFFFFFFEE705699
shooting bool FFFFFFFF9647DF9B
visitedSpaces PyArrayDataInstance 000000006EBA829A
_jmp_fly_high bool FFFFFFFFC3AB47A4
_head_exist bool 0000000033AB0946
_save_dcurs tuple 000000000B49FFA7
_spayer_clouds list FFFFFFFFAC289FA8
_sort_flag bool FFFFFFFF946A9FAE
headProvider_special DiffDirProvider 000000004C89D69D
_client_respawn_t0 float 0000000063AE2948
_playing_animation_loot bool 0000000068D987B6
clone_model NoneType FFFFFFFF97F9D7BA
_pushing_with_tilt2 NoneType FFFFFFFFCF4DDFBB
ch_MaxStamina PyFixedDictDataInstance FFFFFFFF863BE7BC
save_dc_direction Math.Vector3 FFFFFFFFE8426D4A
_is_weapon_collide bool FFFFFFFF8B530CC7
_left_mouse_button bool FFFFFFFFCAFFBFF5
set_ch_DamageAbsorb functools.partial FFFFFFFF9900C7C2
default_action_name NoneType 000000005D9AF7C5
_near_pl_timer int 000000004E756FCC
_need_enable_look bool FFFFFFFF8F1FD7CE
_tracker_is_init bool FFFFFFFFB49DB54D
_craft_animation bool 000000001105A7D0
weaponTrapRange int FFFFFFFFA7F352A3
_Thrower__throw_ready bool 0000000003BB0FD7
_HandControl__itemType int 000000005FD67FDA
_Avatar__gun_anim_callback_id NoneType 00000000077E914F
savedYaw float 000000005820BBFA
_deb_last_key str 0000000076AA77DE
show_tracker int FFFFFFFFF90297E2
_kill_counter KillCounter FFFFFFFFADE08FE3
_playing_animation_loot_cam_pos NoneType 0000000043970FE5
xTorso TorsoX FFFFFFFFFEB0F7E7
_black_list CaseInsensitiveStringListSet FFFFFFFF8C8977FC
_torso_disbale_by_lookaround bool 0000000004839FEA
_slope_caps str FFFFFFFF837847EB
tracker_belly instance FFFFFFFFE05787F0
_eq_calb_id int 000000002B6E87F1
_AvatarTrackers__last_complexItemType int 0000000002FAC7F4
karma int 0000000021A9F7F5
deadCallback NoneType 000000004F7EB7F7
isBreathHolding bool 0000000069B41FF8
ch_HitPoints PyFixedDictDataInstance FFFFFFFF999E0FFA
enteredWorld bool 000000003BEA97FB
_hand_gravity_enabled bool 00000000106157FC
CarryingItems PyArrayDataInstance FFFFFFFFDCD42004
_prev_cheked_key tuple 00000000228AB805
uf_item NoneType 000000005DBAA806
AvatarCam CursorCamera 000000000917F009
ch_MaxCombatPoints PyFixedDictDataInstance FFFFFFFFE63B6811
KnowingRecipes PyArrayDataInstance 0000000004DD1012
_loop_anim_dwn_test_id int FFFFFFFFC6C96AAE
_need_torso_roll_value int 000000007FD716DF
inPVPinstance int 000000005DD8D01D
used_item_on_target int 000000003DE89020
_looped_action NoneType FFFFFFFF98F8F021
artefactExtractor NoneType 00000000130734D7
_uf_player_pos NoneType 0000000005E9FA7F
_t_lo_off int 000000002B78D828
last_shot_time NoneType FFFFFFFF827EE02B
_last_anomaly_drag float 000000007324C82C
clanID long 000000000509482D
_tucking_item NoneType 000000003A7F382F
isTogleCursor bool FFFFFFFFAC35B830
tracker_arm_right Tracker FFFFFFFFA01D7031
_AvatarTrackers__last_tracker_key tuple FFFFFFFFFE51B009
_uf_position NoneType 0000000079D26838
_belly_to_right_played bool FFFFFFFFA7AE1AB4
itemChangeTimer int 0000000036C3855F
_todo_useanim_lock_foot bool 0000000030DF46DE
_old_end_shot_sfx NoneType FFFFFFFFEFE9C042
_to_anim bool 00000000566DF844
_unl_magz_id int FFFFFFFF9F905430
marks_data MarksData FFFFFFFFCD3DA04B
_fade_inventory_filter_function NoneType FFFFFFFFD33C684F
_DialogActions__dialog_sound NoneType 000000005FED1852
NPCBarterItemList list FFFFFFFF93445855
previous_fallingvelocity float FFFFFFFFC17A0056
craftItemList list 0000000005F4585A
damageDoneTexts list FFFFFFFF81170EBA
_velocity_hook_value_to NoneType 00000000687104B9
_fake_color_delegates list FFFFFFFFA8FC8060
_StoreHouse__cashe_avatar_dbid int FFFFFFFF9E6E9862
GUNMover_nodeInfo GUNMover FFFFFFFFD6866811
crouching_or_crawling int FFFFFFFFBA31286B
_end_finish_dead_id NoneType FFFFFFFFB6B8C06C
lazy_minimap_controller MinimapController FFFFFFFFBEDCD012
_foot_settings_path str 000000001C41386E
_talk_entity NPC FFFFFFFFF263FEBD
last_space_name str 00000000491AE968
ninjaMode int FFFFFFFFA1F8D874
_last_wound_time float FFFFFFFFE310B875
_wait_real_stop_id int 0000000045E41078
quickSlotActiveLineNumber int 000000004903E07B
_play_sound_put_item_timer int 000000004CB44ADF
_trade_screen instance FFFFFFFFA20B907F
torso_roll_value int FFFFFFFF8CE4016B
footTriggers list 000000006ECE6087
_anim_to_played bool 0000000077F1F88D
_start_time_slope float 000000005F72208E
_camera_isWeapon int 00000000594FD095
_Climb__last_pos_tmp Math.Vector3 FFFFFFFFFFF56899
_AvatarTrackers__saved_yaw NoneType FFFFFFFFF942809C
set_ch_MaxStamina functools.partial 000000006887C0A1
_dung_timer_end int 000000004505F8A4
_last_grenade_type int FFFFFFFF8B0F98A5
antiSpeedGearCallback NoneType 000000006EAF80A8
_areas_counter AreaCounter FFFFFFFFF6C448AC
is_olive_fun_srd NoneType FFFFFFFF89EE3C7E
_HandControl__reload_weapon_progress bool FFFFFFFFC2B6981D
snipingScopeType int FFFFFFFF98D568B0
teamID int FFFFFFFF9D94C8B2
EnableTargettingCallback NoneType 0000000076E148B3
_stopped_action NoneType FFFFFFFFC51380BC
isBleending bool 0000000042A010BD
hp_barrel_node NoneType FFFFFFFFFD86F6CC
is_crafting bool FFFFFFFFDA1388CE
_hd_end_burn_smoke NoneType FFFFFFFFCF1060CF
_locked_action_items list 00000000426990D3
_last_token str FFFFFFFFA8C1BECE
_waitSnowTexture dict FFFFFFFFAED3C8D6
_DialogActions__dialog_camera NoneType 0000000024BE38D9
_playing_animation_device bool 0000000038CE18DC
_headlight Headlight FFFFFFFFA26DF8DD
_uf_err_code int FFFFFFFFCD0DC0DE
_timerFakeDamageID int FFFFFFFFBA1DA8DF
reload_from_sprint bool FFFFFFFF8CA368E3
_members_subscribed bool 00000000686560E4
movingLeft bool 000000001CBA88EB
movingBackward bool 000000005FFCA0EF
_is_lader_end_action_played bool 000000003F3780F0
_AvatarJump__down_duration_left float FFFFFFFF9F1E50F4
moveUpDamagesTimer int FFFFFFFFD98D10F7
CreditNumber int FFFFFFFF94CEF0FC
_ignorGravityAnimation bool FFFFFFFFA9E5F0FE
activeAnomaly int 0000000001980100
collider_nodes dict 0000000056A1D904
pvpFlag int FFFFFFFFB1C6390F
torso_nodeinfo TorsoTrackerNodeInfo 000000007EC6D912
_water_level NoneType FFFFFFFFAF983913
tutorial_phase int 000000006BDC9118
_e_hib_id int FFFFFFFFEDF4C119
transformationProperty PyArrayDataInstance 0000000073B5891A
_potted bool FFFFFFFFB4FCE11C
_danger_coroutine instance 00000000640FC120
shotlog collections.deque FFFFFFFF97DD0121
_async_load_callback int 0000000028E40922
gotten_barter_item_types collections.defaultdict FFFFFFFFADABC126
client_respawn_timer_value int 0000000061418ECA
controlLocks dict FFFFFFFF9C3E392D
_visual_callback NoneType FFFFFFFF89B3B12F
set_ch_MaxWeight functools.partial FFFFFFFFB77D2935
_jmp_up_position Math.Vector3 0000000047C5B936
EquippedGasMaskCond PyFixedDictDataInstance FFFFFFFFFC427189
_tick_ret_dcursor_id int 000000005CB4D939
last_model_list dict 000000001606E13A
hand_cotrol_wait_tmp bool FFFFFFFFA9C0313B
fniLeft FootNodeInfo 0000000073F7713D
_PlayerMovement__slope_material_id int 000000005E90C140
_sound_only_for_me NoneType FFFFFFFFADCCE944
_protect_counter NoneType 0000000065672945
visited_spaces PyArrayDataInstance 0000000069FF4146
_in_hand_model_right NoneType 00000000137E9947
_pot_controller NoneType FFFFFFFF894AA948
_playing_animation_item bool 0000000011155149
_DialogActions__rotate_step int 000000000FDCE14F
_cd_id int FFFFFFFFBA171950
__sfx_model__ PyModel FFFFFFFF9B940152
relationshipClanParam dict FFFFFFFFF86E011C
_knowledge_requesters dict 000000001F102C88
_jmp_down_played bool 000000006882595B
_spayer_tid int FFFFFFFFC905215C
old_cl tuple 000000005830595D
deathDrawn bool FFFFFFFFE266E968
_anim_action_loop NoneType FFFFFFFFCE02716B
_last_ladder_action bool 000000006F6E296C
_breathing_sound NoneType FFFFFFFFD6AD0173
tracker_torso Tracker 000000007EE82175
_on_step_sound_additional NoneType 000000001D397176
lazy_data_loader DataLoader 0000000041962EE9
_throw_need bool 00000000249A243F
canDamage int FFFFFFFFAA7EB97C
_sniping_key_pressed bool FFFFFFFFA42AA57A
_PlayerAvatar__antiPingCallback int FFFFFFFFF7AA217F
blockEscAfterInventoryClosed bool FFFFFFFFE5872180
clanEmblemID int FFFFFFFFC403A181
_HandControl__x2 float 0000000029C532EB
_world_load_time float FFFFFFFFAE315984
_stop_time_slope float FFFFFFFFD5E43985
weaponStatus int 0000000067F2E186
_FootPrinter__water_volume_enable bool FFFFFFFFF4B24988
_stopped_action_played NoneType FFFFFFFFAAFD4989
quickSlotBars PyArrayDataInstance FFFFFFFFF36CD98A
acResultEvent _Event 000000004A3F798C
_PlayerAvatar__played_damage_sound float 000000007DFD0042
_putting_item_off NoneType FFFFFFFFADE7C98F
_UsingItemAnimation__wait_models dict 000000002FE96190
lie_down_counter int FFFFFFFFB2148194
vert_ladder_info PyFixedDictDataInstance FFFFFFFFAF30E197
_soak_water_listener NoneType FFFFFFFFC842C998
set_ch_MaxCombatPoints functools.partial FFFFFFFFE28CE99E
_last_shot_time float FFFFFFFFBE78669D
possible_barter_count int 0000000002A739A1
_Climb__need_add_up float 000000004D33DD9B
ch_DamageAbsorb PyFixedDictDataInstance 000000006DB699A7
waterListenerKnee int FFFFFFFFFFD231AD
_need_torso_roll_left bool 0000000065DC1DA0
ToolTipRepairIDFunc NoneType 0000000025B759B4
spiderModelsDict dict FFFFFFFFD159B1B5
hideNameCallbacker NoneType FFFFFFFFE577D1BB
head_nodeInfo HeadNodeInfo 0000000040F611BC
firstPersonCamera int FFFFFFFFE28A51BD
fraction_relations_copy PyArrayDataInstance FFFFFFFFA189A1BF
colliderNames dict 00000000688319C1
ch_Defence PyFixedDictDataInstance FFFFFFFFC49299C2
_boxgroups NoneType FFFFFFFFFF9359C4
isTrade bool FFFFFFFF9A2B19C5
_talk_pot NoneType 000000005F74F9C8
_player_current_fov float FFFFFFFFFBF699C9
weapon_slots dict 000000003A01C9CA
movingRight bool FFFFFFFFC2A711CF
_danger_pp_id NoneType 000000006F840C4E
clanEnemies PyArrayDataInstance FFFFFFFFB48039D7
_cancel_action_func NoneType 00000000525211D8
use_gesture bool 00000000300801DE
tracker_head Tracker 000000007DB85371
_npc_id_talk int FFFFFFFFDF3E81E1
cheatCount int FFFFFFFFFD14B8F0
_is_walk bool 000000000AA5F6FD
ch_Accuracy PyFixedDictDataInstance FFFFFFFFC76B21F0
cacheMode NoneType 00000000031489F2
clanAlliances PyArrayDataInstance FFFFFFFFE04909F3
need_ladder_yaw NoneType FFFFFFFFE4B231F4
ExpCoefficient int 000000003E9FB9F6
_ViewControl__torso bool FFFFFFFF969C79F9
pvpFree int FFFFFFFFAF8CE1FB
updateInventoryTimer NoneType FFFFFFFF849019FC
ExchangeProperties PyFixedDictDataInstance 0000000004EE89FE
client_respawn_timer_type int 00000000763BE200
_raw_packet_gen NoneType FFFFFFFFCE1ADA06
_is_fix_action_sprint bool 000000000061820A
_Inventory__unload_ammo_last_time NoneType FFFFFFFFCEB5220B
flashLightID long 000000004E14020D
_rep_data dict 000000001B430A0E
_id_partially_upd int FFFFFFFFC5CDD212
color_alphas collections.defaultdict FFFFFFFFD8FBCA13
matrixAddPosTargetMatrix PyMatrix FFFFFFFF974D8E52
lookingaround_smooth bool 00000000404B4215
base_tracker PyFixedDictDataInstance FFFFFFFF847CD216
tracked_wanted NoneType FFFFFFFFFE34E21A
torsoProvider_entity EntityDirProvider FFFFFFFFA328221C
BellyItemID long FFFFFFFFE958EA1D
headProvider_serverLook PyMatrix 00000000004FBA1F
runEnabled bool FFFFFFFFCC1BA220
weaponProvider_entity EntityDirProvider FFFFFFFFBA53B706
ch_MoveSpeed PyFixedDictDataInstance 000000004BF53A28
_danger_pp NoneType 000000000FDD47BB
_equipped_modes_cache NoneType 0000000022AF722F
PCTradeItems list 0000000041E2F231
_PerkUser__callbacks list 00000000581E8234
_cam_sprint_value float FFFFFFFFD219D060
_new_turn instance 000000006AB22A42
_ViewControl__foot bool 000000000C0D3B0B
items_in_shop list FFFFFFFF81046A44
_dry_start_time NoneType FFFFFFFFBEAB9A4E
_dry_controller NoneType FFFFFFFFC3496252
set_ch_MaxHitPoints functools.partial FFFFFFFF97F4CA5A
_leftFreeHandProvider HandFreeProvider 0000000037A2D25B
_last_jump_conf NoneType FFFFFFFFDCC00A5C
_min_stain_index int FFFFFFFFD3134A5E
_cabcarsitdata dict 00000000458511BB
pongChecker NoneType FFFFFFFF8768EA64
name unicode 0000000000E56A65
_Gestures__current_gesture_actions NoneType 00000000306A2266
_outside_shell int 00000000190BBA69
_need_play_action_down_move bool FFFFFFFFE5BA3F7B
_last_killer_avatar_data dict 000000006BCAEA6C
_head_node PyModelNode FFFFFFFFD60A5F12
breath_holding_sound Sound 00000000389E726E
reloading int FFFFFFFFC1635A70
headProvider_cam_dcursor MatrixProvider 000000002DFDB272
magnitude float FFFFFFFFA8B1BA73
_putting_item_replace NoneType FFFFFFFF8A7BBA74
autogunModelVisible bool 00000000094E0A75
nedd_restore_run_after_crouch bool FFFFFFFF849D54CB
_PlayerAvatar__hp_timer_id int 0000000044442277
_velocitytickID int FFFFFFFF8CED8A79
cl_isMovingTest bool FFFFFFFFE7A2427D
_friends_online CaseInsensitiveStringListSet FFFFFFFFF7CBCA7F
eyes_controller instance 00000000381F9286
callbackUpdateEntitiesMarks NoneType 0000000003612288
moving_repeat bool 0000000000500289
RestrictionActionNames dict 000000001A5EF28A
_draw_pickup bool FFFFFFFFB5504A8C
_processed_vertices list 00000000140649C2
_prev_weapon_slots dict 000000001B972A8F
heli_weapon NoneType FFFFFFFFB47F1290
set_ch_HitPoints functools.partial 0000000023FAEA91
_danger_blend instance 000000004B762A93
ENABLE_MovingActionMather bool 000000003BB59A96
_Avatar__shot_played bool 0000000046E5F298
moving_locked bool FFFFFFFF813F2A9A
_foot_settings dict FFFFFFFF89206A9B
inputlock bool 00000000320AAAA0
finish_dead_entity_id NoneType 000000004AE802A1
_todo_useanim_lock_torso bool 00000000167F12A2
set_ch_CombatPoints functools.partial 00000000284BB2A3
_lock_bleed dict FFFFFFFFB203A2A4
lastdirection Math.Vector3 000000002FC4AAA6
ch_Stamina PyFixedDictDataInstance 000000006F3082A9
FakeActiveGadgetList PyArrayDataInstance FFFFFFFFDD521AAD
thirst float 00000000506A2AAE
_putting_item_on NoneType 0000000025589AB0
ch_StaminaRegeneration PyFixedDictDataInstance 000000006A1841C8
_quests_tracker QuestsTracker FFFFFFFFECE8A2B4
debugEnabled bool 000000005D99A2B8
_can_fade bool 000000002462F2B9
_ViewControl__send_head_prev tuple 000000003662E7FC
UserFromMasterPassword int FFFFFFFF8B230ABE
_fader_sound_ambient Fader 000000000876DAC0
camera_in_interior bool FFFFFFFFA40CB2C2
_last_maxSpeed float FFFFFFFFCD90CAC3
_is_weapon_collide_off_time float 0000000008D2DAC6
gunnodeInfo TrackerWeaponNodeInfo 0000000060BED2C9
last_target int FFFFFFFFD0131ACB
_fader_sound_weather Fader FFFFFFFFCBC9C2CC
_PlayerAvatar__bl_ret_dcursor instance FFFFFFFFD914C2CD
kickBackTimer NoneType FFFFFFFF9B92B2D3
_slope int FFFFFFFF9FECC2D6
_param_msg_id long 000000002D956ADD
GoldCreditNumber int 0000000065CDEADE
_weapon_to_attached str 0000000030BCF2DF
weapon_was_in_hands_type int FFFFFFFFD43C8F26
_is_lader_action_played bool 0000000074F24AE6
_in_hand_model_left NoneType 0000000039AB92E7
_head_matr_by_animation PyMatrix FFFFFFFFF08B4AE8
_controller_id int FFFFFFFF8DDD2AEB
_prev_move_vec Math.Vector3 000000003A9DDAED
_FootPrinter__cue_model_to_node dict 000000000BF4CAEE
_DialogActions__dialog_callback NoneType 00000000518BC2F3
right_weapon_prov HandToWeaponProvider FFFFFFFFE07BD2F4
_end_use_radio_anim bool 000000007FFA42F5
exchangePot NoneType 00000000691DF2F7
_looking_around_mult float FFFFFFFF805474C7
_burn_sound NoneType FFFFFFFF8A1282FF
_reload_coroutine NoneType FFFFFFFFBAE99B02
_checkInShellID int FFFFFFFFF9BBDB06
targetObjects dict FFFFFFFFDA182B08
TraderID int FFFFFFFFA9465B0B
msgFromShop list 0000000005F46FFC
_radio_stop_callback NoneType FFFFFFFFFCB30313
_cue_filter dict FFFFFFFFF8942316
ItemsWeight float 000000005A20BB17
_PlayerAvatar__cur_vec Math.Vector3 FFFFFFFF956A4B1C
waterListenerHips int FFFFFFFFD1C1A31E
context_menu_item dict FFFFFFFF84FE8320
_fence_id int FFFFFFFFF07CC323
friendsList list 0000000075BCBB24
_sprintsoundid int FFFFFFFFA9195325
canTakeDamage int FFFFFFFFFEC6B331
kickbackValue float 0000000068CC532B
active_weapon_model PyModel FFFFFFFFEE103B2C
_slope_sound_loopid int FFFFFFFF87B32B2D
_need_stop_actions bool FFFFFFFFA71F9C88
_is_sprinting_action bool 0000000059A4DB33
radio_working long 0000000078B37B38
_Climb__down_start_delay int 000000001A280B39
AgrFlag int 0000000037FAEB3B
_loaded_inventoryPos dict 0000000066263B41
_Inventory__unload_ammo_callback NoneType 0000000014488343
_particles_burn_smoke NoneType 00000000551AB34B
_colorise_emblems_cache NoneType FFFFFFFFC4667351
_is_jump_up_or_fly bool FFFFFFFFE00DB08E
h_crawl_left_hand_anim bool 000000007AADF1FE
_is_tired_after_sprint bool FFFFFFFFD4FD035C
_destroy_counters_controller_id NoneType FFFFFFFFC7313B5F
_ready_attemts int 000000003D56CB3B
transformationID int FFFFFFFFE58AE364
dataParentParamAvatar NoneType 000000003CB0136D
_DialogActions__last_npc_weapon NoneType 000000007EF2A36E
_under_water_sound NoneType 000000000EF9A371
listeners _Listeners 0000000012AB1B72
boost_id int FFFFFFFFDFA7D373
_weapon_settings dict 000000001DF79B7D
_Climb__need_add_fw float 000000004E55C895
left_weapon_prov HandToWeaponProvider 000000003904D380
_isBurn NoneType 000000006013FB87
angle_phy_cur int FFFFFFFFCFA9838B
_dialog_npc NoneType 0000000028DCB38C
test_tracker_gunrw Tracker 000000004BFC238D
_last_iswanted_data tuple FFFFFFFFCED7E391
_PlayerBuilder__buffer_blocks list FFFFFFFFBDDACB43
_HandControl__lock_progress_by_on_hand_weapon bool 000000001119A394
_tracker_locks dict 0000000056E3EB96
_AvatarTrackers__saved_action_queue NoneType 000000006F30AB98
_leg_rotate_inside float FFFFFFFF95B00B9E
_prev_ft_to dict 000000001C5C5BA0
cacheObjectID NoneType FFFFFFFFFF7253A1
ch_Penetration PyFixedDictDataInstance FFFFFFFFACFB33A5
_anomaly_counter NoneType FFFFFFFFCF8ADBAB
_last_weapon_model PyModel FFFFFFFFA34979F6
_achiv_ids set 00000000444363AD
camerainwater_listeners list FFFFFFFFCA7E83B0
prem_id int FFFFFFFFFAE4F1F3
ping_average float 0000000032214BB4
_AvatarTrackers__tired_end_timer_id int 000000004DD6D9F4
_send_blocks_timer int 00000000158DBBBA
effects_posteffects dict 00000000228B63BC
_Climb__curr_add_up int FFFFFFFFF1A673BF
weapon_was_in_hands_id long FFFFFFFFFD8BEB4B
RestrictionCallbacks dict FFFFFFFFDEFA81F6
ClientChannelServerWaiting dict 000000005D3D8BC6
_Climb__vec_add Math.Vector3 FFFFFFFFE18CC8A1
respawn_timer_type long 00000000253B23CB
_Builder__pull_data_blocks dict 000000007CA0E74D
_press_reload_time float FFFFFFFFF58DBD46
worldLoad int 000000003F6223D1
_stop_sprinting_auto_id int 0000000019BA93D3
tracker_arm_left Tracker FFFFFFFFDBCBFBD5
autogunModel NoneType FFFFFFFFBEE1E3DC
NPCBarterSelectedList int 0000000045DC0BDF
set_ch_Accuracy functools.partial 000000006C58ABE1
_last_mov_time float FFFFFFFF9DFF1BE2
_Avatar__brust_id int 0000000034EDC1FB
sprinting int FFFFFFFFD9AB2BE5
_trackers set 00000000390A43E9
targetMatrix MatrixProduct 0000000019055BEC
hungry float 00000000018B6BED
binocularMode int FFFFFFFFC18C0BEF
pvppkstat tuple 000000002BF32BF2
_lensback_node NoneType FFFFFFFFD0DEE3F3
_Avatar__gun_anim_callback_id2 NoneType 000000001B652C5A
myEmblems PyArrayDataInstance 00000000556FD9FE
_FootPrinter__last_surfaceHeight float FFFFFFFFCEAE8BF6
_start_jtime float 00000000522C7CA9
_Inventory__quest_cache_for_items list 0000000013DA23F8
minimap_controller MinimapController FFFFFFFFF762DBFA
transport_seat int FFFFFFFF8AFB2BFF
_fav_relations list 000000004C32B40A
effects_sfxes dict FFFFFFFFCD7D0F57
_HandControl__x float FFFFFFFFE542240C
ch_MaxWeight PyFixedDictDataInstance 000000000B2AA412
_HandControl__climb_command NoneType FFFFFFFF92D86EE9
radio RadioGadget 000000000C136414
ActiveWeaponSet2 PyFixedDictDataInstance FFFFFFFFB1C2B418
emblems_colors dict 00000000162D241A
_ViewControl__disable_particle bool FFFFFFFFF65A4C1E
no_weapon_in_hands bool 000000003D2CA41F
_npc_client_talk_entity NoneType FFFFFFFFD43D6424
to_use_item_ids list FFFFFFFFAD9C4427
set_ch_HitPointsRegeneration functools.partial FFFFFFFFE71FBC28
_sound_dealy_id int 000000000840E42D
_inAir int FFFFFFFFC7824430
set_ch_Defence functools.partial 000000007E64BC35
clientAccessLevel int 000000000BE41436
headProvider_to_target NoneType 0000000065F36C37
throwing_node PyModelNode 0000000033A18C3A
_fence_played bool 00000000248FFC3D
ActiveGadgetList PyArrayDataInstance 000000000BF0FC3E
personality PyFixedDictDataInstance 000000001EA5243F
personal_marks_loaded instancemethod 000000001C81A444
_Climb__addphy_coro NoneType FFFFFFFFB0F91449
need_stay_after_crouch bool 00000000143B5C4A
ch_CombatPoints PyFixedDictDataInstance 000000000D6DFC4E
SellMode int 000000005651FA0D
_usingItemSound NoneType FFFFFFFFEC0CB452
_UsingItemAnimation__current_action ActionQueuer FFFFFFFFAC319453
_hand_wepon_providers_recreted bool 000000001083220E
_end_stop_radio_anim bool 00000000090DF457
fniRight FootNodeInfo FFFFFFFFDE1C9459
_using_attach_model NoneType 000000006A2A145A
_party_status int 0000000029473C5B
angle_phy int 0000000068C2245C
lock_move_by_jump bool 000000003A6AE45D
clanRights long 0000000016D3945F
showNameCallbacker NoneType FFFFFFFFEDF04460
_dialog_hide_areas list 000000005EAFB463
_totally_hidden_slots set 000000006D1C7466
_Climb__curr_add_fw int FFFFFFFFF0E01611
_wt_neck PyModelNode FFFFFFFFC222246C
ReportChangedItemDict dict FFFFFFFFA63FAC6E
current_effects dict 000000003E57A46F
_listeners list 000000001F955C70
exchange_selected_item NoneType 000000002DC59213
h_crawl_anim_played bool FFFFFFFFDB7BD475
_prev_slope_material_id int FFFFFFFFF3A494BF
_trade_pot NoneType FFFFFFFFB78A647D
battleLogTargetEntity NoneType 00000000631FCADF
_send_head_ts float FFFFFFFFB9A4C47F
lastTargetedAvatar NoneType 0000000008193C81
_AvatarTrackers__last_data_trackers NoneType 0000000040BAAC83
PCTradeMoney int 0000000020FF3CC1
is_throwing bool 00000000255FF488
_foot_rotate_limit float FFFFFFFF9AA40489
lasttimekey float 000000007411E48B
_foot_nodes dict 000000003B7CFC8E
creatureDebugInfo dict FFFFFFFFB49E1D2D
block_channel_items bool FFFFFFFFC082C495
pcoro instance 00000000527F049A
_end_throw_t float 0000000007011A1A
control_locked bool FFFFFFFFB21A249E
bboardPot NoneType FFFFFFFFB84E64A2
_todo_useanim_lock_head bool FFFFFFFFB6EE14A4
armorColliderConroller ArmorCollider 000000006A40A371
invulnerable int 000000001CBEFCA9
_soak_enabled bool 00000000411EECAA
colorDelegates PyArrayDataInstance 000000007BEADBED
_dead_cam instance FFFFFFFF87170CAC
set_ch_StaminaRegeneration functools.partial 0000000034D80CB3
localBaseClanID long FFFFFFFFEDFD445A
_cam_anim_factor float 000000001E47FCB6
lookingaround bool FFFFFFFFC986BCB9
_getup_animation_played bool 0000000049AEF24E
_perks_actions_cache dict 000000005B6FF775
_ViewControl__last_time float FFFFFFFFC0CB84C0
_AvatarTrackers__saved_hands NoneType 00000000017AACC1
_temp_item_type_added list FFFFFFFFC82D04C2
showEntitiesMarks bool 00000000366B3CE5
savedPitch float FFFFFFFFE63BFCC7
_left_to_right_played bool 00000000139C8CCA
collide_blend instance 000000001A363CCB
_hidden_item_dress_types set 0000000047AAACCD
_lensfront_node NoneType FFFFFFFFBC8EBCD0
active_weapon ClWeapon FFFFFFFFC611FF78
userCommandLastUse float FFFFFFFFA7CF04D3
multiplier float 000000000481ECD7
EquippedVisibleAttachesIDS PyFixedDictDataInstance FFFFFFFFADA454D8
_moving_to_creature_loot bool FFFFFFFFB64DC4DA
isInWorld bool 000000005B2B6CDE
restrictions list FFFFFFFFFD4E9CE1
_anim_callback_id int 000000006F38ECE3
nodeInfoL HandTrackerNodeInfo 000000000555E4E5
coloriseEmblems PyArrayDataInstance 0000000015429CE8
_paramloopid int 000000007E7894EB
inventoryFilter int 000000001D27CCED
ch_CombatPointsRegeneration PyFixedDictDataInstance 000000006934D4EF
_client_restrictions dict FFFFFFFF83B81A28
nodeInfoR HandTrackerNodeInfo 000000000555E4FB
collider_boxes dict 0000000034A47CFC
_lock_gravity_by_attach_weapon bool FFFFFFFFD2F5762A
reload_from_bored bool 0000000051B05504
event_current_music NoneType FFFFFFFFC0F6D505
clanRoster dict 0000000063B07D07
famousStories PyArrayDataInstance FFFFFFFFE7566D0B
_last_seen_converted_counter PyArrayDataInstance FFFFFFFFF348BD0D
worldLoadStatusCode int 0000000056F76D0E
_rr_id int 00000000111C350F
inventoryPositionList list FFFFFFFFB7EF9510
lazy_trigger_markers list 000000004663B94F
megaLodInOutDistanceInited bool 000000004FED7D18
_is_sprinting_breathing bool FFFFFFFFEA263D1A
_slope_off_time float 000000000F53751D
NPCbarterHideUnaffordable bool FFFFFFFFF92F2D1F
_wt_neck_aim PyModelNode FFFFFFFF94D6CD22
locked_items dict FFFFFFFFE9938523
binoculing int 0000000030D41D28
_raise_flag_id int 000000004F6588DC
_visual_armor_cache NoneType FFFFFFFFBB3BF52B
_online_clan_members dict 000000002E22652D
set_ch_CombatPointsRegeneration functools.partial 000000003CF9A52E
_AvatarTrackers__start_sprint int 00000000521FB52F
_UserFirePlace__tidcr int 000000000A4EF912
_pygunRWnode instance FFFFFFFF8F3F4535
_inventory_pos_callback NoneType 000000000E12DD37
manipulatePot int 00000000045D5538
_moving_to_point bool FFFFFFFFF89E4D3C
itemcacheFilter int 0000000060B85540
PCTradeGold int 0000000020D5CD42
client_respawn_time int 0000000015A0EB8B
_leg_rotate_outside float FFFFFFFFA2EAAD46
fix_roll_left_hand bool FFFFFFFFCCF6ED47
_StoreHouse__cashe_consumables list FFFFFFFF99405549
_distance_counter NoneType 000000001DA4F54A
_subscribed_to_boat bool FFFFFFFF98CD254D
_PlayerAvatar__cr_near_gui instance FFFFFFFFC0383B8D
_equipped_armor_dirty bool 00000000089DAD50
items_to_drop list FFFFFFFFB2453D51
common_marks_loaded instancemethod 0000000029FF2CE3
movingForward bool FFFFFFFFA8119554
items_on_workbench list FFFFFFFFEB84811C
_max_weight float FFFFFFFFB624855D
_last_pivotMaxDist float 000000003DFEA55E
test_nodeInfo_gunrw GUNRWCentrMover FFFFFFFFA42A929A
pinger int FFFFFFFFE7CF6563
blackbox_holyday_config PyFixedDictDataInstance 000000006DAB2565
_pending_data dict 0000000069754D66
_restore_bellyweapon_delay float FFFFFFFFDAAA3D68
acLock _RLock 000000002DF95D6B
_wound_enabled bool 000000006371C56C
_cam_sprint_factor int 0000000023F3756D
_cr_chbreath NoneType 000000001476318C
shootRestrictions list 000000002682AD71
tracker_weaponback instance FFFFFFFFCF72C574
gesture_played_out bool 0000000039BE6D76
_tick_controller_id NoneType FFFFFFFF81EFD57A
belly_weapon NoneType FFFFFFFFDA3972FF
_crafting_callback NoneType 000000007F422583
_id_partially_index int FFFFFFFFB5ED0589
_Inventory__unload_ammo_magaz_id NoneType FFFFFFFF9C02F58E
_frame_index int FFFFFFFF8A26958F
waterListener int 000000000E1FAB98
tracker_weaponback2 instance 0000000072E7F593
_physics_ready bool 000000007A470594
converted_items_counters PyArrayDataInstance FFFFFFFFE7EBFD95
_velocity_hook NoneType 00000000230B9D96
_respawn_timer_id int FFFFFFFFDEF1FB64
_dc_return_t_left int 000000005DF93DFD
craftAutofill bool 000000002C87AD9D
_last_action_type str FFFFFFFFBE01F2DE
_seller_id int 000000001CCC30F0
_foot_twist_lock set 0000000043526F9B
savedTurningHalfLife float FFFFFFFFBF7B45A5
set_ch_Stamina functools.partial FFFFFFFFD48C2DA6
_ViewControl__head bool FFFFFFFFA15E4CF1
_UsingItemAnimation__tmp_time float 00000000119AA5A8
tracker_gun_mover Tracker 000000001C3925AC
_dialog_npc_action NoneType FFFFFFFFAEFC15AE
_ViewControl__send_head_init bool FFFFFFFFB6583F9D
_collide_detected bool FFFFFFFFFAEA95B1
effectsVisibleForAll PyArrayDataInstance 000000000E2B25B2
store_house_items_count int 000000001406C5BC
_hand_blend_prov_complete bool FFFFFFFFB5E1DDBD
_last_model_yaw NoneType 00000000594A85BE
damageTakenTexts list 0000000075B78BA0
_using_item_action_name str 000000006713EDC3
_isFPS bool 000000005F0795C6
_isBurn_smoke NoneType 00000000421895C7
_slope_eff_settings dict 00000000626F40F7
isMovingTest bool 0000000039C3BDCE
StoredItems PyArrayDataInstance FFFFFFFFFBECFDD0
_friends_offline CaseInsensitiveStringListSet 00000000461ACDD2
_last_hips_cache NoneType 000000004E241DD3
lastsource_data PyFixedDictDataInstance 0000000062C98DD5
trigger_markers list 0000000026CDD5D7
_last_wound_point NoneType FFFFFFFF949E9DD9
battleLogSwitchedOn bool 000000003CE8ADDB
_headLArovider HeadLArovider 000000004EDC3FA5
_PlayerAvatar__old_vec_dc_dir Math.Vector3 FFFFFFFFEE3545E0
ActiveItemPollutions PyArrayDataInstance FFFFFFFFB18FB5E2
craftSelectedReceipt int 0000000066AC7CFB
account_is_frod int 000000000F706651
_dung_timer_text NoneType 000000000B75ADE9
onThrStart instancemethod FFFFFFFF9BE33FA7
hp_barrel NoneType FFFFFFFF8C404A52
_active_spots set FFFFFFFFACCFADEE
ActiveItemID long 0000000013E98DF0
_PlayerAvatar__is_bursted bool FFFFFFFFA0E0AFA8
_AchUser__listeners list 0000000022FD0DF6
_detain_blender NoneType FFFFFFFF8FE105FC
RM_curr float 00000000583A45FD
_weapon_reloader NoneType FFFFFFFF99C4A604
clanName str FFFFFFFFD0F61E05
_need_torso_roll_right bool FFFFFFFFA8EC3606
onPhysCallTp instancemethod 000000004CF24607
acCurrentTask NoneType FFFFFFFFF4E0C6A9
_anim_action_out NoneType FFFFFFFFBFEF460C
_gunr_limit_node PyModelNode FFFFFFFFB46BA60E
_key_down_look_around NoneType 0000000041E65658
_FootPrinter__timer_reatt int 0000000023424E12
_async_load_counter int FFFFFFFFE6143616
tracker_gun Tracker FFFFFFFFDB8BFE18
_last_in_pot_notification NoneType 0000000058F96E1A
_burn_world_model NoneType FFFFFFFFFF706622
last_target_time int FFFFFFFF94905E24
_StoreHouse__cashe_avatar_consumables list 0000000067611E26
_wcolide_point Math.Vector3 000000004B51DE29
trade_callback NoneType 000000004226CE2A
_particles_burn NoneType 0000000020CA762B
EquipModes int 000000003556162E
ch_HitPointsRegeneration PyFixedDictDataInstance 0000000027DE662F
_target_items list FFFFFFFFEBEFFE30
frags int 000000000363863A
_UserFirePlace__tid int FFFFFFFFC347963F
_last_start_graw_id int 0000000037E2F641
PVPInfo PyFixedDictDataInstance FFFFFFFF94608645
_to_track_progress bool FFFFFFFFCED92E48
sfx_enabled bool 0000000042A49E50
_action_callback NoneType 000000006AFAF651
_fake_item_dress_types dict FFFFFFFFE99D1C12
_ViewControl__bolt_anim bool 000000007A4C0263
_t_apinc int FFFFFFFFE3E95E55
playerExchangeInProgress bool 000000000A125658
face_controller FaceController 000000001A000659
_ViewControl__send_head_timer int FFFFFFFFEE3EEE5B
wanted_ids PyArrayDataInstance 00000000323D9E5C
_Climb__delta_need_down int FFFFFFFF8841079B
savedPosition Math.Vector3 000000005427BA65
_AvatarTrackers__last_xtorso_data NoneType 000000003B9B586D
foots list FFFFFFFFF5CE6662
_disable_camera_aimtoweapon bool FFFFFFFFB84ADE63
clientAccuracy float 000000000D47CFBC
headProvider_cam_self DiffDirProvider 000000003C44466B
_after_jump_landing_state bool FFFFFFFF86A2766D
context_menu_slot NoneType FFFFFFFF92A9CE71
_callbackOnThrow NoneType 00000000024C8673
_FootPrinter__foot_cue_models dict 000000003A9C4E69
_Climb__down_all_time int 000000002C193679
_isGasMaskSoundBreathing bool FFFFFFFFF058E4C7
_anomaly_drag bool FFFFFFFFCE2CD682
_HandControl__isEquipProgress bool FFFFFFFFEDE4FE6B
_rightFreeHandProvider HandFreeProvider 000000007D9C3E8B
RM_max float 000000000E6CBFC2
dead int FFFFFFFFE14C468E
_cam_fps_node_pivot MatrixBlend FFFFFFFFD4FEA26D
_Avatar__looting_target_id int FFFFFFFFF01546DE
_need_return_incombat bool FFFFFFFFCA0B8693
_PlayerAvatar__trigger_timer int FFFFFFFF8FDE3E95
set_ch_MoveSpeed functools.partial FFFFFFFFB34A1E97
usingGesture int 0000000034B0CE99
_Climb__addphy_push_time float 0000000024AE269B
EquippedCond2 PyArrayDataInstance 000000005799D91A
_current_action NoneType 0000000000262EA0
camera_horiz float FFFFFFFFC69AA052
_velocity Math.Vector3 00000000297AA6A7
_UsingItemAnimation__dealyed_timer int FFFFFFFFEE34A91C
hoisting_flag NoneType FFFFFFFFEA7C86AD
reinfp_tracker PyFixedDictDataInstance 000000000486B6B3
_respawned_recently bool FFFFFFFFE5841EB6
_total_vertices_number int 000000002499DEB7
ActiveArtifactList PyArrayDataInstance FFFFFFFFC4845EBA
_Avatar__shot_played_left bool FFFFFFFFF7C59EBD
_hvat_actions dict 0000000077BCE6BF
_tuck_coroutine NoneType 00000000653646C0
radiometer Radiometer FFFFFFFFED5A36C2
EquippedVisibleAttaches PyFixedDictDataInstance 0000000049230EC3
_stuck bool 0000000012087EC7
isrun int 0000000022C02ECA
_near_npc dict 00000000550FD6CC
actionFunctions dict 000000001E7A8122
enable_pitch bool FFFFFFFF9155AECE
_HandControl__reload_weapon_osn_anmation bool FFFFFFFFC20E5ED2
grenadeArmed bool 00000000685B96D7
_PlayerAvatar__teleport_direction Math.Vector3 FFFFFFFF99B507CF
set_ch_Penetration functools.partial 000000001845B6DE
_relation_cache dict FFFFFFFFA1A966DF
right_hand_model_sound_node PyModel 0000000059D06EE0
_Avatar__SFXSeries_callbacks list FFFFFFFFEEE10EE1
exchange_timer_id int 0000000014B76126
EquippedArmor PyFixedDictDataInstance FFFFFFFF96E076E9
posteffects dict 000000003A086EEF
_center_ladder NoneType FFFFFFFFAB60C6F1
perks PyArrayDataInstance 0000000018B6FEF2
_subscribers dict FFFFFFFFDA7D4EF4
lazy_marks_data MarksData FFFFFFFFABCA76FB
_add_friend_timeout dict FFFFFFFFF9C63EFC
_PlayerMovement__t float 0000000032820EFD
disablePlayerTrade int FFFFFFFF9D91A3D5
_capture_counter NoneType 00000000550C4706
_active_create_box_id int 000000005FCDBFD7
head_look_cam bool 000000002F338F0D
_model_pistol_holster NoneType FFFFFFFFBAF0492D
_is_jump bool FFFFFFFFC454AF12
_time_press NoneType FFFFFFFF9730CF13
_slope_detect_by_angle bool 000000001472F714
_phy_blend_rot instance 000000007D8E3F18
_burn_tick_id int FFFFFFFF929F6F19
_anim_action_in NoneType 0000000063696F1A
isUseItemAnimationPlayed function 0000000077A6752F
_shot_number int FFFFFFFFB7E7371D
_stain_index int FFFFFFFFC1E0BF23
snipingScopeTypeCrosshair int FFFFFFFFB5408F25
_pygunnode instance FFFFFFFFCC6E5726
headProvider_entity EntityDirProvider FFFFFFFFB1F53F2A
_restore_bellyweapon_callback NoneType 000000004BC6472D
_using_item bool FFFFFFFF99B09F2E
_CandleUser__water_listener int 000000007A5C7F34
acResultChecker NoneType 0000000033FE8F37
_prev_matrix NoneType 000000007D73C738
is_burning int FFFFFFFFF6374F3A
_by_anim_weapon_to NoneType 00000000169F173B
playerExperience long FFFFFFFF823A6743
_PlayerAvatar__to_bored_delay float FFFFFFFFCFE2C748
last_grenade_damage int FFFFFFFFC193C74A
_prereqs_model_key list FFFFFFFFD43E4F4D
_auto_clear_callback_id int 00000000129E9751
_current_jmp NoneType 0000000001D1C752
fav_users list FFFFFFFFF039CFE3
_ramid int 000000003B3E3F54
sniping_callback_id int FFFFFFFF855FBF55
ch_MaxHitPoints PyFixedDictDataInstance 000000001E38B757
clanRosterUpdateCall NoneType 000000000676875A
<dummy key> ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл 000000001575975D
_vel_naklon int 0000000073AB57E5
acTasks list FFFFFFFFEA580761
_avatars_ids_set set 0000000008C82A91
_ViewControl__reload_anim bool FFFFFFFFAF10A38B
end_shot_sfx NoneType FFFFFFFFE38ED76E
_hips_offset_by_rotate float FFFFFFFFD0A2F265
_tmp_hl_model NoneType 000000004B598772
_sprint_key_pressed NoneType 000000004D88EF77
_by_anim_has_lock bool FFFFFFFFED99DF74
_cam_fps_offset MatrixBlend FFFFFFFFF3286F75
_trade_state int 00000000567D33E9
_teleport_positions_towait NoneType FFFFFFFFBEE3EF78
_player_press_crouch bool 000000005A666779
acResult NoneType 000000004A28DF7B
deaths int 0000000078BBDF87
_slope_all_particles NoneType 0000000079B5ABEC
data_loader DataLoader 0000000065AE2F8D
_dbd_id int 00000000419A4F8E
cellClanID long FFFFFFFFF0C7E3ED
_PlayerAvatar__cr_to_stay_coroutine NoneType FFFFFFFFDB5B2792
scopeMode int 0000000074A56794
waterListenerHead int FFFFFFFFD8A5EF96
candle int FFFFFFFFEE705699
shooting bool FFFFFFFF9647DF9B
visitedSpaces PyArrayDataInstance 000000006EBA829A
_jmp_fly_high bool FFFFFFFFC3AB47A4
_head_exist bool 0000000033AB0946
_save_dcurs NoneType 000000000B49FFA7
_spayer_clouds list FFFFFFFFAC289FA8
_sort_flag bool FFFFFFFF946A9FAE
headProvider_special DiffDirProvider 000000004C89D69D
_client_respawn_t0 float 0000000063AE2948
_playing_animation_loot bool 0000000068D987B6
clone_model NoneType FFFFFFFF97F9D7BA
_pushing_with_tilt2 NoneType FFFFFFFFCF4DDFBB
ch_MaxStamina PyFixedDictDataInstance FFFFFFFF863BE7BC
save_dc_direction Math.Vector3 FFFFFFFFE8426D4A
_is_weapon_collide bool FFFFFFFF8B530CC7
_left_mouse_button bool FFFFFFFFCAFFBFF5
set_ch_DamageAbsorb functools.partial FFFFFFFF9900C7C2
default_action_name NoneType 000000005D9AF7C5
_near_pl_timer int 000000004E756FCC
_need_enable_look bool FFFFFFFF8F1FD7CE
_tracker_is_init bool FFFFFFFFB49DB54D
_craft_animation bool 000000001105A7D0
weaponTrapRange int FFFFFFFFA7F352A3
_Thrower__throw_ready bool 0000000003BB0FD7
_HandControl__itemType int 000000005FD67FDA
_Avatar__gun_anim_callback_id NoneType 00000000077E914F
savedYaw float 000000005820BBFA
_deb_last_key str 0000000076AA77DE
show_tracker int FFFFFFFFF90297E2
_kill_counter KillCounter FFFFFFFFADE08FE3
_playing_animation_loot_cam_pos NoneType 0000000043970FE5
xTorso TorsoX FFFFFFFFFEB0F7E7
_black_list CaseInsensitiveStringListSet FFFFFFFF8C8977FC
_torso_disbale_by_lookaround bool 0000000004839FEA
_slope_caps str FFFFFFFF837847EB
tracker_belly instance FFFFFFFFE05787F0
_eq_calb_id int 000000002B6E87F1
_AvatarTrackers__last_complexItemType int 0000000002FAC7F4
karma int 0000000021A9F7F5
deadCallback NoneType 000000004F7EB7F7
isBreathHolding bool 0000000069B41FF8
ch_HitPoints PyFixedDictDataInstance FFFFFFFF999E0FFA
enteredWorld bool 000000003BEA97FB
_hand_gravity_enabled bool 00000000106157FC*/


struct Creature : public Entity
{
	Py_dicthead;
	Py_AttributeHASH(Creature, PyUnicodeObject*, name);
	Py_AttributeHASH(Creature, PyINT8Object*, dead);
	Py_AttributeHASH(Creature, PyINT32Object*, looted); 
	Py_AttributeHASH(Creature, PyINT32Object*, isDecomposed);
	//level
	DumpAttribute(Creature);


	std::string GetName()
	{
		auto n = name();
		if (!n)
			return std::string();
		auto utf = n->to_string();
		return utf;
	}
	bool is_dead()
	{
		auto isdeadproperty = this->dead();
		return isdeadproperty->get();
	}
	int is_looted()
	{
		auto isdeadproperty = this->looted();
		return isdeadproperty->get();
	}
	int type_m()
	{
		auto isdeadproperty = this->isDecomposed();
		return isdeadproperty->get();
	}


};
/*
_model_root NoneType 00007FF6DC943040
CarryingItems PyArrayDataInstance 00000000840EABC8
left_looting_koef float 0000000085C7F490
actions dict 00000000BD51AB98
water_listener_id NoneType 00007FF6DC943040
color_alphas collections.defaultdict 00000000BD519E18
LOCK_PUT_ITEM bool 00007FF6DC9410B8
_async_load_counter int 0000000006912B80
_burn_tick_id int 0000000006912B80
current_trackable NoneType 00007FF6DC943040
_burn_world_model NoneType 00007FF6DC943040
_stain_index int 0000000006912B80
tint_id int 0000000006912B80
_particles_burn NoneType 00007FF6DC943040
_pot_playerpos int 0000000006912B80
state int 0000000006912AC0
uniq_id str 00000000039D5030
canTakeDamage int 0000000006912B68
isDecomposed int 0000000006912B80
is_busy int 0000000006912B80
is_burning int 0000000006912B80
creatureType int 0000000006912A78
collider_nodes dict 00000000A9D57DA8
last_grenade_damage int 0000000006912B80
_particles_burn_smoke NoneType 00007FF6DC943040
_Skills__throwed_entities dict 00000000AF49A8F8
effects_sfxes dict 00000000BD51BA38
_min_stain_index int 0000000006912B80
armorColliderConroller ArmorCollider 00000000BADCF780
butcher_id int 0000000006912B80
name unicode 0000000023687750
level int 0000000006912B50
_idle_soundpot int 0000000085C7FB80
_wound_enabled bool 00007FF6DC940F18
current_effects dict 00000000BD51C578
ignore_tracking bool 00007FF6DC940F18
_last_wound_time float 0000000085C8A0E0
attack_active_target_id int 0000000006912B80
soundsPersist dict 00000000BD51A4D8
_CreatureFootsteps__fall_sound_path str 0000000023745B20
_apply_caps_id int 0000000006912B80
state_transition_callback NoneType 00007FF6DC943040
_current_skill_id NoneType 00007FF6DC943040
_isBurn NoneType 00007FF6DC943040
dead int 0000000006912B80
_Skills__wait_for_throwed dict 00000000AD2ADAA8
_debugsound_attach NoneType 00007FF6DC943040
_lock_bleed dict 00000000BD519CF8
override_tracker dict 00000000BD51DBF8
invulnerable int 0000000006912B80
_stipple bool 00007FF6DC9410B8
effectsVisibleForAll PyArrayDataInstance 00000000840EBBE8
_total_vertices_number int 0000000006912B80
effects_posteffects dict 00000000BD519BD8
isBleending bool 00007FF6DC940F18
_stipple_in_id int 0000000085CB2D60
colliderNames dict 00000000A9D5BCA8
_debug_sound_list list 00000000AB210C88
left_butch_koef float 00000000BEE2A1E8
_isBurn_smoke NoneType 00007FF6DC943040
_async_load_callback int 0000000006912B80
_hd_end_burn_smoke NoneType 00007FF6DC943040
creatureSubType str 0000000026D75300
_last_hips_cache NoneType 00007FF6DC943040
_last_wound_point NoneType 00007FF6DC943040
_auto_clear_callback_id int 0000000085CB67F8
_debugsound_textnode NoneType 00007FF6DC943040
current_state int 0000000006912AC0
_active_spots set 00000000AF4E8048
posteffects dict 00000000BD519758
_end_live bool 00007FF6DC940F18
_CreatureFootsteps__sound_path str 0000000023747630
soundsPersistNames set 00000000BEAC6C88
_idleSoundInside bool 00007FF6DC940F18
_burn_sound NoneType 00007FF6DC943040
collider_boxes dict 00000000A9D5BEE8
is_event int 0000000006912B80
looted int 0000000006912B80
_model_root NoneType 00007FF6DC943040
*/


struct Anomaly : public Entity
{
	Py_dicthead;
	Py_AttributeHASH(Anomaly, PyINT32Object*, item_spawn_data);
	Py_AttributeHASH(Anomaly, PyINT32Object*, potMainID);
	Py_AttributeHASH(Anomaly, PyINT32Object*, anomalyType);
	Py_AttributeHASH(Anomaly, PyINT32Object*, state);
	DumpAttribute(Anomaly);

	int GetArtefact()
	{
		auto prop = this->item_spawn_data();
		return prop->get();
	}
	//id ЮМНЛЮКХИ ДКЪ CheckedAnomaly
	int id_anomaly()
	{
		auto prop = this->potMainID();
		return prop->get();
	}
	int GetAnomalyType()
	{
		auto prop = this->anomalyType();
		return prop->get();
	}
	int GetState()
	{
		auto prop = this->state();
		return prop->get();
	}
};

/*
sfx_main_callback int 0000000085C81E30
sfx_main instance 000000009C27C388
TICK_INTERVAL float 000000002433C568
radius_max_effect int 0000000006912B80
radius int 0000000006912B80
sfx_inside instance 0000000084E45F48
current_sfx_state str 0000000024C0FC00
actived_pot_id NoneType 00007FF6DC943040
state int 0000000006912B68
item_model NoneType 00007FF6DC943040
anomalyType int 0000000006912970
player_in_area bool 00007FF6DC940F18
item_emul NoneType 00007FF6DC943040
_quest_state int 0000000006912B08
store_sounds dict 00000000B3CBEA38
player_in_trap bool 00007FF6DC940F18
item_availability list 0000000084E4A4C8
last_enter_time int 0000000006912B80
potMainID int 0000000085CB05A0
item_spawn_data int 0000000006912B80
_fader_anomaly_sound Fader 00000000AEC5DCF8
figure_type int 0000000006912B38
loaded_resources PyResourceRefs 00000000B0E32910
_sound_anomaly_roof_modif int 0000000006912B80
mult int 0000000006912B80
config_name str 00000000039D5030
_initial_position Math.Vector3 00000000AF64FD68
_pot_id NoneType 00007FF6DC943040
_player_main_inside bool 00007FF6DC940F18
controller_id NoneType 00007FF6DC943040
model_path str 000000002D6A54A8
potWallArt NoneType 00007FF6DC943040
potID NoneType 00007FF6DC943040
postproc_ids dict 00000000AF622E18
player_position NoneType 00007FF6DC943040
sfx_main_callback int 0000000085CB5700
sfx_main instance 00000000AB23C188
TICK_INTERVAL float 000000002433C568
radius_max_effect int 0000000006912B80
radius int 0000000006912B80
sfx_inside instance 00000000AB23C308
current_sfx_state str 0000000024C0FC00
actived_pot_id NoneType 00007FF6DC943040
state int 0000000006912B68
item_model NoneType 00007FF6DC943040
anomalyType int 0000000006912970
player_in_area bool 00007FF6DC940F18
item_emul NoneType 00007FF6DC943040
_quest_state int 0000000006912B08
store_sounds dict 00000000AB1966E8
player_in_trap bool 00007FF6DC940F18
item_availability list 00000000AB2306C8
last_enter_time int 0000000006912B80
potMainID int 00000000269B3930
item_spawn_data int 0000000006912B80
_fader_anomaly_sound Fader 00000000AB22F6D8
figure_type int 0000000006912B38
loaded_resources PyResourceRefs 00000000AB089B50
_sound_anomaly_roof_modif int 0000000006912B80
mult int 0000000006912B80
config_name str 00000000039D5030
_initial_position Math.Vector3 00000000AB11A3A8
_pot_id NoneType 00007FF6DC943040
_player_main_inside bool 00007FF6DC940F18
controller_id NoneType 00007FF6DC943040
model_path str 000000002D6A54A8
potWallArt NoneType 00007FF6DC943040
potID NoneType 00007FF6DC943040
postproc_ids dict 00000000AB196808
player_position NoneType 00007FF6DC943040*/

struct Container : public Entity
{
	Py_dicthead;
	Py_AttributeHASH(Container, PyUnicodeObject*, containerName);
	Py_AttributeHASH(Container, PyINT32Object*, looted);

	DumpAttribute(Container);

	std::string GetName()
	{
		auto n = containerName();
		if (!n)
			return std::string();
		auto utf = n->to_string();
		return utf;
	}

	int is_looted() {
		auto isloot = this->looted();
		return isloot->get();
	}
};

/*
butcher_id int 0000000006912B80
CarryingItems PyArrayDataInstance 00000000F181CF28
left_looting_koef float 00000000E9BB35B8
sfx str 00000000039D5030
containerName unicode 00000000039DCF00
name unicode 00000000BB8C6990
_model_path unicode 000000002D7C1750
modelSelect int 0000000006912AC0
effect NoneType 00007FF6DC943040
height float 00000000E9BB8F88
is_busy int 0000000006912B80
looted int 0000000006912B80
butcher_id int 0000000006912B80
*/


struct NPC : public Entity
{
	Py_dicthead;
	Py_AttributeHASH(NPC, PyUnicodeObject*, en_name);
	Py_AttributeHASH(NPC, PyStringObject*, last_space_name);
	Py_AttributeHASH(NPC, PyINT8Object*, is_dead);
	Py_AttributeHASH(NPC, PyINT8Object*, canTakeDamage);
	DumpAttribute(NPC);

	std::string GetName()
	{
		auto n = en_name();
		if (!n)
			return std::string();
		auto utf = n->to_string();
		return utf;
	}
	std::string is_suit()
	{
		auto n = last_space_name();
		if (!n)
			return std::string();
		auto utf = n->to_string();
		return utf;
	}
	bool is_dead_npc()
	{
		auto isdeadproperty = this->is_dead();
		return isdeadproperty->get();
	}
	long long CTD()
	{
		auto prop = this->canTakeDamage();
		return prop->get();
	}
};

/*
CarryingItems PyArrayDataInstance 00000000776E4348
npcSuit int 0000000006912B80
_AvatarTrackers__last_tracker_key tuple 00000000A1C09510
npcID int 00000000269B4440
GUNMover_nodeInfo GUNMover 0000000092EEC558
_HandControl__reload_weapon_progress bool 00007FF6DC940F18
_looped_action NoneType 00007FF6DC943040
_tucking_item NoneType 00007FF6DC943040
tracker_arm_right Tracker 00000000A4C14D78
_old_end_shot_sfx NoneType 00007FF6DC943040
_fake_color_delegates list 00000000A1BF79C8
paint_mode list 000000002471E808
crouching_or_crawling int 0000000006912B80
_AvatarTrackers__last_xtorso_data NoneType 00007FF6DC943040
_foot_settings_path str 000000002C92D870
last_space_name str 000000003CB5F110
_last_wound_time float 0000000085CA86B0
headTrackerEnable int 0000000006912B68
footTriggers list 00000000A1BF3188
_AvatarTrackers__saved_yaw NoneType 00007FF6DC943040
set_ch_MaxStamina functools.partial 0000000084E3A818
_dung_timer_end int 0000000006912B80
_last_grenade_type int 0000000006912B80
_stuck bool 00007FF6DC940F18
_stopped_action NoneType 00007FF6DC943040
isBleending bool 00007FF6DC940F18
is_crafting bool 00007FF6DC940F18
_hd_end_burn_smoke NoneType 00007FF6DC943040
groups list 000000001E325788
_playing_animation_device bool 00007FF6DC940F18
_headlight Headlight 0000000084E377F0
_members_subscribed bool 00007FF6DC940F18
_is_lader_end_action_played bool 00007FF6DC940F18
kickBackTimer NoneType 00007FF6DC943040
_slope_eff_settings dict 000000002DD3C478
_ignorGravityAnimation bool 00007FF6DC940F18
looted int 0000000006912B80
collider_nodes dict 00000000A5AA50A8
torso_nodeinfo TorsoTrackerNodeInfo 00000000A0F667E8
_water_level NoneType 00007FF6DC943040
is_speaking bool 00007FF6DC940F18
EquippedCond2 list 0000000084E3B088
_potted int 0000000006912B80
_async_load_callback int 0000000006912B80
throw_callback_id int 0000000006912B80
bit_flags int 0000000006912B38
_model_pistol_holster NoneType 00007FF6DC943040
_visual_callback NoneType 00007FF6DC943040
set_ch_Penetration functools.partial 0000000084E3AA98
is_busy int 0000000006912B80
last_model_list dict 000000007D095CF8
hand_cotrol_wait_tmp bool 00007FF6DC940F18
fniLeft FootNodeInfo 00000000A4C98498
_sound_only_for_me NoneType 00007FF6DC943040
_head_exist bool 00007FF6DC9410B8
_in_hand_model_right NoneType 00007FF6DC943040
_pot_controller int 00000000269B4038
_playing_animation_item bool 00007FF6DC940F18
dialog_actions bool 00007FF6DC940F18
_Avatar__gun_anim_callback_id NoneType 00007FF6DC943040
_spayer_tid int 0000000006912B80
deathDrawn bool 00007FF6DC9410B8
_anim_action_loop NoneType 00007FF6DC943040
_last_ladder_action bool 00007FF6DC940F18
can_acquaint bool 00007FF6DC9410B8
tracker_torso Tracker 00000000A4C0EF38
_on_step_sound_additional NoneType 00007FF6DC943040
personality dict 000000007D0965F8
clanEmblemID int 0000000006912B80
weaponStatus int 0000000006912B80
_FootPrinter__water_volume_enable bool 00007FF6DC9410B8
_stopped_action_played NoneType 00007FF6DC943040
_putting_item_off NoneType 00007FF6DC943040
wanderSoon int 0000000006912B80
_soak_water_listener NoneType 00007FF6DC943040
_type_rep int 0000000006912B80
set_ch_MaxCombatPoints functools.partial 0000000084E3A778
EquippedGasMaskCond dict 000000007D093C58
en_name unicode 000000001E32A510
waterListenerKnee int 0000000006912880
hideNameCallbacker NoneType 00007FF6DC943040
head_nodeInfo HeadNodeInfo 00000000A1BB2908
colliderNames dict 00000000A5AA8468
ch_Defence dict 000000007D096CB8
_boxgroups NoneType 00007FF6DC943040
weapon_slots dict 00000000A5AA75C8
use_gesture bool 00007FF6DC940F18
need_ladder_yaw NoneType 00007FF6DC943040
model_scale float 000000008710B450
_burn_sound NoneType 00007FF6DC943040
_is_fix_action_sprint bool 00007FF6DC940F18
color_alphas collections.defaultdict 00000000A5AA6CC8
tracked_wanted NoneType 00007FF6DC943040
torsoProvider_entity EntityDirProvider 00000000A5BD57E8
_using_attach_model NoneType 00007FF6DC943040
headProvider_serverLook PyMatrix 00000000A5BD63B8
_equipped_modes_cache NoneType 00007FF6DC943040
_new_turn instance 00000000A1C06708
_dry_start_time NoneType 00007FF6DC943040
hp_barrel NoneType 00007FF6DC943040
set_ch_MaxHitPoints functools.partial 0000000084E3A6D8
_leftFreeHandProvider HandFreeProvider 0000000092EF0558
_min_stain_index int 0000000006912B80
_cabcarsitdata dict 000000007D097498
_hips_offset_by_rotate float 000000001FA89F70
_Gestures__current_gesture_actions NoneType 00007FF6DC943040
idPotHeadTrackIn int 00000000269B4020
_is_jump bool 00007FF6DC940F18
headProvider_cam_dcursor EntityDirProvider 00000000A5BD57E8
magnitude int 00000000069129E8
_putting_item_replace NoneType 00007FF6DC943040
autogunModelVisible bool 00007FF6DC9410B8
_speech_sound NoneType 00007FF6DC943040
eyes_controller instance 00000000A1C05308
chunk unicode 000000001E32A480
_draw_pickup bool 00007FF6DC940F18
walkSpeed float 000000008710B3F0
_prev_weapon_slots dict 00000000A5AA5408
heli_weapon NoneType 00007FF6DC943040
set_ch_HitPoints functools.partial 0000000084E3A688
ENABLE_MovingActionMather bool 00007FF6DC9410B8
moving_locked bool 00007FF6DC940F18
_foot_settings dict 000000008334D948
_todo_useanim_lock_torso bool 00007FF6DC940F18
set_ch_CombatPoints functools.partial 0000000084E3A728
_lock_bleed dict 000000007D095758
space unicode 000000001E32A780
_isBrustWeapon bool 00007FF6DC940F18
_putting_item_on NoneType 00007FF6DC943040
have_voice bool 00007FF6DC9410B8
gunnodeInfo TrackerWeaponNodeInfo 00000000A557F4B8
enable_tracker int 0000000006912B68
npcWeaponSecondary int 0000000006912B80
_is_lader_action_played bool 00007FF6DC940F18
_in_hand_model_left NoneType 00007FF6DC943040
_FootPrinter__cue_model_to_node dict 00000000A5AC92E8
_pot_cam_inside int 00000000269B3FF0
right_weapon_prov NoneType 00007FF6DC943040
_end_use_radio_anim bool 00007FF6DC940F18
belly_weapon NoneType 00007FF6DC943040
_cue_filter dict 00000000A5AA4D48
waterListenerHips int 0000000006912898
npcWeaponPrimaryAttachItemIDs PyArrayDataInstance 00000000A13427A8
_fence_id bool 00007FF6DC940F18
friendsList list 0000000084E3B1C8
kickbackValue float 000000002B781078
active_weapon_model NoneType 00007FF6DC943040
canTakeDamage int 0000000006912B80
talkFlag int 0000000006912B68
_additional_callback NoneType 00007FF6DC943040
_particles_burn_smoke NoneType 00007FF6DC943040
_colorise_emblems_cache NoneType 00007FF6DC943040
npcWeaponSecondaryAttachItemIDs PyArrayDataInstance 00000000A1342988
transformationID int 0000000006912B80
dataParentParamAvatar NoneType 00007FF6DC943040
armorColliderConroller ArmorCollider 00000000A1C084A8
listeners _Listeners 0000000084E37BE0
left_weapon_prov NoneType 00007FF6DC943040
_isBurn NoneType 00007FF6DC943040
test_tracker_gunrw NoneType 00007FF6DC943040
_tracker_locks dict 000000007D08A598
_AvatarTrackers__saved_action_queue NoneType 00007FF6DC943040
_leg_rotate_inside float 000000001FA89F58
effects_posteffects dict 000000007D0953F8
_Builder__pull_data_blocks dict 000000007D093A18
tracker_arm_left Tracker 00000000A4C14078
autogunModel NoneType 00007FF6DC943040
set_ch_Accuracy functools.partial 0000000084E3A8B8
displayName str 00000000039D5030
_trackers set 00000000765472E8
pvppkstat list 0000000084E3B188
_FootPrinter__last_surfaceHeight float 000000002C64E9F0
voice_type unicode 000000001E32A7E0
transport_seat int 0000000006912B80
can_patrol_mode bool 00007FF6DC940F18
visitor NoneType 00007FF6DC943040
fractionID int 0000000006912A78
npcWeaponPrimary int 0000000006912B80
_fake_item_dress_types dict 00000000A5AA64E8
ActiveWeaponSet2 PyFixedDictDataInstance 00000000A1342448
emblems_colors dict 00000000A5AA5648
set_ch_HitPointsRegeneration functools.partial 0000000084E3A908
_inAir bool 00007FF6DC940F18
set_ch_Defence functools.partial 0000000084E3AA48
headProvider_to_target NoneType 00007FF6DC943040
throwing_node PyModelNode 00000000A1BB2568
_fence_played bool 00007FF6DC940F18
_throw_need bool 00007FF6DC940F18
_usingItemSound NoneType 00007FF6DC943040
_UsingItemAnimation__current_action ActionQueuer 000000009793C0E0
_end_stop_radio_anim bool 00007FF6DC940F18
fniRight FootNodeInfo 00000000A4C97F48
_Avatar__gun_anim_callback_id2 NoneType 00007FF6DC943040
_party_status int 0000000006912B50
lock_move_by_jump bool 00007FF6DC940F18
showNameCallbacker NoneType 00007FF6DC943040
_totally_hidden_slots set 00000000782AE208
current_effects dict 000000007D093478
_player_war bool 00007FF6DC940F18
_AvatarTrackers__last_data_trackers NoneType 00007FF6DC943040
is_throwing bool 00007FF6DC940F18
_foot_rotate_limit float 000000001FA8A078
_foot_nodes dict 000000008334DB88
_end_throw_t int 0000000006912B80
_todo_useanim_lock_head bool 00007FF6DC940F18
tracker_head Tracker 00000000A4C10C78
invulnerable int 0000000006912B68
_soak_enabled bool 00007FF6DC940F18
nature int 0000000006912B20
set_ch_StaminaRegeneration functools.partial 0000000084E3A958
additionalModel NoneType 00007FF6DC943040
head_preset_name unicode 000000001E32A630
_AvatarTrackers__saved_hands NoneType 00007FF6DC943040
npcActions str 0000000084E32DF8
_isGasMaskSoundBreathing bool 00007FF6DC940F18
is_disable_hand_gravity bool 00007FF6DC9410B8
_hidden_item_dress_types set 00000000A1BFAAC8
_teleport_positions_towait NoneType 00007FF6DC943040
_anim_callback_id NoneType 00007FF6DC943040
nodeInfoL HandTrackerNodeInfo 000000006CA01538
coloriseEmblems PyArrayDataInstance 00000000A1341F68
wanderPhrase str 00000000039D5030
nodeInfoR HandTrackerNodeInfo 000000006CA096D8
collider_boxes dict 00000000A5AA4E68
repair_type list 000000002471E848
event_current_music NoneType 00007FF6DC943040
megaLodInOutDistanceInited bool 00007FF6DC9410B8
binoculing int 0000000006912B80
_raise_flag_id int 0000000006912B80
_visual_armor_cache NoneType 00007FF6DC943040
set_ch_CombatPointsRegeneration functools.partial 0000000084E3A9A8
isUseItemAnimationPlayed function 0000000084E169E8
BarterAssortment list 0000000084E3B248
_leg_rotate_outside float 000000001FA89F40
fix_roll_left_hand bool 00007FF6DC9410B8
npcWeaponPrimary2AttachItemIDs PyArrayDataInstance 00000000A1341D28
_tracker_is_init bool 00007FF6DC9410B8
_equipped_armor_dirty bool 00007FF6DC940F18
_restore_bellyweapon_delay float 000000002B776EC0
_wound_enabled bool 00007FF6DC940F18
tracker_weaponback instance 00000000A1C065C8
attack_active_target_id int 0000000006912B80
group_for_aggr int 0000000006912970
_tick_controller_id NoneType 00007FF6DC943040
_crafting_callback NoneType 00007FF6DC943040
_frame_index int 0000000006912B80
waterListener int 0000000006912868
tracker_weaponback2 instance 00000000A1C06608
_weapon_attack bool 00007FF6DC940F18
default_headTracker int 0000000006912B68
mark_height float 0000000087107868
_additional_callback_next NoneType 00007FF6DC943040
_foot_twist_lock set 0000000084E38BA8
set_ch_Stamina functools.partial 0000000084E3A7C8
_UsingItemAnimation__tmp_time float 000000008710B5A0
tracker_gun_mover Tracker 00000000A4C12678
effectsVisibleForAll PyArrayDataInstance 00000000776E4528
npcWeaponPrimary2 int 0000000006912B80
_hand_blend_prov_complete bool 00007FF6DC9410B8
_last_model_yaw NoneType 00007FF6DC943040
_using_item_action_name str 00000000039D5030
_isBurn_smoke NoneType 00007FF6DC943040
_tmp_py_head_prov NoneType 00007FF6DC943040
_last_hips_cache NoneType 00007FF6DC943040
_last_wound_point NoneType 00007FF6DC943040
_dry_controller NoneType 00007FF6DC943040
_active_spots set 0000000084E38C88
ActiveItemID long 0000000084E3C330
facingTracker1 NoneType 00007FF6DC943040
clanName str 00000000039D5030
_anim_action_out NoneType 00007FF6DC943040
dialogCameras PyArrayDataInstance 00000000A1341D88
_FootPrinter__timer_reatt int 0000000085CA9718
_additional_action NoneType 00007FF6DC943040
_async_load_counter int 0000000006912B80
tracker_gun Tracker 00000000A4C0F8F8
_last_in_pot_notification NoneType 00007FF6DC943040
_burn_world_model NoneType 00007FF6DC943040
_particles_burn NoneType 00007FF6DC943040
EquipModes int 0000000006912B80
frags int 0000000006912B80
sfx_enabled bool 00007FF6DC9410B8
_action_callback NoneType 00007FF6DC943040
face_controller FaceController 00000000A1C02C18
name unicode 00000000A1BD4540
foots list 00000000A1C06048
_FootPrinter__foot_cue_models dict 00000000A5AC6828
headProvider_cam_self EntityDirProvider 00000000A5BD57E8
maxPrice int 0000000006912B80
_callbackOnThrow NoneType 00007FF6DC943040
coords list 000000001E325748
patrol_mode int 0000000006912B80
_HandControl__isEquipProgress bool 00007FF6DC940F18
_rightFreeHandProvider HandFreeProvider 0000000092EECD58
dead int 0000000006912B80
_NPCAnimations__saved_animation str 000000002D64B6F0
set_ch_MoveSpeed functools.partial 0000000084E3A868
_current_action str 000000002D64B6F0
_UsingItemAnimation__dealyed_timer int 0000000006912B80
hoisting_flag NoneType 00007FF6DC943040
npcWeapon int 0000000006912B80
_total_vertices_number int 0000000006912B80
_hvat_actions dict 000000005AA7FA18
_tuck_coroutine NoneType 00007FF6DC943040
radiometer Radiometer 0000000084E37F60
EquippedVisibleAttaches PyFixedDictDataInstance 00000000777FEF78
ru_name unicode 000000001E32AA80
playedAnimationIndexList int 0000000006912B68
hp_barrel_node NoneType 00007FF6DC943040
enable_pitch bool 00007FF6DC940F18
debug bool 00007FF6DC940F18
_HandControl__reload_weapon_osn_anmation bool 00007FF6DC940F18
idPotHeadTrackOut int 00000000269B4008
grenadeArmed bool 00007FF6DC940F18
_todo_useanim_lock_foot bool 00007FF6DC940F18
right_hand_model_sound_node NoneType 00007FF6DC943040
_Avatar__SFXSeries_callbacks list 0000000084E264C8
EquippedArmor PyFixedDictDataInstance 00000000776E3E08
posteffects dict 000000007D093B38
_center_ladder NoneType 00007FF6DC943040
weaponProvider_entity EntityDirProvider 00000000A5BD57E8
isDisableDialogs int 0000000006912B80
head_look_cam bool 00007FF6DC940F18
_processed_vertices list 0000000084E2FFC8
npcType int 0000000006912B68
_burn_tick_id int 0000000006912B80
_anim_action_in NoneType 00007FF6DC943040
prof_name unicode 000000001E32A6F0
_stain_index int 0000000006912B80
headProvider_entity EntityDirProvider 00000000A5BD57E8
_restore_bellyweapon_callback NoneType 00007FF6DC943040
grade_config unicode 000000002471CBA0
isDecomposed int 0000000006912B80
_prev_matrix NoneType 00007FF6DC943040
_by_anim_weapon_to str 000000002C92C7E0
isBursting bool 00007FF6DC940F18
set_ch_MaxWeight functools.partial 0000000084E3A9F8
last_grenade_damage int 0000000006912B80
npcName str 0000000077DB3F80
_prereqs_model_key list 0000000084E3B408
_auto_clear_callback_id int 0000000076751F68
effects_sfxes dict 000000007D093598
_waitSnowTexture dict 00000000A5AABA68
butcher_id int 0000000006912B80
_head_to_pl_tID int 0000000006912B80
end_shot_sfx NoneType 00007FF6DC943040
_by_anim_has_lock bool 00007FF6DC9410B8
active_weapon NoneType 00007FF6DC943040
dialogAreas PyArrayDataInstance 00000000A13422C8
deaths int 0000000006912B80
waterListenerHead int 00000000069128B0
shooting bool 00007FF6DC940F18
test_nodeInfo_gunrw NoneType 00007FF6DC943040
_spayer_clouds list 0000000084E3B148
_playing_animation_loot bool 00007FF6DC940F18
set_ch_DamageAbsorb functools.partial 0000000084E3AAE8
_need_enable_look bool 00007FF6DC940F18
_subscribed_to_boat bool 00007FF6DC940F18
_craft_animation bool 00007FF6DC940F18
_Thrower__throw_ready bool 00007FF6DC940F18
_playing_animation_loot_cam_pos bool 00007FF6DC940F18
xTorso TorsoX 00000000A1C08D30
_torso_disbale_by_lookaround bool 00007FF6DC940F18
tracker_belly instance 00000000A1C05208
_AvatarTrackers__last_complexItemType int 0000000006912B80
deadCallback NoneType 00007FF6DC943040
_hand_gravity_enabled bool 00007FF6DC940F18
*/



struct DroppedItem : public Entity
{
	Py_dicthead;
	Py_AttributeHASH(DroppedItem, PyUnicodeObject*, name);
	DumpAttribute(DroppedItem);

	std::string GetName()
	{
		auto n = name();
		if (!n)
			return std::string();
		auto utf = n->to_string();
		return utf;
	}
};

/*
_pix_model PyModel 00000000BAA965A8
CarryingItems PyArrayDataInstance 00000000B7D86688
name unicode 000000004D794150
_messageAttachment NoneType 00007FF6BBF83040
_messageTimerHandle NoneType 00007FF6BBF83040
_DroppedItem__weapon NoneType 00007FF6BBF83040
*/

struct SoundNode : public Entity
{
	Py_dicthead;
	Py_AttributeHASH(SoundNode, PyUnicodeObject*, name);
	DumpAttribute(SoundNode);

	std::string GetName()
	{
		auto n = name();
		if (!n)
			return std::string();
		auto utf = n->to_string();
		return utf;
	}
};
struct ForestSoundNode : public Entity
{
	Py_dicthead;
	Py_AttributeHASH(ForestSoundNode, PyUnicodeObject*, name);
	DumpAttribute(ForestSoundNode);

	std::string GetName()
	{
		auto n = name();
		if (!n)
			return std::string();
		auto utf = n->to_string();
		return utf;
	}
};
struct SoundRainNode : public Entity
{
	Py_dicthead;
	Py_AttributeHASH(SoundRainNode, PyUnicodeObject*, name);
	DumpAttribute(SoundRainNode);

	std::string GetName()
	{
		auto n = name();
		if (!n)
			return std::string();
		auto utf = n->to_string();
		return utf;
	}
};

/*
Null
*/

struct QuestEntity : public Entity
{
	Py_dicthead;
	Py_AttributeHASH(QuestEntity, PyUnicodeObject*, name);
	DumpAttribute(QuestEntity);

	std::string GetName()
	{
		auto n = name();
		if (!n)
			return std::string();
		auto utf = n->to_string();
		return utf;
	}
};

/*
_bulbparticle NoneType 00007FF6BBF83040
_loop_sound NoneType 00007FF6BBF83040
obstacle int 0000000007AE7EB0
_particle_name NoneType 00007FF6BBF83040
loop_sound str 0000000003A65030
imitate_npc str 0000000003A65030
_mark_state bool 00007FF6BBF80F18
_has_target bool 00007FF6BBF80F18
_quest_states collections.defaultdict 00000000801A3618
mark PyFixedDictDataInstance 000000007B2213E8
conditions PyArrayDataInstance 000000007B2206C8
always_active int 0000000007AE7EB0
_particle_spawner instance 0000000075C865C8
_particles_cache dict 0000000075604778
light_effect int 0000000007AE7EB0
_target_name NoneType 00007FF6BBF83040
  str 0000000003A65030
avatar_use_action str 0000000075D97780
_particle NoneType 00007FF6BBF83040
_async_counter int 0000000007AE7EB0
_cur_model NoneType 00007FF6BBF83040
avatar_use_duration float 0000000076276850
highlight int 0000000007AE7EB0
_bulbparticle NoneType 00007FF6BBF83040
_loop_sound NoneType 00007FF6BBF83040
obstacle int 0000000007AE7EB0
_particle_name NoneType 00007FF6BBF83040
loop_sound str 0000000003A65030
imitate_npc str 0000000003A65030
_mark_state bool 00007FF6BBF80F18
_has_target bool 00007FF6BBF80F18
_quest_states collections.defaultdict 00000000801A3618
mark PyFixedDictDataInstance 000000007B2213E8
conditions PyArrayDataInstance 000000007B2206C8
always_active int 0000000007AE7EB0
_particle_spawner instance 0000000075C865C8
_particles_cache dict 0000000075604778
light_effect int 0000000007AE7EB0
_target_name NoneType 00007FF6BBF83040
  str 0000000003A65030
avatar_use_action str 0000000075D97780
_particle NoneType 00007FF6BBF83040
_async_counter int 0000000007AE7EB0
_cur_model NoneType 00007FF6BBF83040
avatar_use_duration float 0000000076276850
highlight int 0000000007AE7EB0
*/




struct WeaponWorkbench : public Entity
{
	Py_dicthead;
	Py_AttributeHASH(WeaponWorkbench, PyUnicodeObject*, name);
	DumpAttribute(WeaponWorkbench);

	std::string GetName()
	{
		auto n = name();
		if (!n)
			return std::string();
		auto utf = n->to_string();
		return utf;
	}
};
struct Workbench : public Entity
{
	Py_dicthead;
	Py_AttributeHASH(Workbench, PyUnicodeObject*, name);
	DumpAttribute(Workbench);

	std::string GetName()
	{
		auto n = name();
		if (!n)
			return std::string();
		auto utf = n->to_string();
		return utf;
	}
};

/*
name unicode 00000001011BE600
group_id int 0000000007AE7D48
need_kickstart int 0000000007AE7EB0
workbenchType int 0000000007AE7E80
height float 000000015AA978B0*/



struct ZoneEffects : public Entity
{
	Py_dicthead;
	Py_AttributeHASH(ZoneEffects, PyINT8Object*, zoneEffectID);
	Py_AttributeHASH(ZoneEffects, PyINT8Object*, player_in_area);
	DumpAttribute(ZoneEffects);

	int effectID() {
		auto n = this->zoneEffectID();
		return n->get();
	}
	bool is_player_in_area() {
		auto n = this->player_in_area();
		return n->get();
	}
};
/*
pp_radius_max float 000000007EF829D8
_particle_system NoneType 00007FF696893040
_pot_id int 0000000025F177B8
figure_type int 0000000025F17788
player_in_trap bool 00007FF696890F18
activated int 0000000025F177B8
TICK_INTERVAL float 00000000224A7880
zoneEffectID int 000000007EEE30F8
controller_id NoneType 00007FF696893040
radius_max_effect float 000000007EF81E38
config_name str 0000000003AA5030
radius float 000000007EF81E38
_particle_spawner instance 000000007E5E67C8
postproc_ids dict 000000007CCC6678
player_in_area bool 00007FF696890F18
player_position NoneType 00007FF696893040
_prereqs NoneType 00007FF696893040
mult int 0000000025F177D0
pp_config_name str 0000000003AA5030*/





struct PostProcessZone : public Entity {
	Py_dicthead;
	Py_AttributeHASH(PostProcessZone, PyStringObject*, config_name);
	Py_AttributeHASH(PostProcessZone, PyINT8Object*, player_in_area);
	DumpAttribute(PostProcessZone);

	std::string GetName()
	{
		auto n = config_name();
		if (!n)
			return std::string();
		auto utf = n->to_string();
		return utf;
	}
	bool in_area() {
		auto n = this->player_in_area();
		return n->get();
	}
};

/*
config_name str 00000000EA0E20C0
controller_id NoneType 00007FF6E2573040
sizeX float 00000000B5EA0480
_pot_id int 00000000B9C3A420
figure_type int 0000000008DCFC28
sizeY float 00000000B5EA0468
sizeZ float 00000000B5EA0450
height float 00000000B5EA0498
postproc_ids dict 00000000F2EFF6D8
radius float 00000000B5EA04B0
radius_max_effect float 00000000B5EA0438
TICK_INTERVAL float 0000000025E75348
border_points_list PyArrayDataInstance 00000000CE7809B8
player_in_area bool 00007FF6E2570F18
player_position NoneType 00007FF6E2573040
mult int 0000000008DCFC70
player_in_trap bool 00007FF6E2570F18
*/




struct TriggerObject : public Entity
{
	Py_dicthead;
	Py_AttributeHASH(TriggerObject, PyStringObject*, triggerName);
	Py_AttributeHASH(TriggerObject, PyINT32Object*, quest);
	DumpAttribute(TriggerObject);

	std::string GetName()
	{
		auto n = triggerName();
		if (!n)
			return std::string();
		auto utf = n->to_string();
		return utf;
	}
	int is_quest() {
		auto n = this->quest();
		return n->get();
	}
};

/*
_model_path str 000000004B2341B0
displayName str 00000000906FA870
qEffect str 00000000042AD030
hasPlayer bool 00007FF72B690F18
modelSelect int 0000000008D6F4C0
high_precision int 0000000008D71380
activeFlags long 0000000089D06F50
scaleY float 00000000BF528178
activated int 0000000008D71368
talkFlag int 0000000008D71368
quest int 0000000008D71380
radius float 00000000BF52FC18
scaleZ float 00000000BF529AE0
triggerName str 00000000906DFF80
scaleX float 00000000BF52C510
mark_height float 00000000BF52FC78
obstacle int 0000000008D71368
name unicode 0000000074C097B0*/


struct ObjectInfo : public Entity
{
	Py_dicthead;
	Py_AttributeHASH(ObjectInfo, PyUnicodeObject*, name);
	DumpAttribute(ObjectInfo);

	std::string GetName()
	{
		auto n = name();
		if (!n)
			return std::string();
		auto utf = n->to_string();
		return utf;
	}
};
/*
scale float 00000000889846A8
name unicode 00000000750E9930
_model_path unicode 00000000314459F0
radius float 00000000BF516040
model_index int 0000000008D712D8
name_id str 00000000750B8E30*/

struct DrawWell : public Entity
{
	Py_dicthead;
	Py_AttributeHASH(DrawWell, PyUnicodeObject*, name);
	DumpAttribute(DrawWell);

	std::string GetName()
	{
		auto n = name();
		if (!n)
			return std::string();
		auto utf = n->to_string();
		return utf;
	}
};

/*
waterType int 0000000008DCFC58
name unicode 00000000C9946A20
modelType int 0000000008DCFC70
height float 00000000E144C358
radius float 000000008634CD38
can_coin int 0000000008DCFC70
_pot_handle int 00000000C28DB290
*/









//ЙЮЙХЕ-РН РПХЦЦЕПШ УГ
struct ClientTrigger : public Entity
{
	Py_dicthead;
	Py_AttributeHASH(ClientTrigger, PyStringObject*, trigger_id);
	DumpAttribute(ClientTrigger);

	std::string GetName()
	{
		auto n = trigger_id();
		if (!n)
			return std::string();
		auto utf = n->to_string();
		return utf;
	}
};
/*
notify_on_enter str 00000000E8694CF0
_is_in_world bool 00007FF72B6910B8
trigger_model str 00000000042AD030
sizeX float 0000000088984468
figure_type int 0000000008D71338
sizeY float 00000000BAD1FA00
sizeZ float 000000008898AC00
height float 00000000889ACEC0
sound_on_enter str 0000000074BC4EA0
radius float 000000008898AC48
trigger_id str 00000000042AD030
show_by_knowledge int 0000000008D71368
need_quest int 0000000008D71380
run_dialog_on_enter long 0000000089CF9290
_marked_to_destroy bool 00007FF72B690F18
open_help str 00000000042AD030
destroy_on_enter int 0000000008D71368
_pot_id int 00000000917A8018
TICK_INTERVAL float 0000000026450090
controller_id NoneType 00007FF72B693040
activate_type int 0000000008D71380
model_scale_x float 00000000BAD221F0
model_scale_y float 000000008898AB40
model_scale_z float 00000000889ACF20
border_points_list PyArrayDataInstance 0000000085129818
player_in_area bool 00007FF72B690F18
player_position NoneType 00007FF72B693040
player_in_trap bool 00007FF72B690F18*/

struct ClientTestTriggerTime : public Entity
{
	Py_dicthead;
	Py_AttributeHASH(ClientTestTriggerTime, PyUnicodeObject*, game_time_diap);
	DumpAttribute(ClientTestTriggerTime);

	std::string GetName()
	{
		auto n = game_time_diap();
		if (!n)
			return std::string();
		auto utf = n->to_string();
		return utf;
	}
};
/*
_hundle_timer int 00000000917BC9A0
targetNodes PyArrayDataInstance 00000000DB97B038
state int 0000000008D71380
tto int 00000000917A7FD0
tfrom int 00000001078692E8
game_time_diap str 0000000089D61F10*/





//кеярмхжш
struct VerticalLadder : public Entity
{
	Py_dicthead;
	Py_AttributeHASH(VerticalLadder, PyUnicodeObject*, name);
	DumpAttribute(VerticalLadder);

	std::string GetName()
	{
		auto n = name();
		if (!n)
			return std::string();
		auto utf = n->to_string();
		return utf;
	}
};

/*
model_type int 0000000008D71368
_real_height float 00000000BF51F670
steps int 0000000008D717A0
height float 00000000BF520150
*/







//яйнокемхе фхбмнярх
struct VerminSpawner : public Entity
{
	Py_dicthead;
	Py_AttributeHASH(VerminSpawner, PyStringObject*, config);
	DumpAttribute(VerminSpawner);

	std::string GetName()
	{
		auto n = config();
		if (!n)
			return std::string();
		auto utf = n->to_string();
		return utf;
	}
};


/*
EXT_OBJ VerminSpawnerC 00000000675392D0
sizeX float 00000000889A4F88
figure_type int 0000000008D71350
sizeY float 00000000BF52C4E0
sizeZ float 00000000BF5319B8
height float 00000000BF51F778
radius float 00000000BF517AB0
_tick_controller_id int 00000001050E6D08
config str 0000000074BBB7A0
vermins_count int 0000000008D711A0*/






struct StoriesEntity : public Entity
{
	Py_dicthead;
	Py_AttributeHASH(StoriesEntity, PyUnicodeObject*, name);
	Py_AttributeHASH(StoriesEntity, PyINT8Object*, active);
	DumpAttribute(StoriesEntity);

	std::string GetName()
	{
		auto n = name();
		if (!n)
			return std::string();
		auto utf = n->to_string();
		return utf;
	}
	bool IsActive() {
		auto n = this->active();
		return n->get();
	}
};
/*
scale float 00000000BF518308
name unicode 00000000851678D0
parent NoneType 00007FF72B693040
_model_path unicode 0000000031C3A330
callback_id NoneType 00007FF72B693040
model_index int 0000000008D6E950
active bool 00007FF72B6910B8
stories_id int 0000000008D6F6E8
*/




// дНЯЙЮ НАЗЪБКЕМХИ
struct BulletinBoard : public Entity
{
	Py_dicthead;
	Py_AttributeHASH(BulletinBoard, PyUnicodeObject*, name);
	DumpAttribute(BulletinBoard);

	std::string GetName()
	{
		auto n = name();
		if (!n)
			return std::string();
		auto utf = n->to_string();
		return utf;
	}
};
/*
name
height*/





// уСЕРЮ
struct FarPlaneCustom : public Entity
{
	Py_dicthead;
	Py_AttributeHASH(FarPlaneCustom, PyUnicodeObject*, name);
	DumpAttribute(FarPlaneCustom);

	std::string GetName()
	{
		auto n = name();
		if (!n)
			return std::string();
		auto utf = n->to_string();
		return utf;
	}
};
/*
controller_id NoneType 00007FF7229E3040
sizeX float 00000000C8AEF4E0
_pot_id int 000000008010DC98
figure_type int 00000000260E5558
sizeY float 00000000800EF6E0
sizeZ float 000000004D1612D8
height float 000000002D61D7D0
radius float 000000004D0AF678
player_in_trap bool 00007FF7229E0F18
farPlaneValue float 00000000C8AEDD28
border_points_list PyArrayDataInstance 00000000B4DA71B8
player_in_area bool 00007FF7229E0F18
player_position NoneType 00007FF7229E3040
TICK_INTERVAL float 000000002412E778*/

struct Stone : public Entity
{
	Py_dicthead;
	Py_AttributeHASH(Stone, PyUnicodeObject*, name);
	Py_AttributeHASH(Stone, PyINT32Object*, targetID)
	DumpAttribute(Stone);

	std::string GetName()
	{
		auto n = name();
		if (!n)
			return std::string();
		auto utf = n->to_string();
		return utf;
	}
	int entity_id() {
		auto n = this->targetID();
		return n->get();
	}
};

/*
prematureExplosion int 000000000002A9A4
cached_anomalies NoneType 000000000001FEB1
removeSelfEnt_callback_id int 0000000000000001
npc_controlled bool 00000000000141C6
creature_controlled bool 00000000000141C6
fromServer int 000000000002A9A4
prev_position Math.Vector3 0000000000000001
spawn_time float 0000000000000001
controled_by_this_client bool 0000000000006F14
targetID int 000000000002A9A4
params dict 0000000000000004
prev_tick_time float 0000000000000001
model_sfx NoneType 000000000001FEB1
isJumped bool 00000000000141C6
hit bool 00000000000141C6
originalID int 0000000000000002
last_distance int 0000000000000002
grenade_type int 0000000000000001
anomalyEntityID int 000000000002A9A4
ownerID int 0000000000000002
custom_sound_contact NoneType 000000000001FEB1
collided_anomalies set 0000000000000001
onFlyEnd_callback_id int 0000000000000001
under_water bool 00000000000141C6
startPosition Math.Vector3 0000000000000001
bouncer Bouncer 0000000000000002
water_volume_listener int 0000000000000001
velocity Math.Vector3 0000000000000001
skillID int 000000000002A9A4
anomaly_timer NoneType 000000000001FEB1*/



struct UserFire : public Entity
{
	Py_dicthead;
	Py_AttributeHASH(UserFire, PyUnicodeObject*, name);
	DumpAttribute(UserFire);

	std::string GetName()
	{
		auto n = name();
		if (!n)
			return std::string();
		auto utf = n->to_string();
		return utf;
	}
};
/*
_pl_inside bool 00007FF6BBF80F18
_model PyModel 000000006FCB2748
inTheProcessItems PyArrayDataInstance 00000001210A10F8
light_timer_id int 00000000A29A1D28
pOwnerName unicode 00000001514BC210
isPublicAcces int 0000000007AE7EB0
_sound Sound 0000000126CC9390
life_time_end int 00000000E38C3CB8
_model_OFF PyModel 000000006FCB8288
cookingpot_items PyFixedDictDataInstance 00000001210A1518
_messageTimerHandle NoneType 00007FF6BBF83040
_pot_models dict 0000000133DD20C8
sound NoneType 00007FF6BBF83040
_model_tri PyModel 000000006FCB1078
name unicode 00000001449487B0
dict_items dict 0000000179274B68
light PyChunkLight 0000000148D72DA8
_fireType int 0000000007AE7E68
effect_OFF PyMetaParticleSystem 000000014ED0FE38
_messageAttachment NoneType 00007FF6BBF83040
_pot_handle int 000000015AA9BB88
_sound_model PyModel 000000006FCB1E28
light_start_position Math.Vector3 000000012D314D38
_loopFire_timer_id int 00000000A29AA488
CarryingItems PyArrayDataInstance 00000001210A06D8
effects list 00000001479D8148
*/



//Birdflock
//Stone
//BulletinBoard
//FarPlaneCustom
//ObjectInfo
//StoriesEntity
//Reverb
//AutoTrigger
//ZoneEffects
//VerticalLadder
//ClientTestTriggerTime
//WeaponWorkbench (НПСФЕИМШИ БЕПЯРЮЙ)
//Workbench (БЕПЯРЮЙ)
//UserFire (ЙНЯР╦П)
//SoundRainNode
//ForestSoundNode
//Cabmancar
//DrawWell
//AutomaticSalute
//PostProcessZone
//ClientTrigger
//TriggerObject
//str
//VerminSpawner

struct EntityMapEntry
{
	EntityMapEntry* next();
	Entity* entity();


	int entityID();
};
struct EntityMap
{
	EntityMapEntry* iter;
	int num;
};

struct EntityManager
{
	static EntityManager* instance(); //  https://github.com/v2v3v4/BigWorld-Engine-2.0.1/blob/master/src/client/entity_manager.hpp#L48
	EntityMap Entities();
};