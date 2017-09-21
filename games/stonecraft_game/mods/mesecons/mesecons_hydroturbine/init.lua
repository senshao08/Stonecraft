--[[

2017-01-06 modified by MrCerealGuy <mrcerealguy@gmx.de>
	exit if mod is deactivated

2017-05-17 MrCerealGuy: added intllib support

2017-09-21 modified by MrCerealGuy <mrcerealguy@gmx.de>
	replaced nodeupdate(pos) (deprecated) with minetest.check_for_falling(pos)

--]]

if core.skip_mod("mesecons") then return end

-- Load support for intllib.
local MP = minetest.get_modpath(minetest.get_current_modname())
local S, NS = dofile(MP.."/intllib.lua")

-- HYDRO_TURBINE
-- Water turbine:
-- Active if flowing >water< above it
-- (does not work with other liquids)

minetest.register_node("mesecons_hydroturbine:hydro_turbine_off", {
	drawtype = "mesh",
	mesh = "jeija_hydro_turbine.obj",
	tiles = {
		"jeija_hydro_turbine_sides_off.png",
		"jeija_hydro_turbine_top_bottom.png",
		"jeija_hydro_turbine_turbine_top_bottom.png",
		"jeija_hydro_turbine_turbine_misc.png"
	},
	inventory_image = "jeija_hydro_turbine_inv.png",
	wield_scale = {x=0.75, y=0.75, z=0.75},
	groups = {dig_immediate=2},
	description=S("Water Turbine"),
	paramtype = "light",
	selection_box = {
		type = "fixed",
		fixed = { -0.5, -0.5, -0.5, 0.5, 1.5, 0.5 },
	},
	sounds = default.node_sound_stone_defaults(),
	mesecons = {receptor = {
		state = mesecon.state.off
	}}
})

minetest.register_node("mesecons_hydroturbine:hydro_turbine_on", {
	drawtype = "mesh",
	mesh = "jeija_hydro_turbine.obj",
	wield_scale = {x=0.75, y=0.75, z=0.75},
	tiles = {
		"jeija_hydro_turbine_sides_on.png",
		"jeija_hydro_turbine_top_bottom.png",
		"jeija_hydro_turbine_turbine_top_bottom.png",
		"jeija_hydro_turbine_turbine_misc.png"
	},
	inventory_image = "jeija_hydro_turbine_inv.png",
	drop = "mesecons_hydroturbine:hydro_turbine_off 1",
	groups = {dig_immediate=2,not_in_creative_inventory=1},
	description=S("Water Turbine"),
	paramtype = "light",
	selection_box = {
		type = "fixed",
		fixed = { -0.5, -0.5, -0.5, 0.5, 1.5, 0.5 },
	},
	sounds = default.node_sound_stone_defaults(),
	mesecons = {receptor = {
		state = mesecon.state.on
	}}
})


minetest.register_abm({
nodenames = {"mesecons_hydroturbine:hydro_turbine_off"},
	interval = 1,
	chance = 1,
	action = function(pos, node, active_object_count, active_object_count_wider)
		local waterpos={x=pos.x, y=pos.y+1, z=pos.z}
		if minetest.get_node(waterpos).name=="default:water_flowing" then
			minetest.set_node(pos, {name="mesecons_hydroturbine:hydro_turbine_on"})
			--nodeupdate(pos)  MrCerealGuy: nodeupdate is deprecated
			minetest.check_for_falling(pos)
			mesecon.receptor_on(pos)
		end
	end,
})

minetest.register_abm({
nodenames = {"mesecons_hydroturbine:hydro_turbine_on"},
	interval = 1,
	chance = 1,
	action = function(pos, node, active_object_count, active_object_count_wider)
		local waterpos={x=pos.x, y=pos.y+1, z=pos.z}
		if minetest.get_node(waterpos).name~="default:water_flowing" then
			minetest.set_node(pos, {name="mesecons_hydroturbine:hydro_turbine_off"})
			--nodeupdate(pos)  MrCerealGuy: nodeupdate is deprecated
			minetest.check_for_falling(pos)
			mesecon.receptor_off(pos)
		end
	end,
})

minetest.register_craft({
	output = "mesecons_hydroturbine:hydro_turbine_off 2",
	recipe = {
	{"","default:stick", ""},
	{"default:stick", "default:steel_ingot", "default:stick"},
	{"","default:stick", ""},
	}
})

