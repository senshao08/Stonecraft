/* WARNING: This file was automatically generated by lua2c. */

#ifdef __cplusplus
extern "C" {
#endif
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#ifdef __cplusplus
}
#endif
#include <stdio.h>
#include <stdlib.h>


#include <string.h>


/* pushes new closure table onto the stack, using closure table at
 * given index as its parent */
static void lc_newclosuretable(lua_State * L, int idx) {

  lua_newtable(L);
  lua_pushvalue(L,idx);
  lua_rawseti(L,-2,0);


}

#include <assert.h>

/* __sub metamethod handler.
 * warning: assumes indices in range LUA_REGISTRYINDEX < x < 0 are relative. */
static void lc_sub(lua_State * L, int idxa, int idxb) {
  if (lua_isnumber(L,idxa) && lua_isnumber(L,idxb)) {
    lua_pushnumber(L,lua_tonumber(L,idxa) - lua_tonumber(L,idxb));
  }
  else {
    if (luaL_getmetafield(L,idxa,"__sub")||luaL_getmetafield(L,idxb,"__sub")) {
      lua_pushvalue(L,idxa < 0 && idxa > LUA_REGISTRYINDEX ? idxa-1 : idxa);
      lua_pushvalue(L,idxb < 0 && idxb > LUA_REGISTRYINDEX ? idxb-2 : idxb);
      lua_call(L,2,1);
    }
    else {
      luaL_error(L, "attempt to perform arithmetic");
    }
  }
}


/* gets upvalue with ID varid by consulting upvalue table at index
 * tidx for the upvalue table at given nesting level. */
static void lc_getupvalue(lua_State * L, int tidx, int level, int varid) {
  if (level == 0) {
    lua_rawgeti(L,tidx,varid);
  }
  else {
    lua_pushvalue(L,tidx);
    while (--level >= 0) {
      lua_rawgeti(L,tidx,0); /* 0 links to parent table */
      lua_remove(L,-2);
      tidx = -1;
    }
    lua_rawgeti(L,-1,varid);
    lua_remove(L,-2);
  }
}


/* __add metamethod handler.
 * warning: assumes indices in range LUA_REGISTRYINDEX < x < 0 are relative. */
static void lc_add(lua_State * L, int idxa, int idxb) {
  if (lua_isnumber(L,idxa) && lua_isnumber(L,idxb)) {
    lua_pushnumber(L,lua_tonumber(L,idxa) + lua_tonumber(L,idxb));
  }
  else {
    if (luaL_getmetafield(L,idxa,"__add")||luaL_getmetafield(L,idxb,"__add")) {
      lua_pushvalue(L,idxa < 0 && idxa > LUA_REGISTRYINDEX ? idxa-1 : idxa);
      lua_pushvalue(L,idxb < 0 && idxb > LUA_REGISTRYINDEX ? idxb-2 : idxb);
      lua_call(L,2,1);
    }
    else {
      luaL_error(L, "attempt to perform arithmetic");
    }
  }
}


/* function() */
static int lcf2 (lua_State * L) {
  enum { lc_nformalargs = 0 };
  lua_settop(L,0);
  
  /* minetest.add_particlespawner(
   * 					200, --amount
   * 					0.1, --time
   * 					{x=pos.x-1, y=pos.y-1, z=pos.z-1}, --minpos
   * 					{x=pos.x+1, y=pos.y+1, z=pos.z+1}, --maxpos
   * 					{x=-0, y=-0, z=-0}, --minvel
   * 					{x=1, y=1, z=1}, --maxvel
   * 					{x=-0.5,y=5,z=-0.5}, --minacc
   * 					{x=0.5,y=5,z=0.5}, --maxacc
   * 					0.1, --minexptime
   * 					1, --maxexptime
   * 					3, --minsize
   * 					4, --maxsize
   * 					false, --collisiondetection
   * 					"tnt_smoke.png" --texture
   * 				) */
  lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
  lua_pushliteral(L,"add_particlespawner");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushnumber(L,200);
  lua_pushnumber(L,0.1);
  lua_createtable(L,0,3);
  lua_pushliteral(L,"x");
  lc_getupvalue(L,lua_upvalueindex(1),0,1);
  lua_pushliteral(L,"x");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushnumber(L,1);
  lc_sub(L,-2,-1);
  lua_remove(L,-2);
  lua_remove(L,-2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"y");
  lc_getupvalue(L,lua_upvalueindex(1),0,1);
  lua_pushliteral(L,"y");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushnumber(L,1);
  lc_sub(L,-2,-1);
  lua_remove(L,-2);
  lua_remove(L,-2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"z");
  lc_getupvalue(L,lua_upvalueindex(1),0,1);
  lua_pushliteral(L,"z");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushnumber(L,1);
  lc_sub(L,-2,-1);
  lua_remove(L,-2);
  lua_remove(L,-2);
  lua_rawset(L,-3);
  lua_createtable(L,0,3);
  lua_pushliteral(L,"x");
  lc_getupvalue(L,lua_upvalueindex(1),0,1);
  lua_pushliteral(L,"x");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushnumber(L,1);
  lc_add(L,-2,-1);
  lua_remove(L,-2);
  lua_remove(L,-2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"y");
  lc_getupvalue(L,lua_upvalueindex(1),0,1);
  lua_pushliteral(L,"y");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushnumber(L,1);
  lc_add(L,-2,-1);
  lua_remove(L,-2);
  lua_remove(L,-2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"z");
  lc_getupvalue(L,lua_upvalueindex(1),0,1);
  lua_pushliteral(L,"z");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushnumber(L,1);
  lc_add(L,-2,-1);
  lua_remove(L,-2);
  lua_remove(L,-2);
  lua_rawset(L,-3);
  lua_createtable(L,0,3);
  lua_pushliteral(L,"x");
  lua_pushnumber(L,-0);
  lua_rawset(L,-3);
  lua_pushliteral(L,"y");
  lua_pushnumber(L,-0);
  lua_rawset(L,-3);
  lua_pushliteral(L,"z");
  lua_pushnumber(L,-0);
  lua_rawset(L,-3);
  lua_createtable(L,0,3);
  lua_pushliteral(L,"x");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"y");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"z");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_createtable(L,0,3);
  lua_pushliteral(L,"x");
  lua_pushnumber(L,-0.5);
  lua_rawset(L,-3);
  lua_pushliteral(L,"y");
  lua_pushnumber(L,5);
  lua_rawset(L,-3);
  lua_pushliteral(L,"z");
  lua_pushnumber(L,-0.5);
  lua_rawset(L,-3);
  lua_createtable(L,0,3);
  lua_pushliteral(L,"x");
  lua_pushnumber(L,0.5);
  lua_rawset(L,-3);
  lua_pushliteral(L,"y");
  lua_pushnumber(L,5);
  lua_rawset(L,-3);
  lua_pushliteral(L,"z");
  lua_pushnumber(L,0.5);
  lua_rawset(L,-3);
  lua_pushnumber(L,0.1);
  lua_pushnumber(L,1);
  lua_pushnumber(L,3);
  lua_pushnumber(L,4);
  lua_pushboolean(L,0);
  lua_pushliteral(L,"tnt_smoke.png");
  lua_call(L,14,0);
  assert(lua_gettop(L) == 0);
  
  /* local pos1 = {x=pos.x+math.random(-1,1), y=pos.y+0.5, z=pos.z+math.random(-1,1)} */
  lua_createtable(L,0,3);
  lua_pushliteral(L,"x");
  lc_getupvalue(L,lua_upvalueindex(1),0,1);
  lua_pushliteral(L,"x");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_getfield(L,LUA_ENVIRONINDEX,"math");
  lua_pushliteral(L,"random");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushnumber(L,-1);
  lua_pushnumber(L,1);
  lua_call(L,2,1);
  lc_add(L,-2,-1);
  lua_remove(L,-2);
  lua_remove(L,-2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"y");
  lc_getupvalue(L,lua_upvalueindex(1),0,1);
  lua_pushliteral(L,"y");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushnumber(L,0.5);
  lc_add(L,-2,-1);
  lua_remove(L,-2);
  lua_remove(L,-2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"z");
  lc_getupvalue(L,lua_upvalueindex(1),0,1);
  lua_pushliteral(L,"z");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_getfield(L,LUA_ENVIRONINDEX,"math");
  lua_pushliteral(L,"random");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushnumber(L,-1);
  lua_pushnumber(L,1);
  lua_call(L,2,1);
  lc_add(L,-2,-1);
  lua_remove(L,-2);
  lua_remove(L,-2);
  lua_rawset(L,-3);
  assert(lua_gettop(L) == 1);
  
  /* local pos2 = {x=pos.x+math.random(-1,1), y=pos.y+0.5, z=pos.z+math.random(-1,1)} */
  lua_createtable(L,0,3);
  lua_pushliteral(L,"x");
  lc_getupvalue(L,lua_upvalueindex(1),0,1);
  lua_pushliteral(L,"x");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_getfield(L,LUA_ENVIRONINDEX,"math");
  lua_pushliteral(L,"random");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushnumber(L,-1);
  lua_pushnumber(L,1);
  lua_call(L,2,1);
  lc_add(L,-2,-1);
  lua_remove(L,-2);
  lua_remove(L,-2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"y");
  lc_getupvalue(L,lua_upvalueindex(1),0,1);
  lua_pushliteral(L,"y");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushnumber(L,0.5);
  lc_add(L,-2,-1);
  lua_remove(L,-2);
  lua_remove(L,-2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"z");
  lc_getupvalue(L,lua_upvalueindex(1),0,1);
  lua_pushliteral(L,"z");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_getfield(L,LUA_ENVIRONINDEX,"math");
  lua_pushliteral(L,"random");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushnumber(L,-1);
  lua_pushnumber(L,1);
  lua_call(L,2,1);
  lc_add(L,-2,-1);
  lua_remove(L,-2);
  lua_remove(L,-2);
  lua_rawset(L,-3);
  assert(lua_gettop(L) == 2);
  
  /* minetest.add_entity(pos1, "nssm:masticone") */
  lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
  lua_pushliteral(L,"add_entity");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushvalue(L,1);
  lua_pushliteral(L,"nssm:masticone");
  lua_call(L,2,0);
  assert(lua_gettop(L) == 2);
  
  /* minetest.add_entity(pos2, "nssm:masticone") */
  lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
  lua_pushliteral(L,"add_entity");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushvalue(L,2);
  lua_pushliteral(L,"nssm:masticone");
  lua_call(L,2,0);
  assert(lua_gettop(L) == 2);
  return 0;
}


/* function(self, pos) */
static int lcf3 (lua_State * L) {
  enum { lc_nformalargs = 2 };
  lua_settop(L,2);
  lc_newclosuretable(L,lua_upvalueindex(1));
  enum { lc1 = 3 };
  assert((lua_gettop(L) == lc1));
  lua_pushvalue(L,2);
  lua_rawseti(L,-2,1);
  
  /* core.after(2, function()
   * 				minetest.add_particlespawner(
   * 					200, --amount
   * 					0.1, --time
   * 					{x=pos.x-1, y=pos.y-1, z=pos.z-1}, --minpos
   * 					{x=pos.x+1, y=pos.y+1, z=pos.z+1}, --maxpos
   * 					{x=-0, y=-0, z=-0}, --minvel
   * 					{x=1, y=1, z=1}, --maxvel
   * 					{x=-0.5,y=5,z=-0.5}, --minacc
   * 					{x=0.5,y=5,z=0.5}, --maxacc
   * 					0.1, --minexptime
   * 					1, --maxexptime
   * 					3, --minsize
   * 					4, --maxsize
   * 					false, --collisiondetection
   * 					"tnt_smoke.png" --texture
   * 				)
   * 				local pos1 = {x=pos.x+math.random(-1,1), y=pos.y+0.5, z=pos.z+math.random(-1,1)}
   * 				local pos2 = {x=pos.x+math.random(-1,1), y=pos.y+0.5, z=pos.z+math.random(-1,1)}
   * 				minetest.add_entity(pos1, "nssm:masticone")
   * 				minetest.add_entity(pos2, "nssm:masticone")
   *     end) */
  lua_getfield(L,LUA_ENVIRONINDEX,"core");
  lua_pushliteral(L,"after");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushnumber(L,2);
  lua_pushvalue(L,lc1);
  lua_pushcclosure(L,lcf2,1);
  lua_call(L,2,0);
  assert(lua_gettop(L) == 3);
  return 0;
}


/* name: (main)
 * function(...) */
static int lcf_main (lua_State * L) {
  enum { lc_nformalargs = 0 };
  #ifndef NDEBUG
  const int lc_nactualargs = lua_gettop(L);
  #endif
  #ifndef NDEBUG
  const int lc_nextra = (lc_nactualargs - lc_nformalargs);
  #endif
  
  /* nssm:register_mob("nssm:masticone", {
   * 	type = "monster",
   * 	hp_max = 15,
   * 	hp_min = 14,
   * 	collisionbox = {-0.45, 0.00, -0.45, 0.45, 0.40, 0.45},
   * 	visual = "mesh",
   * 	mesh = "masticone.x",
   * 	textures = {{"masticone.png"}},
   * 	visual_size = {x=4, y=4},
   * 	makes_footstep_sound = true,
   * 	view_range = 15,
   * 	lifetimer = 500,
   * 	fear_height = 4,
   * 	rotate = 270,
   * 	walk_velocity = 1.5,
   * 	run_velocity = 2.5,
   *   sounds = {
   * 		random = "masticone",
   * 	},
   * 	damage = 5,
   * 	jump = true,
   * 	drops = {
   * 		{name = "nssm:life_energy",
   * 		chance = 1,
   * 		min = 7,
   * 		max = 8,},
   * 		{name = "nssm:masticone_fang",
   * 		chance = 1,
   * 		min = 1,
   * 		max = 2,},
   * 		{name = "nssm:masticone_skull_fragments",
   * 		chance = 2,
   * 		min = 1,
   * 		max = 2,},
   * 	},
   * 	armor = 60,
   * 	drawtype = "front",
   * 	water_damage = 0,
   * 	lava_damage = 5,
   * 	floats=0,
   * 	hydra = true,
   * 	light_damage = 0,
   * 	on_rightclick = nil,
   * 	attack_type = "dogfight",
   * 	reach =1.5,
   * 	animation = {
   * 		speed_normal = 20,
   * 		speed_run = 25,
   * 		stand_start = 80,
   * 		stand_end = 140,
   * 		walk_start = 20,
   * 		walk_end = 40,
   * 		run_start = 20,
   * 		run_end = 40,
   * 		punch_start = 150,
   * 		punch_end = 180,
   * 	},
   * 	on_die = function(self, pos)
   * 			core.after(2, function()
   * 				minetest.add_particlespawner(
   * 					200, --amount
   * 					0.1, --time
   * 					{x=pos.x-1, y=pos.y-1, z=pos.z-1}, --minpos
   * 					{x=pos.x+1, y=pos.y+1, z=pos.z+1}, --maxpos
   * 					{x=-0, y=-0, z=-0}, --minvel
   * 					{x=1, y=1, z=1}, --maxvel
   * 					{x=-0.5,y=5,z=-0.5}, --minacc
   * 					{x=0.5,y=5,z=0.5}, --maxacc
   * 					0.1, --minexptime
   * 					1, --maxexptime
   * 					3, --minsize
   * 					4, --maxsize
   * 					false, --collisiondetection
   * 					"tnt_smoke.png" --texture
   * 				)
   * 				local pos1 = {x=pos.x+math.random(-1,1), y=pos.y+0.5, z=pos.z+math.random(-1,1)}
   * 				local pos2 = {x=pos.x+math.random(-1,1), y=pos.y+0.5, z=pos.z+math.random(-1,1)}
   * 				minetest.add_entity(pos1, "nssm:masticone")
   * 				minetest.add_entity(pos2, "nssm:masticone")
   *     end)
   * 	end,
   * }) */
  lua_getfield(L,LUA_ENVIRONINDEX,"nssm");
  lua_pushliteral(L,"register_mob");
  lua_gettable(L,-2);
  lua_insert(L,-2);
  lua_pushliteral(L,"nssm:masticone");
  lua_createtable(L,0,31);
  lua_pushliteral(L,"type");
  lua_pushliteral(L,"monster");
  lua_rawset(L,-3);
  lua_pushliteral(L,"hp_max");
  lua_pushnumber(L,15);
  lua_rawset(L,-3);
  lua_pushliteral(L,"hp_min");
  lua_pushnumber(L,14);
  lua_rawset(L,-3);
  lua_pushliteral(L,"collisionbox");
  lua_createtable(L,6,0);
  lua_pushnumber(L,-0.45);
  lua_rawseti(L,-2,1);
  lua_pushnumber(L,0);
  lua_rawseti(L,-2,2);
  lua_pushnumber(L,-0.45);
  lua_rawseti(L,-2,3);
  lua_pushnumber(L,0.45);
  lua_rawseti(L,-2,4);
  lua_pushnumber(L,0.4);
  lua_rawseti(L,-2,5);
  lua_pushnumber(L,0.45);
  lua_rawseti(L,-2,6);
  lua_rawset(L,-3);
  lua_pushliteral(L,"visual");
  lua_pushliteral(L,"mesh");
  lua_rawset(L,-3);
  lua_pushliteral(L,"mesh");
  lua_pushliteral(L,"masticone.x");
  lua_rawset(L,-3);
  lua_pushliteral(L,"textures");
  lua_createtable(L,1,0);
  lua_createtable(L,1,0);
  lua_pushliteral(L,"masticone.png");
  lua_rawseti(L,-2,1);
  lua_rawseti(L,-2,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"visual_size");
  lua_createtable(L,0,2);
  lua_pushliteral(L,"x");
  lua_pushnumber(L,4);
  lua_rawset(L,-3);
  lua_pushliteral(L,"y");
  lua_pushnumber(L,4);
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"makes_footstep_sound");
  lua_pushboolean(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"view_range");
  lua_pushnumber(L,15);
  lua_rawset(L,-3);
  lua_pushliteral(L,"lifetimer");
  lua_pushnumber(L,500);
  lua_rawset(L,-3);
  lua_pushliteral(L,"fear_height");
  lua_pushnumber(L,4);
  lua_rawset(L,-3);
  lua_pushliteral(L,"rotate");
  lua_pushnumber(L,270);
  lua_rawset(L,-3);
  lua_pushliteral(L,"walk_velocity");
  lua_pushnumber(L,1.5);
  lua_rawset(L,-3);
  lua_pushliteral(L,"run_velocity");
  lua_pushnumber(L,2.5);
  lua_rawset(L,-3);
  lua_pushliteral(L,"sounds");
  lua_createtable(L,0,1);
  lua_pushliteral(L,"random");
  lua_pushliteral(L,"masticone");
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"damage");
  lua_pushnumber(L,5);
  lua_rawset(L,-3);
  lua_pushliteral(L,"jump");
  lua_pushboolean(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"drops");
  lua_createtable(L,3,0);
  lua_createtable(L,0,4);
  lua_pushliteral(L,"name");
  lua_pushliteral(L,"nssm:life_energy");
  lua_rawset(L,-3);
  lua_pushliteral(L,"chance");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"min");
  lua_pushnumber(L,7);
  lua_rawset(L,-3);
  lua_pushliteral(L,"max");
  lua_pushnumber(L,8);
  lua_rawset(L,-3);
  lua_rawseti(L,-2,1);
  lua_createtable(L,0,4);
  lua_pushliteral(L,"name");
  lua_pushliteral(L,"nssm:masticone_fang");
  lua_rawset(L,-3);
  lua_pushliteral(L,"chance");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"min");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"max");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_rawseti(L,-2,2);
  lua_createtable(L,0,4);
  lua_pushliteral(L,"name");
  lua_pushliteral(L,"nssm:masticone_skull_fragments");
  lua_rawset(L,-3);
  lua_pushliteral(L,"chance");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"min");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"max");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_rawseti(L,-2,3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"armor");
  lua_pushnumber(L,60);
  lua_rawset(L,-3);
  lua_pushliteral(L,"drawtype");
  lua_pushliteral(L,"front");
  lua_rawset(L,-3);
  lua_pushliteral(L,"water_damage");
  lua_pushnumber(L,0);
  lua_rawset(L,-3);
  lua_pushliteral(L,"lava_damage");
  lua_pushnumber(L,5);
  lua_rawset(L,-3);
  lua_pushliteral(L,"floats");
  lua_pushnumber(L,0);
  lua_rawset(L,-3);
  lua_pushliteral(L,"hydra");
  lua_pushboolean(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"light_damage");
  lua_pushnumber(L,0);
  lua_rawset(L,-3);
  lua_pushliteral(L,"on_rightclick");
  lua_pushnil(L);
  lua_rawset(L,-3);
  lua_pushliteral(L,"attack_type");
  lua_pushliteral(L,"dogfight");
  lua_rawset(L,-3);
  lua_pushliteral(L,"reach");
  lua_pushnumber(L,1.5);
  lua_rawset(L,-3);
  lua_pushliteral(L,"animation");
  lua_createtable(L,0,10);
  lua_pushliteral(L,"speed_normal");
  lua_pushnumber(L,20);
  lua_rawset(L,-3);
  lua_pushliteral(L,"speed_run");
  lua_pushnumber(L,25);
  lua_rawset(L,-3);
  lua_pushliteral(L,"stand_start");
  lua_pushnumber(L,80);
  lua_rawset(L,-3);
  lua_pushliteral(L,"stand_end");
  lua_pushnumber(L,140);
  lua_rawset(L,-3);
  lua_pushliteral(L,"walk_start");
  lua_pushnumber(L,20);
  lua_rawset(L,-3);
  lua_pushliteral(L,"walk_end");
  lua_pushnumber(L,40);
  lua_rawset(L,-3);
  lua_pushliteral(L,"run_start");
  lua_pushnumber(L,20);
  lua_rawset(L,-3);
  lua_pushliteral(L,"run_end");
  lua_pushnumber(L,40);
  lua_rawset(L,-3);
  lua_pushliteral(L,"punch_start");
  lua_pushnumber(L,150);
  lua_rawset(L,-3);
  lua_pushliteral(L,"punch_end");
  lua_pushnumber(L,180);
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"on_die");
  lua_pushcfunction(L,lcf3);
  lua_rawset(L,-3);
  lua_call(L,3,0);
  assert(lua_gettop(L) - lc_nextra == 0);
  return 0;
}


/* from lua.c */
static int traceback (lua_State *L) {
  if (!lua_isstring(L, 1))  /* 'message' not a string? */
    return 1;  /* keep it intact */
  lua_getfield(L, LUA_GLOBALSINDEX, "debug");
  if (!lua_istable(L, -1)) {
    lua_pop(L, 1);
    return 1;
  }
  lua_getfield(L, -1, "traceback");
  if (!lua_isfunction(L, -1)) {
    lua_pop(L, 2);
    return 1;
  }
  lua_pushvalue(L, 1);  /* pass error message */
  lua_pushinteger(L, 2);  /* skip this function and traceback */
  lua_call(L, 2, 1);  /* call debug.traceback */
  return 1;
}


static void lc_l_message (const char *pname, const char *msg) {
  if (pname) fprintf(stderr, "%s: ", pname);
  fprintf(stderr, "%s\n", msg);
  fflush(stderr);
}

static int lc_report (lua_State *L, int status) {
  if (status && !lua_isnil(L, -1)) {
    const char *msg = lua_tostring(L, -1);
    if (msg == NULL) msg = "(error object is not a string)";
    /*FIX-IMROVE:progname*/
    lc_l_message("lua", msg);
    lua_pop(L, 1);
  }
  return status;
}

static int lc_docall (lua_State *L, int narg, int clear) {
  int status;
  int base = lua_gettop(L) - narg;  /* function index */
  lua_pushcfunction(L, traceback);  /* push traceback function */
  lua_insert(L, base);  /* put it under chunk and args */
  /*FIX? signal(SIGINT, laction); */
  status = lua_pcall(L, narg, (clear ? 0 : LUA_MULTRET), base);
  /*FIX? signal(SIGINT, SIG_DFL); */
  lua_remove(L, base);  /* remove traceback function */
  /* force a complete garbage collection in case of errors */
  if (status != 0) lua_gc(L, LUA_GCCOLLECT, 0);
  return status;
}

static int lc_dofile (lua_State *L, const char *name) {
  int status = luaL_loadfile(L, name) || lc_docall(L, 0, 1);
  return lc_report(L, status);
}

static int lc_dostring (lua_State *L, const char *s, const char *name) {
  int status = luaL_loadbuffer(L, s, strlen(s), name) || lc_docall(L, 0, 1);
  return lc_report(L, status);
}

static int lc_handle_luainit (lua_State *L) {
  const char *init = getenv(LUA_INIT);
  if (init == NULL) return 0;  /* status OK */
  else if (init[0] == '@')
    return lc_dofile(L, init+1);
  else
    return lc_dostring(L, init, "=" LUA_INIT);
}


typedef struct {
  int c;
  const char ** v;
} lc_args_t;


/* create global arg table */
static void lc_createarg(lua_State * L, const lc_args_t * const args) {
  int i;
  lua_newtable(L);
  for (i=0; i < args->c; i++) {
    lua_pushstring(L, args->v[i]);
    lua_rawseti(L, -2, i);
  }
  lua_setglobal(L, "arg");
}


int lc_pmain_mod_nssm_masticone(lua_State * L) {
  luaL_openlibs(L);

  lua_pushcfunction(L, traceback);

  const int status1 = lc_handle_luainit(L);
  if (status1 != 0) return 0;

  /* note: IMPROVE: closure not always needed here */
  lua_newtable(L); /* closure table */
  lua_pushcclosure(L, lcf_main, 1);

  int status2 = lua_pcall(L, 0, 0, -2);
  if (status2 != 0) {
    const char * msg = lua_tostring(L,-1);
    if (msg == NULL) msg = "(error object is not a string)";
    fputs(msg, stderr);
  }
  return 0;
}

