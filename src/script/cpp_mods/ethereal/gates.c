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
  const int lc_nactualargs = lua_gettop(L);
  const int lc_nextra = (lc_nactualargs - lc_nformalargs);
  
  /* local S = ethereal.intllib */
  lua_getfield(L,LUA_ENVIRONINDEX,"ethereal");
  lua_pushliteral(L,"intllib");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  assert(lua_gettop(L) - lc_nextra == 1);
  
  /* -- register Ethereal wood type gates
   * doors.register_fencegate("ethereal:fencegate_scorched", {
   * 	description = S("Scorched Wood Fence Gate"),
   * 	texture = "scorched_tree.png",
   * 	material = "ethereal:scorched_tree",
   * 	groups = {choppy = 2, oddly_breakable_by_hand = 2, flammable = 2}
   * }) */
  lua_getfield(L,LUA_ENVIRONINDEX,"doors");
  lua_pushliteral(L,"register_fencegate");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushliteral(L,"ethereal:fencegate_scorched");
  lua_createtable(L,0,4);
  lua_pushliteral(L,"description");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"Scorched Wood Fence Gate");
  lua_call(L,1,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"texture");
  lua_pushliteral(L,"scorched_tree.png");
  lua_rawset(L,-3);
  lua_pushliteral(L,"material");
  lua_pushliteral(L,"ethereal:scorched_tree");
  lua_rawset(L,-3);
  lua_pushliteral(L,"groups");
  lua_createtable(L,0,3);
  lua_pushliteral(L,"choppy");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"oddly_breakable_by_hand");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"flammable");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_call(L,2,0);
  assert(lua_gettop(L) - lc_nextra == 1);
  
  /* doors.register_fencegate("ethereal:fencegate_frostwood", {
   * 	description = S("Frost Wood Fence Gate"),
   * 	texture = "frost_wood.png",
   * 	material = "ethereal:frost_wood",
   * 	groups = {choppy = 2, oddly_breakable_by_hand = 2, flammable = 2}
   * }) */
  lua_getfield(L,LUA_ENVIRONINDEX,"doors");
  lua_pushliteral(L,"register_fencegate");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushliteral(L,"ethereal:fencegate_frostwood");
  lua_createtable(L,0,4);
  lua_pushliteral(L,"description");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"Frost Wood Fence Gate");
  lua_call(L,1,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"texture");
  lua_pushliteral(L,"frost_wood.png");
  lua_rawset(L,-3);
  lua_pushliteral(L,"material");
  lua_pushliteral(L,"ethereal:frost_wood");
  lua_rawset(L,-3);
  lua_pushliteral(L,"groups");
  lua_createtable(L,0,3);
  lua_pushliteral(L,"choppy");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"oddly_breakable_by_hand");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"flammable");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_call(L,2,0);
  assert(lua_gettop(L) - lc_nextra == 1);
  
  /* doors.register_fencegate("ethereal:fencegate_redwood", {
   * 	description = S("Redwood Fence Gate"),
   * 	texture = "redwood_wood.png",
   * 	material = "ethereal:redwood_wood",
   * 	groups = {choppy = 2, oddly_breakable_by_hand = 2, flammable = 2}
   * }) */
  lua_getfield(L,LUA_ENVIRONINDEX,"doors");
  lua_pushliteral(L,"register_fencegate");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushliteral(L,"ethereal:fencegate_redwood");
  lua_createtable(L,0,4);
  lua_pushliteral(L,"description");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"Redwood Fence Gate");
  lua_call(L,1,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"texture");
  lua_pushliteral(L,"redwood_wood.png");
  lua_rawset(L,-3);
  lua_pushliteral(L,"material");
  lua_pushliteral(L,"ethereal:redwood_wood");
  lua_rawset(L,-3);
  lua_pushliteral(L,"groups");
  lua_createtable(L,0,3);
  lua_pushliteral(L,"choppy");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"oddly_breakable_by_hand");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"flammable");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_call(L,2,0);
  assert(lua_gettop(L) - lc_nextra == 1);
  
  /* doors.register_fencegate("ethereal:fencegate_willow", {
   * 	description = S("Willow Wood Fence Gate"),
   * 	texture = "willow_wood.png",
   * 	material = "ethereal:willow_wood",
   * 	groups = {choppy = 2, oddly_breakable_by_hand = 2, flammable = 2}
   * }) */
  lua_getfield(L,LUA_ENVIRONINDEX,"doors");
  lua_pushliteral(L,"register_fencegate");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushliteral(L,"ethereal:fencegate_willow");
  lua_createtable(L,0,4);
  lua_pushliteral(L,"description");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"Willow Wood Fence Gate");
  lua_call(L,1,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"texture");
  lua_pushliteral(L,"willow_wood.png");
  lua_rawset(L,-3);
  lua_pushliteral(L,"material");
  lua_pushliteral(L,"ethereal:willow_wood");
  lua_rawset(L,-3);
  lua_pushliteral(L,"groups");
  lua_createtable(L,0,3);
  lua_pushliteral(L,"choppy");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"oddly_breakable_by_hand");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"flammable");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_call(L,2,0);
  assert(lua_gettop(L) - lc_nextra == 1);
  
  /* doors.register_fencegate("ethereal:fencegate_yellowwood", {
   * 	description = S("Healing Wood Fence Gate"),
   * 	texture = "yellow_wood.png",
   * 	material = "ethereal:yellow_wood",
   * 	groups = {choppy = 2, oddly_breakable_by_hand = 2, flammable = 2}
   * }) */
  lua_getfield(L,LUA_ENVIRONINDEX,"doors");
  lua_pushliteral(L,"register_fencegate");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushliteral(L,"ethereal:fencegate_yellowwood");
  lua_createtable(L,0,4);
  lua_pushliteral(L,"description");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"Healing Wood Fence Gate");
  lua_call(L,1,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"texture");
  lua_pushliteral(L,"yellow_wood.png");
  lua_rawset(L,-3);
  lua_pushliteral(L,"material");
  lua_pushliteral(L,"ethereal:yellow_wood");
  lua_rawset(L,-3);
  lua_pushliteral(L,"groups");
  lua_createtable(L,0,3);
  lua_pushliteral(L,"choppy");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"oddly_breakable_by_hand");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"flammable");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_call(L,2,0);
  assert(lua_gettop(L) - lc_nextra == 1);
  
  /* doors.register_fencegate("ethereal:fencegate_palm", {
   * 	description = S("Palm Wood Fence Gate"),
   * 	texture = "moretrees_palm_wood.png",
   * 	material = "ethereal:palm_wood",
   * 	groups = {choppy = 2, oddly_breakable_by_hand = 2, flammable = 2}
   * }) */
  lua_getfield(L,LUA_ENVIRONINDEX,"doors");
  lua_pushliteral(L,"register_fencegate");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushliteral(L,"ethereal:fencegate_palm");
  lua_createtable(L,0,4);
  lua_pushliteral(L,"description");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"Palm Wood Fence Gate");
  lua_call(L,1,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"texture");
  lua_pushliteral(L,"moretrees_palm_wood.png");
  lua_rawset(L,-3);
  lua_pushliteral(L,"material");
  lua_pushliteral(L,"ethereal:palm_wood");
  lua_rawset(L,-3);
  lua_pushliteral(L,"groups");
  lua_createtable(L,0,3);
  lua_pushliteral(L,"choppy");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"oddly_breakable_by_hand");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"flammable");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_call(L,2,0);
  assert(lua_gettop(L) - lc_nextra == 1);
  
  /* doors.register_fencegate("ethereal:fencegate_banana", {
   * 	description = S("Banana Wood Fence Gate"),
   * 	texture = "banana_wood.png",
   * 	material = "ethereal:banana_wood",
   * 	groups = {choppy = 2, oddly_breakable_by_hand = 2, flammable = 2}
   * }) */
  lua_getfield(L,LUA_ENVIRONINDEX,"doors");
  lua_pushliteral(L,"register_fencegate");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushliteral(L,"ethereal:fencegate_banana");
  lua_createtable(L,0,4);
  lua_pushliteral(L,"description");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"Banana Wood Fence Gate");
  lua_call(L,1,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"texture");
  lua_pushliteral(L,"banana_wood.png");
  lua_rawset(L,-3);
  lua_pushliteral(L,"material");
  lua_pushliteral(L,"ethereal:banana_wood");
  lua_rawset(L,-3);
  lua_pushliteral(L,"groups");
  lua_createtable(L,0,3);
  lua_pushliteral(L,"choppy");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"oddly_breakable_by_hand");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"flammable");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_call(L,2,0);
  assert(lua_gettop(L) - lc_nextra == 1);
  
  /* doors.register_fencegate("ethereal:fencegate_mushroom", {
   * 	description = S("Mushroom Trunk Fence Gate"),
   * 	texture = "mushroom_trunk.png",
   * 	material = "ethereal:mushroom_trunk",
   * 	groups = {choppy = 2, oddly_breakable_by_hand = 2, flammable = 2}
   * }) */
  lua_getfield(L,LUA_ENVIRONINDEX,"doors");
  lua_pushliteral(L,"register_fencegate");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushliteral(L,"ethereal:fencegate_mushroom");
  lua_createtable(L,0,4);
  lua_pushliteral(L,"description");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"Mushroom Trunk Fence Gate");
  lua_call(L,1,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"texture");
  lua_pushliteral(L,"mushroom_trunk.png");
  lua_rawset(L,-3);
  lua_pushliteral(L,"material");
  lua_pushliteral(L,"ethereal:mushroom_trunk");
  lua_rawset(L,-3);
  lua_pushliteral(L,"groups");
  lua_createtable(L,0,3);
  lua_pushliteral(L,"choppy");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"oddly_breakable_by_hand");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"flammable");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_call(L,2,0);
  assert(lua_gettop(L) - lc_nextra == 1);
  
  /* doors.register_fencegate("ethereal:fencegate_birch", {
   * 	description = S("Birch Wood Fence Gate"),
   * 	texture = "moretrees_birch_wood.png",
   * 	material = "ethereal:birch_wood",
   * 	groups = {choppy = 2, oddly_breakable_by_hand = 2, flammable = 2}
   * }) */
  lua_getfield(L,LUA_ENVIRONINDEX,"doors");
  lua_pushliteral(L,"register_fencegate");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushliteral(L,"ethereal:fencegate_birch");
  lua_createtable(L,0,4);
  lua_pushliteral(L,"description");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"Birch Wood Fence Gate");
  lua_call(L,1,1);
  lua_rawset(L,-3);
  lua_pushliteral(L,"texture");
  lua_pushliteral(L,"moretrees_birch_wood.png");
  lua_rawset(L,-3);
  lua_pushliteral(L,"material");
  lua_pushliteral(L,"ethereal:birch_wood");
  lua_rawset(L,-3);
  lua_pushliteral(L,"groups");
  lua_createtable(L,0,3);
  lua_pushliteral(L,"choppy");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"oddly_breakable_by_hand");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_pushliteral(L,"flammable");
  lua_pushnumber(L,2);
  lua_rawset(L,-3);
  lua_rawset(L,-3);
  lua_call(L,2,0);
  assert(lua_gettop(L) - lc_nextra == 1);
  
  /* -- add compatibility for ethereal's to default wooden gates
   * minetest.register_alias("ethereal:fencegate_wood_open", "doors:gate_wood_open") */
  lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
  lua_pushliteral(L,"register_alias");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushliteral(L,"ethereal:fencegate_wood_open");
  lua_pushliteral(L,"doors:gate_wood_open");
  lua_call(L,2,0);
  assert(lua_gettop(L) - lc_nextra == 1);
  
  /* minetest.register_alias("ethereal:fencegate_wood_closed", "doors:gate_wood_closed") */
  lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
  lua_pushliteral(L,"register_alias");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushliteral(L,"ethereal:fencegate_wood_closed");
  lua_pushliteral(L,"doors:gate_wood_closed");
  lua_call(L,2,0);
  assert(lua_gettop(L) - lc_nextra == 1);
  
  /* minetest.register_alias("ethereal:fencegate_acacia_open", "doors:gate_acacia_wood_open") */
  lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
  lua_pushliteral(L,"register_alias");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushliteral(L,"ethereal:fencegate_acacia_open");
  lua_pushliteral(L,"doors:gate_acacia_wood_open");
  lua_call(L,2,0);
  assert(lua_gettop(L) - lc_nextra == 1);
  
  /* minetest.register_alias("ethereal:fencegate_acacia_closed", "doors:gate_acacia_wood_closed") */
  lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
  lua_pushliteral(L,"register_alias");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushliteral(L,"ethereal:fencegate_acacia_closed");
  lua_pushliteral(L,"doors:gate_acacia_wood_closed");
  lua_call(L,2,0);
  assert(lua_gettop(L) - lc_nextra == 1);
  
  /* minetest.register_alias("ethereal:fencegate_junglewood_open", "doors:gate_junglewood_open") */
  lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
  lua_pushliteral(L,"register_alias");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushliteral(L,"ethereal:fencegate_junglewood_open");
  lua_pushliteral(L,"doors:gate_junglewood_open");
  lua_call(L,2,0);
  assert(lua_gettop(L) - lc_nextra == 1);
  
  /* minetest.register_alias("ethereal:fencegate_junglewood_closed", "doors:gate_junglewood_closed") */
  lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
  lua_pushliteral(L,"register_alias");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushliteral(L,"ethereal:fencegate_junglewood_closed");
  lua_pushliteral(L,"doors:gate_junglewood_closed");
  lua_call(L,2,0);
  assert(lua_gettop(L) - lc_nextra == 1);
  
  /* minetest.register_alias("ethereal:fencegate_pine_open", "doors:gate_pine_wood_open") */
  lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
  lua_pushliteral(L,"register_alias");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushliteral(L,"ethereal:fencegate_pine_open");
  lua_pushliteral(L,"doors:gate_pine_wood_open");
  lua_call(L,2,0);
  assert(lua_gettop(L) - lc_nextra == 1);
  
  /* minetest.register_alias("ethereal:fencegate_pine_closed", "doors:gate_pine_wood_closed") */
  lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
  lua_pushliteral(L,"register_alias");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushliteral(L,"ethereal:fencegate_pine_closed");
  lua_pushliteral(L,"doors:gate_pine_wood_closed");
  lua_call(L,2,0);
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


int lc_pmain_mod_ethereal_gates(lua_State * L) {
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


