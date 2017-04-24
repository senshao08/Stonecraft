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


/* function(pos, node) */
static int lcf44 (lua_State * L) {
  enum { lc_nformalargs = 2 };
  lua_settop(L,2);
  
  /* local light = minetest.get_node_light(pos) */
  lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
  lua_pushliteral(L,"get_node_light");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushvalue(L,1);
  lua_call(L,1,1);
  assert(lua_gettop(L) == 3);
  
  /* if not light
   * 		or light < 13 then */
  enum { lc1 = 3 };
  lua_pushboolean(L,!(lua_toboolean(L,3)));
  if (!(lua_toboolean(L,-1))) {
    lua_pop(L,1);
    lua_pushnumber(L,13);
    const int lc2 = lua_lessthan(L,3,-1);
    lua_pop(L,1);
    lua_pushboolean(L,lc2);
  }
  const int lc3 = lua_toboolean(L,-1);
  lua_pop(L,1);
  if (lc3) {
    
    /* return */
    return 0;
    assert(lua_gettop(L) == 3);
  }
  lua_settop(L,lc1);
  assert(lua_gettop(L) == 3);
  
  /* local pos0 = {x = pos.x - 4, y = pos.y - 2, z = pos.z - 4} */
  lua_createtable(L,0,3);
  lua_pushliteral(L,"x");
  lua_pushliteral(L,"x");
  lua_gettable(L,1);
  lua_pushnumber(L,4);
  lc_sub(L,-2,-1);
  lua_remove(L,-2);
  lua_remove(L,-2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"y");
  lua_pushliteral(L,"y");
  lua_gettable(L,1);
  lua_pushnumber(L,2);
  lc_sub(L,-2,-1);
  lua_remove(L,-2);
  lua_remove(L,-2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"z");
  lua_pushliteral(L,"z");
  lua_gettable(L,1);
  lua_pushnumber(L,4);
  lc_sub(L,-2,-1);
  lua_remove(L,-2);
  lua_remove(L,-2);
  lua_rawset(L,-3);
  assert(lua_gettop(L) == 4);
  
  /* local pos1 = {x = pos.x + 4, y = pos.y + 2, z = pos.z + 4} */
  lua_createtable(L,0,3);
  lua_pushliteral(L,"x");
  lua_pushliteral(L,"x");
  lua_gettable(L,1);
  lua_pushnumber(L,4);
  lc_add(L,-2,-1);
  lua_remove(L,-2);
  lua_remove(L,-2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"y");
  lua_pushliteral(L,"y");
  lua_gettable(L,1);
  lua_pushnumber(L,2);
  lc_add(L,-2,-1);
  lua_remove(L,-2);
  lua_remove(L,-2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"z");
  lua_pushliteral(L,"z");
  lua_gettable(L,1);
  lua_pushnumber(L,4);
  lc_add(L,-2,-1);
  lua_remove(L,-2);
  lua_remove(L,-2);
  lua_rawset(L,-3);
  assert(lua_gettop(L) == 5);
  
  /* local num = #minetest.find_nodes_in_area_under_air(
   * 			pos0, pos1, "group:flora") */
  lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
  lua_pushliteral(L,"find_nodes_in_area_under_air");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushvalue(L,4);
  lua_pushvalue(L,5);
  lua_pushliteral(L,"group:flora");
  lua_call(L,3,1);
  const double lc4 = lua_objlen(L,-1);
  lua_pop(L,1);
  lua_pushnumber(L,lc4);
  assert(lua_gettop(L) == 6);
  
  /* if num > 3
   * 		and node.name == "ethereal:crystalgrass" then */
  enum { lc5 = 6 };
  lua_pushnumber(L,3);
  const int lc6 = lua_lessthan(L,-1,6);
  lua_pop(L,1);
  lua_pushboolean(L,lc6);
  if (lua_toboolean(L,-1)) {
    lua_pop(L,1);
    lua_pushliteral(L,"name");
    lua_gettable(L,2);
    lua_pushliteral(L,"ethereal:crystalgrass");
    const int lc7 = lua_equal(L,-2,-1);
    lua_pop(L,2);
    lua_pushboolean(L,lc7);
  }
  const int lc8 = lua_toboolean(L,-1);
  lua_pop(L,1);
  if (lc8) {
    
    /* local grass = minetest.find_nodes_in_area_under_air(
     * 				pos0, pos1, {"ethereal:crystalgrass"}) */
    lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
    lua_pushliteral(L,"find_nodes_in_area_under_air");
    lua_gettable(L,-2);
    lua_remove(L,-2);
    lua_pushvalue(L,4);
    lua_pushvalue(L,5);
    lua_createtable(L,1,0);
    lua_pushliteral(L,"ethereal:crystalgrass");
    lua_rawseti(L,-2,1);
    lua_call(L,3,1);
    assert(lua_gettop(L) == 7);
    
    /* local crystal = minetest.find_nodes_in_area_under_air(
     * 				pos0, pos1, {"ethereal:crystal_spike"}) */
    lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
    lua_pushliteral(L,"find_nodes_in_area_under_air");
    lua_gettable(L,-2);
    lua_remove(L,-2);
    lua_pushvalue(L,4);
    lua_pushvalue(L,5);
    lua_createtable(L,1,0);
    lua_pushliteral(L,"ethereal:crystal_spike");
    lua_rawseti(L,-2,1);
    lua_call(L,3,1);
    assert(lua_gettop(L) == 8);
    
    /* if #grass > 4
     * 			and #crystal < 1 then */
    enum { lc9 = 8 };
    lua_pushnumber(L,4);
    const double lc10 = lua_objlen(L,7);
    lua_pushnumber(L,lc10);
    const int lc11 = lua_lessthan(L,-2,-1);
    lua_pop(L,2);
    lua_pushboolean(L,lc11);
    if (lua_toboolean(L,-1)) {
      lua_pop(L,1);
      const double lc12 = lua_objlen(L,8);
      lua_pushnumber(L,lc12);
      lua_pushnumber(L,1);
      const int lc13 = lua_lessthan(L,-2,-1);
      lua_pop(L,2);
      lua_pushboolean(L,lc13);
    }
    const int lc14 = lua_toboolean(L,-1);
    lua_pop(L,1);
    if (lc14) {
      
      /* grass = grass[math.random(#grass)] */
      lua_getfield(L,LUA_ENVIRONINDEX,"math");
      lua_pushliteral(L,"random");
      lua_gettable(L,-2);
      lua_remove(L,-2);
      const double lc15 = lua_objlen(L,7);
      lua_pushnumber(L,lc15);
      lua_call(L,1,1);
      lua_gettable(L,7);
      lua_replace(L,7);
      assert(lua_gettop(L) == 8);
      
      /* grass.y = grass.y - 1 */
      lua_pushliteral(L,"y");
      lua_gettable(L,7);
      lua_pushnumber(L,1);
      lc_sub(L,-2,-1);
      lua_remove(L,-2);
      lua_remove(L,-2);
      lua_pushliteral(L,"y");
      lua_insert(L,-2);
      lua_settable(L,7);
      assert(lua_gettop(L) == 8);
      
      /* if minetest.get_node(grass).name == "ethereal:crystal_dirt" then */
      enum { lc16 = 8 };
      lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
      lua_pushliteral(L,"get_node");
      lua_gettable(L,-2);
      lua_remove(L,-2);
      lua_pushvalue(L,7);
      lua_call(L,1,1);
      lua_pushliteral(L,"name");
      lua_gettable(L,-2);
      lua_remove(L,-2);
      lua_pushliteral(L,"ethereal:crystal_dirt");
      const int lc17 = lua_equal(L,-2,-1);
      lua_pop(L,2);
      lua_pushboolean(L,lc17);
      const int lc18 = lua_toboolean(L,-1);
      lua_pop(L,1);
      if (lc18) {
        
        /* grass.y = grass.y + 1 */
        lua_pushliteral(L,"y");
        lua_gettable(L,7);
        lua_pushnumber(L,1);
        lc_add(L,-2,-1);
        lua_remove(L,-2);
        lua_remove(L,-2);
        lua_pushliteral(L,"y");
        lua_insert(L,-2);
        lua_settable(L,7);
        assert(lua_gettop(L) == 8);
        
        /* minetest.swap_node(grass, {name = "ethereal:crystal_spike"}) */
        lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
        lua_pushliteral(L,"swap_node");
        lua_gettable(L,-2);
        lua_remove(L,-2);
        lua_pushvalue(L,7);
        lua_createtable(L,0,1);
        lua_pushliteral(L,"name");
        lua_pushliteral(L,"ethereal:crystal_spike");
        lua_rawset(L,-3);
        lua_call(L,2,0);
        assert(lua_gettop(L) == 8);
      }
      lua_settop(L,lc16);
      assert(lua_gettop(L) == 8);
    }
    lua_settop(L,lc9);
    assert(lua_gettop(L) == 8);
    
    /* return */
    return 0;
    assert(lua_gettop(L) == 8);
  }
  else {
    
    /* elseif num > 3
     * 		and node.name == "ethereal:dry_shrub" then */
    enum { lc19 = 6 };
    lua_pushnumber(L,3);
    const int lc20 = lua_lessthan(L,-1,6);
    lua_pop(L,1);
    lua_pushboolean(L,lc20);
    if (lua_toboolean(L,-1)) {
      lua_pop(L,1);
      lua_pushliteral(L,"name");
      lua_gettable(L,2);
      lua_pushliteral(L,"ethereal:dry_shrub");
      const int lc21 = lua_equal(L,-2,-1);
      lua_pop(L,2);
      lua_pushboolean(L,lc21);
    }
    const int lc22 = lua_toboolean(L,-1);
    lua_pop(L,1);
    if (lc22) {
      
      /* local grass = minetest.find_nodes_in_area_under_air(
       * 				pos0, pos1, {"ethereal:dry_shrub"}) */
      lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
      lua_pushliteral(L,"find_nodes_in_area_under_air");
      lua_gettable(L,-2);
      lua_remove(L,-2);
      lua_pushvalue(L,4);
      lua_pushvalue(L,5);
      lua_createtable(L,1,0);
      lua_pushliteral(L,"ethereal:dry_shrub");
      lua_rawseti(L,-2,1);
      lua_call(L,3,1);
      assert(lua_gettop(L) == 7);
      
      /* local fflower = minetest.find_nodes_in_area_under_air(
       * 				pos0, pos1, {"ethereal:fire_flower"}) */
      lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
      lua_pushliteral(L,"find_nodes_in_area_under_air");
      lua_gettable(L,-2);
      lua_remove(L,-2);
      lua_pushvalue(L,4);
      lua_pushvalue(L,5);
      lua_createtable(L,1,0);
      lua_pushliteral(L,"ethereal:fire_flower");
      lua_rawseti(L,-2,1);
      lua_call(L,3,1);
      assert(lua_gettop(L) == 8);
      
      /* if #grass > 8
       * 			and #fflower < 1 then */
      enum { lc23 = 8 };
      lua_pushnumber(L,8);
      const double lc24 = lua_objlen(L,7);
      lua_pushnumber(L,lc24);
      const int lc25 = lua_lessthan(L,-2,-1);
      lua_pop(L,2);
      lua_pushboolean(L,lc25);
      if (lua_toboolean(L,-1)) {
        lua_pop(L,1);
        const double lc26 = lua_objlen(L,8);
        lua_pushnumber(L,lc26);
        lua_pushnumber(L,1);
        const int lc27 = lua_lessthan(L,-2,-1);
        lua_pop(L,2);
        lua_pushboolean(L,lc27);
      }
      const int lc28 = lua_toboolean(L,-1);
      lua_pop(L,1);
      if (lc28) {
        
        /* grass = grass[math.random(#grass)] */
        lua_getfield(L,LUA_ENVIRONINDEX,"math");
        lua_pushliteral(L,"random");
        lua_gettable(L,-2);
        lua_remove(L,-2);
        const double lc29 = lua_objlen(L,7);
        lua_pushnumber(L,lc29);
        lua_call(L,1,1);
        lua_gettable(L,7);
        lua_replace(L,7);
        assert(lua_gettop(L) == 8);
        
        /* grass.y = grass.y - 1 */
        lua_pushliteral(L,"y");
        lua_gettable(L,7);
        lua_pushnumber(L,1);
        lc_sub(L,-2,-1);
        lua_remove(L,-2);
        lua_remove(L,-2);
        lua_pushliteral(L,"y");
        lua_insert(L,-2);
        lua_settable(L,7);
        assert(lua_gettop(L) == 8);
        
        /* if minetest.get_node(grass).name == "ethereal:fiery_dirt" then */
        enum { lc30 = 8 };
        lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
        lua_pushliteral(L,"get_node");
        lua_gettable(L,-2);
        lua_remove(L,-2);
        lua_pushvalue(L,7);
        lua_call(L,1,1);
        lua_pushliteral(L,"name");
        lua_gettable(L,-2);
        lua_remove(L,-2);
        lua_pushliteral(L,"ethereal:fiery_dirt");
        const int lc31 = lua_equal(L,-2,-1);
        lua_pop(L,2);
        lua_pushboolean(L,lc31);
        const int lc32 = lua_toboolean(L,-1);
        lua_pop(L,1);
        if (lc32) {
          
          /* grass.y = grass.y + 1 */
          lua_pushliteral(L,"y");
          lua_gettable(L,7);
          lua_pushnumber(L,1);
          lc_add(L,-2,-1);
          lua_remove(L,-2);
          lua_remove(L,-2);
          lua_pushliteral(L,"y");
          lua_insert(L,-2);
          lua_settable(L,7);
          assert(lua_gettop(L) == 8);
          
          /* minetest.swap_node(grass, {name = "ethereal:fire_flower"}) */
          lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
          lua_pushliteral(L,"swap_node");
          lua_gettable(L,-2);
          lua_remove(L,-2);
          lua_pushvalue(L,7);
          lua_createtable(L,0,1);
          lua_pushliteral(L,"name");
          lua_pushliteral(L,"ethereal:fire_flower");
          lua_rawset(L,-3);
          lua_call(L,2,0);
          assert(lua_gettop(L) == 8);
        }
        lua_settop(L,lc30);
        assert(lua_gettop(L) == 8);
      }
      lua_settop(L,lc23);
      assert(lua_gettop(L) == 8);
      
      /* return */
      return 0;
      assert(lua_gettop(L) == 8);
    }
    else {
      
      /* elseif num > 3 then */
      enum { lc33 = 6 };
      lua_pushnumber(L,3);
      const int lc34 = lua_lessthan(L,-1,6);
      lua_pop(L,1);
      lua_pushboolean(L,lc34);
      const int lc35 = lua_toboolean(L,-1);
      lua_pop(L,1);
      if (lc35) {
        
        /* return */
        return 0;
        assert(lua_gettop(L) == 6);
      }
      lua_settop(L,lc33);
    }
    lua_settop(L,lc19);
  }
  lua_settop(L,lc5);
  assert(lua_gettop(L) == 6);
  
  /* local seedling = minetest.find_nodes_in_area_under_air(
   * 			pos0, pos1, {"group:soil"}) */
  lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
  lua_pushliteral(L,"find_nodes_in_area_under_air");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushvalue(L,4);
  lua_pushvalue(L,5);
  lua_createtable(L,1,0);
  lua_pushliteral(L,"group:soil");
  lua_rawseti(L,-2,1);
  lua_call(L,3,1);
  assert(lua_gettop(L) == 7);
  
  /* if #seedling > 0 then */
  enum { lc36 = 7 };
  lua_pushnumber(L,0);
  const double lc37 = lua_objlen(L,7);
  lua_pushnumber(L,lc37);
  const int lc38 = lua_lessthan(L,-2,-1);
  lua_pop(L,2);
  lua_pushboolean(L,lc38);
  const int lc39 = lua_toboolean(L,-1);
  lua_pop(L,1);
  if (lc39) {
    
    /* seedling = seedling[math.random(#seedling)] */
    lua_getfield(L,LUA_ENVIRONINDEX,"math");
    lua_pushliteral(L,"random");
    lua_gettable(L,-2);
    lua_remove(L,-2);
    const double lc40 = lua_objlen(L,7);
    lua_pushnumber(L,lc40);
    lua_call(L,1,1);
    lua_gettable(L,7);
    lua_replace(L,7);
    assert(lua_gettop(L) == 7);
    
    /* seedling.y = seedling.y + 1 */
    lua_pushliteral(L,"y");
    lua_gettable(L,7);
    lua_pushnumber(L,1);
    lc_add(L,-2,-1);
    lua_remove(L,-2);
    lua_remove(L,-2);
    lua_pushliteral(L,"y");
    lua_insert(L,-2);
    lua_settable(L,7);
    assert(lua_gettop(L) == 7);
    
    /* light = minetest.get_node_light(seedling) */
    lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
    lua_pushliteral(L,"get_node_light");
    lua_gettable(L,-2);
    lua_remove(L,-2);
    lua_pushvalue(L,7);
    lua_call(L,1,1);
    lua_replace(L,3);
    assert(lua_gettop(L) == 7);
    
    /* if not light
     * 			or light < 13 then */
    enum { lc41 = 7 };
    lua_pushboolean(L,!(lua_toboolean(L,3)));
    if (!(lua_toboolean(L,-1))) {
      lua_pop(L,1);
      lua_pushnumber(L,13);
      const int lc42 = lua_lessthan(L,3,-1);
      lua_pop(L,1);
      lua_pushboolean(L,lc42);
    }
    const int lc43 = lua_toboolean(L,-1);
    lua_pop(L,1);
    if (lc43) {
      
      /* return */
      return 0;
      assert(lua_gettop(L) == 7);
    }
    lua_settop(L,lc41);
    assert(lua_gettop(L) == 7);
    
    /* minetest.swap_node(seedling, {name = node.name}) */
    lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
    lua_pushliteral(L,"swap_node");
    lua_gettable(L,-2);
    lua_remove(L,-2);
    lua_pushvalue(L,7);
    lua_createtable(L,0,1);
    lua_pushliteral(L,"name");
    lua_pushliteral(L,"name");
    lua_gettable(L,2);
    lua_rawset(L,-3);
    lua_call(L,2,0);
    assert(lua_gettop(L) == 7);
  }
  lua_settop(L,lc36);
  assert(lua_gettop(L) == 7);
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
  
  /* -- Flowers spread over all types of soil
   * minetest.register_abm({
   * 	nodenames = {"group:flora"},
   * 	neighbors = {"group:soil"},
   * 	interval = 13, --25,
   * 	chance = 96, --15,
   * 	catch_up = false,
   * 	action = function(pos, node)
   * 
   * 		local light = minetest.get_node_light(pos)
   * 
   * 		if not light
   * 		or light < 13 then
   * 			return
   * 		end
   * 
   * 		local pos0 = {x = pos.x - 4, y = pos.y - 2, z = pos.z - 4}
   * 		local pos1 = {x = pos.x + 4, y = pos.y + 2, z = pos.z + 4}
   * 		local num = #minetest.find_nodes_in_area_under_air(
   * 			pos0, pos1, "group:flora")
   * 
   * 		if num > 3
   * 		and node.name == "ethereal:crystalgrass" then
   * 
   * 			local grass = minetest.find_nodes_in_area_under_air(
   * 				pos0, pos1, {"ethereal:crystalgrass"})
   * 
   * 			local crystal = minetest.find_nodes_in_area_under_air(
   * 				pos0, pos1, {"ethereal:crystal_spike"})
   * 
   * 			if #grass > 4
   * 			and #crystal < 1 then
   * 
   * 				grass = grass[math.random(#grass)]
   * 
   * 				grass.y = grass.y - 1
   * 
   * 				if minetest.get_node(grass).name == "ethereal:crystal_dirt" then
   * 
   * 					grass.y = grass.y + 1
   * 
   * 					minetest.swap_node(grass, {name = "ethereal:crystal_spike"})
   * 				end
   * 			end
   * 
   * 			return
   * 
   * 		elseif num > 3
   * 		and node.name == "ethereal:dry_shrub" then
   * 
   * 			local grass = minetest.find_nodes_in_area_under_air(
   * 				pos0, pos1, {"ethereal:dry_shrub"})
   * 
   * 			local fflower = minetest.find_nodes_in_area_under_air(
   * 				pos0, pos1, {"ethereal:fire_flower"})
   * 
   * 			if #grass > 8
   * 			and #fflower < 1 then
   * 
   * 				grass = grass[math.random(#grass)]
   * 
   * 				grass.y = grass.y - 1
   * 
   * 				if minetest.get_node(grass).name == "ethereal:fiery_dirt" then
   * 
   * 					grass.y = grass.y + 1
   * 
   * 					minetest.swap_node(grass, {name = "ethereal:fire_flower"})
   * 				end
   * 			end
   * 
   * 			return
   * 
   * 		elseif num > 3 then
   * 			return
   * 		end
   * 
   * 		local seedling = minetest.find_nodes_in_area_under_air(
   * 			pos0, pos1, {"group:soil"})
   * 
   * 		if #seedling > 0 then
   * 
   * 			seedling = seedling[math.random(#seedling)]
   * 			seedling.y = seedling.y + 1
   * 
   * 			light = minetest.get_node_light(seedling)
   * 
   * 			if not light
   * 			or light < 13 then
   * 				return
   * 			end
   * 
   * 			minetest.swap_node(seedling, {name = node.name})
   * 		end
   * 	end,
   * }) */
  lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
  lua_pushliteral(L,"register_abm");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_createtable(L,0,6);
  lua_pushliteral(L,"nodenames");
  lua_createtable(L,1,0);
  lua_pushliteral(L,"group:flora");
  lua_rawseti(L,-2,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"neighbors");
  lua_createtable(L,1,0);
  lua_pushliteral(L,"group:soil");
  lua_rawseti(L,-2,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"interval");
  lua_pushnumber(L,13);
  lua_rawset(L,-3);
  lua_pushliteral(L,"chance");
  lua_pushnumber(L,96);
  lua_rawset(L,-3);
  lua_pushliteral(L,"catch_up");
  lua_pushboolean(L,0);
  lua_rawset(L,-3);
  lua_pushliteral(L,"action");
  lua_pushcfunction(L,lcf44);
  lua_rawset(L,-3);
  lua_call(L,1,0);
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


int lc_pmain_mod_ethereal_flowers(lua_State * L) {
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


