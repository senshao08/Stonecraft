--[[

2017-01-06 modified by MrCerealGuy <mrcerealguy@gmx.de>
	exit if mod is deactivated

--]]

local DIR_DELIM = DIR_DELIM or "/"
local world_file = minetest.get_worldpath()..DIR_DELIM.."world.mt"
local world_conf = Settings(world_file)
local enable_digilines = world_conf:get("enable_digilines")

if enable_digilines ~= nil and enable_digilines == "false" then
	minetest.log("info", "[mesecons:digilines] skip loading mod.")
	return
end

-- --------------------------------------------------------------------------------------------------------

digiline = {}

local modpath = minetest.get_modpath("digilines")
dofile(modpath .. "/presetrules.lua")
dofile(modpath .. "/util.lua")
dofile(modpath .. "/internal.lua")
dofile(modpath .. "/wires_common.lua")
dofile(modpath .. "/wire_std.lua")

function digiline:receptor_send(pos, rules, channel, msg)
	local checked = {}
	checked[tostring(pos.x).."_"..tostring(pos.y).."_"..tostring(pos.z)] = true -- exclude itself
	for _,rule in ipairs(rules) do
		if digiline:rules_link(pos, digiline:addPosRule(pos, rule)) then
			digiline:transmit(digiline:addPosRule(pos, rule), channel, msg, checked)
		end
	end
end

minetest.register_craft({
	output = 'digilines:wire_std_00000000 2',
	recipe = {
		{'mesecons_materials:fiber', 'mesecons_materials:fiber', 'mesecons_materials:fiber'},
		{'mesecons_insulated:insulated_off', 'mesecons_insulated:insulated_off', 'default:gold_ingot'},
		{'mesecons_materials:fiber', 'mesecons_materials:fiber', 'mesecons_materials:fiber'},
	}
})

-- former submods
if minetest.is_yes(minetest.setting_get("digilines_enable_inventory") or true) then
	dofile(modpath .. "/inventory.lua")
end

if minetest.is_yes(minetest.setting_get("digilines_enable_lcd") or true) then
	dofile(modpath .. "/lcd.lua")
end

if minetest.is_yes(minetest.setting_get("digilines_enable_lightsensor") or true) then
	dofile(modpath .. "/lightsensor.lua")
end

if minetest.is_yes(minetest.setting_get("digilines_enable_rtc") or true) then
	dofile(modpath .. "/rtc.lua")
end
