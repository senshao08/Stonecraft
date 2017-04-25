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

/* name: mg_villages.add_village_type
 * function( type_name, v) */
static int lcf1_mg_villages_add_village_type (lua_State * L) {
  enum { lc_nformalargs = 2 };
  lua_settop(L,2);
  
  /* local found = true */
  lua_pushboolean(L,1);
  assert(lua_gettop(L) == 3);
  
  /* if( not( v.mods )) then */
  enum { lc1 = 3 };
  lua_pushliteral(L,"mods");
  lua_gettable(L,2);
  lua_pushboolean(L,!(lua_toboolean(L,-1)));
  lua_remove(L,-2);
  const int lc2 = lua_toboolean(L,-1);
  lua_pop(L,1);
  if (lc2) {
    
    /* v.mods = {} */
    lua_newtable(L);
    lua_pushliteral(L,"mods");
    lua_insert(L,-2);
    lua_settable(L,2);
    assert(lua_gettop(L) == 3);
  }
  lua_settop(L,lc1);
  assert(lua_gettop(L) == 3);
  
  /* for _,m in ipairs( v.mods ) do
   * internal: local f, s, var = explist */
  enum { lc3 = 3 };
  lua_getfield(L,LUA_ENVIRONINDEX,"ipairs");
  lua_pushliteral(L,"mods");
  lua_gettable(L,2);
  lua_call(L,1,3);
  while (1) {
    
    /* internal: local var_1, ..., var_n = f(s, var)
     *           if var_1 == nil then break end
     *           var = var_1 */
    lua_pushvalue(L,-3);
    lua_pushvalue(L,-3);
    lua_pushvalue(L,-3);
    lua_call(L,2,2);
    if (lua_isnil(L,-2)) {
      break;
    }
    lua_pushvalue(L,-2);
    lua_replace(L,-4);
    
    /* internal: local _ with idx 7
     * internal: local m with idx 8 */
    
    
    /* if( not( minetest.get_modpath( m ))) then */
    enum { lc4 = 8 };
    lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
    lua_pushliteral(L,"get_modpath");
    lua_gettable(L,-2);
    lua_remove(L,-2);
    lua_pushvalue(L,8);
    lua_call(L,1,1);
    lua_pushboolean(L,!(lua_toboolean(L,-1)));
    lua_remove(L,-2);
    const int lc5 = lua_toboolean(L,-1);
    lua_pop(L,1);
    if (lc5) {
      
      /* -- this village type will not be used because not all required mods are installed
       * return false */
      lua_pushboolean(L,0);
      return 1;
      assert(lua_gettop(L) == 8);
    }
    lua_settop(L,lc4);
    assert(lua_gettop(L) == 8);
    
    /* internal: stack cleanup on scope exit */
    lua_pop(L,2);
  }
  lua_settop(L,lc3);
  assert(lua_gettop(L) == 3);
  
  /* if( not( v.only_single ) and (not(v.min) or not(v.max))) then */
  enum { lc6 = 3 };
  lua_pushliteral(L,"only_single");
  lua_gettable(L,2);
  lua_pushboolean(L,!(lua_toboolean(L,-1)));
  lua_remove(L,-2);
  if (lua_toboolean(L,-1)) {
    lua_pop(L,1);
    lua_pushliteral(L,"min");
    lua_gettable(L,2);
    lua_pushboolean(L,!(lua_toboolean(L,-1)));
    lua_remove(L,-2);
    if (!(lua_toboolean(L,-1))) {
      lua_pop(L,1);
      lua_pushliteral(L,"max");
      lua_gettable(L,2);
      lua_pushboolean(L,!(lua_toboolean(L,-1)));
      lua_remove(L,-2);
    }
  }
  const int lc7 = lua_toboolean(L,-1);
  lua_pop(L,1);
  if (lc7) {
    
    /* mg_villages.print( mg_villages.DEBUG_LEVEL_NORMAL, 'Error: Village type '..tostring( type_name )..' lacks size information.') */
    lua_getfield(L,LUA_ENVIRONINDEX,"mg_villages");
    lua_pushliteral(L,"print");
    lua_gettable(L,-2);
    lua_remove(L,-2);
    lua_getfield(L,LUA_ENVIRONINDEX,"mg_villages");
    lua_pushliteral(L,"DEBUG_LEVEL_NORMAL");
    lua_gettable(L,-2);
    lua_remove(L,-2);
    lua_pushliteral(L,"Error: Village type ");
    lua_getfield(L,LUA_ENVIRONINDEX,"tostring");
    lua_pushvalue(L,1);
    lua_call(L,1,1);
    lua_pushliteral(L," lacks size information.");
    lua_concat(L,2);
    lua_concat(L,2);
    lua_call(L,2,0);
    assert(lua_gettop(L) == 3);
    
    /* return false */
    lua_pushboolean(L,0);
    return 1;
    assert(lua_gettop(L) == 3);
  }
  lua_settop(L,lc6);
  assert(lua_gettop(L) == 3);
  
  /* -- set some default values
   * if( not( v.sapling_divisor )) then */
  enum { lc8 = 3 };
  lua_pushliteral(L,"sapling_divisor");
  lua_gettable(L,2);
  lua_pushboolean(L,!(lua_toboolean(L,-1)));
  lua_remove(L,-2);
  const int lc9 = lua_toboolean(L,-1);
  lua_pop(L,1);
  if (lc9) {
    
    /* v.sapling_divisor = 10 */
    lua_pushnumber(L,10);
    lua_pushliteral(L,"sapling_divisor");
    lua_insert(L,-2);
    lua_settable(L,2);
    assert(lua_gettop(L) == 3);
  }
  lua_settop(L,lc8);
  assert(lua_gettop(L) == 3);
  
  /* if( not( v.plant_type )) then */
  enum { lc10 = 3 };
  lua_pushliteral(L,"plant_type");
  lua_gettable(L,2);
  lua_pushboolean(L,!(lua_toboolean(L,-1)));
  lua_remove(L,-2);
  const int lc11 = lua_toboolean(L,-1);
  lua_pop(L,1);
  if (lc11) {
    
    /* v.plant_type      = 'default:grass_5' */
    lua_pushliteral(L,"default:grass_5");
    lua_pushliteral(L,"plant_type");
    lua_insert(L,-2);
    lua_settable(L,2);
    assert(lua_gettop(L) == 3);
    
    /* if( not( minetest.registered_nodes[ v.plant_type ])) then */
    enum { lc12 = 3 };
    lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
    lua_pushliteral(L,"registered_nodes");
    lua_gettable(L,-2);
    lua_remove(L,-2);
    lua_pushliteral(L,"plant_type");
    lua_gettable(L,2);
    lua_gettable(L,-2);
    lua_remove(L,-2);
    lua_pushboolean(L,!(lua_toboolean(L,-1)));
    lua_remove(L,-2);
    const int lc13 = lua_toboolean(L,-1);
    lua_pop(L,1);
    if (lc13) {
      
      /* v.plant_type = 'default:dry_shrub' */
      lua_pushliteral(L,"default:dry_shrub");
      lua_pushliteral(L,"plant_type");
      lua_insert(L,-2);
      lua_settable(L,2);
      assert(lua_gettop(L) == 3);
    }
    lua_settop(L,lc12);
    assert(lua_gettop(L) == 3);
  }
  lua_settop(L,lc10);
  assert(lua_gettop(L) == 3);
  
  /* if( not( v.plant_frequency )) then */
  enum { lc14 = 3 };
  lua_pushliteral(L,"plant_frequency");
  lua_gettable(L,2);
  lua_pushboolean(L,!(lua_toboolean(L,-1)));
  lua_remove(L,-2);
  const int lc15 = lua_toboolean(L,-1);
  lua_pop(L,1);
  if (lc15) {
    
    /* v.plant_frequency = 3 */
    lua_pushnumber(L,3);
    lua_pushliteral(L,"plant_frequency");
    lua_insert(L,-2);
    lua_settable(L,2);
    assert(lua_gettop(L) == 3);
  }
  lua_settop(L,lc14);
  assert(lua_gettop(L) == 3);
  
  /* -- this village type is supported by the mods installed and may be used
   * v.supported = 1 */
  lua_pushnumber(L,1);
  lua_pushliteral(L,"supported");
  lua_insert(L,-2);
  lua_settable(L,2);
  assert(lua_gettop(L) == 3);
  
  /* mg_villages.village_type_data[ type_name ] = v */
  lua_pushvalue(L,2);
  lua_getfield(L,LUA_ENVIRONINDEX,"mg_villages");
  lua_pushliteral(L,"village_type_data");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_insert(L,-2);
  lua_pushvalue(L,1);
  lua_insert(L,-2);
  lua_settable(L,-3);
  lua_pop(L,1);
  assert(lua_gettop(L) == 3);
  
  /* return true */
  lua_pushboolean(L,1);
  return 1;
  assert(lua_gettop(L) == 3);
}


/* name: (main)
 * function(...) */
static int lcf_main (lua_State * L) {
  enum { lc_nformalargs = 0 };
  const int lc_nactualargs = lua_gettop(L);
  const int lc_nextra = (lc_nactualargs - lc_nformalargs);
  
  /* --  DOCUMENTATION: mg_villages.village_type_data has entries in the following form:
   * --      key = { data values }   with key beeing the name of the village type
   * --  meaning of the data values:
   * --      min, max: the village size will be choosen randomly between these two values;
   * --                the actual village will have a radius about twice as big (including sourrounding area)
   * --      space_between_buildings=2  How much space is there between the buildings. 1 or 2 are good values.
   * --                The higher, the further the buildings are spread apart.
   * --      mods = {'homedecor','moreblocks'} List of mods that are required for the buildings of this village type.
   * --                List all the mods the blocks used by your buildings which are not in default.
   * --      texture = 'wool_white.png'        Texture used to show the location of the village when using the
   * --                vmap  command.
   * --      name_prefix = 'Village ',
   * --      name_postfix = ''                 When creating village names for single houses which are spawned outside
   * --                of villages, the village name will consist of  name_prefix..village_name..name_postfix
   * --	sapling_divisor = 1	Villages are sourrounded by a flat area that may contain trees. Increasing this
   * --				value decreses the mount of trees placed.
   * --	plant_type = 'farming:wheat_8'  Type of plant that is placed around villages.
   * --	plant_frequency = 1	The higher this value is, the less plants are placed.
   * local village_type_data_list = {
   * 	nore         = { min = 20, max = 40,   space_between_buildings=1, mods={},            texture = 'default_stone_brick.png',
   * 			 replacement_function = mg_villages.replacements_nore },
   * 	taoki        = { min = 30, max = 70,   space_between_buildings=1, mods={},            texture = 'default_brick.png' ,
   * 			 sapling_divisor =  5, plant_type = 'farming:cotton_8',    plant_frequency = 1,
   * 			 replacement_function = mg_villages.replacements_taoki },
   * 	medieval     = { min = 25, max = 60,   space_between_buildings=2, mods={'cottages'},  texture = 'cottages_darkage_straw.png', -- they often have straw roofs
   * 			 sapling_divisor = 10, plant_type = 'farming:wheat_8',     plant_frequency = 1,
   * 			 replacement_function = mg_villages.replacements_medieval,
   * 			roadsize_list = {2,3,4,5,6},
   * --			road_materials = {'default:cobble','default:gravel','default:stonebrick','default:coalblock'},
   * 			}, --roadsize_list = {1,1,2,3,4} },
   * 	charachoal   = { min = 10, max = 15,   space_between_buildings=1, mods={'cottages'},  texture = 'default_coal_block.png',
   * 			 replacement_function = mg_villages.replacements_charachoal },
   * 	lumberjack   = { min = 10, max = 30,   space_between_buildings=1, mods={'cottages'},  texture = 'default_tree.png', name_prefix = 'Camp ',
   * 			 sapling_divisor =  1, plant_type = 'default:junglegrass', plant_frequency = 24,
   * 			 replacement_function = mg_villages.replacements_lumberjack },
   * 	claytrader   = { min = 10, max = 20,   space_between_buildings=1, mods={'cottages'},  texture = 'default_clay.png',
   * 			 replacement_function = mg_villages.replacements_claytrader },
   * 	logcabin     = { min = 15, max = 30,   space_between_buildings=1, mods={'cottages'},  texture = 'default_wood.png',
   * 			 replacement_function = mg_villages.replacements_logcabin },
   * 	grasshut     = { min = 10, max = 40,   space_between_buildings=1, mods={'dryplants'}, texture = 'dryplants_reed.png',
   * 			 replacement_function = mg_villages.replacements_grasshut },
   * 	tent         = { min =  5, max = 20,   space_between_buildings=2, mods={'cottages'},  texture = 'wool_white.png', name_preifx = 'Tent at',
   * 			 replacement_function = mg_villages.replacements_tent },
   * 
   * 	-- these sub-types may occour as single houses placed far from villages
   * 	tower        = { only_single = 1, name_prefix = 'Tower at ',      mods={'cottages'},  texture = 'default_mese.png',
   * 			 replacement_function = mg_villages.replacements_tower },
   * 	chateau      = { only_single = 1, name_prefix = 'Chateau ',                           texture = 'default_gold_block.png',
   * 			 replacement_function = mg_villages.replacements_chateau },
   * 	forge        = { only_single = 1, name_prefix = 'Forge at '},
   * 	tavern       = { only_single = 1, name_prefix = 'Inn at '},
   * 	well         = { only_single = 1, name_prefix = 'Well at ',
   * 			 replacement_function = mg_villages.replacements_medieval },
   * 	trader       = { only_single = 1, name_prefix = 'Trading post ' },
   * 	sawmill      = { only_single = 1, name_prefix = 'Sawmill at ' },
   * 	farm_tiny    = { only_single = 1, name_prefix = 'House '},
   * 	farm_full    = { only_single = 1, name_prefix = 'Farm '},
   * 	single       = { only_single = 1, name_prefix = 'House '}, -- fallback
   * } */
  lua_createtable(L,0,19);
  lua_pushliteral(L,"nore");
  lua_createtable(L,0,6);
  lua_pushliteral(L,"min");
  lua_pushnumber(L,20);
  lua_rawset(L,-3);
  lua_pushliteral(L,"max");
  lua_pushnumber(L,40);
  lua_rawset(L,-3);
  lua_pushliteral(L,"space_between_buildings");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"mods");
  lua_newtable(L);
  lua_rawset(L,-3);
  lua_pushliteral(L,"texture");
  lua_pushliteral(L,"default_stone_brick.png");
  lua_rawset(L,-3);
  lua_pushliteral(L,"replacement_function");
  lua_getfield(L,LUA_ENVIRONINDEX,"mg_villages");
  lua_pushliteral(L,"replacements_nore");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"taoki");
  lua_createtable(L,0,9);
  lua_pushliteral(L,"min");
  lua_pushnumber(L,30);
  lua_rawset(L,-3);
  lua_pushliteral(L,"max");
  lua_pushnumber(L,70);
  lua_rawset(L,-3);
  lua_pushliteral(L,"space_between_buildings");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"mods");
  lua_newtable(L);
  lua_rawset(L,-3);
  lua_pushliteral(L,"texture");
  lua_pushliteral(L,"default_brick.png");
  lua_rawset(L,-3);
  lua_pushliteral(L,"sapling_divisor");
  lua_pushnumber(L,5);
  lua_rawset(L,-3);
  lua_pushliteral(L,"plant_type");
  lua_pushliteral(L,"farming:cotton_8");
  lua_rawset(L,-3);
  lua_pushliteral(L,"plant_frequency");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"replacement_function");
  lua_getfield(L,LUA_ENVIRONINDEX,"mg_villages");
  lua_pushliteral(L,"replacements_taoki");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"medieval");
  lua_createtable(L,0,10);
  lua_pushliteral(L,"min");
  lua_pushnumber(L,25);
  lua_rawset(L,-3);
  lua_pushliteral(L,"max");
  lua_pushnumber(L,60);
  lua_rawset(L,-3);
  lua_pushliteral(L,"space_between_buildings");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"mods");
  lua_createtable(L,1,0);
  lua_pushliteral(L,"cottages");
  lua_rawseti(L,-2,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"texture");
  lua_pushliteral(L,"cottages_darkage_straw.png");
  lua_rawset(L,-3);
  lua_pushliteral(L,"sapling_divisor");
  lua_pushnumber(L,10);
  lua_rawset(L,-3);
  lua_pushliteral(L,"plant_type");
  lua_pushliteral(L,"farming:wheat_8");
  lua_rawset(L,-3);
  lua_pushliteral(L,"plant_frequency");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"replacement_function");
  lua_getfield(L,LUA_ENVIRONINDEX,"mg_villages");
  lua_pushliteral(L,"replacements_medieval");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"roadsize_list");
  lua_createtable(L,5,0);
  lua_pushnumber(L,2);
  lua_rawseti(L,-2,1);
  lua_pushnumber(L,3);
  lua_rawseti(L,-2,2);
  lua_pushnumber(L,4);
  lua_rawseti(L,-2,3);
  lua_pushnumber(L,5);
  lua_rawseti(L,-2,4);
  lua_pushnumber(L,6);
  lua_rawseti(L,-2,5);
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"charachoal");
  lua_createtable(L,0,6);
  lua_pushliteral(L,"min");
  lua_pushnumber(L,10);
  lua_rawset(L,-3);
  lua_pushliteral(L,"max");
  lua_pushnumber(L,15);
  lua_rawset(L,-3);
  lua_pushliteral(L,"space_between_buildings");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"mods");
  lua_createtable(L,1,0);
  lua_pushliteral(L,"cottages");
  lua_rawseti(L,-2,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"texture");
  lua_pushliteral(L,"default_coal_block.png");
  lua_rawset(L,-3);
  lua_pushliteral(L,"replacement_function");
  lua_getfield(L,LUA_ENVIRONINDEX,"mg_villages");
  lua_pushliteral(L,"replacements_charachoal");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"lumberjack");
  lua_createtable(L,0,10);
  lua_pushliteral(L,"min");
  lua_pushnumber(L,10);
  lua_rawset(L,-3);
  lua_pushliteral(L,"max");
  lua_pushnumber(L,30);
  lua_rawset(L,-3);
  lua_pushliteral(L,"space_between_buildings");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"mods");
  lua_createtable(L,1,0);
  lua_pushliteral(L,"cottages");
  lua_rawseti(L,-2,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"texture");
  lua_pushliteral(L,"default_tree.png");
  lua_rawset(L,-3);
  lua_pushliteral(L,"name_prefix");
  lua_pushliteral(L,"Camp ");
  lua_rawset(L,-3);
  lua_pushliteral(L,"sapling_divisor");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"plant_type");
  lua_pushliteral(L,"default:junglegrass");
  lua_rawset(L,-3);
  lua_pushliteral(L,"plant_frequency");
  lua_pushnumber(L,24);
  lua_rawset(L,-3);
  lua_pushliteral(L,"replacement_function");
  lua_getfield(L,LUA_ENVIRONINDEX,"mg_villages");
  lua_pushliteral(L,"replacements_lumberjack");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"claytrader");
  lua_createtable(L,0,6);
  lua_pushliteral(L,"min");
  lua_pushnumber(L,10);
  lua_rawset(L,-3);
  lua_pushliteral(L,"max");
  lua_pushnumber(L,20);
  lua_rawset(L,-3);
  lua_pushliteral(L,"space_between_buildings");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"mods");
  lua_createtable(L,1,0);
  lua_pushliteral(L,"cottages");
  lua_rawseti(L,-2,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"texture");
  lua_pushliteral(L,"default_clay.png");
  lua_rawset(L,-3);
  lua_pushliteral(L,"replacement_function");
  lua_getfield(L,LUA_ENVIRONINDEX,"mg_villages");
  lua_pushliteral(L,"replacements_claytrader");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"logcabin");
  lua_createtable(L,0,6);
  lua_pushliteral(L,"min");
  lua_pushnumber(L,15);
  lua_rawset(L,-3);
  lua_pushliteral(L,"max");
  lua_pushnumber(L,30);
  lua_rawset(L,-3);
  lua_pushliteral(L,"space_between_buildings");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"mods");
  lua_createtable(L,1,0);
  lua_pushliteral(L,"cottages");
  lua_rawseti(L,-2,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"texture");
  lua_pushliteral(L,"default_wood.png");
  lua_rawset(L,-3);
  lua_pushliteral(L,"replacement_function");
  lua_getfield(L,LUA_ENVIRONINDEX,"mg_villages");
  lua_pushliteral(L,"replacements_logcabin");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"grasshut");
  lua_createtable(L,0,6);
  lua_pushliteral(L,"min");
  lua_pushnumber(L,10);
  lua_rawset(L,-3);
  lua_pushliteral(L,"max");
  lua_pushnumber(L,40);
  lua_rawset(L,-3);
  lua_pushliteral(L,"space_between_buildings");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"mods");
  lua_createtable(L,1,0);
  lua_pushliteral(L,"dryplants");
  lua_rawseti(L,-2,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"texture");
  lua_pushliteral(L,"dryplants_reed.png");
  lua_rawset(L,-3);
  lua_pushliteral(L,"replacement_function");
  lua_getfield(L,LUA_ENVIRONINDEX,"mg_villages");
  lua_pushliteral(L,"replacements_grasshut");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"tent");
  lua_createtable(L,0,7);
  lua_pushliteral(L,"min");
  lua_pushnumber(L,5);
  lua_rawset(L,-3);
  lua_pushliteral(L,"max");
  lua_pushnumber(L,20);
  lua_rawset(L,-3);
  lua_pushliteral(L,"space_between_buildings");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"mods");
  lua_createtable(L,1,0);
  lua_pushliteral(L,"cottages");
  lua_rawseti(L,-2,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"texture");
  lua_pushliteral(L,"wool_white.png");
  lua_rawset(L,-3);
  lua_pushliteral(L,"name_preifx");
  lua_pushliteral(L,"Tent at");
  lua_rawset(L,-3);
  lua_pushliteral(L,"replacement_function");
  lua_getfield(L,LUA_ENVIRONINDEX,"mg_villages");
  lua_pushliteral(L,"replacements_tent");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"tower");
  lua_createtable(L,0,5);
  lua_pushliteral(L,"only_single");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"name_prefix");
  lua_pushliteral(L,"Tower at ");
  lua_rawset(L,-3);
  lua_pushliteral(L,"mods");
  lua_createtable(L,1,0);
  lua_pushliteral(L,"cottages");
  lua_rawseti(L,-2,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"texture");
  lua_pushliteral(L,"default_mese.png");
  lua_rawset(L,-3);
  lua_pushliteral(L,"replacement_function");
  lua_getfield(L,LUA_ENVIRONINDEX,"mg_villages");
  lua_pushliteral(L,"replacements_tower");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"chateau");
  lua_createtable(L,0,4);
  lua_pushliteral(L,"only_single");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"name_prefix");
  lua_pushliteral(L,"Chateau ");
  lua_rawset(L,-3);
  lua_pushliteral(L,"texture");
  lua_pushliteral(L,"default_gold_block.png");
  lua_rawset(L,-3);
  lua_pushliteral(L,"replacement_function");
  lua_getfield(L,LUA_ENVIRONINDEX,"mg_villages");
  lua_pushliteral(L,"replacements_chateau");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"forge");
  lua_createtable(L,0,2);
  lua_pushliteral(L,"only_single");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"name_prefix");
  lua_pushliteral(L,"Forge at ");
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"tavern");
  lua_createtable(L,0,2);
  lua_pushliteral(L,"only_single");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"name_prefix");
  lua_pushliteral(L,"Inn at ");
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"well");
  lua_createtable(L,0,3);
  lua_pushliteral(L,"only_single");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"name_prefix");
  lua_pushliteral(L,"Well at ");
  lua_rawset(L,-3);
  lua_pushliteral(L,"replacement_function");
  lua_getfield(L,LUA_ENVIRONINDEX,"mg_villages");
  lua_pushliteral(L,"replacements_medieval");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"trader");
  lua_createtable(L,0,2);
  lua_pushliteral(L,"only_single");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"name_prefix");
  lua_pushliteral(L,"Trading post ");
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"sawmill");
  lua_createtable(L,0,2);
  lua_pushliteral(L,"only_single");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"name_prefix");
  lua_pushliteral(L,"Sawmill at ");
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"farm_tiny");
  lua_createtable(L,0,2);
  lua_pushliteral(L,"only_single");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"name_prefix");
  lua_pushliteral(L,"House ");
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"farm_full");
  lua_createtable(L,0,2);
  lua_pushliteral(L,"only_single");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"name_prefix");
  lua_pushliteral(L,"Farm ");
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"single");
  lua_createtable(L,0,2);
  lua_pushliteral(L,"only_single");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"name_prefix");
  lua_pushliteral(L,"House ");
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  assert(lua_gettop(L) - lc_nextra == 1);
  
  /* -- NOTE: Most values of village types added with mg_villages.add_village_type can still be changed later on by
   * --       changing the global variable mg_villages.village_type_data[ village_type ]
   * --       Village types where one or more of the required mods (listed in v.mods) are missing will not be
   * --       available.
   * -- You can add your own village type by i.e. calling
   * --         mg_villages.add_village_type( 'town', { min = 10, max = 30, space_between_buildings = 2, mods = {'moreblocks','homedecor'}, texture='default_diamond_block.png'} );
   * --   This will add a new village type named 'town', which will only be available if the mods moreblocks and homedecor are installed.
   * --   It will show the texture of the diamond block when showing the position of a village of that type in the map displayed by the /vmap command.
   * -- some villages require special mods as building material for their houses;
   * -- figure out which village types can be used 
   * mg_villages.add_village_type = function( type_name, v )
   * 	local found = true;
   * 	if( not( v.mods )) then
   * 		v.mods = {};
   * 	end
   * 	for _,m in ipairs( v.mods ) do
   * 		if( not( minetest.get_modpath( m ))) then
   * 			-- this village type will not be used because not all required mods are installed
   * 			return false;
   * 		end
   * 	end
   * 
   * 	if( not( v.only_single ) and (not(v.min) or not(v.max))) then
   * 		mg_villages.print( mg_villages.DEBUG_LEVEL_NORMAL, 'Error: Village type '..tostring( type_name )..' lacks size information.');
   * 		return false;
   * 	end
   * 
   * 	-- set some default values
   * 	if( not( v.sapling_divisor )) then
   * 		v.sapling_divisor = 10;
   * 	end
   * 	if( not( v.plant_type )) then
   * 		v.plant_type      = 'default:grass_5';
   * 		if( not( minetest.registered_nodes[ v.plant_type ])) then
   * 			v.plant_type = 'default:dry_shrub';
   * 		end
   * 	end
   * 	if( not( v.plant_frequency )) then
   * 		v.plant_frequency = 3;
   * 	end
   * 
   * 	-- this village type is supported by the mods installed and may be used
   * 	v.supported = 1;
   * 
   * 	mg_villages.village_type_data[ type_name ] = v;
   * 	return true;
   * end */
  lua_pushcfunction(L,lcf1_mg_villages_add_village_type);
  lua_getfield(L,LUA_ENVIRONINDEX,"mg_villages");
  lua_insert(L,-2);
  lua_pushliteral(L,"add_village_type");
  lua_insert(L,-2);
  lua_settable(L,-3);
  lua_pop(L,1);
  assert(lua_gettop(L) - lc_nextra == 1);
  
  /* -- build a list of all useable village types the mg_villages mod comes with
   * mg_villages.village_type_data = {} */
  lua_newtable(L);
  lua_getfield(L,LUA_ENVIRONINDEX,"mg_villages");
  lua_insert(L,-2);
  lua_pushliteral(L,"village_type_data");
  lua_insert(L,-2);
  lua_settable(L,-3);
  lua_pop(L,1);
  assert(lua_gettop(L) - lc_nextra == 1);
  
  /* for k,v in pairs( village_type_data_list ) do
   * internal: local f, s, var = explist */
  enum { lc16 = 1 };
  lua_getfield(L,LUA_ENVIRONINDEX,"pairs");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_call(L,1,3);
  while (1) {
    
    /* internal: local var_1, ..., var_n = f(s, var)
     *           if var_1 == nil then break end
     *           var = var_1 */
    lua_pushvalue(L,-3);
    lua_pushvalue(L,-3);
    lua_pushvalue(L,-3);
    lua_call(L,2,2);
    if (lua_isnil(L,-2)) {
      break;
    }
    lua_pushvalue(L,-2);
    lua_replace(L,-4);
    
    /* internal: local k with idx 5
     * internal: local v with idx 6 */
    
    
    /* mg_villages.add_village_type( k, v ) */
    lua_getfield(L,LUA_ENVIRONINDEX,"mg_villages");
    lua_pushliteral(L,"add_village_type");
    lua_gettable(L,-2);
    lua_remove(L,-2);
    lua_pushvalue(L,(5 + lc_nextra));
    lua_pushvalue(L,(6 + lc_nextra));
    lua_call(L,2,0);
    assert(lua_gettop(L) - lc_nextra == 6);
    
    /* internal: stack cleanup on scope exit */
    lua_pop(L,2);
  }
  lua_settop(L,(lc16 + lc_nextra));
  assert(lua_gettop(L) - lc_nextra == 1);
  
  /* village_type_data_list = nil */
  lua_pushnil(L);
  lua_replace(L,(1 + lc_nextra));
  assert(lua_gettop(L) - lc_nextra == 1);
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


int lc_pmain_mod_mg_villages_village_types(lua_State * L) {
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

