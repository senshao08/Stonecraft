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


/* __mul metamethod handler.
 * warning: assumes indices in range LUA_REGISTRYINDEX < x < 0 are relative. */
static void lc_mul(lua_State * L, int idxa, int idxb) {
  if (lua_isnumber(L,idxa) && lua_isnumber(L,idxb)) {
    lua_pushnumber(L,lua_tonumber(L,idxa) * lua_tonumber(L,idxb));
  }
  else {
    if (luaL_getmetafield(L,idxa,"__mul")||luaL_getmetafield(L,idxb,"__mul")) {
      lua_pushvalue(L,idxa < 0 && idxa > LUA_REGISTRYINDEX ? idxa-1 : idxa);
      lua_pushvalue(L,idxb < 0 && idxb > LUA_REGISTRYINDEX ? idxb-2 : idxb);
      lua_call(L,2,1);
    }
    else {
      luaL_error(L, "attempt to perform arithmetic");
    }
  }
}


/* name: spawnplayer
 * function(player) */
static int lcf1_spawnplayer (lua_State * L) {
  lua_checkstack(L,23);
  enum { lc_nformalargs = 1 };
  lua_settop(L,1);
  
  /* if( minetest.setting_get("static_spawnpoint")) then */
  enum { lc2 = 1 };
  lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
  lua_pushliteral(L,"setting_get");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushliteral(L,"static_spawnpoint");
  lua_call(L,1,1);
  const int lc3 = lua_toboolean(L,-1);
  lua_pop(L,1);
  if (lc3) {
    
    /* return; */
    return 0;
    assert(lua_gettop(L) == 1);
  }
  lua_settop(L,lc2);
  assert(lua_gettop(L) == 1);
  
  /* -- make sure the village types are initialized
   * if( not( mg_villages.village_types )) then */
  enum { lc4 = 1 };
  lua_getfield(L,LUA_ENVIRONINDEX,"mg_villages");
  lua_pushliteral(L,"village_types");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushboolean(L,!(lua_toboolean(L,-1)));
  lua_remove(L,-2);
  const int lc5 = lua_toboolean(L,-1);
  lua_pop(L,1);
  if (lc5) {
    
    /* mg_villages.init_weights() */
    lua_getfield(L,LUA_ENVIRONINDEX,"mg_villages");
    lua_pushliteral(L,"init_weights");
    lua_gettable(L,-2);
    lua_remove(L,-2);
    lua_call(L,0,0);
    assert(lua_gettop(L) == 1);
  }
  lua_settop(L,lc4);
  assert(lua_gettop(L) == 1);
  
  /* local noise1 = minetest.get_perlin(12345, 6, 0.5, 256) */
  lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
  lua_pushliteral(L,"get_perlin");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushnumber(L,12345);
  lua_pushnumber(L,6);
  lua_pushnumber(L,0.5);
  lua_pushnumber(L,256);
  lua_call(L,4,1);
  assert(lua_gettop(L) == 2);
  
  /* local min_dist = math.huge */
  lua_getfield(L,LUA_ENVIRONINDEX,"math");
  lua_pushliteral(L,"huge");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  assert(lua_gettop(L) == 3);
  
  /* local min_pos = {x = 0, y = 3, z = 0} */
  lua_createtable(L,0,3);
  lua_pushliteral(L,"x");
  lua_pushnumber(L,0);
  lua_rawset(L,-3);
  lua_pushliteral(L,"y");
  lua_pushnumber(L,3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"z");
  lua_pushnumber(L,0);
  lua_rawset(L,-3);
  assert(lua_gettop(L) == 4);
  
  /* for bx = -20, 20 do */
  lua_pushnumber(L,-20);
  lua_pushnumber(L,20);
  if (!((lua_isnumber(L,-2) && lua_isnumber(L,-1)))) {
    luaL_error(L,"'for' limit must be a number");
  }
  double lc6_var = lua_tonumber(L,-2);
  const double lc7_limit = lua_tonumber(L,-1);
  const double lc8_step = 1;
  lua_pop(L,2);
  enum { lc9 = 4 };
  while ((((lc8_step > 0) && (lc6_var <= lc7_limit)) || ((lc8_step <= 0) && (lc6_var >= lc7_limit)))) {
    
    /* internal: local bx at index 5 */
    lua_pushnumber(L,lc6_var);
    
    /* for bz = -20, 20 do */
    lua_pushnumber(L,-20);
    lua_pushnumber(L,20);
    if (!((lua_isnumber(L,-2) && lua_isnumber(L,-1)))) {
      luaL_error(L,"'for' limit must be a number");
    }
    double lc10_var = lua_tonumber(L,-2);
    const double lc11_limit = lua_tonumber(L,-1);
    const double lc12_step = 1;
    lua_pop(L,2);
    enum { lc13 = 5 };
    while ((((lc12_step > 0) && (lc10_var <= lc11_limit)) || ((lc12_step <= 0) && (lc10_var >= lc11_limit)))) {
      
      /* internal: local bz at index 6 */
      lua_pushnumber(L,lc10_var);
      
      /* local minp = {x = -32 + 80 * bx, y = -32, z = -32 + 80 * bz} */
      lua_createtable(L,0,3);
      lua_pushliteral(L,"x");
      lua_pushnumber(L,-32);
      lua_pushnumber(L,80);
      lc_mul(L,-1,5);
      lua_remove(L,-2);
      lc_add(L,-2,-1);
      lua_remove(L,-2);
      lua_remove(L,-2);
      lua_rawset(L,-3);
      lua_pushliteral(L,"y");
      lua_pushnumber(L,-32);
      lua_rawset(L,-3);
      lua_pushliteral(L,"z");
      lua_pushnumber(L,-32);
      lua_pushnumber(L,80);
      lc_mul(L,-1,6);
      lua_remove(L,-2);
      lc_add(L,-2,-1);
      lua_remove(L,-2);
      lua_remove(L,-2);
      lua_rawset(L,-3);
      assert(lua_gettop(L) == 7);
      
      /* for _, village in ipairs(mg_villages.villages_at_point(minp, noise1)) do
       * internal: local f, s, var = explist */
      enum { lc14 = 7 };
      lua_getfield(L,LUA_ENVIRONINDEX,"ipairs");
      const int lc15 = lua_gettop(L);
      lua_getfield(L,LUA_ENVIRONINDEX,"mg_villages");
      lua_pushliteral(L,"villages_at_point");
      lua_gettable(L,-2);
      lua_remove(L,-2);
      lua_pushvalue(L,7);
      lua_pushvalue(L,2);
      lua_call(L,2,LUA_MULTRET);
      lua_call(L,(lua_gettop(L) - lc15),3);
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
        
        /* internal: local _ with idx 11
         * internal: local village with idx 12 */
        
        
        /* if math.abs(village.vx) + math.abs(village.vz) < min_dist then */
        enum { lc16 = 12 };
        lua_getfield(L,LUA_ENVIRONINDEX,"math");
        lua_pushliteral(L,"abs");
        lua_gettable(L,-2);
        lua_remove(L,-2);
        lua_pushliteral(L,"vx");
        lua_gettable(L,12);
        lua_call(L,1,1);
        lua_getfield(L,LUA_ENVIRONINDEX,"math");
        lua_pushliteral(L,"abs");
        lua_gettable(L,-2);
        lua_remove(L,-2);
        lua_pushliteral(L,"vz");
        lua_gettable(L,12);
        lua_call(L,1,1);
        lc_add(L,-2,-1);
        lua_remove(L,-2);
        lua_remove(L,-2);
        const int lc17 = lua_lessthan(L,-1,3);
        lua_pop(L,1);
        lua_pushboolean(L,lc17);
        const int lc18 = lua_toboolean(L,-1);
        lua_pop(L,1);
        if (lc18) {
          
          /* min_pos = {x = village.vx, y = village.vh + 2, z = village.vz} */
          lua_createtable(L,0,3);
          lua_pushliteral(L,"x");
          lua_pushliteral(L,"vx");
          lua_gettable(L,12);
          lua_rawset(L,-3);
          lua_pushliteral(L,"y");
          lua_pushliteral(L,"vh");
          lua_gettable(L,12);
          lua_pushnumber(L,2);
          lc_add(L,-2,-1);
          lua_remove(L,-2);
          lua_remove(L,-2);
          lua_rawset(L,-3);
          lua_pushliteral(L,"z");
          lua_pushliteral(L,"vz");
          lua_gettable(L,12);
          lua_rawset(L,-3);
          lua_replace(L,4);
          assert(lua_gettop(L) == 12);
          
          /* -- some villages are later adjusted in height; adapt these changes
           * local village_id = tostring( village.vx )..':'..tostring( village.vz ) */
          lua_getfield(L,LUA_ENVIRONINDEX,"tostring");
          lua_pushliteral(L,"vx");
          lua_gettable(L,12);
          lua_call(L,1,1);
          lua_pushliteral(L,":");
          lua_getfield(L,LUA_ENVIRONINDEX,"tostring");
          lua_pushliteral(L,"vz");
          lua_gettable(L,12);
          lua_call(L,1,1);
          lua_concat(L,2);
          lua_concat(L,2);
          assert(lua_gettop(L) == 13);
          
          /* if(   mg_villages.all_villages[ village_id ] 
           * 				  and mg_villages.all_villages[ village_id ].optimal_height ) then */
          enum { lc19 = 13 };
          lua_getfield(L,LUA_ENVIRONINDEX,"mg_villages");
          lua_pushliteral(L,"all_villages");
          lua_gettable(L,-2);
          lua_remove(L,-2);
          lua_pushvalue(L,13);
          lua_gettable(L,-2);
          lua_remove(L,-2);
          if (lua_toboolean(L,-1)) {
            lua_pop(L,1);
            lua_getfield(L,LUA_ENVIRONINDEX,"mg_villages");
            lua_pushliteral(L,"all_villages");
            lua_gettable(L,-2);
            lua_remove(L,-2);
            lua_pushvalue(L,13);
            lua_gettable(L,-2);
            lua_remove(L,-2);
            lua_pushliteral(L,"optimal_height");
            lua_gettable(L,-2);
            lua_remove(L,-2);
          }
          const int lc20 = lua_toboolean(L,-1);
          lua_pop(L,1);
          if (lc20) {
            
            /* min_pos.y = mg_villages.all_villages[ village_id ].vh + 2 */
            lua_getfield(L,LUA_ENVIRONINDEX,"mg_villages");
            lua_pushliteral(L,"all_villages");
            lua_gettable(L,-2);
            lua_remove(L,-2);
            lua_pushvalue(L,13);
            lua_gettable(L,-2);
            lua_remove(L,-2);
            lua_pushliteral(L,"vh");
            lua_gettable(L,-2);
            lua_remove(L,-2);
            lua_pushnumber(L,2);
            lc_add(L,-2,-1);
            lua_remove(L,-2);
            lua_remove(L,-2);
            lua_pushliteral(L,"y");
            lua_insert(L,-2);
            lua_settable(L,4);
            assert(lua_gettop(L) == 13);
          }
          else {
            
            /* else
             * min_pos.y = 1+2 */
            lua_pushnumber(L,3);
            lua_pushliteral(L,"y");
            lua_insert(L,-2);
            lua_settable(L,4);
            assert(lua_gettop(L) == 13);
          }
          lua_settop(L,lc19);
          assert(lua_gettop(L) == 13);
          
          /* min_dist = math.abs(village.vx) + math.abs(village.vz) */
          lua_getfield(L,LUA_ENVIRONINDEX,"math");
          lua_pushliteral(L,"abs");
          lua_gettable(L,-2);
          lua_remove(L,-2);
          lua_pushliteral(L,"vx");
          lua_gettable(L,12);
          lua_call(L,1,1);
          lua_getfield(L,LUA_ENVIRONINDEX,"math");
          lua_pushliteral(L,"abs");
          lua_gettable(L,-2);
          lua_remove(L,-2);
          lua_pushliteral(L,"vz");
          lua_gettable(L,12);
          lua_call(L,1,1);
          lc_add(L,-2,-1);
          lua_remove(L,-2);
          lua_remove(L,-2);
          lua_replace(L,3);
          assert(lua_gettop(L) == 13);
        }
        lua_settop(L,lc16);
        assert(lua_gettop(L) == 12);
        
        /* internal: stack cleanup on scope exit */
        lua_pop(L,2);
      }
      lua_settop(L,lc14);
      assert(lua_gettop(L) == 7);
      
      /* internal: stack cleanup on scope exit */
      lua_pop(L,2);
      lc10_var += lc12_step;
    }
    lua_settop(L,lc13);
    assert(lua_gettop(L) == 5);
    
    /* internal: stack cleanup on scope exit */
    lua_pop(L,1);
    lc6_var += lc8_step;
  }
  lua_settop(L,lc9);
  assert(lua_gettop(L) == 4);
  
  /* player:setpos(min_pos) */
  lua_pushvalue(L,1);
  lua_pushliteral(L,"setpos");
  lua_gettable(L,-2);
  lua_insert(L,-2);
  lua_pushvalue(L,4);
  lua_call(L,2,0);
  assert(lua_gettop(L) == 4);
  return 0;
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


/* function(player) */
static int lcf21 (lua_State * L) {
  enum { lc_nformalargs = 1 };
  lua_settop(L,1);
  
  /* spawnplayer(player) */
  lc_getupvalue(L,lua_upvalueindex(1),0,1);
  lua_pushvalue(L,1);
  lua_call(L,1,0);
  assert(lua_gettop(L) == 1);
  return 0;
}


/* function(player) */
static int lcf22 (lua_State * L) {
  enum { lc_nformalargs = 1 };
  lua_settop(L,1);
  
  /* spawnplayer(player) */
  lc_getupvalue(L,lua_upvalueindex(1),0,1);
  lua_pushvalue(L,1);
  lua_call(L,1,0);
  assert(lua_gettop(L) == 1);
  
  /* return true */
  lua_pushboolean(L,1);
  return 1;
  assert(lua_gettop(L) == 1);
}


/* name: (main)
 * function(...) */
static int lcf_main (lua_State * L) {
  enum { lc_nformalargs = 0 };
  const int lc_nactualargs = lua_gettop(L);
  const int lc_nextra = (lc_nactualargs - lc_nformalargs);
  
  /* local function spawnplayer(player)
   * 	if( minetest.setting_get("static_spawnpoint")) then
   * 		return;
   * 	end
   * 
   * 	-- make sure the village types are initialized
   * 	if( not( mg_villages.village_types )) then
   * 		mg_villages.init_weights();
   * 	end
   * 
   * 	local noise1 = minetest.get_perlin(12345, 6, 0.5, 256)
   * 	local min_dist = math.huge
   * 	local min_pos = {x = 0, y = 3, z = 0}
   * 	for bx = -20, 20 do
   * 	for bz = -20, 20 do
   * 		local minp = {x = -32 + 80 * bx, y = -32, z = -32 + 80 * bz}
   * 		for _, village in ipairs(mg_villages.villages_at_point(minp, noise1)) do
   * 			if math.abs(village.vx) + math.abs(village.vz) < min_dist then
   * 				min_pos = {x = village.vx, y = village.vh + 2, z = village.vz}
   * 				-- some villages are later adjusted in height; adapt these changes
   * 				local village_id = tostring( village.vx )..':'..tostring( village.vz );
   * 				if(   mg_villages.all_villages[ village_id ] 
   * 				  and mg_villages.all_villages[ village_id ].optimal_height ) then
   * 					min_pos.y = mg_villages.all_villages[ village_id ].vh + 2;
   * 				-- the first villages will have a height of 1 in order to make sure that the player does not end up embedded in stone
   * 				else
   * 					min_pos.y = 1+2;
   * 				end
   * 				min_dist = math.abs(village.vx) + math.abs(village.vz)
   * 			end
   * 		end
   * 	end
   * 	end
   * 	player:setpos(min_pos)
   * end */
  lc_newclosuretable(L,lua_upvalueindex(1));
  enum { lc1 = 1 };
  assert((lua_gettop(L) == (lc1 + lc_nextra)));
  lua_pushcfunction(L,lcf1_spawnplayer);
  lua_rawseti(L,(lc1 + lc_nextra),1);
  assert(lua_gettop(L) - lc_nextra == 1);
  
  /* minetest.register_on_newplayer(function(player)
   * 	spawnplayer(player)
   * end) */
  lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
  lua_pushliteral(L,"register_on_newplayer");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushvalue(L,(lc1 + lc_nextra));
  lua_pushcclosure(L,lcf21,1);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1);
  
  /* minetest.register_on_respawnplayer(function(player)
   * 	spawnplayer(player)
   * 	return true
   * end) */
  lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
  lua_pushliteral(L,"register_on_respawnplayer");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushvalue(L,(lc1 + lc_nextra));
  lua_pushcclosure(L,lcf22,1);
  lua_call(L,1,0);
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


int lc_pmain_mod_mg_villages_spawn_player(lua_State * L) {
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



