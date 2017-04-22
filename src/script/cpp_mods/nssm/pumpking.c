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

/* function(self,pos) */
static int lcf1 (lua_State * L) {
  enum { lc_nformalargs = 2 };
  lua_settop(L,2);
  
  /* nssm:explosion(pos, 3, 0, 1, self.sounds.explode) */
  lua_getfield(L,LUA_ENVIRONINDEX,"nssm");
  lua_pushliteral(L,"explosion");
  lua_gettable(L,-2);
  lua_insert(L,-2);
  lua_pushvalue(L,2);
  lua_pushnumber(L,3);
  lua_pushnumber(L,0);
  lua_pushnumber(L,1);
  lua_pushliteral(L,"sounds");
  lua_gettable(L,1);
  lua_pushliteral(L,"explode");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_call(L,6,0);
  assert(lua_gettop(L) == 2);
  return 0;
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


/* function(self) */
static int lcf10 (lua_State * L) {
  enum { lc_nformalargs = 1 };
  lua_settop(L,1);
  
  /* if self.timer >3 then */
  enum { lc2 = 1 };
  lua_pushnumber(L,3);
  lua_pushliteral(L,"timer");
  lua_gettable(L,1);
  const int lc3 = lua_lessthan(L,-2,-1);
  lua_pop(L,2);
  lua_pushboolean(L,lc3);
  const int lc4 = lua_toboolean(L,-1);
  lua_pop(L,1);
  if (lc4) {
    
    /* self.timer = 0 */
    lua_pushnumber(L,0);
    lua_pushliteral(L,"timer");
    lua_insert(L,-2);
    lua_settable(L,1);
    assert(lua_gettop(L) == 1);
    
    /* local s = self.object:getpos() */
    lua_pushliteral(L,"object");
    lua_gettable(L,1);
    lua_pushliteral(L,"getpos");
    lua_gettable(L,-2);
    lua_insert(L,-2);
    lua_call(L,1,1);
    assert(lua_gettop(L) == 2);
    
    /* local p = self.attack:getpos() */
    lua_pushliteral(L,"attack");
    lua_gettable(L,1);
    lua_pushliteral(L,"getpos");
    lua_gettable(L,-2);
    lua_insert(L,-2);
    lua_call(L,1,1);
    assert(lua_gettop(L) == 3);
    
    /* p.y = p.y + 1.5 */
    lua_pushliteral(L,"y");
    lua_gettable(L,3);
    lua_pushnumber(L,1.5);
    lc_add(L,-2,-1);
    lua_remove(L,-2);
    lua_remove(L,-2);
    lua_pushliteral(L,"y");
    lua_insert(L,-2);
    lua_settable(L,3);
    assert(lua_gettop(L) == 3);
    
    /* s.y = s.y + 1.5 */
    lua_pushliteral(L,"y");
    lua_gettable(L,2);
    lua_pushnumber(L,1.5);
    lc_add(L,-2,-1);
    lua_remove(L,-2);
    lua_remove(L,-2);
    lua_pushliteral(L,"y");
    lua_insert(L,-2);
    lua_settable(L,2);
    assert(lua_gettop(L) == 3);
    
    /* if minetest.line_of_sight(p, s) == true then */
    enum { lc5 = 3 };
    lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
    lua_pushliteral(L,"line_of_sight");
    lua_gettable(L,-2);
    lua_remove(L,-2);
    lua_pushvalue(L,3);
    lua_pushvalue(L,2);
    lua_call(L,2,1);
    lua_pushboolean(L,1);
    const int lc6 = lua_equal(L,-2,-1);
    lua_pop(L,2);
    lua_pushboolean(L,lc6);
    const int lc7 = lua_toboolean(L,-1);
    lua_pop(L,1);
    if (lc7) {
      
      /* -- play attack sound
       * if self.sounds.attack then */
      enum { lc8 = 3 };
      lua_pushliteral(L,"sounds");
      lua_gettable(L,1);
      lua_pushliteral(L,"attack");
      lua_gettable(L,-2);
      lua_remove(L,-2);
      const int lc9 = lua_toboolean(L,-1);
      lua_pop(L,1);
      if (lc9) {
        
        /* minetest.sound_play(self.sounds.attack, {
         * 					object = self.object,
         * 					max_hear_distance = self.sounds.distance
         * 					}) */
        lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
        lua_pushliteral(L,"sound_play");
        lua_gettable(L,-2);
        lua_remove(L,-2);
        lua_pushliteral(L,"sounds");
        lua_gettable(L,1);
        lua_pushliteral(L,"attack");
        lua_gettable(L,-2);
        lua_remove(L,-2);
        lua_createtable(L,0,2);
        lua_pushliteral(L,"object");
        lua_pushliteral(L,"object");
        lua_gettable(L,1);
        lua_rawset(L,-3);
        lua_pushliteral(L,"max_hear_distance");
        lua_pushliteral(L,"sounds");
        lua_gettable(L,1);
        lua_pushliteral(L,"distance");
        lua_gettable(L,-2);
        lua_remove(L,-2);
        lua_rawset(L,-3);
        lua_call(L,2,0);
        assert(lua_gettop(L) == 3);
      }
      lua_settop(L,lc8);
      assert(lua_gettop(L) == 3);
      
      /* local pos1 = {x=s.x+math.random(-1,1), y=s.y-1.5, z=s.z+math.random(-1,1)} */
      lua_createtable(L,0,3);
      lua_pushliteral(L,"x");
      lua_pushliteral(L,"x");
      lua_gettable(L,2);
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
      lua_pushliteral(L,"y");
      lua_gettable(L,2);
      lua_pushnumber(L,1.5);
      lc_sub(L,-2,-1);
      lua_remove(L,-2);
      lua_remove(L,-2);
      lua_rawset(L,-3);
      lua_pushliteral(L,"z");
      lua_pushliteral(L,"z");
      lua_gettable(L,2);
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
      assert(lua_gettop(L) == 4);
      
      /* minetest.set_node(pos1, {name="nssm:pumpbomb"}) */
      lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
      lua_pushliteral(L,"set_node");
      lua_gettable(L,-2);
      lua_remove(L,-2);
      lua_pushvalue(L,4);
      lua_createtable(L,0,1);
      lua_pushliteral(L,"name");
      lua_pushliteral(L,"nssm:pumpbomb");
      lua_rawset(L,-3);
      lua_call(L,2,0);
      assert(lua_gettop(L) == 4);
      
      /* minetest.get_node_timer(pos1):start(2) */
      lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
      lua_pushliteral(L,"get_node_timer");
      lua_gettable(L,-2);
      lua_remove(L,-2);
      lua_pushvalue(L,4);
      lua_call(L,1,1);
      lua_pushliteral(L,"start");
      lua_gettable(L,-2);
      lua_insert(L,-2);
      lua_pushnumber(L,2);
      lua_call(L,2,0);
      assert(lua_gettop(L) == 4);
    }
    lua_settop(L,lc5);
    assert(lua_gettop(L) == 3);
  }
  lua_settop(L,lc2);
  assert(lua_gettop(L) == 1);
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
  
  /* nssm:register_mob("nssm:pumpking", {
   * 	type = "monster",
   * 	hp_max = 100,
   * 	hp_min = 100,
   * 	collisionbox = {-0.4, 0.00, -0.4, 0.4, 3.2, 0.4},
   * 	visual = "mesh",
   * 	mesh = "pumpking.x",
   * 	textures = {{"pumpking.png"}},
   * 	visual_size = {x=2.5, y=2.5},
   * 	makes_footstep_sound = true,
   * 	lifetimer=500,
   * 	rotate=270,
   * 	fear_height = 4,
   * 	view_range = 35,
   * 	walk_velocity = 2,
   * 	run_velocity = 4,
   *     sounds = {
   * 		random = "king",
   * 		explode = "tnt_explode",
   * 	},
   * 	damage = 9,
   * 	jump = true,
   * 	drops = {
   * 		{name = "nssm:life_energy",
   * 		chance = 1,
   * 		min = 7,
   * 		max = 9,},
   * 		{name = "nssm:cursed_pumpkin_seed",
   * 		chance = 1,
   * 		min = 1,
   * 		max = 1,},
   * 	},
   * 	armor =50,
   * 	drawtype = "front",
   * 	water_damage = 2,
   * 	lava_damage = 5,
   * 	light_damage = 0,
   * 	on_rightclick = nil,
   * 	attack_type = "dogfight",
   * 	animation = {
   * 		stand_start = 165,		stand_end = 210,
   * 		walk_start = 220,		walk_end = 260,
   * 		run_start = 220,		run_end = 260,
   * 		punch_start = 300,		punch_end = 330,
   * 		speed_normal = 15,		speed_run = 15,
   * 	},
   * 	on_die=function(self,pos)
   * 		nssm:explosion(pos, 3, 0, 1, self.sounds.explode)
   * 	end,
   * 	custom_attack = function(self)
   * 		if self.timer >3 then
   * 			self.timer = 0
   * 			local s = self.object:getpos()
   * 			local p = self.attack:getpos()
   * 			p.y = p.y + 1.5
   * 			s.y = s.y + 1.5
   * 			if minetest.line_of_sight(p, s) == true then
   * 				-- play attack sound
   * 				if self.sounds.attack then
   * 					minetest.sound_play(self.sounds.attack, {
   * 					object = self.object,
   * 					max_hear_distance = self.sounds.distance
   * 					})
   * 				end
   * 				local pos1 = {x=s.x+math.random(-1,1), y=s.y-1.5, z=s.z+math.random(-1,1)}
   * 				minetest.set_node(pos1, {name="nssm:pumpbomb"})
   * 				minetest.get_node_timer(pos1):start(2)
   * 			end
   * 		end
   * 	end
   * }) */
  lua_getfield(L,LUA_ENVIRONINDEX,"nssm");
  lua_pushliteral(L,"register_mob");
  lua_gettable(L,-2);
  lua_insert(L,-2);
  lua_pushliteral(L,"nssm:pumpking");
  lua_createtable(L,0,29);
  lua_pushliteral(L,"type");
  lua_pushliteral(L,"monster");
  lua_rawset(L,-3);
  lua_pushliteral(L,"hp_max");
  lua_pushnumber(L,100);
  lua_rawset(L,-3);
  lua_pushliteral(L,"hp_min");
  lua_pushnumber(L,100);
  lua_rawset(L,-3);
  lua_pushliteral(L,"collisionbox");
  lua_createtable(L,6,0);
  lua_pushnumber(L,-0.4);
  lua_rawseti(L,-2,1);
  lua_pushnumber(L,0);
  lua_rawseti(L,-2,2);
  lua_pushnumber(L,-0.4);
  lua_rawseti(L,-2,3);
  lua_pushnumber(L,0.4);
  lua_rawseti(L,-2,4);
  lua_pushnumber(L,3.2);
  lua_rawseti(L,-2,5);
  lua_pushnumber(L,0.4);
  lua_rawseti(L,-2,6);
  lua_rawset(L,-3);
  lua_pushliteral(L,"visual");
  lua_pushliteral(L,"mesh");
  lua_rawset(L,-3);
  lua_pushliteral(L,"mesh");
  lua_pushliteral(L,"pumpking.x");
  lua_rawset(L,-3);
  lua_pushliteral(L,"textures");
  lua_createtable(L,1,0);
  lua_createtable(L,1,0);
  lua_pushliteral(L,"pumpking.png");
  lua_rawseti(L,-2,1);
  lua_rawseti(L,-2,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"visual_size");
  lua_createtable(L,0,2);
  lua_pushliteral(L,"x");
  lua_pushnumber(L,2.5);
  lua_rawset(L,-3);
  lua_pushliteral(L,"y");
  lua_pushnumber(L,2.5);
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"makes_footstep_sound");
  lua_pushboolean(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"lifetimer");
  lua_pushnumber(L,500);
  lua_rawset(L,-3);
  lua_pushliteral(L,"rotate");
  lua_pushnumber(L,270);
  lua_rawset(L,-3);
  lua_pushliteral(L,"fear_height");
  lua_pushnumber(L,4);
  lua_rawset(L,-3);
  lua_pushliteral(L,"view_range");
  lua_pushnumber(L,35);
  lua_rawset(L,-3);
  lua_pushliteral(L,"walk_velocity");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"run_velocity");
  lua_pushnumber(L,4);
  lua_rawset(L,-3);
  lua_pushliteral(L,"sounds");
  lua_createtable(L,0,2);
  lua_pushliteral(L,"random");
  lua_pushliteral(L,"king");
  lua_rawset(L,-3);
  lua_pushliteral(L,"explode");
  lua_pushliteral(L,"tnt_explode");
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"damage");
  lua_pushnumber(L,9);
  lua_rawset(L,-3);
  lua_pushliteral(L,"jump");
  lua_pushboolean(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"drops");
  lua_createtable(L,2,0);
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
  lua_pushnumber(L,9);
  lua_rawset(L,-3);
  lua_rawseti(L,-2,1);
  lua_createtable(L,0,4);
  lua_pushliteral(L,"name");
  lua_pushliteral(L,"nssm:cursed_pumpkin_seed");
  lua_rawset(L,-3);
  lua_pushliteral(L,"chance");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"min");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"max");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_rawseti(L,-2,2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"armor");
  lua_pushnumber(L,50);
  lua_rawset(L,-3);
  lua_pushliteral(L,"drawtype");
  lua_pushliteral(L,"front");
  lua_rawset(L,-3);
  lua_pushliteral(L,"water_damage");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"lava_damage");
  lua_pushnumber(L,5);
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
  lua_pushliteral(L,"animation");
  lua_createtable(L,0,10);
  lua_pushliteral(L,"stand_start");
  lua_pushnumber(L,165);
  lua_rawset(L,-3);
  lua_pushliteral(L,"stand_end");
  lua_pushnumber(L,210);
  lua_rawset(L,-3);
  lua_pushliteral(L,"walk_start");
  lua_pushnumber(L,220);
  lua_rawset(L,-3);
  lua_pushliteral(L,"walk_end");
  lua_pushnumber(L,260);
  lua_rawset(L,-3);
  lua_pushliteral(L,"run_start");
  lua_pushnumber(L,220);
  lua_rawset(L,-3);
  lua_pushliteral(L,"run_end");
  lua_pushnumber(L,260);
  lua_rawset(L,-3);
  lua_pushliteral(L,"punch_start");
  lua_pushnumber(L,300);
  lua_rawset(L,-3);
  lua_pushliteral(L,"punch_end");
  lua_pushnumber(L,330);
  lua_rawset(L,-3);
  lua_pushliteral(L,"speed_normal");
  lua_pushnumber(L,15);
  lua_rawset(L,-3);
  lua_pushliteral(L,"speed_run");
  lua_pushnumber(L,15);
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"on_die");
  lua_pushcfunction(L,lcf1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"custom_attack");
  lua_pushcfunction(L,lcf10);
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


int lc_pmain_mod_nssm_pumpking(lua_State * L) {
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


