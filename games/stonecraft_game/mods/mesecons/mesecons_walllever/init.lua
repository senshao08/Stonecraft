--[[

2017-01-06 modified by MrCerealGuy <mrcerealguy@gmx.de>
	exit if mod is deactivated

2017-05-17 MrCerealGuy: added intllib support

--]]

if core.skip_mod("mesecons") then return end

-- Load support for intllib.
local MP = minetest.get_modpath(minetest.get_current_modname())
local S, NS = dofile(MP.."/intllib.lua")

-- WALL LEVER
-- Basically a switch that can be attached to a wall
-- Powers the block 2 nodes behind (using a receiver)
mesecon.register_node("mesecons_walllever:wall_lever", {
	description=S("Lever"),
	drawtype = "mesh",
	inventory_image = "jeija_wall_lever_inv.png",
	wield_image = "jeija_wall_lever_inv.png",
	paramtype = "light",
	paramtype2 = "facedir",
	sunlight_propagates = true,
	walkable = false,
	selection_box = {
		type = "fixed",
		fixed = { -8/16, -8/16, 3/16, 8/16, 8/16, 8/16 },
	},
	sounds = default.node_sound_wood_defaults(),
	on_rightclick = function (pos, node)
		if(mesecon.flipstate(pos, node) == "on") then
			mesecon.receptor_on(pos, mesecon.rules.buttonlike_get(node))
		else
			mesecon.receptor_off(pos, mesecon.rules.buttonlike_get(node))
		end
		minetest.sound_play("mesecons_lever", {pos=pos})
	end
},{
	tiles = {
		"jeija_wall_lever_lever_light_off.png",
		"jeija_wall_lever_front.png",
		"jeija_wall_lever_front_bump.png",
		"jeija_wall_lever_back_edges.png"
	},
	mesh="jeija_wall_lever_off.obj",
	mesecons = {receptor = {
		rules = mesecon.rules.buttonlike_get,
		state = mesecon.state.off
	}},
	groups = {dig_immediate = 2, mesecon_needs_receiver = 1}
},{
	tiles = {
		"jeija_wall_lever_lever_light_on.png",
		"jeija_wall_lever_front.png",
		"jeija_wall_lever_front_bump.png",
		"jeija_wall_lever_back_edges.png"
	},
	mesh="jeija_wall_lever_on.obj",
	mesecons = {receptor = {
		rules = mesecon.rules.buttonlike_get,
		state = mesecon.state.on
	}},
	groups = {dig_immediate = 2, mesecon_needs_receiver = 1, not_in_creative_inventory = 1}
})

minetest.register_craft({
	output = "mesecons_walllever:wall_lever_off 2",
	recipe = {
	    {"group:mesecon_conductor_craftable"},
		{"default:stone"},
		{"default:stick"},
	}
})
