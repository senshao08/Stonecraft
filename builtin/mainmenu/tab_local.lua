--Minetest
--Copyright (C) 2014 sapier
--
--This program is free software; you can redistribute it and/or modify
--it under the terms of the GNU Lesser General Public License as published by
--the Free Software Foundation; either version 2.1 of the License, or
--(at your option) any later version.
--
--This program is distributed in the hope that it will be useful,
--but WITHOUT ANY WARRANTY; without even the implied warranty of
--MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
--GNU Lesser General Public License for more details.
--
--You should have received a copy of the GNU Lesser General Public License along
--with this program; if not, write to the Free Software Foundation, Inc.,
--51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

local function current_game()
	local last_game_id = core.settings:get("menu_last_game")
	local game, index = gamemgr.find_by_gameid(last_game_id)

	return game
end

local function get_formspec(tabview, name, tabdata)
	local retval = ""

	local index = filterlist.get_current_index(menudata.worldlist,
				tonumber(core.settings:get("mainmenu_last_selected_world"))
				)

	retval = retval ..
			"button[4,4.15;2.8,0.5;world_create;".. fgettext("New") .. "]" ..
			"button[6.7,4.15;2.6,0.5;world_delete;".. fgettext("Delete") .. "]" ..
			"button[9.2,4.15;2.55,0.5;world_configure;".. fgettext("Configure") .. "]" ..
			"label[4,-0.25;".. fgettext("Select World:") .. "]"..
			"checkbox[0.25,0.25;cb_creative_mode;".. fgettext("Creative Mode") .. ";" ..
			dump(core.settings:get_bool("creative_mode")) .. "]"..
			"checkbox[0.25,0.7;cb_enable_damage;".. fgettext("Enable Damage") .. ";" ..
			dump(core.settings:get_bool("enable_damage")) .. "]"..
			"checkbox[0.25,1.15;cb_server;".. fgettext("Host Game") ..";" ..
			dump(core.settings:get_bool("enable_server")) .. "]" ..
			"textlist[4,0.25;7.5,3.7;sp_worlds;" ..
			menu_render_worldlist() ..
			";" .. index .. "]"

	if core.settings:get_bool("enable_server") then
		retval = retval ..
				"button[8.5,5;3.25,0.5;play;".. fgettext("Host Game") .. "]" ..
				"checkbox[0.25,1.6;cb_server_announce;" .. fgettext("Announce Server") .. ";" ..
				dump(core.settings:get_bool("server_announce")) .. "]" ..
				"label[0.25,2.2;" .. fgettext("Name/Password") .. "]" ..
				"field[0.55,3.2;3.5,0.5;te_playername;;" ..
				core.formspec_escape(core.settings:get("name")) .. "]" ..
				"pwdfield[0.55,4;3.5,0.5;te_passwd;]"

		local bind_addr = core.settings:get("bind_address")
		if bind_addr ~= nil and bind_addr ~= "" then
			retval = retval ..
				"field[0.55,5.2;2.25,0.5;te_serveraddr;" .. fgettext("Bind Address") .. ";" ..
				core.formspec_escape(core.settings:get("bind_address")) .. "]" ..
				"field[2.8,5.2;1.25,0.5;te_serverport;" .. fgettext("Port") .. ";" ..
				core.formspec_escape(core.settings:get("port")) .. "]"
		else
			retval = retval ..
				"field[0.55,5.2;3.5,0.5;te_serverport;" .. fgettext("Server Port") .. ";" ..
				core.formspec_escape(core.settings:get("port")) .. "]"
		end
	else
		retval = retval ..
				"button[8.5,5;3.25,0.5;play;".. fgettext("Play Game") .. "]"
	end

	return retval
end

local function main_button_handler(this, fields, name, tabdata)

	assert(name == "local")

	local world_doubleclick = false

	if fields["sp_worlds"] ~= nil then
		local event = core.explode_textlist_event(fields["sp_worlds"])
		local selected = core.get_textlist_index("sp_worlds")

		menu_worldmt_legacy(selected)

		if event.type == "DCL" then
			world_doubleclick = true
		end

		if event.type == "CHG" and selected ~= nil then
			core.settings:set("mainmenu_last_selected_world",
				menudata.worldlist:get_raw_index(selected))
			return true
		end
	end

	if menu_handle_key_up_down(fields,"sp_worlds","mainmenu_last_selected_world") then
		return true
	end

	if fields["cb_creative_mode"] then
		core.settings:set("creative_mode", fields["cb_creative_mode"])
		local selected = core.get_textlist_index("sp_worlds")
		menu_worldmt(selected, "creative_mode", fields["cb_creative_mode"])

		return true
	end

	if fields["cb_enable_damage"] then
		core.settings:set("enable_damage", fields["cb_enable_damage"])
		local selected = core.get_textlist_index("sp_worlds")
		menu_worldmt(selected, "enable_damage", fields["cb_enable_damage"])

		return true
	end

	if fields["cb_server"] then
		core.settings:set("enable_server", fields["cb_server"])

		return true
	end

	if fields["cb_server_announce"] then
		core.settings:set("server_announce", fields["cb_server_announce"])
		local selected = core.get_textlist_index("srv_worlds")
		menu_worldmt(selected, "server_announce", fields["cb_server_announce"])

		return true
	end

	if fields["play"] ~= nil or world_doubleclick or fields["key_enter"] then
		local selected = core.get_textlist_index("sp_worlds")
		gamedata.selected_world = menudata.worldlist:get_raw_index(selected)

		if core.settings:get_bool("enable_server") then
			if selected ~= nil and gamedata.selected_world ~= 0 then
				gamedata.playername     = fields["te_playername"]
				gamedata.password       = fields["te_passwd"]
				gamedata.port           = fields["te_serverport"]
				gamedata.address        = ""

				core.settings:set("port",gamedata.port)
				if fields["te_serveraddr"] ~= nil then
					core.settings:set("bind_address",fields["te_serveraddr"])
				end

				--update last game
				local world = menudata.worldlist:get_raw_element(gamedata.selected_world)
				if world then
					local game, index = gamemgr.find_by_gameid(world.gameid)
					core.settings:set("menu_last_game", game.id)
				end

				core.start()
			else
				gamedata.errormessage =
					fgettext("No world created or selected!")
			end
		else
			if selected ~= nil and gamedata.selected_world ~= 0 then
				gamedata.singleplayer = true
				core.start()
			else
				gamedata.errormessage =
					fgettext("No world created or selected!")
			end
			return true
		end
	end

	if fields["world_create"] ~= nil then
		local create_world_dlg = create_create_world_dlg(true)
		create_world_dlg:set_parent(this)
		this:hide()
		create_world_dlg:show()
		mm_texture.update("singleplayer",current_game())
		return true
	end

	if fields["world_delete"] ~= nil then
		local selected = core.get_textlist_index("sp_worlds")
		if selected ~= nil and
			selected <= menudata.worldlist:size() then
			local world = menudata.worldlist:get_list()[selected]
			if world ~= nil and
				world.name ~= nil and
				world.name ~= "" then
				local index = menudata.worldlist:get_raw_index(selected)
				local delete_world_dlg = create_delete_world_dlg(world.name,index)
				delete_world_dlg:set_parent(this)
				this:hide()
				delete_world_dlg:show()
				mm_texture.update("singleplayer",current_game())
			end
		end

		return true
	end

	if fields["world_configure"] ~= nil then
		local selected = core.get_textlist_index("sp_worlds")
		if selected ~= nil then
			local configdialog =
				create_configure_world_dlg(
						menudata.worldlist:get_raw_index(selected))

			if (configdialog ~= nil) then
				configdialog:set_parent(this)
				this:hide()
				configdialog:show()
				mm_texture.update("singleplayer",current_game())
			end
		end

		return true
	end
end

local function on_change(type, old_tab, new_tab)
	if (type == "ENTER") then
		local game = current_game()

		if game then
			menudata.worldlist:set_filtercriteria(game.id)
			core.set_topleft_text(game.name)
			mm_texture.update("singleplayer",game)
		end
	else
		menudata.worldlist:set_filtercriteria(nil)
		core.set_topleft_text("")
		mm_texture.update(new_tab,nil)
	end
end

--------------------------------------------------------------------------------
return {
	name = "local",
	caption = fgettext("Local Game"),
	cbf_formspec = get_formspec,
	cbf_button_handler = main_button_handler,
	on_change = on_change
}