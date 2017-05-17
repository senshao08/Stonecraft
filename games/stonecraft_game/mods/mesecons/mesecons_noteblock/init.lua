--[[

2017-01-06 modified by MrCerealGuy <mrcerealguy@gmx.de>
	exit if mod is deactivated

2017-05-17 MrCerealGuy: added intllib support

--]]

local DIR_DELIM = DIR_DELIM or "/"
local world_file = minetest.get_worldpath()..DIR_DELIM.."world.mt"
local world_conf = Settings(world_file)
local enable_mesecons = world_conf:get("enable_mesecons")

if enable_mesecons ~= nil and enable_mesecons == "false" then
	minetest.log("info", "[mesecons:noteblock] skip loading mod.")
	return
end

-- --------------------------------------------------------------------------------------------------------


-- Load support for intllib.
local MP = minetest.get_modpath(minetest.get_current_modname())
local S, NS = dofile(MP.."/intllib.lua")

minetest.register_node("mesecons_noteblock:noteblock", {
	description = S("Noteblock"),
	tiles = {"mesecons_noteblock.png"},
	groups = {snappy=2, choppy=2, oddly_breakable_by_hand=2},
	on_punch = function(pos, node) -- change sound when punched
		node.param2 = (node.param2+1)%12
		mesecon.noteblock_play(pos, node.param2)
		minetest.set_node(pos, node)
	end,
	sounds = default.node_sound_wood_defaults(),
	mesecons = {effector = { -- play sound when activated
		action_on = function(pos, node)
			mesecon.noteblock_play(pos, node.param2)
		end
	}}
})

minetest.register_craft({
	output = "mesecons_noteblock:noteblock 1",
	recipe = {
		{"group:wood", "group:wood", "group:wood"},
		{"group:mesecon_conductor_craftable", "default:steel_ingot", "group:mesecon_conductor_craftable"},
		{"group:wood", "group:wood", "group:wood"},
	}
})

local soundnames = {
	[0] = "mesecons_noteblock_csharp",
	"mesecons_noteblock_d",
	"mesecons_noteblock_dsharp",
	"mesecons_noteblock_e",
	"mesecons_noteblock_f",
	"mesecons_noteblock_fsharp",
	"mesecons_noteblock_g",
	"mesecons_noteblock_gsharp",

	"mesecons_noteblock_a",
	"mesecons_noteblock_asharp",
	"mesecons_noteblock_b",
	"mesecons_noteblock_c"
}

local node_sounds = {
	["default:glass"] = "mesecons_noteblock_hihat",
	["default:stone"] = "mesecons_noteblock_kick",
	["default:lava_source"] = "fire_large",
	["default:chest"] = "mesecons_noteblock_snare",
	["default:tree"] = "mesecons_noteblock_crash",
	["default:wood"] = "mesecons_noteblock_litecrash",
	["default:coalblock"] = "tnt_explode",
}

mesecon.noteblock_play = function(pos, param2)
	pos.y = pos.y-1
	local nodeunder = minetest.get_node(pos).name
	local soundname = node_sounds[nodeunder]
	if not soundname then
		soundname = soundnames[param2]
		if not soundname then
			minetest.log("error", "[mesecons_noteblock] No soundname found, test param2")
			return
		end
		if nodeunder == "default:steelblock" then
			soundname = soundname.. 2
		end
	end
	pos.y = pos.y+1
	minetest.sound_play(soundname, {pos = pos})
end
