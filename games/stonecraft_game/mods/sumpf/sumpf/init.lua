--[[

2017-01-06 modified by MrCerealGuy <mrcerealguy@gmx.de>
	exit if mod is deactivated

2017-05-15 MrCerealGuy: added intllib support

2018-03-21 MrCerealGuy: disallow abms when the server is lagging

--]]

if core.skip_mod("swamps") then return end

local abm_allowed = true

-- Load support for intllib.
local MP = minetest.get_modpath(minetest.get_current_modname())
local S, NS = dofile(MP.."/intllib.lua")

local load_time_start = minetest.get_us_time()

minetest.register_craft({
	output = "sumpf:junglestonebrick",
	recipe = {
		{"sumpf:junglestone", "sumpf:junglestone"},
		{"sumpf:junglestone", "sumpf:junglestone"},
	}
})

minetest.register_craft({
	output = "sumpf:junglestone 4",
	recipe = {
		{"sumpf:junglestonebrick"},
	}
})

minetest.register_craft({
	output = "sumpf:roofing",
	recipe = {
		{"sumpf:gras", "default:junglegrass", "sumpf:gras"},
		{"default:junglegrass", "sumpf:gras", "default:junglegrass"},
		{"sumpf:gras", "default:junglegrass", "sumpf:gras"},
	}
})

minetest.register_craft({
	type = "cooking",
	output = "sumpf:junglestone",
	recipe = "sumpf:cobble",
})

minetest.register_node("sumpf:junglestone", {
	description = S("swamp stone"),
	tiles = {"sumpf_swampstone.png"},
	groups = {cracky=3},
	drop = "sumpf:cobble",
	sounds = default.node_sound_stone_defaults(),
})

minetest.register_node("sumpf:cobble", {
	description = S("swamp cobble stone"),
	tiles = {"sumpf_cobble.png"},
	groups = {cracky=3},
	sounds = default.node_sound_stone_defaults(),
})

minetest.register_node("sumpf:junglestonebrick", {
	description = S("swamp stone brick"),
	tiles = {"sumpf_swampstone_brick.png"},
	groups = {cracky=2, stone=1},
	sounds = default.node_sound_stone_defaults(),
})

minetest.register_node("sumpf:peat", {
	description = S("peat"),
	tiles = {"sumpf_peat.png"},
	groups = {crumbly=3, falling_node=1, sand=1, soil=1},
	sounds = default.node_sound_sand_defaults({
		footstep = {name="sumpf", gain=0.4},
		place = {name="sumpf", gain=0.4},
		dig = {name="sumpf", gain=0.4},
		dug = {name="default_dirt_footstep", gain=0.25}
	}),
})

minetest.register_node("sumpf:kohle", {
	description = S("coal ore"),
	tiles = {"sumpf_swampstone.png^default_mineral_coal.png"},
	groups = {cracky=3},
	drop = 'default:coal_lump',
	sounds = default.node_sound_stone_defaults(),
})

minetest.register_node("sumpf:eisen", {
	description = S("iron ore"),
	tiles = {"sumpf_swampstone.png^default_mineral_iron.png"},
	groups = {cracky=3},
	drop = 'default:iron_lump',
	sounds = default.node_sound_stone_defaults(),
})

minetest.register_node("sumpf:sumpf", {
	description = S("swamp"),
	--~ tiles = {"sumpf.png"},
	tiles = {{name="sumpf.png", align_style="world", scale=2}},
	groups = {crumbly=3, soil=1},
	sounds = default.node_sound_dirt_defaults({
		footstep = {name="sumpf", gain=0.4},
	}),
})

minetest.register_node("sumpf:sumpf2", {
	tiles = {"sumpf.png", "sumpf_swampstone.png",
		{name="sumpf_swampstone.png^sumpf_transition.png", tileable_vertical = false}
	},
	groups = {cracky=3, soil=1},
	drop = "sumpf:cobble",
	sounds = default.node_sound_stone_defaults({
		footstep = {name="sumpf", gain=0.4},
	}),
})

minetest.register_node("sumpf:roofing", {
	description = S("swamp grass roofing"),
	tiles = {"sumpf_roofing.png"},
	is_ground_content = false,
	groups = {snappy = 3, flammable = 1, level = 2},
	sounds = default.node_sound_leaves_defaults(),
	furnace_burntime = 13,
})


--------------------------fences------------------------

if minetest.register_fence then
	minetest.register_fence({fence_of = "sumpf:junglestone"})--, {drop = "sumpf:fence_cobble"})
	minetest.register_fence({fence_of = "sumpf:cobble"})
	minetest.register_fence({fence_of = "sumpf:junglestonebrick"})
	minetest.register_fence({fence_of = "sumpf:peat"})
	minetest.register_fence({fence_of = "sumpf:sumpf"})
	minetest.register_fence({fence_of = "sumpf:roofing"}, {furnace_burntime = 6.5})
end

--------------------------------------------------------



----------------------stairs and slabs------------------

if rawget(_G, "stairs") then
	stairs.register_stair_and_slab("swampstone", "sumpf:junglestone",
		{cracky=3},
		{"sumpf_swampstone.png"},
		S("swamp stone stair"),
		S("swamp stone slab"),
		default.node_sound_stone_defaults()
	)

	stairs.register_stair_and_slab("swampcobble", "sumpf:cobble",
		{cracky=3},
		{"sumpf_cobble.png"},
		S("swamp cobble stone stair"),
		S("swamp cobble stone slab"),
		default.node_sound_stone_defaults()
	)

	stairs.register_stair_and_slab("swampstonebrick", "sumpf:junglestonebrick",
		{cracky=2, stone=1},
		{"sumpf_swampstone_brick.png"},
		S("swamp stone brick stair"),
		S("swamp stone brick slab"),
		default.node_sound_stone_defaults()
	)

	stairs.register_stair_and_slab("sumpf_roofing", "sumpf:roofing",
		{snappy = 3, flammable = 1, level = 2},
		{"sumpf_roofing.png"},
		S("swamp grass roofing stair"),
		S("swamp grass roofing slab"),
		default.node_sound_leaves_defaults()
	)
end

---------------------------------------------------------



minetest.register_node("sumpf:gras", {
	description = S("swamp grass"),
	tiles = {"sumpfgrass.png"},
	inventory_image = "sumpfgrass.png",
	drawtype = "plantlike",
	paramtype = "light",
	waving = 1,
	selection_box = {type = "fixed",fixed = {-1/3, -1/2, -1/3, 1/3, -1/5, 1/3},},
	buildable_to = true,
	walkable = false,
	groups = {snappy=3,flammable=3,flora=1,attached_node=1},
	sounds = default.node_sound_leaves_defaults(),
	furnace_burntime = 1,
})

local ani = {type="vertical_frames", aspect_w=16, aspect_h=16, length=1.5}--17
minetest.register_node("sumpf:dirtywater_flowing", {
	drawtype = "flowingliquid",
	tiles = {"default_water.png"},
	special_tiles = {
		{name="sumpf_water_flowing.png", backface_culling=false,	animation=ani},
		{name="sumpf_water_flowing.png", backface_culling=true,	animation=ani}
	},
	alpha = WATER_ALPHA,
	paramtype = "light",
	walkable = false,
	pointable = false,
	diggable = false,
	buildable_to = true,
	drop = "",
	liquidtype = "flowing",
	liquid_alternative_flowing = "sumpf:dirtywater_flowing",
	liquid_alternative_source = "sumpf:dirtywater_source",
	liquid_viscosity = WATER_VISC,
	post_effect_color = {a=64, r=70, g=90, b=120},
	groups = {water=3, liquid=3, puts_out_fire=1, not_in_creative_inventory=1},
})

minetest.register_node("sumpf:dirtywater_source", {
	description = S("swampwater"),
	drawtype = "liquid",
	tiles = {
		{name="sumpf_water_source.png", animation=ani},
		{name="sumpf_water_source.png", animation=ani},
		{name="sumpf_water_flowing.png", animation=ani}
	},
	special_tiles = {{name="sumpf_water_source.png", animation=ani, backface_culling=false},},
	alpha = WATER_ALPHA,
	paramtype = "light",
	walkable = false,
	pointable = false,
	diggable = false,
	buildable_to = true,
	liquidtype = "source",
	liquid_alternative_flowing = "sumpf:dirtywater_flowing",
	liquid_alternative_source = "sumpf:dirtywater_source",
	liquid_viscosity = WATER_VISC,
	post_effect_color = {a=64, r=70, g=90, b=120},
	groups = {water=3, liquid=3, puts_out_fire=1},
})

if bucket then
	bucket.register_liquid(
		"sumpf:dirtywater_source",
		"sumpf:dirtywater_flowing",
		"sumpf:bucket_dirtywater",
		"bucket.png^sumpf_bucket_dirtywater.png",
		S("swampwater bucket")
	)
end


--sumpf = rawget(_G, "sumpf") or {}
local modpath = minetest.get_modpath"sumpf".."/"
dofile(modpath.."settings.lua")
dofile(modpath.."functions.lua")
dofile(modpath .. "birke.lua")
if sumpf.enable_mapgen then
	dofile(modpath .. "mapgen.lua")
end


-- legacy

minetest.register_alias("sumpf:pilz", "riesenpilz:brown")

-- disallow abms when the server is lagging
minetest.register_globalstep(function(dtime)
   if dtime > 0.5
   and abm_allowed then
      abm_allowed = false
      minetest.after(2, function() abm_allowed = true end)
      --minetest.chat_send_all(dtime)
   end
end)

local time = (minetest.get_us_time() - load_time_start) / 1000000
local msg = "[sumpf] loaded after ca. " .. time .. " seconds."
if time > 0.01 then
	print(msg)
else
	minetest.log("info", msg)
end
