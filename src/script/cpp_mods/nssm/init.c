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

#include "cpp_mods/cpp_mods_init.h"

/* name: (main)
 * function(...) */
static int lcf_main (lua_State * L) {
  enum { lc_nformalargs = 0 };
  const int lc_nactualargs = lua_gettop(L);
  const int lc_nextra = (lc_nactualargs - lc_nformalargs);
  
  /* local path = minetest.get_modpath("nssm") */
  lua_getfield(L,LUA_ENVIRONINDEX,"minetest");
  lua_pushliteral(L,"get_modpath");
  lua_gettable(L,-2);
  lua_remove(L,-2);
  lua_pushliteral(L,"nssm");
  lua_call(L,1,1);
  assert(lua_gettop(L) - lc_nextra == 1);
  
  /* dofile(path.."/api.lua") */
  lc_pmain_mod_nssm_api(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/api.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/spawn.lua") */
  lc_pmain_mod_nssm_spawn(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/spawn.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* --Mobs
   * dofile(path.."/ant_queen.lua") */
  lc_pmain_mod_nssm_ant_queen(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/ant_queen.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/ant_soldier.lua") */
  lc_pmain_mod_nssm_ant_soldier(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/ant_soldier.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/ant_worker.lua") */
  lc_pmain_mod_nssm_ant_worker(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/ant_worker.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/black_widow.lua") */
  lc_pmain_mod_nssm_black_widow(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/black_widow.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/bloco.lua") */
  lc_pmain_mod_nssm_bloco(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/bloco.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/crab.lua") */
  lc_pmain_mod_nssm_crab(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/crab.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/crocodile.lua") */
  lc_pmain_mod_nssm_crocodile(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/crocodile.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/daddy_long_legs.lua") */
  lc_pmain_mod_nssm_daddy_long_legs(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/daddy_long_legs.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/dolidrosaurus.lua") */
  lc_pmain_mod_nssm_dolidrosaurus(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/dolidrosaurus.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/duck.lua") */
  lc_pmain_mod_nssm_duck(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/duck.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/duckking.lua") */
  lc_pmain_mod_nssm_duckking(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/duckking.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/echidna.lua") */
  lc_pmain_mod_nssm_echidna(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/echidna.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/enderduck.lua") */
  lc_pmain_mod_nssm_enderduck(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/enderduck.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* --dofile(path.."/flying_duck.lua")
   * dofile(path.."/giant_sandworm.lua") */
  lc_pmain_mod_nssm_giant_sandworm(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/giant_sandworm.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/icelamander.lua") */
  lc_pmain_mod_nssm_icelamander(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/icelamander.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/icesnake.lua") */
  lc_pmain_mod_nssm_icesnake(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/icesnake.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/kraken.lua") */
  lc_pmain_mod_nssm_kraken(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/kraken.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/larva.lua") */
  lc_pmain_mod_nssm_larva(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/larva.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/lava_titan.lua") */
  lc_pmain_mod_nssm_lava_titan(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/lava_titan.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/manticore.lua") */
  lc_pmain_mod_nssm_manticore(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/manticore.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/mantis_beast.lua") */
  lc_pmain_mod_nssm_mantis_beast(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/mantis_beast.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/mantis.lua") */
  lc_pmain_mod_nssm_mantis(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/mantis.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/masticone.lua") */
  lc_pmain_mod_nssm_masticone(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/masticone.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/moonheron.lua") */
  lc_pmain_mod_nssm_moonheron(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/moonheron.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/night_master.lua") */
  lc_pmain_mod_nssm_night_master(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/night_master.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/octopus.lua") */
  lc_pmain_mod_nssm_octopus(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/octopus.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/phoenix.lua") */
  lc_pmain_mod_nssm_phoenix(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/phoenix.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/pumpboom.lua") */
  lc_pmain_mod_nssm_pumpboom(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/pumpboom.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/pumpking.lua") */
  lc_pmain_mod_nssm_pumpking(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/pumpking.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/sandworm.lua") */
  lc_pmain_mod_nssm_sandworm(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/sandworm.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/scrausics.lua") */
  lc_pmain_mod_nssm_scrausics(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/scrausics.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/sand_bloco.lua") */
  lc_pmain_mod_nssm_sand_bloco(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/sand_bloco.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/signosigno.lua") */
  lc_pmain_mod_nssm_signosigno(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/signosigno.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/snow_biter.lua") */
  lc_pmain_mod_nssm_snow_biter(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/snow_biter.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/spiderduck.lua") */
  lc_pmain_mod_nssm_spiderduck(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/spiderduck.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/stone_eater.lua") */
  lc_pmain_mod_nssm_stone_eater(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/stone_eater.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/swimming_duck.lua") */
  lc_pmain_mod_nssm_swimming_duck(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/swimming_duck.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/tarantula.lua") */
  lc_pmain_mod_nssm_tarantula(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/tarantula.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/uloboros.lua") */
  lc_pmain_mod_nssm_uloboros(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/uloboros.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/werewolf.lua") */
  lc_pmain_mod_nssm_werewolf(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/werewolf.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/white_werewolf.lua") */
  lc_pmain_mod_nssm_white_werewolf(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/white_werewolf.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* --Final Boss
   * dofile(path.."/mese_dragon.lua") */
  lc_pmain_mod_nssm_mese_dragon(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/mese_dragon.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* --Others
   * dofile(path.."/rainbow_staff.lua") */
  lc_pmain_mod_nssm_rainbow_staff(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/rainbow_staff.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/darts.lua") */
  lc_pmain_mod_nssm_darts(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/darts.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/nssm_materials.lua") */
  lc_pmain_mod_nssm_nssm_materials(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/nssm_materials.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/nssm_spears.lua") */
  lc_pmain_mod_nssm_nssm_spears(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/nssm_spears.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/nssm_api.lua") */
  lc_pmain_mod_nssm_nssm_api(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/nssm_api.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
  
  /* dofile(path.."/nssm_weapons.lua") */
  lc_pmain_mod_nssm_nssm_weapons(L);
  /* lua_getfield(L,LUA_ENVIRONINDEX,"dofile");
  lua_pushvalue(L,(1 + lc_nextra));
  lua_pushliteral(L,"/nssm_weapons.lua");
  lua_concat(L,2);
  lua_call(L,1,0);
  assert(lua_gettop(L) - lc_nextra == 1); */
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


int lc_pmain_mod_nssm_init(lua_State * L) {
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

