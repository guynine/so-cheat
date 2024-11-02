#pragma once
struct espent
{
	static inline bool show_menu = false;
	static inline bool  overlay_vsync = true;

	static inline bool test = true;

	static inline bool esp_nick = false;
	static inline bool esp_aimbox = false;
	static inline bool esp_people_fill_box = false;
	static inline bool esp_people_box = false;
	static inline bool esp_clanName = false;
	static inline bool esp_creature_live = false;
	static inline bool esp_creature_dead = false;
	static inline bool esp_npc_name = false;
	static inline bool esp_anomaly = false;
	static inline bool esp_Container = false;
	static inline bool esp_artefact = false;
	static inline bool esp_loot = false;
	static inline bool esp_quest_objects = false;
	static inline bool esp_sound_objects = false;
	static inline bool esp_fires = false;
	static inline bool esp_tables = false;
	static inline bool esp_recommendations = false;
	static inline bool esp_trigger_objects = false;
	static inline bool esp_info = false;
	static inline bool esp_notes = false;
	static inline bool esp_ladders = false;
	static inline bool esp_spawner = false;

	static inline bool esp_visible_players = false;

	static inline bool esp_test = false;

	static inline bool esp_creature_distance = true;
	static inline float esp_creature_radius = 0;
	static inline float esp_npc_radius = 0;
	static inline float esp_people_radius = 0;
	static inline float esp_anomaly_radius = 0;
	static inline float esp_container_radius = 0;
	static inline bool esp_people_distance = true;
	static inline bool esp_npc_distance = true;
	static inline bool esp_anomaly_distance = true;
	static inline bool esp_container_distance = true;
	static inline bool esp_qsobjects_distance = true;
	static inline float esp_qsobjects_radius = 0;

	static inline bool esp_checked_anomaly = false;
	static inline bool esp_radar = false;
	static inline int esp_radar_radius = 10;
	static inline bool esp_radar_a = false;
	static inline bool esp_radar_n = false;
	static inline bool esp_radar_p = false;
	static inline bool esp_radar_m = false;
};

struct menu_vars2
{
	static inline bool show_menu = false;
	static inline bool  overlay_vsync = true;

	static inline bool aim_player = false;
	static inline bool aim_clan_player = false;
	static inline float aim_speed_people = 0.0;
	static inline float aim_smooth_people = 0.0;
	static inline int aim_high = 25;
	static inline int aim_high_circle = 0;
	static inline int aim_creature_high_circle = 0;
	static inline bool no_speed_no_smooth = false;
	static inline float size_p = 86;
};
struct main {
	static inline bool show_menu = true;
};
struct settings
{
	static inline bool show_menu = false;
	static inline bool  overlay_vsync = true;

	static inline float size_sh = 12.0F;
	static inline bool aim_npc = false;
	static inline float aim_speed_npc = 0.6;
	static inline float aim_smooth_npc = 3.5;
	static inline int aim_high_npc = 25;
	static inline float size_n = 77;
};
struct menu_vars3
{
	static inline bool show_menu = false;
	static inline bool  overlay_vsync = true;

	static inline bool aim_creature = false;
	static inline float aim_speed_creature = 0.0;
	static inline float aim_smooth_creature = 0.0;
	static inline float size_c = 0;
};

struct menu_vars4
{
	static inline bool show_menu = false;
	static inline bool  overlay_vsync = true;

	static inline bool crosshair = false;
	static inline bool aim_radius_p = false;
	static inline bool aim_radius_n = false;
	static inline bool aim_radius_c = false;
	static inline bool esp_kills_people = false;
	static inline bool esp_karma_people = false;
	static inline bool esp_cantakedamage_people = false;
	static inline bool esp_accesslevel_people = false;
	static inline bool esp_blacklist_people = false;
	static inline bool esp_only_active_notes = false;
	static inline bool memorizer_artefacts = false;
	static inline bool name_anomalies = false;
	static inline bool panic_key = true;
	static inline bool speed_key = false;
	static inline bool auto_farm_kaban = false;
	static inline float speed_sh = 7.5;
	static inline bool speedhack_legit = false;

	static inline char nickname_blacklist[64];
	static inline char name_config_c[120];
};

struct exploit
{
	static inline bool show_menu = false;
	static inline bool  overlay_vsync = true;

	static inline bool no_clip = false;
	static inline int no_clip_distance = 1;
	static inline bool tp_people = false;
	static inline bool tp_creature = false;
	static inline bool anomaly_protect = false;
	static inline bool magnit_people = false;
	static inline bool magnit_anomaly = false;
	static inline bool legit_magnit_anomaly = false;
	static inline int distance_magnit = 0;
	static inline int radius_magnit = 100;
	static inline int player_count_limit = 0;
	static inline bool freeze_packets = false;
	static inline int kilobyte_rate = 0;
	static inline bool bright = false;
	static inline int bright_int = 0;
};

struct snapline_menu
{
	static inline bool show_menu = true;
	static inline bool  overlay_vsync = true;

	static inline bool players_snapline = false;
	static inline bool creature_snapline = false;
	static inline bool npc_snapline = false;
	static inline bool anomaly_snapline = false;
	static inline bool artefact_snapline = false;
	static inline bool container_snapline = false; 
	static inline bool loot_snapline = false;
};

