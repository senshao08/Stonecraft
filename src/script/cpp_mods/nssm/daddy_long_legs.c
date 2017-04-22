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
  
  /* nssm:register_mob("nssm:daddy_long_legs", {
   * 	type = "monster",
   * 	hp_max = 19,
   * 	hp_min = 16,
   * 	collisionbox = {-0.4, 0.00, -0.4, 0.4, 0.6, 0.4},
   * 	visual = "mesh",
   * 	mesh = "daddy_long_legs.x",
   * 	textures = {{"daddy_long_legs.png"}},
   * 	visual_size = {x=8, y=8},
   * 	makes_footstep_sound = true,
   * 	view_range = 12,
   * 	walk_velocity = 1.5,
   * 	fear_height = 4,
   * 	run_velocity = 3.3,
   *   	rotate = 90,
   *   	sounds = {
   * 		random = "daddy",
   * 	},
   * 	damage = 3,
   * 	jump = true,
   * 	drops = {
   * 		{name = "nssm:life_energy",
   * 		chance = 1,
   * 		min = 1,
   * 		max = 2,},
   * 		{name = "nssm:spider_leg",
   * 		chance = 3,
   * 		min = 1,
   * 		max = 8,},
   * 	},
   * 	armor = 100,
   * 	drawtype = "front",
   * 	water_damage = 1,
   * 	lava_damage = 7,
   * 	light_damage = 0,
   * 	on_rightclick = nil,
   * 	attack_type = "dogfight",
   * 	animation = {
   * 		speed_normal = 20,
   * 		speed_run = 25,
   * 		stand_start = 1,
   * 		stand_end = 60,
   * 		walk_start = 80,
   * 		walk_end = 120,
   * 		run_start = 80,
   * 		run_end = 120,
   * 		punch_start = 140,
   * 		punch_end = 165,
   * 	}
   * }) */
  lua_getfield(L,LUA_ENVIRONINDEX,"nssm");
  lua_pushliteral(L,"register_mob");
  lua_gettable(L,-2);
  lua_insert(L,-2);
  lua_pushliteral(L,"nssm:daddy_long_legs");
  lua_createtable(L,0,26);
  lua_pushliteral(L,"type");
  lua_pushliteral(L,"monster");
  lua_rawset(L,-3);
  lua_pushliteral(L,"hp_max");
  lua_pushnumber(L,19);
  lua_rawset(L,-3);
  lua_pushliteral(L,"hp_min");
  lua_pushnumber(L,16);
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
  lua_pushnumber(L,0.6);
  lua_rawseti(L,-2,5);
  lua_pushnumber(L,0.4);
  lua_rawseti(L,-2,6);
  lua_rawset(L,-3);
  lua_pushliteral(L,"visual");
  lua_pushliteral(L,"mesh");
  lua_rawset(L,-3);
  lua_pushliteral(L,"mesh");
  lua_pushliteral(L,"daddy_long_legs.x");
  lua_rawset(L,-3);
  lua_pushliteral(L,"textures");
  lua_createtable(L,1,0);
  lua_createtable(L,1,0);
  lua_pushliteral(L,"daddy_long_legs.png");
  lua_rawseti(L,-2,1);
  lua_rawseti(L,-2,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"visual_size");
  lua_createtable(L,0,2);
  lua_pushliteral(L,"x");
  lua_pushnumber(L,8);
  lua_rawset(L,-3);
  lua_pushliteral(L,"y");
  lua_pushnumber(L,8);
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"makes_footstep_sound");
  lua_pushboolean(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"view_range");
  lua_pushnumber(L,12);
  lua_rawset(L,-3);
  lua_pushliteral(L,"walk_velocity");
  lua_pushnumber(L,1.5);
  lua_rawset(L,-3);
  lua_pushliteral(L,"fear_height");
  lua_pushnumber(L,4);
  lua_rawset(L,-3);
  lua_pushliteral(L,"run_velocity");
  lua_pushnumber(L,3.3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"rotate");
  lua_pushnumber(L,90);
  lua_rawset(L,-3);
  lua_pushliteral(L,"sounds");
  lua_createtable(L,0,1);
  lua_pushliteral(L,"random");
  lua_pushliteral(L,"daddy");
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"damage");
  lua_pushnumber(L,3);
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
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"max");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_rawseti(L,-2,1);
  lua_createtable(L,0,4);
  lua_pushliteral(L,"name");
  lua_pushliteral(L,"nssm:spider_leg");
  lua_rawset(L,-3);
  lua_pushliteral(L,"chance");
  lua_pushnumber(L,3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"min");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"max");
  lua_pushnumber(L,8);
  lua_rawset(L,-3);
  lua_rawseti(L,-2,2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"armor");
  lua_pushnumber(L,100);
  lua_rawset(L,-3);
  lua_pushliteral(L,"drawtype");
  lua_pushliteral(L,"front");
  lua_rawset(L,-3);
  lua_pushliteral(L,"water_damage");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"lava_damage");
  lua_pushnumber(L,7);
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
  lua_pushliteral(L,"speed_normal");
  lua_pushnumber(L,20);
  lua_rawset(L,-3);
  lua_pushliteral(L,"speed_run");
  lua_pushnumber(L,25);
  lua_rawset(L,-3);
  lua_pushliteral(L,"stand_start");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"stand_end");
  lua_pushnumber(L,60);
  lua_rawset(L,-3);
  lua_pushliteral(L,"walk_start");
  lua_pushnumber(L,80);
  lua_rawset(L,-3);
  lua_pushliteral(L,"walk_end");
  lua_pushnumber(L,120);
  lua_rawset(L,-3);
  lua_pushliteral(L,"run_start");
  lua_pushnumber(L,80);
  lua_rawset(L,-3);
  lua_pushliteral(L,"run_end");
  lua_pushnumber(L,120);
  lua_rawset(L,-3);
  lua_pushliteral(L,"punch_start");
  lua_pushnumber(L,140);
  lua_rawset(L,-3);
  lua_pushliteral(L,"punch_end");
  lua_pushnumber(L,165);
  lua_rawset(L,-3);
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


int lc_pmain_mod_nssm_daddy_long_legs(lua_State * L) {
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


