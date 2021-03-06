--[[

2017-01-06 modified by MrCerealGuy <mrcerealguy@gmx.de>
	exit if mod is deactivated

2017-05-16 MrCerealGuy: added intllib support

--]]

if core.skip_mod("seaplants") then return end

-- Load support for intllib.
local MP = minetest.get_modpath(minetest.get_current_modname())
local S, NS = dofile(MP.."/intllib.lua")

-- NODES

minetest.register_node("sealamps:torch", {
	description = S("Sea torch"),
	drawtype = "torchlike",
	tiles = {
		{name="sealamps_torch_on_floor_animated.png", animation={type="vertical_frames", aspect_w=16, aspect_h=16, length=3.0}},
		{name="sealamps_torch_on_ceiling_animated.png", animation={type="vertical_frames", aspect_w=16, aspect_h=16, length=3.0}},
		{name="sealamps_torch_animated.png", animation={type="vertical_frames", aspect_w=16, aspect_h=16, length=3.0}}
	},
	inventory_image = "sealamps_torch_on_floor.png",
	wield_image = "sealamps_torch_on_floor.png",
	paramtype = "light",
	paramtype2 = "wallmounted",
	sunlight_propagates = true,
	walkable = false,
	light_source = LIGHT_MAX-1,
	selection_box = {
		type = "wallmounted",
		wall_top = {-0.1, 0.5-0.6, -0.1, 0.1, 0.5, 0.1},
		wall_bottom = {-0.1, -0.5, -0.1, 0.1, -0.5+0.6, 0.1},
		wall_side = {-0.5, -0.3, -0.1, -0.5+0.3, 0.3, 0.1},
	},
	groups = {choppy=2,dig_immediate=3,flammable=1,attached_node=1,hot=2,sea=1},
	legacy_wallmounted = true,
	sounds = default.node_sound_defaults(),
})

minetest.register_node("sealamps:lantern", {
	description = S("Sea lantern"),
	drawtype = "torchlike",
	tiles = {
		{name="sealamps_lantern_on_floor.png"},
		{name="sealamps_lantern_on_ceiling.png"},
		{name="sealamps_lantern.png"}
	},
	inventory_image = "sealamps_lantern_on_floor.png",
	wield_image = "sealamps_lantern_on_floor.png",
	paramtype = "light",
	paramtype2 = "wallmounted",
	sunlight_propagates = true,
	walkable = false,
	light_source = LIGHT_MAX-1,
	selection_box = {
		type = "wallmounted",
		wall_top = {-0.1, 0.5-0.6, -0.1, 0.1, 0.5, 0.1},
		wall_bottom = {-0.1, -0.5, -0.1, 0.1, -0.5+0.6, 0.1},
		wall_side = {-0.5, -0.3, -0.1, -0.5+0.3, 0.3, 0.1},
	},
	groups = {choppy=2,dig_immediate=3,attached_node=1,hot=2,sea=1},
	legacy_wallmounted = true,
	sounds = default.node_sound_defaults(),
})


-- CRAFTING


minetest.register_craft({
	output = 'sealamps:torch 8',
	recipe = {
		{'bucket:bucket_lava'},
		{'default:coal_lump'},
		{'default:stick'}
	},
	replacements = { {'bucket:bucket_lava', 'bucket:bucket_empty'}, },
})

minetest.register_craft({
	output = 'sealamps:lantern 4',
	recipe = {
		{'default:steel_ingot', 'default:bronze_ingot', 'default:glass'},
	},
})