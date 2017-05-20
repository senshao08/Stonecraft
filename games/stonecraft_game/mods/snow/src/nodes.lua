--[[

2017-05-15 MrCerealGuy: added intllib support

--]]


-- Load support for intllib.
local MP = minetest.get_modpath(minetest.get_current_modname())
local S, NS = dofile(MP.."/intllib.lua")

-- NODES

-- Pine Needles
local nodedef = {
	description = S("Pine Needles"),
	drawtype = "allfaces_optional",
	visual_scale = 1.3,
	tiles = {"snow_needles.png"},
	waving = 1,
	paramtype = "light",
	groups = {snappy=3, leafdecay=5},
	furnace_burntime = 1,
	drop = {
		max_items = 1,
		items = {
			{
				-- player will get sapling with 1/20 chance
				items = {'snow:sapling_pine'},
				rarity = 20,
			},
			{
				items = {'snow:needles'},
			}
		}
	},
	sounds = default.node_sound_leaves_defaults(),
}

--[[
If christmas_content is enabled, then this next part will override the pine needles' drop code
(in the code section above) and adds Xmas tree saplings to the items that are dropped.
The Xmas tree needles are registred and defined a farther down in this nodes.lua file.

~ LazyJ
]]
if snow.christmas_content then
	table.insert(nodedef.drop.items, 1, {
		-- player will get xmas tree with 1/120 chance
		items = {"snow:xmas_tree"},
		rarity = 120,
	})
end

minetest.register_node("snow:needles", table.copy(nodedef))

snow.register_on_configuring(function(name, v)
	if name == "christmas_content" then
		local drop = minetest.registered_nodes["snow:needles"].drop
		if v then
			table.insert(drop.items, 1, {
				items = {"snow:xmas_tree"},
				rarity = 120,
			})
		else
			table.remove(drop.items, 1)
		end
		minetest.override_item("snow:needles", {drop = drop})
	end
end)



	-- Christmas egg
	if minetest.global_exists"skins" then
		skins.add"character_snow_man"
	end


-- Decorated Pine Leaves

nodedef.description = S("Decorated @1", nodedef.description)
nodedef.light_source = 5
nodedef.waving = nil
if snow.disable_deco_needle_ani then
	nodedef.tiles = {"snow_needles_decorated.png"}
else
	-- Animated, "blinking lights" version. ~ LazyJ
	nodedef.inventory_image = minetest.inventorycube("snow_needles_decorated.png")
	nodedef.tiles = {
		{name="snow_needles_decorated_animated.png", animation={type="vertical_frames", aspect_w=16, aspect_h=16, length=20.0}}
	}
end
nodedef.drop.items[#nodedef.drop.items] = {items = {'snow:needles_decorated'}}

minetest.register_node("snow:needles_decorated", nodedef)


-- Saplings

nodedef = {
	description = S("Pine Sapling"),
	drawtype = "plantlike",
	visual_scale = 1.0,
	tiles = {"snow_sapling_pine.png"},
	inventory_image = "snow_sapling_pine.png",
	wield_image = "snow_sapling_pine.png",
	paramtype = "light",
	walkable = false,
	groups = {snappy=2,dig_immediate=3},
	furnace_burntime = 10,
	sounds = default.node_sound_defaults(),
}

-- Pine Sapling
minetest.register_node("snow:sapling_pine", table.copy(nodedef))

-- Xmas Tree Sapling
nodedef.description = S("Christmas Tree")
nodedef.tiles = {"snow_xmas_tree.png"}
nodedef.inventory_image = "snow_xmas_tree.png"
nodedef.wield_image = "snow_xmas_tree.png"

minetest.register_node("snow:xmas_tree", nodedef)


nodedef = {
	description = S("Star"),
	drawtype = "plantlike",
	tiles = {"snow_star.png"},
	inventory_image = "snow_star.png",
	wield_image = "snow_star.png",
	paramtype = "light",
	walkable = false,
	-- Don't want the ornament breaking too easily because you have to punch it to turn it on and off. ~ LazyJ
	groups = {cracky=1, crumbly=1, choppy=1, oddly_breakable_by_hand=1},
	-- Breaking "glass" sound makes it sound like a real, broken, Xmas tree ornament (Sorry, Mom!).  ;)-  ~ LazyJ
	sounds = default.node_sound_glass_defaults({dig = {name="default_glass_footstep", gain=0.2}}),
	on_punch = function(pos, node) -- Added a "lit" star that can be punched on or off depending on your preference. ~ LazyJ
		node.name = "snow:star_lit"
		minetest.set_node(pos, node)
		nodeupdate(pos)
	end,
}

minetest.log("error", S("Star"))

-- Star on Xmas Trees
minetest.register_node("snow:star", table.copy(nodedef))

-- Star (Lit Version) on Xmas Trees
nodedef.description = S("@1 Lighted", nodedef.description)
nodedef.light_source = LIGHT_MAX
nodedef.tiles = {"snow_star_lit.png"}
nodedef.drop = "snow:star"
nodedef.groups.not_in_creative_inventory = 1
nodedef.on_punch = function(pos, node)
	node.name = "snow:star"
	minetest.set_node(pos, node)
	nodeupdate(pos)
end

minetest.register_node("snow:star_lit", nodedef)



-- Plants

-- Moss
minetest.register_node("snow:moss", {
	description = S("Moss"),
	inventory_image = "snow_moss.png",
	tiles = {"snow_moss.png"},
	drawtype = "signlike",
	paramtype = "light",
	paramtype2 = "wallmounted",
	walkable = false,
	selection_box = {
		type = "wallmounted",
	},
	is_ground_content = true,
	groups = {crumbly=3, attached_node=1},
	furnace_burntime = 3,
})

-- Shrub(s)
nodedef = {
	description = S("Snow Shrub"),
	tiles = {"snow_shrub.png"},
	inventory_image = "snow_shrub.png",
	wield_image = "snow_shrub.png",
	drawtype = "plantlike",
	paramtype = "light",
	waving = 1,
	sunlight_propagates = true,
	walkable = false,
	is_ground_content = true,
	buildable_to = true,
	groups = {snappy=3,flammable=3,attached_node=1},
	sounds = default.node_sound_leaves_defaults(),
	selection_box = {
		type = "fixed",
		fixed = {-0.3, -0.5, -0.3, 0.3, -5/16, 0.3},
	},
	furnace_burntime = 5,
}
minetest.register_node("snow:shrub", table.copy(nodedef))

nodedef.tiles = {"snow_shrub.png^snow_shrub_covering.png"}
nodedef.inventory_image = "snow_shrub.png^snow_shrub_covering.png"
nodedef.wield_image = "snow_shrub.png^snow_shrub_covering.png"
nodedef.paramtype2 = "degrotate"
nodedef.drop = "snow:shrub"
nodedef.furnace_burntime = 3
minetest.register_node("snow:shrub_covered", nodedef)

-- Flowers
if rawget(_G, "flowers") then
	-- broken flowers
	snow.known_plants = {}
	for _,name in pairs({"dandelion_yellow", "geranium", "rose", "tulip", "dandelion_white", "viola"}) do
		local flowername = "flowers:"..name
		local newname = "snow:flower_"..name
		local flower = minetest.registered_nodes[flowername]
		minetest.register_node(newname, {
			drawtype = "plantlike",
			tiles = { "snow_" .. name .. ".png" },
			sunlight_propagates = true,
			paramtype = "light",
			paramtype2 = "degrotate",
			walkable = false,
			drop = "",
			groups = {snappy=3, attached_node = 1},
			sounds = default.node_sound_leaves_defaults(),
			selection_box = flower.selection_box
		})
		snow.known_plants[minetest.get_content_id(flowername)] = minetest.get_content_id(newname)
	end
end

-- Leaves
local leaves = minetest.registered_nodes["default:leaves"]
nodedef = {
	description = S("Snow Leaves"),
	tiles = {"snow_leaves.png"},
	waving = 1,
	visual_scale = leaves.visual_scale,
	drawtype = leaves.drawtype,
	paramtype = leaves.paramtype,
	groups = leaves.groups,
	drop = leaves.drop,
	sounds = leaves.sounds,
}
nodedef.groups.flammable = 1

minetest.register_node("snow:leaves", nodedef)
snow.known_plants[minetest.get_content_id("default:leaves")] = minetest.get_content_id("snow:leaves")

local apple = minetest.registered_nodes["default:apple"]
nodedef = {
	description = S("Snow Apple"),
	drawtype = "plantlike",
	tiles = {"snow_apple.png"},
	paramtype = "light",
	paramtype2 = "degrotate",
	walkable = false,
	sunlight_propagates = apple.sunlight_propagates,
	selection_box = apple.selection_box,
	groups = apple.groups,
	sounds = apple.sounds,
	drop = apple.drop,
}
nodedef.groups.flammable = 1

minetest.register_node("snow:apple", nodedef)
snow.known_plants[minetest.get_content_id("default:apple")] = minetest.get_content_id("snow:apple")

-- TODO
snow.known_plants[minetest.get_content_id("default:jungleleaves")] = minetest.get_content_id("default:jungleleaves")



local function snow_onto_dirt(pos)
	pos.y = pos.y - 1
	local node = minetest.get_node(pos)
	if node.name == "default:dirt_with_grass"
	or node.name == "default:dirt" then
		node.name = "default:dirt_with_snow"
		minetest.set_node(pos, node)
	end
end



-- Bricks

nodedef = {
	description = S("Snow Brick"),
	tiles = {"snow_snow_brick.png"},
	is_ground_content = true,
	--freezemelt = "default:water_source", -- deprecated
	liquidtype = "none",
	paramtype = "light",
	sunlight_propagates = true,
	paramtype2 = "facedir", -- Allow blocks to be rotated with the screwdriver or
	-- by player position. ~ LazyJ
	 -- I made this a little harder to dig than snow blocks because
	 -- I imagine snow brick as being much more dense and solid than fluffy snow. ~ LazyJ
	groups = {cracky=2, crumbly=2, choppy=2, oddly_breakable_by_hand=2, melts=1, icemaker=1, cooks_into_ice=1},
	 --Let's use the new snow sounds instead of the old grass sounds. ~ LazyJ
	sounds = default.node_sound_dirt_defaults({
		footstep = {name="default_snow_footstep", gain=0.25},
		dig = {name="default_dig_crumbly", gain=0.4},
		dug = {name="default_snow_footstep", gain=0.75},
		place = {name="default_place_node", gain=1.0}
	}),
 	-- The "on_construct" part below, thinking in terms of layers, dirt_with_snow could also
 	-- double as dirt_with_frost which adds subtlety to the winterscape. ~ LazyJ
	on_construct = snow_onto_dirt
}

-- Snow Brick
minetest.register_node("snow:snow_brick", table.copy(nodedef))


-- hard Ice Brick, original texture from LazyJ
local ibdef = table.copy(nodedef)
ibdef.description = S("Ice Brick")
ibdef.tiles = {"snow_ice_brick.png"}
ibdef.use_texture_alpha = true
ibdef.drawtype = "glasslike"
ibdef.groups = {cracky=1, crumbly=1, choppy=1, melts=1}
ibdef.sounds = default.node_sound_glass_defaults({
	dug = {name="default_hard_footstep", gain=1}
})

minetest.register_node("snow:ice_brick", ibdef)


-- Snow Cobble  ~ LazyJ
-- Described as Icy Snow
nodedef.description = S("Icy Snow")
nodedef.tiles = {"snow_snow_cobble.png"}

minetest.register_node("snow:snow_cobble", nodedef)



-- Override Default Nodes to Add Extra Functions

minetest.override_item("default:ice", {
	use_texture_alpha = true,
	param2 = 0, --param2 is reserved for how much ice will freezeover.
	sunlight_propagates = true, -- necessary for dirt_with_grass/snow/just dirt ABMs
	drawtype = "glasslike",
	inventory_image  = minetest.inventorycube"default_ice.png".."^[brighten",
	liquidtype = "none",
	 -- I made this a lot harder to dig than snow blocks because ice is much more dense
	 -- and solid than fluffy snow. ~ LazyJ
	groups = {cracky=2, crumbly=1, choppy=1, --[[oddly_breakable_by_hand=1,]] melts=1},
	on_construct = snow_onto_dirt,
	liquids_pointable = true,
	--Make ice freeze over when placed by a maximum of 10 blocks.
	after_place_node = function(pos)
		minetest.set_node(pos, {name="default:ice", param2=math.random(0,10)})
	end
})


minetest.override_item("default:snowblock", {
	-- LazyJ to make dirt below change to dirt_with_snow (see default, nodes.lua, dirt ABM)
	liquidtype = "none",
	paramtype = "light",
	sunlight_propagates = true,
	 -- Snow blocks should be easy to dig because they are just fluffy snow. ~ LazyJ
	groups = {cracky=3, crumbly=3, choppy=3, oddly_breakable_by_hand=3, melts=1, icemaker=1, cooks_into_ice=1, falling_node=1},
	--drop = "snow:snow_cobble",
	on_construct = snow_onto_dirt
		-- Thinking in terms of layers, dirt_with_snow could also double as
		-- dirt_with_frost which adds subtlety to the winterscape. ~ LazyJ, 2014_04_04
})


minetest.override_item("default:snow", {
	drop = {
		max_items = 2,
		items = {
			{items = {'snow:moss'}, rarity = 20,},
			{items = {'default:snow'},}
		}
	},
	leveled = 7,
	node_box = {
		type = "leveled",
		fixed = {
			{-0.5, -0.5, -0.5, 0.5, -0.5, 0.5},
		},
	},
	groups = {cracky=3, crumbly=3, choppy=3, oddly_breakable_by_hand=3, falling_node=1, melts=2, float=1},
	sunlight_propagates = true,
	walkable = true,
	node_placement_prediction = "",
	on_construct = function(pos)
		pos.y = pos.y-1
		local node = minetest.get_node(pos)
		if node.name == "default:dirt_with_grass"
		or node.name == "default:dirt" then
			node.name = "default:dirt_with_snow"
			minetest.set_node(pos, node)
		end
	end,
	--Handle node drops due to node level.
	on_dig = function(pos, node, digger)
		local level = minetest.get_node_level(pos)
		minetest.node_dig(pos, node, digger)
		if minetest.get_node(pos).name ~= node.name then
			local inv = digger:get_inventory()
			if not inv then
				return
			end
			local left = inv:add_item("main", "default:snow "..tostring(level/7-1))
			if not left:is_empty() then
				minetest.add_item({
					x = pos.x + math.random()/2-0.25,
					y = pos.y + math.random()/2-0.25,
					z = pos.z + math.random()/2-0.25,
				}, left)
			end
		end
	end,
	--Manage snow levels.
	on_place = function(itemstack, placer, pointed_thing)
		local under = pointed_thing.under
		local oldnode_under = minetest.get_node_or_nil(under)
		local above = pointed_thing.above

		if not oldnode_under
		or not above then
			return
		end

		local olddef_under = ItemStack({name=oldnode_under.name}):get_definition()
		olddef_under = olddef_under or minetest.nodedef_default

		local place_to
		-- If node under is buildable_to, place into it instead (eg. snow)
		if olddef_under.buildable_to then
			place_to = under
		else
			-- Place above pointed node
			place_to = above
		end

		local level = minetest.get_node_level(place_to)
		if level == 63 then
			minetest.set_node(place_to, {name="default:snowblock"})
		else
			minetest.set_node_level(place_to, level+7)
		end

		if minetest.get_node(place_to).name ~= "default:snow" then
			local itemstack, placed = minetest.item_place_node(itemstack, placer, pointed_thing)
			return itemstack, placed
		end

		itemstack:take_item()

		return itemstack
	end,
	on_use = snow.shoot_snowball
})



-- Do stairs files

local path = minetest.get_modpath"snow".."/src/"

dofile(path.."basic_stairs_slabs.lua")

if minetest.global_exists"stairsplus"
and minetest.get_modpath"moreblocks" then
	dofile(path.."stairsplus.lua")
end
