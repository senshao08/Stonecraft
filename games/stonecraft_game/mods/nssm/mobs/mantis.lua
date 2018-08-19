mobs:register_mob("nssm:mantis", {
	type = "monster",
	hp_max = 31,
	hp_min = 24,
	collisionbox = {-0.5, 0.00, -0.5, 0.5, 2.30, 0.5},
	visual = "mesh",
	mesh = "mantis.x",
	textures = {{"mantis.png"}, {"mantis2.png"}},
	visual_size = {x=4, y=4},
	makes_footstep_sound = true,
	view_range = 20,
	fear_height = 4,
	walk_velocity = 2,
	run_velocity = 2.5,
	sounds = {
		random = "manti",
	},
	damage = 4,
	jump = true,
	drops = {
		{name = "nssm:mantis_claw",
		chance = 2,
		min = 1,
		max = 4,},
		{name = "nssm:life_energy",
		chance = 1,
		min = 1,
		max = 2,},
		{name = "nssm:mantis_skin",
		chance = 3,
		min = 1,
		max = 2,},
		{name = "nssm:mantis_meat",
		chance = 2,
		min = 1,
		max = 2,},
	},
	armor = 70,
	drawtype = "front",
	water_damage = 2,
	lava_damage = 5,
	light_damage = 0,
	on_rightclick = nil,
	group_attack=true,
	attack_animals=true,
	knock_back=2,
	blood_texture="nssm_blood_blue.png",
	stepheight=1.1,
	double_melee_attack = true,
	attack_type = "dogfight",
	animation = {
		speed_normal = 25,
		speed_run = 25,
		stand_start = 1,
		stand_end = 20,
		walk_start = 20,
		walk_end = 60,
		run_start = 60,
		run_end = 80,
		punch_start = 120,
		punch_end = 140,
		punch2_start = 145,
		punch2_end = 165,
	}
})
