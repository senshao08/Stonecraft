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
  
  /* nssm:register_mob("nssm:manticore", {
   * 	type = "monster",
   * 	hp_max = 25,
   * 	hp_min = 24,
   * 	collisionbox = {-0.8, -0.85, -0.8, 0.8, 1.9, 0.8},
   * 	visual = "mesh",
   * 	mesh = "manticore.x",
   * 	textures = {{"manticore.png"}},
   * 	visual_size = {x=4, y=4},
   * 	makes_footstep_sound = true,
   * 	view_range = 25,
   * 	fear_height = 4,
   * 	walk_velocity = 2,
   * 	run_velocity = 4,
   *   sounds = {
   * 		random = "manticore",
   * 	},
   * 	damage = 4,
   * 	jump = true,
   * 	drops = {
   * 		{name = "nssm:life_energy",
   * 		chance = 1,
   * 		min = 3,
   * 		max = 4,},
   * 		{name = "nssm:manticore_spine",
   * 		chance = 3,
   * 		min = 2,
   * 		max = 5,},
   * 	},
   * 	armor = 100,
   * 	drawtype = "front",
   * 	water_damage = 2,
   *   rotate = 270,
   * 	lava_damage = 5,
   * 	light_damage = 0,
   * 	on_rightclick = nil,
   * 	attack_type = "dogshoot",
   * 	dogshoot_stop = true,
   *     arrow = "nssm:spine",
   *     reach = 3,
   *     shoot_interval = 2,
   *     shoot_offset = 1,
   * 	animation = {
   * 		speed_normal = 25,
   * 		speed_run = 25,
   * 		stand_start = 1,
   * 		stand_end = 40,
   * 		walk_start = 240,
   * 		walk_end = 280,
   * 		run_start = 91,
   * 		run_end = 108,
   * 		punch_start = 110,
   * 		punch_end = 143,
   *     dattack_start =180,
   *     dattack_end=230,
   * 	}
   * }) */
  lua_getfield(L,LUA_ENVIRONINDEX,"nssm");
  lua_pushliteral(L,"register_mob");
  lua_gettable(L,-2);
  lua_insert(L,-2);
  lua_pushliteral(L,"nssm:manticore");
  lua_createtable(L,0,31);
  lua_pushliteral(L,"type");
  lua_pushliteral(L,"monster");
  lua_rawset(L,-3);
  lua_pushliteral(L,"hp_max");
  lua_pushnumber(L,25);
  lua_rawset(L,-3);
  lua_pushliteral(L,"hp_min");
  lua_pushnumber(L,24);
  lua_rawset(L,-3);
  lua_pushliteral(L,"collisionbox");
  lua_createtable(L,6,0);
  lua_pushnumber(L,-0.8);
  lua_rawseti(L,-2,1);
  lua_pushnumber(L,-0.85);
  lua_rawseti(L,-2,2);
  lua_pushnumber(L,-0.8);
  lua_rawseti(L,-2,3);
  lua_pushnumber(L,0.8);
  lua_rawseti(L,-2,4);
  lua_pushnumber(L,1.9);
  lua_rawseti(L,-2,5);
  lua_pushnumber(L,0.8);
  lua_rawseti(L,-2,6);
  lua_rawset(L,-3);
  lua_pushliteral(L,"visual");
  lua_pushliteral(L,"mesh");
  lua_rawset(L,-3);
  lua_pushliteral(L,"mesh");
  lua_pushliteral(L,"manticore.x");
  lua_rawset(L,-3);
  lua_pushliteral(L,"textures");
  lua_createtable(L,1,0);
  lua_createtable(L,1,0);
  lua_pushliteral(L,"manticore.png");
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
  lua_pushnumber(L,25);
  lua_rawset(L,-3);
  lua_pushliteral(L,"fear_height");
  lua_pushnumber(L,4);
  lua_rawset(L,-3);
  lua_pushliteral(L,"walk_velocity");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"run_velocity");
  lua_pushnumber(L,4);
  lua_rawset(L,-3);
  lua_pushliteral(L,"sounds");
  lua_createtable(L,0,1);
  lua_pushliteral(L,"random");
  lua_pushliteral(L,"manticore");
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"damage");
  lua_pushnumber(L,4);
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
  lua_pushnumber(L,3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"max");
  lua_pushnumber(L,4);
  lua_rawset(L,-3);
  lua_rawseti(L,-2,1);
  lua_createtable(L,0,4);
  lua_pushliteral(L,"name");
  lua_pushliteral(L,"nssm:manticore_spine");
  lua_rawset(L,-3);
  lua_pushliteral(L,"chance");
  lua_pushnumber(L,3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"min");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"max");
  lua_pushnumber(L,5);
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
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"rotate");
  lua_pushnumber(L,270);
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
  lua_pushliteral(L,"dogshoot");
  lua_rawset(L,-3);
  lua_pushliteral(L,"dogshoot_stop");
  lua_pushboolean(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"arrow");
  lua_pushliteral(L,"nssm:spine");
  lua_rawset(L,-3);
  lua_pushliteral(L,"reach");
  lua_pushnumber(L,3);
  lua_rawset(L,-3);
  lua_pushliteral(L,"shoot_interval");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"shoot_offset");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"animation");
  lua_createtable(L,0,12);
  lua_pushliteral(L,"speed_normal");
  lua_pushnumber(L,25);
  lua_rawset(L,-3);
  lua_pushliteral(L,"speed_run");
  lua_pushnumber(L,25);
  lua_rawset(L,-3);
  lua_pushliteral(L,"stand_start");
  lua_pushnumber(L,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"stand_end");
  lua_pushnumber(L,40);
  lua_rawset(L,-3);
  lua_pushliteral(L,"walk_start");
  lua_pushnumber(L,240);
  lua_rawset(L,-3);
  lua_pushliteral(L,"walk_end");
  lua_pushnumber(L,280);
  lua_rawset(L,-3);
  lua_pushliteral(L,"run_start");
  lua_pushnumber(L,91);
  lua_rawset(L,-3);
  lua_pushliteral(L,"run_end");
  lua_pushnumber(L,108);
  lua_rawset(L,-3);
  lua_pushliteral(L,"punch_start");
  lua_pushnumber(L,110);
  lua_rawset(L,-3);
  lua_pushliteral(L,"punch_end");
  lua_pushnumber(L,143);
  lua_rawset(L,-3);
  lua_pushliteral(L,"dattack_start");
  lua_pushnumber(L,180);
  lua_rawset(L,-3);
  lua_pushliteral(L,"dattack_end");
  lua_pushnumber(L,230);
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


int lc_pmain_mod_nssm_manticore(lua_State * L) {
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


