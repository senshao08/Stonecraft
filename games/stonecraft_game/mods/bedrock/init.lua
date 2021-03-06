--[[
=====================================================================
Minetest mod: Bedrock

Copyright (c) 2013-2017 Hugo Locurcio and contributors.
Licensed under the zlib license. See LICENSE.md for more information.
=====================================================================
--]]

--[[

2017-05-21 MrCerealGuy: added intllib support

--]]


-- Load support for intllib.
local MP = minetest.get_modpath(minetest.get_current_modname())
local S, NS = dofile(MP.."/intllib.lua")

minetest.register_ore({
	ore_type       = "scatter",
	ore            = "bedrock:bedrock",
	wherein        = "default:stone",
	clust_scarcity = 1 * 1 * 1,
	clust_num_ores = 5,
	clust_size     = 2,
	height_min     = -30912, -- Engine changes can modify this value
	height_max     = -30656, -- This ensures the bottom of the world is not even loaded
})

minetest.register_ore({
	ore_type       = "scatter",
	ore            = "bedrock:deepstone",
	wherein        = "default:stone",
	clust_scarcity = 1 * 1 * 1,
	clust_num_ores = 5,
	clust_size     = 2,
	height_min     = -30656,
	height_max     = -30000,
})

minetest.register_node("bedrock:bedrock", {
	description = S("Bedrock"),
	tile_images = {"bedrock_bedrock.png"},
	drop = "",
	groups = {unbreakable = 1, not_in_creative_inventory = 1}, -- For Map Tools' admin pickaxe
	sounds = default.node_sound_stone_defaults(),
})

minetest.register_node("bedrock:deepstone", {
	description = S("Deepstone"),
	tile_images = {"bedrock_deepstone.png"},
	drop = "default:stone", -- Intended
	groups = {cracky = 1},
	sounds = default.node_sound_stone_defaults(),
})

if minetest.setting_getbool("log_mods") then
	minetest.log("action", "[bedrock] loaded.")
end
