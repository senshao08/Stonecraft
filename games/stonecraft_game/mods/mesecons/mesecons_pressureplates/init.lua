--[[

2017-01-06 modified by MrCerealGuy <mrcerealguy@gmx.de>
	exit if mod is deactivated

2017-05-20 MrCerealGuy: added intllib support

--]]

if core.skip_mod("mesecons") then return end

-- Load support for intllib.
local MP = minetest.get_modpath(minetest.get_current_modname())
local S, NS = dofile(MP.."/intllib.lua")

local pp_box_off = {
	type = "fixed",
	fixed = { -7/16, -8/16, -7/16, 7/16, -7/16, 7/16 },
}

local pp_box_on = {
	type = "fixed",
	fixed = { -7/16, -8/16, -7/16, 7/16, -7.5/16, 7/16 },
}

pp_on_timer = function (pos, elapsed)
	local node = minetest.get_node(pos)
	local basename = minetest.registered_nodes[node.name].pressureplate_basename

	-- This is a workaround for a strange bug that occurs when the server is started
	-- For some reason the first time on_timer is called, the pos is wrong
	if not basename then return end

	local objs   = minetest.get_objects_inside_radius(pos, 1)
	local two_below = vector.add(pos, vector.new(0, -2, 0))

	if objs[1] == nil and node.name == basename .. "_on" then
		minetest.set_node(pos, {name = basename .. "_off"})
		mesecon.receptor_off(pos, mesecon.rules.pplate)
	elseif node.name == basename .. "_off" then
		for k, obj in pairs(objs) do
			local objpos = obj:getpos()
			if objpos.y > pos.y-1 and objpos.y < pos.y then
				minetest.set_node(pos, {name = basename .. "_on"})
				mesecon.receptor_on(pos, mesecon.rules.pplate )
			end
		end
	end
	return true
end

-- Register a Pressure Plate
-- offstate:	name of the pressure plate when inactive
-- onstate:	name of the pressure plate when active
-- description:	description displayed in the player's inventory
-- tiles_off:	textures of the pressure plate when inactive
-- tiles_on:	textures of the pressure plate when active
-- image:	inventory and wield image of the pressure plate
-- recipe:	crafting recipe of the pressure plate

function mesecon.register_pressure_plate(basename, description, textures_off, textures_on, image_w, image_i, recipe)
	mesecon.register_node(basename, {
		drawtype = "nodebox",
		inventory_image = image_i,
		wield_image = image_w,
		paramtype = "light",
	    	description = description,
		pressureplate_basename = basename,
		on_timer = pp_on_timer,
		on_construct = function(pos)
			minetest.get_node_timer(pos):start(mesecon.setting("pplate_interval", 0.1))
		end,
	},{
		mesecons = {receptor = { state = mesecon.state.off, rules = mesecon.rules.pplate }},
		node_box = pp_box_off,
		selection_box = pp_box_off,
		groups = {snappy = 2, oddly_breakable_by_hand = 3},
		tiles = textures_off
	},{
		mesecons = {receptor = { state = mesecon.state.on, rules = mesecon.rules.pplate }},
		node_box = pp_box_on,
		selection_box = pp_box_on,
		groups = {snappy = 2, oddly_breakable_by_hand = 3, not_in_creative_inventory = 1},
		tiles = textures_on
	})

	minetest.register_craft({
		output = basename .. "_off",
		recipe = recipe,
	})
end

mesecon.register_pressure_plate(
	"mesecons_pressureplates:pressure_plate_wood",
	S("Wooden Pressure Plate"),
	{"jeija_pressure_plate_wood_off.png","jeija_pressure_plate_wood_off.png","jeija_pressure_plate_wood_off_edges.png"},
	{"jeija_pressure_plate_wood_on.png","jeija_pressure_plate_wood_on.png","jeija_pressure_plate_wood_on_edges.png"},
	"jeija_pressure_plate_wood_wield.png",
	"jeija_pressure_plate_wood_inv.png",
	{{"group:wood", "group:wood"}})

mesecon.register_pressure_plate(
	"mesecons_pressureplates:pressure_plate_stone",
	S("Stone Pressure Plate"),
	{"jeija_pressure_plate_stone_off.png","jeija_pressure_plate_stone_off.png","jeija_pressure_plate_stone_off_edges.png"},
	{"jeija_pressure_plate_stone_on.png","jeija_pressure_plate_stone_on.png","jeija_pressure_plate_stone_on_edges.png"},
	"jeija_pressure_plate_stone_wield.png",
	"jeija_pressure_plate_stone_inv.png",
	{{"default:cobble", "default:cobble"}})
